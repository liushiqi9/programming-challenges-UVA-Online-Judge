#include <iostream>
#include <map>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <math.h>
using namespace std;
void split(string s, vector<int >& a)
{
	string::size_type pos1, pos2;
	pos2 = s.find(':');
	pos1 = 0;
	while (string::npos != pos2)
	{
		a.push_back(stoi(s.substr(pos1, pos2 - pos1)));
		pos1 = pos2 + 1;
		pos2 = s.find(':', pos1);
	}
	if (pos1 != s.length())
		a.push_back(stoi(s.substr(pos1)));
}
int main()
{
	map<string, vector<vector<int>>> r;
	double rate[24];
	int s, t, i, j, k;
	cin >> t;
	vector<int> time, record;
	string plate, times, state, dist;
	while (t--)
	{
		r.clear();
		for (i = 0; i < 24; i++)
			cin >> rate[i];
		string inputString;
		getline(cin, inputString);
		getline(cin, inputString);
		while (!inputString.empty())
		{
			stringstream inpuS(inputString);
			inpuS >> plate >> times >> state >> dist;
			time.clear();
			record.clear();
			split(times, time);
			record.push_back(((time[1] * 24) + time[2]) * 60 + time[3]);
			if (state == "enter")
				record.push_back(1);
			else record.push_back(0);
			record.push_back(stoi(dist));
			r[plate].push_back(record);
			getline(cin, inputString);
		}
		for (map<string, vector<vector<int>>>::iterator it = r.begin(); it != r.end(); it++)
			sort(it->second.begin(), it->second.end());
		for (map<string, vector<vector<int>>>::iterator it = r.begin(); it != r.end(); it++)
		{
			double cost = 2;
			for (vector<vector<int>>::iterator it2 = (it->second).begin(); it2 != (it->second).end(); it2++)
			{
				if ((*it2)[1] == 1 && (it2 + 1) != it->second.end() && (*(it2 + 1))[1] == 0)
				{
					cost += abs((*(it2 + 1))[2] - (*it2)[2]) *rate[(*it2)[0] % (24 * 60) / 60] / 100.0 + 1;
					it2++;
				}
			}
			if (cost>2)
			cout << it->first << " $" << setprecision(2) << fixed << cost << endl;
		}
		if (t) cout << endl;
	}
}