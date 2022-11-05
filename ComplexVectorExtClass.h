#pragma once
#ifndef COMPLEXVECTOREXTCLASS_H
#define COMPLEXVECTOREXTCLASS_H
#include "ComplexCoreClass.h"

TemplateDefinition
class ComplexVectorExtClass : ComplexCoreClass <TemplateParameter>
{
public:
	ComplexVectorExtClass() 
	{
		// dont call base class default constructor directly, icc has problem with it.
		// default constructor of base class automatically called befor constructor of derived class.
		// but parametrized constructor of base class should be called explicitly.
	}
	ComplexVectorExtClass(MemoryManagerClass *MemoryManager) : BaseConstructor
	{

	}
	Ts* PaddingLeft(Ts* A, int ALength, int PaddingLength)
	{
		int resLength = ALength + PaddingLength;
		Ts* res = this->AllocMem_Single(resLength);

		memcpy(res + (PaddingLength*sizeof(Ts)), A, sizeof(Ts)*ALength);
		return res;
	}
	Ts* PaddingRight(Ts *A, int ALength, int PaddingLength)
	{
		int resLength = ALength + PaddingLength;
		Ts* res = this->AllocMem_Single(resLength);
		memcpy(res, A, sizeof(Ts)*ALength);
		return res;
	}
	Ts* PaddingLeft(Ta Input, int PaddingLength)
	{
		return PaddingLeft(Input.GetArray(), Input.Length, PaddingLength);
	}
	Ts* PaddingRight(Ta Input, int PaddingLength)
	{
		return PaddingRight(Input.GetArray(), Input.Length, PaddingLength);
	}
	Tc* PaddingLeft(Tc* A, int ALength, int PaddingLength)
	{
		int resLength = ALength + PaddingLength;
		Tc* res = this->AllocMem_Complex(resLength);
		memcpy(res + (PaddingLength*sizeof(Tc)), A, sizeof(Tc)*ALength);
		return res;
	}
	Tc* PaddingRight(Tc* A, int ALength, int PaddingLength)
	{
		int resLength = ALength + PaddingLength;
		Tc* res = this->AllocMem_Complex(resLength);
		memcpy(res, A, sizeof(Tc)*ALength);
		return res;
	}
	Tca PaddingLeft(Tca Input, int PaddingLength)
	{
		Tca res(this->MemManager);
		int resLength = Input.Length + PaddingLength;
		res.SetArray(PaddingLeft(Input.GetArray(), Input.Length, PaddingLength), resLength);
		return res;
	}
	Tca PaddingRight(Tca Input, int PaddingLength)
	{
		Tca res(this->MemManager);
		int resLength = Input.Length + PaddingLength;
		res.SetArray(PaddingRight(Input.GetArray(), Input.Length, PaddingLength), resLength);
		return res;
	}

