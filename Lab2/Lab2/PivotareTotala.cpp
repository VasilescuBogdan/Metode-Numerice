#include <iostream>
#include <math.h>
using namespace std;


int main()
{
	int n, c[10][3];
	float e = 0.00001, a[10][11];
	std::cout << "n = ";
	std::cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n + 1; j++)
			std::cin >> a[i][j];

	int npc = 0;
	for (int k = 1; k <= n - 1; k++)
	{
		float piv = fabs(a[k][k]);
		int lin = k, col = k;
		for (int i = k; i <= n; i++)
			for (int j = k; j <= n; j++)
				if (piv < fabs(a[i][j]))
				{
					piv = fabs(a[i][j]);
					lin = i;
					col = j;
				}

		if (piv <= e)
		{
			std::cout << "Sistemul nu are solutie unica";
			return 0;
		}

		if (lin != k)
			for (int j = k; j <= n + 1; j++)
			{
				float aux = a[k][j];
				a[k][j] = a[lin][j];
				a[lin][j] = aux;
			}

		if (col != k)
		{
			npc = npc + 1;
			c[npc][1] = k;
			c[npc][2] = col;
			for (int i = 1; i <= n; i++)
			{
				int aux = a[i][k];
				a[i][k] = a[i][col];
				a[i][col] = aux;
			}
		}

		for (int i = k + 1; i <= n; i++)
		{
			a[i][k] = a[i][k] / a[k][k];
			for (int j = k + 1; j <= n + 1; j++)
				a[i][j] = a[i][j] - a[i][k] * a[k][j];
		}
	}

	if (fabs(a[n][n]) <= e)
	{
		std::cout << "Sistemul nu are solutie unica";
		return 0;
	}

	a[n][n + 1] = a[n][n + 1] / a[n][n];

	for (int i = n - 1; i >= 1; i--)
	{
		int S = 0;
		for (int j = i + 1; j <= n; j++)
			S = S + a[i][j] * a[j][n + 1];
		a[i][n + 1] = (a[i][n + 1] - S) / a[i][i];
	}

	if (npc != 0)
		for (int i = npc; i >= 1; i--)
		{
			float aux = a[c[i][1]][n + 1];
			a[c[i][1]][n + 1] = a[c[i][2]][n + 1];
			a[c[i][2]][n + 1] = aux;
		}

	for (int i = 1; i <= n; i++)
		std::cout << "x[" << i << "] = " << a[i][n + 1] << std::endl;

	return 0;
}