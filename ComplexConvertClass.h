#pragma once
#ifndef COMPLEXCONVERTCLASS_H
#define COMPLEXCONVERTCLASS_H
#include "ComplexCoreClass.h"

TemplateDefinition
class ComplexConvertClass : ComplexCoreClass <TemplateParameter>
{

public:
	ComplexConvertClass() 
	{
		// dont call base class default constructor directly, icc has problem with it.
		// default constructor of base class automatically called befor constructor of derived class.
		// but parametrized constructor of base class should be called explicitly.
	}
	ComplexConvertClass(MemoryManagerClass *MemoryManager) : BaseConstructor
	{

	}
	Complex64* ConvertToComplex64(double* real, int imagesValue, int length)
	{
		if (length <= 0)
			return NULL;
		Complex64* tmp = this->AllocComplex64(length);
		for (int i = 0; i < length; i++)
		{
			tmp[i].real = real[i];
			tmp[i].imag = imagesValue;
		}
		return tmp;
	}
	Complex64* ConvertToComplex64(int realsValue, double* image, int length)
	{
		if (length <= 0)
			return NULL;
		Complex64* tmp = this->AllocComplex64(length);
		for (int i = 0; i < length; i++)
		{
			tmp[i].real = realsValue;
			tmp[i].imag = image[i];
		}
		return tmp;
	}
	std::complex<double>* ConvertComplex64IntoComplex(Complex64* A, int ALength)
	{
		if (ALength <= 0)
		{
			return NULL;
		}
		complex<double>* res = (complex<double>*)malloc(sizeof(complex<double>)*ALength);
		for (int i = 0; i < ALength; i++)
		{
			res[i] = complex<double>(A[i].real, A[i].imag);
		}
		return res;
	}


	Complex32* ConvertToComplex32(float* real, int imagesValue, int length)
	{
		if (length <= 0)
			return NULL;
		Complex32* tmp = this->AllocComplex32(length);
		for (int i = 0; i < length; i++)
		{
			tmp[i].real = real[i];
			tmp[i].imag = imagesValue;
		}
		return tmp;
	}
	Complex32* ConvertToComplex32(int realsValue, float* image, int length)
	{
		if (length <= 0)
			return NULL;
		Complex32* tmp = this->AllocComplex32(length);
		for (int i = 0; i < length; i++)
		{
			tmp[i].real = realsValue;
			tmp[i].imag = image[i];
		}
		return tmp;
	}
	std::complex<float>* ConvertComplex32IntoComplex(Complex32* A, int ALength)
	{
		if (ALength <= 0)
		{
			return NULL;
		}
		complex<float>* res = (complex<float>*)malloc(sizeof(complex<float>)*ALength);
		for (int i = 0; i < ALength; i++)
		{
			res[i] = complex<float>(A[i].real, A[i].imag);
		}
		return res;
	}

	TdArr ConvertTfArrToTdArr(TfArr input)
	{
		TdArr res(input.Length, this->MemManager);
		for (int i = 0; i < input.Length; i++)
		{
			res[i] = input[i];
		}
		res.Length = input.Length;
		return res;
	}
	TfArr ConvertTdArrToTfArr(TdArr input)
	{
		TfArr res(this->MemManager);
		for (int i = 0; i < input.Length; i++)
		{
			res[i] = input[i];
		}
		res.Length = input.Length;
		return res;
	}

	TcArr64 ConvertTcArr32ToTcArr64(TcArr32 input)
	{
		TcArr64 res(input.Length, this->MemManager);
		for (int i = 0; i < input.Length; i++)
		{
			res[i].real = input[i].real;
			res[i].imag = input[i].imag;
		}
		res.Length = input.Length;
		return res;
	}
	TcArr32 ConvertTcArr64ToTcArr32(TcArr64 input)
	{
		TcArr32 res(input.Length, this->MemManager);
		for (int i = 0; i < input.Length; i++)
		{
			res[i].real = input[i].real;
			res[i].imag = input[i].imag;
		}
		res.Length = input.Length;
		return res;
	}
};
#endif