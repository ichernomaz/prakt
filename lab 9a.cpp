#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
void input(int **a, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		a[i] = (int*)malloc(n * sizeof(int));
		for (j = 0; j < n; j++)
		{
			a[i][j] = rand() % 5;
		}
	}
}

void output(int **a, int n)
{
	int i, j;
	for (i = 0; i < n; i++)  // цикл по строкам
	{
		for (j = 0; j < n; j++)  // цикл по столбцам
		{
			printf("%5d ", a[i][j]); // 5 знакомест под элемент массива
		}
		printf("\n");
	}
}

void change(int **a, int n)
{
	int i, j, z, max, min;
	for (i = 0; i < n; i++)  // цикл по строкам
	{
		max = min = 0;
		for (j = 0; j < n; j++)  // цикл по столбцам
		{
			if (a[i][j] > a[i][max])
				max = j;
			if (a[i][j] < a[i][min])
				min = j;
		}
		z = a[i][max];
		a[i][max] = a[i][min];
		a[i][min] = z;
		printf("\n");
	}
}
int main()
{
	int **a;  // указатель на указатель на строку элементов
	int i, n;
	printf("Kol-vo strok: ");
	scanf("%d", &n);
	// Выделение памяти под указатели на строки
	a = (int**)malloc(n * sizeof(int*));
	input(a, n);
	output(a, n);
	change(a, n);
	output(a, n);
	for (i = 0; i < n; i++)  // цикл по строкам
		free(a[i]);   // освобождение памяти под строку
	free(a);
	return 0;
}