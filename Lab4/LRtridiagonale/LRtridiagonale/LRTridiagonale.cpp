#include <iostream>

int main()
{
	int n; 
	float a[11], b[10], c[10], t[11];
	std::cout << "n = ";
	std::cin >> n;
	std::cout << "a[" << n << "] = ";
	for (int i = 1; i <= n; i++)
	{
		std::cin >> a[i];
	}
	std::cout << "b[" << n - 1 << "] = ";
	for (int i = 1; i < n; i++)
	{
		std::cin >> b[i];
	}
	std::cout << "c[" << n - 1 << "] = ";
	for (int i = 1; i < n; i++)
	{
		std::cin >> c[i];
	}
	std::cout << "t[" << n << "] = ";
	for (int i = 1; i <= n; i++)
	{
		std::cin >> t[i];
	}

	for (int i = 1; i < n; i++)
	{
		if (a[i] == 0)
		{
			std::cout << "Sistemul nu are solutie unica deoarece avem elementul diagonal nul in linia " << i;
			return 0;
		}

		c[i] = c[i] / a[i];
		a[i + 1] -= b[i] * c[i];
	}

	for (int i = 2; i <= n; i++)
		t[i] -= c[i - 1] * t[i - 1];

	if (a[n] == 0)
	{
		std::cout << "Sist. nu are solutie unica deoarece avem elementul diagonal nul in linia " << n;
		return 0;
	}

	t[n] = t[n] / a[n];

	for (int i = n - 1; i >= 1; i--)
		t[i] = (t[i] - b[i] * t[i + 1]) / a[i];

	for (int i = 1; i <= n; i++)
		std::cout << "x[" << i << "] = " << t[i] << std::endl;

	return 0;
}