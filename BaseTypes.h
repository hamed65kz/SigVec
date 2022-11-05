#pragma once
#ifndef BASETYPE_H
#define BASETYPE_H


typedef struct  {
	double real;
	double imag;
	void Complex64()
	{
		real = 0;
		imag = 0;
	}

}Complex64;

typedef struct  {
	float real;
	float imag;
	void Complex32()
	{
		real = 0;
		imag = 0;
	}
}Complex32;



typedef struct  {
	long long real;
	long long imag;
	void ComplexLong()
	{
		real = 0;
		imag = 0;
	}

}ComplexLong;

typedef struct  {
	int real;
	int imag;
	void ComplexInt()
	{
		real = 0;
		imag = 0;
	}

}ComplexInt;

typedef struct  {
	short real;
	short imag;
	void ComplexShort()
	{
		real = 0;
		imag = 0;
	}
}ComplexShort;

typedef struct  {
	char real;
	char imag;
	void ComplexChar()
	{
		real = 0;
		imag = 0;
	}
}ComplexChar;

typedef struct{
	double real;
	double imag;
	void TMyComplex()
	{
		real = 0;
		imag = 0;
	}
}TMyComplex;

Complex64 operator * (const Complex64 &left, const Complex64 &right);
Complex64 operator * (const Complex64 &left, const ComplexShort &right);
Complex64 operator * (const Complex64 &left, const double &right);
Complex64 operator / (const Complex64 &left, const double &right);
Complex64 operator / (const Complex64 &left, const Complex64 &right);
Complex64 operator + (const Complex64 &left, const Complex64 &right);
Complex64 operator - (const Complex64 &left, const Complex64 &right);
Complex64 operator + (const Complex64 &left, const double &right);
Complex64 operator - (const Complex64 &left, const double &right);


Complex32 operator * (const Complex32 &left, const Complex32 &right);
Complex32 operator * (const Complex32 &left, const ComplexShort &right);
Complex32 operator * (const Complex32 &left, const float &right);
Complex32 operator / (const Complex32 &left, const float &right);
Complex32 operator / (const Complex32 &left, const Complex32 &right);
Complex32 operator + (const Complex32 &left, const Complex32 &right);
Complex32 operator - (const Complex32 &left, const Complex32 &right);
Complex32 operator + (const Complex32 &left, const float &right);
Complex32 operator - (const Complex32 &left, const float &right);

ComplexLong operator * (const ComplexLong &left, const ComplexLong &right);
ComplexLong operator * (const ComplexLong &left, const int &right);
ComplexLong operator / (const ComplexLong &left, const int &right);
ComplexLong operator / (const ComplexLong &left, const ComplexLong &right);
ComplexLong operator + (const ComplexLong &left, const ComplexLong &right);
ComplexLong operator - (const ComplexLong &left, const ComplexLong &right);
ComplexLong operator + (const ComplexLong &left, const int &right);
ComplexLong operator - (const ComplexLong &left, const int &right);

ComplexInt operator * (const ComplexInt &left, const ComplexInt &right);
ComplexInt operator * (const ComplexInt &left, const int &right);
ComplexInt operator / (const ComplexInt &left, const int &right);
ComplexInt operator / (const ComplexInt &left, const ComplexInt &right);
ComplexInt operator + (const ComplexInt &left, const ComplexInt &right);
ComplexInt operator - (const ComplexInt &left, const ComplexInt &right);
ComplexInt operator + (const ComplexInt &left, const int &right);
ComplexInt operator - (const ComplexInt &left, const int &right);

ComplexShort operator * (const ComplexShort &left, const ComplexShort &right);
ComplexShort operator * (const ComplexShort &left, const short &right);
ComplexShort operator / (const ComplexShort &left, const short &right);
ComplexShort operator / (const ComplexShort &left, const int &right);
ComplexShort operator / (const ComplexShort &left, const ComplexShort &right);
ComplexShort operator + (const ComplexShort &left, const ComplexShort &right);
ComplexShort operator - (const ComplexShort &left, const ComplexShort &right);
ComplexShort operator + (const ComplexShort &left, const short &right);
ComplexShort operator - (const ComplexShort &left, const short &right);

ComplexChar operator * (const ComplexChar &left, const ComplexChar &right);
ComplexChar operator * (const ComplexChar &left, const char &right);
ComplexChar operator / (const ComplexChar &left, const char &right);
ComplexChar operator / (const ComplexChar &left, const short &right);
ComplexChar operator / (const ComplexChar &left, const int &right);
ComplexChar operator / (const ComplexChar &left, const ComplexChar &right);
ComplexChar operator + (const ComplexChar &left, const ComplexChar &right);
ComplexChar operator - (const ComplexChar &left, const ComplexChar &right);
ComplexChar operator + (const ComplexChar &left, const char &right);
ComplexChar operator - (const ComplexChar &left, const char &right);

enum HostISA
{
	SSE=0,
	SSE2=1,
	SSE3=2,
	SSSE3=3,
	SSE4_1=4,
	SSE4_2=5,
	AVX=6,
	AVX2=7,
	AVX512=8
};

#endif
