
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

//sqrt(x)*exp(-x^2)
double F(double x)
{
	return sqrt(x) * exp(-x*x);
}

double PRM(double L, double R, double Eps, int n)
{
	double X, h = (R - L) / n;
	int i;
	float sum = 0;
	if (Eps <= 0.0)
       	{
	       	puts("Nevernoezadanietochnosti\n"); 
		exit(1); 
	}
	for (i = 0; i<= n - 1; i++)
	{
		X = L + i * h; /* vichislenieseredinyotrezka */
		sum = sum + F(X + h / 2);
	}
	return(sum*h);
}

double TRAP(double L, double R, double Eps, int n)
{
	double X, h = (R - L) / n;
	int i;
	float sum = 0;
	if (Eps <= 0.0)
       	{ 
		puts("Неверное задание точности\n");
	       	exit(1);
       	}
	for (i = 0; i<= n - 1; i++)
	{
		X = L + i * h; /* vichislenieseredinyotrezka */
		sum = sum + F(X) + F(L + (i + 1)*h);
	}
	return(sum*h / 2);
}

double SIMPSON(double L, double R, double Eps, int n)
{
	double X, h = (R - L) / n;
	int i;
	float sum = 0;
	if (Eps <= 0.0)
       	{ 
		puts("Неверное задание точности\n");
		exit(1); 
	}
	for (i = 0; i<= n - 1; i += 2)
	{
		X = L + i * h; //Computing half of section
		sum = sum + F(X) + 4 * F(L + (i + 1)*h) + F(L + (i + 2)*h);
	}
	return(sum*h / 3);
}


int main()
{
	int k;
	long int s;
	float a1, b1;
	double a, b, eps, x, x1, X1;
	cout<< "I = sqrt(x)*exp(-x^2)" << endl;
	a = M_PI/2;
	b = M_PI;
	for(double eps = 0.1; eps >= 0.0001; eps *= 0.1)
	{
		cout << "\tEps = " << eps << endl;
		k = 1;
		x1 = PRM(a, b, eps, k);

		do
		{
			X1 = x1;
			k = k * 2;
			x1 = PRM(a, b, eps, k);
			a1 = fabs(x1 - X1) / 3;
		} while (a1>eps);
		cout<< "\tRectangle method: I ="<<X1<<" k="<< k << endl;
		k = 1;
		x1 = TRAP(a, b, eps, k);

		do
		{
		X1 = x1;
		k = k * 2;
		x1 = TRAP(a, b, eps, k);
		a1 = fabs(x1 - X1) / 3;
		} while (a1>eps);
		cout<<"\tTrapezoid method: I =" << X1 << " k=" << k << endl;
		k = 1;
		x1 = SIMPSON(a, b, eps, k);

		do
		{
		X1 = x1;
		k = k * 2;
		x1 = SIMPSON(a, b, eps, k);
		a1 = fabs(x1 - X1) / 15;
		} while (a1>eps);
		cout<< "\tSimpson method: I =" << X1 << " k=" << k << endl << endl;
	}
	return 0;
}
