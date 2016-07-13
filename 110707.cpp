#include <iostream>
using namespace std;
long long n1, n2, gcd;
struct represent {
	long long c1;
	long long c2;
};
long long calgcd(long long n1,long long n2)
{
	if (n1%n2 == 0)
		return n2;
	else return calgcd(n2, n1 - (n1 / n2)*n2);
}
represent find(represent r1, represent r2)
{
	long long value1, value2;
	represent r3;
	value1 = r1.c1*n1 + r1.c2*n2;
	value2 = r2.c1*n1 + r2.c2*n2;
	r3.c1 = r1.c1 - r2.c1*(value1 / value2);
	r3.c2 = r1.c2 - r2.c2*(value1 / value2);
	if (value1 - (value1 / value2)*value2 == gcd)
		return r3;
	if (value1 - (value1 / value2)*value2 == 0)
		return r2;
	return find(r2, r3);
}
int main() 
{
	long long m1, m2, c1, c2,n,i,j,offset1,offset2;
	represent r1, r2, sol;
	while (cin >> n && n!=0)
	{
		cin >> c1 >> n1;
		cin >> c2 >> n2;
		r1.c1 = 1;
		r1.c2 = 0;
		r2.c1 = 0;
		r2.c2 = 1;
		if (n1 < n2)
		{
			gcd = calgcd(n2, n1);
			if (n%gcd != 0)
			{
				cout << "failed" << endl;
				continue;
			}
			sol=find(r2, r1);

		}
		else
		{
			gcd = calgcd(n1, n2);
			if (n%gcd != 0)
			{
				cout << "failed" << endl;
				continue;
			}
			sol = find(r1, r2);
		}
		sol.c1 *= n / gcd;
		sol.c2 *= n / gcd;
		if ((double)c1 / n1 < (double)c2 / n2)
		{
			offset1=(sol.c2) / (n1 / gcd);
			offset2 = (-sol.c2 + n1 / gcd - 1) / (n1 / gcd);
			if (sol.c2 < 0)
			{
				sol.c2 += offset2*(n1 / gcd);
				sol.c1 -= offset2*(n2 / gcd);
			}
			else
			{
				sol.c2 -= offset1*(n1 / gcd);
				sol.c1 += offset1*(n2 / gcd);
			}
		}
		else 
		{
			offset1 = (sol.c1) / (n2 / gcd);
			offset2= (-sol.c1+ n2 / gcd-1) / (n2 / gcd);
			if (sol.c1<0)
			{ 
				sol.c1 += offset2*(n2 / gcd);
				sol.c2 -= offset2*(n1 / gcd);
			}
			else
			{
				sol.c1 -= offset1*(n2 / gcd);
				sol.c2 += offset1*(n1 / gcd);
			}
		}
		if (sol.c1<0 || sol.c2<0)
			cout << "failed" << endl;
		else
		cout << sol.c1 << " " << sol.c2 << endl;

	}
	
}