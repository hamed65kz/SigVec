#pragma once
#ifndef COMPLEXINTERLEAVECLASS_H
#define COMPLEXINTERLEAVECLASS_H
#include "ComplexCoreClass.h"

TemplateDefinition
class ComplexInterleaveClass : ComplexCoreClass <TemplateParameter>
{
public:
	ComplexInterleaveClass()
	{
		// dont call base class default constructor directly, icc has problem with it.
		// default constructor of base class automatically called befor constructor of derived class.
		// but parametrized constructor of base class should be called explicitly.
	}
	ComplexInterleaveClass(MemoryManagerClass *MemoryManager) : BaseConstructor
	{

	}
	Tca Interleave(Tca input, int* interleve_indexes)
	{
		Tca inter = Tca(input.Length, MemManager);
		for (int i = 0; i < input.Length; i++)
		{
			inter[interleve_indexes[i]] = input[i];
		}
		inter.Length = input.Length;
		return input;
	}
	Ta Interleave(Ta input, int* interleve_indexes)
	{
		Ta inter = Tca(input.Length, MemManager);
		for (int i = 0; i < input.Length; i++)
		{
			inter[interleve_indexes[i]] = input[i];
		}
		inter.Length = input.Length;
		return input;
	}
};
#endif