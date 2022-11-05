#pragma once
#ifndef MYTYPE_H
#define MYTYPE_H

// ver = 29.3 18/03/1400

// for linux add this switch to QT .pro file
//QMAKE_CXXFLAGS += -std=c++11
//CONFIG += c++11

#define Use_MKL 1 // if you want use MKL Library Must Set UseMKL To 1 and Doing Below Step For Add MKL Library To Project ; if you dont need MKL Functions Set UseMKL to 0
#define Use_Ipp 0 // if you want use IPP Library Must Set UseIpp To 1 and Doing Below Step For Add IPP Library To Project ; if you dont need IPP Functions Set UseIpp to 0
#define Use_MATLAB 0  // if you want use MATLAB Must Set Use_MATLAB To 1 and Doing Below Step For Add Use_MATLAB Library To Project ; if you dont need MATLAB Functions Set Use_MATLAB to 0
// For use this Class Must Do This :
// 1. Add MATLAB Include Directory Path To "Additional Include Directory"
//    "C:\Program Files\MATLAB\R2017b\extern\include"
//
// 2. Add MATLAB LIB Directory Path To "Additional Library Directory"
//    "C:\Program Files\MATLAB\R2017b\extern\lib\win64\microsoft" for built 64bit assemblies
//
// 3. Add "libMatlabEngine.lib"; "libMatlabDataArray.lib";  To "Additional Dependencies" for built 64bit assemblies
// 4. Add Path="C:\Program Files\MATLAB\R2017b\extern\bin\win64"     to Environment Variables for Run 64bit assemblies
// 5. Set Matlab shared Engine name :  matlab.engine.shareEngine('SME')
//	

#include <cstring>  //for memset

// MemManager Always return align memory with DataType size alignment. 

// MyComplexClass V5.1 For Use With MKL Library and Ipp Library
//------------------------------Intel Compiler 11---------------------
// For use this Class Must Do This :
// 1. Add MKL Include Directory Path To "Additional Include Directory"
//    "C:\Program Files\Intel\Compiler\11.0\066\cpp\mkl\include"
//
// 2. Add MKL LIB Directory Path To "Additional Library Directory"
//    "C:\Program Files\Intel\Compiler\11.0\066\cpp\mkl\ia32\lib" for built 32bit assemblies
//	  "C:\Program Files\Intel\Compiler\11.0\066\cpp\mkl\em64t\lib" for built 64bit assemblies
//
// 3. Add "mkl_intel_c_dll.lib"   ;  "mkl_core_dll.lib" To "Additional Dependencies" for built 32bit assemblies
//    ADD "mkl_intel_lp64_dll.lib";  "mkl_core_dll.lib" To "Additional Dependencies" for built 64bit assemblies

//    MKL_THREADING_LAYER : 
//			A. MKL_THREADING_INTEL   
//			   for intel threading,  mkl functions run multithread with intel thread threading.  use "mkl_intel_thread_dll.lib" to utilize intel threading.
// 			   in this mode application is not threaded and since intel use omp for threading it also need libiomp5.lib
//
//			B. MKL_THREADING_SEQUENTIAL
//					for sequential mode of Intel MKL. Application could be threaded and doesnt need libiomp5.lib.
//
//			note : MKL_THREADING_LAYER could be selected by mkl_set_threading_layer() funtion programmitically.
//---------------------------------------------------------------------

//------------Intel Parallel Studio XE 2015 Composer Edition-----------
// For use MKL Must Do This :
// 1. Add MKL Include Directory Path To "Additional Include Directory"
//    "C:\Program Files (x86)\Intel\Composer XE 2015\mkl\include"
//
// 2. Add MKL LIB Directory Path To "Additional Library Directory"
//    "C:\Program Files (x86)\Intel\Composer XE 2015\mkl\lib\ia32"    for built 32bit assemblies
//	  "C:\Program Files (x86)\Intel\Composer XE 2015\mkl\lib\intel64" for built 64bit assemblies
//
// 3. Add "mkl_intel_c_dll.lib"   ; "mkl_core_dll.lib" To "Additional Dependencies" for built 32bit assemblies
//    ADD "mkl_intel_lp64_dll.lib"; "mkl_core_dll.lib" To "Additional Dependencies" for built 64bit assemblies
//	
//    MKL_THREADING_LAYER : 
//			A. MKL_THREADING_INTEL   
//			   for intel threading,  mkl functions run multithread with intel thread threading.  use "mkl_intel_thread_dll.lib" to utilize intel threading.
// 			   in this mode application is not threaded and since intel use omp for threading it also need libiomp5.lib
//
//			B. MKL_THREADING_SEQUENTIAL
//					for sequential mode of Intel MKL. Application could be threaded and doesnt need libiomp5.lib.
//
//			note : MKL_THREADING_LAYER could be selected by mkl_set_threading_layer() funtion programmitically.
//
// 4. Add Path="C:\Program Files (x86)\Intel\Composer XE 2015\redist\ia32\mkl"     to Environment Variables for Run 32bit assemblies
//    Add Path="C:\Program Files (x86)\Intel\Composer XE 2015\redist\intel64\mkl"  to Environment Variables for Run 64bit assemblies

	
#include <vector>
#include <time.h>
#include <stdexcept>
#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <stdio.h>


#include "MemoryManagerClass.h"



#ifdef _MSC_VER
#include <crtdbg.h>
#endif

#if Use_Ipp==1
#include<ippcore.h>
#include<ippvm.h>
#include<ipps.h>
#pragma comment(lib;"ipps")
#endif

#if Use_MKL==1
#include <mkl_vsl.h>
#include <mkl.h>
#include <mkl_dfti.h>


//#pragma comment(lib;"mkl_intel_lp64_dll")
//#pragma comment(lib;"mkl_intel_thread_dll")
//#pragma comment(lib;"mkl_core_dll")
#endif


#if Use_MATLAB
#include "MatlabEngine.hpp"  
#define MATLABSharedEngineName "SME"
// run this by MATLAB  : matlab.engine.shareEngine('SME')
using namespace matlab::engine;
#endif


// it is impossible to define assignment overload as non member function according to below page:
// en.cppreference.com/w/cpp/language/operator
//



#define PTcArr64 TcArr64
#define PTcArr32 TcArr32
#define PTcArrInt TcArrInt
#define PTcArrShort TcArrShort
#define PTcArrChar TcArrChar

#define PTdArr TdArr
#define PTfArr TfArr
#define PTsArr TsArr
#define PTintArr TintArr
#define PTCharArr TCharArr
#define PTbArr TbArr

#define PTcArr2d64 TcArr2d64
#define PTcArr2d32 TcArr2d32
#define PTcArr2dInt TcArr2dInt
#define PTcArr2dShort TcArr2dShort
#define PTcArr2dChar TcArr2dChar

#define PTdArr2d TdArr2d
#define PTfArr2d TfArr2d
#define PTsArr2d TsArr2d
#define PTCharArr2d TCharArr2d
#define PTintArr2d TintArr2d


#define END(x) (x.Length-1)

#ifdef _DEBUG
#define DebugBuild
#endif 

#if Use_MATLAB ==1

#include <type_traits>
enum MatlabColor
{
	yellow='y',
	magenta='m',
	cyan='c',
	red = 'r',
	green='g',
	blue='b',
	white='w',
	black='k',
};
class DimensionClass
{
public :
	int Row;
	int Column;
};
class MATLABEngineClass
{
public:
	
	MATLABEngineClass(string MatlabSharedEngineName)
	{
		if (!_CS)
		{
			_CS = new CRITICAL_SECTION();
			InitializeCriticalSection(_CS);
		}
		if (_inited==false)
		{
			Sleep(10); // waiting for when two thread call class constructor simultounsly and create two _CS . waiting last thread fill _CS
		}
		
		// test is matlab engine shared (matlab command) : matlab.engine.isEngineShared
		// for sharing matlab engine (matlab command) : matlab.engine.shareEngine(name)  
		_MatlabSharedEngineName = MatlabSharedEngineName;

		if (!_matlabptr && !_inited)
		{
			EnterCriticalSection(_CS);
			if (!_matlabptr )
			{
				char16_t* m_str = Getchar16(_MatlabSharedEngineName);
				try
				{
					_matlabptr = connectMATLAB(m_str);
				}			
				catch (...)
				{
				
				}
				
				free(m_str);
			}
			LeaveCriticalSection(_CS);
		}
		_inited = true;
	}
	double DiffValue(double* CppArr,int CppArrLength, string MatlabVarName)
	{
		string CppVarname = "CppAns";
		SetVariable(CppArr, CppArrLength, CppVarname);

		int MatlabVarLength=GetMatlabVariableLength(MatlabVarName);
		if (MatlabVarLength!=CppArrLength)
		{
			return -1;
		}
		if (NeedTranspose(MatlabVarName,CppArrLength))
		{
			MatlabVarName = "transpose(" + MatlabVarName + ")";
		}

		char cmd[500] = { 0 };
		sprintf(cmd, "sum(abs(%s-%s))", MatlabVarName.c_str(), CppVarname.c_str());
		Eval(cmd);

		double ans = GetMatlabScalarVariable("ans");
		return ans;
	}
	void Plot(double* CppArr, int CppArrLength,string title="CppAns",MatlabColor lineColor=MatlabColor::red,string Legend="CppVar")
	{
		string CppVarname = "CppAns";
		SetVariable(CppArr, CppArrLength, CppVarname);
		char color = (char)lineColor;
		char cmd[500] = { 0 };
		sprintf(cmd, "plot(%s,'%c'),  title('%s'), legend('%s')", CppVarname.c_str(),color,title.c_str(),Legend.c_str());
		Eval(cmd);
	}
	void ScatterPlot(double* CppArr, int CppArrLength, string title = "CppAns", MatlabColor lineColor = MatlabColor::red, string Legend = "CppVar")
	{
		string CppVarname = "CppAns";
		SetVariable(CppArr, CppArrLength, CppVarname);
		char color = (char)lineColor;
		char cmd[500] = { 0 };
		sprintf(cmd, "plot(%s,'.%c'),  title('%s'), legend('%s')", CppVarname.c_str(), color, title.c_str(), Legend.c_str());
		Eval(cmd);
	}
	void Stem(double* CppArr, int CppArrLength, string title = "CppAns", MatlabColor lineColor = MatlabColor::red, string Legend = "CppVar")
	{
		string CppVarname = "CppAns";
		SetVariable(CppArr, CppArrLength, CppVarname);
		char color = (char)lineColor;
		char cmd[500] = { 0 };
		sprintf(cmd, "stem(%s,'%c'),  title('%s'), legend('%s')", CppVarname.c_str(), color, title.c_str(), Legend.c_str());
		Eval(cmd);
	}
	void StemDiffIndex(double* CppArr, int CppArrLength, string MatlabVarName, double Tolerance = 0.0000000001, string title = "CppAns", MatlabColor lineColor = MatlabColor::red, string Legend = "CppVar")
	{
		string CppVarname = "CppAns";
		SetVariable(CppArr, CppArrLength, CppVarname);

		if (NeedTranspose(MatlabVarName, CppArrLength))
		{
			MatlabVarName = "transpose(" + MatlabVarName + ")";
		}

		char color = (char)lineColor;
		char cmd[500] = { 0 };
		sprintf(cmd, "CppDiff = %s-%s ;  CppDiffindex= find(abs(CppDiff)>%0.15lf); if isempty(CppDiffindex)stem(CppDiffindex) ; else  stem(1:length(CppAns),zeros(length(CppAns),1)) ; hold on ; stem(CppDiffindex,CppDiff(CppDiffindex),'%c');hold off;,  title('%s'), legend('%s');ylim([min(CppDiff)-2 max(CppDiff)+2]); end", CppVarname.c_str(), MatlabVarName.c_str(), Tolerance, color, title.c_str(), Legend.c_str());
		Eval(cmd);
	}
	void PlotDiffValue(double* CppArr, int CppArrLength, string MatlabVarName, string title = "CppAns", MatlabColor lineColor = MatlabColor::red, string Legend = "CppVar")
	{
	
		string CppVarname = "CppAns";
		SetVariable(CppArr, CppArrLength, CppVarname);
		char color = (char)lineColor;

		if (NeedTranspose(MatlabVarName, CppArrLength))
		{
			MatlabVarName = "transpose(" + MatlabVarName + ")";
		}

		char cmd[500] = { 0 };
		sprintf(cmd, "plot(%s-%s,'%c'),  title('%s'), legend('%s')", CppVarname.c_str(), MatlabVarName.c_str(), color, title.c_str(), Legend.c_str());
		Eval(cmd);
	}
	bool isSame(double* CppArr, int CppArrLength, string MatlabVarName, double Tolerance = 0.0000000001)
	{
		DimensionClass dim = GetVariableDimension(MatlabVarName);
		string CppVarname = "CppAns";
		SetVariable(CppArr, CppArrLength, CppVarname);

		if (NeedTranspose(MatlabVarName, CppArrLength))
		{
			MatlabVarName = "transpose(" + MatlabVarName + ")";
		}

		char cmd[500] = { 0 };
		sprintf(cmd, "CppDiff = %s-%s ;  CppDiffindex= find(abs(CppDiff)>%0.15lf); ", CppVarname.c_str(), MatlabVarName.c_str(), Tolerance);
		Eval(cmd);

		int differenceIndexCount = GetMatlabVariableLength("CppDiffindex");

		if (differenceIndexCount == 0)
		{
			return true;
		}
		return false;
	}

	double* GetMatlabArrayVariable(string MatlabVarName, int &Length)
	{
		auto m_str = Getchar16(MatlabVarName);
		double* arr = nullptr;
		try
		{
			auto result_m = _matlabptr->getVariable(m_str);


			free(m_str);
			//	auto dim=result_m.getDimensions();
			Length = result_m.getNumberOfElements();
			arr = (double*)malloc(sizeof(double*)*Length);
			for (int i = 0; i < Length; i++)
			{
				//std::complex<short> a(result_m[i]);
				arr[i] = result_m[i];
			}
		}

		catch (...)
		{
			arr = nullptr;
		}
		return arr;
	}
	double GetMatlabScalarVariable(string MatlabVarName)
	{
		auto m_str = Getchar16(MatlabVarName);
		auto result_m = _matlabptr->getVariable(m_str);
		free(m_str);		
		return result_m[0];
	}
	int GetMatlabVariableLength(string MatlabVarName)
	{
		char ss[300] = { 0 };
		sprintf(ss, "length(%s)", MatlabVarName.c_str());
		string str3 = string(ss);
		auto m_str = Getchar16(str3);
		_matlabptr->eval(m_str);
		free(m_str);

		m_str = Getchar16("ans");
		auto result_m = _matlabptr->getVariable(m_str);
		free(m_str);
		int length = result_m[0];
		return length;
	}	
	void SetVariable(double* CppArr, int CppArrLength, string VarName)
	{
		matlab::data::ArrayFactory factory;

		auto data = factory.createArray<double>({ 1, (unsigned __int64)CppArrLength }, &CppArr[0], &CppArr[CppArrLength]);
		
		auto m_str = Getchar16(VarName);
		_matlabptr->setVariable(m_str, data);
		free(m_str);
	}

