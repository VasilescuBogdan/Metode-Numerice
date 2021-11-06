#include <iostream>
#include <math.h>

float f(float x);

int main()
{
	float a, b, e;
	std::cout << "a = ";
	std::cin >> a;
	std::cout << "b = ";
	std::cin >> b;
	std::cout << "e = ";
	std::cin >> e;

	int n = 1;

	float Integr = (f(a) - f(b)) * (b - a) / 2;
	float Integr0;

	do
	{
		n *= 2;
		float h = (b - a) / n;
		Integr0 = Integr;
		float S = 0;
		for (int i = 1; i < n; i++)
			S += f(a + i * h);
		Integr = (f(a) + 2 * S + f(b)) * h / 2;
	} while (abs(Integr - Integr0) > e);

	std::cout << "Valoarea integralei, obtinuta cu precizia " << e << " este " << Integr;
}

float f(float x)
{
	if (x >= -1 && x <= 0)
		return 0.4 * pow((1 + x), 3) + 0.6 * (1 + x) - 5 * x;
	if (x >= 0 && x <= 1)
		return 1 / (1 + x);
}