
#include <iostream>
#include <cmath>
using namespace std;


//f = ln(x) - 1(1 + x^2)
double f(double x)
{
	return log(x) - 1/(1 + x*x); 
}

//f' = 1/x + 2*x/(1 + x^2)^2
double f1(double x)
{
	return 1/x + 2*x/((1 + x*x)*(1 + x*x));	
}

double Round (double X,double Delta) 
{
	if (Delta<=1E-9)
	{
		puts("Неверное задание точности округления\n");
		exit(1);
	}
	if (X>0.0) 
		return (Delta*(long((X/Delta)+0.5)));
       	else
	       	return (Delta*(long((X/Delta)-0.5)));
}

double newton(double X,double Eps, double Delta, int &N)
{
	double Y,Y1,DX;
	N=0;
	do
	{
		Y = Round(f(X), Delta);
		if(Y==0.0)
		       	return (X);
		Y1 = Round(f1(X), Delta);
		if(Y1==0.0) 
		{
			puts("Производная обратилась в ноль\n");
			exit(1);
		}
	       	DX=Y/Y1; 
		X=X-DX; 
		N++;
	}
	while(fabs(DX)>Eps);
	return X; 
}



int main()
{
	int n;
	double x = 1.1;//start approximation
	for(double delta = 0.1; delta > 10E-7; delta *= 0.1)
	{
		cout << "Delta = " << delta << endl;
		for(double eps = 0.1; eps > 10E-7; eps *= 0.1)
		{
			cout << "Eps = " << eps << endl;
			cout << "x = " << newton(x, eps, delta, n) << " for " << n << " iteration" << endl;
		}
		cout << "--------------" << endl;	
	}


	return 0;
}
