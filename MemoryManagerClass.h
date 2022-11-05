#pragma once
#ifndef MEMORYMANAGERCLASS_H
#define MEMORYMANAGERCLASS_H



#include <string.h>
#include "BaseTypes.h"
#include <stdlib.h>
#include <stdio.h>
#include <vector>

#include "TimerClass.h"
using namespace std;

typedef struct
{
	unsigned int Start;
	unsigned int Length;
	void* Address;
}TMemoryArea;

class MemoryManagerClass
{
public:
	bool _UseSelfMemoryManagement;
	MemoryManagerClass(unsigned int SegmentSize, bool AutomaticReleaseSegment, bool InitializeMems);
	MemoryManagerClass(bool InitializeMems);

	void* AllocVoid(int ElementNumber, int ElementSize);
	short* AllocShort(int ElementNumber);
	char* AllocChar(int ElementNumber);
	int* AllocInt(int ElementNumber);
	double* AllocDouble(int ElementNumber);
	float* AllocFloat(int ElementNumber);
	Complex64* AllocComplex64(int ElementNumber);
	Complex32* AllocComplex32(int ElementNumber);
	ComplexInt* AllocComplexInt(int ElementNumber);
	ComplexShort* AllocComplexShort(int ElementNumber);
	void FREEMEM(void** MemAdd);
	void Distroy();
	__int64 GetTotalAllocationTime();
	__int64 GetTotalAllocationSize();
	void ResetManager(int KeepSegmentCount);
	int GetAllocationCount();
	int GetReleaseCount();
	int GetUnReleaseCount();
	int GetMaxAllocationSize();

private:
	int _Max_Allocation_Size;
	int _Allocation_Count;
	int _Release_Count;
	int _UnReleased_Count;
	void** _Mem;
	bool _Automatic_Release_Segment;
	int _Current_Segment;
	int _Max_Segment_Count;
	unsigned int _Start;
	unsigned int _Segment_Size;
	__int64 _Total_Allocation_Size;
	__int64 _Total_Allocation_Time;
	char LogFileName[200];
	bool _InitializeMems;
	vector<string> _MemTag;
	vector< vector<TMemoryArea>> _In_Use_Memory_Locations;
	void* AssignAddressFromIntrnalMem(unsigned int ByteSize, int ElementSize);
	void RemoveMemAreaFromList(void* MemAddress);
	void* MyAlloc(unsigned int ByteSize, int ElementSize);
	void FreeSegment(int SegmentIndex);
	void WriteErrorToLogFile(char* txt);
	void InitVariables();
};

#endif