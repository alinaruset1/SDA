#include <stdio.h>

int v[10];
int solutii = 0;

int valid(int k)
{
	if (k > 0 && v[k] % 2 == 0 && v[k - 1] % 2 == 0)
		return 0;
	return 1;
}

int solutie(int k)
{
	return k == 9;
}

void afisare()
{
	for (int i = 0; i < 10; i++)
	{
		printf("%d", v[i]);
	}
	printf("\n");
}

void back(int k)
{
	
	if (solutii >= 5)
	{
		return;
	}
	
	for (int i = 0; i < 10; i++)
	{
		if (k == 9) {
			if (v[k - 1] % 2 == 0)
				continue;
			v[k] = 0;
			afisare();
			solutii++;
			return;
			if (solutii >= 5)
			{
				return;
			}
		}
		v[k] = i;
	
		if (valid(k))
		{
			if (solutie(k))
			{
				afisare();
				
			}
			else
			{
				back(k + 1);
			}
		}
	}
}

int main(void)
{
	v[0] = 0;
	v[1] = 7;
	v[2] = 9;
	v[3] = 9;
	back(4);
	return 0;
}