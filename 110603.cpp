#include<iostream>
#include <iomanip>
#include <cstring>
using namespace std;
int main()
{
	int a[1001][100];
	int i, j, k,n;
	memset(a, 0, sizeof(a));
	a[1][0] = 2;
	a[2][0] = 5;
	a[3][0] = 13;
	for (i = 4; i < 1001; i++)
	{
		for (j = 0; j < 100; j++)
		{
			a[i][j] = a[i][j] + a[i - 1][j] * 2 + a[i - 2][j] + a[i - 3][j];
			if (a[i][j] >= 1000000)
			{
				a[i][j + 1] += a[i][j] / 1000000;
				a[i][j] = a[i][j] % 1000000;
			}
		}
	}
	while (cin >> n)
	{
		int length = 99;
		while (a[n][length] == 0) length--;
		cout << a[n][length];
		length--;
		while (length >= 0)
		{
			cout << setfill('0') << setw(6) << a[n][length];
			length--;
		}
		cout << endl;
		
	}
}