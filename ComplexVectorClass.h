#pragma once
#ifndef COMPLEXVECTORCLASS_H
#define COMPLEXVECTORCLASS_H
#include "ComplexCoreClass.h"

TemplateDefinition
class ComplexVectorClass : ComplexCoreClass <TemplateParameter>
{

public:
	ComplexVectorClass()
	{
		// dont call base class default constructor directly, icc has problem with it.
		// default constructor of base class automatically called befor constructor of derived class.
		// but parametrized constructor of base class should be called explicitly.
	}
	ComplexVectorClass(MemoryManagerClass *MemoryManager) : BaseConstructor
	{

	}

	Ts* MulArrayAToX(Ts *A, int arrayLength, Ts X)
	{
		if (arrayLength == 0)
			return NULL;
		Ts *mul = this->AllocMem_Single(arrayLength);
		for (int i = 0; i<arrayLength; i++)
		{
			mul[i] = A[i] * X;
		}
		return mul;
	}
	Ta MulArrayAToX(Ta Input, Ts X)
	{
		Ta res(this->MemManager);
		res.SetArray(MulArrayAToX(Input.GetArray(), Input.Length, X), Input.Length);

		return res;
	}
	Tc* MulArrayAToX(Tc *A, int arrayLength, Ts X)
	{
		if (arrayLength == 0)
			return NULL;
		Tc *mul = this->AllocMem_Complex(arrayLength);
		for (int i = 0; i<arrayLength; i++)
		{
			mul[i].real = A[i].real*X;
			mul[i].imag = A[i].imag*X;
		}
		return mul;
	}
	Tca MulArrayAToX(Tca Input, Ts X)
	{
		Tca res(this->MemManager);
		res.SetArray(MulArrayAToX(Input.GetArray(), Input.Length, X), Input.Length);
		return res;
	}
	Tc* MulArrayAToX(Tc *A, int arrayLength, Ts *X)
	{
		if (arrayLength == 0)
			return NULL;
		Tc *mul = this->AllocMem_Complex(arrayLength);
		for (int i = 0; i<arrayLength; i++)
		{
			mul[i].real = A[i].real*X[i];
			mul[i].imag = A[i].imag*X[i];
		}
		return mul;
	}
	Tca MulArrayAToX(Tca Input, Ts* X)
	{
		Tca res(this->MemManager);
		res.SetArray(MulArrayAToX(Input.GetArray(), Input.Length, X), Input.Length);
		return res;
	}
	Tca MulArrayAToX(Tca Input, Ta X)
	{
		Tca res = MulArrayAToX(Input, X.GetArray());
		return res;
	}
	Tc* MulArrayAToX(Tc *A, int arrayLength, Tc X)
	{
		if (arrayLength == 0)
			return NULL;
		Tc *mul = this->AllocMem_Complex(arrayLength);
		if (X.real == 1 || X.real == 0 || X.imag == 1 || X.imag == 0)
		{
			if (X.real == 1 && X.imag == 0)
			{
				for (int i = 0; i<arrayLength; i++)
				{
					mul[i] = A[i];
				}
			}
			else if (X.real == 0 && X.imag == 1)
			{
				for (int i = 0; i<arrayLength; i++)
				{
					mul[i] = MulWithRightZeroRealAndOneImage(A[i], X);
				}
			}
			else if (X.real == 1)
			{
				for (int i = 0; i<arrayLength; i++)
				{
					mul[i] = MulWithRightOneReal(A[i], X);
				}
			}
			else if (X.real == 0)
			{
				for (int i = 0; i<arrayLength; i++)
				{
					mul[i] = MulWithRightZeroReal(A[i], X);
				}
			}
			else if (X.imag == 1)
			{
				for (int i = 0; i<arrayLength; i++)
				{
					mul[i] = MulWithRightOneImage(A[i], X);
				}
			}
			else if (X.imag == 0)
			{
				for (int i = 0; i<arrayLength; i++)
				{
					mul[i] = MulWithRightZeroImage(A[i], X);
				}
			}
		}
		else
		{
			for (int i = 0; i<arrayLength; i++)
			{
				mul[i] = A[i] * X;
			}
		}
		return mul;
	}
	

	Tc MulWithRightZeroReal(Tc A, Tc B)
	{
		Tc tmp;
		tmp.real = -(A.imag * B.imag);
		tmp.imag = (A.real * B.imag);
		return tmp;
	}
	Tc MulWithRightZeroImage(Tc A, Tc B)
	{
		Tc tmp;
		tmp.real = (A.real * B.real);
		tmp.imag = (A.imag * B.real);
		return tmp;
	}
	Tc MulWithRightOneReal(Tc A, Tc B)
	{
		Tc tmp;
		tmp.real = (A.real) - (A.imag * B.imag);
		tmp.imag = (A.real * B.imag) + (A.imag);
		return tmp;
	}
	Tc MulWithRightOneImage(Tc A, Tc B)
	{
		Tc tmp;
		tmp.real = (A.real * B.real) - (A.imag);
		tmp.imag = (A.real) + (A.imag * B.real);
		return tmp;
	}

