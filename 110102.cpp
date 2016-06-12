#include <stdio.h>
#include <string.h>
int main()
{
	int n, m,i,j;
	int a[101][101];
	int Field = 0;
	char c;
	scanf("%d %d", &n, &m);
	while (n!=0 || m!=0)
	{
		Field++;
		memset(a, 0, 101 * 101 * sizeof(int));
		for (i = 1; i <=n; i++)
			for (j = 1; j <= m; j++)
			{
				scanf(" %c", &c);
				if (c == '*')
				{
					a[i][j] = -1;
					for (int p = -1; p <= 1; p++)
						for (int q = -1; q <= 1; q++)
							if ((q != 0 || p != 0)&& a[i + p][j + q]!=-1)
								a[i + p][j + q]++;
				}
			}
		printf("Field #%d:\n", Field);
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
				if (a[i][j] != -1)
					printf("%d", a[i][j]);
				else printf("*");
			//if (i!=n)
				printf("\n");
		}
		scanf("%d %d", &n, &m);
		if (n != 0 || m != 0)
			printf("\n");
	}
	return 0;
}