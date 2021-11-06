#include <iostream>
#include <math.h>

int main()
{
	float A[10][10], y[10][11];
	int n;

	std::cout << "n = ";
	std::cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			std::cin >> A[i][j];

	std::cout << "y(0) = ";
	for (int i = 1; i <= n; i++)
		std::cin >> y[i][n];

	for (int j = n - 1; j >= 1; j--)
		for (int i = 1; i <= n; i++)
		{
			y[i][j] = 0;
			for (int k = 1; k <= n; k++)
				y[i][j] += A[i][k] * y[k][j + 1];
		}

	for (int i = 1; i <= n; i++)
	{
		y[i][n + 1] = 0;
		for (int k = 1; k <= n; k++)
			y[i][n + 1] += A[i][k] * y[k][1];
		y[i][n + 1] = -y[i][n + 1];
	}

	//Rezolvare sistem folosind metoda lui Gauss cu pivotare partiala
	for (int k = 1; k < n; k++)
	{
		float piv = y[k][k];
		int lin = k;

		for (int i = k + 1; i <= n; i++)
			if (fabs(piv) < fabs(y[i][k]))
			{
				piv = y[i][k];
				lin = i;
			}

		if (piv == 0)
		{
			std::cout << "Sistemul nu are solutie unica";
			return 0;
		}

		if (lin != k)
		{
			for (int j = k; j <= n + 1; j++)
			{


				float aux = y[k][j];
				y[k][j] = y[lin][j];
				y[lin][j] = aux;
			}
		}

		for (int i = k + 1; i <= n + 1; i++)
		{
			y[i][k] = y[i][k] / y[k][k];

			for (int j = k + 1; j <= n + 1; j++)
				y[i][j] = y[i][j] - y[i][k] * y[k][j];
		}
	}

	if (y[n][n] == 0)
	{
		std::cout << "Sistemul nu are solutie unica";
		return 0;
	}

	y[n][n + 1] = y[n][n + 1] / y[n][n];

	for (int i = n - 1; i >= 1; i--)
	{
		float S = 0;

		for (int j = i + 1; j <= n; j++)
			S = S + y[i][j] * y[j][n + 1];

		y[i][n + 1] = (y[i][n + 1] - S) / y[i][i];
	}

	for (int i = 1; i <= n; i++)
		std::cout << "c[" << i << "] = " << y[i][n + 1] << std::endl;


	return 0;
}