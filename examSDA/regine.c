#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int n, v[20], count = 0;

void afisare(void)
{
	int i, j;
    count++;
	for (i = 1;i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			if (v[i] == j)
				printf("1 ");
			else
				printf("0 ");
		printf("\n");
	}
	printf("\n\n");
}

int valid(int k)
{
	for (int i = 1; i <= k - 1 ; i++)
	if ((v[i] == v[k]) || (abs(v[k] - v[i]) == (k - i)))
		return 0;
	return 1;
}

int solutie(int k)
{
	if (k == n)
		return 1;
	return 0;
}

void back(int k)
{
	for (int i = 1; i <= n; i++)
	{
		v[k] = i;
		if (valid(k) == 1)
		{
			if (solutie(k) == 1)
				afisare();
			else
				back(k + 1);
		}
	}
}

int main(void)
{ 
	printf("numarul de regine?");
	scanf("%d", &n);
	printf("Solutiile posibile de repartizare a celor %d regine sunt:\n\n", n);
	back(1);
    printf("Numarul de solutii =  %d\n", count);
	return 0;
}

