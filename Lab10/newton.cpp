
#include <iostream>
#include <cmath>
using namespace std;

double Newton(double x, int n, double *MasX, double *MasY, double step)
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


int main()
{
	double MasX[] = {0.2870, 0.4590, 0.6320, 0.8040, 0.9770, 1.1490, 1.3220, 1.4940, 1.6670, 1.8390, 2.0120};
	double MasY[] = {-0.2380, -0.0590, 0.0140, 0.0120, -0.0340, -0.0940, -0.1380, -0.1349, -0.0500, 0.1400, 0.4740};
//	double MasX[] = {0.2870, 0.4590, 0.6320, 0.8040};
//	double MasY[] = {pow(MasX[0], 3), pow(MasX[1], 3), pow(MasX[2], 3), pow(MasX[3], 3)};
	double x;
	cout << "Enter x:";
	cin >> x;
	cout << "f(" << x << ")" << " = " << Newton(x, 4, MasX, MasY, MasX[1] - MasX[0]);
	
	return 0;
}