	Tc MulWithRightZeroRealAndOneImage(Tc A, Tc B)
	{
		Tc tmp;
		tmp.real = -A.imag;
		tmp.imag = A.real;
		return tmp;
	}
	Tca MulArrayAToX(Tca Input, Tc X)
	{
		Tca res(this->MemManager);
		res.SetArray(MulArrayAToX(Input.GetArray(), Input.Length, X), Input.Length);
		return res;
	}
	Tc* MulArrayAToX(Tc *A, int arrayLength, Tc* X)
	{
		if (arrayLength == 0)
			return NULL;
		Tc *mul = this->AllocMem_Complex(arrayLength);
		for (int i = 0; i<arrayLength; i++)
		{
			mul[i] = A[i] * X[i];
		}
		return mul;
	}
	Tca MulArrayAToX(Tca Input, Tc* X)
	{
		Tca res(this->MemManager);
		res.SetArray(MulArrayAToX(Input.GetArray(), Input.Length, X), Input.Length);
		return res;
	}

	Tc* MulArrayAToConjX(Tc *A, int arrayLength, Tc* X)
	{
		if (arrayLength == 0)
			return NULL;
		Tc *mul = this->AllocMem_Complex(arrayLength);
		for (int i = 0; i<arrayLength; i++)
		{
			mul[i] = this->MulAtoConjB( A[i] , X[i]);
		}
		return mul;
	}
	Tca MulArrayAToConjX(Tca Input, Tc* X)
	{
		Tca res(this->MemManager);
		res.SetArray(MulArrayAToX(Input.GetArray(), Input.Length, X), Input.Length);
		return res;
	}

	void MulRealArrayAToX_inplace(Tc *A, int arrayLength, Ts X)
	{
		for (int i = 0; i < arrayLength; i++)
		{
			A[i].real = A[i].real*X;//loop vectorized
		}
	}
	void MulImageArrayAToX_inplace(Tc *A, int arrayLength, Ts X)
	{
		for (int i = 0; i < arrayLength; i++)
		{
			A[i].imag = A[i].imag*X;//loop vectorized
		}
	}
	Tc* MulRealArrayAToX(Tc *A, int arrayLength, Ts X)
	{
		if (arrayLength == 0)
			return NULL;
		Tc *mul = this->AllocMem_Complex(arrayLength);
		for (int i = 0; i < arrayLength; i++)
		{
			mul[i].real = A[i].real*X;//loop vectorized
			mul[i].imag = A[i].imag;
		}
		return mul;
	}
	Tc* MulImageArrayAToX(Tc *A, int arrayLength, Ts X)
	{
		if (arrayLength == 0)
			return NULL;
		Tc *mul = this->AllocMem_Complex(arrayLength);
		for (int i = 0; i < arrayLength; i++)
		{
			mul[i].imag = A[i].imag*X;//loop vectorized
			mul[i].real = A[i].real;
		}
		return mul;
	}

	void MulRealArrayAToX_inplace(Tca A, Ts X)
	{
		for (int i = 0; i < A.Length; i++)
		{
			A[i].real = A[i].real*X;//loop vectorized
		}
	}
	void MulImageArrayAToX_inplace(Tca A, Ts X)
	{
		for (int i = 0; i < A.Length; i++)
		{
			A[i].imag = A[i].imag*X;//loop vectorized
		}
	}
	Tca MulRealArrayAToX(Tca A, Ts X)
	{
		if (A.Length == 0)
			return NULL;
		Tca mul = Tca(A.Length, this->MemManager);
		for (int i = 0; i < A.Length; i++)
		{
			mul[i].real = A[i].real*X;//loop vectorized
			mul[i].imag = A[i].imag;
		}
		mul.Length = A.Length;
		return mul;
	}
	Tca MulImageArrayAToX(Tca A, Ts X)
	{
		if (A.Length == 0)
			return NULL;
		Tca mul = Tca(A.Length, this->MemManager);
		for (int i = 0; i < A.Length; i++)
		{
			mul[i].imag = A[i].imag*X;//loop vectorized
			mul[i].real = A[i].real;
		}
		mul.Length = A.Length;
		return mul;
	}

