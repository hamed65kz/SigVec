#pragma once
#ifndef COMPLEXDUSAMPLECLASS_H
#define COMPLEXDUSAMPLECLASS_H
#include "ComplexCoreClass.h"

TemplateDefinition
class ComplexDownUpSampleClass : ComplexCoreClass <TemplateParameter>
{
public:
	ComplexDownUpSampleClass() 
	{
		// dont call base class default constructor directly, icc has problem with it.
		// default constructor of base class automatically called befor constructor of derived class.
		// but parametrized constructor of base class should be called explicitly.
	}
	ComplexDownUpSampleClass(MemoryManagerClass *MemoryManager) : BaseConstructor
	{

	}
	Tc* Upsample(Tc* samples, int Samples_length, int Upsample_Rate)
	{
		if (Samples_length == 0)
			return NULL;
		Tc* Upsample_data = this->AllocMem_Complex(Samples_length*Upsample_Rate);
		for (int i = 0; i < Samples_length; i++)
		{
			Upsample_data[i * Upsample_Rate].real = samples[i].real;
			Upsample_data[i * Upsample_Rate].imag = samples[i].imag;
		}
		return Upsample_data;
	}
	Ts* Upsample(Ts* samples, int Samples_length, int Upsample_Rate)
	{
		if (Samples_length == 0)
			return NULL;
		Ts* Upsample_data = this->AllocMem_Single(Samples_length*Upsample_Rate);
		for (int i = 0; i < Samples_length; i++)
		{
			Upsample_data[i * Upsample_Rate] = samples[i];
		}
		return Upsample_data;
	}
	Ta Upsample(Ta Input, int Upsample_Rate)
	{
		Ta res(this->MemManager);
		res.SetArray(upsample(Input.GetArray(), Input.Length, Upsample_Rate), Input.Length * Upsample_Rate);
		return res;
	}
	Tca Upsample(Tca Input, int Upsample_Rate)
	{
		Tca res(this->MemManager);
		res.SetArray(upsample(Input.GetArray(), Input.Length, Upsample_Rate), Input.Length * Upsample_Rate);
		return res;
	}
	void Upsample_ToOutMem(Tc* samples, int Samples_length, int Upsample_Rate, Tc* UpsampledSamples)
	{
		if (Samples_length == 0)
			return;
		//Tc* Upsample_data  = AllocComplex64(Samples_length*Upsample_Rate);
		for (int i = 0; i < Samples_length; i++)
		{
			UpsampledSamples[i * Upsample_Rate].real = samples[i].real;
			UpsampledSamples[i * Upsample_Rate].imag = samples[i].imag;
		}
	}

	Tca Downsample(Tc* samples, int Samples_length, int Downsample_Rate)
	{

		Tca res(this->MemManager);
		int size = Samples_length / Downsample_Rate;
		int mod = Samples_length%Downsample_Rate;
		if (mod > 0)
		{
			size++;
		}
		if (size == 0)
		{
			return res;
		}
		Tc* Upsample_data = this->AllocMem_Complex(size);

		for (int i = 0; i < Samples_length; i += Downsample_Rate)
		{
			Upsample_data[i / Downsample_Rate].real = samples[i].real;
			Upsample_data[i / Downsample_Rate].imag = samples[i].imag;
		}
		res.SetArray(Upsample_data, size);
		return res;
	}	
	Tca Downsample(Tca Input, int Downsample_Rate)
	{
		return Downsample(Input.GetArray(), Input.Length, Downsample_Rate);
	}
	Tca Downsample(Tc *samples, int Downsample_Rate, int StartIndex, int EndIndex)
	{
		Tca res(this->MemManager);
		int size = (EndIndex - StartIndex + 1) / Downsample_Rate;
		int mod = (EndIndex - StartIndex + 1) % Downsample_Rate;
		if (mod > 0)
		{
			size++;
		}
		if (size == 0)
		{
			return res;
		}
		Tc* Upsample_data = this->AllocMem_Complex(size);
		int x = 0;
		for (int i = StartIndex; i <= EndIndex; i += Downsample_Rate)
		{
			Upsample_data[x].real = samples[i].real;
			Upsample_data[x].imag = samples[i].imag;
			x++;
		}
		res.SetArray(Upsample_data, size);
		return res;
	}

