#include <iostream>

int main()
{
	int n;
	double A[10][10], B[10][10], c[10], D[10][10];
	std::cout << "n = ";
	std::cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			std::cin >> A[i][j];
	
	// initializam B cu matricea unitate In
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				B[i][j] = 1;
			else
				B[i][j] = 0;
		}
	for (int k = 1; k <= n - 1; k++)
	{
		// calculam A[k], folosind A[k] = A · B[k?1],  ?si notam D = A[k]
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				D[i][j] = 0;
				for (int h = 1; h <= n; h++)
					D[i][j] += A[i][h] * B[h][j];
			}

		// calculam c[k], folosind c[k] = ?Tr(A[k])/k
		c[k] = 0;
		for (int i = 1; i <= n; i++)
			c[k] += D[i][i];
		c[k] = -c[k] / k;

		// calculam B[k], folosind B[k] = c[k] · In + A[k]
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (i == j)
					B[i][j] = D[i][j] + c[k];
				else
					B[i][j] = D[i][j];
	}

	// calculam A[n] = D
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			D[i][j] = 0;
			for (int h = 1; h <= n; h++)
				D[i][j] += A[i][h] * B[h][j];
		}

	// calculam c[n] = ?Tr(A[n])/n
	c[n] = 0;
	for (int i = 1; i <= n; i++)
		c[n] += D[i][i];
	c[n] = -c[n] / n;

	std::cout << "Coeficientii polinomului caracteristic sunt :" << std::endl;
	for (int i = 1; i <= n; i++)
		std::cout << "c[" << i << "] = " << c[i] << std::endl;
	if (c[n] == 0)
		std::cout << "Matricea nu este inversabila.";
	else
	{
		std::cout << "Matricea inversa este:" << std::endl;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				std::cout << B[i][j] / c[n] << " ";
			std::cout << std::endl;
		}
	}
	
	return 0;
}