#include <stdio.h>
#include <string.h>
#include <math.h>
int main() 
{
	int n,i;
	bool a[3000];
	bool flag;
	int val;
	while (scanf("%d", &n) == 1)
	{
		flag = true;
		memset(a,false,sizeof(bool)*n);
		int pre = 0, current = 0;
		scanf("%d", &pre);
		for (i = 1; i < n; i++)
		{
			scanf("%d", &current);
			val = abs(current - pre);
			a[val] = true;
			pre = current;
		}
		for (i = 1; i < n; i++)
			if (!a[i])
				flag = false;
		if (flag)
			printf("Jolly\n");
		else printf("Not jolly\n");

		
	}
}