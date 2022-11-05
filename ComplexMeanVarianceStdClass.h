#pragma once
#ifndef COMPLEXMVSCLASS_H
#define COMPLEXMVSCLASS_H
#include "ComplexAbsClass.h"

TemplateDefinition
class ComplexMeanVarianceStdClass : ComplexCoreClass <TemplateParameter>
{

public:
	ComplexMeanVarianceStdClass() 
	{
		// dont call base class default constructor directly, icc has problem with it.
		// default constructor of base class automatically called befor constructor of derived class.
		// but parametrized constructor of base class should be called explicitly.
	}
	ComplexMeanVarianceStdClass(MemoryManagerClass *MemoryManager) : BaseConstructor
	{

	}
	Ts mean(Ts* A, int arrayLength)
	{
		Ts_sum mean1 = 0;
		if (arrayLength <= 0)
		{
			return 0;
		}
#if Use_Ipp==1
		ippsMean_64f(A, arrayLength, &mean1);
		return mean1;
#else	
		for (int i = 0; i < arrayLength; i++)
		{
			mean1 += A[i];
		}
		mean1 = mean1 / arrayLength;

		return (Ts)mean1;
#endif
	}
	Ts mean(Ta Input)
	{
		return mean(Input.GetArray(), Input.Length);
	}
	Ts mean(Ta Input, int StartIndex, int EndIndex)
	{
		int size = EndIndex - StartIndex + 1;
#ifdef DebugBuild		
		if (StartIndex >= Input.Length || StartIndex < 0 || EndIndex >= Input.Length || EndIndex < 0 || EndIndex < StartIndex)
		{
			throw std::invalid_argument(" Invalid mean parameter");
		}
#endif
		return mean(&Input.GetArray()[StartIndex], size);
	}
	Ts meanOnIndex(Ta Input, Ta Index)
	{
		if (Index.Length <= 0)
		{
			return 0;
		}
		Ts_sum mean1 = 0;
		for (int i = 0; i < Index.Length; i++)
		{
			mean1 += Input[Index[i]];
		}
		mean1 = mean1 / Index.Length;
		return (Ts)mean1;
	}

	Tc mean(Tc* A, int arrayLength)
	{
		Tc_sum tmp;
		tmp.real = 0;
		tmp.imag = 0;
		Tc mean1;
		mean1.real = 0;
		mean1.imag = 0;
		if (arrayLength <= 0)
		{
			return mean1;
		}

		for (int i = 0; i < arrayLength; i++)
		{
			tmp.real = tmp.real + A[i].real;
			tmp.imag = tmp.imag + A[i].imag;
		}
		tmp = tmp / arrayLength;
		mean1.real = tmp.real;
		mean1.imag = tmp.imag;
		return mean1;

	}
	Tc mean(Tca Input)
	{
		return mean(Input.GetArray(), Input.Length);
	}
	Tc mean(Tca Input, int StartIndex, int EndIndex)
	{

#ifdef DebugBuild		
		if (StartIndex >= Input.Length || StartIndex < 0 || EndIndex >= Input.Length || EndIndex < 0 || EndIndex < StartIndex)
		{
			throw std::invalid_argument(" Invalid mean parameter");
		}
#endif

		int size = EndIndex - StartIndex + 1;
		return mean(&Input.GetArray()[StartIndex], size);

	}
	Tc meanOnIndex(Tca Input, Ta Index)
	{
		if (Index.Length <= 0)
		{
			return 0;
		}
		Tc_sum mean1;
		mean1.real = 0;
		mean1.imag = 0;
		for (int i = 0; i < Index.Length; i++)
		{
			mean1 = mean1 + Input[Index[i]];
		}
		mean1 = mean1 / Index.Length;

		Tc tmp;
		tmp.real = mean1.real;
		tmp.imag = mean1.imag;
		return tmp;
	}