	Tca GetSubArray(Tc *A, int StartIndex, int EndIndex, int Step)
	{

		Tca res(this->MemManager);
		int size = (EndIndex - StartIndex + 1) / Step;
		int mod = (EndIndex - StartIndex + 1) % Step;
		if (mod > 0)
		{
			size++;
		}

		if (size <= 0)
			return res;
		Tc* sub = this->AllocMem_Complex(size);
		int index = 0;
		for (int i = StartIndex; i <= EndIndex; i += Step)
		{
			sub[index] = A[i];
			index++;
		}
		res.SetArray(sub, size);
		return res;
	}
	Tca GetSubArray(Tca A, int StartIndex, int EndIndex, int Step)
	{

#ifdef DebugBuild		
		if (StartIndex >= A.Length || StartIndex < 0 || EndIndex >= A.Length || EndIndex < 0)
		{
			throw std::invalid_argument(" invalid range selected");
		}
#endif

		Tca res(this->MemManager);
		int size = (EndIndex - StartIndex + 1) / Step;
		int mod = (EndIndex - StartIndex + 1) % Step;
		if (mod>0)
		{
			size++;
		}
		if (size <= 0)
			return res;

		// res.Alloc(size);


		Tc* sub = this->AllocMem_Complex(size);

		for (int i = StartIndex; i <= EndIndex; i += Step)
		{
			int index = (i - StartIndex) / Step;
			sub[index] = A[i];
			//res[index] = A[i];
			//index++;
		}
		res.SetArray(sub, size);

		return res;
	}
	Ta GetSubArray(Ts *A, int StartIndex, int EndIndex, int Step)
	{
		Ta res(this->MemManager);
		int size = (EndIndex - StartIndex + 1) / Step;
		int mod = (EndIndex - StartIndex + 1) % Step;
		if (mod > 0)
		{
			size++;
		}
		if ((size <= 0) || (StartIndex < 0) || (EndIndex < 0) || (A == NULL))
		{
			return res;
		}

		Ts* sub = this->AllocMem_Single(size);
		int index = 0;
		for (int i = StartIndex; i <= EndIndex; i += Step)
		{
			sub[index] = A[i];
			index++;
		}
		res.SetArray(sub, size);
		return res;
	}
	Ta GetSubArray(Ta A, int StartIndex, int EndIndex, int Step)
	{

#ifdef DebugBuild		
		if (StartIndex >= A.Length || StartIndex < 0 || EndIndex >= A.Length || EndIndex < 0)
		{
			throw std::invalid_argument(" invalid range selected");
		}
#endif

		Ta res(this->MemManager);
		int size = (EndIndex - StartIndex + 1) / Step;
		int mod = (EndIndex - StartIndex + 1) % Step;
		if (mod>0)
		{
			size++;
		}
		if (size <= 0)
		{
			return res;
		}

		Ts* sub = this->AllocMem_Single(size);
		int index = 0;
		for (int i = StartIndex; i <= EndIndex; i += Step)
		{
			sub[index] = A[i];
			index++;
		}
		res.SetArray(sub, size);
		return res;
	}

	Ts* GetSubArray(Ts* A, Ts* Indexs, int IndexsLength)
	{
		if (IndexsLength == 0)
			return NULL;
		Ts* sub = this->AllocMem_Single(IndexsLength);
		for (int i = 0; i < IndexsLength; i++)
		{
			sub[i] = A[(int)Indexs[i]];
		}
		return sub;
	}
	Ta GetSubArray(Ta A, Ta Indexs)
	{
		Ts* sub = GetSubArray(A.GetArray(), Indexs.GetArray(), Indexs.Length);
		Ta res(this->MemManager);
		res.SetArray(sub, Indexs.Length);
		return res;
	}

	Tc* GetSubArray(Tc* A, Ts* Indexs, int IndexsLength)
	{
		if (IndexsLength == 0)
			return NULL;
		Tc* sub = this->AllocMem_Complex(IndexsLength);
		for (int i = 0; i < IndexsLength; i++)
		{
			sub[i] = A[(int)Indexs[i]];
		}
		return sub;
	}
	Tca GetSubArray(Tca A, Ta Indexs)
	{
		Tc* sub = GetSubArray(A.GetArray(), Indexs.GetArray(), Indexs.Length);
		Tca res(this->MemManager);
		res.SetArray(sub, Indexs.Length);
		return res;
	}

	Ta GetSubArray(Ts* A, int ALength, Ts* BinaryArray)
	{
		Ta res(this->MemManager);
		if (ALength == 0)
			return res;
		Ts* sub = this->AllocMem_Single(ALength);
		int c = 0;
		for (int i = 0; i<ALength; i++)
		{
			if (BinaryArray[i]>0)
			{
				sub[c] = A[i];
				c++;
			}
		}
		if (c == 0)
		{
			this->FREEMEM((void**)&sub);
		}

		res.SetArray(sub, c);
		return res;
	}
	Ta GetSubArray(Ta Input, Ts* BinaryArray)
	{
		return GetSubArray(Input.GetArray(), Input.Length, BinaryArray);
	}


