
#include <cmath>
#include <iostream>
using namespace std;

double Delta = 0.0001;

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


double Eitken(int a, int b, double x)
{
	double masX[4];
	masX[0] = Round(0.315236273252746, Delta);
//	masX[1] = 0.9536;
//	masX[2] = 1.1080;
//	masX[3] = 2.4728;
	masX[1] = Round(4.17921233625173, Delta);
//	masX[5] = 4.5616;
//	masX[6] = 4.6304;
	masX[2] = Round(4.6704674547625, Delta);
//	masX[8] = 5.2480;
	masX[3] = Round(5.5680073432236745, Delta);
//	masX[10] = 6.3568;
	double masY[4];
	masY[0] = Round(pow(masX[0], 3), Delta);
//	masY[1] = -0.0994;
//	masY[2] = 0.1823;
//	masY[3] = -0.3571;
	masY[1] = Round(pow(masX[1], 3), Delta);
//	masY[5] = 14.2471;
//	masY[6] = 15.5694;
	masY[2] = Round(pow(masX[2], 3), Delta);
//	masY[8] = 31.0168;
	masY[3] = Round(pow(masX[3], 3), Delta);
//	masY[10] = 78.3427;
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
    y = Eitken(0, 3, x);
    cout << "The method of Eitken: y = " <<  y;
return 0; }
