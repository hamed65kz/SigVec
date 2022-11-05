#pragma once
#ifndef COMPLEXFFTSHIFTCLASS_H
#define COMPLEXFFTSHIFTCLASS_H
#include "ComplexCoreClass.h"

TemplateDefinition
class ComplexConjFFTshiftWrevClass : ComplexCoreClass <TemplateParameter>
{
public:
	ComplexConjFFTshiftWrevClass() 
	{
		// dont call base class default constructor directly, icc has problem with it.
		// default constructor of base class automatically called befor constructor of derived class.
		// but parametrized constructor of base class should be called explicitly.
	}
	ComplexConjFFTshiftWrevClass(MemoryManagerClass *MemoryManager) : BaseConstructor
	{

	}
	Tc Conj(Tc a)
	{
		Tc res;
		res.real = a.real;
		res.imag = a.imag*(-1);
		return res;
	}
	Tc* Conj(Tc* a, int aLength)
	{
		if (aLength == 0)
			return NULL;
		Tc* res = this->AllocMem_Complex(aLength);
		for (int i = 0; i < aLength; i++)
		{
			res[i] = Conj(a[i]);
		}
		return res;
	}
	Tca Conj(Tca Input)
	{
		Tca res = Tca(Conj(Input.GetArray(), Input.Length), Input.Length, false, this->MemManager);
		return res;
	}

	void Conj_inplace(Tc &a)
	{
		a.imag = a.imag*(-1);
	}
	void Conj_inplace(Tc* a, int aLength)
	{
		for (int i = 0; i < aLength; i++)
		{
			Conj_inplace(a[i]);
		}
	}
	void Conj_inplace(Tca Input)
	{
		Conj_inplace(Input.GetArray(), Input.Length);

	}

	Tc* FftShift(Tc *Signal, int Signal_Length)
	{
		if (Signal_Length == 0)
			return NULL;
		Tc* shift = this->AllocMem_Complex(Signal_Length);
		int start = Signal_Length / 2;
		int size = Signal_Length / 2;
		for (int i = 0; i<size; i++)
		{
			shift[i] = Signal[i + start];
			shift[i + start] = Signal[i];
		}
		//for(int i = 0;i<start;i++)
		//{
		//	shift[i+size] = Signal[i];
		//}
		//memcpy(shift, Signal+(start*(sizeof(Tc))), size*sizeof(Tc));
		//memcpy(shift+(size*sizeof(Tc)), Signal, (start)*sizeof(Tc));
		return shift;
	}
	Tca FftShift(Tca Input)
	{
		Tca res(this->MemManager);
		res.SetArray(FftShift(Input.GetArray(), Input.Length), Input.Length);
		res.Length = Input.Length;
		return res;
	}
	Ts* FftShift(Ts *Signal, int Signal_Length)
	{
		if (Signal_Length == 0)
			return NULL;
		Ts* shift = this->AllocMem_Single(Signal_Length);
		int start = Signal_Length / 2;
		int size = Signal_Length / 2;
		for (int i = 0; i<size; i++)
		{
			shift[i] = Signal[i + start];
			shift[i + start] = Signal[i];
		}
		/*for(int i = 0;i<start;i++)
		{
		shift[i+size] = Signal[i];
		}*/
		//memcpy(shift, Signal+(start*(sizeof(Tc))), size*sizeof(Tc));
		//memcpy(shift+(size*sizeof(Tc)), Signal, (start)*sizeof(Tc));
		return shift;
	}
	void FftShift_inplace(Ts *Signal, int Signal_Length)
	{
		if (Signal_Length == 0)
			return;
		//Ts* shift = AllocDouble(Signal_Length);
		int start = Signal_Length / 2;
		int size = Signal_Length / 2;
		for (int i = 0; i<size; i++)
		{
			Ts tmp = Signal[i];
			Signal[i] = Signal[i + start];
			Signal[i + start] = tmp;
		}
		/*for(int i = 0;i<start;i++)
		{
		shift[i+size] = Signal[i];
		}*/
		//memcpy(shift, Signal+(start*(sizeof(Tc))), size*sizeof(Tc));
		//memcpy(shift+(size*sizeof(Tc)), Signal, (start)*sizeof(Tc));
		//return shift;
	}
	void FftShift_inplace(Tc *Signal, int Signal_Length)
	{
		if (Signal_Length == 0)
			return;
		//Tc* shift  = AllocComplex64(Signal_Length);
		int start = Signal_Length / 2;
		int size = Signal_Length / 2;
		for (int i = 0; i<size; i++)
		{
			Tc tmp = Signal[i];
			Signal[i] = Signal[i + start];
			Signal[i + start] = tmp;
		}
		//for(int i = 0;i<start;i++)
		//{
		//	shift[i+size] = Signal[i];
		//}
		//memcpy(shift, Signal+(start*(sizeof(Tc))), size*sizeof(Tc));
		//memcpy(shift+(size*sizeof(Tc)), Signal, (start)*sizeof(Tc));
		//return shift;
	}
	void FftShift_inplace(Tca Signal)
	{
		FftShift_inplace(Signal.GetArray(), Signal.Length);
	}
	Ta FftShift(Ta Input)
	{
		Ta res(this->MemManager);
		res.SetArray(FftShift(Input.GetArray(), Input.Length), Input.Length);
		return res;
	}

	Tc* wrev(Tc *a, int length)
	{
		if (length == 0)
			return NULL;
		Tc *RX = this->AllocMem_Complex(length);
		for (int i = 0; i < length; i++)
		{
			RX[length - 1 - i].real = a[i].real;
			RX[length - 1 - i].imag = a[i].imag;
		}
		return RX;
	}
	Tca wrev(Tca Input)
	{
		Tca res(this->MemManager);
		res.SetArray(wrev(Input.GetArray(), Input.Length), Input.Length);
		return res;
	}
	Ts* wrev(Ts *a, int length)
	{
		if (length == 0)
			return NULL;
		Ts *RX = this->AllocMem_Single(length);
		for (int i = 0; i < length; i++)
		{
			RX[length - 1 - i] = a[i];

		}
		return RX;
	}
	Ta wrev(Ta Input)
	{
		Ta res(this->MemManager);
		res.SetArray(wrev(Input.GetArray(), Input.Length), Input.Length);
		return res;
	}
	void wrev_inplace(Ts *a, int length)
	{
		if (length == 0)
			return;
		Ts tmp = 0;
		for (int i = 0; i < length / 2; i++)
		{
			tmp = a[length - 1 - i];
			a[length - 1 - i] = a[i];
			a[i] = tmp;
		}

	}
	void wrev_inplace(Ta Input)
	{
		wrev_inplace(Input.GetArray(), Input.Length);

	}
	void wrev_inplace(Tc *a, int length)
	{
		if (length == 0)
			return;
		Tc tmp;
		for (int i = 0; i < length / 2; i++)
		{
			tmp = a[length - 1 - i];
			a[length - 1 - i] = a[i];
			a[i] = tmp;
		}

	}
	void wrev_inplace(Tca Input)
	{
		wrev_inplace(Input.GetArray(), Input.Length);

	}
};
#endif