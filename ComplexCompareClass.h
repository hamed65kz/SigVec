#pragma once
#ifndef COMPLEXCOMPARECLASS_H
#define COMPLEXCOMPARECLASS_H
#include "ComplexCoreClass.h"

TemplateDefinition
class ComplexCompareClass : ComplexCoreClass <TemplateParameter>
{
public:
	ComplexCompareClass() 
	{
		// dont call base class default constructor directly, icc has problem with it.
		// default constructor of base class automatically called befor constructor of derived class.
		// but parametrized constructor of base class should be called explicitly.
	}
	ComplexCompareClass(MemoryManagerClass *MemoryManager) : BaseConstructor
	{

	}
	Ts* Compare(Ts *A, Ts *B, int ArrayLength)
	{
		if (ArrayLength <= 0)
			return NULL;
		Ts* res = this->AllocMem_Single(ArrayLength);
		for (int i = 0; i < ArrayLength; i++)
		{
			if (A[i] == B[i])
			{
				res[i] = 1;
			}
		}
		return res;
	}
	Ts* Compare(Tc *A, Tc *B, int ArrayLength)
	{
		if (ArrayLength <= 0)
			return NULL;
		Ts* res = this->AllocMem_Single(ArrayLength);
		for (int i = 0; i < ArrayLength; i++)
		{
			if (A[i].real == B[i].real && A[i].imag == B[i].imag)
			{
				res[i] = 1;
			}
		}
		return res;
	}
	Ta Compare(Ta A, Ta B)
	{
		Ta res = Ta(Compare(A.GetArray(), B.GetArray(), A.Length), A.Length, false, this->MemManager);
		return res;
	}
	Ta Compare(Tca A, Tca B)
	{
		Ta res = Ta(Compare(A.GetArray(), B.GetArray(), A.Length), A.Length, false, this->MemManager);
		return res;
	}
};
#endif