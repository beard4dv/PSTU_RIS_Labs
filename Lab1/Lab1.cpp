#include <iostream>
#include <math.h>


int main()
{
	setlocale(LC_ALL, "Rus");
	std::cout << "Задание 1" << std::endl;
	float af = 100, bf = 0.001f;	//a=100, b=0.001
	float cf = pow((af + bf), 4);	//часть выражения (a+b)^4
	float df = af * af * af * af + 4 * af * af * af * bf;		//часть выражения (a^4+4a^3b)
	float ef = 6 * af * af * bf * bf + 4 * af * bf * bf * bf;	//часть выражения (6a^2b^2+4ab^3)
	float ff = pow(bf, 4);	//часть выражения b^4
	float resf = (cf - df) / (ef + ff);		//итоговый результат
	std::cout << resf << std::endl;			//вывод итогового результата
	double ad = 100, bd = 0.001;	//те же вычисления только с типом данных double
	double cd = pow((ad + bd), 4);
	double dd = ad * ad * ad * ad + 4 * ad * ad * ad * bd;
	double ed = 6 * ad * ad * bd * bd + 4 * ad * bd * bd * bd;
	double fd = pow(bd, 4);
	double resd = (cd - dd) / (ed + fd);
	std::cout << resd << std::endl;	//вывод итогового результата

	std::cout << "Задание 2" << std::endl;
	int m, n;	//инициализировали переменные m,n
	std::cout << "Введите m: ";
	std::cin >> m;	//ввод m
	std::cout << "Введите n: ";
	std::cin >> n;	//ввод n
	int res1;	//инициализировали переменную результата 1
	bool res2, res3;	//инициализировали переменную результата 3, 4 c типом bool
	res1 = ++n * ++m;
	res2 = m++ <= n;	
	res3 = n++ > m;	
	std::cout << res1 << std::endl << res2 << std::endl << res3 << std::endl; // вывели результаты
}

