#include <iostream>
#include <cstring>
using namespace std;
int a[1000000];
int step(long long n)
{
	int i=0;
	while (n != 1)
	{
		if (n < 1000000 && a[n] != 0) break;
		if (n % 2 == 0) n = n / 2;
		else n = n * 3 + 1;
		i++;
	}
	return a[n] + i;
}
int main()
{
	int i,j,k;
	int tmp = 0;
	memset(a, 0, 1000000 * sizeof(int));
	while (!cin.eof())
	{
		cin>>i>>j;
		int tmpi = i;
		int tmpj = j;
		int max=0;
		if (i > j)
		{
			i = i + j;
			j = i - j;
			i = i - j;
		}
		for (k = i; k <= j; k++)
		{
			a[k] = step(k);
			if (a[k] > max)
				max = a[k];
		}
		cout << tmpi << " " << tmpj << " " << max + 1<<endl;
	}
	return 0;
}
