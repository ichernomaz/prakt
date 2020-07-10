#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <conio.h> 
#include <locale.h> 
#include <cmath>
#include <iostream>
using namespace std;
int power(int x, int n)
{
	if (n == 0) return 1;
	return x * power(x, n - 1);
}
int main()
{
	setlocale(LC_ALL, "");
	unsigned int c, x, max, min, k, mask;
	mask = 15;
	scanf("%d", &c);
	while ((c != 16)
	{
		printf("Введено неверное чсило. Введите его повторно\n");
		scanf("%d", &c);
	};
	if (c == 16)
	{
		printf("Ввод шестнад. x\n");
		scanf("%x", &x);
	}
	min = max = x & mask;
	k = 8;
	while ((x & (power(16, k - 1) * 15)) == 0)
		k--;
	for (int i = 0; i < k; i++)
	{
		if ((x >> i * 4 & mask) > max)
			max = x >> i * 4 & mask;
		if ((x >> i * 4 & mask) < min)
			min = x >> i * 4 & mask;
	};
	x = x << (8 - k + 1) * 4 >> (8 - k) * 4 | max << k * 4;
	x = x >> 8 << 4 | min;
	printf("шестнад. min=%x max=%x x=%x\n", min, max, x);
}}

