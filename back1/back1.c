#include <stdio.h>
#include <string.h>

int solutii = 0;
int v[11];

int valid(int k)
{
	int a = 0, b = 0, c = 0;
	for (int i = 1; i <= k; i++)
	{
		if (v[i] == 1) a++;
		else if (v[i] == 2) b++;
		else if (v[i] == 3) c++;
	}

	if (a > 3 || b > 4 || c > 3)
	{
		return 0;
	}
	return 1;
}

int solutie(int k)
{
	if (k != 10)
		return 0;
	int a = 0, b = 0, c = 0;
	for (int i = 1; i <= k; i++)
	{
		if (v[i] == 1) a++;
		else if (v[i] == 2) b++;
		else if (v[i] == 3) c++;
	}

	return a == 3 && b == 4 && c == 3;
}

void afisare(int k) {
	for (int i = 1; i <= k; i++) {
		if (v[i] == 1) printf("a");
		else if (v[i] == 2) printf("b");
		else if (v[i] == 3) printf("c");
	}
	printf("\n");
}

int back(int k)
{
	if (solutii >= 5) return;
	for (int i = 1; i <= 3; i++)  // 1 = 'a', 2 = 'b', 3 = 'c'
	{
		v[k] = i;
		if (valid(k))
		{
			if (solutie(k))
			{
				afisare(k);
				solutii++;
				if (solutii >= 5) return;
			}
			else {
				back(k + 1);
			}
		}

	}
}

int main(void)
{
	back(1);
	return 0;
}