#pragma once
#ifndef COMPLEXRESHAPECLASS_H
#define COMPLEXRESHAPECLASS_H
#include "ComplexCoreClass.h"

TemplateDefinition
class ComplexReShapeClass : ComplexCoreClass <TemplateParameter>
{
public:
	ComplexReShapeClass()
	{
		// dont call base class default constructor directly, icc has problem with it.
		// default constructor of base class automatically called befor constructor of derived class.
		// but parametrized constructor of base class should be called explicitly.
	}
	ComplexReShapeClass(MemoryManagerClass *MemoryManager) : BaseConstructor
	{

	}
	Tca ReShapeColMajor_GetColumn(Tca input, int reShapedMatrix_rowCount, int desire_colIndex, int start_rowIndex = 0, int end_rowIndex = 0)
	{
		if (end_rowIndex == 0)
		{
			end_rowIndex = reShapedMatrix_rowCount - 1;
		}
		int reslen = end_rowIndex - start_rowIndex + 1;
	
		int input_start_index = (desire_colIndex * reShapedMatrix_rowCount) + start_rowIndex;
		Tca col = input.GetSubArray(input_start_index, reslen);
		return col;
	}
	Tca ReShapeColMajor_GetColumn_Getpointer(Tca input, int reShapedMatrix_rowCount, int desire_colIndex, int start_rowIndex = 0, int end_rowIndex = 0)
	{
		if (end_rowIndex == 0)
		{
			end_rowIndex = reShapedMatrix_rowCount - 1;
		}
		int reslen = end_rowIndex - start_rowIndex + 1;

		int input_start_index = (desire_colIndex * reShapedMatrix_rowCount) + start_rowIndex;
		Tca col = input.GetPointer(input_start_index, input_start_index + reslen - 1);
		return col;
	}
};
#endif