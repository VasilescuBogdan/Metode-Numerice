#include <iostream>

int main()
{
	//Citim n, dimensiunea matricei A si matricea extinsa (A / b)
	int n;
	float a[10][11];
	std::cout << "n = ";
	std::cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n + 1; j++)
			std::cin >> a[i][j];

	for (int k = 1; k <= n - 1; k++)
	{
		if (a[k][k] != 0)
			//Aplicam formulele din metoda Gauss (regula dreptunghiului)
			for (int i = k + 1; i <= n; i++)
			{
				a[i][k] = a[i][k] / a[k][k];
				for (int j = k + 1; j <= n + 1; j++)
					a[i][j] = a[i][j] - a[i][k] * a[k][j];
			}
		else
		{
			// se cauta o linie cu al k-lea termen nenul pe care sa o schimbam cu linia noastra
			int i = k;
			do 
				i = i + 1;
			while (a[i][k] == 0 && i <= n);
			if (i > n)
			{
				std::cout << "Sistemul nu are solutie unica";
				return 0;
			}
			for (int j = k; j <= n + 1; j++)
			{
				int aux = a[k][j];
				a[k][j] = a[i][j];
				a[i][j] = aux;
			}
		}
	}

	if (a[n][n] == 0)
	{
		std::cout << "Sistemul nu are solutie unica";
		return 0;
	}

	//Determinam x[n]
	a[n][n + 1] = a[n][n + 1] / a[n][n];

	//Determinam x[i]
	for (int i = n - 1; i >= 1; i--)
	{
		int S = 0;
		for (int j = i + 1; j <= n; j++)
			S = S + a[i][j] * a[j][n + 1];
		a[i][n + 1] = (a[i][n + 1] - S) / a[i][i];
	}

	for (int i = 1; i <= n; i++)
		std::cout << "x[" << i << "] = " << a[i][n + 1] << std::endl;

	return 0;
}