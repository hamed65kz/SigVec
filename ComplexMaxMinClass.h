#pragma once
#ifndef COMPLEXMAXMINCLASS_H
#define COMPLEXMAXMINCLASS_H
#include "ComplexCoreClass.h"

TemplateDefinition
class ComplexMaxMinClass : ComplexCoreClass <TemplateParameter>
{

public:
	ComplexMaxMinClass() 
	{
		// dont call base class default constructor directly, icc has problem with it.
		// default constructor of base class automatically called befor constructor of derived class.
		// but parametrized constructor of base class should be called explicitly.
	}
	ComplexMaxMinClass(MemoryManagerClass *MemoryManager) : BaseConstructor
	{

	}
	Ts Max(Ts A, Ts B)
	{
		if (A >= B)
			return A;
		else
			return B;
	}
	Ts Max(Ts* a, int aLength, int &MaxIndex)
	{
		if (aLength <= 0)
		{
			return 0;
		}
#if Use_Ipp==1
		double maxvalue = 0;
		ippsMaxIndx_64f(a, aLength, &maxvalue, &MaxIndex);
		return maxvalue;
#else	
		MaxIndex = 0;
		for (int i = 0; i<aLength; i++)
		{
			if (a[i]>a[MaxIndex])
			{
				MaxIndex = i;
			}
		}
		return a[MaxIndex];
#endif
	}
	Ts Max(Ts* a, int aLength)
	{
		if (aLength <= 0)
		{
			return 0;
		}
#if Use_Ipp==1
		double maxvalue = 0;
		int maxIndex = 0;
		ippsMaxIndx_64f(a, aLength, &maxvalue, &maxIndex);
		return maxvalue;
#else	
		int MaxIndex = 0;
		for (int i = 0; i<aLength; i++)
		{
			if (a[i]>a[MaxIndex])
			{
				MaxIndex = i;
			}
		}
		return a[MaxIndex];
#endif
	}
	Ts Max(Ta Input, int &MaxIndex)
	{
		if (Input.Length <= 0)
		{
			return NULL;
		}
		return Max(Input.GetArray(), Input.Length, MaxIndex);
	}
	Ts Max(Ta Input)
	{
		if (Input.Length <= 0)
		{
			return NULL;
		}
		return Max(Input.GetArray(), Input.Length);
	}
	Ts MaxOnIndex(Ta Input, Ta Index)
	{
		if (Input.Length <= 0)
		{
			return NULL;
		}
		Ts Maxvalue = Input[0];
		int maxindex = 0;
		for (int i = 0; i < Index.Length; i++)
		{
			if (Input[i]>Maxvalue)
			{
				Maxvalue = Input[i];
				maxindex = i;
			}
		}
		return Maxvalue;
	}

	Tc Max(Tc* a, int aLength, int &MaxIndex)
	{
		if (aLength <= 0)
		{
			Tc b;
			b.real = 0;
			b.imag = 0;
			return b;
		}
		MaxIndex = 0;
		Ts Maxabs = Abs(a[0]);
		for (int i = 0; i<aLength; i++)
		{
			Ts absAi = Abs(a[i]);
			if (absAi>Maxabs)
			{
				MaxIndex = i;
				Maxabs = absAi;
			}
		}
		return a[MaxIndex];
	}
	Tc Max(Tc* a, int aLength)
	{
		if (aLength <= 0)
		{
			Tc b;
			b.real = 0;
			b.imag = 0;
			return b;
		}
		int MaxIndex = 0;
		Ts Maxabs = Abs(a[0]);
		for (int i = 0; i<aLength; i++)
		{
			Ts absAi = Abs(a[i]);
			if (absAi>Maxabs)
			{
				MaxIndex = i;
				Maxabs = absAi;
			}
		}
		return a[MaxIndex];
	}
	Tc Max(Tca Input, int &MaxIndex)
	{
		if (Input.Length <= 0)
		{
			Tc b;
			b.real = 0;
			b.imag = 0;
			return b;
		}
		return Max(Input.GetArray(), Input.Length, MaxIndex);
	}
	Tc Max(Tca Input)
	{
		if (Input.Length <= 0)
		{
			Tc b;
			b.real = 0;
			b.imag = 0;
			return b;
		}
		return Max(Input.GetArray(), Input.Length);
	}
	Tc MaxOnIndex(Tca Input, Ta Index)
	{
		if (Input.Length <= 0)
		{
			Tc b;
			b.real = 0;
			b.imag = 0;
			return b;
		}
		Ts Maxvalue = Abs(Input[0]);
		int maxindex = 0;
		for (int i = 0; i < Index.Length; i++)
		{
			Ts absAi = Abs(Input[i]);
			if (absAi>Maxvalue)
			{
				Maxvalue = absAi;
				maxindex = i;
			}
		}
		return Input[maxindex];
	}