	Ta2d GetSubArray(Ta2d A, int StartRowIndex, int EndRowIndex)
	{
		if (EndRowIndex < 0)
		{
			EndRowIndex += A.RowsCount;
		}
		if (StartRowIndex < 0)
		{
			StartRowIndex += A.RowsCount;
		}
		int rownumber = EndRowIndex - StartRowIndex + 1;
		Ta2d res = Ta2d(rownumber, this->MemManager);
		for (int i = StartRowIndex; i <= EndRowIndex; i++)
		{
			Ta r = GetRow(A, i);
			res.Rows[res.RowsCount] = r;
			res.RowsCount++;
		}
		return res;
	}
	Tca2d GetSubArray(Tca2d A, int StartRowIndex, int EndRowIndex)
	{
		if (EndRowIndex < 0)
		{
			EndRowIndex += A.RowsCount;
		}
		if (StartRowIndex < 0)
		{
			StartRowIndex += A.RowsCount;
		}
		int rownumber = EndRowIndex - StartRowIndex + 1;
		Tca2d res = Tca2d(rownumber, this->MemManager);
		for (int i = StartRowIndex; i <= EndRowIndex; i++)
		{
			Tca r = GetRow(A, i);
			res.Rows[res.RowsCount] = r;
			res.RowsCount++;
		}
		return res;
	}

	void GetSubArray_ToOutMem(Tc* A, int StartIndex, int EndIndex, Tc* Sub)
	{
		int size = EndIndex - StartIndex + 1;
		//	Tc* sub = (Tc*)malloc(size*sizeof(Tc));
		//memset(Sub, 0, size*sizeof(Tc));
		int index = 0;
		for (int i = StartIndex; i <= EndIndex; i++)
		{
			Sub[index] = A[i];
			index++;
		}
	}
	void GetSubArray_ToOutMem(Ts* A, int StartIndex, int EndIndex, Ts* Sub)
	{
		int size = EndIndex - StartIndex + 1;
		//Ts* sub = (Ts*)malloc(size*sizeof(Ts));
		//memset(Sub, 0, size*sizeof(Ts));
		int index = 0;
		for (int i = StartIndex; i <= EndIndex; i++)
		{
			Sub[index] = A[i];
			index++;
		}
	}

	void GetSubArraySx_ToOutMem(ComplexShort* A, int StartIndex, int EndIndex, Tc* Sub)
	{
		int size = EndIndex - StartIndex + 1;
		//	Tc* sub = (Tc*)malloc(size*sizeof(Tc));
		//memset(Sub, 0, size*sizeof(Tc));
		int index = 0;
		for (int i = StartIndex; i <= EndIndex; i++)
		{
			Sub[index].real = A[i].real;
			Sub[index].imag = A[i].imag;
			index++;
		}
	}
	void GetSubArraySx_ToOutMem(short* A, int StartIndex, int EndIndex, Ts* Sub)
	{
		int size = EndIndex - StartIndex + 1;
		//Ts* sub = (Ts*)malloc(size*sizeof(Ts));
		//memset(Sub, 0, size*sizeof(Ts));
		int index = 0;
		for (int i = StartIndex; i <= EndIndex; i++)
		{
			Sub[index].real = A[i].real;
			Sub[index].imag = A[i].imag;
			index++;
		}
	}


	Ts* AddXToLeftOfArray(Ts* A, int Alength, Ts X)
	{
		Ts* res = this->AllocMem_Single(Alength + 1);
		for (int i = 0; i < Alength; i++)
		{
			res[i + 1] = A[i];
		}
		res[0] = X;
		return res;
	}
	Ts* AddXToLeftOfArray(Ts* A, int Alength, Ts *X, int Xlength)
	{
		if (Alength + Xlength <= 0)
			return NULL;
		Ts* res = this->AllocMem_Single(Alength + Xlength);
		for (int i = 0; i < Alength; i++)
		{
			res[i + Xlength] = A[i];
		}
		for (int i = 0; i < Xlength; i++)
		{
			res[i] = X[i];
		}
		return res;
	}
	Ts* AddXToLeftOfArray(Ta Input, Ts X)
	{
		return  AddXToLeftOfArray(Input.GetArray(), Input.Length, X);
	}
	Ts* AddXToLeftOfArray(Ta Input, Ts *X, int Xlength)
	{
		return  AddXToLeftOfArray(Input.GetArray(), Input.Length, X, Xlength);
	}
	Tc* AddXToLeftOfArray(Tc* A, int Alength, Tc X)
	{

		Tc* res = this->AllocMem_Complex(Alength + 1);
		for (int i = 0; i < Alength; i++)
		{
			res[i + 1] = A[i];
		}
		res[0] = X;
		return res;
	}
	Tc* AddXToLeftOfArray(Tc* A, int Alength, Tc *X, int Xlength)
	{
		if (Alength + Xlength <= 0)
			return NULL;
		Tc* res = this->AllocMem_Complex(Alength + Xlength);
		for (int i = 0; i < Alength; i++)
		{
			res[i + Xlength] = A[i];
		}
		for (int i = 0; i < Xlength; i++)
		{
			res[i] = X[i];
		}
		return res;
	}
	Tc* AddXToLeftOfArray(Tca Input, Tc X)
	{
		return  AddXToLeftOfArray(Input.GetArray(), Input.Length, X);
	}
	Tc* AddXToLeftOfArray(Tca Input, Tc *X, int Xlength)
	{
		return  AddXToLeftOfArray(Input.GetArray(), Input.Length, X, Xlength);
	}


