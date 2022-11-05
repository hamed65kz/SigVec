#pragma once
#ifndef COMPLEXFINDCLASS_H
#define COMPLEXFINDCLASS_H
#include "ComplexCoreClass.h"

TemplateDefinition
class ComplexFindClass : ComplexCoreClass <TemplateParameter>
{
public:
	ComplexFindClass()
	{
		// dont call base class default constructor directly, icc has problem with it.
		// default constructor of base class automatically called befor constructor of derived class.
		// but parametrized constructor of base class should be called explicitly.
	}
	ComplexFindClass(MemoryManagerClass *MemoryManager) : BaseConstructor
	{

	}
	Ts* GreaterThanX(Ts* A, int Alength, Ts X)
	{
		if (Alength <= 0)
			return NULL;
		Ts* tmp = this->AllocMem_Single(Alength);
		for (int i = 0; i<Alength; i++)
		{
			if (A[i]>X)
			{
				tmp[i] = 1;
			}
		}
		return tmp;
	}
	Ts* GreaterThanX(Ts* A, int Alength, Ts *X)
	{
		if (Alength <= 0)
			return NULL;
		Ts* tmp = this->AllocMem_Single(Alength);
		for (int i = 0; i<Alength; i++)
		{
			if (A[i]>X[i])
			{
				tmp[i] = 1;
			}
		}
		return tmp;
	}
	Ta GreaterThanX(Ta A, Ts X)
	{
		Ta res(this->MemManager);
		if (A.Length <= 0)
			return res;
		res.SetArray(GreaterThanX(A.GetArray(), A.Length, X), A.Length);

		return res;
	}
	Ta GreaterThanX(Ta A, Ts *X)
	{
		Ta res(this->MemManager);
		if (A.Length <= 0)
			return res;
		res.SetArray(GreaterThanX(A.GetArray(), A.Length, X), A.Length);
		return res;
	}
	Ts GreaterThanX(Ts A, Ts X)
	{
		if (A > X)
		{
			return 1;
		}
		return 0;
	}
	void GreaterThanX_inplace(Ts* A, int Alength, Ts X)
	{
		if (Alength <= 0)
		{
			return;
		}
		for (int i = 0; i < Alength; i++)
		{
			GreaterThanX_inplace(A[i], X);
		}
	}
	void GreaterThanX_inplace(Ts* A, int Alength, Ts *X)
	{
		if (Alength <= 0)
		{
			return;
		}
		for (int i = 0; i < Alength; i++)
		{
			GreaterThanX_inplace(A[i], X[i]);
		}
	}
	void GreaterThanX_inplace(Ta Input, Ts X)
	{
		if (Input.Length <= 0)
		{
			return;
		}
		GreaterThanX_inplace(Input.GetArray(), Input.Length, X);

	}
	void GreaterThanX_inplace(Ta Input, Ts *X)
	{
		if (Input.Length <= 0)
		{
			return;
		}
		GreaterThanX_inplace(Input.GetArray(), Input.Length, X);

	}
	void GreaterThanX_inplace(Ts &A, Ts X)
	{
		if (A > X)
		{
			A = 1;
		}
		else
		{
			A = 0;
		}
	}

