
#include <iostream>
#include <cmath>
using namespace std;

//sin(x)/(1+x)
double F(double x)
{
	return sin(x) / (1 + x); //M_PI is pi
}

double GAUS(double L, double R)
{
	float *A = new float[8];
	A[0] = A[7] = 0.10122854,
	A[1] = A[6] = 0.22238103,
	A[2] = A[5] = 0.31370664,
	A[3] = A[4] = 0.36268378;
	float *x = new float[8];
	x[0] = -0.96028986;
	x[1] = -0.79666648;
	x[2] = -0.52553242;
	x[3] = -0.18343464;
	x[4] = -x[3];
	x[5] = -x[2];
	x[6] = -x[1];
	x[7] = -x[0];
	float s = 0, t = 0;
	for (int i = 0; i < 8; i++)
	{
		t = (L + R) / 2 + (R - L) / 2 * x[i];
		s = s + A[i] * F(t);
	}
	s = (R - L) / 2 * s;
	return(s);
}


int main()
{
	double a = 0, b = 1;
	cout << "I = " << GAUS(a, b) << endl;
	return 0;
}
