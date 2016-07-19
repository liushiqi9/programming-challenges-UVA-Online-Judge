#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int maxn = 4000;
int  path[maxn];
string position[6]= {"front", "back", "left", "right", "top", "bottom"};
struct Cube {
	int bot, top, wei, pos;
	Cube() {};
	Cube(int t, int b, int w, int p) {
		bot = b;
		top = t;
		wei = w;
		pos = p;
	}
};
Cube c[maxn];
void display(int index)
{
	if (index != -1)
	{
		display(path[index]);
		cout << c[index].wei << " " << position[c[index].pos] << endl;

	}
}
int main()
{
	
	int dp[maxn],color[6];
	int i, j, k, n, m, count=0, number, max, maxindex;
	while (cin >> n && n != 0)
	{
		count++;
		number = 0;
		max = 0;
		maxindex = 0;
		memset(dp, 0, sizeof(dp));
		memset(path, -1, sizeof(path));
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < 6; j++)
				cin >> color[j];
			for (j = 0; j < 6; j++)
				if (j % 2)
					c[number++] = Cube(color[j], color[j - 1], i + 1, j);
				else
					c[number++] = Cube(color[j], color[j + 1], i + 1, j);
		}
		for (i = 0; i < number; i++)
			for (j = i + 1; j < number;j++)
				if (c[i].wei < c[j].wei && c[i].bot == c[j].top && dp[j] < dp[i] + 1)
				{
					dp[j] = dp[i] + 1;
					path[j] = i;
				}
		for (i = 0; i < number;i++)
			if (max < dp[i])
			{
				max = dp[i];
				maxindex = i;
			}
		if (count!=1)
			cout << endl;
		cout << "Case #" << count << endl << max + 1 << endl;
		display(maxindex);
		
	}
}