	Ts* LessThanX(Ts* A, int Alength, Ts X)
	{
		if (Alength <= 0)
			return NULL;
		Ts* tmp = this->AllocMem_Single(Alength);
		for (int i = 0; i < Alength; i++)
		{
			if (A[i] < X)
			{
				tmp[i] = 1;
			}
		}
		return tmp;
	}
	Ts* LessThanX(Ts* A, int Alength, Ts *X)
	{
		if (Alength <= 0)
			return NULL;
		Ts* tmp = this->AllocMem_Single(Alength);
		for (int i = 0; i < Alength; i++)
		{
			if (A[i] < X[i])
			{
				tmp[i] = 1;
			}
		}
		return tmp;
	}
	Ta LessThanX(Ta A, Ts X)
	{
		Ta res(this->MemManager);
		if (A.Length <= 0)
			return res;
		res.SetArray(LessThanX(A.GetArray(), A.Length, X), A.Length);
		return res;
	}
	Ta LessThanX(Ta A, Ts *X)
	{
		Ta res(this->MemManager);
		if (A.Length <= 0)
			return res;
		res.SetArray(LessThanX(A.GetArray(), A.Length, X), A.Length);
		return res;
	}
	Ts LessThanX(Ts A, Ts X)
	{
		if (A < X)
		{
			return 1;
		}
		return 0;
	}
	void LessThanX_inplace(Ts* A, int Alength, Ts X)
	{
		if (Alength <= 0)
		{
			return;
		}
		for (int i = 0; i < Alength; i++)
		{
			LessThanX_inplace(A[i], X);
		}
	}
	void LessThanX_inplace(Ts* A, int Alength, Ts *X)
	{
		if (Alength <= 0)
		{
			return;
		}
		for (int i = 0; i < Alength; i++)
		{
			LessThanX_inplace(A[i], X[i]);
		}
	}
	void LessThanX_inplace(Ta Input, Ts X)
	{
		if (Input.Length <= 0)
		{
			return;
		}
		GreaterThanX_inplace(Input.GetArray(), Input.Length, X);

	}
	void LessThanX_inplace(Ta Input, Ts *X)
	{
		if (Input.Length <= 0)
		{
			return;
		}
		GreaterThanX_inplace(Input.GetArray(), Input.Length, X);

	}
	void LessThanX_inplace(Ts &A, Ts X)
	{
		if (A < X)
		{
			A = 1;
		}
		else
		{
			A = 0;
		}
	}

	Ts* GreaterThanX(Tc* A, int Alen, Ts realX, Ts imagX)
	{
		if (Alen <= 0)
			return NULL;
		Ts* tmp = this->AllocMem_Single(Alen);
		for (int i = 0; i<Alen; i++)
		{
			if (realX<A[i].real &&  imagX<A[i].imag )
			{
				tmp[i] = 1;
			}
		}
		return tmp;
	}
	Ta GreaterThanX(Tca A, Ts realX, Ts imagX)
	{
		if (A.Length <= 0)
			return NULL;
		Ta tmp = Ta(GreaterThanX(A.GetArray(), A.Length, realX, imagX), A.Length, false, this->MemManager);
		return tmp;
	}


	Ts* LessThanX(Tc* A, int Alen, Ts realX, Ts imagX)
	{
		if (Alen <= 0)
			return NULL;
		Ts* tmp = this->AllocMem_Single(Alen);
		for (int i = 0; i < Alen; i++)
		{
			if ( realX > A[i].real&&  imagX > A[i].imag )
			{
				tmp[i] = 1;
			}
		}
		return tmp;
	}
	Ta LessThanX(Tca A, Ts realX, Ts imagX)
	{
		if (A.Length <= 0)
			return NULL;
		Ta tmp = Ta(LessThanX(A.GetArray(), A.Length, realX, imagX), A.Length, false, this->MemManager);
		return tmp;
	}


	Ts* GreaterThanX_real(Tc* A, int Alen, Ts realX)
	{
		if (Alen <= 0)
			return NULL;
		Ts* tmp = this->AllocMem_Single(Alen);
		for (int i = 0; i<Alen; i++)
		{
			if (realX<A[i].real)
			{
				tmp[i] = 1;
			}
		}
		return tmp;
	}
	Ta GreaterThanX_real(Tca A, Ts realX)
	{
		if (A.Length <= 0)
			return NULL;
		Ta tmp = Ta(GreaterThanX_real(A.GetArray(), A.Length, realX), A.Length, false, this->MemManager);
		return tmp;
	}


	Ts* LessThanX_real(Tc* A, int Alen, Ts realX)
	{
		if (Alen <= 0)
			return NULL;
		Ts* tmp = this->AllocMem_Single(Alen);
		for (int i = 0; i < Alen; i++)
		{
			if ( realX>A[i].real )
			{
				tmp[i] = 1;
			}
		}
		return tmp;
	}
	Ta LessThanX_real(Tca A, Ts realX)
	{
		if (A.Length <= 0)
			return NULL;
		Ta tmp = Ta(LessThanX_real(A.GetArray(), A.Length, realX), A.Length, false, this->MemManager);
		return tmp;
	}


