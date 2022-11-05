
#include "MemoryManagerClass.h"

#pragma warning(disable:4996)

MemoryManagerClass::MemoryManagerClass(unsigned int SegmentSize, bool AutomaticReleaseSegment, bool InitializeMems)
{
	InitVariables();
	_UseSelfMemoryManagement = true;
	_Automatic_Release_Segment = AutomaticReleaseSegment;
	_Max_Segment_Count = 100;
	_Segment_Size = SegmentSize;
	__int64 t1 = TimerClass::GetTime_in_MiliSec();
	_Mem = (void**)malloc(sizeof(void*)*_Max_Segment_Count);
	if (!_Mem)
	{
		WriteErrorToLogFile("MemManager Cant Alloc Memory Segments");
	}
	memset(_Mem, 0, sizeof(void*)*_Max_Segment_Count);
	_Mem[_Current_Segment] = malloc(_Segment_Size);
	if (!_Mem[_Current_Segment])
	{
		WriteErrorToLogFile("MemManager Cant Alloc Memory Segment 1");
	}
	memset(_Mem[_Current_Segment], 0, _Segment_Size);
	__int64 t2 = TimerClass::GetTime_in_MiliSec();
	__int64 t3 = t2 - t1;
	_Total_Allocation_Time += t3;

	if (_Automatic_Release_Segment)
	{
		vector<TMemoryArea> List;
		_In_Use_Memory_Locations.push_back(List);
	}
	_InitializeMems = InitializeMems;
}
MemoryManagerClass::MemoryManagerClass(bool InitializeMems)
{
	InitVariables();

	_UseSelfMemoryManagement = false;
	_Automatic_Release_Segment = false;
	_Max_Segment_Count = 0;
	_Segment_Size = 0;

	_InitializeMems = InitializeMems;
}
void MemoryManagerClass::InitVariables()
{
	sprintf(LogFileName, "%s", "MemManagerLog.txt");
	_Total_Allocation_Time = 0;
	_Current_Segment = 0;
	_Start = 0;
	_Mem = NULL;
	_Total_Allocation_Size = 0;
	_Allocation_Count = 0;
	_Release_Count = 0;
	_UnReleased_Count = 0;
	_Max_Allocation_Size = 0;
}

