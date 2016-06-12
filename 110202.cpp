#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int Flush(char c[][2])
{
	if ( ( c[0][1] == c[1][1]) && c[1][1] == c[2][1] && c[2][1] == c[3][1] && c[3][1] == c[4][1])
		return 1;
	else return 0;

}
int Straight(int*a)
{
	if (a[1] + 1 == a[2] && a[2] + 1 == a[3] && a[3] + 1 == a[4] && a[0] + 1 == a[1])
		return 1;
	else return 0;
}
int pairC(int *a)
{
	if (a[0] == a[1])
		return a[0];
	if (a[1] == a[2])
		return a[1];
	if (a[2] == a[3])
		return a[2];
	if (a[3] == a[4])
		return a[3];
	return 0;
}
int Tpair(int *a)
{
	if (a[0] == a[1] && a[2] == a[3])
		return a[2]*15+a[0];
	if (a[0] == a[1] && a[3] == a[4])
		return a[3]*15+a[0];
	if (a[1] == a[2] && a[3] == a[4])
		return a[3]*15+a[1];
	return 0;
}
int three(int *a)
{
	if (a[0] == a[1] && a[1] == a[2])
		return a[0];
	if (a[3] == a[2] && a[1] == a[2])
		return a[1];
	if (a[4] == a[3] && a[3] == a[2])
		return a[2];
	return 0;
}
int four(int *a)
{
	if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3])
		return a[0];
	if (a[4] == a[3] && a[1] == a[2] && a[2] == a[3])
		return a[1];
	return 0;
}
int fullhouse(int *a)
{
	if (a[0] == a[1] && a[3] == a[4])
	{
		if (a[1] == a[2]) return a[1];
		if (a[2] == a[3]) return a[2];
	}
	return 0;
}
int SFlush(char c[][2], int* a)
{
	if (Flush(c))
		return Straight(a);
	else return 0;

}
int main() 
{

	//ofstream myfile;
	//myfile.open("example.txt");
	char p1[5][2], p2[5][2];
	int a1[5], a2[5];
	char tmp;
	int i;
	long long score1, score2;
	while (cin >> p1[0][0] >> p1[0][1])
	{
		for (i = 1; i < 5; i++)
			cin >> p1[i][0] >> p1[i][1];
		for (i = 0; i < 5; i++)
			cin >> p2[i][0] >> p2[i][1];
		for (i = 0; i < 5; i++)
		{
			if (p1[i][0] >= '2' && p1[i][0] <= '9')
				a1[i] = p1[i][0] - '0';
			switch (p1[i][0])
			{
				case 'T':
					a1[i] = 10;
					break;
				case 'J':
					a1[i] = 11;
					break;
				case 'Q':
					a1[i] = 12;
					break;
				case 'K':
					a1[i] = 13;
					break;
				case 'A':
					a1[i] = 14;
					break;
				default:
					break;
			}
			if (p2[i][0] >= '2' && p2[i][0] <= '9')
				a2[i] = p2[i][0] - '0';
			switch (p2[i][0])
			{
			case 'T':
				a2[i] = 10;
				break;
			case 'J':
				a2[i] = 11;
				break;
			case 'Q':
				a2[i] = 12;
				break;
			case 'K':
				a2[i] = 13;
				break;
			case 'A':
				a2[i] = 14;
				break;
			default:
				break;
			}
		}
		//transform to numbers
		sort(a1,a1+5);
		sort(a2,a2+5);
		
		score1 = 0;
		score1 +=SFlush(p1,a1) ;
		score1 = score1 * 15 + four(a1);
		score1 = score1 * 15 + fullhouse(a1);
		score1 = score1 * 15 + Flush(p1);
		if (score1 > 0 && score1 < 15)
		{
			score1 = score1 * 15 * 15 * 15 * 15;
			score1 = score1 * 15 + a1[4];
			score1 = score1 * 15 + a1[3];
			score1 = score1 * 15 + a1[2];
			score1 = score1 * 15 + a1[1];
			score1 = score1 * 15 + a1[0];
		}
		else 
		{
			score1 = score1 * 15 + Straight(a1);
			score1 = score1 * 15 + three(a1);
			score1 = score1 * 15*15 + Tpair(a1);
			score1 = score1 * 15 + pairC(a1);
			score1 = score1 * 15 + a1[4];
			score1 = score1 * 15 + a1[3];
			score1 = score1 * 15 + a1[2];
			score1 = score1 * 15 + a1[1];
			score1 = score1 * 15 + a1[0];
		}
		
		score2 = 0;
		score2 += SFlush(p2, a2);
		score2 = score2 * 15 + four(a2);
		score2 = score2 * 15 + fullhouse(a2);
		score2 = score2 * 15 + Flush(p2);
		if (score2 > 0 && score2 < 15)
		{
			score2 = score2 * 15 * 15 * 15 * 15;
			score2 = score2 * 15 + a2[4];
			score2 = score2 * 15 + a2[3];
			score2 = score2 * 15 + a2[2];
			score2 = score2 * 15 + a2[1];
			score2 = score2 * 15 + a2[0];
		}
		else
		{

			score2 = score2 * 15 + Straight(a2);
			score2 = score2 * 15 + three(a2);
			score2 = score2 * 15*15 + Tpair(a2);
			score2 = score2 * 15 + pairC(a2);
			score2 = score2 * 15 + a2[4];
			score2 = score2 * 15 + a2[3];
			score2 = score2 * 15 + a2[2];
			score2 = score2 * 15 + a2[1];
			score2 = score2 * 15 + a2[0];
		}
		if (score1 > score2)
			cout << "Black wins."<<endl;
		else if (score2 > score1)
			 cout << "White wins."<<endl;
		else cout << "Tie."<<endl;


	}
}