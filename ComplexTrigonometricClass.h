#pragma once
#ifndef COMPLEXTRIGONOMETRICCLASS_H
#define COMPLEXTRIGONOMETRICCLASS_H

#include "ComplexCoreClass.h"
TemplateDefinition
class ComplexTrigonometricClass :  ComplexCoreClass <TemplateParameter>
{

public:
	ComplexTrigonometricClass() 
	{
		// dont call base class default constructor directly, icc has problem with it.
		// default constructor of base class automatically called befor constructor of derived class.
		// but parametrized constructor of base class should be called explicitly.
	}
	ComplexTrigonometricClass(MemoryManagerClass *MemoryManager) : BaseConstructor
	{

	}
	Ts* Sin(Ts* A, int ALength)
	{
		if (ALength <= 0)
		{
			return NULL;
		}
		Ts* res = this->AllocMem_Single(ALength);
		for (int i = 0; i < ALength; i++)
		{
			res[i] = sin(A[i]);
		}
		return res;
	}
	Ta Sin(Ta Input)
	{
		Ta res(this->MemManager);
		if (Input.Length <= 0)
			return res;
		res.SetArray(Sin(Input.GetArray(), Input.Length), Input.Length);
		res.Length = Input.Length;
		return res;
	}
	void Sin_inplace(Ts* A, int ALength)
	{
		if (ALength <= 0)
		{
			return;
		}
		for (int i = 0; i < ALength; i++)
		{
			A[i] = sin(A[i]);
		}
	}
	void Sin_inplace(Ta Input)
	{
		if (Input.Length <= 0)
		{
			return;
		}
		Sin_inplace(Input.GetArray(), Input.Length);

	}

	Ts* Cos(Ts* A, int ALength)
	{
		if (ALength <= 0)
		{
			return 0;
		}
		Ts* res = this->AllocMem_Single(ALength);
		for (int i = 0; i < ALength; i++)
		{
			res[i] = cos(A[i]);
		}
		return res;
	}
	Ta Cos(Ta Input)
	{
		Ta res(this->MemManager);
		if (Input.Length <= 0)
		{
			return res;
		}
		res.SetArray(Cos(Input.GetArray(), Input.Length), Input.Length);
		return res;
	}
	void Cos_inplace(Ts* A, int ALength)
	{
		if (ALength <= 0)
		{
			return;
		}
		for (int i = 0; i < ALength; i++)
		{
			A[i] = cos(A[i]);
		}
	}
	void Cos_inplace(Ta Input)
	{
		if (Input.Length <= 0)
		{
			return;
		}
		Cos_inplace(Input.GetArray(), Input.Length);

	}

	Ts Angle(Tc X)
	{
		return  atan2(X.imag, X.real);
		/*double bdiva = X.imag/X.real;
		double theta = atan(bdiva);
		return theta;*/
	}
	Ts* Angle(Tc* X, int arrayLength)
	{
		if (arrayLength == 0)
			return NULL;
		Ts* Angleres = this->AllocMem_Single(arrayLength);
		for (int i = 0; i<arrayLength; i++)
		{
			//double bdiva = X[i].imag / X[i].real;
			//Angle[i] = atan(bdiva);
			Angleres[i] = Angle(X[i]);
		}
		return Angleres;
	}
	Ta Angle(Tca Input)
	{
		Ta res(this->MemManager);
		res.SetArray(Angle(Input.GetArray(), Input.Length), Input.Length);
		return res;
	}

	Ts deg2rad(Ts A)
	{
		//Ts pi = 3.141592653589793;
		return  (this->pi / 180.0) * A;
	}
	Ts* deg2rad(Ts *A, int ALength)
	{
		if (ALength == 0)
			return NULL;
		Ts* res = this->AllocMem_Single(ALength);
		for (int i = 0; i < ALength; i++)
		{
			res[i] = deg2rad(A[i]);
		}
		return res;
	}
	Ta deg2rad(Ta Input)
	{
		Ta res(this->MemManager);
		res.SetArray(deg2rad(Input.GetArray(), Input.Length), Input.Length);
		return res;
	}
	void deg2rad_inplace(Ts *A, int ALength)
	{
		for (int i = 0; i < ALength; i++)
		{
			A[i] = deg2rad(A[i]);
		}
	}
	void deg2rad_inplace(Ta Input)
	{
		deg2rad_inplace(Input.GetArray(), Input.Length);

	}

