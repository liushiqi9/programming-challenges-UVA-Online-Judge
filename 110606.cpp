#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
int main()
{
	int c[21], f[10001][21];
	int i, j, k, n , t, end;
	memset(c, 0, sizeof(c));
	memset(f, 0, sizeof(f));
	c[0] = 1;
	f[1][0] = 1;
	i = 2;
	k = 2;
	while (i<10001)
	{
		for (j = 0; j < 20; j++)
			c[j] = c[j] * 2;
		for (j = 0; j < 20; j++)
		{
			c[j + 1] += c[j] / 100000000;
			c[j] = c[j] % 100000000;
		}
		for (t = 1; t <= k; t++)
		{
			for (j = 0; j < 20; j++)
			{
				f[i][j] += f[i - 1][j] + c[j];
				f[i][j + 1] += f[i][j] / 100000000;
				f[i][j] = f[i][j] % 100000000;
			}
			i++;
			if (i == 10001)
				break;
		}
		
		if (i == 10001)
			break;
		k++;
			
	}

	while (cin >> n)
	{
		end = 19;
		while (f[n][end] == 0 && end>0) end--;
		cout << f[n][end];
		end--;
		while (end >= 0)
		{
			cout << setfill('0') << setw(8) << f[n][end];
			end--;
		}
		cout << endl;
	}
}