#include <iostream>
#include <math.h>

double g(double x);
int main() 
{
	double x0, x1, e, dif;
	int it = 0, itmax;

	std::cout << "x0 = ";
	std::cin >> x0;
	
	std::cout << "e = ";
	std::cin >> e;
	
	std::cout << "itmax = ";
	std::cin >> itmax;

	do
	{
		x1 = g(x0);
		dif = abs(x1 - x0);
		x0 = x1;
		it++;
	} while (dif > e && it <= itmax);

	if (it > itmax)
	{
		std::cout << "Nu se poate obtine solutia in " << itmax << " iteratii, cu precizia " << e;
		return 0;
	}

	std::cout << "Solutia obtinuta in " << it << " iteratii cu precizia " << e << " este " << x1;
	return 0;
}

double g(double x)
{
	return (-pow(x, 3) + 4) / 5;
}