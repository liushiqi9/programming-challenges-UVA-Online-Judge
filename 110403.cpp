//This program got AC at UVA judge but not at the programming challenge judge

#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int main()
{
	int t, i, j, n, time, cost1, cost2;
	vector<int> speed;
	cin >> t;
	while (t--)
	{
		cin >> n;
		
		speed.clear();
		while (n--)
		{
			cin >> j;
			speed.push_back(j);
		}
		n = speed.size();
		if (n == 1)
		{
			cout << speed[0] << endl << speed[0] << endl;
			if (t != 1)
				cout << endl;
			continue;
		}
		sort(speed.begin(), speed.end());
		time = speed[1];
		for (i = n - 1; i >= 3; i = i - 2)
		{
			cost1 = speed[1] * 2 + speed[0] + speed[i];
			cost2 = speed[i] + speed[i - 1] + speed[0] * 2;
			if (cost1 < cost2)
				time += cost1;
			else
				time += cost2;
		}
		if (n % 2 != 0)
		{
			time += speed[0] + speed[2];
		}
		cout << time << endl;
		for (i = n - 1; i >= 3; i = i - 2)
		{
			cost1 = speed[1] * 2 + speed[0] + speed[i];
			cost2 = speed[i] + speed[i - 1] + speed[0] * 2;
			if (cost1 < cost2)
			{
				cout << speed[0] << " " << speed[1] << endl;
				cout << speed[0] << endl;
				cout << speed[i-1] << " " << speed[i] << endl;
				cout << speed[1] << endl;
			}
			else
			{
				cout << speed[0] << " " << speed[i-1] << endl;
				cout << speed[0] << endl;
				cout << speed[0] << " " << speed[i] << endl;
				cout << speed[0] << endl;
			}
		}
		if (n % 2 != 0)
		{
			cout << speed[0] << " " << speed[1] << endl;
			cout << speed[0] << endl;
			cout << speed[0] << " " << speed[2] << endl;
		}
		else
		{
			cout << speed[0] << " " << speed[1] << endl;
		}
		if (t != 0)
			cout << endl;

	}
}