	Ta Downsample_real(Tc* samples, int Samples_length, int Downsample_Rate)
	{
		Ta res(this->MemManager);
		int size = Samples_length / Downsample_Rate;
		int mod = Samples_length%Downsample_Rate;
		if (mod > 0)
		{
			size++;
		}
		if (size == 0)
		{
			return res;
		}
		Ts* Upsample_data = this->AllocMem_Single(size);

		for (int i = 0; i < Samples_length; i += Downsample_Rate)
		{
			Upsample_data[i / Downsample_Rate] = samples[i].real;
		}
		res.SetArray(Upsample_data, size);
		return res;
	}
	Ta Downsample_real(Tca Input, int Downsample_Rate)
	{
		return Downsample_real(Input.GetArray(), Input.Length, Downsample_Rate);
	}
	Ta Downsample_real(Tc *samples, int Downsample_Rate, int StartIndex, int EndIndex)
	{
		Ta res(this->MemManager);
		int size = (EndIndex - StartIndex + 1) / Downsample_Rate;
		int mod = (EndIndex - StartIndex + 1) % Downsample_Rate;
		if (mod > 0)
		{
			size++;
		}
		if (size == 0)
		{
			return res;
		}
		Ts* Upsample_data = this->AllocMem_Single(size);
		int x = 0;
		for (int i = StartIndex; i <= EndIndex; i += Downsample_Rate)
		{
			Upsample_data[x] = samples[i].real;
			x++;
		}
		res.SetArray(Upsample_data, size);
		return res;
	}

	Ta Downsample_imag(Tc* samples, int Samples_length, int Downsample_Rate)
	{
		Ta res(this->MemManager);
		int size = Samples_length / Downsample_Rate;
		int mod = Samples_length%Downsample_Rate;
		if (mod > 0)
		{
			size++;
		}
		if (size == 0)
		{
			return res;
		}
		Ts* Upsample_data = this->AllocMem_Single(size);

		for (int i = 0; i < Samples_length; i += Downsample_Rate)
		{
			Upsample_data[i / Downsample_Rate] = samples[i].imag;
		}
		res.SetArray(Upsample_data, size);
		return res;
	}
	Ta Downsample_imag(Tca Input, int Downsample_Rate)
	{
		return Downsample_imag(Input.GetArray(), Input.Length, Downsample_Rate);
	}
	Ta Downsample_imag(Tc *samples, int Downsample_Rate, int StartIndex, int EndIndex)
	{
		Ta res(this->MemManager);
		int size = (EndIndex - StartIndex + 1) / Downsample_Rate;
		int mod = (EndIndex - StartIndex + 1) % Downsample_Rate;
		if (mod > 0)
		{
			size++;
		}
		if (size == 0)
		{
			return res;
		}
		Ts* Upsample_data = this->AllocMem_Single(size);
		int x = 0;
		for (int i = StartIndex; i <= EndIndex; i += Downsample_Rate)
		{
			Upsample_data[x] = samples[i].imag;
			x++;
		}
		res.SetArray(Upsample_data, size);
		return res;
	}

	int Downsample_ToOutMem(Tc* samples, int Samples_length, int Downsample_Rate, Tc* DownSampledOutput)
	{


		int size = Samples_length / Downsample_Rate;
		int mod = Samples_length%Downsample_Rate;
		if (mod > 0)
		{
			size++;
		}
		if (size == 0)
		{
			return size;
		}

		
		for (int i = 0; i < Samples_length; i += Downsample_Rate)
		{
			
			DownSampledOutput[i / Downsample_Rate].real = samples[i].real;
			DownSampledOutput[i / Downsample_Rate].imag = samples[i].imag;
		}
		return size;
	}
	int Downsample_ToOutMem(Tc *samples, int Downsample_Rate, int StartIndex, int EndIndex, Tc* DownsampledOutput)
	{
		int size = (EndIndex - StartIndex + 1) / Downsample_Rate;
		int mod = (EndIndex - StartIndex + 1) % Downsample_Rate;
		if (mod > 0)
		{
			size++;
		}
		if (size == 0)
		{
			return size;
		}
		int x = 0;
		for (int i = StartIndex; i <= EndIndex; i += Downsample_Rate)
		{
			DownsampledOutput[x].real = samples[i].real;
			DownsampledOutput[x].imag = samples[i].imag;
			x++;
		}
		return size;
	}

