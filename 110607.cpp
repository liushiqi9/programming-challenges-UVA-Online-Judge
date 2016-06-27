#include <iostream>
using namespace std;
int main()
{
	int i, j, k, n, ans, tmp;
	ans = 0;
	int a[1000000];
	i = 3;
	a[1] = 1;
	a[2] = 2;
	a[3] = 2;
	ans = 4;
	while (ans <= 2000000000)
	{
		for (j = 1; j <= a[i] && ans <= 2000000000; j++)
		{
			if (ans<1000000)
				a[ans] = i;
			ans++;
		}
		i++;
	}
	while (cin >> n && n != 0)
	{
		tmp = 0;
		j = 0;
		while (tmp < n)
		{
			j++;
			tmp += a[j];
		}
		cout << j << endl;
	}
}