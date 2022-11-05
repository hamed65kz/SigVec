//#pragma once
#ifndef ComplexAbsClass_h
#define ComplexAbsClass_h

#include "ComplexCoreClass.h"

TemplateDefinition
class ComplexAbsClass : public  ComplexCoreClass <TemplateParameter>
{
public:
		
	Ts Abs(Tc data)
	{
		return ComplexCoreClass<TemplateParameter>::Abs(data);
	}
	ComplexAbsClass(void) 
	{
		// dont call base class default constructor directly, icc has problem with it.
		// default constructor of base class automatically called befor constructor of derived class.
		// but parametrized constructor of base class should be called explicitly.
	}
	ComplexAbsClass(MemoryManagerClass *MemoryManager) : BaseConstructor// initialize base. do not use () for calling base class constructor because of new version of c++ limits.
	{
	
	}
	~ComplexAbsClass()
	{
		//destructors are called automatically in the reverse order of construction.(base classes last). Do not call base class destructors
	}
	Ts Abs(Ts A)
	{	
		return std::abs(A);
	}
	Ts* Abs(Tc* A, int arrayLength)
	{
		if (arrayLength <= 0)
			return NULL;
		Ts* abs = this->AllocMem_Single(arrayLength);

		for (int i = 0; i < arrayLength; i++)
		{
			abs[i] = Abs(A[i]);
		}
		return abs;
	}
	Ts* Abs(Ts* A, int arrayLength)
	{
		if (arrayLength <= 0)
			return NULL;
		Ts* abs = this->AllocMem_Single(arrayLength);
		for (int i = 0; i < arrayLength; i++)
		{
			abs[i] = std::abs(A[i]);
		}
		return abs;
	}

	Ta Abs(Tca Input)
	{
		Ta res(this->MemManager);
		if (Input.Length <= 0)
		{
			return res;
		}
		res.SetArray(Abs(Input.GetArray(), Input.Length), Input.Length);
		return res;
	}
	Ta Abs(Ta Input)
	{
		Ta res(this->MemManager);
		if (Input.Length <= 0)
		{
			return res;
		}
		res.SetArray(Abs(Input.GetArray(), Input.Length), Input.Length);
		return res;
	}

	void Abs_inplace(Tc* A, int arrayLength)
	{
		if (arrayLength <= 0)
			return;
		for (int i = 0; i < arrayLength; i++)
		{
			A[i].real = Abs(A[i]);
			A[i].imag = 0;
		}
	}	
	void Abs_inplace(Ts* A, int arrayLength)
	{
		if (arrayLength <= 0)
			return;
#if Use_Ipp==1
		ippsAbs_64f_I(A, arrayLength);
#else
		for (int i = 0; i < arrayLength; i++)
		{
			A[i] = std::abs(A[i]);
		}
#endif
	}

	void Abs_inplace(Tca Input)
	{
		if (Input.Length <= 0)
		{
			return;
		}
		Abs_inplace(Input.GetArray(), Input.Length);

	}
	void Abs_inplace(Ta Input)
	{
		if (Input.Length <= 0)
		{
			return;
		}
		Abs_inplace(Input.GetArray(), Input.Length);
	}
	
