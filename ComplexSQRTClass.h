#pragma once
#ifndef COMPLEXSQRTCLASS_H
#define COMPLEXSQRTCLASS_H

#include "ComplexCoreClass.h"

TemplateDefinition
class ComplexSQRTClass : ComplexCoreClass <TemplateParameter>
{
public:
	ComplexSQRTClass() 
	{
		// dont call base class default constructor directly, icc has problem with it.
		// default constructor of base class automatically called befor constructor of derived class.
		// but parametrized constructor of base class should be called explicitly.
	}
	ComplexSQRTClass(MemoryManagerClass *MemoryManager) : BaseConstructor
	{

	}
	Ts* SQRT(Ts* a, int alength)
	{
		if (alength == 0)
			return NULL;
		Ts* res = this->AllocMem_Single(alength);
		for (int i = 0; i < alength; i++)
		{
			res[i] = sqrt(a[i]);
		}
		return res;
	}
	Ts* SQRT(Ta Input)
	{
		if (Input.Length <= 0)
		{
			return NULL;
		}
		return SQRT(Input.GetArray(), Input.Length);
	}
	void SQRT_inplace(Ts* a, int alength)
	{
		if (alength <= 0)
		{
			return;
		}
		for (int i = 0; i < alength; i++)
		{
			a[i] = sqrt(a[i]);
		}
	}
	void SQRT_inplace(Ta Input)
	{
		if (Input.Length <= 0)
		{
			return;
		}
		SQRT_inplace(Input.GetArray(), Input.Length);

	}
};
#endif