void* MemoryManagerClass::AllocVoid(int ElementNumber, int ElementSize)
{
	void* temp = MyAlloc(ElementSize*ElementNumber, ElementSize);
	return temp;
}
short* MemoryManagerClass::AllocShort(int ElementNumber)
{
	int ElementSize = sizeof(short);
	short* temp = (short*)MyAlloc(sizeof(short)*ElementNumber, ElementSize);
	return temp;
}
char* MemoryManagerClass::AllocChar(int ElementNumber)
{
	int ElementSize = sizeof(char);
	char* temp = (char*)MyAlloc(sizeof(char)*ElementNumber, ElementSize);
	return temp;
}
int* MemoryManagerClass::AllocInt(int ElementNumber)
{
	int ElementSize = sizeof(int);
	int* temp = (int*)MyAlloc(sizeof(int)*ElementNumber, ElementSize);
	return temp;
}
double* MemoryManagerClass::AllocDouble(int ElementNumber)
{
	int ElementSize = sizeof(double);
	double* temp = (double*)MyAlloc(sizeof(double)*ElementNumber, ElementSize);
	return temp;
}
float* MemoryManagerClass::AllocFloat(int ElementNumber)
{
	int ElementSize = sizeof(float);
	float* temp = (float*)MyAlloc(sizeof(float)*ElementNumber, ElementSize);
	return temp;
}
Complex64* MemoryManagerClass::AllocComplex64(int ElementNumber)
{
	int ElementSize = sizeof(Complex64);
	Complex64* temp = (Complex64*)MyAlloc(sizeof(Complex64)*ElementNumber, ElementSize);
	return temp;
}
Complex32* MemoryManagerClass::AllocComplex32(int ElementNumber)
{
	int ElementSize = sizeof(Complex32);
	Complex32* temp = (Complex32*)MyAlloc(sizeof(Complex32)*ElementNumber, ElementSize);
	return temp;
}
ComplexInt* MemoryManagerClass::AllocComplexInt(int ElementNumber)
{
	int ElementSize = sizeof(ComplexInt);
	ComplexInt* temp = (ComplexInt*)MyAlloc(sizeof(ComplexInt)*ElementNumber, ElementSize);
	return temp;
}
ComplexShort* MemoryManagerClass::AllocComplexShort(int ElementNumber)
{
	int ElementSize = sizeof(ComplexShort);
	ComplexShort* temp = (ComplexShort*)MyAlloc(sizeof(ComplexShort)*ElementNumber, ElementSize);
	return temp;
}
void MemoryManagerClass::FREEMEM(void** MemAdd)
{
	__int64 t1 = TimerClass::GetTime_in_MiliSec();
	if (!_UseSelfMemoryManagement)
	{
		if (*MemAdd)
		{
			//delete[] *_Mem;
			free(*MemAdd);
			*MemAdd = NULL;
		}
	}
	else
	{
		if (_Automatic_Release_Segment)
		{
			RemoveMemAreaFromList(*MemAdd);
		}
	}
	_Release_Count++;
	_UnReleased_Count--;
	__int64 t2 = TimerClass::GetTime_in_MiliSec();
	__int64 t3 = t2 - t1;
	_Total_Allocation_Time += t3;
}
void MemoryManagerClass::Distroy()
{
	if (_Mem)
	{
		for (int i = 0; i <= _Current_Segment; i++)
		{
			FreeSegment(i);
		}
		free(_Mem);
		_Mem = NULL;
	}
	_In_Use_Memory_Locations.clear();
	_Total_Allocation_Time = 0;
	_Total_Allocation_Size = 0;
	_Start = 0;
	_Segment_Size = 0;

}
__int64 MemoryManagerClass::GetTotalAllocationTime()
{
	return _Total_Allocation_Time;
}
__int64 MemoryManagerClass::GetTotalAllocationSize()
{
	return _Total_Allocation_Size;
}
void MemoryManagerClass::ResetManager(int KeepSegmentCount )
{
	if (KeepSegmentCount-1>_Current_Segment)
	{
		KeepSegmentCount = _Current_Segment;
	}
	for (int i = KeepSegmentCount; i <= _Current_Segment; i++)
	{
		FreeSegment(i);
	}

	_Current_Segment = 0;
	if (_UseSelfMemoryManagement == true && _InitializeMems == true)
	{
		memset(_Mem[0], 0, _Segment_Size);
	}

	if (_Automatic_Release_Segment)
	{
		_In_Use_Memory_Locations[0].clear();
	}

	_Total_Allocation_Time = 0;
	_Start = 0;
	_Total_Allocation_Size = 0;
	_Allocation_Count = 0;
	_Release_Count = 0;
	_UnReleased_Count = 0;
	_Max_Allocation_Size = 0;
}
int MemoryManagerClass::GetAllocationCount()
{
	return _Allocation_Count;
}
int MemoryManagerClass::GetReleaseCount()
{
	return _Release_Count;
}
int MemoryManagerClass::GetUnReleaseCount()
{
	return _UnReleased_Count;
}
int MemoryManagerClass::GetMaxAllocationSize()
{
	return _Max_Allocation_Size;
}
void* MemoryManagerClass::AssignAddressFromIntrnalMem(unsigned int ByteSize, int ElementSize)
{

	while (_Start%ElementSize != 0)
	{
		_Start++;// move forward _Start for alignment issues
		// move forward until the address being multiply of elementsize
	}
	void* temp = (char *)(_Mem[_Current_Segment]) + _Start;
	_Total_Allocation_Size += ByteSize;
	if (_Automatic_Release_Segment)
	{
		TMemoryArea MA;
		MA.Start = _Start;
		MA.Length = ByteSize;
		MA.Address = temp;

		_In_Use_Memory_Locations[_Current_Segment].push_back(MA);
	}
	_Start += ByteSize;
	return temp;
}
void MemoryManagerClass::RemoveMemAreaFromList(void* MemAddress)
{
	for (int i = 0; i <= _Current_Segment; i++)
	{
		int size = _In_Use_Memory_Locations[i].size();
		for (int j = 0; j<size; j++)
		{
			if (_In_Use_Memory_Locations[i][j].Address == MemAddress)
			{
				_In_Use_Memory_Locations[i].erase(_In_Use_Memory_Locations[i].begin() + j);
				if (j == 0 && i != _Current_Segment)
				{
					FreeSegment(i);
				}
				break;
			}
		}
	}
}
void* MemoryManagerClass::MyAlloc(unsigned int ByteSize, int ElementSize)
{
	if (ByteSize > _Max_Allocation_Size)
	{
		_Max_Allocation_Size = ByteSize;
	}
	__int64 t1 = TimerClass::GetTime_in_MiliSec();
	void* temp = NULL;
	if (_UseSelfMemoryManagement)
	{
		int remain_space_byte = (int)_Segment_Size - (int)_Start;
		if (remain_space_byte>ByteSize && remain_space_byte>0)
		{
			temp = AssignAddressFromIntrnalMem(ByteSize, ElementSize);
		}
		else
		{
			int SegmentSizetmp = _Segment_Size;
			//go to next segment
			if (ByteSize>_Segment_Size)
			{
				SegmentSizetmp = ByteSize;
			}
			if (++_Current_Segment<_Max_Segment_Count)
			{
				_Mem[_Current_Segment] = malloc(SegmentSizetmp);// alloc next segment
				if (!_Mem[_Current_Segment])
				{
					WriteErrorToLogFile("MemManager Cant Alloc Memory Next Segment");
				}
				memset(_Mem[_Current_Segment], 0, SegmentSizetmp);
				_Start = 0;
				if (_Automatic_Release_Segment)
				{
					vector<TMemoryArea> List;
					_In_Use_Memory_Locations.push_back(List);
				}
				if (SegmentSizetmp - _Start >= ByteSize)
				{
					temp = AssignAddressFromIntrnalMem(ByteSize, ElementSize);
				}
				else
				{
					// Byte size is greater than _Segment_Size
					return NULL;
				}
			}
			else
			{
				// reached to max segment count
				return NULL;
			}
		}
	}
	else
	{
		temp = malloc(ByteSize);
		if (!temp)
		{
			WriteErrorToLogFile("MemManager Cant Alloc Memory");
		}
		if (_InitializeMems)
		{
			memset(temp, 0, ByteSize);
		}
		_Total_Allocation_Size += ByteSize;
	}
	_Allocation_Count++;
	_UnReleased_Count++;
	__int64 t2 = TimerClass::GetTime_in_MiliSec();
	__int64 t3 = t2 - t1;
	_Total_Allocation_Time += t3;
	return temp;
}
void MemoryManagerClass::FreeSegment(int SegmentIndex)
{
	__int64 t1 = TimerClass::GetTime_in_MiliSec();
	if (_Mem[SegmentIndex])
	{

		free(_Mem[SegmentIndex]);
		_Mem[SegmentIndex] = NULL;

	}
	if (_Automatic_Release_Segment)
	{

		_In_Use_Memory_Locations[SegmentIndex].clear();
	}
	__int64 t2 = TimerClass::GetTime_in_MiliSec();
	__int64 t3 = t2 - t1;
	_Total_Allocation_Time += t3;
}
void MemoryManagerClass::WriteErrorToLogFile(char* txt)
{
	// I comment this function because it's instruction is incompatible with gcc compiler



	//time_t now = time(0);
	////	char* dt = ctime(&now);
	//char dt[26];
	//ctime_s(dt, sizeof(dt), &now);
	//char month[5] = { 0 };
	//char daystr[5] = { 0 };
	//int day = 0;
	//int hour = 0;
	//int min = 0;
	//int sec = 0;
	//int year = 0;

	////sscanf(dt, "%s %s %d %d:%d:%d %d", daystr, month, &day, &hour, &min, &sec, &year);
	//sscanf_s(dt, "%s %s %d %d:%d:%d %d", daystr, month, &day, &hour, &min, &sec, &year);
	//char timestamp[200] = { 0 };
	////	sprintf(timestamp, "%d_%s_%d___%d_%d_%d", day, month, year, hour, min, sec);
	//sprintf_s(timestamp, "%d_%s_%d___%d_%d_%d", day, month, year, hour, min, sec);
	///*String^ now=DateTime::Now.ToString();

	//for(int i = 0;i<now->Length;i++)
	//{
	//nows += now[i];
	//}*/
	//char etxt[500] = { 0 };
	////	sprintf(etxt, "%s		%s", txt, timestamp);
	//sprintf_s(etxt, "%s		%s", txt, timestamp);
	////	FILE* logfile = fopen(LogFileName, "at");
	//FILE* logfile;
	//errno_t err = fopen_s(&logfile, LogFileName, "at");
	//if (logfile)
	//{
	//	//fprintf(logfile, "%s\n", etxt);
	//	fprintf_s(logfile, "%s\n", etxt);
	//	fclose(logfile);

	//}

	/*FILE* f=fopen(LogFileName,"at");
	if(f)
	{
	fprintf(f,"\n%s","MemManager Cant Alloc Memory Segments");
	fclose(f);
	}*/
}