	void Abs_ToOutMem(Tc* A, int arrayLength, Ts* out, AssignmentOperator Aop=AssignmentOperator::Assignment)
	{
		if (arrayLength <= 0)
			return;		
		
		if (Aop==AssignmentOperator::Assignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				out[i] = Abs(A[i]);
			}
		}
		else if (Aop == AssignmentOperator::AdditionAssignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				out[i] += Abs(A[i]);
			}
		}
		else if (Aop == AssignmentOperator::SubtractionAssignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				out[i] -= Abs(A[i]);
			}
		}
		else if (Aop == AssignmentOperator::MultiplicationAssignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				out[i] *= Abs(A[i]);
			}
		}
		else if (Aop == AssignmentOperator::divisionAssignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				out[i] /= Abs(A[i]);
			}
		}
	}
	void Abs_ToOutMem(Tca A, Ta out, AssignmentOperator Aop = AssignmentOperator::Assignment)
	{
		Abs_ToOutMem(A.GetArray(), A.Length, out.GetArray(), Aop);
	}


	void Abs_ToOutMem(Ts* A, int arrayLength, Ts* out, AssignmentOperator Aop = AssignmentOperator::Assignment)
	{
		if (arrayLength <= 0)
			return;

		if (Aop == AssignmentOperator::Assignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				out[i] = Abs(A[i]);
			}
		}
		else if (Aop == AssignmentOperator::AdditionAssignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				out[i] += Abs(A[i]);
			}
		}
		else if (Aop == AssignmentOperator::SubtractionAssignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				out[i] -= Abs(A[i]);
			}
		}
		else if (Aop == AssignmentOperator::MultiplicationAssignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				out[i] *= Abs(A[i]);
			}
		}
		else if (Aop == AssignmentOperator::divisionAssignment)
		{
			for (int i = 0; i < arrayLength; i++)
			{
				out[i] /= Abs(A[i]);
			}
		}
	}
	void Abs_ToOutMem(Ta A, Ta out, AssignmentOperator Aop = AssignmentOperator::Assignment)
	{
		Abs_ToOutMem(A.GetArray(), A.Length, out.GetArray(), Aop);
	}

	void Abs_ToOutMem(Ts* A_real, Ts * A_imag, int arrayLength, Ts* out)
	{
		if (arrayLength <= 0)
			return;
		for (int i = 0; i < arrayLength; i++)
		{
			out[i] = sqrtf(A_real[i] * A_real[i] + A_imag[i] * A_imag[i]);
		}
	}
	void Abs_ToOutMem(Ta A_real, Ta A_imag, int arrayLength, Ta out)
	{
		if (arrayLength <= 0)
			return;
		for (int i = 0; i < arrayLength; i++)
		{
			out[i] = sqrtf(A_real[i] * A_real[i] + A_imag[i] * A_imag[i]);
		}
	}

	Ts AbsPow(Tc data, int Y)
	{
		Ts abs = sqrt(data.real * data.real + data.imag * data.imag);
		return pow(abs, Y);
	}
	Ts AbsPow2(Tc data)
	{
		Ts absp =(data.real * data.real + data.imag * data.imag);
		return absp;
	}
	Ts* AbsPow(Tc* A, int arrayLength, int Y)
	{
		if (arrayLength <= 0)
			return NULL;
		Ts* abs = this->AllocMem_Single(arrayLength);

		for (int i = 0; i < arrayLength; i++)
		{
			abs[i] = AbsPow(A[i], Y);
		}
		return abs;
	}	
	Ts* AbsPow2(Tc* A, int arrayLength)
	{
		if (arrayLength <= 0)
			return NULL;
		Ts* abs = this->AllocMem_Single(arrayLength);

		for (int i = 0; i < arrayLength; i++)
		{
			abs[i] = AbsPow2(A[i]);
		}
		return abs;
	}
	Ts* AbsPow(Ts* A, int arrayLength, int Y)
	{
		if (arrayLength <= 0)
			return NULL;
		Ts* abs1 = this->AllocMem_Single(arrayLength);
		for (int i = 0; i < arrayLength; i++)
		{
			abs1[i] = pow(std::abs(A[i]), Y);
		}
		return abs1;
	}

	Ta AbsPow(Tca Input, int Y)
	{
		Ta res(this->MemManager);
		if (Input.Length <= 0)
		{
			return res;
		}
		res.SetArray(AbsPow(Input.GetArray(), Input.Length, Y), Input.Length);
		return res;
	}
	Ta AbsPow2(Tca Input)
	{
		Ta res(this->MemManager);
		if (Input.Length <= 0)
		{
			return res;
		}
		res.SetArray(AbsPow2(Input.GetArray(), Input.Length), Input.Length);
		return res;
	}
	Ta AbsPow(Ta Input, int Y)
	{
		Ta res(this->MemManager);
		if (Input.Length <= 0)
		{
			return res;
		}
		res.SetArray(AbsPow(Input.GetArray(), Input.Length, Y), Input.Length);
		return res;
	}

	void AbsPow_ToOutMem(Tc* A, int arrayLength, int Y, Ts* out)
	{
		if (arrayLength <= 0)
			return ;

		for (int i = 0; i < arrayLength; i++)
		{
			out[i] = AbsPow(A[i], Y);
		}

	}
	void AbsPow2_ToOutMem(Tc* A, int arrayLength, Ts* out)
	{
		if (arrayLength <= 0)
			return;

		for (int i = 0; i < arrayLength; i++)
		{
			out[i] = AbsPow2(A[i]);
		}

	}
	Ts AbsPow2Sum(Tc* A, int arrayLength)
	{
		if (arrayLength <= 0)
			return 0;
		Ts sum = 0;
		for (int i = 0; i < arrayLength; i++)
		{
			sum += AbsPow2(A[i]);
		}
		return sum;
	}
	void AbsPow_ToOutMem(Ts* A, int arrayLength, int Y, Ts* out)
	{
		if (arrayLength <= 0)
			return ;

		for (int i = 0; i < arrayLength; i++)
		{
			out[i] = pow(std::abs(A[i]), Y);
		}

	}

	void AbsPow_ToOutMem(Tca Input, int Y,Ts* out)
	{
	
		if (Input.Length <= 0)
		{
			return ;
		}
		AbsPow_ToOutMem(Input.GetArray(),Input.Length, Y, out);
	}
	void AbsPow2_ToOutMem(Tca Input, Ts* out)
	{
		if (Input.Length <= 0)
		{
			return;
		}
		AbsPow2_ToOutMem(Input.GetArray(), Input.Length, out);
	}
	Ts AbsPow2Sum(Tca Input)
	{
		if (Input.Length <= 0)
		{
			return 0;
		}
		return AbsPow2Sum(Input.GetArray(), Input.Length);
	}
	void AbsPow_ToOutMem(Ta Input, int Y, Ts* out)
	{
		if (Input.Length <= 0)
		{
			return ;
		}
		AbsPow_ToOutMem(Input.GetArray(), Input.Length, Y, out);
	}

	Ts* AbsReal(Tc* A, int arrayLength)
	{
		if (arrayLength <= 0)
			return NULL;
		Ts* abs1 = this->AllocMem_Single(arrayLength);
		for (int i = 0; i < arrayLength; i++)
		{
			abs1[i] = std::abs(A[i].real);
		}
		return abs1;
	}
	Ta AbsReal(Tca A)
	{
		Ta res(this->MemManager);
		if (A.Length <= 0)
		{
			return res;
		}
		Ts* abs = AbsReal(A.GetArray(), A.Length);
		res.SetArray(abs, A.Length);
		return res;
	}

	Ts* AbsImage(Tc* A, int arrayLength)
	{
		if (arrayLength <= 0)
			return NULL;
		Ts* abs1 = this->AllocMem_Single(arrayLength);
		for (int i = 0; i < arrayLength; i++)
		{
			abs1[i] = std::abs(A[i].imag);
		}
		return abs1;
	}
	Ta AbsImage(Tca A)
	{
		Ta res(this->MemManager);
		if (A.Length <= 0)
		{
			return res;
		}
		Ts* abs = AbsImage(A.GetArray(), A.Length);
		res.SetArray(abs, A.Length);
		return res;
	}

	Ts MaxAbsReal(Tca A, int &MaxIndex)
	{
		if (A.Length < 1)
		{
			return 0;
		}
		Ts Max = A[0].real;
		MaxIndex = 0;
		Ts AbsMax = Abs(Max);
		for (int i = 1; i < A.Length; i++)
		{
			Ts abs_value = abs(A[i].real);
			if (Max < abs_value)
			{
				Max = A[i].real;
				MaxIndex = i;
				AbsMax = abs_value;
			}
		}
		return AbsMax;
	}
	Ts MaxAbsImage(Tca A, int &MaxIndex)
	{
		if (A.Length < 1)
		{
			return 0;
		}
		Ts Max = A[0].imag;
		MaxIndex = 0;
		Ts AbsMax = Abs(Max);
		for (int i = 1; i < A.Length; i++)
		{
			Ts abs_value = abs(A[i].imag);
			if (Max <abs_value)
			{
				Max = A[i].imag;
				MaxIndex = i;
				AbsMax = abs_value;
			}
		}
		return AbsMax;
	}
	Ts MinAbsReal(Tca A, int& MinIndex)
	{
		if (A.Length < 1)
		{
			return 0;
		}
		Ts Min = A[0].real;
		MinIndex = 0;
		Ts AbsMin = Abs(Min);
		for (int i = 1; i < A.Length; i++)
		{
			Ts abs_value = abs(A[i].real);
			if (Min>abs_value)
			{
				Min = A[i].real;
				MinIndex = i;
				AbsMin = abs_value;
			}
		}
		return AbsMin;
	}
	Ts MinAbsImage(Tca A, int &MinIndex)
	{
		if (A.Length < 1)
		{
			return 0;
		}
		Ts Min = A[0].imag;
		MinIndex = 0;

		Ts AbsMin = Abs(Min);

		for (int i = 1; i < A.Length; i++)
		{
			Ts abs_value = abs(A[i].imag);
			if (Min>abs_value)
			{
				Min = A[i].imag;
				MinIndex = i;
				AbsMin = abs_value;
			}
		}
		return AbsMin;
	}

	Ts MaxAbs(Ts* A, int ALen, int &MaxIndex)
	{
		if (ALen < 1)
		{
			return 0;
		}
		Ts Max = A[0];
		MaxIndex = 0;
		Ts AbsMax = Abs(Max);
		for (int i = 1; i < ALen; i++)
		{
			Ts abs_value = Abs(A[i]);
			if (Max < abs_value)
			{
				Max = A[i];
				MaxIndex = i;
				AbsMax = abs_value;
			}
		}
		return Max;
	}
	Ts MaxAbs(Ta A, int &MaxIndex)
	{
		return MaxAbs(A.GetArray(), A.Length, MaxIndex);
	}
	Ts MinAbs(Ts* A, int ALen, int &MinIndex)
	{
		if (ALen < 1)
		{
			return 0;
		}
		Ts Min = A[0];
		MinIndex = 0;
		Ts AbsMin = Abs(Min);
		for (int i = 1; i < ALen; i++)
		{
			Ts abs_value = Abs(A[i]);
			if (Min>abs_value)
			{
				Min = A[i];
				MinIndex = i;
				AbsMin = abs_value;
			}
		}
		return Min;
	}
	Ts MinAbs(Ta A, int &MinIndex)
	{
		return MinAbs(A.GetArray(), A.Length, MinIndex);
	}

	Ts MaxAbs(Tc* A, int ALen, int &MaxIndex)
	{		
		if (ALen < 1)
		{
			return 0;
		}
		Tc Max= A[0];
		MaxIndex = 0;
		Ts AbsMax = Abs(Max);
		for (int i = 1; i < ALen; i++)
		{
			Ts abs_value = Abs(A[i]);
			if (AbsMax < abs_value)
			{
				Max = A[i];
				MaxIndex = i;
				AbsMax = abs_value;
			}
		}
		return AbsMax;
	}
	Ts MaxAbs(Tca A, int &MaxIndex)
	{
		return MaxAbs(A.GetArray(), A.Length, MaxIndex);
	}
	Ts MinAbs(Tc* A, int ALen, int &MinIndex)
	{
		if (ALen < 1)
		{
			return 0;
		}
		Tc Min = A[0];
		MinIndex = 0;
		Ts AbsMin = Abs(Min);
		for (int i = 1; i < ALen; i++)
		{
			Ts abs_value = Abs(A[i]);
			if (AbsMin>abs_value)
			{
				Min = A[i];
				MinIndex = i;
				AbsMin = abs_value;
			}
		}
		return AbsMin;
	}
	Ts MinAbs(Tca A, int &MinIndex)
	{
		return MinAbs(A.GetArray(), A.Length, MinIndex);
	}

	Ts* AbsReal_Sum_AbsImage(Tc* A, int Alen)
	{
		Ts* Sum = this->AllocMem_Single(Alen); 
		for (int i = 0; i < Alen; i++)
		{
			Sum[i] = abs(A[i].real) + abs(A[i].imag);
		}
		return Sum;
	}
	Ta AbsReal_Sum_AbsImage(Tca A)
	{
		Ta res = Ta(this->MemManager);
		res.SetArray(AbsReal_Sum_AbsImage(A.GetArray(), A.Length), A.Length);
		return res;
	}
};
#endif

