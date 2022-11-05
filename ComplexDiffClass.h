#pragma once
#ifndef COMPLEXDIFFCLASS_H
#define COMPLEXDIFFCLASS_H
#include "ComplexCoreClass.h"

TemplateDefinition
class ComplexDiffClass : ComplexCoreClass <TemplateParameter>
{
public:
	ComplexDiffClass()
	{
		// dont call base class default constructor directly, icc has problem with it.
		// default constructor of base class automatically called befor constructor of derived class.
		// but parametrized constructor of base class should be called explicitly.
	}
	ComplexDiffClass(MemoryManagerClass *MemoryManager) : BaseConstructor
	{

	}
	Ts* Diff(Ts* A, int Alength)
	{
		if (Alength <= 1)
			return NULL;
		Ts* res = this->AllocMem_Single(Alength - 1);
		for (int i = 0; i < Alength - 1; i++)
		{
			res[i] = A[i + 1] - A[i];
		}
		return res;
	}
	Ts* DiffOnIndexes(Ts* A, int Alength, Ts* Indexes, int Indexeslength)
	{
		if (Alength <= 1)
			return NULL;
		Ts* res = this->AllocMem_Single(Indexeslength - 1);
		for (int i = 0; i < Indexeslength - 1; i++)
		{
			res[i] = A[(int)Indexes[i + 1]] - A[(int)Indexes[i]];
		}
		return res;
	}
	Ta Diff(Ta Input)
	{
		Ta res(this->MemManager);
		if (Input.Length <= 1)
			return res;
		Ts* diff = Diff(Input.GetArray(), Input.Length);
		res.SetArray(diff, Input.Length - 1);
		return res;
	}
	Ta DiffOnIndexes(Ta Input, Ta Indexes)
	{
		Ta res(this->MemManager);
		if (Input.Length <= 1)
			return res;
		Ts* diff = DiffOnIndexes(Input.GetArray(), Input.Length, Indexes.GetArray(), Indexes.Length);
		res.SetArray(diff, Input.Length - 1);
		return res;
	}


	void Diff_inplace(Ts* A, int Alength)
	{
		if (Alength <= 1)
			return;
		//Ts* res = this->AllocMem_Single(Alength - 1);
		for (int i = 0; i < Alength - 1; i++)
		{
			A[i] = A[i + 1] - A[i];
		}
		//return res;
	}
	void Diff_inplace(Ta& Input)
	{
		//for changing input.length we should get pointer to input
		Diff_inplace(Input.GetArray(), Input.Length);
		Input.Length--;


	}

};
#endif