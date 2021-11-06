#include <iostream>
#include <math.h>

double f(double x, double y);

int main()
{
	double xi, xs, yi, ys, S, I[3], p;
	
	std::cout << "interval abscise : ";
	std::cin >> xi >> xs;

	std::cout << "interval ordonate : ";
	std::cin >> yi >> ys;

	S = (xs - xi) * (ys - yi) / 2;

	I[1] = S / 12 * (f(xi, yi) + f(xs, yi) + f(xs, ys) + 9 * f((xi + 2 * xs) / 3, (2 * yi + ys) / 3));
	I[2] = S / 12 * (f(xi, yi) + f(xi, ys) + f(xs, ys) + 9 * f((2 * xi + xs) / 3, (yi + 2 * ys) / 3));

	std::cout << "Valoarea integralei este " << I[1] + I[2];

	return 0;
}

double f(double x, double y)
{
	return (x * y - 1) / (pow(x, 2) + pow(y, 2) + 1) ;
}