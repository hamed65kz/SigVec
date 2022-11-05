#pragma once
#include "BaseTypes.h"



Complex64 operator * (const Complex64 &left, const Complex64 &right)
{
	Complex64 tmp;
	tmp.real = (left.real * right.real) - (left.imag * right.imag);
	tmp.imag = (left.real * right.imag) + (left.imag * right.real);
	return tmp;
}
Complex64 operator * (const Complex64 &left, const ComplexShort &right)
{
	Complex64 tmp;
	tmp.real = (left.real * right.real) - (left.imag * right.imag);
	tmp.imag = (left.real * right.imag) + (left.imag * right.real);
	return tmp;
}
Complex64 operator * (const Complex64 &left, const double &right)
{
	Complex64 tmp;
	tmp.real = left.real * right;
	tmp.imag = left.imag * right;
	return tmp;
}
Complex64 operator / (const Complex64 &left, const double &right)
{
	Complex64 tmp;
	tmp.real = left.real / right;
	tmp.imag = left.imag / right;
	return tmp;
}
Complex64 operator / (const Complex64 &left, const Complex64 &right)
{
	Complex64 tmp;
	double D = right.real*right.real + right.imag*right.imag;
	tmp.real = ((left.real*right.real) + (left.imag*right.imag)) / D;
	tmp.imag = ((left.imag * right.real) - (left.real * right.imag)) / D;

	return tmp;
}
Complex64 operator + (const Complex64 &left, const Complex64 &right)
{
	Complex64 tmp;
	tmp.real = (left.real + right.real);
	tmp.imag = (left.imag + right.imag);
	return tmp;
}
Complex64 operator - (const Complex64 &left, const Complex64 &right)
{
	Complex64 tmp;
	tmp.real = (left.real - right.real);
	tmp.imag = (left.imag - right.imag);
	return tmp;
}
Complex64 operator + (const Complex64 &left, const double &right)
{
	Complex64 tmp;
	tmp.real = (left.real + right);
	tmp.imag = left.imag;
	return tmp;
}
Complex64 operator - (const Complex64 &left, const double &right)
{
	Complex64 tmp;
	tmp.real = (left.real - right);
	tmp.imag = left.imag;
	return tmp;
}

Complex32 operator * (const Complex32 &left, const Complex32 &right)
{
	Complex32 tmp;
	tmp.real = (left.real * right.real) - (left.imag * right.imag);
	tmp.imag = (left.real * right.imag) + (left.imag * right.real);
	return tmp;
}
Complex32 operator * (const Complex32 &left, const ComplexShort &right)
{
	Complex32 tmp;
	tmp.real = (left.real * right.real) - (left.imag * right.imag);
	tmp.imag = (left.real * right.imag) + (left.imag * right.real);
	return tmp;
}
Complex32 operator * (const Complex32 &left, const float &right)
{
	Complex32 tmp;
	tmp.real = left.real * right;
	tmp.imag = left.imag * right;
	return tmp;
}
Complex32 operator / (const Complex32 &left, const float &right)
{
	Complex32 tmp;
	tmp.real = left.real / right;
	tmp.imag = left.imag / right;
	return tmp;
}
Complex32 operator / (const Complex32 &left, const Complex32 &right)
{
	Complex32 tmp;
	float D = right.real*right.real + right.imag*right.imag;
	tmp.real = ((left.real*right.real) + (left.imag*right.imag)) / D;
	tmp.imag = ((left.imag * right.real) - (left.real * right.imag)) / D;

	return tmp;
}
Complex32 operator + (const Complex32 &left, const Complex32 &right)
{
	Complex32 tmp;
	tmp.real = (left.real + right.real);
	tmp.imag = (left.imag + right.imag);
	return tmp;
}
Complex32 operator - (const Complex32 &left, const Complex32 &right)
{
	Complex32 tmp;
	tmp.real = (left.real - right.real);
	tmp.imag = (left.imag - right.imag);
	return tmp;
}
Complex32 operator + (const Complex32 &left, const float &right)
{
	Complex32 tmp;
	tmp.real = (left.real + right);
	tmp.imag = left.imag;
	return tmp;
}
Complex32 operator - (const Complex32 &left, const float &right)
{
	Complex32 tmp;
	tmp.real = (left.real - right);
	tmp.imag = left.imag;
	return tmp;
}