	double DiffValue_Complex(std::complex<double>* CppArr, int CppArrLength, string MatlabVarName)
	{
		string CppVarname = "CppAns";
		SetVariable_Complex(CppArr, CppArrLength, CppVarname);

		int MatlabVarLength = GetMatlabVariableLength_Complex(MatlabVarName);
		if (MatlabVarLength != CppArrLength)
		{
			return -1;
		}
		if (NeedTranspose(MatlabVarName, CppArrLength))
		{
			MatlabVarName = "transpose(" + MatlabVarName + ")";
		}

		char cmd[500] = { 0 };
		sprintf(cmd, "sum(abs(%s-%s))", MatlabVarName.c_str(), CppVarname.c_str());
		Eval(cmd);

		double ans = GetMatlabScalarVariable("ans");
		return ans;
	}
	void Plot_Complex(std::complex<double>* CppArr, int CppArrLength, string title = "CppAns", MatlabColor lineColor = MatlabColor::red, string Legend = "CppVar")
	{
		string CppVarname = "CppAns";
		SetVariable_Complex(CppArr, CppArrLength, CppVarname);
		char color = (char)lineColor;
		char cmd[500] = { 0 };
		sprintf(cmd, "plot(%s,'%c'),  title('%s'), legend('%s')", CppVarname.c_str(), color, title.c_str(), Legend.c_str());
		Eval(cmd);
	}
	void ScatterPlot_Complex(std::complex<double>* CppArr, int CppArrLength, string title = "CppAns", MatlabColor lineColor = MatlabColor::red, string Legend = "CppVar")
	{
		string CppVarname = "CppAns";
		SetVariable_Complex(CppArr, CppArrLength, CppVarname);
		char color = (char)lineColor;
		char cmd[500] = { 0 };
		sprintf(cmd, "plot(%s,'.%c'),  title('%s'), legend('%s')", CppVarname.c_str(), color, title.c_str(), Legend.c_str());
		Eval(cmd);
	}
	void Stem_Complex(std::complex<double>* CppArr, int CppArrLength, string title = "CppAns", MatlabColor lineColor = MatlabColor::red, string Legend = "CppVar")
	{
		string CppVarname = "CppAns";
		SetVariable_Complex(CppArr, CppArrLength, CppVarname);
		char color = (char)lineColor;
		char cmd[500] = { 0 };
		sprintf(cmd, "stem(%s,'%c'),  title('%s'), legend('%s')", CppVarname.c_str(), color, title.c_str(), Legend.c_str());
		Eval(cmd);
	}
	void StemDiffIndex_Complex(std::complex<double>* CppArr, int CppArrLength, string MatlabVarName, double Tolerance = 0.0000000001, string title = "CppAns", MatlabColor lineColor = MatlabColor::red, string Legend = "CppVar")
	{
		string CppVarname = "CppAns";
		SetVariable_Complex(CppArr, CppArrLength, CppVarname);

		if (NeedTranspose(MatlabVarName, CppArrLength))
		{
			MatlabVarName = "transpose(" + MatlabVarName + ")";
		}

		char color = (char)lineColor;
		char cmd[500] = { 0 };
		sprintf(cmd, "CppDiff = abs(%s)-abs(%s) ;  CppDiffindex= find(abs(CppDiff)>%0.15lf);if isempty(CppDiffindex)stem(CppDiffindex) ; else stem(1:length(CppAns),zeros(length(CppAns),1)) ; hold on ; stem(CppDiffindex,CppDiff(CppDiffindex),'%c');hold off;,  title('%s'), legend('%s');ylim([min(CppDiff)-2 max(CppDiff)+2]); end", CppVarname.c_str(), MatlabVarName.c_str(), Tolerance, color, title.c_str(), Legend.c_str());
		Eval(cmd);
	}
	bool isSame_Complex(std::complex<double>* CppArr, int CppArrLength, string MatlabVarName, double Tolerance = 0.0000000001)
	{
		string CppVarname = "CppAns";
		SetVariable_Complex(CppArr, CppArrLength, CppVarname);

		if (NeedTranspose(MatlabVarName, CppArrLength))
		{
			MatlabVarName = "transpose(" + MatlabVarName + ")";
		}

		char cmd[500] = { 0 };
		sprintf(cmd, "CppDiff = abs(%s)-abs(%s) ;  CppDiffindex= find(abs(CppDiff)>%0.15lf); ", CppVarname.c_str(), MatlabVarName.c_str(), Tolerance);
		Eval(cmd);

		int differenceIndexCount=GetMatlabVariableLength("CppDiffindex");

		if (differenceIndexCount==0)
		{
			return true;
		}
		return false;
	}
	void PlotDiffValue_Complex(std::complex<double>* CppArr, int CppArrLength, string MatlabVarName, string title = "CppAns", MatlabColor lineColor = MatlabColor::red, string Legend = "CppVar")
	{

		string CppVarname = "CppAns";
		SetVariable_Complex(CppArr, CppArrLength, CppVarname);
		char color = (char)lineColor;

		if (NeedTranspose(MatlabVarName, CppArrLength))
		{
			MatlabVarName = "transpose(" + MatlabVarName + ")";
		}

		char cmd[500] = { 0 };
		sprintf(cmd, "plot(abs(%s)-abs(%s),'%c'),  title('%s'), legend('%s')", CppVarname.c_str(), MatlabVarName.c_str(), color, title.c_str(), Legend.c_str());
		Eval(cmd);
	}


	std::complex<double>* GetMatlabArrayVariable_Complex(string MatlabVarName, int &Length)
	{
		auto m_str = Getchar16(MatlabVarName);
		auto result_m = _matlabptr->getVariable(m_str);
		free(m_str);
		//	auto dim=result_m.getDimensions();
		Length = result_m.getNumberOfElements();
		std::complex<double>* arr = (std::complex<double>*)malloc(sizeof(std::complex<double>)*Length);
		for (int i = 0; i < Length; i++)
		{
			//std::complex<short> a(result_m[i]);
			arr[i] = complex<double>(result_m[i]);
		}
		return arr;
	}
	std::complex<double> GetMatlabScalarVariable_Complex(string MatlabVarName)
	{
		auto m_str = Getchar16(MatlabVarName);
		auto result_m = _matlabptr->getVariable(m_str);
		free(m_str);
		return result_m[0];
	}
	int GetMatlabVariableLength_Complex(string MatlabVarName)
	{
		char ss[300] = { 0 };
		sprintf(ss, "length(%s)", MatlabVarName.c_str());
		string str3 = string(ss);
		auto m_str = Getchar16(str3);

		_matlabptr->eval(m_str);
		free(m_str);
		m_str = Getchar16("ans");
		auto result_m = _matlabptr->getVariable(m_str);
		free(m_str);
		int length = result_m[0];
		return length;
	}
	void SetVariable_Complex(std::complex<double>* CppArr, int CppArrLength, string VarName)
	{
		matlab::data::ArrayFactory factory;
		auto data = factory.createArray<std::complex<double>>({ 1, (unsigned __int64)CppArrLength }, &CppArr[0], &CppArr[CppArrLength]);
		auto m_str = Getchar16(VarName);
		_matlabptr->setVariable(m_str, data);
		free(m_str);
	}

	void Eval(const char* cmd)
	{
		string str3 = string(cmd);
		auto m_str = Getchar16(str3);
		_matlabptr->eval(m_str);	
		free(m_str);
	}
	void HoldOn()
	{
		Eval("hold on");
	}
	void HoldOff()
	{
		Eval("hold off");
	}
	void Figure()
	{
		Eval("figure()");
	}
	DimensionClass GetVariableDimension(string MatlabVarName)
	{
		DimensionClass dim;

		char cmd[500] = { 0 };
		sprintf(cmd, "CppArrayDim=size(%s);",MatlabVarName.c_str());
		Eval(cmd);
		int length = 0;
		double* dimlength = GetMatlabArrayVariable("CppArrayDim", length);
		dim.Row = dimlength[0];
		if (length>0)
		{
			dim.Column = dimlength[1];
		}
		if (dimlength)
		{
			free(dimlength);
		}
		return dim;
	}
	bool NeedTranspose(string MatlabVarName, int CppVarColumnCount, int CppVarRowcount=1)
	{
		DimensionClass dimlen= GetVariableDimension(MatlabVarName);
		if (CppVarRowcount == dimlen.Row && CppVarColumnCount == dimlen.Column)
		{
			// it is square matrix
			return false;
		}
		if (CppVarRowcount == dimlen.Column && CppVarColumnCount == dimlen.Row)
		{
			return true;
		}
		return false;

	}
	~MATLABEngineClass()
	{
		//matlab::engine::terminateEngineClient();
	}	

private:

	char16_t* Getchar16(string cmd)
	{
		int length = cmd.length();
		char16_t* cmd16 = (char16_t*)malloc(sizeof(char16_t)* (length + 1));
		for (int i = 0; i < length; i++)
		{
			cmd16[i] = cmd[i];
		}
		cmd16[length] = 0;
		return cmd16;
	}
	static std::unique_ptr<MATLABEngine> _matlabptr;
	string _MatlabSharedEngineName;
	static CRITICAL_SECTION *_CS;
	static bool _inited;

	// static variables should define outside of class body again.
	// if class is Template : static variable define should placed in .h file
	// if class isn't Template : static variable define should placed in .cpp file.
	
};


// Forward declaration of TArr for using in MATLABClass 
template<class T,class Tptr>
class TArr;

template<class T,class Tptr>
class MATLABClass
{
public:

	MATLABClass(TArr<T, Tptr> *A)
	{
		_SourceArr = A;
		_MatlabEng = new MATLABEngineClass(MATLABSharedEngineName);
		
	}

	double Diff(string MatlabVarName)
	{
		double* srcdouble = (double*)malloc(_SourceArr->Length*sizeof(double));
		for (int i = 0; i < _SourceArr->Length; i++)
		{
			srcdouble[i] = _SourceArr->Array[i];
		}
		double diff = _MatlabEng->Diff(srcdouble, _SourceArr->Length, MatlabVarName);
		free(srcdouble);
		return diff;
	}
	void Plot(string title = "CppAns", MatlabColor lineColor = MatlabColor::red, string Legend = "CppVar")
	{
		
			double* srcdouble = (double*)malloc(_SourceArr->Length*sizeof(double));
			for (int i = 0; i < _SourceArr->Length; i++)
			{
				srcdouble[i] = _SourceArr->Array[i];
			}
			_MatlabEng->Plot(srcdouble, _SourceArr->Length, title, lineColor, Legend);
			free(srcdouble);
	
	}
	void ScatterPlot(string title = "CppAns", MatlabColor lineColor = MatlabColor::red, string Legend = "CppVar")
	{

		double* srcdouble = (double*)malloc(_SourceArr->Length*sizeof(double));
		for (int i = 0; i < _SourceArr->Length; i++)
		{
			srcdouble[i] = _SourceArr->Array[i];
		}
		_MatlabEng->ScatterPlot(srcdouble, _SourceArr->Length, , title, lineColor, Legend);
		free(srcdouble);

	}
	void Stem(string title = "CppAns", MatlabColor lineColor = MatlabColor::red, string Legend = "CppVar")
	{

		double* srcdouble = (double*)malloc(_SourceArr->Length*sizeof(double));
		for (int i = 0; i < _SourceArr->Length; i++)
		{
			srcdouble[i] = _SourceArr->Array[i];
		}
		_MatlabEng->Stem(srcdouble, _SourceArr->Length, title, lineColor, Legend);
		free(srcdouble);

	}
	bool isSame(string MatlabVarName, double Tolerance = 0.0000000001)
	{
		double* srcdouble = (double*)malloc(_SourceArr->Length*sizeof(double));
		for (int i = 0; i < _SourceArr->Length; i++)
		{
			srcdouble[i] = _SourceArr->Array[i];
		}
		bool issame = _MatlabEng->isSame(srcdouble, _SourceArr->Length, MatlabVarName, Tolerance);
		free(srcdouble);
		return issame;
	}
	void StemDiffIndex(string MatlabVarName, double Tolerance = 0.0000000001, string title = "CppAns", MatlabColor lineColor = MatlabColor::red, string Legend = "CppVar")
	{
		double* srcdouble = (double*)malloc(_SourceArr->Length*sizeof(double));
		for (int i = 0; i < _SourceArr->Length; i++)
		{
			srcdouble[i] = _SourceArr->Array[i];
		}
		_MatlabEng->StemDiffIndex(srcdouble, _SourceArr->Length, MatlabVarName, Tolerance, title, lineColor, Legend);
		free(srcdouble);

	}
	void HoldOn()
	{
		_MatlabEng->HoldOn();
	}
	void HoldOff()
	{
		_MatlabEng->HoldOff();
	}
	void Figure()
	{
		_MatlabEng->Figure();
	}
	void PlotDiffValue(string MatlabVarName, string title = "CppAns", MatlabColor lineColor = MatlabColor::red, string Legend = "CppVar")
	{

			double* srcdouble = (double*)malloc(_SourceArr->Length*sizeof(double));
			for (int i = 0; i < _SourceArr->Length; i++)
			{
				srcdouble[i] = _SourceArr->Array[i];
			}
			_MatlabEng->PlotDiffValue(srcdouble, _SourceArr->Length, MatlabVarName, title, lineColor, Legend);
			free(srcdouble);
	}
	void LoadFromVar(string MatlabVarName)
	{
		int Length = 0;
		double* arr=_MatlabEng->GetMatlabArrayVariable(MatlabVarName, Length);
		T* srcdouble = (T*)malloc(Length*sizeof(T));
		for (int i = 0; i <Length; i++)
		{
			srcdouble[i] = arr[i];
		}
		_SourceArr->CopyFrom(srcdouble, Length);
		free(srcdouble);
	}
	void SetIntoVar(string MatlabVarName)
	{
		double* srcdouble = (double*)malloc(_SourceArr->Length*sizeof(double));
		for (int i = 0; i < _SourceArr->Length; i++)
		{
			srcdouble[i] = _SourceArr->Array[i];
		}
		_MatlabEng->SetVariable(srcdouble, _SourceArr->Length, MatlabVarName);
		free(srcdouble);
	}
	~MATLABClass()
	{
		delete _MatlabEng;
		_MatlabEng = nullptr;
	}
private:
	TArr<T, Tptr> * _SourceArr =nullptr;
	MATLABEngineClass* _MatlabEng;
	
};

// Forward declaration of TcArr for using in CMATLABClass 
template<class Tc, class Ts, class TcAr, class TsAr>
class TcArr;

template<class Tc, class Ts, class TcAr, class TsAr>
class CMATLABClass
{
public:

	CMATLABClass(TcArr< Tc, Ts, TcAr, TsAr> *A)
	{
		_SourceArr = A;
		_MatlabEng = new MATLABEngineClass(MATLABSharedEngineName);
	}