	Ts* GreaterThanX_imag(Tc* A, int Alen, Ts imagX)
	{
		if (Alen <= 0)
			return NULL;
		Ts* tmp = this->AllocMem_Single(Alen);
		for (int i = 0; i<Alen; i++)
		{
			if ( imagX<A[i].imag )
			{
				tmp[i] = 1;
			}
		}
		return tmp;
	}
	Ta GreaterThanX_imag(Tca A, Ts imagX)
	{
		if (A.Length <= 0)
			return NULL;
		Ta tmp = Ta(GreaterThanX_imag(A.GetArray(), A.Length, imagX), A.Length, false, this->MemManager);
		return tmp;
	}


	Ts* LessThanX_imag(Tc* A, int Alen, Ts imagX)
	{
		if (Alen <= 0)
			return NULL;
		Ts* tmp = this->AllocMem_Single(Alen);
		for (int i = 0; i < Alen; i++)
		{
			if (imagX>A[i].imag  )
			{
				tmp[i] = 1;
			}
		}
		return tmp;
	}
	Ta LessThanX_imag(Tca A, Ts imagX)
	{
		if (A.Length <= 0)
			return NULL;
		Ta tmp = Ta(LessThanX_imag(A.GetArray(), A.Length, imagX), A.Length, false, this->MemManager);
		return tmp;
	}

	Ta FindGreaterThanXIndex(Ts* A, int Alength, Ts X)
	{
		Ta res(this->MemManager);
		if (Alength <= 0)
			return res;
		Ts* tmp = this->AllocMem_Single(Alength);
		int c = 0;
		for (int i = 0; i<Alength; i++)
		{
			if (A[i]>X)
			{
				tmp[c] = i;
				c++;
			}
		}
		if (c == 0)
		{
			this->FREEMEM((void**)&tmp);
		}

		res.SetArray(tmp, c);
		return res;
	}
	void FindGreaterThanXIndex_ToOutMem(Ts* A, int Alength, Ts X,Ts* OutMem,int &OutLen)
	{
		if (Alength <= 0)
			return ;
		
		OutLen = 0;
		for (int i = 0; i<Alength; i++)
		{
			if (A[i]>X)
			{
				OutMem[OutLen] = i;
				OutLen++;
			}
		}


	}
	Ta FindGreaterThanXIndex(Ts* A, int Alength, Ts *X)
	{
		Ta res(this->MemManager);
		if (Alength <= 0)
			return res;
		Ts* tmp = this->AllocMem_Single(Alength);
		int c = 0;
		for (int i = 0; i<Alength; i++)
		{
			if (A[i]>X[i])
			{
				tmp[c] = i;
				c++;
			}
		}
		if (c == 0)
		{
			this->FREEMEM((void**)&tmp);
		}

		res.SetArray(tmp, c);
		return res;
	}
	Ta FindGreaterThanXIndex(Ta Input, Ts X)
	{
		Ta res(this->MemManager);
		if (Input.Length <= 0)
		{
			return res;
		}
		return FindGreaterThanXIndex(Input.GetArray(), Input.Length, X);
	}
	void FindGreaterThanXIndex_ToOutMem(Ta Input, Ts X, Ta &Out)
	{
		
		if (Input.Length <= 0)
		{
			return;
		}
		return FindGreaterThanXIndex_ToOutMem(Input.GetArray(), Input.Length, X, Out.GetArray(),Out.Length);
	}
	Ta FindGreaterThanXIndex(Ta Input, Ts *X)
	{
		Ta res(this->MemManager);
		if (Input.Length <= 0)
		{
			return res;
		}
		return FindGreaterThanXIndex(Input.GetArray(), Input.Length, X);
	}

	void FindGreaterThanXIndex_inplace(Ts* A, int& Alength, Ts X)
	{
		int c = 0;
		for (int i = 0; i<Alength; i++)
		{
			if (A[i]>X)
			{
				A[c] = i;
				c++;
			}
		}
		Alength = c;
	}
	void FindGreaterThanXIndex_inplace(Ts* A, int& Alength, Ts *X)
	{
		int c = 0;
		for (int i = 0; i<Alength; i++)
		{
			if (A[i]>X[i])
			{
				A[c] = i;
				c++;
			}
		}
		Alength = c;
	}
	void FindGreaterThanXIndex_inplace(Ta &Input, Ts X)
	{
		return FindGreaterThanXIndex_inplace(Input.GetArray(), Input.Length, X);
	}
	void FindGreaterThanXIndex_inplace(Ta &Input, Ts *X)
	{
		return FindGreaterThanXIndex_inplace(Input.GetArray(), Input.Length, X);
	}

