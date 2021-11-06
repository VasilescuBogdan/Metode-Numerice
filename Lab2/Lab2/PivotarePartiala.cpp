#include <iostream>
#include <math.h>

int main()
{
	int n, nrp = 0;
	float a[10][11];
	std::cout << "n = ";
	std::cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n + 1; j++)
			std::cin >> a[i][j];

	for (int k = 1; k < n; k++)
	{
		float piv = a[k][k];
		int lin = k;

		for (int i = k + 1; i <= n; i++)
			if (fabs(piv) < fabs(a[i][k]))
			{
				piv = a[i][k];
				lin = i;
			}

		std::cout << "pivotul la pasul " << k << " este " << piv << std::endl;
		std::cout << "acesta se afla pe pozitia " << lin << " cu " << k << std::endl;

		if (piv == 0)
		{
			std::cout << "Sistemul nu are solutie unica";
			return 0;
		}

		if (lin != k)
		{
			std::cout << "au fost permutate liniile " << k << " si " << lin << std::endl;
			nrp++;
			for (int j = k; j <= n + 1; j++)
			{

				
				float aux = a[k][j];
				a[k][j] = a[lin][j];
				a[lin][j] = aux;
			}
		}

		for (int i = k + 1; i <= n + 1; i++)
		{
			a[i][k] = a[i][k] / a[k][k];

			for (int j = k + 1; j <= n + 1; j++)
				a[i][j] = a[i][j] - a[i][k] * a[k][j];
		}
	}
	
	if (a[n][n] == 0)
	{
		std::cout << "Sistemul nu are solutie unica";
		return 0;
	}

	a[n][n + 1] = a[n][n + 1] / a[n][n];

	for (int i = n - 1; i >= 1; i--)
	{
		float S = 0;

		for (int j = i + 1; j <= n; j++)
			S = S + a[i][j] * a[j][n + 1];

		a[i][n + 1] = (a[i][n + 1] - S) / a[i][i];
	}

	for (int i = 1; i <= n; i++)
		std::cout << "x[" << i << "] = " << a[i][n + 1] << std::endl;
	
	std::cout << "au fost facute " << nrp << " permutari";

	return 0;
}