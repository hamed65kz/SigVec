#pragma once
#ifndef COMPLEXSORTCLASS_H
#define COMPLEXSORTCLASS_H
#include "ComplexCoreClass.h"

TemplateDefinition
class ComplexSortClass : ComplexCoreClass <TemplateParameter>
{
public:
	ComplexSortClass() 
	{
		// dont call base class default constructor directly, icc has problem with it.
		// default constructor of base class automatically called befor constructor of derived class.
		// but parametrized constructor of base class should be called explicitly.
	}
	ComplexSortClass(MemoryManagerClass *MemoryManager) : BaseConstructor
	{

	}
	void QuickSort(Ts* A, int FirstIndex, int LastIndex)
	{
		int r;
		if (FirstIndex < LastIndex)
		{
			r = QuickSort_Partition(A, FirstIndex, LastIndex);
			QuickSort(A, FirstIndex, r);
			QuickSort(A, r + 1, LastIndex);
		}
	}
	int QuickSort_Partition(Ts* A, int FirstIndex, int LastIndex)
	{
		Ts x = A[FirstIndex];
		int i = FirstIndex;
		int j;

		for (j = FirstIndex + 1; j < LastIndex; j++)
		{
			if (A[j] <= x)
			{
				i = i + 1;
				swap(A[i], A[j]);
			}

		}

		swap(A[i], A[FirstIndex]);
		return i;
	}
	void QuickSort(Ta A, int FirstIndex, int LastIndex)
	{
		int r;
		if (FirstIndex < LastIndex)
		{
			r = QuickSort_Partition(A, FirstIndex, LastIndex);
			QuickSort(A, FirstIndex, r);
			QuickSort(A, r + 1, LastIndex);
		}
	}
	int QuickSort_Partition(Ta A, int FirstIndex, int LastIndex)
	{
		Ts x = A[FirstIndex];
		int i = FirstIndex;
		int j;

		for (j = FirstIndex + 1; j < LastIndex; j++)
		{
			if (A[j] <= x)
			{
				i = i + 1;
				swap(A[i], A[j]);
			}
		}

		swap(A[i], A[FirstIndex]);
		return i;
	}
};
#endif