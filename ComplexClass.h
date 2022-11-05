#pragma once
#ifndef COMPLEXCLASS_H
#define COMPLEXCLASS_H

// ver = 29.3 18/03/1400

// for linux add this switch to QT .pro file
//QMAKE_CXXFLAGS += -std=c++11
//CONFIG += c++11

// in Visual Studio should add MemManagerClass.h\.cpp  and BaseTypes.h\.cpp  and InstructionSet.h\.cpp to solution explorer.

#include "ComplexModClass.h"
#include "ComplexAbsClass.h"
#include "ComplexTrigonometricClass.h"
#include "ComplexFloorClass.h"
#include "ComplexSignClass.h"
#include "ComplexFormatClass.h"
#include "ComplexSQRTClass.h"
#include "ComplexMaxMinClass.h"
#include "ComplexMeanVarianceStdClass.h"
#include "ComplexSumRoundInnerProductClass.h"
#include "ComplexDownUpSampleClass.h"
#include "ComplexConjFFTshiftWrevClass.h"
#include "ComplexFillArrayGetArrayClass.h"
#include "ComplexVectorClass.h"
#include "ComplexVectorExtClass.h"
#include "ComplexMatrixClass.h"
#include "ComplexCompareClass.h"
#include "ComplexFindClass.h"
#include "ComplexDiffClass.h"
#include "ComplexNANClass.h"
#include "ComplexSortClass.h"
#include "ComplexConvFFTClass.h"
#include "ComplexConvertClass.h"
#include "ComplexFrequencyShiftClass.h"
#include "ComplexReShapeClass.h"
#include "ComplexInterleaveClass.h"

