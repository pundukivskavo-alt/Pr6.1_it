// Лабораторна робота № 6. Завдання 6.1 (ітераційний спосіб). Варіант 20
// Масив x із 24 елементів цілого типу, діапазон значень (-17,...,53).
// Критерій: всі від'ємні, крім кратних 3.
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;


void Create(int *a, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low + 1);
}

void Print(int *a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << a[i];
	cout << endl;
}

// кількість елементів, що задовольняють критерію
int Count(int *x, const int size)
{
	 int k = 0;
	for (int i = 0; i < size; i++)
		if (x[i]<0 && x[i] % 3 != 0)
			k++;
	return k;
}

int Sum(int *x, const int size)
{
	int S = 0;
	for (int i = 0; i < size; i++)
		if (x[i] < 0 && x[i] % 3 != 0)
			S += x[i];
	return S;
}

void Zeroing(int* x, const int size)
{
	for (int i=0;i<size;i++)
		if(x[i]<0 && x[i] % 3 != 0)
			x[i] = 0;

}
int main()
{
	srand((unsigned)time(NULL));
	const int n = 24;
	int x[n];

	int Low = -17;
	int High = 53;

	Create(x, n, Low, High);
	Print(x, n);

	cout << "count = "<< Count(x, n) << endl;
	cout << "sum = " << Sum(x, n) << endl;

	Zeroing(x, n);
	Print(x, n);

	return 0;

}

