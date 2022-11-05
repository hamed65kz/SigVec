#pragma once
#ifndef COMPLEXNANCLASS_H
#define COMPLEXNANCLASS_H
#include "ComplexCoreClass.h"

TemplateDefinition
class ComplexNANClass : ComplexCoreClass <TemplateParameter>
{
public:
	ComplexNANClass()
	{
		// dont call base class default constructor directly, icc has problem with it.
		// default constructor of base class automatically called befor constructor of derived class.
		// but parametrized constructor of base class should be called explicitly.
	}
	ComplexNANClass(MemoryManagerClass *MemoryManager) : BaseConstructor
	{

	}
	void SetNaNToZero(Ts* A, int Len)
	{
		for (int i = 0; i < Len; i++)
		{
			bool isNAN = isnan(A[i]);
			if (isNAN)
			{
				A[i] = 0;
			}
		}
	}

	void SetNaNToZero(Tc* A, int Len)
	{
		for (int i = 0; i < Len; i++)
		{
			bool isNAN1 = isnan(A[i].real);
			bool isNAN2 = isnan(A[i].imag);
			if (isNAN1 || isNAN2)
			{
				A[i].real = 0;
				A[i].imag = 0;
			}
		}
	}

	void SetNaNToZero(Tca A)
	{
		SetNaNToZero(A.GetArray(), A.Length);
	}

	void SetNaNToZero(Ta A)
	{
		SetNaNToZero(A.GetArray(), A.Length);
	}
};
#endif