	Tc ComplexEXP(Tc Value)
	{
		Tc res;
		Ts temp = exp(Value.real);
		res.real = cos(Value.imag)*temp;
		res.imag = sin(Value.imag)*temp;
		return res;
	}
	Tc ComplexEXPValueRealIsZero(Tc Value)
	{
		Tc res;
		res.real = cos(Value.imag);
		res.imag = sin(Value.imag);
		return res;
	}
	Tc ComplexEXPValueRealIsOne(Tc Value)
	{
		Tc res;
		Ts temp = 2.7182818284590451;
		res.real = cos(Value.imag)*temp;
		res.imag = sin(Value.imag)*temp;
		return res;
	}
	Tc ComplexEXPValueImageIsZero(Tc Value)
	{
		Tc res;
		Ts temp = exp(Value.real);
		res.real = temp;
		res.imag = 0;
		return res;
	}
	Tc* ComplexEXP(Tc* Values, int Length)
	{
		if (Length == 0)
			return NULL;
		Tc* res = this->AllocMem_Complex(Length);
		for (int i = 0; i < Length; i++)
		{
			res[i] = ComplexEXP(Values[i]);
		}
		return res;
	}
	Tc* ComplexEXPOptimized(Tc* Values, int Length)
	{
		if (Length == 0)
			return NULL;
		Tc* res = this->AllocMem_Complex(Length);
		if (Values[0].real == 0)
		{
			for (int i = 0; i < Length; i++)
			{
				res[i] = ComplexEXPValueRealIsZero(Values[i]);
			}
		}
		else if (Values[0].real == 1)
		{
			for (int i = 0; i < Length; i++)
			{
				res[i] = ComplexEXPValueRealIsOne(Values[i]);
			}
		}
		else if (Values[0].imag == 0)
		{
			for (int i = 0; i < Length; i++)
			{
				res[i] = ComplexEXPValueImageIsZero(Values[i]);
			}
		}
		else
		{
			for (int i = 0; i < Length; i++)
			{
				res[i] = ComplexEXP(Values[i]);
			}
		}
		return res;
	}
	Tc* ComplexEXP(Tca Input)
	{
		return ComplexEXP(Input.GetArray(), Input.Length);
	}
	Tc ComplexEXP(double re, double img)
	{
		Tc tmp;
		tmp.real = re;
		tmp.imag = img;
		return ComplexEXP(tmp);
	}
	void ComplexEXP_inplace(Tc* A, int Length)
	{
		for (int i = 0; i < Length; i++)
		{
			A[i] = ComplexEXP(A[i]);
		}
	}
	void ComplexEXP_inplace(Tca Input)
	{
		ComplexEXP_inplace(Input.GetArray(), Input.Length);

	}
	void ComplexEXPOptimized_inplace(Tc* Values, int Length)
	{
		if (Length == 0)
			return;

		if (Values[0].real == 0)
		{
			for (int i = 0; i < Length; i++)
			{
				Values[i] = ComplexEXPValueRealIsZero(Values[i]);
			}
		}
		else if (Values[0].real == 1)
		{
			for (int i = 0; i < Length; i++)
			{
				Values[i] = ComplexEXPValueRealIsOne(Values[i]);
			}
		}
		else if (Values[0].imag == 0)
		{
			for (int i = 0; i < Length; i++)
			{
				Values[i] = ComplexEXPValueImageIsZero(Values[i]);
			}
		}
		else
		{
			for (int i = 0; i < Length; i++)
			{
				Values[i] = ComplexEXP(Values[i]);
			}
		}
	}

