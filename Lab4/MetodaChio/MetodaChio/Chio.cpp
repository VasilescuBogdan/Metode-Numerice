#include <iostream>

int main()
{
	int n;
	float a[10][10];
	std::cout << "n = ";
	std::cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			std::cin >> a[i][j];
	float det = 1;
	do
	{
		if (a[1][1] == 0)
		{
			int i = 2;
			
			while (i <= n && a[i][1] == 0)
				i++;
			
			if (i > n)
			{
				std::cout << "det(A) = 0";
				return 0;
			}
			
			for (int j = 1; j <= n; j++)
			{
				a[1][j] += a[i][j];
				a[i][j] = a[1][j] - a[i][j];
				a[1][j] -= a[i][j];
			}
			
			det = -det;
		}
		
		for (int i = 1; i <= n - 2; i++)
			det = det * a[1][1];

		for (int i = 2; i <= n; i++)
			for (int j = 2; j <= n; j++)
				a[i][j] = a[i][j] * a[1][1] - a[i][1] * a[1][j];

		n--;

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				a[i][j] = a[i + 1][j + 1];
	} while (n != 1);

	det = a[1][1] / det;
	
	std::cout << "det(A) = " << det;

	return 0;
}