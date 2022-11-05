#pragma once
#ifndef COMPLEXSIGNCLASS_H
#define COMPLEXSIGNCLASS_H

#include "ComplexCoreClass.h"

TemplateDefinition
class ComplexSignClass :  ComplexCoreClass <TemplateParameter>
{
public:
	ComplexSignClass() 
	{
		// dont call base class default constructor directly, icc has problem with it.
		// default constructor of base class automatically called befor constructor of derived class.
		// but parametrized constructor of base class should be called explicitly.
	}
	ComplexSignClass(MemoryManagerClass *MemoryManager) : BaseConstructor
	{

	}
	Ts Sign(Ts A)
	{
		if (A<0)
		{
			return  -1;
		}
		else if (A>0)
		{
			return  1;
		}
		else
		{
			return  0;
		}
	}
	Ts * Sign(Ts* A, int ALength)
	{
		Ts* sign = this->AllocMem_Single(ALength);
		for (size_t i = 0; i < ALength; i++)
		{
			sign[i] = Sign(A[i]);
		}
		return sign;
	}
	Ta Sign(Ta A)
	{
		Ta res(this->MemManager);
		if (A.Length <= 0)
			return res;
		res.SetArray(Sign(A.GetArray(), A.Length), A.Length);
		return res;
	}
	void Sign_inplace(Ts* A, int ALength)
	{
		//	double* sign = AllocDouble(ALength);
		for (size_t i = 0; i < ALength; i++)
		{
			A[i] = Sign(A[i]);
		}
		//return sign;
	}
	void Sign_inplace(Ta A)
	{
		Sign_inplace(A.GetArray(), A.Length);
	}
};
#endif