#include <iostream> 

int main()
{
	int n, m;
	double x[10], f[10], z[10];

	std::cout << "n = ";
	std::cin >> n;

	std::cout << "x = ";
	for (int i = 0; i <= n; i++)
		std::cin >> x[i];

	std::cout << "f = ";
	for (int i = 0; i <= n; i++)
		std::cin >> f[i];

	std::cout << "m = ";
	std::cin >> m;
	
	
	for (int j = 1; j <= m; j++)
	{
		std::cout << "z[" << j << "] = ";
		std::cin >> z[j];
		if (z[j] < x[0] || z[j] > x[n])
		{
			std::cout << "nu putem aproxima f in " << z[j] << std::endl;
			continue;
		}
		
		float L = 0;

		for (int k = 0; k <= n; k++)
		{
			float P = 1;
			for (int i = 0; i <= n; i++)
				if (i != k)
					P = P * (z[j] - x[i]) / (x[k] - x[i]);
			L += f[k] * P;
		}
		
		for (int i = 0; i <= n; i++)
		if (z[j] == x[i])
			L = f[i];

		std::cout << "Valoarea aproximativa a functiei f in " << z[j] << " este " << L << std::endl;
	}

	
	return 0;
}