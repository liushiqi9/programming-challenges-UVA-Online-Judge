#include <stdio.h>
#include <string.h>
int getl(char s[])
{
	int i, c;
	i = 0;
	while ((c = getchar()) != '\n' && c!=EOF)
	{
		s[i++] = c;
	}
	s[i] = '\0';
	if (c == EOF) return 0;
	return i;
}
int main()
{
	int t, i;
	scanf("%d ", &t);
	while (t--)
	{
		i = 0;
		int r[10],v,s,count;
		char a[1001][4];
		memset(a,'0',1001*4*sizeof(char));
		memset(r, 0, sizeof(int) * 10);
		while (getl(a[i]))
			i++;
		if (t == 1)
			i++;
		memset(a[i], '0', 4);
		i--;
		i = 0;
		count = 0;
		while (strcmp(a[i],"100"))
		{
			switch (a[i][0])
			{
			case '2':
				r[a[i][1] - '0'] = a[i][2] - '0';
				break;
			case '3':
				r[a[i][1] - '0'] += a[i][2] - '0';
				r[a[i][1] - '0'] = r[a[i][1] - '0'] % 1000;
				break;
			case '4':
				r[a[i][1] - '0'] *= a[i][2] - '0';
				r[a[i][1] - '0'] = r[a[i][1] - '0'] % 1000;
				break;
			case '5':
				r[a[i][1] - '0'] = r[a[i][2] - '0'];
				break;
			case '6':
				r[a[i][1] - '0'] += r[a[i][2] - '0'];
				r[a[i][1] - '0'] = r[a[i][1] - '0'] % 1000;
				break;
			case '7':
				r[a[i][1] - '0'] *= r[a[i][2] - '0'];
				r[a[i][1] - '0'] = r[a[i][1] - '0'] % 1000;
				break;
			case '8':
				v = r[a[i][2] - '0'];
				r[a[i][1] - '0'] = (a[v][0] - '0') * 100 + (a[v][1] - '0') * 10 + (a[v][2] - '0');
				break;
			case '9':
				v = r[a[i][2] - '0'];
				s = r[a[i][1] - '0'];
				a[v][0] = '0'+s/100;
				a[v][1] = '0' + (s / 10)%10;
				a[v][2] = '0' + s % 10;
				a[v][3] = '\0';
				break;
			case '0':
				s = a[i][2] - '0';
				v = a[i][1] - '0';
				if (r[s] != 0)
					i =r[v]-1 ;
				break;
			default:
				break;
			}
			i++;
			count++;
		}
		printf("%d\n", count+1);
		if (t != 0)
			printf("\n");
		
	}
}