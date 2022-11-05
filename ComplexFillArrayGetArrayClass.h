#pragma once
#ifndef COMPLEXFILLGETARRAYCLASS_H
#define COMPLEXFILLGETARRAYCLASS_H
#include "ComplexCoreClass.h"

TemplateDefinition
class ComplexFillArrayGetArrayClass : ComplexCoreClass <TemplateParameter>
{
public:
	ComplexFillArrayGetArrayClass()
	{
		// dont call base class default constructor directly, icc has problem with it.
		// default constructor of base class automatically called befor constructor of derived class.
		// but parametrized constructor of base class should be called explicitly.
	}
	ComplexFillArrayGetArrayClass(MemoryManagerClass *MemoryManager) : BaseConstructor
	{

	}
	Ts* FillArray(Ts Value, int ArrayLength)
	{
		if (ArrayLength == 0)
			return NULL;
		Ts* tmp = this->AllocMem_Single(ArrayLength);
		for (int i = 0; i < ArrayLength; i++)
		{
			tmp[i] = Value;
		}
		return tmp;
	}
	void FillArray(Ts* a, int StartIndex, int EndIndex, Ts Value)
	{
		for (int i = StartIndex; i <= EndIndex; i++)
		{
			a[i] = Value;
		}
	}
	void FillArray(Ts* a, int StartIndex, int EndIndex, Ts* Value)
	{
		int j = 0;
		for (int i = StartIndex; i <= EndIndex; i++)
		{
			a[i] = Value[j];
			j++;
		}
	}
	void FillArray(Tc* a, int StartIndex, int EndIndex, Tc Value)
	{
		for (int i = StartIndex; i <= EndIndex; i++)
		{
			a[i] = Value;
		}
	}
	void FillArray(Tc* a, int StartIndex, int EndIndex, Tc* Value)
	{
		int j = 0;
		for (int i = StartIndex; i <= EndIndex; i++)
		{
			a[i] = Value[j];
			j++;
		}
	}
	void FillArray(Ta Input, int StartIndex, int EndIndex, Ts Value)
	{
		if (EndIndex < 0)
		{
			EndIndex += Input.Length;
		}
		if (StartIndex < 0)
		{
			StartIndex += Input.Length;
		}
		FillArray(Input.GetArray(), StartIndex, EndIndex, Value);
	}
	void FillArray(Tca Input, int StartIndex, int EndIndex, Tc Value)
	{
		if (EndIndex < 0)
		{
			EndIndex += Input.Length;
		}
		if (StartIndex < 0)
		{
			StartIndex += Input.Length;
		}
		FillArray(Input.GetArray(), StartIndex, EndIndex, Value);
	}
	void FillArray(Ta Input, int StartIndex, int EndIndex, Ts* Value)
	{
		if (EndIndex < 0)
		{
			EndIndex += Input.Length;
		}
		if (StartIndex < 0)
		{
			StartIndex += Input.Length;
		}
		FillArray(Input.GetArray(), StartIndex, EndIndex, Value);
	}
	void FillArray(Tca Input, int StartIndex, int EndIndex, Tc* Value)
	{
		if (EndIndex < 0)
		{
			EndIndex += Input.Length;
		}
		if (StartIndex < 0)
		{
			StartIndex += Input.Length;
		}
		FillArray(Input.GetArray(), StartIndex, EndIndex, Value);
	}
	void FillArray(Ta Input, int StartIndex, int EndIndex, Ta Value)
	{
		if (EndIndex < 0)
		{
			EndIndex += Input.Length;
		}
		if (StartIndex < 0)
		{
			StartIndex += Input.Length;
		}
		FillArray(Input.GetArray(), StartIndex, EndIndex, Value.GetArray());
	}
	void FillArray(Tca Input, int StartIndex, int EndIndex, Tca Value)
	{
		if (EndIndex < 0)
		{
			EndIndex += Input.Length;
		}
		if (StartIndex < 0)
		{
			StartIndex += Input.Length;
		}
		FillArray(Input.GetArray(), StartIndex, EndIndex, Value.GetArray());
	}
	Tc* FillArray(Ts real, Ts image, int ArrayLength)
	{
		if (ArrayLength == 0)
			return NULL;
		Tc* tmp = this->AllocMem_Complex(ArrayLength);
		for (int i = 0; i < ArrayLength; i++)
		{
			tmp[i].real = real;
			tmp[i].imag = image;
		}
		return tmp;
	}
	Tc* FillArray(Ts* real, Ts* image, int ArrayLength)
	{
		if (ArrayLength == 0)
			return NULL;
		Tc* tmp = this->AllocMem_Complex(ArrayLength);
		FillRealOfArray_inplace(real, ArrayLength, tmp);
		FillImagesOfArray_inplace(image, ArrayLength, tmp);
		return tmp;
	}
	Tca FillArray(Ta real, Ta image)
	{
		Tca res(this->MemManager);
		if (real.Length == 0)
			return res;
		res.SetArray(FillArray(real.GetArray(), image.GetArray(), real.Length), real.Length);
		return res;
	}


