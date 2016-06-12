#include <stdio.h>
#include <math.h>
double max(double x, double y)
{
	if (x > y) return x;
	else return y;
}
int main()
{
	int i,j,n;
	double a[1000];
	double sum,answer1,answer2,sumup,sumbot;
	scanf_s("%d", &n);
	while (n != 0)
	{
		answer1 = 0;
		answer2 = 0;
		sum = 0;
		for (i = 0; i < n; i++) 
		{
			scanf_s("%lf", &a[i]);
			sum += a[i];
		}
		sum = sum / n;
		if (sum * 100-(int)(sum * 100) >0.0001)
		{
			sumup = (double)((int)(sum * 100)) / 100 + 0.01;
			sumbot = sumup - 0.01;
		}
		else
		{
			sumup = sum;
			sumbot = sum;
		}
		for (i = 0; i < n; i++)
			if (a[i]>sum)
				answer1 += (a[i] - sumup);
			else
			{
				answer2 += sumbot - a[i];
			}
		printf("$%.2lf\n", max(answer1,answer2));
		scanf_s("%d", &n);
	}
}