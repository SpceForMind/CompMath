
#include <iostream>
#include <cmath>

using namespace std;
//f(x) = ln(x) - 1/(1 + x^2)

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

double f(double x)
{
	return log(x) - 1/(1 + x * x); 
}


double horda(double Left,double Right,double Eps, double Delta, int &N)
{
	double FLeft = Round(f(Left), Delta);
	double FRight = Round(f(Right), Delta);
	double Y;
	double old_x;
	double X = 2.0;//random start value
	if (FLeft*FRight>0.0) 
	{
		puts("Неверное задание интервала\n");
		exit(1);
	}
       	if (Eps<=0.0) 
	{
		puts("Неверное задание точности\n");
		exit(1);
	}
	N=0;
	if (FLeft==0.0) return Left;
	if (FRight==0.0) return Right;
	do
	{	
		old_x = X;
		X = Left-(Right-Left)*FLeft/(FRight-FLeft);
	       	Y = Round(f(X), Delta);
		if (Y == 0.0) return (X);
		if (Y*FLeft < 0.0)
		{ 
			Right=X;
		       	FRight=Y;
	       	}
		else
		{
		       	Left=X;
		       	FLeft=Y;
       		}
		N++;
       	}
	while ( fabs(old_x - X) >= Eps );
return(X); 
}


int main()
{
	double x;
	int n;
	for(double delta = 0.1; delta > 10E-7; delta *= 0.1)
	{
		cout << "Delta = " << delta << endl;
		for(double eps = 0.1; eps > 10E-7; eps *= 0.1)\
		{
			x = horda(1.0, 2.0, eps, delta, n);
			cout << "Eps = " << eps << endl;
			cout << "x = " << x << " for " << n << " iteration" << endl; 
		}
		cout << "--------" << endl;
	}


	return 0;
}
