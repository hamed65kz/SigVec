#pragma once
#ifndef COMPLEXMODCLASS_H
#define COMPLEXMODCLASS_H
#include "ComplexCoreClass.h"

TemplateDefinition
class ComplexModClass :  ComplexCoreClass <TemplateParameter>
{
public:

	ComplexModClass() 
	{
		// dont call base class default constructor directly, icc has problem with it.
		// default constructor of base class automatically called befor constructor of derived class.
		// but parametrized constructor of base class should be called explicitly.
	}
	ComplexModClass(MemoryManagerClass *MemoryManager) : BaseConstructor
	{

	}
	Ts Mod(Ts X, Ts Y)
	{
		Ts n = floor(X / Y);
		Ts m = X - (n*Y);

		return m;
	}
	Ts* Mod(Ts* X, int XLength, Ts Division)
	{
		if (XLength <= 0)
			return NULL;
		Ts* m = this->AllocMem_Single(XLength);
		for (int i = 0; i < XLength; i++)
		{
			m[i] = Mod(X[i], Division);
		}
		return m;
	}
	Ta Mod(Ta X, Ts Division)
	{
		Ta res(this->MemManager);
		if (X.Length <= 0)
		{
			return res;
		}
		res.SetArray(Mod(X.GetArray(), X.Length, Division), X.Length);
		return res;
	}
	void Mod_inplace(Ts* X, int XLength, Ts Division)
	{
		if (XLength <= 0)
			return;
		for (int i = 0; i < XLength; i++)
		{
			X[i] = Mod(X[i], Division);
		}
	}
	void Mod_inplace(Ta X, Ts Division)
	{
		if (X.Length <= 0)
		{
			return;
		}
		Mod_inplace(X.GetArray(), X.Length, Division);
	}
};

#endif