#include <iostream>
#include <math.h>

int main()
{
	int n, itmax, it;
	double a[10][10], b[10], e, x[10], y[10], max;

	std::cout << "n = ";
	std::cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			std::cin >> a[i][j];

	std::cout << "b = ";
	for (int i = 1; i <= n; i++)
		std::cin >> b[i];

	std::cout << "e = ";
	std::cin >> e;

	std::cout << "itmax = ";
	std::cin >> itmax;

	std::cout << "x = ";
	for (int i = 1; i <= n; i++)
		std::cin >> x[i];

	it = 0;

	do
	{
		max = 0;

		for (int i = 1; i <= n; i++)
		{
			double S = 0;

			for (int j = 1; j <= n; j++)
				if (j != i)
					S += a[i][j] * x[j];

			y[i] = (b[i] - S) / a[i][i];

			if (max < abs(y[i] - x[i]))
				max = abs(y[i] - x[i]);
			
			x[i] = y[i];
		}

		it++;
	} while (max > e && it <= itmax);

	if (it > itmax)
	{
		std::cout << "nu se poate obtine solutia in " << itmax << " iteratii cu precizia " << e;
		return 0;
	}

	std::cout << "Solutia obtinuta in " << it << " iteratii cu precizia " << e << " este :";
	for (int i = 1; i <= n; i++)
		std::cout << x[i] << " ";
}