	Ts* AddXToRightOfArray(Ts* A, int Alength, Ts X)
	{

		Ts* res = this->AllocMem_Single(Alength + 1);
		for (int i = 0; i < Alength; i++)
		{
			res[i] = A[i];
		}
		res[Alength] = X;
		return res;
	}
	Ts* AddXToRightOfArray(Ts* A, int Alength, Ts *X, int Xlength)
	{
		if (Alength + Xlength <= 0)
			return NULL;
		Ts* res = this->AllocMem_Single(Alength + Xlength);
		for (int i = 0; i < Alength; i++)
		{
			res[i] = A[i];
		}
		for (int i = Alength; i < Alength + Xlength; i++)
		{
			res[i] = X[i - Alength];
		}
		return res;
	}
	Ts* AddXToRightOfArray(Ta Input, Ts X)
	{
		return  AddXToRightOfArray(Input.GetArray(), Input.Length, X);
	}
	Ts* AddXToRightOfArray(Ta Input, Ts *X, int Xlength)
	{
		return  AddXToRightOfArray(Input.GetArray(), Input.Length, X, Xlength);
	}
	Tc* AddXToRightOfArray(Tc* A, int Alength, Tc X)
	{
		Tc* res = this->AllocMem_Complex(Alength + 1);
		for (int i = 0; i < Alength; i++)
		{
			res[i] = A[i];
		}
		res[Alength] = X;
		return res;
	}
	Tc* AddXToRightOfArray(Tc* A, int Alength, Tc *X, int Xlength)
	{
		if (Alength + Xlength <= 0)
			return NULL;
		Tc* res = this->AllocMem_Complex(Alength + Xlength);
		for (int i = 0; i < Alength; i++)
		{
			res[i] = A[i];
		}
		for (int i = Alength; i < Alength + Xlength; i++)
		{
			res[i] = X[i - Alength];
		}
		return res;
	}
	Tc* AddXToRightOfArray(Tca Input, Tc X)
	{
		return  AddXToRightOfArray(Input.GetArray(), Input.Length, X);
	}
	Tc* AddXToRightOfArray(Tca Input, Tc *X, int Xlength)
	{
		return  AddXToRightOfArray(Input.GetArray(), Input.Length, X, Xlength);
	}

	void AddXToRightOfArray_inplace(Ts* A, int Alength, Ts X)
	{
		A[Alength] = X;
		Alength++;
	}
	void AddXToRightOfArray_inplace(Ts* A, int Alength, Ts *X, int Xlength)
	{
		for (int i = Alength; i < Alength + Xlength; i++)
		{
			A[i] = X[i - Alength];
		}
		Alength += Xlength;
	}
	void AddXToRightOfArray_inplace(Ta &Input, Ts X)
	{
		AddXToRightOfArray_inplace(Input.GetArray(), Input.Length, X);
		Input.Length++;

	}
	void AddXToRightOfArray_inplace(Ta &Input, Ts *X, int Xlength)
	{
		AddXToRightOfArray_inplace(Input.GetArray(), Input.Length, X, Xlength);
		Input.Length += Xlength;

	}

	void AddXToRightOfArray_inplace(Tc* A, int &Alength, Tc X)
	{
		A[Alength] = X;
		Alength++;
	}
	void AddXToRightOfArray_inplace(Tc* A, int &Alength, Tc *X, int Xlength)
	{
		for (int i = Alength; i < Alength + Xlength; i++)
		{
			A[i] = X[i - Alength];
		}
		Alength += Xlength;
	}
	void AddXToRightOfArray_inplace(Tca &Input, Tc X)
	{
		AddXToRightOfArray_inplace(Input.GetArray(), Input.Length, X);
		Input.Length++;

	}
	void AddXToRightOfArray_inplace(Tca &Input, Tc *X, int Xlength)
	{
		AddXToRightOfArray_inplace(Input.GetArray(), Input.Length, X, Xlength);
		Input.Length += Xlength;

	}

