#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string s,tok;
	int i, j, k,n;
	vector<int> pancake;
	while (getline(cin, s))
	{
		stringstream ss(s);
		cout << s << endl;
		pancake.clear();
		while (getline(ss, tok, ' '))
		{
			pancake.push_back(stoi(tok));
		}
		n = pancake.size();
		while (!pancake.empty())
		{
			if (pancake.back() == *max_element(pancake.begin(), pancake.end()))
				pancake.pop_back();
			else
				if (pancake.front() == *max_element(pancake.begin(), pancake.end()))
				{
					cout << n-pancake.size()+1 << " ";
					reverse(pancake.begin(), pancake.end());
					pancake.pop_back();
				}
				else
				{
					cout <<n-distance(pancake.begin(), max_element(pancake.begin(), pancake.end())) << " " << n - pancake.size() + 1 << " ";
					reverse(pancake.begin(), max_element(pancake.begin(), pancake.end())+1);
					reverse(pancake.begin(), pancake.end());
					pancake.pop_back();
				}
		}
		cout << 0<<endl;
		

	}
}