	Ta FindGreaterThanXIndex_real(Tc* A, int Alength, Ts X)
	{
		Ta res(this->MemManager);
		if (Alength <= 0)
			return res;
		Ts* tmp = this->AllocMem_Single(Alength);
		int c = 0;
		for (int i = 0; i<Alength; i++)
		{
			if (X < A[i].real)
			{
				tmp[c] = i;
				c++;
			}
		}
		if (c == 0)
		{
			this->FREEMEM((void**)&tmp);
		}

		res.SetArray(tmp, c);
		return res;
	}
	Ta FindGreaterThanXIndex_real(Tc* A, int Alength, Ts *X)
	{
		Ta res(this->MemManager);
		if (Alength <= 0)
			return res;
		Ts* tmp = this->AllocMem_Single(Alength);
		int c = 0;
		for (int i = 0; i<Alength; i++)
		{
			if (X[i]<A[i].real)
			{
				tmp[c] = i;
				c++;
			}
		}
		if (c == 0)
		{
			this->FREEMEM((void**)&tmp);
		}

		res.SetArray(tmp, c);
		return res;
	}
	Ta FindGreaterThanXIndex_real(Tca Input, Ts X)
	{
		Ta res(this->MemManager);
		if (Input.Length <= 0)
		{
			return res;
		}
		return FindGreaterThanXIndex_real(Input.GetArray(), Input.Length, X);
	}
	Ta FindGreaterThanXIndex_real(Tca Input, Ts *X)
	{
		Ta res(this->MemManager);
		if (Input.Length <= 0)
		{
			return res;
		}
		return FindGreaterThanXIndex_real(Input.GetArray(), Input.Length, X);
	}

	int FindGreaterXCount(Ts* A, int Alength, Ts* X)
	{
		if (Alength <= 0)
			return 0;
		int counter = 0;
		for (int i = 0; i<Alength; i++)
		{
			if (A[i] > X[i])
			{
				counter++;
			}
		}
		return counter;
	}
	int FindGreaterXCount(Ts* A, int Alength, Ts X)
	{
		if (Alength <= 0)
			return 0;
		int counter = 0;
		for (int i = 0; i<Alength; i++)
		{
			if (A[i] > X)
			{
				counter++;
			}
		}
		return counter;
	}

	int FindGreaterXCount_real(Tc* A, int Alength, Ts* X)
	{
		if (Alength <= 0)
			return 0;
		int counter = 0;
		for (int i = 0; i<Alength; i++)
		{
			if (X[i] < A[i].real)
			{
				counter++;
			}
		}
		return counter;
	}
	int FindGreaterXCount_real(Tc* A, int Alength, Ts X)
	{
		if (Alength <= 0)
			return 0;
		int counter = 0;
		for (int i = 0; i<Alength; i++)
		{
			if ( X<A[i].real )
			{
				counter++;
			}
		}
		return counter;
	}


	Ta FindLessThanXIndex(Ts* A, int Alength, Ts X)
	{
		Ta res(this->MemManager);
		if (Alength <= 0)
			return res;
		Ts* tmp = this->AllocMem_Single(Alength);
		int c = 0;
		for (int i = 0; i < Alength; i++)
		{
			if (A[i] < X)
			{
				tmp[c] = i;
				c++;
			}
		}
		if (c == 0)
		{
			this->FREEMEM((void**)&tmp);
			return res;
		}

		res.SetArray(tmp, c);
		return res;
	}
	Ta FindLessThanXIndex(Ts* A, int Alength, Ts *X)
	{
		Ta res(this->MemManager);
		if (Alength <= 0)
			return res;
		Ts* tmp = this->AllocMem_Single(Alength);
		int c = 0;
		for (int i = 0; i < Alength; i++)
		{
			if (A[i] < X[i])
			{
				tmp[c] = i;
				c++;
			}
		}
		if (c == 0)
		{
			this->FREEMEM((void**)&tmp);

			return res;
		}

		res.SetArray(tmp, c);
		return res;
	}
	Ta FindLessThanXIndex(Ta Input, Ts X)
	{
		Ta res(this->MemManager);
		if (Input.Length <= 0)
		{
			return res;
		}
		return FindLessThanXIndex(Input.GetArray(), Input.Length, X);
	}
	Ta FindLessThanXIndex(Ta Input, Ts *X)
	{
		Ta res(this->MemManager);
		if (Input.Length <= 0)
		{
			return res;
		}
		return FindLessThanXIndex(Input.GetArray(), Input.Length, X);
	}