	double Diff(string MatlabVarName)
	{
		std::complex<double>* srcdouble = (std::complex<double>*)malloc(_SourceArr->Length*sizeof(std::complex<double>));
		for (int i = 0; i < _SourceArr->Length; i++)
		{
			srcdouble[i] = complex<double>(_SourceArr->Array[i].real, _SourceArr->Array[i].imag);
		}
		double diff = _MatlabEng->Diff_Complex(srcdouble, _SourceArr->Length, MatlabVarName);
		free(srcdouble);
		return diff;
	}
	bool isSame(string MatlabVarName, double Tolerance = 0.0000000001)
	{
		std::complex<double>* srcdouble = (std::complex<double>*)malloc(_SourceArr->Length*sizeof(std::complex<double>));
		for (int i = 0; i < _SourceArr->Length; i++)
		{
			srcdouble[i] = complex<double>(_SourceArr->Array[i].real, _SourceArr->Array[i].imag);
		}
		bool issame = _MatlabEng->isSame_Complex(srcdouble, _SourceArr->Length, MatlabVarName, Tolerance);
		free(srcdouble);
		return issame;
	}
	void StemDiffIndex(string MatlabVarName, double Tolerance = 0.0000000001, string title = "CppAns", MatlabColor lineColor = MatlabColor::red, string Legend = "CppVar")
	{
		std::complex<double>* srcdouble = (std::complex<double>*)malloc(_SourceArr->Length*sizeof(std::complex<double>));
		for (int i = 0; i < _SourceArr->Length; i++)
		{
			srcdouble[i] = complex<double>(_SourceArr->Array[i].real, _SourceArr->Array[i].imag);
		}
		_MatlabEng->StemDiffIndex_Complex(srcdouble, _SourceArr->Length, MatlabVarName, Tolerance, title, lineColor, Legend);
		free(srcdouble);
	}
	void Plot(string title = "CppAns", MatlabColor lineColor = MatlabColor::red, string Legend = "CppVar")
	{

		std::complex<double>* srcdouble = (std::complex<double>*)malloc(_SourceArr->Length*sizeof(std::complex<double>));
		for (int i = 0; i < _SourceArr->Length; i++)
		{
			srcdouble[i] = complex<double>(_SourceArr->Array[i].real, _SourceArr->Array[i].imag);
		}
		_MatlabEng->Plot_Complex(srcdouble, _SourceArr->Length, title, lineColor, Legend);
		free(srcdouble);

	}
	void ScatterPlot(string title = "CppAns", MatlabColor lineColor = MatlabColor::red, string Legend = "CppVar")
	{

		std::complex<double>* srcdouble = (std::complex<double>*)malloc(_SourceArr->Length*sizeof(std::complex<double>));
		for (int i = 0; i < _SourceArr->Length; i++)
		{
			srcdouble[i] = complex<double>(_SourceArr->Array[i].real, _SourceArr->Array[i].imag);
		}
		_MatlabEng->ScatterPlot_Complex(srcdouble, _SourceArr->Length, title, lineColor, Legend);
		free(srcdouble);

	}
	void Stem(string title = "CppAns", MatlabColor lineColor = MatlabColor::red, string Legend = "CppVar")
	{

		std::complex<double>* srcdouble = (std::complex<double>*)malloc(_SourceArr->Length*sizeof(std::complex<double>));
		for (int i = 0; i < _SourceArr->Length; i++)
		{
			srcdouble[i] = complex<double>(_SourceArr->Array[i].real, _SourceArr->Array[i].imag);
		}
		_MatlabEng->Stem_Complex(srcdouble, _SourceArr->Length, title, lineColor, Legend);
		free(srcdouble);

	}
	void HoldOn()
	{
		_MatlabEng->HoldOn();
	}
	void HoldOff()
	{
		_MatlabEng->HoldOff();
	}
	void Figure()
	{
		_MatlabEng->Figure();
	}
	void PlotDiffValues(string MatlabVarName, string title = "CppAns", MatlabColor lineColor = MatlabColor::red, string Legend = "CppVar")
	{

		std::complex<double>* srcdouble = (std::complex<double>*)malloc(_SourceArr->Length*sizeof(std::complex<double>));
		for (int i = 0; i < _SourceArr->Length; i++)
		{
			srcdouble[i] = complex<double>(_SourceArr->Array[i].real, _SourceArr->Array[i].imag);
		}
		_MatlabEng->PlotDiffValue_Complex(srcdouble, _SourceArr->Length, MatlabVarName,  title, lineColor, Legend);
		free(srcdouble);
	}
	void SetIntoVar(string MatlabVarName)
	{
		std::complex<double>* srcdouble = (std::complex<double>*)malloc(_SourceArr->Length*sizeof(std::complex<double>));
		for (int i = 0; i < _SourceArr->Length; i++)
		{
			srcdouble[i] = complex<double>(_SourceArr->Array[i].real, _SourceArr->Array[i].imag);
		}
		_MatlabEng->SetVariable_Complex(srcdouble, _SourceArr->Length, MatlabVarName);
		free(srcdouble);
	}
	void Release()
	{
		delete _MatlabEng;
	}
	~CMATLABClass()
	{
		delete _MatlabEng;
		_MatlabEng = nullptr;
	}
private:
	TcArr<Tc, Ts, TcAr, TsAr> * _SourceArr=nullptr;
	MATLABEngineClass* _MatlabEng;
};
#endif

// implementation of template class should placed in class header in .h file 
template<class T,class Tptr>
class TArr
{
protected:
	T* Array = nullptr;
public:
	int Length = 0;
protected:
	int MemSize = 0;
public:

	TArr(int ElementNumber)
	{
		Alloc(ElementNumber);
		IsPointer = false;
#if Use_MATLAB	==1
		MATLAB = new MATLABClass<T, Tptr>(this);
#endif
	}
	TArr(const TArr &obj)
	{
		*this = obj;// copy constructor
		// initialized one object from another of the same type
		// or copy object to pass it as an argument to a function
		// copy an object to return it from a function 
	}
	TArr(void)
	{
#if Use_MATLAB	==1	
		MATLAB = new MATLABClass<T, Tptr>(this);
#endif
	}
	TArr(MemoryManagerClass *MemoryManager)
	{
		MemManager = MemoryManager;
		IsPointer = false;
#if Use_MATLAB	==1
		MATLAB = new MATLABClass<T, Tptr>(this);
#endif
	}
	TArr(int ElementNumber, MemoryManagerClass *MemoryManager)
	{

		MemManager = MemoryManager;
		Alloc(ElementNumber);

		IsPointer = false;
#if Use_MATLAB	==1	
		MATLAB = new MATLABClass<T, Tptr>(this);
#endif
	}
	TArr(T* A, int Alength, bool CopyValues, MemoryManagerClass *MemoryManager)
	{
		MemManager = MemoryManager;
		if (CopyValues)
		{
			CopyFrom(A, Alength);
		}
		else
		{
			SetArray(A, Alength);
		}
		IsPointer = false;
#if Use_MATLAB	==1
		MATLAB = new MATLABClass<T, Tptr>(this);
#endif
	}
	~TArr()
	{
		MemSize = 0;
		Array = nullptr;
		Length = 0;
		TagArr = nullptr;
		TagArrLength = 0;
		TagObject = nullptr;
		MemManager = nullptr;
		IsPointer = false;
#if Use_MATLAB	==1	
		delete MATLAB ;
		MATLAB = nullptr;
#endif
	}

	MemoryManagerClass *MemManager = nullptr;
	
	char* TagArr = nullptr;
	int TagArrLength = 0;
	void* TagObject = nullptr;

#if Use_MATLAB ==1
	friend class MATLABClass<T, Tptr>;
	MATLABClass<T, Tptr>* MATLAB = nullptr;
#endif

