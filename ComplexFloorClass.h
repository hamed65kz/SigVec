#pragma once
#ifndef COMPLEXFLOORCLASS_H
#define COMPLEXFLOORCLASS_H
#include "ComplexCoreClass.h"

TemplateDefinition
class ComplexFloorClass :  ComplexCoreClass <TemplateParameter>
{
public:
	ComplexFloorClass() 
	{
		// dont call base class default constructor directly, icc has problem with it.
		// default constructor of base class automatically called befor constructor of derived class.
		// but parametrized constructor of base class should be called explicitly.
	}
	ComplexFloorClass(MemoryManagerClass *MemoryManager) : BaseConstructor
	{

	}
	Ts* Floor(Ts* X, int XLength)
	{
		if (XLength <= 0)
			return NULL;
		Ts* m = this->AllocMem_Single(XLength);
		for (int i = 0; i < XLength; i++)
		{
			m[i] = floor(X[i]);
		}
		return m;
	}
	Ta Floor(Ta X)
	{
		Ta res(this->MemManager);
		if (X.Length <= 0)
		{
			return res;
		}
		res.SetArray(Floor(X.GetArray(), X.Length), X.Length);
		return res;
	}
	void Floor_inplace(Ts* X, int XLength)
	{
		if (XLength <= 0)
			return;
		for (int i = 0; i < XLength; i++)
		{
			X[i] = floor(X[i]);
		}
	}
	void Floor_inplace(Ta X)
	{
		Floor_inplace(X.GetArray(), X.Length);

	}
};
#endif