	Tc Pow(Tc X, int Y)
	{
		Ts r = this->Abs(X);
		Ts bdiva = 0;
		if (X.real != 0)
		{
			bdiva = X.imag / X.real;
		}
		Ts theta = atan(bdiva);
		Tc jthetan;
		jthetan.real = 0;
		jthetan.imag = theta*Y;
		Tc expJtheta = ComplexEXP(jthetan);
		Tc res;
		Ts rPy = pow(r, Y);
		res.real = rPy*expJtheta.real;
		res.imag = rPy*expJtheta.imag;
		return res;
	}
	Tc* Pow(Tc *X, int ArrayLength, int Y)
	{
		if (ArrayLength == 0)
			return NULL;
		Tc* pows = this->AllocMem_Complex(ArrayLength);
		for (int i = 0; i < ArrayLength; i++)
		{
			Ts r = this->Abs(X[i]);
			Ts bdiva = 0;
			if (X[i].real != 0)
			{
				bdiva = X[i].imag / X[i].real;
			}
			Ts theta = atan(bdiva);
			Tc jthetan;
			jthetan.real = 0;
			jthetan.imag = theta*Y;
			Tc expJtheta = ComplexEXP(jthetan);
			Tc res;
			Ts rPy = pow(r, Y);
			pows[i].real = rPy*expJtheta.real;
			pows[i].imag = rPy*expJtheta.imag;
		}
		return pows;

	}
	Tca Pow(Tca Input, int Y)
	{
		Tca res(this->MemManager);
		res.SetArray(Pow(Input.GetArray(), Input.Length, Y), Input.Length);
		return res;
	}
	Ts* Pow(Ts* X, int ArrayLength, int Y)
	{
		if (ArrayLength == 0)
			return NULL;
		Ts* Res = this->AllocMem_Single(ArrayLength);
		for (int i = 0; i < ArrayLength; i++)
		{
			Res[i] = pow(X[i], Y);
		}
		return Res;
	}
	Ta Pow(Ta Input, int Y)
	{

		Ta res(this->MemManager);
		res.SetArray(Pow(Input.GetArray(), Input.Length, Y), Input.Length);
		return res;
	}
	void Pow_inplace(Tc *X, int ArrayLength, int Y)
	{
		for (int i = 0; i < ArrayLength; i++)
		{
			Ts r = this->Abs(X[i]);
			Ts bdiva = 0;
			if (X[i].real != 0)
			{
				bdiva = X[i].imag / X[i].real;
			}
			Ts theta = atan(bdiva);
			Tc jthetan;
			jthetan.real = 0;
			jthetan.imag = theta*Y;
			Tc expJtheta = ComplexEXP(jthetan);
			Tc res;
			Ts rPy = pow(r, Y);
			X[i].real = rPy*expJtheta.real;
			X[i].imag = rPy*expJtheta.imag;
		}
	}
	void Pow_inplace(Tca Input, int Y)
	{
		Pow_inplace(Input.GetArray(), Input.Length, Y);

	}
	void Pow_inplace(Ts *X, int ArrayLength, int Y)
	{
		for (int i = 0; i < ArrayLength; i++)
		{
			X[i] = pow(X[i], Y);
		}
	}
	void Pow_inplace(Ta Input, int Y)
	{
		Pow_inplace(Input.GetArray(), Input.Length, Y);

	}

	Ts PowReal(Tc X, int Y)
	{
		Ts p = pow(X.real, Y);
		return p;
	}
	Ts* PowReal(Tc *X, int ArrayLength, int Y)
	{
		if (ArrayLength == 0)
			return NULL;
		Ts* pows = this->AllocMem_Single(ArrayLength);
		for (int i = 0; i < ArrayLength; i++)
		{
			pows[i] = PowReal(X[i]);
		}
		return pows;

	}
	Ta PowReal(Tca Input, int Y)
	{
		Ta res(this->MemManager);
		res.SetArray(PowReal(Input.GetArray(), Input.Length, Y), Input.Length);
		return res;
	}
	void PowReal_inplace(Tc *X, int ArrayLength, int Y)
	{
		for (int i = 0; i < ArrayLength; i++)
		{
			X[i].real = PowReal(X[i],Y);
		}


	}
	void PowReal_inplace(Tca Input, int Y)
	{
		PowReal_inplace(Input.GetArray(), Input.Length, Y);
	}

	Ts PowImage(Tc X, int Y)
	{
		Ts p = pow(X.imag, Y);
		return p;
	}
	Ts* PowImage(Tc *X, int ArrayLength, int Y)
	{
		if (ArrayLength == 0)
			return NULL;
		Ts* pows = this->AllocMem_Single(ArrayLength);
		for (int i = 0; i < ArrayLength; i++)
		{
			pows[i] = PowImage(X[i]);
		}
		return pows;

	}
	Ta PowImage(Tca Input, int Y)
	{
		Ta res(this->MemManager);
		res.SetArray(PowImage(Input.GetArray(), Input.Length, Y), Input.Length);
		return res;
	}
	void PowImage_inplace(Tc *X, int ArrayLength, int Y)
	{
		for (int i = 0; i < ArrayLength; i++)
		{
			X[i].imag = PowImage(X[i],Y);
		}
	}
	void PowImage_inplace(Tca Input, int Y)
	{
		PowImage_inplace(Input.GetArray(), Input.Length, Y);
	}

};

#endif