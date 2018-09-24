
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;
//f(x) = ln(x) - 1/(1 + x^2)

double f(double x)
{
	return log(x) - 1 / (1 + x * x);
}

double bisect(double Left,double Right,double Eps,int &count_iteration)
{
	double E = Eps * 2.0; //minimal size of line segment
	double Fleft = f(Left);
	double Fright = f(Right);
	double x = (Right + Left) * 0.5;
	double y;
	if(Fleft * Fright > 0)
	{
		cout << "incorrect line segment!" << endl;
		exit(1);
	}
	if(Eps <= 0)
	{
		cout << "incorrect eps!" << endl;
		exit(1);
	}
	if(Fleft == 0.0)
		return Left;
	if(Fright == 0.0)
		return Right;
	while(Right - Left >= E)
	{
		y = f(x);
		if(y == 0.0)
			return x;
		if(y * Fleft < 0)
			Right = x;
		else
		{
			Left = x;
			Fleft = y;
		}
		x = (Right + Left) * 0.5;
		++count_iteration;
	}
	return x;
}

double round(double x, double delta)
{
	if(delta <= 1E-9)
	{
		cout << "Incorrect rounding accuracy!";
		exit(1);
	}
	if(x >= 0.0)
		return delta * ((long int)(x / delta) + 0.5);
	else
		return delta * ((long int)(x / delta) - 0.5);
}

int main()
{
	int count_iteration = 0;
	for(double delta = 0.1; delta >= 1E-6; delta *= 0.1)
	{
		cout << "Delta is " << delta << endl;
		for(double eps = 0.1 ; eps >= 1E-6; eps *= 0.1)
		{
			double x = round(bisect(1.0, 10.0, eps, count_iteration), delta);
			cout << "Root is " << x << " for " << count_iteration << " itteration" << endl;
			count_iteration = 0;
		}
		cout << endl << "------------" << endl;
	}

	return 0;
}
