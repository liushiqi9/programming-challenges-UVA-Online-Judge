#include <iostream>
#include <cstring>
using namespace std;
int prime[10000], ct=0;
bool notprime[50000];
int size(int n, int prime)
{
	if (n < prime) return 0;
	else return n / prime + size(n / prime, prime);
}
bool divide(int n, int m)
{
	long long answer=1;
	int i, k;

	if (m == 1)
		return true;
	i = 0;
	while (m > 1 && i<ct)
	{
		k = 0;
		while (m%prime[i] == 0)
		{
			k++;
			m = m / prime[i];
		}
		if (k != 0 && size(n, prime[i]) < k)
			return false;
		i++;
	}
	if (m > 1 && size(n, m) < 1)
		return false;
	return true;
}
int main()
{
	int i, j, n, m, k;
	memset(notprime, false, sizeof(notprime));
	ct = 0;
	for (i = 2; i < 50000;i++)
		if (!notprime[i])
		{
			prime[ct] = i;
			ct++;
			for (j = i * 2; j < 50000; j = j + i)
				notprime[j] = true;
		}
	while (cin>>n>>m)
	{
		if (divide(n, m) && m)
			cout << m << " divides " << n << "!" << endl;
		else
			cout << m<<" does not divide " << n << "!" << endl;
	}
}