	void MulArrayAToX_inplace(Tc *A, int arrayLength, Ts X)
	{
		for (int i = 0; i<arrayLength; i++)
		{
			A[i].real = A[i].real*X;//loop vectorized
			A[i].imag = A[i].imag*X;
		}
	}
	void MulArrayAToX_inplace(Tca Input, Ts X)
	{
		MulArrayAToX_inplace(Input.GetArray(), Input.Length, X);

	}
	void MulArrayAToX_inplace(Tc *A, int arrayLength, Ts *X)
	{
		for (int i = 0; i<arrayLength; i++)
		{
			A[i].real = A[i].real*X[i];
			A[i].imag = A[i].imag*X[i];
		}
	}
	void MulArrayAToX_inplace(Tca Input, Ts *X)
	{
		MulArrayAToX_inplace(Input.GetArray(), Input.Length, X);

	}
	void  MulArrayAToX_inplace(Ts *A, int arrayLength, Ts X)
	{
#if Use_Ipp==1
		ippsMulC_64f_I(X, A, arrayLength);
#else
		for (int i = 0; i<arrayLength; i++)
		{
			A[i] = A[i] * X;//loop vectorized
		}
#endif

	}
	void  MulArrayAToX_inplace(Ta Input, Ts X)
	{
		MulArrayAToX_inplace(Input.GetArray(), Input.Length, X);

	}
	void MulArrayAToX_inplace(Tc *A, int arrayLength, Tc X)
	{
		if (arrayLength == 0)
			return;
		if (X.real == 1 || X.real == 0 || X.imag == 1 || X.imag == 0)
		{
			if (X.real == 1 && X.imag == 0)
			{
				/*for(int i = 0;i<arrayLength;i++)
				{
				mul[i] =A[i];
				}*/
				return;
			}
			else if (X.real == 0 && X.imag == 1)
			{
				for (int i = 0; i<arrayLength; i++)
				{
					A[i] = MulWithRightZeroRealAndOneImage(A[i], X);
				}
			}
			else if (X.real == 1)
			{
				for (int i = 0; i<arrayLength; i++)
				{
					A[i] = MulWithRightOneReal(A[i], X);
				}
			}
			else if (X.real == 0)
			{
				for (int i = 0; i<arrayLength; i++)
				{
					A[i] = MulWithRightZeroReal(A[i], X);
				}
			}
			else if (X.imag == 1)
			{
				for (int i = 0; i<arrayLength; i++)
				{
					A[i] = MulWithRightOneImage(A[i], X);
				}
			}
			else if (X.imag == 0)
			{
				for (int i = 0; i<arrayLength; i++)
				{
					A[i] = MulWithRightZeroImage(A[i], X);
				}
			}
		}
		else
		{
			for (int i = 0; i<arrayLength; i++)
			{
				A[i] = A[i] * X;
			}
		}
		return;
	}
	void MulArrayAToX_inplace(Tca Input, Tc X)
	{
		MulArrayAToX_inplace(Input.GetArray(), Input.Length, X);

	}
	void MulArrayAToX_inplace(Tc *A, int arrayLength, Tc* X)
	{
		for (int i = 0; i<arrayLength; i++)
		{
			A[i] = A[i] * X[i];
		}
	}
	void MulArrayAToX_inplace(Tca Input, Tc* X)
	{
		MulArrayAToX_inplace(Input.GetArray(), Input.Length, X);

	}

	void MulArrayAToConjX_inplace(Tc *A, int arrayLength, Tc* X)
	{
		for (int i = 0; i<arrayLength; i++)
		{
			this->MulAtoConjB_inplace(A[i], X[i]);
		}
	}
	void MulArrayAToConjX_inplace(Tca Input, Tc* X)
	{
		MulArrayAToConjX_inplace(Input.GetArray(), Input.Length, X);

	}
	void MulArrayAToX_ToOutMem(Tc*  A, int arrayLength, Tc*  X, Tc*   out)
	{
		for (int i = 0; i < arrayLength; i++)
		{
			out[i] = A[i] * X[i];
		}
	}
	void MulArrayAToX_ToOutMem(Tc*  A, int arrayLength, Tc  X, Tc*   out)
	{
		for (int i = 0; i < arrayLength; i++)
		{
			out[i] = A[i] * X;
		}
	}
	void MulArrayAToConjX_ToOutMem(Tc*  A, int arrayLength, Tc*  X, Tc*   out)
	{
		for (int i = 0; i < arrayLength; i++)
		{
			out[i] = this->MulAtoConjB( A[i] , X[i]);
		}
	}
	void MulArrayAToConjX_ToOutMem(Tc*  A, int arrayLength, Tc  X, Tc*   out)
	{
		for (int i = 0; i < arrayLength; i++)
		{
			out[i] = this->MulAtoConjB(A[i], X);
		}
	}

