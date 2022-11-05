#pragma once
#ifndef COMPLEXFREQSHIFTCLASS_H
#define COMPLEXFREQSHIFTCLASS_H
#include "ComplexCoreClass.h"

TemplateDefinition
class ComplexFrequencyShiftClass : ComplexCoreClass <TemplateParameter>
{
public:
	ComplexFrequencyShiftClass() 
	{
		// dont call base class default constructor directly, icc has problem with it.
		// default constructor of base class automatically called befor constructor of derived class.
		// but parametrized constructor of base class should be called explicitly.
	}
	ComplexFrequencyShiftClass(MemoryManagerClass *MemoryManager) : BaseConstructor
	{
	
	}
	Tca FrequencyShift(Tca Signal, int FS, Ts FoffsetEst, AccuracyDegree Accuracy = AccuracyDegree::HighAccuracy)
	{
		double pi = 3.1415926535897930;	
		Tca shiftedsig = Tca(Signal.Length, this->MemManager);
		double mulfac = -2.0 *FoffsetEst / ((double)FS);
		double tmpAcc = 0;
		if (mulfac>0)
		{
			if (Accuracy == AccuracyDegree::HighAccuracy)
			{
				for (int i = 0; i < Signal.Length; i++)
				{
					Ts inp = tmpAcc*pi;

					shiftedsig[i].real = cos(inp);
					shiftedsig[i].imag = sin(inp);

					shiftedsig[i] = shiftedsig[i] * Signal[i];
					tmpAcc += mulfac;
					//tmpAcc=fmod(tmpAcc, 2.0);
					if (tmpAcc>2.0)
					{
						tmpAcc = tmpAcc - 2.0;
					}
				}
				shiftedsig.Length = Signal.Length;
			}
			else
			{
				double radianshift = 0;
				for (int i = 0; i < Signal.Length; i++)
				{
					Ts inp = tmpAcc*pi;
					this->CSinCos(inp, shiftedsig[i].imag, shiftedsig[i].real);
					shiftedsig[i] = shiftedsig[i] * Signal[i];
					tmpAcc += mulfac;
					//tmpAcc = fmod(tmpAcc, 2.0);
					if (tmpAcc>2.0)
					{
						tmpAcc = tmpAcc - 2.0;
					}
				}
				shiftedsig.Length = Signal.Length;
			}
		}
		else
		{
			if (Accuracy == AccuracyDegree::HighAccuracy)
			{
				for (int i = 0; i < Signal.Length; i++)
				{
					Ts inp = tmpAcc*pi;

					shiftedsig[i].real = cos(inp);
					shiftedsig[i].imag = sin(inp);

					shiftedsig[i] = shiftedsig[i] * Signal[i];
					tmpAcc += mulfac;
					//tmpAcc=fmod(tmpAcc, 2.0);
					if (tmpAcc < -2.0)
					{
						tmpAcc = tmpAcc + 2.0;
					}

				}
				shiftedsig.Length = Signal.Length;
			}
			else
			{
				double radianshift = 0;
				for (int i = 0; i < Signal.Length; i++)
				{
					Ts inp = tmpAcc*pi;
					this->CSinCos(inp, shiftedsig[i].imag, shiftedsig[i].real);
					shiftedsig[i] = shiftedsig[i] * Signal[i];
					tmpAcc += mulfac;
					//tmpAcc = fmod(tmpAcc, 2.0);
					if (tmpAcc < -2.0)
					{
						tmpAcc = tmpAcc + 2.0;
					}
				}
				shiftedsig.Length = Signal.Length;
			}
		}
		

		return shiftedsig;
	}
	void FrequencyShift_inplace(Tca Signal, int FS, Ts FoffsetEst, AccuracyDegree Accuracy = AccuracyDegree::HighAccuracy)
	{
		double pi = 3.1415926535897930;
		double mulfac = -2.0 *FoffsetEst / ((double)FS);
		double tmpAcc = 0;
		Tc tmp;
		if (mulfac > 0)
		{
			if (Accuracy == AccuracyDegree::HighAccuracy)
			{
				for (int i = 0; i < Signal.Length; i++)
				{
					Ts inp = tmpAcc*pi;

					tmp.real = cos(inp);
					tmp.imag = sin(inp);

					Signal[i] = tmp * Signal[i];
					tmpAcc += mulfac;
					if (tmpAcc>2.0)
					{
						tmpAcc = tmpAcc - 2.0;
					}
					//	tmpAcc = fmod(tmpAcc, 2.0);

				}
			}
			else
			{
				double radianshift = 0;
				for (int i = 0; i < Signal.Length; i++)
				{
					Ts inp = tmpAcc*pi;
					this->CSinCos(inp, tmp.imag, tmp.real);
					Signal[i] = tmp * Signal[i];
					tmpAcc += mulfac;
					//tmpAcc = fmod(tmpAcc, 2.0);
					if (tmpAcc > 2.0)
					{
						tmpAcc = tmpAcc - 2.0;
					}
				}
			}
		}
		else
		{
			if (Accuracy == AccuracyDegree::HighAccuracy)
			{
				for (int i = 0; i < Signal.Length; i++)
				{
					Ts inp = tmpAcc*pi;

					tmp.real = cos(inp);
					tmp.imag = sin(inp);

					Signal[i] = tmp * Signal[i];
					tmpAcc += mulfac;
					if (tmpAcc < -2.0)
					{
						tmpAcc = tmpAcc + 2.0;
					}
					//	tmpAcc = fmod(tmpAcc, 2.0);

				}
			}
			else
			{
				double radianshift = 0;
				for (int i = 0; i < Signal.Length; i++)
				{
					Ts inp = tmpAcc*pi;
					this->CSinCos(inp, tmp.imag, tmp.real);
					Signal[i] = tmp * Signal[i];
					tmpAcc += mulfac;
					//tmpAcc = fmod(tmpAcc, 2.0);
					if (tmpAcc< -2.0)
					{
						tmpAcc = tmpAcc + 2.0;
					}
				}
			}
		}
	}
	void FrequencyShift_ToOutMem(Tca Signal, int FS, Ts FoffsetEst,Tca &OutMem, AccuracyDegree Accuracy = AccuracyDegree::HighAccuracy)
	{
		double pi = 3.1415926535897930;

	
		double mulfac = -2.0 *FoffsetEst / ((double)FS);
		double tmpAcc = 0;
		if (mulfac > 0 )
		{
			if (Accuracy == AccuracyDegree::HighAccuracy)
			{
				for (int i = 0; i < Signal.Length; i++)
				{
					Ts inp = tmpAcc*pi;

					OutMem[i].real = cos(inp);
					OutMem[i].imag = sin(inp);

					OutMem[i] = OutMem[i] * Signal[i];
					tmpAcc += mulfac;
					//tmpAcc=fmod(tmpAcc, 2.0);
					if (tmpAcc>2.0)
					{
						tmpAcc = tmpAcc - 2.0;
					}

				}
				OutMem.Length = Signal.Length;
			}
			else
			{
				double radianshift = 0;
				for (int i = 0; i < Signal.Length; i++)
				{

					Ts inp = tmpAcc*pi;
					this->CSinCos(inp, OutMem[i].imag, OutMem[i].real);
					OutMem[i] = OutMem[i] * Signal[i];
					tmpAcc += mulfac;
					//tmpAcc = fmod(tmpAcc, 2.0);
					if (tmpAcc>2.0)
					{
						tmpAcc = tmpAcc - 2.0;
					}
				}
				OutMem.Length = Signal.Length;
			}
		}
		else
		{
			if (Accuracy == AccuracyDegree::HighAccuracy)
			{
				for (int i = 0; i < Signal.Length; i++)
				{
					Ts inp = tmpAcc*pi;

					OutMem[i].real = cos(inp);
					OutMem[i].imag = sin(inp);

					OutMem[i] = OutMem[i] * Signal[i];
					tmpAcc += mulfac;
					//tmpAcc=fmod(tmpAcc, 2.0);
					if (tmpAcc < -2.0)
					{
						tmpAcc = tmpAcc + 2.0;
					}

				}
				OutMem.Length = Signal.Length;
			}
			else
			{
				double radianshift = 0;
				for (int i = 0; i < Signal.Length; i++)
				{

					Ts inp = tmpAcc*pi;
					this->CSinCos(inp, OutMem[i].imag, OutMem[i].real);
					OutMem[i] = OutMem[i] * Signal[i];
					tmpAcc += mulfac;
					//tmpAcc = fmod(tmpAcc, 2.0);
					if (tmpAcc < -2.0)
					{
						tmpAcc = tmpAcc + 2.0;
					}
				}
				OutMem.Length = Signal.Length;
			}
		}
		

	}
	void FrequencyShift_ToOutMem_sx(TcArrShort Signal, int FS, Ts FoffsetEst, Tca &OutMem, AccuracyDegree Accuracy = AccuracyDegree::HighAccuracy)
	{
		//short to anytype
		double pi = 3.1415926535897930;
		double mulfac = -2.0 *FoffsetEst / ((double)FS);
		double tmpAcc = 0;
		if (mulfac > 0)
		{
			if (Accuracy == AccuracyDegree::HighAccuracy)
			{
				for (int i = 0; i < Signal.Length; i++)
				{
					Ts inp = tmpAcc*pi;

					OutMem[i].real = cos(inp);
					OutMem[i].imag = sin(inp);

					OutMem[i] = OutMem[i] * Signal[i];
					tmpAcc += mulfac;
					//tmpAcc=fmod(tmpAcc, 2.0);
					if (tmpAcc>2.0)
					{
						tmpAcc = tmpAcc - 2.0;
					}

				}
				OutMem.Length = Signal.Length;
			}
			else
			{
				double radianshift = 0;
				for (int i = 0; i < Signal.Length; i++)
				{
					Ts inp = tmpAcc*pi;
					this->CSinCos(inp, OutMem[i].imag, OutMem[i].real);
					OutMem[i] = OutMem[i] * Signal[i];
					tmpAcc += mulfac;
					//tmpAcc = fmod(tmpAcc, 2.0);
					if (tmpAcc>2.0)
					{
						tmpAcc = tmpAcc - 2.0;
					}
				}
				OutMem.Length = Signal.Length;
			}
		}
		else
		{
			if (Accuracy == AccuracyDegree::HighAccuracy)
			{
				for (int i = 0; i < Signal.Length; i++)
				{
					Ts inp = tmpAcc*pi;

					OutMem[i].real = cos(inp);
					OutMem[i].imag = sin(inp);

					OutMem[i] = OutMem[i] * Signal[i];
					tmpAcc += mulfac;
					//tmpAcc=fmod(tmpAcc, 2.0);
					if (tmpAcc < -2.0)
					{
						tmpAcc = tmpAcc + 2.0;
					}

				}
				OutMem.Length = Signal.Length;
			}
			else
			{
				double radianshift = 0;
				for (int i = 0; i < Signal.Length; i++)
				{
					Ts inp = tmpAcc*pi;
					this->CSinCos(inp, OutMem[i].imag, OutMem[i].real);
					OutMem[i] = OutMem[i] * Signal[i];
					tmpAcc += mulfac;
					//tmpAcc = fmod(tmpAcc, 2.0);
					if (tmpAcc < -2.0)
					{
						tmpAcc = tmpAcc + 2.0;
					}
				}
				OutMem.Length = Signal.Length;
			}
		}


	}