ComplexLong operator * (const ComplexLong &left, const ComplexLong &right)
{
	ComplexLong tmp;
	tmp.real = (left.real * right.real) - (left.imag * right.imag);
	tmp.imag = (left.real * right.imag) + (left.imag * right.real);
	return tmp;
}
ComplexLong operator * (const ComplexLong &left, const int &right)
{
	ComplexLong tmp;
	tmp.real = left.real * right;
	tmp.imag = left.imag * right;
	return tmp;
}
ComplexLong operator / (const ComplexLong &left, const int &right)
{
	ComplexLong tmp;
	tmp.real = left.real / right;
	tmp.imag = left.imag / right;
	return tmp;
}
ComplexLong operator / (const ComplexLong &left, const ComplexLong &right)
{
	ComplexLong tmp;
	int D = right.real*right.real + right.imag*right.imag;
	tmp.real = ((left.real*right.real) + (left.imag*right.imag)) / D;
	tmp.imag = ((left.imag * right.real) - (left.real * right.imag)) / D;

	return tmp;
}
ComplexLong operator + (const ComplexLong &left, const ComplexLong &right)
{
	ComplexLong tmp;
	tmp.real = (left.real + right.real);
	tmp.imag = (left.imag + right.imag);
	return tmp;
}
ComplexLong operator - (const ComplexLong &left, const ComplexLong &right)
{
	ComplexLong tmp;
	tmp.real = (left.real - right.real);
	tmp.imag = (left.imag - right.imag);
	return tmp;
}
ComplexLong operator + (const ComplexLong &left, const int &right)
{
	ComplexLong tmp;
	tmp.real = (left.real + right);
	tmp.imag = left.imag;
	return tmp;
}
ComplexLong operator - (const ComplexLong &left, const int &right)
{
	ComplexLong tmp;
	tmp.real = (left.real - right);
	tmp.imag = left.imag;
	return tmp;
}

ComplexInt operator * (const ComplexInt &left, const ComplexInt &right)
{
	ComplexInt tmp;
	tmp.real = (left.real * right.real) - (left.imag * right.imag);
	tmp.imag = (left.real * right.imag) + (left.imag * right.real);
	return tmp;
}
ComplexInt operator * (const ComplexInt &left, const int &right)
{
	ComplexInt tmp;
	tmp.real = left.real * right;
	tmp.imag = left.imag * right;
	return tmp;
}
ComplexInt operator / (const ComplexInt &left, const int &right)
{
	ComplexInt tmp;
	tmp.real = left.real / right;
	tmp.imag = left.imag / right;
	return tmp;
}
ComplexInt operator / (const ComplexInt &left, const ComplexInt &right)
{
	ComplexInt tmp;
	int D = right.real*right.real + right.imag*right.imag;
	tmp.real = ((left.real*right.real) + (left.imag*right.imag)) / D;
	tmp.imag = ((left.imag * right.real) - (left.real * right.imag)) / D;

	return tmp;
}
ComplexInt operator + (const ComplexInt &left, const ComplexInt &right)
{
	ComplexInt tmp;
	tmp.real = (left.real + right.real);
	tmp.imag = (left.imag + right.imag);
	return tmp;
}
ComplexInt operator - (const ComplexInt &left, const ComplexInt &right)
{
	ComplexInt tmp;
	tmp.real = (left.real - right.real);
	tmp.imag = (left.imag - right.imag);
	return tmp;
}
ComplexInt operator + (const ComplexInt &left, const int &right)
{
	ComplexInt tmp;
	tmp.real = (left.real + right);
	tmp.imag = left.imag;
	return tmp;
}
ComplexInt operator - (const ComplexInt &left, const int &right)
{
	ComplexInt tmp;
	tmp.real = (left.real - right);
	tmp.imag = left.imag;
	return tmp;
}

