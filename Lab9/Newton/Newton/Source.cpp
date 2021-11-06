#include <iostream>

int main()
{
	int n; 
	float x[10], f[10], z;

	std::cout << "n = ";
	std::cin >> n;

	std::cout << "x = ";
	for (int i = 0; i <= n; i++)
		std::cin >> x[i];

	std::cout << "f = ";
	for (int i = 0; i <= n; i++)
		std::cin >> f[i];

	std::cout << "z = ";
	std::cin >> z;

	float N = f[0];
	for (int k = 1; k <= n; k++)
	{
		float s = 0;
		for (int j = 0; j <= k; j++)
		{
			float p = 1;
			for (int i = 0; i <= k; i++)
				if (i != j)
					p *= (x[j] - x[i]);
			s += f[j] / p;
		}

		float p = 1;
		for (int i = 0; i < k; i++)
			p *= (z - x[i]);

		N += s * p;
	}
	std::cout << "Valoarea aproximativa a functiei f in " << z << " este " << N;
}