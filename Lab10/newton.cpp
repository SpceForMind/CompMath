
#include <iostream>
#include <cmath>
using namespace std;

double DirectNewton(double x, int n, double *MasX, double *MasY, double step)
{
        // выделяем память под динамический двумерный массив dy
        double **dy = new double*[n];
        for ( int i = 0; i < n; i++ )
		dy[i] = new double[n];
        // подсчитываем dy
        for ( int i = 0; i < n; i++ )
        {
                dy[0][i] = MasY[i];
        }
        for ( int i = 1; i < n; i++ )
        {
                for ( int j = 0; j < n-i; j++ )
                {
                        dy[i][j] = dy[i-1][j+1] - dy[i-1][j];
                }
        }
 
        // вычисляем результирующий y
        double q = (x-MasX[0]) / step; // см. формулу
        double result = MasY[0]; // результат (y) 
 
        double mult_q = 1; // произведение из q*(q-1)*(q-2)*(q-n)
        double fact = 1;  // факториал
 
        for ( int i = 1; i < n; i++ )
        {
                fact *= i;
                mult_q *= (q-i+1);
 
                result += mult_q/fact * dy[i][0];
        }
 
        for ( int i = 0; i < n; i++ ) 
		delete[] dy[i];
        delete[] dy;
 
        return result;
}


double ReverseNewton(double x, int n, double *MasX, double *MasY, double step)
{
        // выделяем память под динамический двумерный массив dy
        double **dy = new double*[n];
        for ( int i = 0; i < n; i++ )
		dy[i] = new double[n];
        // подсчитываем dy
        for ( int i = 0; i < n; i++ )
        {
                dy[0][i] = MasY[i];
        }
        for ( int i = 1; i < n; i++ )
        {
                for ( int j = 0; j < n - i; j++ )
                {
                        dy[i][j] = dy[i-1][j+1] - dy[i-1][j];
                }
        }
 
        // вычисляем результирующий y
        double q = (x-MasX[0]) / step; // см. формулу
        double result = MasY[0]; // результат (y) 
 
        double mult_q = 1; // произведение из q*(q-1)*(q-2)*(q-n)
        double fact = 1;  // факториал
 
        for ( int i = 1; i < n; i++ )
        {
                fact *= i;
                mult_q *= (q - i + 1);
                result += mult_q/fact * dy[i][0];
        }
 
        for ( int i = 0; i < n; i++ ) 
		delete[] dy[i];
        delete[] dy;
 
        return result;
}


double Stirling(double x[], double fx[], double x1, int n)
{
    double h, a, u, y1 = 0, N1 = 1, d = 1, N2 = 1, d2 = 1, temp1 = 1, temp2 = 1, k = 1, l = 1, delta[n][n];
    int i, j, s;
    h = x[1] - x[0];
    s = floor(n / 2);
    a = x[s];
    u = (x1 - a) / h;
    for (i = 0; i < n - 1; ++i)
    {
        delta[i][0] = fx[i + 1] - fx[i];
    }
    for (i = 1; i < n - 1; ++i)
    {
        for (j = 0; j < n - i - 1; ++j)
       	{
            delta[j][i] = delta[j + 1][i - 1]
                - delta[j][i - 1];
        }
    }
    y1 = fx[s];
    for (i = 1; i <= n - 1; ++i)
    {
        if (i % 2 != 0) 
	{
            if (k != 2) 
	    {
                temp1 *= (pow(u, k) - pow((k - 1), 2));
            }
            else 
	    {
                temp1 *= (pow(u, 2) - pow((k - 1), 2));
            }
            ++k;
            d *= i;
            s = floor((n - i) / 2);
            y1 += (temp1 / (2 * d)) * (delta[s][i - 1] + delta[s - 1][i - 1]);
        }
        else 
	{
            temp2 *= (pow(u, 2) - pow((l - 1), 2));
            ++l;
            d *= i;
            s = floor((n - i) / 2);
            y1 += (temp2 / (d)) * (delta[s][i - 1]);
        }
    }
    return y1;
}



int main()
{
	double MasX[] = {0.2870, 0.4590, 0.6320, 0.8040, 0.9770, 1.1490, 1.3220, 1.4940, 1.6670, 1.8390, 2.0120};
	double MasY[] = {-0.2380, -0.0590, 0.0140, 0.0120, -0.0340, -0.0940, -0.1380, -0.1349, -0.0500, 0.1400, 0.4740};
//	double MasX[] = {0.2870, 0.4590, 0.6320, 0.8040};
//	double MasY[] = {pow(MasX[0], 3), pow(MasX[1], 3), pow(MasX[2], 3), pow(MasX[3], 3)};
	double x1 = 1.0980;
	double x2 = 1.8770;
	double x3 = 1.5130;
	cout << "f(" << x1 << ")" << " = " << DirectNewton(x1, 11, MasX, MasY, MasX[1] - MasX[0]) << endl;
	cout << "f(" << x2 << ")" << " = " << ReverseNewton(x2, 11, MasX, MasY, MasX[1] - MasX[0]) << endl;
	cout << "f(" << x3 << ")" << " = " << Stirling(MasX, MasY, x3, 11) << endl;

	return 0;
}