ComplexShort operator * (const ComplexShort &left, const ComplexShort &right)
{
	ComplexShort tmp;
	tmp.real = (left.real * right.real) - (left.imag * right.imag);
	tmp.imag = (left.real * right.imag) + (left.imag * right.real);
	return tmp;
}
ComplexShort operator * (const ComplexShort &left, const short &right)
{
	ComplexShort tmp;
	tmp.real = left.real * right;
	tmp.imag = left.imag * right;
	return tmp;
}
ComplexShort operator / (const ComplexShort &left, const short &right)
{
	ComplexShort tmp;
	tmp.real = left.real / right;
	tmp.imag = left.imag / right;
	return tmp;
}
ComplexShort operator / (const ComplexShort &left, const int &right)
{
	ComplexShort tmp;
	tmp.real = left.real / right;
	tmp.imag = left.imag / right;
	return tmp;
}
ComplexShort operator / (const ComplexShort &left, const ComplexShort &right)
{
	ComplexShort tmp;
	short D = right.real*right.real + right.imag*right.imag;
	tmp.real = ((left.real*right.real) + (left.imag*right.imag)) / D;
	tmp.imag = ((left.imag * right.real) - (left.real * right.imag)) / D;

	return tmp;
}
ComplexShort operator + (const ComplexShort &left, const ComplexShort &right)
{
	ComplexShort tmp;
	tmp.real = (left.real + right.real);
	tmp.imag = (left.imag + right.imag);
	return tmp;
}
ComplexShort operator - (const ComplexShort &left, const ComplexShort &right)
{
	ComplexShort tmp;
	tmp.real = (left.real - right.real);
	tmp.imag = (left.imag - right.imag);
	return tmp;
}
ComplexShort operator + (const ComplexShort &left, const short &right)
{
	ComplexShort tmp;
	tmp.real = (left.real + right);
	tmp.imag = left.imag;
	return tmp;
}
ComplexShort operator - (const ComplexShort &left, const short &right)
{
	ComplexShort tmp;
	tmp.real = (left.real - right);
	tmp.imag = left.imag;
	return tmp;
}

ComplexChar operator * (const ComplexChar &left, const ComplexChar &right)
{
	ComplexChar tmp;
	tmp.real = (left.real * right.real) - (left.imag * right.imag);
	tmp.imag = (left.real * right.imag) + (left.imag * right.real);
	return tmp;
}
ComplexChar operator * (const ComplexChar &left, const char &right)
{
	ComplexChar tmp;
	tmp.real = left.real * right;
	tmp.imag = left.imag * right;
	return tmp;
}
ComplexChar operator / (const ComplexChar &left, const char &right)
{
	ComplexChar tmp;
	tmp.real = left.real / right;
	tmp.imag = left.imag / right;
	return tmp;
}
ComplexChar operator / (const ComplexChar &left, const short &right)
{
	ComplexChar tmp;
	tmp.real = left.real / right;
	tmp.imag = left.imag / right;
	return tmp;
}
ComplexChar operator / (const ComplexChar &left, const int &right)
{
	ComplexChar tmp;
	tmp.real = left.real / right;
	tmp.imag = left.imag / right;
	return tmp;
}
ComplexChar operator / (const ComplexChar &left, const ComplexChar &right)
{
	ComplexChar tmp;
	char D = right.real*right.real + right.imag*right.imag;
	tmp.real = ((left.real*right.real) + (left.imag*right.imag)) / D;
	tmp.imag = ((left.imag * right.real) - (left.real * right.imag)) / D;

	return tmp;
}
ComplexChar operator + (const ComplexChar &left, const ComplexChar &right)
{
	ComplexChar tmp;
	tmp.real = (left.real + right.real);
	tmp.imag = (left.imag + right.imag);
	return tmp;
}
ComplexChar operator - (const ComplexChar &left, const ComplexChar &right)
{
	ComplexChar tmp;
	tmp.real = (left.real - right.real);
	tmp.imag = (left.imag - right.imag);
	return tmp;
}
ComplexChar operator + (const ComplexChar &left, const char &right)
{
	ComplexChar tmp;
	tmp.real = (left.real + right);
	tmp.imag = left.imag;
	return tmp;
}
ComplexChar operator - (const ComplexChar &left, const char &right)
{
	ComplexChar tmp;
	tmp.real = (left.real - right);
	tmp.imag = left.imag;
	return tmp;
}
