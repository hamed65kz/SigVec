#pragma once
#ifndef COMPLEXFORMATCLASS_H
#define COMPLEXFORMATCLASS_H

#include "ComplexCoreClass.h"

TemplateDefinition
class ComplexFormatClass :  ComplexCoreClass <TemplateParameter>
{
public:
	ComplexFormatClass()
	{
		// dont call base class default constructor directly, icc has problem with it.
		// default constructor of base class automatically called befor constructor of derived class.
		// but parametrized constructor of base class should be called explicitly.
	}
	ComplexFormatClass(MemoryManagerClass *MemoryManager) : BaseConstructor
	{

	}
	//int bin2Dec(char* bin, int binlen)
	//{
	//	int dec = 0, i, exp;
	//	exp = binlen - 1;
	//	for (i = 0; i<binlen; i++, exp--)
	//	{
	//		dec += bin[i] == '1' ? pow(2.0, exp) : 0;
	//	}
	//	return dec;
	//}
	Ts bin2Dec(Ts* bin, int binlen)
	{
		Ts dec = 0, i, exp;
		exp = binlen - 1;
		for (i = 0; i < binlen; i++, exp--)
		{
			dec += bin[i] == 1 ? pow(2.0, exp) : 0;
		}
		return dec;
	}
	Ts bin2Dec(Ta bin)
	{
		return bin2Dec(bin.GetArray(), bin.Length);
	}

	int Hex2Dec(char Hex)
	{
		switch (Hex)
		{
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		case 'A': return 10;
		case 'B': return 11;
		case 'C': return 12;
		case 'D': return 13;
		case 'E': return 14;
		case 'F': return 15;
		}
	}
	const char* Hex2Bin(char Hex)
	{
		switch (Hex)
		{
		case '0': return "0000";
		case '1': return "0001";
		case '2': return "0010";
		case '3': return "0011";
		case '4': return "0100";
		case '5': return "0101";
		case '6': return "0110";
		case '7': return "0111";
		case '8': return "1000";
		case '9': return "1001";
		case 'A': return "1010";
		case 'B': return "1011";
		case 'C': return "1100";
		case 'D': return "1101";
		case 'E': return "1110";
		case 'F': return "1111";
		}
	}
	TCharArr Hex2Bin(char* Hex, int HexLength)
	{
		string bin;
		for (int i = 0; i<HexLength; i++)
		{
			bin += Hex2Bin(Hex[i]);
		}
		//char* binchar = (char*)malloc(sizeof(char)*(bin.length()+1));
		//memset(binchar, 0, sizeof(char)*(bin.length()+1));
		TCharArr res(bin.length() + 1, this->MemManager);
		for (int i = 0; i<bin.length(); i++)
		{
			res[i] = bin[i];
		}
		res.Length = bin.length();
		return res;
	}
	int Hex2Dec(char* Hex, int Hexlength)
	{
		string hexstr = CharArr2string(Hex, Hexlength);
		int dec = 0;
		std::stringstream ss;
		ss << hex;
		ss >> std::hex >> dec;
		return dec;
	}
	int* HexArr2Dec(char* Hex, int Hexlength)
	{
		//int* dec = (int*)malloc(sizeof(int)*Hexlength);

		int* dec = this->AllocInt(Hexlength);
		memset(dec, 0, sizeof(int)*Hexlength);
		std::stringstream ss;
		for (int i = 0; i<Hexlength; i++)
		{
			string hexstr = CharArr2string(&Hex[i], 1);
			ss << hex;
			ss >> std::hex >> dec[i];
		}

		return dec;
	}
	TCharArr String2CharArr(string str)
	{
		/*char* c = (char*)malloc(sizeof(char)*str.length());
		memset(c, 0, sizeof(char)*str.length());*/
		TCharArr res(str.length(), this->MemManager);
		for (int i = 0; i<str.length(); i++)
		{
			res[i] = str[i];
		}
		res.Length = str.length();
		return res;
	}
	string CharArr2string(char* A, int Alength)
	{
		string str;
		for (int i = 0; i<Alength; i++)
		{
			str += A[i];
		}
		return str;
	}
};
#endif