TemplateDefinition
class ComplexClass : public ComplexAbsClass <TemplateParameter>,
	 public ComplexModClass <TemplateParameter>
	, public ComplexFloorClass <TemplateParameter>
	, public ComplexTrigonometricClass <TemplateParameter>
	, public ComplexSignClass <TemplateParameter>
	, public ComplexFormatClass <TemplateParameter>
	, public ComplexSQRTClass <TemplateParameter>
	, public ComplexMaxMinClass <TemplateParameter>
	, public ComplexMeanVarianceStdClass <TemplateParameter>
	, public ComplexSumRoundInnerProductClass <TemplateParameter>
	, public ComplexDownUpSampleClass <TemplateParameter>
	, public ComplexConjFFTshiftWrevClass <TemplateParameter>
	, public ComplexFillArrayGetArrayClass <TemplateParameter>
	, public ComplexVectorClass <TemplateParameter>
	, public ComplexVectorExtClass <TemplateParameter>
	, public ComplexMatrixClass <TemplateParameter>
	, public ComplexCompareClass <TemplateParameter>
	, public ComplexFindClass <TemplateParameter>
	, public ComplexDiffClass <TemplateParameter>
	, public ComplexNANClass <TemplateParameter>
	, public ComplexSortClass <TemplateParameter>
	, public ComplexConvFFTClass <TemplateParameter>
	, public ComplexConvertClass <TemplateParameter>
	, public ComplexFrequencyShiftClass <TemplateParameter>
	, public ComplexReShapeClass <TemplateParameter>
	, public ComplexInterleaveClass <TemplateParameter>
{
public:


	ComplexClass(void) 
	{			
		// dont call base class default constructor directly, icc has problem with it.
		// default constructor of base class automatically called befor constructor of derived class.
		// but parametrized constructor of base class should be called explicitly.
	} 
	ComplexClass(MemoryManagerClass *MemoryManager) :ComplexAbsClass ConstructorParam // initialize base. do not use () for calling base class constructor because of new version of c++ limits.													
		, ComplexModClass ConstructorParam
		, ComplexFloorClass ConstructorParam
		, ComplexTrigonometricClass ConstructorParam
		, ComplexSignClass ConstructorParam
		, ComplexFormatClass ConstructorParam
		, ComplexSQRTClass ConstructorParam
		, ComplexMaxMinClass ConstructorParam
		, ComplexMeanVarianceStdClass ConstructorParam
		, ComplexSumRoundInnerProductClass ConstructorParam
		, ComplexDownUpSampleClass ConstructorParam
		, ComplexConjFFTshiftWrevClass ConstructorParam
		, ComplexFillArrayGetArrayClass ConstructorParam
		, ComplexVectorClass ConstructorParam
		, ComplexVectorExtClass ConstructorParam
		, ComplexMatrixClass ConstructorParam
		, ComplexCompareClass ConstructorParam
		, ComplexFindClass ConstructorParam
		, ComplexDiffClass ConstructorParam
		, ComplexNANClass ConstructorParam
		, ComplexSortClass ConstructorParam
		, ComplexConvFFTClass ConstructorParam
		, ComplexConvertClass ConstructorParam
		, ComplexFrequencyShiftClass ConstructorParam
		, ComplexReShapeClass ConstructorParam
		, ComplexInterleaveClass ConstructorParam
	{

	}
	
													// because all parent class of ComplexClass inherit from ComplexCoreClass separately for their self,
													// So linker encounter with multiple definition of ComplexCoreClass methods.
													// for solve this problem we use below using to hint linker to use which methods.
													// furthermore only ComplexAbsClass use public inherit  from CompleCoreClass. other class don't use public inheritance(their objects cant use public methods of ComplexCoreClass).
													// public inheritance :				class ComplexAbsClass : public  ComplexCoreClass <TemplateParameter>
													
													
													using ComplexAbsClass<TemplateParameter>::Abs;
													//we solve linker problem in Microsoft compiler by above using statements.

													/*			using ComplexAbsClass::length;
																using ComplexAbsClass::nextpow2;
																using ComplexAbsClass::real;
																using ComplexAbsClass::Imag;
																using ComplexAbsClass::FREEMEM;
																using ComplexAbsClass::AllocFloat;
																using ComplexAbsClass::AllocDouble;
																using ComplexAbsClass::AllocChar;
																using ComplexAbsClass::AllocInt;
																using ComplexAbsClass::AllocComplex64;
																using ComplexAbsClass::AllocComplex32;
																using ComplexAbsClass::AllocComplexInt;
																using ComplexAbsClass::AllocMem;
													using ComplexAbsClass::pi;*/
	

	//we solve linker problem in Microsoft compiler by above using statements. 
	// but intel compiler cant solve linker problem by these using. since we add below methods for solve linker problem for calling ComplexCoreClass methods.
	
	int length(Ta A)
	{
		return ComplexAbsClass <TemplateParameter> ::length(A);
	}
	int length(Tca A)
	{
		return  ComplexAbsClass<TemplateParameter>::length(A);
	}
	int nextpow2(int in)
	{
		return  ComplexAbsClass<TemplateParameter>::nextpow2(in);
	}
	Ts real(Tc A)
	{
		return  ComplexAbsClass<TemplateParameter>::real(A);
	}
	Ts Imag(Tc A)
	{
		return  ComplexAbsClass<TemplateParameter>::Imag(A);
	}
	Ts Abs(Tc data)
	{
		return  ComplexAbsClass<TemplateParameter>::Abs(data);
	}
	void FREEMEM(void** mem)
	{
		ComplexAbsClass<TemplateParameter>::FREEMEM(mem);
	}
	float* AllocFloat(int ElementNumber)
	{
		return ComplexAbsClass<TemplateParameter>::AllocFloat(ElementNumber);
	}
	double* AllocDouble(int ElementNumber)
	{
		return ComplexAbsClass<TemplateParameter>::AllocDouble(ElementNumber);
	}
	char* AllocChar(int ElementNumber)
	{
		return ComplexAbsClass<TemplateParameter>::AllocChar(ElementNumber);
	}
	int* AllocInt(int ElementNumber)
	{
		return ComplexAbsClass<TemplateParameter>::AllocInt(ElementNumber);
	}
	Complex64* AllocComplex64(int ElementNumber)
	{
		return ComplexAbsClass<TemplateParameter>::AllocComplex64(ElementNumber);
	}
	Complex32* AllocComplex32(int ElementNumber)
	{
		return ComplexAbsClass<TemplateParameter>::AllocComplex32(ElementNumber);
	}
	ComplexInt* AllocComplexInt(int ElementNumber)
	{
		return ComplexAbsClass<TemplateParameter>::AllocComplexInt(ElementNumber);
	}
	void* AllocMem(int ElementNumber, int ElementSize)
	{
		return ComplexAbsClass<TemplateParameter>::AllocMem(ElementNumber);
	}
	double CSin(double rad)
	{
		return ComplexAbsClass<TemplateParameter>::CSin(rad);
	}
	double CCos(double rad)
	{
		return ComplexAbsClass<TemplateParameter>::CCos(rad);
	}
	double Getpi()
	{
		return ComplexAbsClass<TemplateParameter>::pi;
	}
	HostISA getHostCpuArchitecture()
	{
		return ComplexAbsClass::HISA;
	}
	~ComplexClass()
	{
		//destructors are called automatically in the reverse order of construction.(base classes last). Do not call base class destructors
	}
};

typedef ComplexClass <TcArr64, TcArr2d64, TdArr, TdArr2d, Complex64, double,Complex64,double> ComplexClassDouble;
typedef ComplexClass <TcArr32, TcArr2d32, TfArr, TfArr2d, Complex32, float, Complex32,float> ComplexClassFloat;
typedef ComplexClass <TcArrInt, TcArr2dInt, TintArr, TintArr2d, ComplexInt, int, ComplexLong,long long > ComplexClassInt;
typedef ComplexClass <TcArrShort, TcArr2dShort, TsArr, TsArr2d, ComplexShort, short,ComplexLong,long long > ComplexClassShort;
typedef ComplexClass <TcArrChar, TcArr2dChar, TCharArr, TCharArr2d, ComplexChar, char,ComplexLong,long long> ComplexClassChar;

#endif