	void FindLessThanXIndex_inplace(Ts* A, int& Alength, Ts X)
	{
		int c = 0;
		for (int i = 0; i<Alength; i++)
		{
			if (A[i]<X)
			{
				A[c] = i;
				c++;
			}
		}
		Alength = c;
	}
	void FindLessThanXIndex_inplace(Ts* A, int& Alength, Ts *X)
	{
		int c = 0;
		for (int i = 0; i<Alength; i++)
		{
			if (A[i]<X[i])
			{
				A[c] = i;
				c++;
			}
		}
		Alength = c;
	}
	void FindLessThanXIndex_inplace(Ta &Input, Ts X)
	{
		return FindLessThanXIndex_inplace(Input.GetArray(), Input.Length, X);
	}
	void FindLessThanXIndex_inplace(Ta &Input, Ts *X)
	{
		return FindLessThanXIndex_inplace(Input.GetArray(), Input.Length, X);
	}

	Ta FindLessThanXIndex_real(Tc* A, int Alength, Ts X)
	{
		Ta res(this->MemManager);
		if (Alength <= 0)
			return res;
		Ts* tmp = this->AllocMem_Single(Alength);
		int c = 0;
		for (int i = 0; i < Alength; i++)
		{
			if (X>A[i].real  )
			{
				tmp[c] = i;
				c++;
			}
		}
		if (c == 0)
		{
			this->FREEMEM((void**)&tmp);
			return res;
		}

		res.SetArray(tmp, c);
		return res;
	}
	Ta FindLessThanXIndex_real(Tc* A, int Alength, Ts *X)
	{
		Ta res(this->MemManager);
		if (Alength <= 0)
			return res;
		Ts* tmp = this->AllocMem_Single(Alength);
		int c = 0;
		for (int i = 0; i < Alength; i++)
		{
			if ( X[i] >A[i].real)
			{
				tmp[c] = i;
				c++;
			}
		}
		if (c == 0)
		{
			this->FREEMEM((void**)&tmp);

			return res;
		}

		res.SetArray(tmp, c);
		return res;
	}
	Ta FindLessThanXIndex_real(Tca Input, Ts X)
	{
		Ta res(this->MemManager);
		if (Input.Length <= 0)
		{
			return res;
		}
		return FindLessThanXIndex_real(Input.GetArray(), Input.Length, X);
	}
	Ta FindLessThanXIndex_real(Tca Input, Ts *X)
	{
		Ta res(this->MemManager);
		if (Input.Length <= 0)
		{
			return res;
		}
		return FindLessThanXIndex_real(Input.GetArray(), Input.Length, X);
	}


	Ta FindBetweenThanXYIndex(Ts* A, int Alength, Ts X, Ts Y)
	{
		Ta res(this->MemManager);
		if (Alength <= 0)
			return res;
		Ts* tmp = this->AllocMem_Single(Alength);
		int c = 0;
		for (int i = 0; i<Alength; i++)
		{
			if (A[i]>X && A[i] < Y)
			{
				tmp[c] = i;
				c++;
			}
		}
		if (c == 0)
		{
			this->FREEMEM((void**)&tmp);
			return res;
		}

		res.SetArray(tmp, c);
		return res;
	}
	Ta FindBetweenThanXYIndex(Ts* A, int Alength, Ts *X, Ts *Y)
	{
		Ta res(this->MemManager);
		if (Alength <= 0)
			return res;
		Ts* tmp = this->AllocMem_Single(Alength);
		int c = 0;
		for (int i = 0; i<Alength; i++)
		{
			if (A[i]>X[i] && A[i] < Y[i])
			{
				tmp[c] = i;
				c++;
			}
		}
		if (c == 0)
		{
			this->FREEMEM((void**)&tmp);
			return res;
		}

		res.SetArray(tmp, c);
		return res;
	}
	Ta FindBetweenThanXYIndex(Ta Input, Ts X, Ts Y)
	{
		Ta res(this->MemManager);
		if (Input.Length <= 0)
		{
			return res;
		}
		return FindBetweenThanXYIndex(Input.GetArray(), Input.Length, X, Y);
	}
	Ta FindBetweenThanXYIndex(Ta Input, Ts *X, Ts *Y)
	{
		Ta res(this->MemManager);
		if (Input.Length <= 0)
		{
			return res;
		}
		return FindBetweenThanXYIndex(Input.GetArray(), Input.Length, X, Y);
	}