	Ts* GetReal(Tc *A, int ALength)
	{
		if (ALength == 0)
			return NULL;
		Ts* real = this->AllocMem_Single(ALength);
		for (int i = 0; i < ALength; i++)
		{
			real[i] = A[i].real;
		}
		return real;
	}
	Ts* GetImage(Tc *A, int ALength)
	{
		if (ALength == 0)
			return NULL;
		Ts* Image = this->AllocMem_Single(ALength);
		for (int i = 0; i < ALength; i++)
		{
			Image[i] = A[i].imag;
		}
		return Image;
	}
	Ta GetReal(Tca Input)
	{
		Ta res(this->MemManager);
		res.SetArray(GetReal(Input.GetArray(), Input.Length), Input.Length);
		res.Length = Input.Length;
		return res;
	}
	Ta GetImage(Tca Input)
	{
		Ta res(this->MemManager);

		res.SetArray(GetImage(Input.GetArray(), Input.Length), Input.Length);
		return res;
	}

	Ts* RemoveIndex(Ts* A, int Alen, int* SortedIndexes, int IndexesLen)
	{
		int reslen = Alen - IndexesLen;
		Ts* res = this->AllocMem_Single(reslen);
		int rescount = 0;
		int strtindx = 0;
		int endindx = 0;
		int copylen = 0;
		for (int i = 0; i < IndexesLen; i++)
		{
			endindx = SortedIndexes[i] - 1;
			copylen = endindx - strtindx + 1;
			if (copylen>0)
			{
				memcpy(&res[rescount], &A[strtindx], sizeof(Ts)*copylen);
				rescount += copylen;
			}

			strtindx = endindx + 2;
		}
		return res;
	}
	void RemoveIndex_inplace(Ts* A, int& Alen, int* SortedIndexes, int IndexesLen)
	{
		int rescount = 0;
		int strtindx = 0;
		int endindx = 0;
		int copylen = 0;
		for (int i = 0; i < IndexesLen; i++)
		{
			endindx = SortedIndexes[i] - 1;
			copylen = endindx - strtindx + 1;
			if (copylen>0)
			{
				memcpy(&A[rescount], &A[strtindx], sizeof(Ts)*copylen);
				rescount += copylen;
			}

			strtindx = endindx + 2;
		}
		int diff = Alen - rescount;
		memset(&A[rescount], 0, diff*sizeof(Ts));
		Alen = rescount;
	}
	Ta RemoveIndex(Ta A, int* SortedIndexes, int IndexesLen)
	{
		int reslen = A.Length - IndexesLen;
		Ta res(reslen, this->MemManager);
		int rescount = 0;
		int strtindx = 0;
		int endindx = 0;
		int copylen = 0;
		for (int i = 0; i < IndexesLen; i++)
		{
			endindx = SortedIndexes[i] - 1;
			copylen = endindx - strtindx + 1;
			if (copylen>0)
			{
				memcpy(&res.GetArray()[rescount], &A.GetArray()[strtindx], sizeof(Ts)*copylen);
				rescount += copylen;
			}
			strtindx = endindx + 2;
		}
		return res;
	}
	void RemoveIndex_inplace(Ta& A, int* SortedIndexes, int IndexesLen)
	{
		int rescount = 0;
		int strtindx = 0;
		int endindx = 0;
		int copylen = 0;
		for (int i = 0; i < IndexesLen; i++)
		{
			endindx = SortedIndexes[i] - 1;
			copylen = endindx - strtindx + 1;
			if (copylen>0)
			{
				memcpy(&A.GetArray()[rescount], &A.GetArray()[strtindx], sizeof(Ts)*copylen);
				rescount += copylen;
			}

			strtindx = endindx + 2;
		}
		int diff = A.Length - rescount;
		memset(&A.GetArray()[rescount], 0, diff*sizeof(Ts));
		A.Length = rescount;
	}
	Ts* RemoveIndex(Ts* A, int Alen, int StartIndex, int EndIndex, int RemoveStep)
	{
		Ts reslen = ceil((Ts)(EndIndex - StartIndex) / RemoveStep);
		if ((EndIndex - StartIndex) % RemoveStep == 0)
		{
			reslen++;
		}
		reslen = Alen - reslen;
		Ts* res = this->AllocMem_Single(reslen);
		int rescount = 0;
		int strtindx = StartIndex + 1;
		int endindx = 0;
		int copylen = StartIndex;
		if (EndIndex >= Alen)
		{
			EndIndex = Alen - 1;
		}
		memcpy(&res[rescount], &A[0], sizeof(Ts)*copylen);
		rescount += copylen;
		endindx = strtindx + RemoveStep - 2;
		while (endindx < EndIndex)
		{

			copylen = endindx - strtindx + 1;
			if (copylen>0)
			{
				memcpy(&res[rescount], &A[strtindx], sizeof(Ts)*copylen);
				rescount += copylen;
			}
			strtindx = endindx + 2;
			endindx = strtindx + RemoveStep - 2;
		}
		int l = Alen - strtindx;
		if (l > 0)
		{
			memcpy(&res[rescount], &A[strtindx], sizeof(Ts)*l);
			rescount += l;
		}
		return res;
	}
	void RemoveIndex_inplace(Ts* A, int &Alen, int StartIndex, int EndIndex, int RemoveStep)
	{

		int rescount = 0;
		int strtindx = StartIndex + 1;
		int endindx = 0;
		int copylen = StartIndex;
		if (EndIndex >= Alen)
		{
			EndIndex = Alen - 1;
		}
		rescount += copylen;
		endindx = strtindx + RemoveStep - 2;
		while (endindx < EndIndex)
		{
			copylen = endindx - strtindx + 1;
			if (copylen>0)
			{
				memcpy(&A[rescount], &A[strtindx], sizeof(Ts)*copylen);
				rescount += copylen;
			}
			strtindx = endindx + 2;
			endindx = strtindx + RemoveStep - 2;
		}
		int l = Alen - strtindx;
		if (l > 0)
		{
			memcpy(&A[rescount], &A[strtindx], sizeof(Ts)*l);
			rescount += l;
		}
		int diff = Alen - rescount;
		memset(&A[rescount], 0, sizeof(Ts)*diff);
		Alen = rescount;
	}
	Ta RemoveIndex(Ta A, int StartIndex, int EndIndex, int RemoveStep)
	{
		Ts reslen = ceil((Ts)(EndIndex - StartIndex) / RemoveStep);
		if ((EndIndex - StartIndex) % RemoveStep == 0)
		{
			reslen++;
		}
		reslen = A.Length - reslen;
		Ta res(reslen, this->MemManager);
		int rescount = 0;
		int strtindx = StartIndex + 1;
		int endindx = 0;
		int copylen = StartIndex;
		if (EndIndex >= A.Length)
		{
			EndIndex = A.Length - 1;
		}
		memcpy(&res.GetArray()[rescount], &A.GetArray()[0], sizeof(Ts)*copylen);
		rescount += copylen;
		endindx = strtindx + RemoveStep - 2;
		while (endindx < EndIndex)
		{

			copylen = endindx - strtindx + 1;
			if (copylen>0)
			{
				memcpy(&res.GetArray()[rescount], &A.GetArray()[strtindx], sizeof(Ts)*copylen);
				rescount += copylen;
			}
			strtindx = endindx + 2;
			endindx = strtindx + RemoveStep - 2;
		}
		int l = A.Length - strtindx;
		if (l > 0)
		{
			memcpy(&res.GetArray()[rescount], &A.GetArray()[strtindx], sizeof(Ts)*l);
			rescount += l;
		}
		return res;
	}
	void RemoveIndex_inplace(Ta &A, int StartIndex, int EndIndex, int RemoveStep)
	{

		int rescount = 0;
		int strtindx = StartIndex + 1;
		int endindx = 0;
		int copylen = StartIndex;
		if (EndIndex >= A.Length)
		{
			EndIndex = A.Length - 1;
		}
		rescount += copylen;
		endindx = strtindx + RemoveStep - 2;
		while (endindx < EndIndex)
		{
			copylen = endindx - strtindx + 1;
			if (copylen>0)
			{
				memcpy(&A.GetArray()[rescount], &A.GetArray()[strtindx], sizeof(Ts)*copylen);
				rescount += copylen;
			}
			strtindx = endindx + 2;
			endindx = strtindx + RemoveStep - 2;
		}
		int l = A.Length - strtindx;
		if (l > 0)
		{
			memcpy(&A.GetArray()[rescount], &A.GetArray()[strtindx], sizeof(Ts)*l);
			rescount += l;
		}
		int diff = A.Length - rescount;
		memset(&A.GetArray()[rescount], 0, sizeof(Ts)*diff);
		A.Length = rescount;
	}