	Ts Min(Ts A, Ts B)
	{
		if (A <= B)
			return A;
		else
			return B;
	}
	Ts Min(Ts* a, int aLength, int &MinIndex)
	{
		if (aLength <= 0)
		{
			return 0;
		}
		MinIndex = 0;
		for (int i = 0; i < aLength; i++)
		{
			if (a[i] < a[MinIndex])
			{
				MinIndex = i;
			}
		}
		return a[MinIndex];
	}
	Ts Min(Ts* a, int aLength)
	{
		if (aLength <= 0)
		{
			return 0;
		}
		int MinIndex = 0;
		for (int i = 0; i < aLength; i++)
		{
			if (a[i] < a[MinIndex])
			{
				MinIndex = i;
			}
		}
		return a[MinIndex];
	}
	Ts Min(Ta Input, int &MinIndex)
	{
		return Min(Input.GetArray(), Input.Length, MinIndex);
	}
	Ts Min(Ta Input)
	{
		return Min(Input.GetArray(), Input.Length);
	}
	Ts MinOnIndex(Ta Input, Ta Index)
	{
		if (Input.Length <= 0)
		{
			return NULL;
		}
		Ts Maxvalue = Input[0];
		int maxindex = 0;
		for (int i = 0; i < Index.Length; i++)
		{
			if (Input[i] < Maxvalue)
			{
				Maxvalue = Input[i];
				maxindex = i;
			}
		}
		return Maxvalue;
	}

	Tc Min(Tc* a, int aLength, int &MinIndex)
	{
		MinIndex = 0;
		Ts Minabs = Abs(a[0]);
		for (int i = 0; i < aLength; i++)
		{
			Ts absAi = Abs(a[i]);
			if (absAi < Minabs)
			{
				MinIndex = i;
				Minabs = absAi;
			}
		}
		return a[MinIndex];
	}
	Tc Min(Tc* a, int aLength)
	{
		int MinIndex = 0;
		Ts Minabs = Abs(a[0]);
		for (int i = 0; i<aLength; i++)
		{
			Ts absAi = Abs(a[i]);
			if (absAi>Minabs)
			{
				MinIndex = i;
				Minabs = absAi;
			}
		}
		return a[MinIndex];
	}
	Tc Min(Tca Input, int &MinIndex)
	{
		return Min(Input.GetArray(), Input.Length, MinIndex);
	}
	Tc Min(Tca Input)
	{
		return Min(Input.GetArray(), Input.Length);
	}
	Tc MinOnIndex(Tca Input, Ta Index)
	{
		if (Input.Length <= 0)
		{
			Tc b;
			b.real = 0;
			b.imag = 0;
			return b;
		}
		Ts Maxvalue = Abs(Input[0]);
		int maxindex = 0;
		for (int i = 0; i < Index.Length; i++)
		{
			Ts absAi = Abs(Input[i]);
			if (absAi < Maxvalue)
			{
				Maxvalue = absAi;
				maxindex = i;
			}
		}
		return Input[maxindex];
	}
};

#endif