	void FindBetweenThanXYIndex_inplace(Ts* A, int& Alength, Ts X)
	{
		int c = 0;
		for (int i = 0; i<Alength; i++)
		{
			if (A[i]==X)
			{
				A[c] = i;
				c++;
			}
		}
		Alength = c;
	}
	void FindBetweenThanXYIndex_inplace(Ts* A, int& Alength, Ts *X)
	{
		int c = 0;
		for (int i = 0; i<Alength; i++)
		{
			if (A[i]==X[i])
			{
				A[c] = i;
				c++;
			}
		}
		Alength = c;
	}
	void FindBetweenThanXYIndex_inplace(Ta &Input, Ts X)
	{
		return FindBetweenThanXYIndex_inplace(Input.GetArray(), Input.Length, X);
	}
	void FindBetweenThanXYIndex_inplace(Ta &Input, Ts *X)
	{
		return FindBetweenThanXYIndex_inplace(Input.GetArray(), Input.Length, X);
	}

	Ta FindBetweenThanXYIndex_real(Tc* A, int Alength, Ts X, Ts Y)
	{
		Ta res(this->MemManager);
		if (Alength <= 0)
			return res;
		Ts* tmp = this->AllocMem_Single(Alength);
		int c = 0;
		for (int i = 0; i<Alength; i++)
		{
			if (X< A[i].real&& Y > A[i].real)
			{
				tmp[c] = i;
				c++;
			}
		}
		if (c == 0)
		{
			this->FREEMEM((void**)&tmp);
			return res;
		}

		res.SetArray(tmp, c);
		return res;
	}
	Ta FindBetweenThanXYIndex_real(Tc* A, int Alength, Ts *X, Ts *Y)
	{
		Ta res(this->MemManager);
		if (Alength <= 0)
			return res;
		Ts* tmp = this->AllocMem_Single(Alength);
		int c = 0;
		for (int i = 0; i<Alength; i++)
		{
			if (X[i]<A[i].real &&  Y[i] >A[i].real)
			{
				tmp[c] = i;
				c++;
			}
		}
		if (c == 0)
		{
			this->FREEMEM((void**)&tmp);
			return res;
		}

		res.SetArray(tmp, c);
		return res;
	}
	Ta FindBetweenThanXYIndex_real(Tca Input, Ts X, Ts Y)
	{
		Ta res(this->MemManager);
		if (Input.Length <= 0)
		{
			return res;
		}
		return FindBetweenThanXYIndex_real(Input.GetArray(), Input.Length, X, Y);
	}
	Ta FindBetweenThanXYIndex_real(Tca Input, Ts *X, Ts *Y)
	{
		Ta res(this->MemManager);
		if (Input.Length <= 0)
		{
			return res;
		}
		return FindBetweenThanXYIndex_real(Input.GetArray(), Input.Length, X, Y);
	}


	int FindEquallXCount(Ts* A, int Alength, Ts* X)
	{
		if (Alength <= 0)
			return 0;
		int counter = 0;
		for (int i = 0; i < Alength; i++)
		{
			if (A[i] == X[i])
			{
				counter++;
			}
		}
		return counter;
	}
	int FindEquallXCount(Ts* A, int Alength, Ts X)
	{
		if (Alength <= 0)
			return 0;
		int counter = 0;
		for (int i = 0; i < Alength; i++)
		{
			if (A[i] == X)
			{
				counter++;
			}
		}
		return counter;
	}
	int FindEquallXCount(Ta A ,Ta X)
	{
		return FindEquallXCount(A.GetArray(), A.Length, X.GetArray());
	}
	int FindEquallXCount(Ta A, Ts X)
	{
		return FindEquallXCount(A.GetArray(), A.Length, X);
	}