	Tc* RemoveIndex(Tc* A, int Alen, int* SortedIndexes, int IndexesLen)
	{
		int reslen = Alen - IndexesLen;
		Tc* res = this->AllocMem_Complex(reslen);
		int rescount = 0;
		int strtindx = 0;
		int endindx = 0;
		int copylen = 0;
		for (int i = 0; i < IndexesLen; i++)
		{
			endindx = SortedIndexes[i] - 1;
			copylen = endindx - strtindx + 1;
			if (copylen>0)
			{
				memcpy(&res[rescount], &A[strtindx], sizeof(Tc)*copylen);
				rescount += copylen;
			}

			strtindx = endindx + 2;
		}
		return res;
	}
	void RemoveIndex_inplace(Tc* A, int& Alen, int* SortedIndexes, int IndexesLen)
	{
		int rescount = 0;
		int strtindx = 0;
		int endindx = 0;
		int copylen = 0;
		for (int i = 0; i < IndexesLen; i++)
		{
			endindx = SortedIndexes[i] - 1;
			copylen = endindx - strtindx + 1;
			if (copylen>0)
			{
				memcpy(&A[rescount], &A[strtindx], sizeof(Tc)*copylen);
				rescount += copylen;
			}

			strtindx = endindx + 2;
		}
		int diff = Alen - rescount;
		memset(&A[rescount], 0, diff*sizeof(Tc));
		Alen = rescount;
	}
	Tca RemoveIndex(Tca A, int* SortedIndexes, int IndexesLen)
	{
		int reslen = A.Length - IndexesLen;
		Tca res(reslen, this->MemManager);
		int rescount = 0;
		int strtindx = 0;
		int endindx = 0;
		int copylen = 0;
		for (int i = 0; i < IndexesLen; i++)
		{
			endindx = SortedIndexes[i] - 1;
			copylen = endindx - strtindx + 1;
			if (copylen>0)
			{
				memcpy(&res.GetArray()[rescount], &A.GetArray()[strtindx], sizeof(Tc)*copylen);
				rescount += copylen;
			}
			strtindx = endindx + 2;
		}
		return res;
	}
	void RemoveIndex_inplace(Tca& A, int* SortedIndexes, int IndexesLen)
	{
		int rescount = 0;
		int strtindx = 0;
		int endindx = 0;
		int copylen = 0;
		for (int i = 0; i < IndexesLen; i++)
		{
			endindx = SortedIndexes[i] - 1;
			copylen = endindx - strtindx + 1;
			if (copylen>0)
			{
				memcpy(&A.GetArray()[rescount], &A.GetArray()[strtindx], sizeof(Tc)*copylen);
				rescount += copylen;
			}

			strtindx = endindx + 2;
		}
		int diff = A.Length - rescount;
		memset(&A.GetArray()[rescount], 0, diff*sizeof(Tc));
		A.Length = rescount;
	}
	Tc* RemoveIndex(Tc* A, int Alen, int StartIndex, int EndIndex, int RemoveStep)
	{
		Ts reslen = ceil((Ts)(EndIndex - StartIndex) / RemoveStep);
		if ((EndIndex - StartIndex) % RemoveStep == 0)
		{
			reslen++;
		}
		reslen = Alen - reslen;
		Tc* res = this->AllocMem_Complex(reslen);
		int rescount = 0;
		int strtindx = StartIndex + 1;
		int endindx = 0;
		int copylen = StartIndex;
		if (EndIndex >= Alen)
		{
			EndIndex = Alen - 1;
		}
		memcpy(&res[rescount], &A[0], sizeof(Tc)*copylen);
		rescount += copylen;
		endindx = strtindx + RemoveStep - 2;
		while (endindx < EndIndex)
		{

			copylen = endindx - strtindx + 1;
			if (copylen>0)
			{
				memcpy(&res[rescount], &A[strtindx], sizeof(Tc)*copylen);
				rescount += copylen;
			}
			strtindx = endindx + 2;
			endindx = strtindx + RemoveStep - 2;
		}
		int l = Alen - strtindx;
		if (l > 0)
		{
			memcpy(&res[rescount], &A[strtindx], sizeof(Tc)*l);
			rescount += l;
		}
		return res;
	}
	void RemoveIndex_inplace(Tc* A, int &Alen, int StartIndex, int EndIndex, int RemoveStep)
	{

		int rescount = 0;
		int strtindx = StartIndex + 1;
		int endindx = 0;
		int copylen = StartIndex;
		if (EndIndex >= Alen)
		{
			EndIndex = Alen - 1;
		}
		rescount += copylen;
		endindx = strtindx + RemoveStep - 2;
		while (endindx < EndIndex)
		{
			copylen = endindx - strtindx + 1;
			if (copylen>0)
			{
				memcpy(&A[rescount], &A[strtindx], sizeof(Tc)*copylen);
				rescount += copylen;
			}
			strtindx = endindx + 2;
			endindx = strtindx + RemoveStep - 2;
		}
		int l = Alen - strtindx;
		if (l > 0)
		{
			memcpy(&A[rescount], &A[strtindx], sizeof(Tc)*l);
			rescount += l;
		}
		int diff = Alen - rescount;
		memset(&A[rescount], 0, sizeof(Tc)*diff);
		Alen = rescount;
	}
	Tca RemoveIndex(Tca A, int StartIndex, int EndIndex, int RemoveStep)
	{
		Ts reslen = ceil((Ts)(EndIndex - StartIndex) / RemoveStep);
		if ((EndIndex - StartIndex) % RemoveStep == 0)
		{
			reslen++;
		}
		reslen = A.Length - reslen;
		Tca res(reslen, this->MemManager);
		int rescount = 0;
		int strtindx = StartIndex + 1;
		int endindx = 0;
		int copylen = StartIndex;
		if (EndIndex >= A.Length)
		{
			EndIndex = A.Length - 1;
		}
		memcpy(&res.GetArray()[rescount], &A.GetArray()[0], sizeof(Tc)*copylen);
		rescount += copylen;
		endindx = strtindx + RemoveStep - 2;
		while (endindx < EndIndex)
		{

			copylen = endindx - strtindx + 1;
			if (copylen>0)
			{
				memcpy(&res.GetArray()[rescount], &A.GetArray()[strtindx], sizeof(Tc)*copylen);
				rescount += copylen;
			}
			strtindx = endindx + 2;
			endindx = strtindx + RemoveStep - 2;
		}
		int l = A.Length - strtindx;
		if (l > 0)
		{
			memcpy(&res.GetArray()[rescount], &A.GetArray()[strtindx], sizeof(Tc)*l);
			rescount += l;
		}
		return res;
	}
	void RemoveIndex_inplace(Tca &A, int StartIndex, int EndIndex, int RemoveStep)
	{

		int rescount = 0;
		int strtindx = StartIndex + 1;
		int endindx = 0;
		int copylen = StartIndex;
		if (EndIndex >= A.Length)
		{
			EndIndex = A.Length - 1;
		}
		rescount += copylen;
		endindx = strtindx + RemoveStep - 2;
		while (endindx < EndIndex)
		{
			copylen = endindx - strtindx + 1;
			if (copylen>0)
			{
				memcpy(&A.GetArray()[rescount], &A.GetArray()[strtindx], sizeof(Tc)*copylen);
				rescount += copylen;
			}
			strtindx = endindx + 2;
			endindx = strtindx + RemoveStep - 2;
		}
		int l = A.Length - strtindx;
		if (l > 0)
		{
			memcpy(&A.GetArray()[rescount], &A.GetArray()[strtindx], sizeof(Tc)*l);
			rescount += l;
		}
		int diff = A.Length - rescount;
		memset(&A.GetArray()[rescount], 0, sizeof(Tc)*diff);
		A.Length = rescount;
	}
};
#endif