	Ta Downsample(Ts* samples, int Samples_length, int Downsample_Rate)
	{
		Ta res(this->MemManager);
		int size = Samples_length / Downsample_Rate;
		int mod = Samples_length%Downsample_Rate;
		if (mod > 0)
		{
			size++;
		}
		if (size == 0)
		{
			return res;
		}
		Ts* Upsample_data = this->AllocMem_Single(size);
	
		for (int i = 0; i < Samples_length; i += Downsample_Rate)
		{
			
			Upsample_data[i / Downsample_Rate] = samples[i];
		}
		res.SetArray(Upsample_data, size);
		return res;
	}
	Ta Downsample(Ta Input, int Downsample_Rate)
	{
		return Downsample(Input.GetArray(), Input.Length, Downsample_Rate);
	}
	Ta Downsample(Ts *samples, int Downsample_Rate, int StartIndex, int EndIndex)
	{
		Ta res(this->MemManager);
		int size = (EndIndex - StartIndex + 1) / Downsample_Rate;
		int mod = (EndIndex - StartIndex + 1) % Downsample_Rate;
		if (mod > 0)
		{
			size++;
		}
		if (size == 0)
		{
			return res;
		}
		Ts* Upsample_data = this->AllocMem_Single(size);
		int x = 0;
		for (int i = StartIndex; i <= EndIndex; i += Downsample_Rate)
		{
			Upsample_data[x] = samples[i];

			x++;
		}
		res.SetArray(Upsample_data, size);
		return res;
	}
	Ta Downsample(Ta samples, int Downsample_Rate, int StartIndex, int EndIndex)
	{
		if (EndIndex < 0)
		{
			EndIndex += samples.Length;
		}
		if (StartIndex<0)
		{
			StartIndex += samples.Length;
		}
		int size = (EndIndex - StartIndex + 1) / Downsample_Rate;
		int mod = (EndIndex - StartIndex + 1) % Downsample_Rate;
		if (mod>0)
		{
			size++;
		}
		Ta res(this->MemManager);
		if (size == 0)
		{
			return res;
		}

		Ts* Upsample_data = this->AllocMem_Single(size);
		//#if Use_Ipp==1
		//	int phase=1;
		//	ippsSampleDown_64f(&samples.GetArray()[StartIndex],EndIndex-StartIndex+1,Upsample_data,&size,Downsample_Rate,&phase);
		//#else
		int x = 0;
		for (int i = StartIndex; i <= EndIndex; i += Downsample_Rate)
		{
			Upsample_data[x] = samples[i];

			x++;
		}
		//#endif
		res.SetArray(Upsample_data, size);
		return res;
	}

	int Downsample_inplace(Ts* samples, int Samples_length, int Downsample_Rate)
	{
		int x = 0;
		for (int i = 0; i < Samples_length; i += Downsample_Rate)
		{
			samples[x] = samples[i];
			x++;
		}
		return x;
	}
	int Downsample_inplace(Ta &Input, int Downsample_Rate)
	{
		int l = Downsample_inplace(Input.GetArray(), Input.Length, Downsample_Rate);
		Input.Length = l;

		return l;
	}
	int Downsample_inplace(Ts* samples, int Downsample_Rate, int StartIndex, int EndIndex)
	{
		int x = 0;
		for (int i = StartIndex; i <= EndIndex; i += Downsample_Rate)
		{
			samples[x] = samples[i];
			x++;
		}
		return x;

	}

	int Downsample_inplace(Tc* samples, int Samples_length, int Downsample_Rate)
	{
		int x = 0;
		for (int i = 0; i < Samples_length; i += Downsample_Rate)
		{
			samples[x].real = samples[i].real;
			samples[x].imag = samples[i].imag;
			x++;
		}
		return x;
	}
	int Downsample_inplace(Tca &Input, int Downsample_Rate)
	{
		int l = Downsample_inplace(Input.GetArray(), Input.Length, Downsample_Rate);
		Input.Length = l;

		return l;
	}
	int Downsample_inplace(Tc* samples, int Downsample_Rate, int StartIndex, int EndIndex)
	{
		int x = 0;
		for (int i = StartIndex; i <= EndIndex; i += Downsample_Rate)
		{
			samples[x].real = samples[i].real;
			samples[x].imag = samples[i].imag;
			x++;
		}
		return x;

	}

};
#endif