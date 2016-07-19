#include <iostream>
#include <vector>
using namespace std;
struct edge
{
	int to, cap;
};
int main()
{
	int i, j, h, k, n, r, s, d, t, c=0;
	while (cin >> n >> r && n != 0)
	{
		c++;
		vector<vector<edge>> path(101, vector<edge>());
		vector<int> flow(101,0);
		vector<bool> flag(101,false);
		vector<int> current;
		for (i = 0; i < r; i++)
		{
			cin >> s >> d >> t;
			edge tmp;
			tmp.to = d;
			tmp.cap = t;
			path[s].push_back(tmp);
			tmp.to = s;
			path[d].push_back(tmp);
		}
		cin >> s >> d >> t;
		flag[s] = false;
		current.push_back(s);
		flow[s] = 0x7FFFFFFF;
		while (!flag[d])
		{
			int currentindex1, currentindex2, max=0;
			for (i = 0; i < current.size(); i++)
			{
				for (j = 0; j < path[current[i]].size();j++)
					if (path[current[i]][j].cap>max && !flag[path[current[i]][j].to])
					{
						max = path[current[i]][j].cap;
						currentindex1 = current[i];
						currentindex2 = j;
					}
			}
			if (path[currentindex1][currentindex2].cap>flow[currentindex1])
				flow[path[currentindex1][currentindex2].to] = flow[currentindex1];
			else
				flow[path[currentindex1][currentindex2].to] = path[currentindex1][currentindex2].cap;
			flag[path[currentindex1][currentindex2].to] = true;
			current.push_back(path[currentindex1][currentindex2].to);
		}
		cout << "Scenario #" << c << endl;
		cout << "Minimum Number of Trips = " << (t + flow[d] - 2) / (flow[d] - 1) << endl;
		cout << endl;
	
	}
}