	T endValue()
	{
		if (Length > 0)
		{
			return Array[Length - 1];
		}
		return 0;
	}
	int Size()
	{
		return MemSize;
	}
	T At(int Index)
	{
#ifdef DebugBuild
		if (IsPointer)
		{
			if (Index >= Length || Index < 0)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
		else
		{
			if (Index >= MemSize || Index < 0)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}

#endif
		return Array[Index];
	}
	void Free()
	{
	
		if (IsPointer)
		{
			Length = 0;
			return;
		}
		if (Array != nullptr)
		{
			if (MemManager)
			{
				MemManager->FREEMEM((void**)&Array);
			}
			else
			{
				delete[] Array;
			}
			//free(Array);
			Array = nullptr;
			Length = 0;
			MemSize = 0;
		}
		if (TagArr != nullptr)
		{

			if (MemManager)
			{
				MemManager->FREEMEM((void**)&TagArr);
			}
			else
			{
				delete[] TagArr;
			}
			//free(TagArr);
			TagArr = nullptr;
			TagArrLength = 0;
		}
		if (TagObject)
		{
			delete TagObject;
			TagObject = nullptr;
		}
	}
	void SetArray(T* A, int Alength)
	{
#ifdef DebugBuild
		if (Alength<0)
		{
			throw std::invalid_argument("Invalid SetArray");
		}
		if (MemSize > 0)
		{
			throw std::invalid_argument("Memory Leak Occurred");
		}
#endif // DebugBuild
		Array = A;
		Length = Alength;
		MemSize = Alength;

		IsPointer = false;

	}
	void Add_s(T Item)
	{
		if (Length == MemSize)
		{
			//Alloc Bigger Mem and Copy current value To that
			int Init_Size = 16;
			int prelen = Length;
			if (MemSize != 0)
			{
				Init_Size = MemSize * 2;
			}
			T* newArray = AllocMem(Init_Size);
			if (Length > 0)
			{
				memcpy(newArray, Array, sizeof(T)*Length);
			}
			Free();
			Length = prelen;
			Array = newArray;
			MemSize = Init_Size;
		}
		Array[Length++] = Item;

	}
	void Add(T Item)
	{
#ifdef DebugBuild
		if (Length >= MemSize)
		{
			throw std::invalid_argument("Memory Corruption Occurred");
		}
#endif // DebugBuild
		Array[Length++] = Item;

	}
	void Add(T* Arr, int ArrLen)
	{
#ifdef DebugBuild
		if (Length + ArrLen > MemSize)
		{
			throw std::invalid_argument("Memory Corruption Occurred");
		}
#endif // DebugBuild

		T* strptr = &Array[Length];
		int copysize = ArrLen*sizeof(T);
		memcpy(strptr, Arr, copysize);
		Length = Length + ArrLen;

	}
	void Add(TArr Arr)
	{
#ifdef DebugBuild
		if (Length + Arr.Length > MemSize)
		{
			throw std::invalid_argument("Memory Corruption Occurred");
		}
#endif // DebugBuild

		T* strptr = &Array[Length];
		int copysize = Arr.Length*sizeof(T);
		memcpy(strptr, Arr.GetArray(), copysize);
		Length = Length + Arr.Length;

	}
	void RemoveLast()
	{
		if (Length>0)
		{
			Length--;
			Array[Length] = 0;
		}
	}
	T* GetArray(int StartIndex=0)
	{
#ifdef DebugBuild	
		if (IsPointer == false && StartIndex >= MemSize && MemSize >0)
		{
			throw std::invalid_argument(" Invalid GetArray");
		}
#endif
		if (StartIndex == 0)
		{
			return Array;
		}
		else
		{
			return &Array[StartIndex];
		}
		
	}
	T operator [](int index)const
	{
#ifdef DebugBuild
		if (IsPointer)
		{
			if (index >= Length || index < 0)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
		else
		{
			if (index >= MemSize || index < 0)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}

#endif
		return Array[index];
	}
	T & operator [](int index)
	{
#ifdef DebugBuild
		if (IsPointer)
		{
			if (index >= Length || index < 0)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
		else
		{
			if (index >= MemSize || index < 0)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}

#endif
		return Array[index];
	}
	void Alloc(int ElementNumber)
	{
#ifdef DebugBuild
		if (MemSize > 0)
		{
			throw std::invalid_argument("Memory Leak Occured");
		}
#endif // DebugBuild
		Length = 0;
		if (ElementNumber < 1)
		{
			return;
		}
		Array = AllocMem(ElementNumber);
		MemSize = ElementNumber;
	}
	void Clear()
	{
		memset(Array, 0, sizeof(T)*MemSize);
		Length = 0;

	}
	void SetToZero(int StartIndex = 0)
	{
#ifdef DebugBuild		
		if (StartIndex >= Length)
		{
			throw std::invalid_argument(" Invalid SetToZero");
		}
#endif
		memset(&Array[StartIndex], 0, sizeof(T)*(Length - StartIndex));
	}
	void SetToZero(int StartIndex , int EndIndex )
	{
#ifdef DebugBuild		
		if (StartIndex > EndIndex)
		{
			throw std::invalid_argument(" Invalid SetToZero");
		}
#endif
		memset(&Array[StartIndex], 0, sizeof(T)*(EndIndex - StartIndex + 1));
	}
	Tptr GetPointer(int StartIndex, int endIndex)
	{

#ifdef DebugBuild	
		
		if (StartIndex >= Length || StartIndex < 0 || endIndex >= Length || endIndex < 0 || endIndex < StartIndex)
		{
			throw std::invalid_argument(" Invalid GetPointer");
		}
#endif

		Tptr p;
		p.Array = &this->Array[StartIndex];
		p.Length = endIndex - StartIndex + 1;
		p.MemSize = 0;
		p.IsPointer = true;
		p.MemManager = MemManager;
		
		return p;
	}
	Tptr GetPointer(int StartIndex=0)
	{

		int endIndex = Length - 1;
#ifdef DebugBuild		
		if (StartIndex >= Length || StartIndex < 0 || endIndex >= Length || endIndex < 0 || endIndex < StartIndex)
		{
			throw std::invalid_argument(" Invalid GetPointer");
		}
#endif

		Tptr p;
		p.Array = &this->Array[StartIndex];
		p.Length = endIndex - StartIndex + 1;
		p.MemSize = 0;
		p.IsPointer = true;
		p.MemManager = MemManager;
		
		return p;
	}
	Tptr GetSubArray(int StartIndex, int SubLength)
	{
#ifdef DebugBuild
		if (IsPointer)
		{
			if (StartIndex + SubLength > Length)
			{
				throw std::invalid_argument("Out Of Memory Index ");
			}
		}
		else
		{
			if (StartIndex + SubLength > MemSize)
			{
				throw std::invalid_argument("Out Of Memory Index ");
			}
		}
#endif // DebugBuild
		T* Sub = AllocMem(Length);
		memcpy(Sub, &Array[StartIndex], SubLength*sizeof(T));
		Tptr res = Tptr(Sub, SubLength, false, MemManager);
		return res;
	}
	void CopyFrom(TArr Source)
	{
		if (MemSize < Source.Length)
		{
			Free();
			Alloc(Source.Length);
		}
		else
		{
			memset(Array, 0, MemSize*sizeof(T));
		}
		memcpy(Array, Source.Array, Source.Length*sizeof(T));
		Length = Source.Length;
		if (Source.TagArr)
		{
			if (MemManager)
			{
				TagArr = MemManager->AllocChar(Source.TagArrLength);
			}
			else
			{
				TagArr = new char[Source.TagArrLength]();
			}
			//TagArr = (char*)malloc(sizeof(char)*Source.TagArrLength);
			memcpy(TagArr, Source.TagArr, sizeof(char)*Source.TagArrLength);
			TagArrLength = Source.TagArrLength;
		}

	}
	void CopyFrom(T* Source, int ElementNumber)
	{
		if (MemSize < ElementNumber)
		{
			Free();
			Alloc(ElementNumber);
		}
		else
		{
			memset(Array, 0, MemSize*sizeof(T));
		}
		memcpy(Array, Source, ElementNumber*sizeof(T));
		Length = ElementNumber;
	}
	void CopyFrom(int DstStartIndex, TArr Source)
	{
		int Endindex = DstStartIndex + Source.Length - 1;
#ifdef DebugBuild
		if (Endindex >= MemSize)
		{
			throw std::invalid_argument(" Copy From Out Of Memory");
		}
#endif // DebugBuild
		memcpy(&Array[DstStartIndex], Source.Array, Source.Length*sizeof(T));
		if (Endindex >= Length)
		{
			Length = Endindex + 1;
		}
	}
	void CopyFrom(int DstStartIndex, T* Source, int ElementNumber)
	{
		int Endindex = DstStartIndex + ElementNumber - 1;
#ifdef DebugBuild
		if (Endindex >= MemSize)
		{
			throw std::invalid_argument(" Copy From Out Of Memory");
		}
#endif // DebugBuild
		memcpy(&Array[DstStartIndex], Source, ElementNumber*sizeof(T));
		if (Endindex >= Length)
		{
			Length = Endindex + 1;
		}
	}
	Tptr Copy()
	{
		Tptr cpy = Tptr(Array, Length, true, MemManager);
		return cpy;
	}

	int LoadFromBinaryCharFile(const char* Path, unsigned int MaxReadCount = 0)
	{
		Free();
		//FILE* fod = fopen(Path, "rb");
		FILE* fod;
		fopen_s(&fod, Path, "rb");
		fseek(fod, 0, SEEK_END);
		int  bytelength = ftell(fod);
		fseek(fod, 0, SEEK_SET);

		int InputFileLength = bytelength / sizeof(char);
		if (MaxReadCount > 0)
		{
			InputFileLength = MaxReadCount ;	
		}
		char* InPutFile = (char*)malloc(sizeof(char)*InputFileLength);
		memset(InPutFile, 0, sizeof(char)*InputFileLength);
		size_t size = fread(InPutFile, sizeof(char), InputFileLength, fod);
		fclose(fod);

		Alloc(InputFileLength);

		for (int i = 0; i < InputFileLength; i++)
		{
			Array[i] = InPutFile[i];
		}
		Length = InputFileLength;
		free(InPutFile);
		return 1;
	}
	int LoadFromBinaryShortFile(const char* Path, unsigned int MaxReadCount = 0)
	{
		Free();
		//FILE* fod = fopen(Path, "rb");
		FILE* fod;
		fopen_s(&fod, Path, "rb");
		fseek(fod, 0, SEEK_END);
		int  bytelength = ftell(fod);
		fseek(fod, 0, SEEK_SET);

		int InputFileLength = bytelength / sizeof(short);
		if (MaxReadCount > 0)
		{
			InputFileLength = MaxReadCount;
		}
		short* InPutFile = (short*)malloc(sizeof(short)*InputFileLength);
		memset(InPutFile, 0, sizeof(short)*InputFileLength);
		size_t size = fread(InPutFile, sizeof(short), InputFileLength, fod);
		fclose(fod);

		Alloc(InputFileLength);

		for (int i = 0; i < InputFileLength; i++)
		{
			Array[i] = InPutFile[i];
		}
		Length = InputFileLength;
		free(InPutFile);
		return 1;
	}
	int LoadFromBinaryIntFile(const char* Path, unsigned int MaxReadCount = 0)
	{
		Free();
		//FILE* fod = fopen(Path, "rb");
		FILE* fod;
		fopen_s(&fod, Path, "rb");
		fseek(fod, 0, SEEK_END);
		int  bytelength = ftell(fod);
		fseek(fod, 0, SEEK_SET);

		int InputFileLength = bytelength / sizeof(int);
		if (MaxReadCount > 0)
		{
			InputFileLength = MaxReadCount;
		}
		int* InPutFile = (int*)malloc(sizeof(int)*InputFileLength);
		memset(InPutFile, 0, sizeof(int)*InputFileLength);
		size_t size = fread(InPutFile, sizeof(int), InputFileLength, fod);
		fclose(fod);

		Alloc(InputFileLength);

		for (int i = 0; i < InputFileLength; i++)
		{
			Array[i] = InPutFile[i];
		}
		Length = InputFileLength;
		free(InPutFile);
		return 1;
	}
	int LoadFromBinaryFloatFile(const char* Path, unsigned int MaxReadCount = 0)
	{
		Free();
		//FILE* fod = fopen(Path, "rb");
		FILE* fod;
		fopen_s(&fod, Path, "rb");
		fseek(fod, 0, SEEK_END);
		int  bytelength = ftell(fod);
		fseek(fod, 0, SEEK_SET);

		int InputFileLength = bytelength / sizeof(float);
		if (MaxReadCount > 0)
		{
			InputFileLength = MaxReadCount;
		}
		float* InPutFile = (float*)malloc(sizeof(float)*InputFileLength);
		memset(InPutFile, 0, sizeof(float)*InputFileLength);
		size_t size = fread(InPutFile, sizeof(float), InputFileLength, fod);
		fclose(fod);

		Alloc(InputFileLength);

		for (int i = 0; i < InputFileLength; i++)
		{
			Array[i] = InPutFile[i];
		}
		Length = InputFileLength;
		free(InPutFile);
		return 1;
	}
	int LoadFromBinaryDoubleFile(const char* Path, unsigned int MaxReadCount = 0)
	{
		Free();
		//FILE* fod = fopen(Path, "rb");
		FILE* fod;
		fopen_s(&fod, Path, "rb");
		fseek(fod, 0, SEEK_END);
		int  bytelength = ftell(fod);
		fseek(fod, 0, SEEK_SET);

		int InputFileLength = bytelength / sizeof(double);
		if (MaxReadCount > 0)
		{
			InputFileLength = MaxReadCount;
		}
		double* InPutFile = (double*)malloc(sizeof(double)*InputFileLength);
		memset(InPutFile, 0, sizeof(double)*InputFileLength);
		size_t size = fread(InPutFile, sizeof(double), InputFileLength, fod);
		fclose(fod);

		Alloc(InputFileLength);

		for (int i = 0; i < InputFileLength; i++)
		{
			Array[i] = InPutFile[i];
		}
		Length = InputFileLength;
		free(InPutFile);
		return 1;
	}
	int WriteToBinaryCharFile(const char* Path, bool Append)
	{
		FILE * pfile;
		string writeMode;
		if (!Append)
			writeMode = "wb";
		else
			writeMode = "ab";
		//pfile = fopen(Path, writeMode.c_str());
		fopen_s(&pfile, Path, writeMode.c_str());
		if (pfile != NULL)
		{
			for (int j = 0; j < Length; j++)
			{
				char  real = Array[j];
				fwrite(&real, sizeof(char), 1, pfile);
			}
			fclose(pfile);
			return 0;
		}
		else
		{
			int err = GetSystemError();
			return err;
		}
		return 1;
	}
	int WriteToBinaryShortFile(const char* Path, bool Append)
	{
		FILE * pfile;
		string writeMode;
		if (!Append)
			writeMode = "wb";
		else
			writeMode = "ab";
		//pfile = fopen(Path, writeMode.c_str());
		fopen_s(&pfile, Path, writeMode.c_str());
		if (pfile != NULL)
		{
			for (int j = 0; j < Length; j++)
			{
				short  real = Array[j];
				fwrite(&real, sizeof(short), 1, pfile);
			}
			fclose(pfile);
			return 0;
		}
		else
		{
			int err = GetSystemError();
			return err;
		}
		return 1;
	}
	int WriteToBinaryIntFile(const char* Path, bool Append)
	{
		FILE * pfile;
		string writeMode;
		if (!Append)
			writeMode = "wb";
		else
			writeMode = "ab";
		//pfile = fopen(Path, writeMode.c_str());
		fopen_s(&pfile, Path, writeMode.c_str());
		if (pfile != NULL)
		{
			for (int j = 0; j < Length; j++)
			{
				int  real = Array[j];
				fwrite(&real, sizeof(int), 1, pfile);
			}
			fclose(pfile);
			return 0;
		}
		else
		{
			int err = GetSystemError();
			return err;
		}
		return 1;
	}
	int WriteToBinaryFloatFile(const char* Path, bool Append)
	{
		FILE * pfile;
		string writeMode;
		if (!Append)
			writeMode = "wb";
		else
			writeMode = "ab";
		//pfile = fopen(Path, writeMode.c_str());
		fopen_s(&pfile, Path, writeMode.c_str());
		if (pfile != NULL)
		{
			for (int j = 0; j < Length; j++)
			{
				float  real = Array[j];
				fwrite(&real, sizeof(float), 1, pfile);
			}
			fclose(pfile);
			return 0;
		}
		else
		{
			int err = GetSystemError();
			return err;
		}
		return 1;
	}
	int WriteToBinaryDoubleFile(const char* Path, bool Append)
	{
		FILE * pfile;
		string writeMode;
		if (!Append)
			writeMode = "wb";
		else
			writeMode = "ab";
		//pfile = fopen(Path, writeMode.c_str());
		fopen_s(&pfile, Path, writeMode.c_str());
		if (pfile != NULL)
		{
			for (int j = 0; j < Length; j++)
			{
				double  real = Array[j];
				fwrite(&real, sizeof(double), 1, pfile);
			}
			fclose(pfile);
			return 0;
		}
		else
		{
			int err = GetSystemError();
			return err;
		}
		return 1;
	}
	void TransferArrayToOwnMemory()
	{
		if (MemManager)
		{
			if (MemManager->_UseSelfMemoryManagement)
			{
				TArr tmp;
				tmp.CopyFrom(*this);
				Free();
				*this = tmp;
			}
			MemManager = nullptr;
		}

	}

	TArr & operator   =  (const TArr &right)
	{
		//	Free();// if this has memory,  release that
#ifdef DebugBuild
		if (MemSize > 0 && Array != right.Array)
		{
			throw std::invalid_argument("Memory Leak Occurred");
		}
#endif // DebugBuild
		Array = right.Array;
		Length = right.Length;
		MemSize = right.MemSize;
		TagArr = right.TagArr;
		TagArrLength = right.TagArrLength;
		MemManager = right.MemManager;
		IsPointer = right.IsPointer;
		TagObject = right.TagObject;
#if Use_MATLAB	==1
		if (!MATLAB)
		{
			MATLAB = new MATLABClass<T,  Tptr>(this);
		}
#endif
		return *this;
	}

	TArr operator + (TArr& right)
	{
#ifdef DebugBuild
		if (IsPointer)
		{
			if (right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
		else
		{
			if (Length > MemSize || right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
#endif
		TArr res = TArr(Length, MemManager);
		for (int i = 0; i < Length; i++)
		{
			res[i] = Array[i] + right[i];
		}
		res.Length = Length;
		return res;
	}
	TArr operator + (T rightX)
	{
		TArr res = TArr(Length, MemManager);
		for (int i = 0; i < Length; i++)
		{
			res[i] = Array[i] + rightX;
		}
		res.Length = Length;
		return res;
	}

	TArr operator - (TArr& right)
	{
#ifdef DebugBuild
		if (IsPointer)
		{
			if (right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
		else
		{
			if (Length > MemSize || right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
#endif
		TArr res = TArr(Length, MemManager);
		for (int i = 0; i < Length; i++)
		{
			res[i] = Array[i] - right[i];
		}
		res.Length = Length;
		return res;
	}
	TArr operator - (T rightX)
	{
		TArr res = TArr(Length, MemManager);
		for (int i = 0; i < Length; i++)
		{
			res[i] = Array[i] - rightX;
		}
		res.Length = Length;
		return res;
	}

	TArr operator * (TArr& right)
	{
#ifdef DebugBuild
		if (IsPointer)
		{
			if (right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
		else
		{
			if (Length > MemSize || right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
#endif
		TArr res = TArr(Length, MemManager);
		for (int i = 0; i < Length; i++)
		{
			res[i] = Array[i] * right[i];
		}
		res.Length = Length;
		return res;
	}
	TArr operator * (T rightX)
	{
		TArr res = TArr(Length, MemManager);
		for (int i = 0; i < Length; i++)
		{
			res[i] = Array[i] * rightX;
		}
		res.Length = Length;
		return res;
	}

	TArr operator / (TArr& right)
	{
#ifdef DebugBuild
		if (IsPointer)
		{
			if (right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
		else
		{
			if (Length > MemSize || right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
#endif
		TArr res = TArr(Length, MemManager);
		for (int i = 0; i < Length; i++)
		{
			res[i] = Array[i] / right[i];
		}
		res.Length = Length;
		return res;
	}
	TArr operator / (T rightX)
	{
		TArr res = TArr(Length, MemManager);
		for (int i = 0; i < Length; i++)
		{
			res[i] = Array[i] / rightX;
		}
		res.Length = Length;
		return res;
	}

	TArr operator += (TArr& right)
	{
#ifdef DebugBuild
		if (IsPointer)
		{
			if (right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
		else
		{
			if (Length > MemSize || right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
#endif		
		for (int i = 0; i < Length; i++)
		{
			Array[i] = Array[i] + right[i];
		}
		return *this;
	}
	TArr operator += (T rightX)
	{
		for (int i = 0; i < Length; i++)
		{
			Array[i] = Array[i] + rightX;
		}
		return *this;
	}

	TArr operator -= (TArr& right)
	{
#ifdef DebugBuild
		if (IsPointer)
		{
			if (right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
		else
		{
			if (Length > MemSize || right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
#endif		
		for (int i = 0; i < Length; i++)
		{
			Array[i] = Array[i] - right[i];
		}
		return *this;
	}
	TArr operator -= (T rightX)
	{
		for (int i = 0; i < Length; i++)
		{
			Array[i] = Array[i] - rightX;
		}
		return *this;
	}

	TArr operator *= (TArr& right)
	{
#ifdef DebugBuild
		if (IsPointer)
		{
			if (right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
		else
		{
			if (Length > MemSize || right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
#endif		
		for (int i = 0; i < Length; i++)
		{
			Array[i] = Array[i] * right[i];
		}
		return *this;
	}
	TArr operator *= (T rightX)
	{
		for (int i = 0; i < Length; i++)
		{
			Array[i] = Array[i] * rightX;
		}
		return *this;
	}

	TArr operator /= (TArr& right)
	{
#ifdef DebugBuild
		if (IsPointer)
		{
			if (right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
		else
		{
			if (Length > MemSize || right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
#endif		
		for (int i = 0; i < Length; i++)
		{
			Array[i] = Array[i] / right[i];
		}
		return *this;
	}
	TArr operator /= (T rightX)
	{
		for (int i = 0; i < Length; i++)
		{
			Array[i] = Array[i] / rightX;
		}
		return *this;
	}

	TArr operator > (TArr& right)
	{
#ifdef DebugBuild
		if (IsPointer)
		{
			if (right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
		else
		{
			if (Length > MemSize || right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
#endif
		TArr res = TArr(Length, MemManager);
		for (int i = 0; i < Length; i++)
		{
			if (Array[i]>right[i])
			{
				res[i] = 1;
			}
			else
			{
				res[i] = 0;
			}
		}
		res.Length = Length;
		return res;
	}
	TArr operator > (T rightX)
	{
		TArr res = TArr(Length, MemManager);
		for (int i = 0; i < Length; i++)
		{
			if (Array[i]>rightX)
			{
				res[i] = 1;
			}
			else
			{
				res[i] = 0;
			}
		}
		res.Length = Length;
		return res;
	}

	TArr operator < (TArr& right)
	{
#ifdef DebugBuild
		if (IsPointer)
		{
			if (right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
		else
		{
			if (Length > MemSize || right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
#endif
		TArr res = TArr(Length, MemManager);
		for (int i = 0; i < Length; i++)
		{
			if (Array[i] < right[i])
			{
				res[i] = 1;
			}
			else
			{
				res[i] = 0;
			}
		}
		res.Length = Length;
		return res;
	}
	TArr operator < (T rightX)
	{
		TArr res = TArr(Length, MemManager);
		for (int i = 0; i < Length; i++)
		{
			if (Array[i] < rightX)
			{
				res[i] = 1;
			}
			else
			{
				res[i] = 0;
			}
		}
		res.Length = Length;
		return res;
	}

	TArr operator >= (TArr& right)
	{
#ifdef DebugBuild
		if (IsPointer)
		{
			if (right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
		else
		{
			if (Length > MemSize || right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
#endif
		TArr res = TArr(Length, MemManager);
		for (int i = 0; i < Length; i++)
		{
			if (Array[i] >= right[i])
			{
				res[i] = 1;
			}
			else
			{
				res[i] = 0;
			}
		}
		res.Length = Length;
		return res;
	}
	TArr operator >= (T rightX)
	{
		TArr res = TArr(Length, MemManager);
		for (int i = 0; i < Length; i++)
		{
			if (Array[i] >= rightX)
			{
				res[i] = 1;
			}
			else
			{
				res[i] = 0;
			}
		}
		res.Length = Length;
		return res;
	}

	TArr operator <= (TArr& right)
	{
#ifdef DebugBuild
		if (IsPointer)
		{
			if (right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
		else
		{
			if (Length > MemSize || right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
#endif
		TArr res = TArr(Length, MemManager);
		for (int i = 0; i < Length; i++)
		{
			if (Array[i] <=  right[i])
			{
				res[i] = 1;
			}
			else
			{
				res[i] = 0;
			}
		}
		res.Length = Length;
		return res;
	}
	TArr operator <= (T rightX)
	{
		TArr res = TArr(Length, MemManager);
		for (int i = 0; i < Length; i++)
		{
			if (Array[i] <=  rightX)
			{
				res[i] = 1;
			}
			else
			{
				res[i] = 0;
			}
		}
		res.Length = Length;
		return res;
	}

	TArr operator == (TArr& right)
	{
#ifdef DebugBuild
		if (IsPointer)
		{
			if (right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
		else
		{
			if (Length > MemSize || right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
#endif
		TArr res = TArr(Length, MemManager);
		for (int i = 0; i < Length; i++)
		{
			if (Array[i] == right[i])
			{
				res[i] = 1;
			}
			else
			{
				res[i] = 0;
			}
		}
		res.Length = Length;
		return res;
	}
	TArr operator == (T rightX)
	{
		TArr res = TArr(Length, MemManager);
		for (int i = 0; i < Length; i++)
		{
			if (Array[i] == rightX)
			{
				res[i] = 1;
			}
			else
			{
				res[i] = 0;
			}
		}
		res.Length = Length;
		return res;
	}
protected:

	T* AllocMem(int ElementNumber)
	{
		T*  arr = nullptr;
		if (MemManager)
		{
			//	arr = MemManager->AllocChar(ElementNumber);
			arr = (T*)MemManager->AllocVoid(ElementNumber, sizeof(T));
		}
		else
		{
			arr = new T[ElementNumber]();
		}
		return arr;
	}
	bool IsPointer = false;
	int GetSystemError()
	{
#ifdef _MSC_VER 
		return GetLastError();
#else
		return -1;
#endif
	}
#ifndef _MSC_VER
	int fopen_s(FILE** f, const char* name, const char* mode)
	{
		int ret = 0;
		*f = fopen(name, mode);
		if (!*f)
		{
			ret = errno;
		}
		return ret;
	}
#endif

};

// implementation of template class should placed in class header in .h file 
template<class Tc,class Ts,class TcAr,class TsAr>
class TcArr
{
protected:
	Tc* Array = nullptr;
public:
	int Length = 0;
protected:
	int MemSize = 0;
public:

	TcArr(void)
	{
#if Use_MATLAB	==1
		MATLAB = new CMATLABClass<Tc, Ts, TcAr, TsAr>(this);
#endif
	}
	TcArr(int ElementNumber)
	{
		Alloc(ElementNumber);
#if Use_MATLAB	==1
		MATLAB = new CMATLABClass<Tc, Ts, TcAr, TsAr>(this);
#endif
	}
	TcArr(MemoryManagerClass *MemoryManager)
	{
		MemManager = MemoryManager;
#if Use_MATLAB	==1	
		MATLAB = new CMATLABClass<Tc, Ts, TcAr, TsAr>(this);
#endif
	}
	TcArr(int ElementNumber, MemoryManagerClass *MemoryManager)
	{
		MemManager = MemoryManager;
		Alloc(ElementNumber);
#if Use_MATLAB	==1
		MATLAB = new CMATLABClass<Tc, Ts, TcAr, TsAr>(this);
#endif
	}
	TcArr(Tc* A, int Alength, bool CopyValues, MemoryManagerClass *MemoryManager)
	{
		MemManager = MemoryManager;

		if (CopyValues)
		{
			CopyFrom(A, Alength);
		}
		else
		{
			SetArray(A, Alength);
		}
#if Use_MATLAB	==1
		MATLAB = new CMATLABClass<Tc, Ts, TcAr, TsAr>(this);
#endif
	}
	TcArr(Ts* real, int length, MemoryManagerClass *MemoryManager)
	{

		MemManager = MemoryManager;
		Alloc(length);

		for (int i = 0; i < length; i++)
		{
			Array[i].real = real[i];
		}
		Length = length;
#if Use_MATLAB	==1	
		MATLAB = new CMATLABClass<Tc, Ts, TcAr, TsAr>(this);
#endif
	}
	TcArr(Ts* real, Ts* imag, int length, MemoryManagerClass *MemoryManager)
	{

		MemManager = MemoryManager;
		Alloc(length);

		for (int i = 0; i < length; i++)
		{
			Array[i].real = real[i];
			Array[i].imag = imag[i];
		}
		Length = length;

#if Use_MATLAB	==1	
		MATLAB = new CMATLABClass<Tc, Ts, TcAr, TsAr>(this);
#endif

	}
	TcArr(const TcArr &obj)
	{
		*this = obj;// copy constructor
		// initialized one object from another of the same type
		// or copy object to pass it as an argument to a function
		// copy an object to return it from a function 
	}
	~TcArr()
	{
		MemSize = 0;
		Array = nullptr;
		Length = 0;
		TagArr = nullptr;
		TagArrLength = 0;
		TagObject = nullptr;
		MemManager = nullptr;
		IsPointer = false;
#if Use_MATLAB	==1
		delete MATLAB;
		MATLAB = nullptr;
#endif
	}

#if Use_MATLAB == 1
	friend class CMATLABClass< Tc,  Ts,  TcAr,  TsAr>;
	CMATLABClass<Tc, Ts, TcAr, TsAr>* MATLAB = nullptr;
#endif

	TcArr operator + (TcArr& right)
	{
#ifdef DebugBuild
		if (IsPointer)
		{
			if (right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
		else
		{
			if (Length > MemSize || right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
#endif
		TcArr res = TcArr(Length, MemManager);
		for (int i = 0; i < Length; i++)
		{
			res[i] = Array[i] + right[i];
		}
		res.Length = Length;
		return res;
	}
	TcArr operator + (Tc rightX)
	{
		TcArr res = TcArr(Length, MemManager);
		for (int i = 0; i < Length; i++)
		{
			res[i] = Array[i] + rightX;
		}
		res.Length = Length;
		return res;
	}
	TcArr operator + (Ts rightX)
	{
		TcArr res = TcArr(Length, MemManager);
		for (int i = 0; i < Length; i++)
		{
			res[i] = Array[i] + rightX;
		}
		res.Length = Length;
		return res;
	}

	TcArr operator - (TcArr& right)
	{
#ifdef DebugBuild
		if (IsPointer)
		{
			if (right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
		else
		{
			if (Length > MemSize || right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
#endif
		TcArr res = TcArr(Length, MemManager);
		for (int i = 0; i < Length; i++)
		{
			res[i] = Array[i] - right[i];
		}
		res.Length = Length;
		return res;
	}
	TcArr operator - (Tc rightX)
	{
		TcArr res = TcArr(Length, MemManager);
		for (int i = 0; i < Length; i++)
		{
			res[i] = Array[i] - rightX;
		}
		res.Length = Length;
		return res;
	}
	TcArr operator - (Ts rightX)
	{
		TcArr res = TcArr(Length, MemManager);
		for (int i = 0; i < Length; i++)
		{
			res[i] = Array[i] - rightX;
		}
		res.Length = Length;
		return res;
	}

	TcArr operator * (TcArr& right)
	{
#ifdef DebugBuild
		if (IsPointer)
		{
			if (right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
		else
		{
			if (Length > MemSize || right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
#endif
		TcArr res = TcArr(Length, MemManager);
		for (int i = 0; i < Length; i++)
		{
			res[i] = Array[i] * right[i];
		}
		res.Length = Length;
		return res;
	}
	TcArr operator * (Tc rightX)
	{
		TcArr res = TcArr(Length, MemManager);
		for (int i = 0; i < Length; i++)
		{
			res[i] = Array[i] * rightX;
		}
		res.Length = Length;
		return res;
	}
	TcArr operator * (Ts rightX)
	{
		TcArr res = TcArr(Length, MemManager);
		for (int i = 0; i < Length; i++)
		{
			res[i] = Array[i] * rightX;
		}
		res.Length = Length;
		return res;
	}

	TcArr operator / (TcArr& right)
	{
#ifdef DebugBuild
		if (IsPointer)
		{
			if (right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
		else
		{
			if (Length > MemSize || right.Length < Length)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
#endif
		TcArr res = TcArr(Length, MemManager);
		for (int i = 0; i < Length; i++)
		{
			res[i] = Array[i] / right[i];
		}
		res.Length = Length;
		return res;
	}
	TcArr operator / (Ts rightX)
	{
		TcArr res = TcArr(Length, MemManager);
		for (int i = 0; i < Length; i++)
		{
			res[i] = Array[i] / rightX;
		}
		res.Length = Length;
		return res;
	}
	TcArr operator / (Tc rightX)
	{
		TcArr res = TcArr(Length, MemManager);
		for (int i = 0; i < Length; i++)
		{
			res[i] = Array[i] / rightX;
		}
		res.Length = Length;
		return res;
	}
	MemoryManagerClass *MemManager = nullptr;
	
	char* TagArr = nullptr;
	int TagArrLength = 0;
	void* TagObject = nullptr;
	Tc endValue()
	{
		if (Length > 0)
		{
			return Array[Length - 1];
		}
		Tc ret;
		ret.real = 0;
		ret.imag = 0;
		return ret;
	}
	int Size()
	{
		return MemSize;
	}
	Tc At(int Index)
	{
#ifdef DebugBuild
		if (IsPointer)
		{
			if (Index >= Length || Index < 0)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
		else
		{
			if (Index >= MemSize || Index < 0)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}

#endif
		return Array[Index];
	}
	void Free()
	{
	
		if (IsPointer)
		{
			Length = 0;
			return;
		}
		if (Array != nullptr)
		{
			if (MemManager)
			{
				MemManager->FREEMEM((void**)&Array);
			}
			else
			{
				delete[] Array;
			}
			//free(Array);
			Array = nullptr;
			Length = 0;
			MemSize = 0;
		}
		if (TagArr != nullptr)
		{
			if (MemManager)
			{
				MemManager->FREEMEM((void**)&TagArr);
			}
			else
			{
				delete[] TagArr;
			}
			//free(TagArr);
			TagArr = nullptr;
			TagArrLength = 0;
		}
		if (TagObject)
		{
			delete TagObject;
			TagObject = nullptr;
		}

	}
	void SetArray(Tc* A, int Alength)
	{
#ifdef DebugBuild
		if (Alength < 0)
		{
			throw std::invalid_argument("Invalid SetArray");
		}
		if (MemSize > 0)
		{
			throw std::invalid_argument("Memory Leak Occurred");
		}
#endif // DebugBuild
		Array = A;
		Length = Alength;
		MemSize = Alength;

		IsPointer = false;

	}

	void Add_s(Tc Item)
	{
		if (Length == MemSize)
		{
			//Alloc Bigger Mem and Copy current value To that
			int Init_Size = 16;
			int prelen = Length;
			if (MemSize != 0)
			{
				Init_Size = MemSize * 2;
			}
			Tc* newArray = AllocMem(Init_Size);
			if (Length > 0)
			{
				memcpy(newArray, Array, sizeof(Tc)*Length);
			}
			Free();
			Length = prelen;
			Array = newArray;
			MemSize = Init_Size;
		}
		Array[Length].real = Item.real;
		Array[Length++].imag = Item.imag;

	}
	void Add(Tc Item)
	{
#ifdef DebugBuild
		if (Length >= MemSize)
		{
			throw std::invalid_argument("Memory Corruption Occurred");
		}
#endif // DebugBuild
		Array[Length].real = Item.real;
		Array[Length++].imag = Item.imag;

	}
	void Add_s(Ts real, Ts imag)
	{
		if (Length == MemSize)
		{
			//Alloc Bigger Mem and Copy current value To that
			int Init_Size = 16;
			int prelen = Length;
			if (MemSize != 0)
			{
				Init_Size = MemSize * 2;
			}
			Tc* newArray = AllocMem(Init_Size);
			if (Length > 0)
			{
				memcpy(newArray, Array, sizeof(Tc)*Length);
			}
			Free();
			Length = prelen;
			Array = newArray;
			MemSize = Init_Size;
		}
		Array[Length].real = real;
		Array[Length++].imag = imag;

	}
	void Add(Ts real, Ts imag)
	{
#ifdef DebugBuild
		if (Length >= MemSize)
		{
			throw std::invalid_argument("Memory Corruption Occurred");
		}
#endif // DebugBuild
		Array[Length].real = real;
		Array[Length++].imag = imag;

	}
	void Add(Tc* Arr, int ArrLen)
	{
#ifdef DebugBuild
		if (Length+ArrLen > MemSize)
		{
			throw std::invalid_argument("Memory Corruption Occurred");
		}
#endif // DebugBuild
		
		Tc* strptr = &Array[Length];
		int copysize = ArrLen*sizeof(Tc);
		memcpy(strptr, Arr, copysize);
		Length= Length + ArrLen;
	}
	void Add(TcArr Arr)
	{
#ifdef DebugBuild
		if (Length + Arr.Length > MemSize)
		{
			throw std::invalid_argument("Memory Corruption Occurred");
		}
#endif // DebugBuild

		Tc* strptr = &Array[Length];
		int copysize = Arr.Length*sizeof(Tc);
		memcpy(strptr, Arr.GetArray(), copysize);
		Length = Length + Arr.Length;

	}
	void RemoveLast()
	{
		if (Length > 0)
		{
			Length--;
			Array[Length].real = 0;
			Array[Length].imag = 0;
		}
	}
	Tc* GetArray(int StartIndex=0)
	{
#ifdef DebugBuild	
		if (IsPointer == false && StartIndex >= MemSize && MemSize >0)
		{
			throw std::invalid_argument(" Invalid GetArray");
		}
#endif
		if (StartIndex==0)
		{
			return Array;
		}
		else
		{
			return &Array[StartIndex];
		}
	}
	Tc operator [](int index)const
	{
#ifdef DebugBuild
		if (IsPointer)
		{
			if (index >= Length || index < 0)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
		else
		{
			if (index >= MemSize || index < 0)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}

#endif
		return Array[index];
	}
	Tc & operator [](int index)
	{
#ifdef DebugBuild
		if (IsPointer)
		{
			if (index >= Length || index < 0)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}
		else
		{
			if (index >= MemSize || index < 0)
			{
				throw std::invalid_argument("Access invalid index");
			}
		}

#endif
		return Array[index];
	}
	void Alloc(int ElementNumber)
	{
#ifdef DebugBuild
		if (MemSize > 0)
		{
			throw std::invalid_argument("Memory Leak Occured");
		}
#endif // DebugBuild
		Length = 0;
		if (ElementNumber < 1)
		{
			return;
		}
		Array = AllocMem(ElementNumber);
		MemSize = ElementNumber;

	}
	void Clear()
	{
		memset(Array, 0, sizeof(Tc)*MemSize);
		Length = 0;

	}
	void SetToZero(int StartIndex=0)
	{
#ifdef DebugBuild		
		if (StartIndex >= Length )
		{
			throw std::invalid_argument(" Invalid SetToZero");
		}
#endif
		memset(&Array[StartIndex], 0, sizeof(Tc)*(Length-StartIndex));
	}
	void SetToZero(int StartIndex , int EndIndex)
	{
#ifdef DebugBuild		
		if (StartIndex > EndIndex)
		{
			throw std::invalid_argument(" Invalid SetToZero");
		}
#endif
		memset(&Array[StartIndex], 0, sizeof(Tc)*(EndIndex - StartIndex + 1));
	}
	TcAr GetPointer(int StartIndex, int endIndex)
	{

#ifdef DebugBuild		
		if (StartIndex >= Length || StartIndex < 0 || endIndex >= Length || endIndex < 0 || endIndex < StartIndex)
		{
			throw std::invalid_argument(" Invalid GetPointer");
		}
#endif

		TcAr p;
		p.Array = &this->Array[StartIndex];
		p.Length = endIndex - StartIndex + 1;
		p.MemSize = 0;
		p.IsPointer = true;
		p.MemManager = MemManager;

		return p;
	}
	TcAr GetPointer(int StartIndex=0)
	{
		int endIndex = Length - 1;
#ifdef DebugBuild		
		if (StartIndex >= Length || StartIndex < 0 || endIndex >= Length || endIndex < 0 || endIndex < StartIndex)
		{
			throw std::invalid_argument(" Invalid GetPointer");
		}
#endif

		TcAr p;
		p.Array = &this->Array[StartIndex];
		p.Length = endIndex - StartIndex + 1;
		p.MemSize = 0;
		p.IsPointer = true;

		p.MemManager = MemManager;
		return p;
	}
	TcAr GetSubArray(int StartIndex, int SubLength)
	{
#ifdef DebugBuild
		if (IsPointer)
		{
			if (StartIndex + SubLength > Length)
			{
				throw std::invalid_argument("Out Of Memory Index ");
			}
		}
		else
		{
			if (StartIndex + SubLength > MemSize)
			{
				throw std::invalid_argument("Out Of Memory Index ");
			}
		}
#endif // DebugBuild
		Tc* Sub = AllocMem(SubLength);
		memcpy(Sub, &Array[StartIndex], SubLength*sizeof(Tc));
		TcAr res = TcAr(Sub, SubLength, false, MemManager);
		return res;
	}

	void CopyFrom(TcArr Source)
	{
		if (MemSize < Source.Length)
		{
			Free();
			Alloc(Source.Length);
		}
		else
		{
			memset(Array, 0, MemSize*sizeof(Tc));
		}
		memcpy(Array, Source.Array, Source.Length*sizeof(Tc));
		Length = Source.Length;
		if (Source.TagArr)
		{
			//
			if (MemManager)
			{
				TagArr = MemManager->AllocChar(Source.TagArrLength);
			}
			else
			{
				TagArr = new char[Source.TagArrLength]();
			}
			//TagArr = (char*)malloc(sizeof(char)*Source.TagArrLength);
			memcpy(TagArr, Source.TagArr, sizeof(char)*Source.TagArrLength);
			TagArrLength = Source.TagArrLength;
		}

	}
	void CopyFrom(Tc* Source, int ElementNumber)
	{
		if (MemSize < ElementNumber)
		{
			Free();
			Alloc(ElementNumber);
		}
		else
		{
			memset(Array, 0, MemSize*sizeof(Tc));
		}
		memcpy(Array, Source, ElementNumber*sizeof(Tc));
		Length = ElementNumber;
	}
	void CopyFrom(int DstStartIndex, TcArr Source)
	{
		int Endindex = DstStartIndex + Source.Length - 1;
#ifdef DebugBuild
		if (Endindex >= MemSize)
		{
			throw std::invalid_argument(" Copy From Out Of Memory");
		}
#endif // DebugBuild
		memcpy(&Array[DstStartIndex], Source.Array, Source.Length*sizeof(Tc));
		if (Endindex >= Length)
		{
			Length = Endindex + 1;
		}
	}
	void CopyFrom(int DstStartIndex, Tc* Source, int ElementNumber)
	{
		int Endindex = DstStartIndex + ElementNumber - 1;
#ifdef DebugBuild
		if (Endindex >= MemSize)
		{
			throw std::invalid_argument(" Copy From Out Of Memory");
		}
#endif // DebugBuild
		memcpy(&Array[DstStartIndex], Source, ElementNumber*sizeof(Tc));
		if (Endindex >= Length)
		{
			Length = Endindex + 1;
		}
	}

	TcAr Copy()
	{
		TcAr cpy = TcAr(Array, Length, true, MemManager);
		return cpy;
	}
	TcAr CopyReal(bool ConjReal)
	{
		Tc* real_part = AllocMem(Length);
		if (ConjReal)
		{
			for (int i = 0; i < Length; i++)
			{
				real_part[i].real = Array[i].real*(-1);
			}
		}
		else
		{
			for (int i = 0; i < Length; i++)
			{
				real_part[i].real = Array[i].real;
			}
		}

		TcAr res = TcAr(real_part, Length, false, MemManager);
		return res;
	}
	TcAr CopyImag(bool ConjImage)
	{
		Tc* imag_part = AllocMem(Length);
		if (ConjImage)
		{
			for (int i = 0; i < Length; i++)
			{
				imag_part[i].imag = Array[i].imag*(-1);
			}
		}
		else
		{
			for (int i = 0; i < Length; i++)
			{
				imag_part[i].imag = Array[i].imag;
			}
		}
		TcAr res = TcAr(imag_part, Length, false, MemManager);
		return res;
	}
	TsAr GetReal()
	{
		Ts* real_part = AllocTsMem(Length);
		for (int i = 0; i < Length; i++)
		{
			real_part[i] = Array[i].real;
		}
		TsAr res = TsAr(real_part, Length, false, MemManager);
		return res;
	}	
	TsAr GetImag()
	{
		Ts* imag_part = AllocTsMem(Length);
		for (int i = 0; i < Length; i++)
		{
			imag_part[i] = Array[i].imag;
		}
		TsAr res = TsAr(imag_part, Length, false, MemManager);
		return res;
	}

	int WriteToBinaryFloatFile(const char* Path, bool Append)
	{
		FILE * pfile;
		string writeMode;
		if (!Append)
			writeMode = "wb";
		else
			writeMode = "ab";
		//	pfile = fopen(Path, writeMode.c_str());
		fopen_s(&pfile, Path, writeMode.c_str());
		if (pfile != NULL)
		{
			for (int j = 0; j < Length; j++)
			{
				float  real = Array[j].real;
				float image = Array[j].imag;
				fwrite(&real, sizeof(float), 1, pfile);
				fwrite(&image, sizeof(float), 1, pfile);
			}
			fclose(pfile);
			return 0;
		}
		else
		{
			int err = GetSystemError();
			return err;
		}
		return 1;
	}
	int WriteToBinaryDoubleFile(const char* Path, bool Append)
	{
		FILE * pfile;
		string writeMode;
		if (!Append)
			writeMode = "wb";
		else
			writeMode = "ab";
		//	pfile = fopen(Path, writeMode.c_str());
		fopen_s(&pfile, Path, writeMode.c_str());
		if (pfile != NULL)
		{
			for (int j = 0; j < Length; j++)
			{
				double  real = Array[j].real;
				double image = Array[j].imag;
				fwrite(&real, sizeof(double), 1, pfile);
				fwrite(&image, sizeof(double), 1, pfile);
			}
			fclose(pfile);
			return 0;
		}
		else
		{
			int err = GetSystemError();
			return err;
		}
		return 1;
	}
	int WriteToBinaryShortFile(const char* Path, bool Append)
	{
		FILE * pfile;
		string writeMode;
		if (!Append)
			writeMode = "wb";
		else
			writeMode = "ab";
		//pfile = fopen(Path, writeMode.c_str());
		fopen_s(&pfile, Path, writeMode.c_str());
		if (pfile != NULL)
		{
			for (int j = 0; j < Length; j++)
			{
				short  real = Array[j].real;
				short image = Array[j].imag;
				fwrite(&real, sizeof(short), 1, pfile);
				fwrite(&image, sizeof(short), 1, pfile);
			}
			fclose(pfile);
			return 0;
		}
		else
		{
			int err = GetSystemError();
			return err;
		}
	}
	int WriteToBinaryIntFile(const char* Path, bool Append)
	{
		FILE * pfile;
		string writeMode;
		if (!Append)
			writeMode = "wb";
		else
			writeMode = "ab";
		//pfile = fopen(Path, writeMode.c_str());
		fopen_s(&pfile, Path, writeMode.c_str());
		if (pfile != NULL)
		{
			for (int j = 0; j < Length; j++)
			{
				int  real = Array[j].real;
				int image = Array[j].imag;
				fwrite(&real, sizeof(int), 1, pfile);
				fwrite(&image, sizeof(int), 1, pfile);
			}
			fclose(pfile);
			return 0;
		}
		else
		{
			int err = GetSystemError();
			return err;
		}
	}
	int WriteToBinaryCharFile(const char* Path, bool Append)
	{
		FILE * pfile;
		string writeMode;
		if (!Append)
			writeMode = "wb";
		else
			writeMode = "ab";
		//pfile = fopen(Path, writeMode.c_str());
		fopen_s(&pfile, Path, writeMode.c_str());
		if (pfile != NULL)
		{
			for (int j = 0; j < Length; j++)
			{
				char  real = Array[j].real;
				char image = Array[j].imag;
				fwrite(&real, sizeof(char), 1, pfile);
				fwrite(&image, sizeof(char), 1, pfile);
			}
			fclose(pfile);
			return 0;
		}
		else
		{
			int err = GetSystemError();
			return err;
		}
	}
	int LoadFromBinaryFloatFile(const char* Path,unsigned int MaxReadCount=0)
	{
		Free();
		//FILE* fod = fopen(Path, "rb");
		FILE* fod;
		fopen_s(&fod, Path, "rb");
		fseek(fod, 0, SEEK_END);
		int  bytelength = ftell(fod);
		fseek(fod, 0, SEEK_SET);


		int InputFileLength = bytelength / sizeof(float);
		if (MaxReadCount > 0)
		{
			if (InputFileLength > MaxReadCount * 2)
			{
				InputFileLength = MaxReadCount * 2;
			}
		}
		
		int 	complexLength = InputFileLength / 2;


		float* InPutFile = (float*)malloc(sizeof(float)*InputFileLength);
		memset(InPutFile, 0, sizeof(float)*InputFileLength);
		size_t size = fread(InPutFile, sizeof(float), InputFileLength, fod);
		fclose(fod);

		Alloc(complexLength);

		for (int i = 0; i < complexLength; i++)
		{
			Array[i].real = InPutFile[2 * i];
			Array[i].imag = InPutFile[2 * i + 1];
		}
		Length = complexLength;
		free(InPutFile);

		return 1;
	}
	int LoadFromBinaryShortFile(const char* Path, unsigned int MaxReadCount = 0)
	{
		Free();
		//FILE* fod = fopen(Path, "rb");
		FILE* fod;
		fopen_s(&fod, Path, "rb");
		fseek(fod, 0, SEEK_END);
		int  bytelength = ftell(fod);
		fseek(fod, 0, SEEK_SET);

		int InputFileLength = bytelength / sizeof(short);
		if (MaxReadCount > 0)
		{
			if (InputFileLength > MaxReadCount * 2)
			{
				InputFileLength = MaxReadCount * 2;
			}
		}
		int 	complexLength = InputFileLength / 2;

		short* InPutFile = (short*)malloc(sizeof(short)*InputFileLength);
		memset(InPutFile, 0, sizeof(short)*InputFileLength);
		size_t size = fread(InPutFile, sizeof(short), InputFileLength, fod);
		fclose(fod);

		Alloc(complexLength);

		for (int i = 0; i < complexLength; i++)
		{
			Array[i].real = InPutFile[2 * i];
			Array[i].imag = InPutFile[2 * i + 1];
		}
		Length = complexLength;
		free(InPutFile);

		return 1;
	}
	int LoadFromBinaryDoubleFile(const char* Path, unsigned int MaxReadCount = 0)
	{
		Free();
		//FILE* fod = fopen(Path, "rb");
		FILE* fod;
		fopen_s(&fod, Path, "rb");
		fseek(fod, 0, SEEK_END);
		int  bytelength = ftell(fod);
		fseek(fod, 0, SEEK_SET);

		int InputFileLength = bytelength / sizeof(double);
		if (MaxReadCount > 0)
		{
			if (InputFileLength > MaxReadCount * 2)
			{
				InputFileLength = MaxReadCount * 2;
			}
		}
		int 	complexLength = InputFileLength / 2;

		double* InPutFile = (double*)malloc(sizeof(double)*InputFileLength);
		memset(InPutFile, 0, sizeof(double)*InputFileLength);
		size_t size = fread(InPutFile, sizeof(double), InputFileLength, fod);
		fclose(fod);

		Alloc(complexLength);

		for (int i = 0; i < complexLength; i++)
		{
			Array[i].real = InPutFile[2 * i];
			Array[i].imag = InPutFile[2 * i + 1];
		}
		Length = complexLength;
		free(InPutFile);

		return 1;
	}
	int LoadFromBinaryIntFile(const char* Path, unsigned int MaxReadCount = 0)
	{
		Free();
		//FILE* fod = fopen(Path, "rb");
		FILE* fod;
		fopen_s(&fod, Path, "rb");
		fseek(fod, 0, SEEK_END);
		int  bytelength = ftell(fod);
		fseek(fod, 0, SEEK_SET);

		int InputFileLength = bytelength / sizeof(int);
		if (MaxReadCount > 0)
		{
			if (InputFileLength > MaxReadCount * 2)
			{
				InputFileLength = MaxReadCount * 2;
			}
		}
		int 	complexLength = InputFileLength / 2;

		int* InPutFile = (int*)malloc(sizeof(int)*InputFileLength);
		memset(InPutFile, 0, sizeof(int)*InputFileLength);
		size_t size = fread(InPutFile, sizeof(int), InputFileLength, fod);
		fclose(fod);

		Alloc(complexLength);

		for (int i = 0; i < complexLength; i++)
		{
			Array[i].real = InPutFile[2 * i];
			Array[i].imag = InPutFile[2 * i + 1];
		}
		Length = complexLength;
		free(InPutFile);

		return 1;
	}
	int LoadFromBinaryCharFile(const char* Path, unsigned int MaxReadCount = 0)
	{
		Free();
		//FILE* fod = fopen(Path, "rb");
		FILE* fod;
		fopen_s(&fod, Path, "rb");
		fseek(fod, 0, SEEK_END);
		int  bytelength = ftell(fod);
		fseek(fod, 0, SEEK_SET);

		int InputFileLength = bytelength / sizeof(char);
		if (MaxReadCount > 0)
		{
			if (InputFileLength > MaxReadCount * 2)
			{
				InputFileLength = MaxReadCount * 2;
			}
		}
		int 	complexLength = InputFileLength / 2;

		char* InPutFile = (char*)malloc(sizeof(char)*InputFileLength);
		memset(InPutFile, 0, sizeof(char)*InputFileLength);
		size_t size = fread(InPutFile, sizeof(char), InputFileLength, fod);
		fclose(fod);

		Alloc(complexLength);

		for (int i = 0; i < complexLength; i++)
		{
			Array[i].real = InPutFile[2 * i];
			Array[i].imag = InPutFile[2 * i + 1];
		}
		Length = complexLength;
		free(InPutFile);

		return 1;
	}
	void TransferArrayToOwnMemory()
	{
		if (MemManager)
		{
			if (MemManager->_UseSelfMemoryManagement)
			{
				TcArr tmp;
				tmp.CopyFrom(*this);
				Free();
				*this = tmp;
			}
			MemManager = nullptr;

		}


	}
	TcArr & operator   =  (const TcArr &right)
	{
		//	Free();// if this has memory,  release that
#ifdef DebugBuild
		if (MemSize > 0 && Array != right.Array)
		{
			throw std::invalid_argument("Memory Leak Occurred");
		}
#endif // DebugBuild
		Array = right.Array;
		Length = right.Length;
		MemSize = right.MemSize;
		TagArr = right.TagArr;
		TagArrLength = right.TagArrLength;
		MemManager = right.MemManager;
		IsPointer = right.IsPointer;
		TagObject = right.TagObject;
#if Use_MATLAB	==1
		if (!MATLAB)
		{
			MATLAB = new CMATLABClass<Tc, Ts, TcAr, TsAr>(this);
		}
#endif
		return *this;
		//this->MATLAB = new CMATLABClass<Tc, Ts, TcAr, TsAr>(this);
	}
	
protected:

	Tc* AllocMem(int ElementNumber)
	{
		Tc*  arr = nullptr;
		if (MemManager)
		{
			//	arr = MemManager->AllocChar(ElementNumber);
			arr = (Tc*)MemManager->AllocVoid(ElementNumber, sizeof(Tc));
		}
		else
		{
			arr = new Tc[ElementNumber]();
		}
		return arr;
	}
	bool IsPointer = false;

	Ts* AllocTsMem(int ElementNumber)
	{
		Ts*  arr = nullptr;
		if (MemManager)
		{
			arr = (Ts*)MemManager->AllocVoid(ElementNumber,sizeof(Ts));
		}
		else
		{
			arr = new Ts[ElementNumber]();
		}
		return arr;
	}
	int GetSystemError()
	{
#ifdef _MSC_VER
		return GetLastError();
#else
		return -1;
#endif
		
	}
#ifndef _MSC_VER
	int fopen_s(FILE** f, const char* name, const char* mode)
	{
		int ret = 0;

		*f = fopen(name, mode);
		if (!*f)
		{
			ret = errno;
		}
		return ret;
	}
#endif
};



class TbArr : public TArr<bool, PTbArr>
{

public:
	TbArr(int ElementNumber) : TArr(ElementNumber){}
	TbArr(const TbArr &obj) :TArr(obj){}
	TbArr(const TArr<bool, PTbArr> &obj) :TArr(obj){}
	TbArr(void) :TArr(){}
	TbArr(MemoryManagerClass *MemoryManager) :TArr(MemoryManager){}
	TbArr(char ElementNumber, MemoryManagerClass *MemoryManager) :TArr(ElementNumber, MemoryManager){}
	TbArr(bool* A, int Alength, bool CopyValues, MemoryManagerClass *MemoryManager) :TArr(A, Alength, CopyValues, MemoryManager){}
	~TbArr()
	{
		//destructors are called automatically in the reverse order of construction.(base classes last). Do not call base class destructors
	}
};
class TCharArr : public TArr<char,PTCharArr>
{
public:
	TCharArr(int ElementNumber) : TArr(ElementNumber){}
	TCharArr(const TCharArr &obj) :TArr(obj){}
	TCharArr(const TArr<char, PTCharArr> &obj) :TArr(obj){}
	TCharArr(void) :TArr(){}
	TCharArr(MemoryManagerClass *MemoryManager) :TArr(MemoryManager){}
	TCharArr(char ElementNumber, MemoryManagerClass *MemoryManager) :TArr(ElementNumber, MemoryManager){}
	TCharArr(char* A, int Alength, bool CopyValues, MemoryManagerClass *MemoryManager) :TArr(A, Alength, CopyValues, MemoryManager){}
	~TCharArr()
	{
		//destructors are called automatically in the reverse order of construction.(base classes last). Do not call base class destructors
	}
};
class TintArr :public TArr<int, PTintArr>
{

public:
	TintArr(int ElementNumber): TArr(ElementNumber){}
	TintArr(const TintArr &obj) :TArr(obj){}
	TintArr(const TArr<int,PTintArr> &obj) :TArr(obj){}
	TintArr(void) :TArr(){}
	TintArr(MemoryManagerClass *MemoryManager) :TArr(MemoryManager){}
	TintArr(int ElementNumber, MemoryManagerClass *MemoryManager) :TArr(ElementNumber, MemoryManager){}
	TintArr(int* A, int Alength, bool CopyValues, MemoryManagerClass *MemoryManager) :TArr(A, Alength, CopyValues, MemoryManager){}
	~TintArr()
	{
		//destructors are called automatically in the reverse order of construction.(base classes last). Do not call base class destructors
	}

};
class TsArr :public TArr<short, PTsArr>
{

public:
	TsArr(int ElementNumber) : TArr(ElementNumber){}
	TsArr(const TsArr &obj) :TArr(obj){}
	TsArr(const TArr<short, PTsArr> &obj) :TArr(obj){}
	TsArr(void) :TArr()	{}
	TsArr(MemoryManagerClass *MemoryManager) :TArr(MemoryManager){}
	TsArr(int ElementNumber, MemoryManagerClass *MemoryManager) :TArr(ElementNumber, MemoryManager){}
	TsArr(short* A, int Alength, bool CopyValues, MemoryManagerClass *MemoryManager) :TArr(A, Alength, CopyValues, MemoryManager){}
	~TsArr()
	{
		//destructors are called automatically in the reverse order of construction.(base classes last). Do not call base class destructors
	}

	TintArr ConvertToTintArr()
	{
		TintArr in(Length, MemManager);
		for (int i = 0; i<Length; i++)
		{
			in[i] = Array[i];
		}
		in.Length = Length;
		return in;
	}

};
class TfArr : public TArr<float,PTfArr>
{
public:
	TfArr(int ElementNumber) : TArr(ElementNumber)	{}
	TfArr(const TfArr &obj) :TArr(obj){}
	TfArr(const TArr<float, PTfArr> &obj) :TArr(obj){}
	TfArr(void) :TArr()	{}
	TfArr(MemoryManagerClass *MemoryManager) :TArr(MemoryManager)	{}
	TfArr(int ElementNumber, MemoryManagerClass *MemoryManager) :TArr(ElementNumber, MemoryManager)	{}
	TfArr(float* A, int Alength, bool CopyValues, MemoryManagerClass *MemoryManager) :TArr(A, Alength, CopyValues, MemoryManager)	{}
	~TfArr() 
	{
		//destructors are called automatically in the reverse order of construction.(base classes last). Do not call base class destructors
	}
	TintArr ConvertToTintArr()
	{
		TArr ff;
		TintArr in(Length, MemManager);
		for (int i = 0; i<Length; i++)
		{
			in[i] = Array[i];
		}
		in.Length = Length;
		return in;
	}

};
class TdArr : public TArr<double,PTdArr>
{

public:

	TdArr(int ElementNumber) : TArr(ElementNumber)	{}
	TdArr(const TdArr &obj) :TArr(obj)	{}
	TdArr(const TArr<double, PTdArr> &obj) :TArr(obj){}
	TdArr(void) :TArr()	{}
	TdArr(MemoryManagerClass *MemoryManager) :TArr(MemoryManager)	{}
	TdArr(int ElementNumber, MemoryManagerClass *MemoryManager) :TArr(ElementNumber, MemoryManager)	{}
	TdArr(double* A, int Alength, bool CopyValues, MemoryManagerClass *MemoryManager) :TArr(A, Alength, CopyValues, MemoryManager)	{}
	~TdArr() 
	{
		//destructors are called automatically in the reverse order of construction.(base classes last). Do not call base class destructors
	}
	TfArr ConvertToTfArr()
	{
		TfArr fl(Length, MemManager);
		for (int i = 0; i<Length; i++)
		{
			fl[i] = (float)Array[i];
		}
		fl.Length = Length;
		return fl;
	}
	TintArr ConvertToTintArr()
	{
		TintArr in(Length, MemManager);
		for (int i = 0; i<Length; i++)
		{
			in[i] = Array[i];
		}
		in.Length = Length;
		return in;
	}

};

class TcArrInt :public TcArr<ComplexInt, int, PTcArrInt,PTintArr>
{

public:
	TcArrInt(void) :TcArr()	{}
	TcArrInt(int ElementNumber) : TcArr(ElementNumber)	{}
	TcArrInt(MemoryManagerClass *MemoryManager) :TcArr(MemoryManager)	{}
	TcArrInt(int ElementNumber, MemoryManagerClass *MemoryManager) :TcArr(ElementNumber, MemoryManager)	{}
	TcArrInt(ComplexInt* A, int Alength, bool CopyValues, MemoryManagerClass *MemoryManager) :TcArr(A, Alength, CopyValues, MemoryManager)	{}
	TcArrInt(int* real, int length, MemoryManagerClass *MemoryManager) :TcArr(real, length, MemoryManager)	{}
	TcArrInt(int* real, int* imag, int length, MemoryManagerClass *MemoryManager) :TcArr(real, imag, length, MemoryManager)	{}
	TcArrInt(const TcArrInt &obj) :TcArr(obj)	{}
	TcArrInt(const TcArr<ComplexInt, int, PTcArrInt, PTintArr> &obj) :TcArr(obj){}
	~TcArrInt()
	{
		//destructors are called automatically in the reverse order of construction.(base classes last). Do not call base class destructors
	}
};
class TcArrShort : public TcArr<ComplexShort, short, PTcArrShort,PTsArr>
{

public:
	TcArrShort(void) :TcArr()	{}
	TcArrShort(int ElementNumber) : TcArr(ElementNumber)	{}
	TcArrShort(MemoryManagerClass *MemoryManager) :TcArr(MemoryManager)	{}
	TcArrShort(int ElementNumber, MemoryManagerClass *MemoryManager) :TcArr(ElementNumber, MemoryManager)	{}
	TcArrShort(ComplexShort* A, int Alength, bool CopyValues, MemoryManagerClass *MemoryManager) :TcArr(A, Alength, CopyValues, MemoryManager)	{}
	TcArrShort(short* real, int length, MemoryManagerClass *MemoryManager) :TcArr(real, length, MemoryManager)	{}
	TcArrShort(short* real, short* imag, int length, MemoryManagerClass *MemoryManager) :TcArr(real, imag, length, MemoryManager)	{}
	TcArrShort(const TcArrShort &obj) :TcArr(obj)	{}
	TcArrShort(const TcArr<ComplexShort, short, PTcArrShort, PTsArr> &obj) :TcArr(obj){}
	~TcArrShort()
	{
		//destructors are called automatically in the reverse order of construction.(base classes last). Do not call base class destructors
	}
};
class TcArrChar : public TcArr<ComplexChar, char, PTcArrChar, PTCharArr>
{

public:
	TcArrChar(void) :TcArr()	{}
	TcArrChar(int ElementNumber) : TcArr(ElementNumber)	{}
	TcArrChar(MemoryManagerClass *MemoryManager) :TcArr(MemoryManager)	{}
	TcArrChar(int ElementNumber, MemoryManagerClass *MemoryManager) :TcArr(ElementNumber, MemoryManager)	{}
	TcArrChar(ComplexChar* A, int Alength, bool CopyValues, MemoryManagerClass *MemoryManager) :TcArr(A, Alength, CopyValues, MemoryManager)	{}
	TcArrChar(char* real, int length, MemoryManagerClass *MemoryManager) :TcArr(real, length, MemoryManager)	{}
	TcArrChar(char* real, char* imag, int length, MemoryManagerClass *MemoryManager) :TcArr(real, imag, length, MemoryManager)	{}
	TcArrChar(const TcArrChar &obj) :TcArr(obj)	{}
	TcArrChar(const TcArr<ComplexChar, char, PTcArrChar, PTCharArr> &obj) :TcArr(obj){}
	~TcArrChar()
	{
		//destructors are called automatically in the reverse order of construction.(base classes last). Do not call base class destructors
	}

};
class TcArr32 : public TcArr<Complex32, float, PTcArr32,PTfArr>
{

public:
	TcArr32(void) :TcArr()	{}
	TcArr32(int ElementNumber) : TcArr(ElementNumber)	{}
	TcArr32(MemoryManagerClass *MemoryManager) :TcArr(MemoryManager)	{}
	TcArr32(int ElementNumber, MemoryManagerClass *MemoryManager) :TcArr(ElementNumber, MemoryManager)	{}
	TcArr32(Complex32* A, int Alength, bool CopyValues, MemoryManagerClass *MemoryManager) :TcArr(A, Alength, CopyValues, MemoryManager)	{}
	TcArr32(float* real, int length, MemoryManagerClass *MemoryManager) :TcArr(real, length, MemoryManager)	{}
	TcArr32(float* real, float* imag, int length, MemoryManagerClass *MemoryManager) :TcArr(real, imag, length, MemoryManager)	{}
	TcArr32(const TcArr32 &obj) :TcArr(obj)	{}
	TcArr32(const TcArr<Complex32, float, PTcArr32, PTfArr> &obj) :TcArr(obj){}
	~TcArr32()
	{
		//destructors are called automatically in the reverse order of construction.(base classes last). Do not call base class destructors
	}
};
class TcArr64 : public TcArr<Complex64, double, PTcArr64,PTdArr>
{

public:
	TcArr64(void) :TcArr()	{}
	TcArr64(int ElementNumber) : TcArr(ElementNumber)	{}
	TcArr64(MemoryManagerClass *MemoryManager) :TcArr(MemoryManager)	{}
	TcArr64(int ElementNumber, MemoryManagerClass *MemoryManager) :TcArr(ElementNumber, MemoryManager)	{}
	TcArr64(Complex64* A, int Alength, bool CopyValues, MemoryManagerClass *MemoryManager) :TcArr(A, Alength, CopyValues, MemoryManager)	{}
	TcArr64(double* real, int length, MemoryManagerClass *MemoryManager) :TcArr(real, length, MemoryManager)	{}
	TcArr64(double* real, double* imag, int length, MemoryManagerClass *MemoryManager) :TcArr(real, imag, length, MemoryManager)	{}
	TcArr64(const TcArr64 &obj) :TcArr(obj)	{}
	TcArr64(const TcArr<Complex64, double, PTcArr64, PTdArr> &obj) :TcArr(obj){}
	~TcArr64()
	{ 
		//destructors are called automatically in the reverse order of construction.(base classes last). Do not call base class destructors
	}
};

template<class TA,class PTA2d>
class TArr2d{
protected:
	int RowCapacity;
	MemoryManagerClass *MemManager;
public:	
	TA* Rows;//remember private this member in feature
	int RowsCount;
	int TotalLength;
	TArr2d(void)
	{
		RowCapacity = 0;
		TotalLength = 0;
		Rows = nullptr;
		RowsCount = 0;
		MemManager = nullptr;
	}
	TArr2d(MemoryManagerClass *MemoryManager)
	{
		RowCapacity = 0;
		TotalLength = 0;
		Rows = nullptr;
		RowsCount = 0;
		MemManager = MemoryManager;
	}
	TArr2d(int Capacity, MemoryManagerClass *MemoryManager)
	{
		RowCapacity = 0;
		TotalLength = 0;
		Rows = nullptr;
		RowsCount = 0;
		MemManager = MemoryManager;
		AllocRows(Capacity);
	}
	bool AddRow(TA Row)
	{
		if (RowsCount == RowCapacity)
		{
			int Init_Size = 16;
			if (RowCapacity != 0)
			{
				Init_Size = RowCapacity * 2;
			}
			TA* newRows = nullptr;
			if (MemManager)
			{
				
				newRows = (TA*)MemManager->AllocVoid(Init_Size, sizeof(TA));
			}
			else
			{
				newRows = new TA[Init_Size]();
			}

			if (RowsCount > 0)
			{
				memcpy(newRows, Rows, sizeof(TA)*RowCapacity);
			}
			FreeRootonly();
			Rows = newRows;
			RowsCount = RowCapacity;
			RowCapacity = Init_Size;
		}
		if (RowsCount < RowCapacity)
		{
			Rows[RowsCount++] = Row;
			TotalLength += Row.Length;
			return true;
		}
		return false;
	}
	void AddRows(TArr2d Rows)
	{
		for (int i = 0; i < Rows.RowsCount; i++)
		{
			AddRow(Rows.Rows[i]);
		}
	}
	void FreeAllRow()
	{
		if (Rows)
		{
			for (int i = 0; i < RowCapacity; i++)
			{
				Rows[i].Free();
			}
			if (MemManager)
			{
				MemManager->FREEMEM((void**)&Rows);
			}
			else
			{
				delete[] Rows;
			}
			
			Rows = nullptr;

		}
		RowsCount = 0;
		RowCapacity = 0;
	}
	void FreeRootonly()
	{
		if (Rows)
		{
			if (MemManager)
			{
				MemManager->FREEMEM((void**)&Rows);
			}
			else
			{
				delete[] Rows;
			}
			
			Rows = nullptr;
			RowsCount = 0;
		}
	}
	void AllocRows(int Capacity)
	{
		FreeAllRow();
		if (Capacity > 0)
		{
			if (MemManager)
			{
				//Rows = new TA[Capacity]();
				Rows =(TA*)MemManager->AllocVoid(Capacity, sizeof(TA));
			}
			else
			{
				Rows = new TA[Capacity]();
			}
			
			for (int i = 0; i < Capacity; i++)
			{
				Rows[i] = TA(MemManager);
			}
			RowCapacity = Capacity;
		}
	}
	TA RowsToRow()
	{
		TA row(TotalLength, MemManager);
		int index = 0;
		for (int i = 0; i < RowsCount; i++)
		{
			for (int j = 0; j < Rows[i].Length; j++)
			{
				row[index++] = Rows[i][j];
			}
		}
		row.Length = TotalLength;
		return row;
	}
	TA ColumnsToColumn()
	{
		TA Column(TotalLength, MemManager);
		int index = 0;
		for (int i = 0; i < Rows[0].Length; i++)
		{
			for (int j = 0; j < RowsCount; j++)
			{
				Column[index++] = Rows[j][i];
			}
		}
		Column.Length = TotalLength;
		return Column;
	}
	void TransferArrayToOwnMemory()
	{
		if (MemManager)
		{
			if (MemManager->_UseSelfMemoryManagement)
			{
				TArr2d tmp(RowsCount, nullptr);
				for (int i = 0; i < RowsCount; i++)
				{
					tmp.Rows[i].CopyFrom(Rows[i]);
					tmp.Rows[i].MemManager = nullptr;
				}
				tmp.RowsCount = RowsCount;
				tmp.TotalLength = TotalLength;
				FreeAllRow();
				*this = tmp;
			}
			else
			{
				for (int i = 0; i < RowsCount; i++)
				{
					Rows[i].MemManager = nullptr;
				}
			}
			MemManager = nullptr;
		}
	}
	PTA2d GetPointer(int StartRowIndex, int endRowIndex)
	{
#ifdef DebugBuild		
		if (StartRowIndex >= RowsCount || StartRowIndex < 0 || endRowIndex >= RowsCount || endRowIndex < 0)
		{
			throw std::invalid_argument(" Invalid 2d GetPointer");
		}
#endif
		PTA2d p;
		p.Rows = &this->Rows[StartRowIndex];
		p.RowsCount = endRowIndex - StartRowIndex + 1;
		p.RowCapacity = 0;
		p.MemManager = MemManager;
		int total = 0;
		for (int i = 0; i < p.RowsCount; i++)
		{
			total += p.Rows[i].Length;
		}
		p.TotalLength = total;
		return p;
	}
	PTA2d GetPointer(int StartRowIndex)
	{
#ifdef DebugBuild		
		if (StartRowIndex >= RowsCount || StartRowIndex < 0)
		{
			throw std::invalid_argument(" Invalid 2d GetPointer");
		}
#endif
		PTA2d p;
		p.Rows = &this->Rows[StartRowIndex];
		p.RowsCount = (RowsCount - 1) - StartRowIndex + 1;
		p.RowCapacity = 0;
		p.MemManager = MemManager;
		int total = 0;
		for (int i = 0; i < p.RowsCount; i++)
		{
			total += p.Rows[i].Length;
		}
		p.TotalLength = total;
		return p;
	}
	void ReorderRows(int* NewOrder, int NewOrderLen)
	{
		// NewOrder Should not include repeated index
		TA* NewRows;
		if (MemManager)
		{
			NewRows = (TA*)MemManager->AllocVoid(NewOrderLen, sizeof(TA));
		}
		else
		{
			NewRows = new TA[NewOrderLen]();
		}
		
		RowsCount = 0;
		TotalLength = 0;
		for (int i = 0; i < NewOrderLen; i++)
		{
			if (i >= RowCapacity)
			{
				break;
			}
			if (NewOrder[i] >= RowCapacity)
			{
				continue;
			}
			bool isRepeated = false;
			for (int j = 0; j < i; j++)
			{
				if (NewOrder[j] == NewOrder[i])
				{
					isRepeated = true;
					break;
				}
			}
			if (isRepeated)
			{
				#ifdef DebugBuild		
					throw std::invalid_argument(" Repeated Index in NewOrder");
				#endif
				continue;
			}
			NewRows[i] = Rows[NewOrder[i]];					
			TotalLength += Rows[NewOrder[i]].Length;
			RowsCount++;
		}
		for (int i = 0; i < RowCapacity; i++)
		{
			bool exist = false;
			for (int j = 0; j < NewOrderLen; j++)
			{
				if (NewOrder[j] == i)
				{
					exist = true;
					break;
				}
			}
			if (exist == false)
			{
				Rows[i].Free();
			}
		}
		if (MemManager)
		{
			MemManager->FREEMEM((void**)&Rows);
		}
		else
		{
			delete[] Rows;
		}
		Rows = NewRows;
		RowCapacity = NewOrderLen;
	}
};

class TcArr2dChar :public TArr2d<TcArrChar, PTcArr2dChar>
{
public:
	TcArr2dChar(void) : TArr2d()	{}
	TcArr2dChar(MemoryManagerClass *MemoryManager) :TArr2d(MemoryManager)	{}
	TcArr2dChar(int Capacity, MemoryManagerClass *MemoryManager) :TArr2d(Capacity, MemoryManager)	{}
};
class TcArr2dInt :public TArr2d<TcArrInt, PTcArr2dInt>
{
public:
	TcArr2dInt(void) : TArr2d()	{}
	TcArr2dInt(MemoryManagerClass *MemoryManager) :TArr2d(MemoryManager)	{}
	TcArr2dInt(int Capacity, MemoryManagerClass *MemoryManager) :TArr2d(Capacity, MemoryManager)	{}
};
class TcArr2dShort : public TArr2d<TcArrShort, PTcArr2dShort>
{
public:
	TcArr2dShort(void) : TArr2d()	{}
	TcArr2dShort(MemoryManagerClass *MemoryManager) :TArr2d(MemoryManager)	{}
	TcArr2dShort(int Capacity, MemoryManagerClass *MemoryManager) :TArr2d(Capacity, MemoryManager)	{}
};
class TcArr2d32 : public TArr2d<TcArr32, PTcArr2d32>
{
public:
	TcArr2d32(void) : TArr2d()	{}
	TcArr2d32(MemoryManagerClass *MemoryManager) :TArr2d(MemoryManager)	{}
	TcArr2d32(int Capacity, MemoryManagerClass *MemoryManager) :TArr2d(Capacity, MemoryManager)	{}
};
class TcArr2d64 : public TArr2d<TcArr64, PTcArr2d64>
{
public:
	TcArr2d64(void) : TArr2d()	{}
	TcArr2d64(MemoryManagerClass *MemoryManager) :TArr2d(MemoryManager)	{}
	TcArr2d64(int Capacity, MemoryManagerClass *MemoryManager) :TArr2d(Capacity, MemoryManager)	{}
};

class TCharArr2d : public TArr2d<TCharArr, PTCharArr2d>
{
public:
	TCharArr2d(void) : TArr2d()	{}
	TCharArr2d(MemoryManagerClass *MemoryManager) :TArr2d(MemoryManager)	{}
	TCharArr2d(int Capacity, MemoryManagerClass *MemoryManager) :TArr2d(Capacity, MemoryManager)	{}
};
class TintArr2d : public TArr2d<TintArr, PTintArr2d>
{
public:
	TintArr2d(void) : TArr2d()	{}
	TintArr2d(MemoryManagerClass *MemoryManager) :TArr2d(MemoryManager)	{}
	TintArr2d(int Capacity, MemoryManagerClass *MemoryManager) :TArr2d(Capacity, MemoryManager)	{}
};
class TsArr2d : public TArr2d<TsArr, PTsArr2d>
{
public:
	TsArr2d(void) : TArr2d()	{}
	TsArr2d(MemoryManagerClass *MemoryManager) :TArr2d(MemoryManager)	{}
	TsArr2d(int Capacity, MemoryManagerClass *MemoryManager) :TArr2d(Capacity, MemoryManager)	{}
};
class TfArr2d : public TArr2d<TfArr, PTfArr2d>
{
public:
	TfArr2d(void) : TArr2d()	{}
	TfArr2d(MemoryManagerClass *MemoryManager) :TArr2d(MemoryManager)	{}
	TfArr2d(int Capacity, MemoryManagerClass *MemoryManager) :TArr2d(Capacity, MemoryManager)	{}
};
class TdArr2d : public TArr2d<TdArr, PTdArr2d>
{
public:
	TdArr2d(void) : TArr2d()	{}
	TdArr2d(MemoryManagerClass *MemoryManager) :TArr2d(MemoryManager)	{}
	TdArr2d(int Capacity, MemoryManagerClass *MemoryManager) :TArr2d(Capacity, MemoryManager)	{}
};

/////////////// ALIGNMENT OF MALLOC

// if you use malloc; Alignment depends on the operand size. if arg >= 8; the memory returned is 8 byte aligned. if arg< 8 ; the alignment of the memory 
// returned is the first power of 2 less than arg. for example; if you use malloc(7); the alignment is 4 byte.

///////////////end
#endif