	Tca FrequencyShift_Continuous(Tca Signal, int FS, Ts FoffsetEst, double &StartState, AccuracyDegree Accuracy = AccuracyDegree::HighAccuracy)
	{
		double pi = 3.1415926535897930;
		Tca shiftedsig = Tca(Signal.Length, this->MemManager);
		double mulfac = -2.0 *FoffsetEst / ((double)FS);

		if (mulfac>0)
		{
			if (Accuracy == AccuracyDegree::HighAccuracy)
			{
				for (int i = 0; i < Signal.Length; i++)
				{
					Ts inp = StartState*pi;

					shiftedsig[i].real = cos(inp);
					shiftedsig[i].imag = sin(inp);

					shiftedsig[i] = shiftedsig[i] * Signal[i];
					StartState += mulfac;
					//tmpAcc=fmod(tmpAcc, 2.0);
					if (StartState>2.0)
					{
						StartState = StartState - 2.0;
					}
				}
				shiftedsig.Length = Signal.Length;
			}
			else
			{
				double radianshift = 0;
				for (int i = 0; i < Signal.Length; i++)
				{
					Ts inp = StartState*pi;
					this->CSinCos(inp, shiftedsig[i].imag, shiftedsig[i].real);
					shiftedsig[i] = shiftedsig[i] * Signal[i];
					StartState += mulfac;
					//tmpAcc = fmod(tmpAcc, 2.0);
					if (StartState>2.0)
					{
						StartState = StartState - 2.0;
					}
				}
				shiftedsig.Length = Signal.Length;
			}
		}
		else
		{
			if (Accuracy == AccuracyDegree::HighAccuracy)
			{
				for (int i = 0; i < Signal.Length; i++)
				{
					Ts inp = StartState*pi;

					shiftedsig[i].real = cos(inp);
					shiftedsig[i].imag = sin(inp);

					shiftedsig[i] = shiftedsig[i] * Signal[i];
					StartState += mulfac;
					//tmpAcc=fmod(tmpAcc, 2.0);
					if (StartState < -2.0)
					{
						StartState = StartState + 2.0;
					}

				}
				shiftedsig.Length = Signal.Length;
			}
			else
			{
				double radianshift = 0;
				for (int i = 0; i < Signal.Length; i++)
				{
					Ts inp = StartState*pi;
					this->CSinCos(inp, shiftedsig[i].imag, shiftedsig[i].real);
					shiftedsig[i] = shiftedsig[i] * Signal[i];
					StartState += mulfac;
					//tmpAcc = fmod(tmpAcc, 2.0);
					if (StartState < -2.0)
					{
						StartState = StartState + 2.0;
					}
				}
				shiftedsig.Length = Signal.Length;
			}
		}


		return shiftedsig;
	}
	void FrequencyShift_Continuous_inplace(Tca Signal, int FS, Ts FoffsetEst, double &StartState, AccuracyDegree Accuracy = AccuracyDegree::HighAccuracy)
	{
		double pi = 3.1415926535897930;
		double mulfac = -2.0 *FoffsetEst / ((double)FS);

		Tc tmp;
		if (mulfac > 0)
		{
			if (Accuracy == AccuracyDegree::HighAccuracy)
			{
				for (int i = 0; i < Signal.Length; i++)
				{
					Ts inp = StartState*pi;

					tmp.real = cos(inp);
					tmp.imag = sin(inp);

					Signal[i] = tmp * Signal[i];
					StartState += mulfac;
					if (StartState>2.0)
					{
						StartState = StartState - 2.0;
					}
					//	StartState = fmod(StartState, 2.0);

				}
			}
			else
			{
				double radianshift = 0;
				for (int i = 0; i < Signal.Length; i++)
				{
					Ts inp = StartState*pi;
					this->CSinCos(inp, tmp.imag, tmp.real);
					Signal[i] = tmp * Signal[i];
					StartState += mulfac;
					//StartState = fmod(StartState, 2.0);
					if (StartState > 2.0)
					{
						StartState = StartState - 2.0;
					}
				}
			}
		}
		else
		{
			if (Accuracy == AccuracyDegree::HighAccuracy)
			{
				for (int i = 0; i < Signal.Length; i++)
				{
					Ts inp = StartState*pi;

					tmp.real = cos(inp);
					tmp.imag = sin(inp);

					Signal[i] = tmp * Signal[i];
					StartState += mulfac;
					if (StartState < -2.0)
					{
						StartState = StartState + 2.0;
					}
					//	StartState = fmod(StartState, 2.0);

				}
			}
			else
			{
				double radianshift = 0;
				for (int i = 0; i < Signal.Length; i++)
				{
					Ts inp = StartState*pi;
					this->CSinCos(inp, tmp.imag, tmp.real);
					Signal[i] = tmp * Signal[i];
					StartState += mulfac;
					//StartState = fmod(StartState, 2.0);
					if (StartState< -2.0)
					{
						StartState = StartState + 2.0;
					}
				}
			}
		}
	}
	void FrequencyShift_Continuous_ToOutMem(Tca Signal, int FS, Ts FoffsetEst, double &StartState, Tca &OutMem, AccuracyDegree Accuracy = AccuracyDegree::HighAccuracy)
	{
		double pi = 3.1415926535897930;


		double mulfac = -2.0 *FoffsetEst / ((double)FS);

		if (mulfac > 0)
		{
			if (Accuracy == AccuracyDegree::HighAccuracy)
			{
				for (int i = 0; i < Signal.Length; i++)
				{
					Ts inp = StartState*pi;

					OutMem[i].real = cos(inp);
					OutMem[i].imag = sin(inp);

					OutMem[i] = OutMem[i] * Signal[i];
					StartState += mulfac;
					//StartState=fmod(StartState, 2.0);
					if (StartState>2.0)
					{
						StartState = StartState - 2.0;
					}

				}
				OutMem.Length = Signal.Length;
			}
			else
			{
				double radianshift = 0;
				for (int i = 0; i < Signal.Length; i++)
				{

					Ts inp = StartState*pi;
					this->CSinCos(inp, OutMem[i].imag, OutMem[i].real);
					OutMem[i] = OutMem[i] * Signal[i];
					StartState += mulfac;
					//StartState = fmod(StartState, 2.0);
					if (StartState>2.0)
					{
						StartState = StartState - 2.0;
					}
				}
				OutMem.Length = Signal.Length;
			}
		}
		else
		{
			if (Accuracy == AccuracyDegree::HighAccuracy)
			{
				for (int i = 0; i < Signal.Length; i++)
				{
					Ts inp = StartState*pi;

					OutMem[i].real = cos(inp);
					OutMem[i].imag = sin(inp);

					OutMem[i] = OutMem[i] * Signal[i];
					StartState += mulfac;
					//StartState=fmod(StartState, 2.0);
					if (StartState < -2.0)
					{
						StartState = StartState + 2.0;
					}

				}
				OutMem.Length = Signal.Length;
			}
			else
			{
				double radianshift = 0;
				for (int i = 0; i < Signal.Length; i++)
				{

					Ts inp = StartState*pi;
					this->CSinCos(inp, OutMem[i].imag, OutMem[i].real);
					OutMem[i] = OutMem[i] * Signal[i];
					StartState += mulfac;
					//StartState = fmod(StartState, 2.0);
					if (StartState < -2.0)
					{
						StartState = StartState + 2.0;
					}
				}
				OutMem.Length = Signal.Length;
			}
		}


	}
	void FrequencyShift_Continuous_ToOutMem_sx(TcArrShort Signal, int FS, Ts FoffsetEst, double &StartState, Tca &OutMem, AccuracyDegree Accuracy = AccuracyDegree::HighAccuracy)
	{
		//short to anytype
		double pi = 3.1415926535897930;
		double mulfac = -2.0 *FoffsetEst / ((double)FS);

		if (mulfac > 0)
		{
			if (Accuracy == AccuracyDegree::HighAccuracy)
			{
				for (int i = 0; i < Signal.Length; i++)
				{
					Ts inp = StartState*pi;

					OutMem[i].real = cos(inp);
					OutMem[i].imag = sin(inp);

					OutMem[i] = OutMem[i] * Signal[i];
					StartState += mulfac;
					//StartState=fmod(StartState, 2.0);
					if (StartState>2.0)
					{
						StartState = StartState - 2.0;
					}

				}
				OutMem.Length = Signal.Length;
			}
			else
			{
				double radianshift = 0;
				for (int i = 0; i < Signal.Length; i++)
				{
					Ts inp = StartState*pi;
					this->CSinCos(inp, OutMem[i].imag, OutMem[i].real);
					OutMem[i] = OutMem[i] * Signal[i];
					StartState += mulfac;
					//StartState = fmod(StartState, 2.0);
					if (StartState>2.0)
					{
						StartState = StartState - 2.0;
					}
				}
				OutMem.Length = Signal.Length;
			}
		}
		else
		{
			if (Accuracy == AccuracyDegree::HighAccuracy)
			{
				for (int i = 0; i < Signal.Length; i++)
				{
					Ts inp = StartState*pi;

					OutMem[i].real = cos(inp);
					OutMem[i].imag = sin(inp);

					OutMem[i] = OutMem[i] * Signal[i];
					StartState += mulfac;
					//StartState=fmod(StartState, 2.0);
					if (StartState < -2.0)
					{
						StartState = StartState + 2.0;
					}

				}
				OutMem.Length = Signal.Length;
			}
			else
			{
				double radianshift = 0;
				for (int i = 0; i < Signal.Length; i++)
				{
					Ts inp = StartState*pi;
					this->CSinCos(inp, OutMem[i].imag, OutMem[i].real);
					OutMem[i] = OutMem[i] * Signal[i];
					StartState += mulfac;
					//StartState = fmod(StartState, 2.0);
					if (StartState < -2.0)
					{
						StartState = StartState + 2.0;
					}
				}
				OutMem.Length = Signal.Length;
			}
		}


	}

};
#endif