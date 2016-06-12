#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
	int i, j, k, t, count,p,n;
	vector<string> paper,current,next;
	map<string, vector<string>> relation;
	map<string, int> score;
	string tok;
	string s,a;
	cin >> t;
	count = 0;
	while (count < t)
	{
		count++;
		current.clear();
		next.clear();
		cin >> p >> n;
		getline(cin, s);
		while (p--)
		{	
			paper.clear();
			getline(cin, s);
			stringstream ss(s);
			while (getline(ss, tok, ':'))
			{
				paper.push_back(tok);
			}
			s = paper.front();
			paper.clear();
			stringstream ss1(s);
			while (getline(ss1, tok, ','))
			{
				paper.push_back(tok);
			}
			for (i = 0; i < paper.size() / 2; i++)
			{
				paper[i] = paper[i * 2] + "," + paper[i * 2 + 1];
				std::string::iterator end_pos = std::remove(paper[i].begin(), paper[i].end(), ' ');
				paper[i].erase(end_pos, paper[i].end());
			}
			for (i = 0; i < paper.size(); i++)
				paper.pop_back();
			//for (i = 1; i < paper.size(); i++)
			//	paper[i] = paper[i].substr(1, paper[i].length()-1);
			for (vector<string>::iterator it = paper.begin(); it != paper.end();it++)
			{
				if (relation.find(*it) == relation.end())
				{
					relation[*it];
					for (vector<string>::iterator it2 = paper.begin(); it2 != paper.end(); it2++)
						if (it2 != it && std::find(relation[*it].begin(), relation[*it].end(),*it2)== relation[*it].end())
							relation[*it].push_back(*it2);
				}
				else
				{
					for (vector<string>::iterator it2 = paper.begin(); it2 != paper.end();it2++)
						if (it2 != it && std::find(relation[*it].begin(), relation[*it].end(), *it2) == relation[*it].end())
							relation[*it].push_back(*it2);
				}
			}
		}
		current.push_back("Erdos,P.");
		score["Erdos,P."] = 0;
		while (!current.empty())
		{
			next.clear();
			for (vector<string>::iterator it = current.begin(); it != current.end();it++)
			{
				for (vector<string>::iterator it2 = relation[*it].begin(); it2 != relation[*it].end();it2++)
					if (score.find(*it2) == score.end())
					{
						score[*it2] = score[*it] + 1;
						next.push_back(*it2);
					}

			}
			current = next;
		}
		cout << "Scenario " << count << endl;
		while (n--)
		{
			getline(cin, s);
			cout << s<<" ";
			std::string::iterator end_pos = std::remove(s.begin(), s.end(), ' ');
			s.erase(end_pos, s.end());
			if (score.find(s) != score.end())
				cout << score[s]<< endl;
			else
				cout << "infinity" << endl;
		}

	}
}