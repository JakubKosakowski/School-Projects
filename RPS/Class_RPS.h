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
		int sX, sP;
	public:
		Class_RPS(int = 0);
		void FillInt(int, int);
		void FillFloat(float, int);	
		void PrintX();
		void PrintP();
		double WO();
		float checkP();
		double Var(double);
};

#include "Class_RPS.cpp"
#endif
