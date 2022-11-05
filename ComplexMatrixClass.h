#pragma once
#ifndef COMPLEXMATRIXCLASS_H
#define COMPLEXMATRIXCLASS_H
#include "ComplexCoreClass.h"

TemplateDefinition
class ComplexMatrixClass : ComplexCoreClass <TemplateParameter>
{
public:
	ComplexMatrixClass() 
	{
		// dont call base class default constructor directly, icc has problem with it.
		// default constructor of base class automatically called befor constructor of derived class.
		// but parametrized constructor of base class should be called explicitly.
	}
	ComplexMatrixClass(MemoryManagerClass *MemoryManager) : BaseConstructor
	{

	}
	Ts* GetColumn(Ts **A, int RowsCount, int ColumnIndex)
	{
		if (RowsCount == 0)
			return NULL;
		Ts * Column = this->AllocMem_Single(RowsCount);
		for (int i = 0; i < RowsCount; i++)
		{
			Column[i] = A[i][ColumnIndex];
		}
		return Column;
	}
	Tc* GetColumn(Tc **A, int RowsCount, int ColumnIndex)
	{
		if (RowsCount == 0)
			return NULL;
		Tc * Column = this->AllocMem_Complex(RowsCount);
		for (int i = 0; i < RowsCount; i++)
		{
			Column[i] = A[i][ColumnIndex];
		}
		return Column;
	}
	void GetColumn_ToOutMem(Ts **A, int RowsCount, int ColumnIndex, Ts* OutA)
	{
		memset(OutA, 0, sizeof(Ts)*RowsCount);
		for (int i = 0; i < RowsCount; i++)
		{
			OutA[i] = A[i][ColumnIndex];
		}
	}
	void GetColumn_ToOutMem(Tc **A, int RowsCount, int ColumnIndex, Tc* OutA)
	{
		memset(OutA, 0, sizeof(Tc)*RowsCount);
		for (int i = 0; i < RowsCount; i++)
		{
			OutA[i] = A[i][ColumnIndex];
		}
	}
	Tca GetColumn(Tca2d A, int ColumnIndex)
	{
		Tca res(this->MemManager);
		if (A.RowsCount == 0)
			return res;

		Tc * Column = this->AllocMem_Complex(A.RowsCount);
		for (int i = 0; i < A.RowsCount; i++)
		{
			Column[i] = A.Rows[i][ColumnIndex];
		}
		res.SetArray(Column, A.RowsCount);
		return res;
	}
	Ta GetColumn(Ta2d A, int ColumnIndex)
	{
		Ta res(this->MemManager);
		if (A.RowsCount == 0)
			return res;

		Ts * Column = this->AllocMem_Single(A.RowsCount);
		for (int i = 0; i < A.RowsCount; i++)
		{
			Column[i] = A.Rows[i][ColumnIndex];
		}
		res.SetArray(Column, A.RowsCount);
		return res;
	}

	Ts* GetRow(Ts **A, int ColumnCount, int RowIndex)
	{
		if (ColumnCount == 0)
			return NULL;
		Ts * Row = this->AllocMem_Single(ColumnCount);
		for (int i = 0; i < ColumnCount; i++)
		{
			Row[i] = A[RowIndex][i];
		}
		return Row;
	}
	Tc* GetRow(Tc **A, int ColumnCount, int RowIndex)
	{
		if (ColumnCount == 0)
			return NULL;
		Tc * Row = this->AllocMem_Complex(ColumnCount);
		for (int i = 0; i < ColumnCount; i++)
		{
			Row[i] = A[RowIndex][i];
		}
		return Row;
	}
	Ta GetRow(Ta2d A, int RowIndex)
	{
		Ta res(this->MemManager);
		if (A.Rows[RowIndex].Length == 0)
			return res;
		Ts * Row = this->AllocMem_Single(A.Rows[RowIndex].Length);
		for (int i = 0; i < A.Rows[RowIndex].Length; i++)
		{
			Row[i] = A.Rows[RowIndex][i];
		}
		res.SetArray(Row, A.Rows[RowIndex].Length);
		return res;
	}
	Tca GetRow(Tca2d A, int RowIndex)
	{
		Tca res(this->MemManager);
		if (A.Rows[RowIndex].Length == 0)
			return res;
		Tc * Row = this->AllocMem_Complex(A.Rows[RowIndex].Length);
		for (int i = 0; i < A.Rows[RowIndex].Length; i++)
		{
			Row[i] = A.Rows[RowIndex][i];
		}
		res.SetArray(Row, A.Rows[RowIndex].Length);
		return res;
	}
};
#endif