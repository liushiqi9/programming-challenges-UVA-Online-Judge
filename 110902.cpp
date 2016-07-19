#include <iostream>
#include <vector>
#include <deque>
using namespace std;
struct edge
{
	int to, length;
};
void spfa(const int &begin, const vector<vector<edge>> &adjlist, vector<int > &dist, vector<int> path)
{
	int node = adjlist.size(), INF=0x7FFFFFFF;
	dist.assign(node, INF);
	path.assign(node, -1);
	deque<int> que(1, begin);
	vector<bool> flag(node, false);
	dist[begin] = 0;
	flag[begin] = true;
	while (!que.empty())
	{
		int now = que.front();
		que.pop_front();
		flag[now] = false;
		for (int i = 0; i < adjlist[now].size(); i++)
		{
			int next = adjlist[now][i].to;
			if (dist[now]<INF && dist[next]>dist[now] + adjlist[now][i].length)
			{
				dist[next] = dist[now] + adjlist[now][i].length;
				path[next] = now;
				if (!flag[next])
				{
					if (que.empty() || dist[next] < dist[que.front()])
						que.push_front(next);
					else que.push_back(next);
					flag[next] = true;
				}
			}
		}
	}
	return;
}
int readnumber()
{
	int i, k, a=0;
	for (i = 0; i < 4; i++)
	{
		cin >> k;
		a = a * 10 + k;
		
	}
	return a;
}
void addNode(int i, vector<vector<edge>> &adjlist)
{
	edge e;
	e.length = 1;
	e.to = (i / 1000 - 1+10) % 10 * 1000 + i % 1000;
	adjlist[i].push_back(e);
	e.to = (i / 100 % 10 - 1+10) % 10 * 100 + i % 100 + i / 1000 * 1000;
	adjlist[i].push_back(e);
	e.to = (i / 10 % 10 - 1+10) % 10 * 10 + i % 10 + i / 100 * 100;
	adjlist[i].push_back(e);
	e.to = (i % 10 - 1+10) % 10 + i / 10 * 10;
	adjlist[i].push_back(e);
	e.to = (i / 1000 + 1 + 10) % 10 * 1000 + i % 1000;
	adjlist[i].push_back(e);
	e.to = (i / 100 % 10 + 1 + 10) % 10 * 100 + i % 100 + i / 1000 * 1000;
	adjlist[i].push_back(e);
	e.to = (i / 10 % 10 + 1 + 10) % 10 * 10 + i % 10 + i / 100 * 100;
	adjlist[i].push_back(e);
	e.to = (i % 10 + 1 + 10) % 10 + i / 10 * 10;
	adjlist[i].push_back(e);
}
int main()
{
	vector<vector<edge>> adjlist(10000,vector<edge>());
	int i, j, k, n, m, t,begin,end;
	vector<int> dist, path, delpath;
	cin >> t;
	for (i = 0; i < 10000; i++)
		addNode(i, adjlist);
	while (t--)
	{
		begin = readnumber();
		end = readnumber();
		cin >> n;
		delpath.clear();
		for (i = 0; i < n; i++)
		{
			delpath.push_back(readnumber());
			adjlist[delpath[i]].clear();
		}
		spfa(begin, adjlist, dist, path);
		if (dist[end]!= 0x7FFFFFFF)
			cout << dist[end];
		else cout << -1;
		for (i = 0; i < n; i++)
			addNode(delpath[i],adjlist);
		cout << endl;

	}
}