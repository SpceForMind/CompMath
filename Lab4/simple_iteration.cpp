
#include <iostream>
#include <cmath>
using namespace std;


//f' = 1/x + 2*x/(1 + x^2)^2
double f1(double x)
{
	return 1/x + 2*x/((1 + x*x)*(1 + x*x));	
}

//f = ln(x) - 1(1 + x^2)
double f(double x)
{
	return x - 0.925925 * (log(x) - 1/(1 + x*x)); 
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

double iter(double X0,double Eps, double Delta, int &N)
{
	if (Eps<=0.0)
       	{
		puts("Неверное задание точности\n");
		exit (1);
	}
       	double X1 = Round(f(X0), Delta);
	double X2 = Round(f(X1), Delta);
	N = 2;
	while((X1 - X2)*(X1 - X2) > fabs((2*X1-X0-X2)*Eps))
       	{
		X0 = X1;
		X1 = X2;
		X2 = Round(f(X1), Delta);
	       	N++;
	}
	return X2;
}


int main()
{
	int n;
	for(double delta = 0.1; delta >= 1E-6; delta *= 0.1)
	{
		cout << "Delta = " << delta << endl;
		for(double eps = 0.1; eps >= 1E-6; eps *= 0.1)
		{
			cout << "Eps = " << eps << endl;
			cout << "x = " << iter (1.6, eps, delta, n) << " for " << n << " iteration" << endl;
		}
		cout << "------------" << endl;
	}

	return 0;
}