	Ts Variance(Ts* A, int arrayLength)
	{
		Ts_sum var = 0;
		if (arrayLength <= 0)
		{
			return 0;
		}
		Ts Mean = mean(A, arrayLength);

		for (int i = 0; i < arrayLength; i++)
		{
			var += pow((A[i] - Mean), 2);
		}
		var = var / (arrayLength - 1);
		return var;
	}
	Ts Variance(Ta A)
	{
		return Variance(A.GetArray(), A.Length);
	}
	Ts Variance(Ta A, int StartIndex, int EndIndex)
	{

#ifdef DebugBuild		
		if (StartIndex >= A.Length || StartIndex < 0 || EndIndex >= A.Length || EndIndex < 0 || EndIndex < StartIndex)
		{
			throw std::invalid_argument(" invalid range selected");
		}
#endif
		int size = EndIndex - StartIndex + 1;
		return Variance(&A.GetArray()[StartIndex], size);

	}
	Ts VarianceOnIndex(Ta Input, Ta Index)
	{
		Ts_sum var = 0;
		if (Input.Length <= 0)
		{
			return 0;
		}
		Ts Mean = meanOnIndex(Input, Index);

		for (int i = 0; i < Index.Length; i++)
		{
			var += pow((Input[Index[i]] - Mean), 2);
		}
		var = var / (Index.Length - 1);
		return var;
	}

	Ts Variance(Tc* A, int arrayLength)
	{
		Ts_sum var = 0;
		if (arrayLength <= 0)
		{
			return var;
		}
		Tc Mean = mean(A, arrayLength);

		for (int i = 0; i < arrayLength; i++)
		{
			var = var + pow(Abs(A[i] - Mean), 2);
		}
		var = var / (arrayLength - 1);
		return var;
	}
	Ts Variance(Tca A)
	{
		return Variance(A.GetArray(), A.Length);
	}
	Ts Variance(Tca A, int StartIndex, int EndIndex)
	{

#ifdef DebugBuild		
		if (StartIndex >= A.Length || StartIndex < 0 || EndIndex >= A.Length || EndIndex < 0 || EndIndex < StartIndex)
		{
			throw std::invalid_argument(" invalid range selected");
		}
#endif

		int size = EndIndex - StartIndex + 1;
		return Variance(&A.GetArray()[StartIndex], size);
	}
	Ts VarianceOnIndex(Tca Input, Ta Index)
	{
		Ts_sum var = 0;
		if (Input.Length <= 0)
		{
			return var;
		}

		Tc Mean = meanOnIndex(Input, Index);

		for (int i = 0; i < Index.Length; i++)
		{
			var = var + pow(Abs(Input[Index[i]] - Mean), 2);
		}
		var = var / (Index.Length - 1);
		return var;
	}

	Ts Std(Ts* A, int arrayLength)
	{
		Ts var = Variance(A, arrayLength);
		Ts dev = sqrt(var);
		return dev;
	}
	Ts Std(Ta A)
	{
		return Std(A.GetArray(), A.Length);
	}
	Ts Std(Ta A, int StartIndex, int EndIndex)
	{

#ifdef DebugBuild		
		if (StartIndex >= A.Length || StartIndex < 0 || EndIndex >= A.Length || EndIndex < 0 || EndIndex < StartIndex)
		{
			throw std::invalid_argument(" invalid range selected");
		}
#endif

		int size = EndIndex - StartIndex + 1;
		return Std(&A.GetArray()[StartIndex], size);
	}
	Ts StdOnIndex(Ta A, Ta Index)
	{
		Ts var = VarianceOnIndex(A, Index);
		Ts dev = sqrt(var);
		return dev;
	}

	Ts Std(Tc* A, int arrayLength)
	{
		Ts var = Variance(A, arrayLength);
		Ts dev = sqrt(var);
		return dev;
	}
	Ts Std(Tca A)
	{
		return Std(A.GetArray(), A.Length);
	}
	Ts Std(Tca A, int StartIndex, int EndIndex)
	{

#ifdef DebugBuild		
		if (StartIndex >= A.Length || StartIndex < 0 || EndIndex >= A.Length || EndIndex < 0 || EndIndex < StartIndex)
		{
			throw std::invalid_argument(" invalid range selected");
		}
#endif
		int size = EndIndex - StartIndex + 1;
		return Std(&A.GetArray()[StartIndex], size);
	}
	Ts StdOnIndex(Tca A, Ta Index)
	{
		Ts var = VarianceOnIndex(A, Index);
		Ts dev = sqrt(var);
		return dev;
	}
};
#endif