	Ts* DivArrayAToX(Ts *A, int arrayLength, Ts X)
	{
		if (arrayLength == 0)
			return NULL;
		Ts *mul = this->AllocMem_Single(arrayLength);
		for (int i = 0; i < arrayLength; i++)
		{
			mul[i] = A[i] / X;
		}
		return mul;
	}
	Ta DivArrayAToX(Ta Input, Ts X)
	{
		Ta res(this->MemManager);
		res.SetArray(DivArrayAToX(Input.GetArray(), Input.Length, X), Input.Length);
		return res;
	}
	Tc* DivArrayAToX(Tc *A, int arrayLength, Ts* X)
	{
		if (arrayLength == 0)
			return NULL;
		Tc *mul = this->AllocMem_Complex(arrayLength);
		for (int i = 0; i < arrayLength; i++)
		{
			mul[i].real = A[i].real / X[i];
			mul[i].imag = A[i].imag / X[i];
		}
		return mul;
	}
	Tc* DivArrayAToX(Tc *A, int arrayLength, Tc* X)
	{
		if (arrayLength == 0)
			return NULL;
		Tc *mul = this->AllocMem_Complex(arrayLength);
		for (int i = 0; i < arrayLength; i++)
		{
			mul[i] = A[i] / X[i];
		}
		return mul;
	}
	Tca DivArrayAToX(Tca Input, Ts *X)
	{
		Tca res(this->MemManager);
		res.SetArray(DivArrayAToX(Input.GetArray(), Input.Length, X), Input.Length);
		return res;
	}
	Tca DivArrayAToX(Tca Input, Tc *X)
	{
		Tca res(this->MemManager);
		res.SetArray(DivArrayAToX(Input.GetArray(), Input.Length, X), Input.Length);
		return res;
	}
	Tc* DivArrayAToX(Tc *A, int arrayLength, Ts X)
	{
		if (arrayLength == 0)
			return NULL;
		Tc *mul = this->AllocMem_Complex(arrayLength);
		for (int i = 0; i < arrayLength; i++)
		{
			mul[i].real = A[i].real / X;
			mul[i].imag = A[i].imag / X;
		}
		return mul;
	}
	Tc* DivArrayAToX(Tc *A, int arrayLength, Tc X)
	{
		if (arrayLength == 0)
			return NULL;
		Tc *mul = this->AllocMem_Complex(arrayLength);
		for (int i = 0; i < arrayLength; i++)
		{
			mul[i] = A[i] / X;
		}
		return mul;
	}
	Tca DivArrayAToX(Tca Input, Ts X)
	{
		Tca res(this->MemManager);
		res.SetArray(DivArrayAToX(Input.GetArray(), Input.Length, X), Input.Length);
		return res;
	}
	void DivArrayAToX_inplace(Tc *A, int arrayLength, Ts X)
	{
		for (int i = 0; i < arrayLength; i++)
		{
			A[i].real = A[i].real / X;//loop vectorized
			A[i].imag = A[i].imag / X;
		}
	}
	void DivArrayAToX_inplace(Tc *A, int arrayLength, Tc X)
	{
		for (int i = 0; i < arrayLength; i++)
		{
			A[i] = A[i] / X;
		}
	}
	void DivArrayAToX_inplace(Tca Input, Ts X)
	{
		DivArrayAToX_inplace(Input.GetArray(), Input.Length, X);

	}
	void DivArrayAToX_inplace(Tca Input, Tc X)
	{
		DivArrayAToX_inplace(Input.GetArray(), Input.Length, X);

	}
	void DivArrayAToX_inplace(Tc *A, int arrayLength, Tc* X)
	{
		for (int i = 0; i < arrayLength; i++)
		{
			A[i] = A[i]/ X[i];
		}
	}
	void DivArrayAToX_inplace(Tca Input, Ts* X)
	{
		DivArrayAToX_inplace(Input.GetArray(), Input.Length, X);

	}
	void DivArrayAToX_inplace(Tca Input, Tc* X)
	{
		DivArrayAToX_inplace(Input.GetArray(), Input.Length, X);

	}
	void  DivArrayAToX_inplace(Ts *A, int arrayLength, Ts X)
	{
		for (int i = 0; i < arrayLength; i++)
		{
			A[i] = A[i] / X;//loop vectorized
		}
	}
	void  DivArrayAToX_inplace(Ta Input, Ts X)
	{
		DivArrayAToX_inplace(Input.GetArray(), Input.Length, X);
	}