	int FindEquallXCount_real(Tc* A, int Alength, Ts* X)
	{
		if (Alength <= 0)
			return 0;
		int counter = 0;
		for (int i = 0; i < Alength; i++)
		{
			if (A[i].real == X[i])
			{
				counter++;
			}
		}
		return counter;
	}
	int FindEquallXCount_real(Tc* A, int Alength, Ts X)
	{
		if (Alength <= 0)
			return 0;
		int counter = 0;
		for (int i = 0; i < Alength; i++)
		{
			if (A[i].real == X)
			{
				counter++;
			}
		}
		return counter;
	}
	int FindEquallXCount_real(Tca A, Ta X)
	{
		return FindEquallXCount_real(A.GetArray(), A.Length, X.GetArray());
	}
	int FindEquallXCount_real(Tca A, Ts X)
	{
		return FindEquallXCount_real(A.GetArray(), A.Length, X);
	}

	Ta FindEquallXIndex(Ts* A, int Alength, Ts X)
	{
		Ta res(this->MemManager);
		if (Alength <= 0)
			return res;
		Ts* tmp = this->AllocMem_Single(Alength);
		int c = 0;
		for (int i = 0; i < Alength; i++)
		{
			if (A[i] == X)
			{
				tmp[c] = i;
				c++;
			}
		}
		if (c == 0)
		{
			this->FREEMEM((void**)&tmp);
			return res;
		}
		res.SetArray(tmp, c);
		return res;
	}
	Ta FindEquallXIndex(Ts* A, int Alength, Ts *X)
	{
		Ta res(this->MemManager);
		if (Alength <= 0)
			return res;
		Ts* tmp = this->AllocMem_Single(Alength);
		int c = 0;
		for (int i = 0; i < Alength; i++)
		{
			if (A[i] == X[i])
			{
				tmp[c] = i;
				c++;
			}
		}
		if (c == 0)
		{
			this->FREEMEM((void**)&tmp);
			return res;
		}

		res.SetArray(tmp, c);
		return res;
	}
	Ta FindEquallXIndex(Ta Input, Ts X)
	{
		Ta res(this->MemManager);
		if (Input.Length <= 0)
		{
			return res;
		}
		return FindEquallXIndex(Input.GetArray(), Input.Length, X);
	}
	Ta FindEquallXIndex(Ta Input, Ts *X)
	{
		Ta res(this->MemManager);
		if (Input.Length <= 0)
		{
			return res;
		}
		return FindEquallXIndex(Input.GetArray(), Input.Length, X);
	}

	Ta FindEquallXIndex_real(Tc* A, int Alength, Ts X)
	{
		Ta res(this->MemManager);
		if (Alength <= 0)
			return res;
		Ts* tmp = this->AllocMem_Single(Alength);
		int c = 0;
		for (int i = 0; i < Alength; i++)
		{
			if (A[i].real == X)
			{
				tmp[c] = i;
				c++;
			}
		}
		if (c == 0)
		{
			this->FREEMEM((void**)&tmp);
			return res;
		}
		res.SetArray(tmp, c);
		return res;
	}
	Ta FindEquallXIndex_real(Tc* A, int Alength, Ts *X)
	{
		Ta res(this->MemManager);
		if (Alength <= 0)
			return res;
		Ts* tmp = this->AllocMem_Single(Alength);
		int c = 0;
		for (int i = 0; i < Alength; i++)
		{
			if (A[i].real == X[i])
			{
				tmp[c] = i;
				c++;
			}
		}
		if (c == 0)
		{
			this->FREEMEM((void**)&tmp);
			return res;
		}

		res.SetArray(tmp, c);
		return res;
	}
	Ta FindEquallXIndex_real(Tca Input, Ts X)
	{
		Ta res(this->MemManager);
		if (Input.Length <= 0)
		{
			return res;
		}
		return FindEquallXIndex_real(Input.GetArray(), Input.Length, X);
	}
	Ta FindEquallXIndex_real(Tca Input, Ts *X)
	{
		Ta res(this->MemManager);
		if (Input.Length <= 0)
		{
			return res;
		}
		return FindEquallXIndex_real(Input.GetArray(), Input.Length, X);
	}

};
#endif