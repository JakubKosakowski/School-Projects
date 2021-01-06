#ifndef Class_RPS_H
#define Class_RPS_H
#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::string;
using std::endl;

class Class_RPS{
	private:
		int* pX;
		float* pP;
		int sX, sP, n, x;
		double wo,sd,a,b;
		float p, q;
	public:
		Class_RPS(int = 0);
		Class_RPS(double,double,double,int,int);
		Class_RPS(double,double,double,double,int,int);
		Class_RPS(float,float,double,int,int);
		Class_RPS(float,float,double,double,int,int);
		void FillInt(int, int);
		void FillFloat(float, int);	
		void PrintX();
		void PrintP();
		double WO();
		float checkP();
		double Var(double);
		double Ia();
		double Ib();
		double I2a();
		double I2b();
};

#include "Class_RPS.cpp"
#endif