	Ta GetArrayR(int StartValue, int EndValue, int IncStep)
	{
		Ta tr(this->MemManager);
		if (IncStep > 0)
		{
			int size = (EndValue - StartValue + 1) / IncStep;
			int mod = (EndValue - StartValue + 1) % IncStep;
			if (mod > 0)
			{
				size++;
			}
			if (size < 1)
			{
				return tr;
			}
			Ts* res = this->AllocMem_Single(size);
			int index = 0;
			for (int i = StartValue; i <= EndValue; i += IncStep)
			{
				res[index] = i;
				index++;
			}
			tr.SetArray(res, size);
			return tr;
		}
		else
		{
			int size = (StartValue - EndValue + 1) / (IncStep*(-1));
			int mod = (StartValue - EndValue + 1) % (IncStep*(-1));
			if (mod > 0)
			{
				size++;
			}
			if (size < 1)
			{
				return tr;
			}
			Ts* res = this->AllocMem_Single(size);
			int index = 0;
			for (int i = StartValue; i >= EndValue; i += IncStep)
			{
				res[index] = i;
				index++;
			}
			tr.SetArray(res, size);
			return tr;
		}
	}
	Tca GetArrayC(int RealStartValue, int RealEndValue, int IncStep)
	{
		if (IncStep > 0)
		{
			int size = (RealEndValue - RealStartValue + 1) / IncStep;
			int mod = (RealEndValue - RealStartValue + 1) % IncStep;
			if (mod > 0)
			{
				size++;
			}
			if (size < 1)
			{
				Tca tr(this->MemManager);
				return tr;
			}
			Tca tr(size, this->MemManager);
			int index = 0;
			for (int i = RealStartValue; i <= RealEndValue; i += IncStep)
			{
				tr[index].real = i;
				index++;
			}
			tr.Length = index;
			return tr;
		}
		else
		{
			int size = (RealStartValue - RealEndValue + 1) / (IncStep*(-1));
			int mod = (RealStartValue - RealEndValue + 1) % (IncStep*(-1));
			if (mod > 0)
			{
				size++;
			}
			if (size < 1)
			{
				Tca tr(this->MemManager);
				return tr;
			}
			Tca tr(size, this->MemManager);
			int index = 0;
			for (int i = RealStartValue; i >= RealEndValue; i += IncStep)
			{
				tr[index].real = i;
				index++;
			}
			tr.Length = index;
			return tr;
		}
	}
	Ta GetArrayRDivX(int StartValue, int EndValue, int IncStep, Ts X)
	{
		int size = (EndValue - StartValue + 1) / IncStep;
		int mod = (EndValue - StartValue + 1) % IncStep;
		if (mod > 0)
		{
			size++;
		}
		if (size < 1)
		{
			Ta tr(this->MemManager);
			return tr;
		}
		Ta tr(size, this->MemManager);
		int index = 0;
		for (int i = StartValue; i <= EndValue; i += IncStep)
		{
			tr[index] = i / X;
			index++;
		}
		tr.Length = index;
		return tr;
	}
	Ta GetArrayRMulX(int StartValue, int EndValue, int IncStep, Ts X)
	{
		int size = (EndValue - StartValue + 1) / IncStep;
		int mod = (EndValue - StartValue + 1) % IncStep;
		if (mod > 0)
		{
			size++;
		}
		if (size < 1)
		{
			Ta tr(this->MemManager);
			return tr;
		}
		Ta tr = Ta(size, this->MemManager);
		int index = 0;
		for (int i = StartValue; i <= EndValue; i += IncStep)
		{
			tr[index] = i*X;
			index++;
		}
		tr.Length = index;
		return tr;
	}
	Tca GetArrayCDivX(int RealStartValue, int RealEndValue, int IncStep, Ts X)
	{
		int size = (RealEndValue - RealStartValue + 1) / IncStep;
		int mod = (RealEndValue - RealStartValue + 1) % IncStep;
		if (mod > 0)
		{
			size++;
		}
		if (size < 1)
		{
			Tca tr(this->MemManager);
			return tr;
		}
		Tca tr(size, this->MemManager);
		int index = 0;
		for (int i = RealStartValue; i <= RealEndValue; i += IncStep)
		{
			tr[index].real = i / X;
			index++;
		}
		tr.Length = index;
		return tr;
	}
	Tca GetArrayCMulX(int RealStartValue, int RealEndValue, int IncStep, Ts X)
	{
		int size = (RealEndValue - RealStartValue + 1) / IncStep;
		int mod = (RealEndValue - RealStartValue + 1) % IncStep;
		if (mod > 0)
		{
			size++;
		}
		if (size < 1)
		{
			Tca tr(this->MemManager);
			return tr;
		}
		Tca tr(size, this->MemManager);
		int index = 0;
		for (int i = RealStartValue; i <= RealEndValue; i += IncStep)
		{
			tr[index].real = i*X;
			index++;
		}
		tr.Length = index;
		return tr;
	}
	Tca GetArrayCMulX(int RealStartValue, int RealEndValue, int IncStep, Tc X)
	{
		int size = (RealEndValue - RealStartValue + 1) / IncStep;
		int mod = (RealEndValue - RealStartValue + 1) % IncStep;
		if (mod > 0)
		{
			size++;
		}
		if (size < 1)
		{
			Tca tr(this->MemManager);
			return tr;
		}
		Tca tr(size, this->MemManager);
		int index = 0;
		for (int i = RealStartValue; i <= RealEndValue; i += IncStep)
		{
			tr[index].real = i;
			tr[index] = tr[index] * X;
			index++;
		}
		tr.Length = index;
		return tr;
	}
	void GetArrayRDivX_ToOutMem(int StartValue, int EndValue, int IncStep, Ts X, Ts* outA)
	{
		int size = (EndValue - StartValue + 1) / IncStep;
		int mod = (EndValue - StartValue + 1) % IncStep;
		if (mod > 0)
		{
			size++;
		}
		//Ts* res = (Ts *)malloc(sizeof(Ts)*size);
		memset(outA, 0, sizeof(Ts)*size);
		int index = 0;
		for (int i = StartValue; i <= EndValue; i += IncStep)
		{
			outA[index] = i / X;
			index++;
		}
	}

