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

	float Integrala = (f(a) + 4 * f((a + b) / 2) + f(b)) * (b - a) / 6;
	float IntegralaO;

	do
	{
		n *= 2;
		float h = (b - a) / n;
		IntegralaO = Integrala;
		float s1 = 0;
		for (int i = 1; i < n; i++)
			s1 += f(a + i * h);
		float s2 = 0;
		for (int i = 0; i < n; i++)
			s2 += f(a + i * h + h / 2);
		Integrala = (f(a) + 2 * s1 + 4 * s2 + f(b)) * h / 6;
	} while (abs(Integrala - IntegralaO) > e);

	std::cout << "Valoarea integralei, obtinuta cu precizia " << e << " este " << Integrala;
}

float f(float x)
{
	return 1. / (x + 1);
}