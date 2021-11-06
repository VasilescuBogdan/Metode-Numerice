#include <iostream>

int main()
{
	int n;
	float a[10][11];
	std::cout << "n = ";
	std::cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n + 1; j++)
			std::cin >> a[i][j];

	if (a[1][1] == 0)
	{
		int i = 1;
		do
			i = i + 1;
		while (a[i][1] == 0 && i <= n);
		
		if (i > n)
		{
			std::cout << "Sistemul nu are solutie unica";
			return 0;
		}

		for (int j = 1; j <= n + 1; j++)
		{
			float aux = a[1][j];
			a[1][j] = a[i][j];
			a[i][j] = aux;
		}
		std::cout << "Se permuta linia 1 cu linia" << i << std::endl;
	}

	for (int i = 2; i <= n; i++)
		a[i][1] = a[i][1] / a[1][1];

	for (int k = 2; k <= n; k++)
	{
		int i = k;
		float piv = 0;
		do
		{
			float S = 0;
			for (int h = 1; h <= k - 1; h++)
				S = S + a[i][h] * a[h][k];
			piv = a[i][k] - S;
			i = i + 1;
		} 		while (piv == 0 && i <= n);

		if (piv == 0)
		{
			std::cout << "Sistemul nu are solutie unica";
			return 0;
		}

		if (i != k + 1)
		{
			std::cout << "Se permuta linia " << i - 1 << " cu linia " << k << std::endl;
			for (int j = 1; j <= n + 1; j++)
			{
				float aux = a[k][j];
				a[k][j] = a[i - 1][j];
				a[i - 1][j] = aux;
			}
		}
		
		

		for (int j = k; j <= n; j++)
		{
			float S = 0;
			for (int h = 1; h <= k - 1; h++)
				S = S + a[k][h] * a[h][j];
			a[k][j] = a[k][j] - S;
		}

		for (int i = k + 1; i <= n; i++)
		{
			float S = 0;
			for (int h = 1; h <= k - 1; h++)
				S = S + a[i][h] * a[h][k];
			a[i][k] = (a[i][k] - S) / a[k][k];
		}
	}

	std::cout << "L = " << std::endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			if (i == j)
				std::cout << "1 ";
			else if (i < j)
				std::cout << "0 ";
			else
				std::cout << a[i][j] << " ";
		std::cout << std::endl;
	}
		
	std::cout << "R = " << std::endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			if (i > j)
				std::cout << "0 ";
			else
				std::cout << a[i][j] << " ";
		std::cout << std::endl;
	}

	for (int i = 2; i <= n; i++)
	{
		float S = 0;
		for (int k = 1; k <= i - 1; k++)
			S = S + a[i][k] * a[k][n + 1];
		a[i][n + 1] = a[i][n + 1] - S;
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

	return 0;
}