	void DivArrayAByX_ToOutMem(Tc *a, int arrayLength, Ts *X, Tc* out, AssignmentOperator Aop = AssignmentOperator::Assignment)
	{
		if (Aop == AssignmentOperator::Assignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				out[i].real = a[i].real / X[i];
				out[i].imag = a[i].imag / X[i];
			}
		}
		else if (Aop == AssignmentOperator::AdditionAssignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				out[i].real += a[i].real / X[i];
				out[i].imag += a[i].imag / X[i];
			}
		}
		else if (Aop == AssignmentOperator::divisionAssignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				out[i].real /= a[i].real / X[i];
				out[i].imag /= a[i].imag / X[i];
			}
		}
		else if (Aop == AssignmentOperator::MultiplicationAssignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				out[i].real *= a[i].real / X[i];
				out[i].imag *= a[i].imag / X[i];
			}
		}
		else if (Aop == AssignmentOperator::SubtractionAssignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				out[i].real -= a[i].real / X[i];
				out[i].imag -= a[i].imag / X[i];
			}
		}

	}
	void DivArrayAByX_ToOutMem(Tca a, Ts *X, Tc* out, AssignmentOperator Aop = AssignmentOperator::Assignment)
	{
		DivArrayAByX_ToOutMem(a.GetArray(), a.Length, X, out, Aop);
	}
	void DivArrayAByX_ToOutMem(Tca a, Ta X, Tc* out, AssignmentOperator Aop = AssignmentOperator::Assignment)
	{
		DivArrayAByX_ToOutMem(a.GetArray(), a.Length, X.GetArray(), out, Aop);
	}

	void DivArrayAByX_NanFree_ToOutMem(Tc *a, int arrayLength, Ts *X, Tc* out, AssignmentOperator Aop = AssignmentOperator::Assignment)
	{
		if (Aop == AssignmentOperator::Assignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				if (X[i] != 0)
				{
					out[i].real = a[i].real / X[i];
					out[i].imag = a[i].imag / X[i];
				}
				else
				{
					out[i].real = 0;
					out[i].imag = 0;
				}
			}
		}
		else if (Aop == AssignmentOperator::AdditionAssignment)
		{

			for (int i = 0; i < arrayLength; i++)
			{
				if (X[i] != 0)
				{
					out[i].real += a[i].real / X[i];
					out[i].imag += a[i].imag / X[i];
				}
				else
				{
					out[i].real = 0;
					out[i].imag = 0;
				}
			}
		}
		else if (Aop == AssignmentOperator::divisionAssignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				if (X[i] != 0)
				{
					out[i].real /= a[i].real / X[i];
					out[i].imag /= a[i].imag / X[i];
				}
				else
				{
					out[i].real = 0;
					out[i].imag = 0;
				}
			}
		}
		else if (Aop == AssignmentOperator::MultiplicationAssignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				if (X[i] != 0)
				{
					out[i].real *= a[i].real / X[i];
					out[i].imag *= a[i].imag / X[i];
				}
				else
				{
					out[i].real = 0;
					out[i].imag = 0;
				}
			}
		}
		else if (Aop == AssignmentOperator::SubtractionAssignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				if (X[i] != 0)
				{
					out[i].real -= a[i].real / X[i];
					out[i].imag -= a[i].imag / X[i];
				}
				else
				{
					out[i].real = 0;
					out[i].imag = 0;
				}
			}
		}
	}
	void DivArrayAByX_NanFree_ToOutMem(Tca a, Ts *X, Tc* out, AssignmentOperator Aop = AssignmentOperator::Assignment)
	{
		DivArrayAByX_NanFree_ToOutMem(a.GetArray(), a.Length, X, out, Aop);
	}
	void DivArrayAByX_NanFree_ToOutMem(Tca a, Ta X, Tc* out, AssignmentOperator Aop = AssignmentOperator::Assignment)
	{
		DivArrayAByX_NanFree_ToOutMem(a.GetArray(), a.Length, X.GetArray(), out, Aop);
	}

	Ts* SubtractArrayAByX(Ts *a, int arrayLength, Ts X)
	{
		if (arrayLength <= 0)
			return NULL;
		Ts* res = this->AllocMem_Single(arrayLength);
		for (int i = 0; i < arrayLength; i++)
		{
			res[i] = a[i] - X;
		}
		return res;
	}
	Ts* SubtractArrayAByX(Ts *a, int arrayLength, Ts* X)
	{
		if (arrayLength <= 0)
			return NULL;
		Ts* res = this->AllocMem_Single(arrayLength);
		for (int i = 0; i < arrayLength; i++)
		{
			res[i] = a[i] - X[i];
		}
		return res;
	}
	Ta SubtractArrayAByX(Ta Input, Ts X)
	{
		Ta res(this->MemManager);
		if (Input.Length <= 0)
		{
			return res;
		}
		res.SetArray(SubtractArrayAByX(Input.GetArray(), Input.Length, X), Input.Length);
		return res;
	}
	Ta SubtractArrayAByX(Ta Input, Ts* X)
	{
		Ta res(this->MemManager);
		if (Input.Length <= 0)
		{
			return res;
		}
		res.SetArray(SubtractArrayAByX(Input.GetArray(), Input.Length, X), Input.Length);
		return res;
	}
	Tc* SubtractArrayAByX(Tc *a, int arrayLength, Tc X)
	{
		if (arrayLength <= 0)
			return NULL;
		Tc* res = this->AllocMem_Complex(arrayLength);
		for (int i = 0; i < arrayLength; i++)
		{
			res[i].real = a[i].real - X.real;
			res[i].imag = a[i].imag - X.imag;
		}
		return res;
	}
	Tc* SubtractArrayAByX(Tc* a, int arrayLength, Ts Xre, Ts Ximg)
	{
		Tc X;
		X.real = Xre;
		X.imag = Ximg;
		if (arrayLength <= 0)
			return NULL;
		Tc* res = this->AllocMem_Complex(arrayLength);
		for (int i = 0; i < arrayLength; i++)
		{
			res[i].real = a[i].real - X.real;
			res[i].imag = a[i].imag - X.imag;
		}
		return res;
	}
	Tc* SubtractArrayAByX(Tc *a, int arrayLength, Tc *X)
	{
		if (arrayLength <= 0)
			return NULL;
		Tc* res = this->AllocMem_Complex(arrayLength);
		for (int i = 0; i < arrayLength; i++)
		{
			res[i].real = a[i].real - X[i].real;
			res[i].imag = a[i].imag - X[i].imag;
		}
		return res;
	}
	Tca SubtractArrayAByX(Tca Input, Tc X)
	{
		Tca res(this->MemManager);
		if (Input.Length <= 0)
		{
			return res;
		}
		res.SetArray(SubtractArrayAByX(Input.GetArray(), Input.Length, X), Input.Length);
		return res;
	}
	Tca SubtractArrayAByX(Tca Input, Ts Xre, Ts Ximg)
	{
		Tca res(this->MemManager);
		if (Input.Length <= 0)
		{
			return res;
		}
		res.SetArray(SubtractArrayAByX(Input.GetArray(), Input.Length, Xre, Ximg), Input.Length);
		return res;
	}
	Tca SubtractArrayAByX(Tca Input, Tc *X)
	{
		Tca res(this->MemManager);
		if (Input.Length <= 0)
		{
			return res;
		}
		res.SetArray(SubtractArrayAByX(Input.GetArray(), Input.Length, X), Input.Length);
		return res;
	}

	void SubtractArrayAByX_inplace(Ts *a, int arrayLength, Ts X)
	{
#if Use_Ipp==1
		ippsSubC_64f_I(X, a, arrayLength);
#else
		for (int i = 0; i < arrayLength; i++)
		{
			a[i] = a[i] - X;
		}
#endif
	}
	void SubtractArrayAByX_inplace(Ts *a, int arrayLength, Ts* X)
	{
		for (int i = 0; i < arrayLength; i++)
		{
			a[i] = a[i] - X[i];
		}
	}
	void SubtractArrayAByX_inplace(Tc *a, int arrayLength, Tc X)
	{
		for (int i = 0; i < arrayLength; i++)
		{
			a[i].real = a[i].real - X.real;
			a[i].imag = a[i].imag - X.imag;
		}
	}
	void SubtractArrayAByX_inplace(Tc* a, int arrayLength, Ts Xre, Ts Ximg)
	{
		Tc X;
		X.real = Xre;
		X.imag = Ximg;
		for (int i = 0; i < arrayLength; i++)
		{
			a[i].real = a[i].real - X.real;
			a[i].imag = a[i].imag - X.imag;
		}
	}
	void SubtractArrayAByX_inplace(Tc *a, int arrayLength, Tc *X)
	{
		for (int i = 0; i < arrayLength; i++)
		{
			a[i].real = a[i].real - X[i].real;
			a[i].imag = a[i].imag - X[i].imag;
		}
	}

	void SubtractArrayAByX_inplace(Ta Input, Ts X)
	{
		if (Input.Length <= 0)
		{
			return;
		}
		SubtractArrayAByX_inplace(Input.GetArray(), Input.Length, X);

	}
	void SubtractArrayAByX_inplace(Ta Input, Ts* X)
	{
		if (Input.Length <= 0)
		{
			return;
		}
		SubtractArrayAByX_inplace(Input.GetArray(), Input.Length, X);

	}
	void SubtractArrayAByX_inplace(Tca Input, Tc X)
	{
		if (Input.Length <= 0)
		{
			return;
		}
		SubtractArrayAByX_inplace(Input.GetArray(), Input.Length, X);

	}
	void SubtractArrayAByX_inplace(Tca Input, Ts Xre, Ts Ximg)
	{
		if (Input.Length <= 0)
		{
			return;
		}
		SubtractArrayAByX_inplace(Input.GetArray(), Input.Length, Xre, Ximg);

	}
	void SubtractArrayAByX_inplace(Tca Input, Tc *X)
	{
		if (Input.Length <= 0)
		{
			return;
		}
		SubtractArrayAByX_inplace(Input.GetArray(), Input.Length, X);

	}

	void SubtractArrayAByX_ToOutMem(Tc *a, int arrayLength, Tc *X, Tc* out, AssignmentOperator Aop = AssignmentOperator::Assignment)
	{
		if (Aop == AssignmentOperator::Assignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				out[i].real = a[i].real - X[i].real;
				out[i].imag = a[i].imag - X[i].imag;
			}
		}
		else if (Aop == AssignmentOperator::AdditionAssignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				out[i].real += a[i].real - X[i].real;
				out[i].imag += a[i].imag - X[i].imag;
			}
		}
		else if (Aop == AssignmentOperator::divisionAssignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				out[i].real /= a[i].real - X[i].real;
				out[i].imag /= a[i].imag - X[i].imag;
			}
		}
		else if (Aop == AssignmentOperator::MultiplicationAssignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				out[i].real *= a[i].real - X[i].real;
				out[i].imag *= a[i].imag - X[i].imag;
			}
		}
		else if (Aop == AssignmentOperator::SubtractionAssignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				out[i].real -= a[i].real - X[i].real;
				out[i].imag -= a[i].imag - X[i].imag;
			}
		}

	}
	void SubtractArrayAByX_ToOutMem(Tca a, Tc *X, Tc* out, AssignmentOperator Aop = AssignmentOperator::Assignment)
	{
		SubtractArrayAByX_ToOutMem(a.GetArray(), a.Length, X, out, Aop);
	}
	void SubtractArrayAByX_ToOutMem(Tca a, Tca X, Tc* out, AssignmentOperator Aop = AssignmentOperator::Assignment)
	{
		SubtractArrayAByX_ToOutMem(a.GetArray(), a.Length, X.GetArray(), out, Aop);
	}

	Ts* AddArrayAByX(Ts *a, int arrayLength, Ts X)
	{
		if (arrayLength <= 0)
			return NULL;
		Ts* res = this->AllocMem_Single(arrayLength);
		for (int i = 0; i < arrayLength; i++)
		{
			res[i] = a[i] + X;
		}
		return res;
	}
	Ts* AddArrayAByX(Ts *a, int arrayLength, Ts* X)
	{
		if (arrayLength <= 0)
			return NULL;
		Ts* res = this->AllocMem_Single(arrayLength);
		for (int i = 0; i < arrayLength; i++)
		{
			res[i] = a[i] + X[i];
		}
		return res;
	}
	Tc* AddArrayAByX(Tc *a, int arrayLength, Tc X)
	{
		if (arrayLength <= 0)
			return NULL;
		Tc* res = this->AllocMem_Complex(arrayLength);
		for (int i = 0; i < arrayLength; i++)
		{
			res[i].real = a[i].real + X.real;
			res[i].imag = a[i].imag + X.imag;
		}
		return res;
	}
	Tc* AddArrayAByX(Tc* a, int arrayLength, Ts Xre, Ts Ximg)
	{
		if (arrayLength <= 0)
			return NULL;
		Tc X;
		X.real = Xre;
		X.imag = Ximg;
		Tc* res = this->AllocMem_Complex(arrayLength);
		for (int i = 0; i < arrayLength; i++)
		{
			res[i].real = a[i].real + X.real;
			res[i].imag = a[i].imag + X.imag;
		}
		return res;
	}
	Tc* AddArrayAByX(Tc *a, int arrayLength, Tc *X)
	{
		if (arrayLength <= 0)
			return NULL;
		Tc* res = this->AllocMem_Complex(arrayLength);
		for (int i = 0; i < arrayLength; i++)
		{
			res[i].real = a[i].real + X[i].real;
			res[i].imag = a[i].imag + X[i].imag;
		}
		return res;
	}
	Ta AddArrayAByX(Ta Input, Ts X)
	{
		Ta res(this->MemManager);
		if (Input.Length <= 0)
		{
			return res;
		}
		res.SetArray(AddArrayAByX(Input.GetArray(), Input.Length, X), Input.Length);
		return res;
	}
	Ta AddArrayAByX(Ta Input, Ts* X)
	{
		Ta res(this->MemManager);
		if (Input.Length <= 0)
		{
			return res;
		}
		res.SetArray(AddArrayAByX(Input.GetArray(), Input.Length, X), Input.Length);
		return res;
	}
	Tca AddArrayAByX(Tca Input, Tc X)
	{
		Tca res(this->MemManager);
		if (Input.Length <= 0)
		{
			return res;
		}
		res.SetArray(AddArrayAByX(Input.GetArray(), Input.Length, X), Input.Length);
		return res;
	}
	Tca AddArrayAByX(Tca Input, Ts Xre, Ts Ximg)
	{
		Tca res(this->MemManager);
		if (Input.Length <= 0)
		{
			return res;
		}
		res.SetArray(AddArrayAByX(Input.GetArray(), Input.Length, Xre, Ximg), Input.Length);
		res.Length = Input.Length;
		return res;
	}
	Tca AddArrayAByX(Tca Input, Tc *X)
	{
		Tca res(this->MemManager);
		if (Input.Length <= 0)
		{
			return res;
		}
		res.SetArray(AddArrayAByX(Input.GetArray(), Input.Length, X), Input.Length);
		return res;
	}

	void AddArrayAByX_inplace(Ts *a, int arrayLength, Ts X)
	{
		for (int i = 0; i < arrayLength; i++)
		{
			a[i] = a[i] + X;
		}	
	}
	void AddArrayAByX_inplace(Ts *a, int arrayLength, Ts* X)
	{
		for (int i = 0; i < arrayLength; i++)
		{
			a[i] = a[i] + X[i];
		}		
	}
	void AddArrayAByX_inplace(Ts *a, int arrayLength, Tc* X)
	{
		for (int i = 0; i < arrayLength; i++)
		{
			a[i] = a[i] + X[i].real;
		}	
	}
	void AddArrayAByX_inplace(Tc *a, int arrayLength, Tc X)
	{
		for (int i = 0; i < arrayLength; i++)
		{
			a[i].real = a[i].real + X.real;
			a[i].imag = a[i].imag + X.imag;
		}
	}
	void AddArrayAByX_inplace(Tc* a, int arrayLength, Ts Xre, Ts Ximg)
	{
		Tc X;
		X.real = Xre;
		X.imag = Ximg;
		for (int i = 0; i < arrayLength; i++)
		{
			a[i].real = a[i].real + X.real;
			a[i].imag = a[i].imag + X.imag;
		}
		
	}
	void AddArrayAByX_inplace(Tc *a, int arrayLength, Tc *X)
	{
		for (int i = 0; i < arrayLength; i++)
		{
			a[i].real = a[i].real + X[i].real;
			a[i].imag = a[i].imag + X[i].imag;
		}
	}

	void AddArrayAByX_ToOutMem(Tc *a, int arrayLength, Tc *X,Tc* out,AssignmentOperator Aop=AssignmentOperator::Assignment)
	{
		if (Aop == AssignmentOperator::Assignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				out[i].real = a[i].real + X[i].real;
				out[i].imag = a[i].imag + X[i].imag;
			}
		}
		else if (Aop==AssignmentOperator::AdditionAssignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				out[i].real += a[i].real + X[i].real;
				out[i].imag += a[i].imag + X[i].imag;
			}
		}
		else if (Aop == AssignmentOperator::divisionAssignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				out[i].real /= a[i].real + X[i].real;
				out[i].imag /= a[i].imag + X[i].imag;
			}
		}
		else if (Aop == AssignmentOperator::MultiplicationAssignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				out[i].real *= a[i].real + X[i].real;
				out[i].imag *= a[i].imag + X[i].imag;
			}
		}
		else if (Aop == AssignmentOperator::SubtractionAssignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				out[i].real -= a[i].real + X[i].real;
				out[i].imag -= a[i].imag + X[i].imag;
			}
		}
	
	}
	void AddArrayAByX_ToOutMem(Tca a, Tc *X, Tc* out, AssignmentOperator Aop = AssignmentOperator::Assignment)
	{
		AddArrayAByX_ToOutMem(a.GetArray(), a.Length,X, out, Aop);
	}
	void AddArrayAByX_ToOutMem(Tca a, Tca X, Tc* out, AssignmentOperator Aop = AssignmentOperator::Assignment)
	{
		AddArrayAByX_ToOutMem(a.GetArray(), a.Length, X.GetArray(), out, Aop);
	}

	void AddArrayAByX_ToOutMem(Ts *a, int arrayLength, Ts *X, Ts* out, AssignmentOperator Aop = AssignmentOperator::Assignment)
	{
		if (Aop == AssignmentOperator::Assignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				out[i] = a[i] + X[i];
			}
		}
		else if (Aop == AssignmentOperator::AdditionAssignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				out[i] += a[i] + X[i];
			}
		}
		else if (Aop == AssignmentOperator::divisionAssignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				out[i] /= a[i] + X[i];
			}
		}
		else if (Aop == AssignmentOperator::MultiplicationAssignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				out[i] *= a[i] + X[i];
			}
		}
		else if (Aop == AssignmentOperator::SubtractionAssignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				out[i] -= a[i] + X[i];
			}
		}

	}
	void AddArrayAByX_ToOutMem(Ta a, Ts *X, Ts* out, AssignmentOperator Aop = AssignmentOperator::Assignment)
	{
		AddArrayAByX_ToOutMem(a.GetArray(), a.Length, X, out, Aop);
	}
	void AddArrayAByX_ToOutMem(Ta a, Ta X, Ts* out, AssignmentOperator Aop = AssignmentOperator::Assignment)
	{
		AddArrayAByX_ToOutMem(a.GetArray(), a.Length, X.GetArray(), out, Aop);
	}


	void AddArrayAByX_inplace(Ta Input, Ts X)
	{
		AddArrayAByX_inplace(Input.GetArray(), Input.Length, X);

	}
	void AddArrayAByX_inplace(Ta Input, Ts* X)
	{
		AddArrayAByX_inplace(Input.GetArray(), Input.Length, X);

	}
	void AddArrayAByX_inplace(Ta Input, Tc* X)
	{
		AddArrayAByX_inplace(Input.GetArray(), Input.Length, X);
	}
	void AddArrayAByX_inplace(Tca Input, Tc X)
	{
		AddArrayAByX_inplace(Input.GetArray(), Input.Length, X);

	}
	void AddArrayAByX_inplace(Tca Input, Ts Xre, Ts Ximg)
	{
		AddArrayAByX_inplace(Input.GetArray(), Input.Length, Xre, Ximg);

	}
	void AddArrayAByX_inplace(Tca Input, Tc *X)
	{
		AddArrayAByX_inplace(Input.GetArray(), Input.Length, X);

	}
};
#endif