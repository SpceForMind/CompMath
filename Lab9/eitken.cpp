
#include <cmath>
#include <iostream>
using namespace std;


double Eitken(int a, int b, double x)
{
	double masX[11];
	masX[0] = 0.3152;
	masX[1] = 0.9536;
	masX[2] = 1.1080;
	masX[3] = 2.4728;
	masX[4] = 4.1792;
	masX[5] = 4.5616;
	masX[6] = 4.6304;
	masX[7] = 4.6704;
	masX[8] = 5.2480;
	masX[9] = 5.5680;
	masX[10] = 6.3568;
	double masY[11];
	masY[0] = -3.0796;
	masY[1] = -0.0994;
	masY[2] = 0.1823;
	masY[3] = -0.3571;
	masY[4] = 8.1696;
	masY[5] = 14.2471;
	masY[6] = 15.5694;
	masY[7] = 16.3723;
	masY[8] = 31.0168;
	masY[9] = 41.8549;
	masY[10] = 78.3427;
	double dx1,dx2;
	if(b - a == 1) 
	{
	// для соседних значений в таблице
		dx1 = (x - masX[a]) * masY[b]; // вычисление опредилителя 
		dx2 = (x - masX[b]) * masY[a];
		return((dx1 - dx2) / (masX[b] - masX[a])); 
	}
	else // если элементы не соседние, то вычисляем значение интерполяционных многочленов более мелких порядков
		return(((x - masX[a]) * Eitken(a + 1, b, x) - (x - masX[b]) * Eitken(a,b - 1, x)) / (masX[b] - masX[a]));
}

int main() {
double x, y;
    cout << "Input the argument: x = ";
    cin >> x;
    y = Eitken(0, 10, x);
    cout << "The method of Eitken: y = " <<  y;
return 0; }
