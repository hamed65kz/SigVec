#pragma once
#ifndef COMPLEXSRIPCLASS_H
#define COMPLEXSRIPCLASS_H
#include "ComplexCoreClass.h"
TemplateDefinition
class ComplexSumRoundInnerProductClass : ComplexCoreClass <TemplateParameter>
{
public:
	ComplexSumRoundInnerProductClass() 
	{
		// dont call base class default constructor directly, icc has problem with it.
		// default constructor of base class automatically called befor constructor of derived class.
		// but parametrized constructor of base class should be called explicitly.
	}
	ComplexSumRoundInnerProductClass(MemoryManagerClass *MemoryManager) : BaseConstructor
	{

	}
	Ts_sum sum(Ts* A, int arrayLength)
	{
		Ts_sum sum = 0;
		for (int i = 0; i < arrayLength; i++)
		{
			sum += A[i];
		}
		return sum;
	}
	Ts_sum sum(Ta Input)
	{
		return sum(Input.GetArray(), Input.Length);
	}
	Tc_sum sum(Tc* A, int arrayLength)
	{
		Tc_sum sum;
		sum.real = 0;
		sum.imag = 0;
		for (int i = 0; i < arrayLength; i++)
		{
			sum = sum + A[i];
		}
		return sum;
	}
	Tc_sum sum(Tca Input)
	{
		return sum(Input.GetArray(), Input.Length);
	}
	Ts_sum sum(Ts* A, int StartIndex, int EndIndex)
	{
		Ts_sum sum = 0;
		for (int i = StartIndex; i <= EndIndex; i++)
		{
			sum += A[i];
		}
		return sum;
	}

	Ts_sum sumReal(Tc* A, int arrayLength)
	{
		Ts_sum sum;
		sum = 0;
		for (int i = 0; i < arrayLength; i++)
		{
			sum = sum + A[i].real;
		}
		return sum;
	}
	Ts_sum sumReal(Tca Input)
	{
		return sumReal(Input.GetArray(), Input.Length);
	}

	Ts_sum sumImage(Tc* A, int arrayLength)
	{
		Ts_sum sum;
		sum = 0;
		for (int i = 0; i < arrayLength; i++)
		{
			sum = sum + A[i].imag;
		}
		return sum;
	}
	Ts_sum sumImage(Tca Input)
	{
		return sumImage(Input.GetArray(), Input.Length);
	}

	Ts Round(Ts A)
	{
		return round(A);
		//return floor(A + 0.5);
	}
	Tc Round(Tc A)
	{
		Tc res;
		res.real = Round(A.real);
		res.imag = Round(A.imag);
		return res;
	}
	Ts* Round(Ts* A, int ALength)
	{
		Ts* res = this->AllocMem_Single(ALength);
		for (int i = 0; i < ALength; i++)
		{
			res[i] = Round(A[i]);
		}
		return res;
	}
	Ta Round(Ta Input)
	{
		Ta res(this->MemManager);
		res.SetArray(Round(Input.GetArray(), Input.Length), Input.Length);
		return res;
	}
	Tc* Round(Tc* A, int ALength)
	{
		Tc* res = this->AllocMem_Complex(ALength);
		for (int i = 0; i < ALength; i++)
		{
			res[i].real = Round(A[i].real);
			res[i].imag = Round(A[i].imag);
		}
		return res;
	}
	Tca Round(Tca Input)
	{
		Tca res(this->MemManager);
		res.SetArray(Round(Input.GetArray(), Input.Length), Input.Length);
		return res;
	}

	void Round_inplace(Tc* A, int ALength)
	{
		for (int i = 0; i < ALength; i++)
		{
			A[i].real = Round(A[i].real);//loop vectorized
			A[i].imag = Round(A[i].imag);
		}
	}
	void Round_inplace(Tca Input)
	{
		Round_inplace(Input.GetArray(), Input.Length);

	}
	void Round_inplace(Ts* A, int ALength)
	{
		for (int i = 0; i < ALength; i++)
		{
			A[i] = Round(A[i]); //loop vectorized
		}
	}
	void Round_inplace(Ta Input)
	{
		Round_inplace(Input.GetArray(), Input.Length);
	}

	void RoundReal_inplace(Tc* A, int ALength)
	{
		for (int i = 0; i < ALength; i++)
		{
			A[i].real = Round(A[i].real);//loop vectorized
		}
	}
	void RoundReal_inplace(Tca Input)
	{
		RoundReal_inplace(Input.GetArray(), Input.Length);
	}
	void RoundImage_inplace(Tc* A, int ALength)
	{
		for (int i = 0; i < ALength; i++)
		{
			A[i].imag = Round(A[i].image);//loop vectorized
		}
	}
	void RoundImage_inplace(Tca Input)
	{
		RoundImage_inplace(Input.GetArray(), Input.Length);
	}

	Ts_sum InnerProduct(Ts *A, Ts *B, int arrayLength)
	{
		Ts_sum InPr = 0;
		for (int i = 0; i < arrayLength; i++)
		{
			InPr = InPr + (A[i] * B[i]);
		}
		return InPr;
	}
	Ts_sum InnerProduct(Ta Input, Ta B)
	{
		return InnerProduct(Input.GetArray(), B.GetArray(), Input.Length);
	}

	Tc_sum InnerProduct(Tc *A, Tc *B, int arrayLength)
	{
		Tc_sum InPr;
		InPr.real = 0;
		InPr.imag = 0;
		for (int i = 0; i < arrayLength; i++)
		{
			InPr = InPr + (A[i] * B[i]);
		}
		return InPr;
	}
	Tc_sum InnerProduct(Tca Input, Tca B)
	{
		return InnerProduct(Input.GetArray(), B.GetArray(), Input.Length);
	}

	Tc_sum InnerProductA_ConjB(Tc *A, Tc *B, int arrayLength)
	{
		Tc_sum InPr;
		InPr.real = 0;
		InPr.imag = 0;
		for (int i = 0; i < arrayLength; i++)
		{
			InPr.real += (A[i].real * B[i].real) + (A[i].imag * B[i].imag);
			InPr.imag += (A[i].imag * B[i].real)-(A[i].real * B[i].imag);
		}

	
		return InPr;
	}
	Tc_sum InnerProductA_ConjB(Tca Input, Tca B)
	{
		return InnerProductA_ConjB(Input.GetArray(), B.GetArray(), Input.Length);
	}
};
#endif