	Tc* FillImagesOfArray(Ts *Values, int arrayLength)
	{
		if (arrayLength == 0)
			return NULL;
		Tc *a = this->AllocMem_Complex(arrayLength);
		for (int i = 0; i < arrayLength; i++)
		{
			a[i].imag = Values[i];
		}
		return a;
	}
	Tc* FillRealOfArray(Ts *Values, int arrayLength)
	{
		if (arrayLength == 0)
			return NULL;
		Tc *a = this->AllocMem_Complex(arrayLength);
		for (int i = 0; i < arrayLength; i++)
		{
			a[i].real = Values[i];
		}
		return a;

	}
	Tca FillImagesOfArray(Ta Input)
	{
		Tca res(this->MemManager);
		res.SetArray(FillImagesOfArray(Input.GetArray(), Input.Length), Input.Length);
		return res;
	}
	Tca FillRealOfArray(Ta Input)
	{
		Tca res(this->MemManager);
		res.SetArray(FillRealOfArray(Input.GetArray(), Input.Length), Input.Length);
		return res;
	}
	void FillImagesOfArray_ToOutMem(Ts* Values, int arrayLength, Tc* OutA)
	{
		//memset(OutA, 0, sizeof(Tc)*arrayLength);
		for (int i = 0; i < arrayLength; i++)
		{
			OutA[i].imag = Values[i];
		}
	}
	void FillImagesOfArray_ToOutMem(Tc* OutA, int ALength, Ts Values)
	{
		//memset(OutA, 0, sizeof(Tc)*arrayLength);
		for (int i = 0; i < ALength; i++)
		{
			OutA[i].imag = Values;
		}
	}
	void FillRealOfArray_ToOutMem(Tc* OutA, int ALength, Ts Values)
	{
		//memset(OutA, 0, sizeof(Tc)*arrayLength);
		for (int i = 0; i < ALength; i++)
		{
			OutA[i].real = Values;
		}
	}

	void FillImagesOfArray_ToOutMem(Ta Input, Tc* OutA)
	{
		FillImagesOfArray_inplace(Input.GetArray(), Input.Length, OutA);

	}
	void FillRealOfArray_ToOutMem(Ts* Values, int arrayLength, Tc* OutA)
	{
		//memset(OutA, 0, sizeof(Tc)*arrayLength);
		for (int i = 0; i < arrayLength; i++)
		{
			OutA[i].real = Values[i];
		}
	}
	void FillRealOfArray_ToOutMem(Ta Input, Tc* OutA)
	{
		FillRealOfArray_inplace(Input.GetArray(), Input.Length, OutA);

	}
};
#endif
