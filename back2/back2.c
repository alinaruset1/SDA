#include <stdio.h>

int v[7];
int cnt1 = 4, cnt0 = 2;

int  valid(int k)
{
	int unu = 0, zero = 0;
	for (int i = 1; i <= k; i++)
	{
		if (v[i] == 1) unu++;
		else if (v[i] == 0) zero++;
	}

	if (unu > cnt1 || zero > cnt0)
	{
		return 0;
	}
	if (k >= 2 && v[1] == 1 && v[2] == 1)
	{
		return 0;
	}
	if (k == 6 && v[k] == 0)
	{
		return 0;
	}
	return 1;
}

int solutie(int k)
{
	if (k != 6) 
		return 0;

	int unu = 0, zero = 0;

	for (int i = 1; i <= k; i++)
	{
		if (v[i] == 1) unu++;
		else if (v[i] == 0) zero++;
	}

		return unu == cnt1 && zero == cnt0;
}

void afisare()
{
	for (int i = 1; i <= 6; i++)
	{
		printf("%d", v[i]);
	}
	printf("\n");
}

void back(int k)
{
	for (int i = 0; i <= 1; i++)
	{
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
	back(1);
	return 0;
}

