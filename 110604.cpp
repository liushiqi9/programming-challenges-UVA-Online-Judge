#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
int main()
{
	int p[151][151][80];
	int i, j, k, n, d, l, r, end;
	int ans[80];
	memset(p, 0, sizeof(p));
	for (i = 0; i < 151; i++)
		p[0][i][0] = 1;
	for (i = 1; i < 151; i++)
		for (j = 1; j < 151; j++)
			for (k = 0; k < i; k++)
			{
				for (l = 0; l < 40; l++)
					for (r = 0; r < 40; r++)
						p[i][j][l + r] += p[k][j - 1][l] * p[i - k - 1][j][r];
				for (r = 0; r < 80; r++)
				{
					p[i][j][r + 1] += p[i][j][r] / 10000;
					p[i][j][r] = p[i][j][r] % 10000;
				}
			}

	while (cin >> n>> d)
	{
		if (d == 0)
		{
			cout << 0 << endl;
			continue;
		}
		memset(ans, 0, sizeof(ans));
		for (i = 0; i < 80; i++)
		{
			ans[i] += p[n / 2][d][i] - p[n / 2][d - 1][i];
			if (ans[i] < 0)
			{
				ans[i] += 10000;
				ans[i + 1] -= 1;
			}
		}

		end = 79;
		while (ans[end] == 0 && end > 0) end--;
		cout << ans[end];
		end--;
		while (end >= 0)
		{
			cout << setfill('0') << setw(4) << ans[end];
			end--;
		}
		cout << endl;
	}
}