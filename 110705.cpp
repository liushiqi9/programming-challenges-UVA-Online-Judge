#include <iostream>
#include <cstring>
using namespace std;
int prime[3000000], ct;
bool notprime[10000001];
void summation(int n)
{
	int i, j, p, q;
	for (i = 0; prime[i] <= n / 4 && i<ct; i++)
		for (j = i; prime[j] <= (n-prime[i]) / 3 && j<ct; j++)
			for (p = j; prime[p] <= (n-prime[i]-prime[j]) / 2 && p<ct; p++)
				if (!notprime[n-prime[i] - prime[j] - prime[p]] )
					{
						cout << prime[i]<<" " << prime[j] <<" "<< prime[p]<<" " << n - prime[i] - prime[j] - prime[p] << endl;
						return;
					}
	cout << "Impossible."<<endl;
	return;
}
int main()
{
	int i, j, k, n,p,q;
	memset(notprime, false, sizeof(notprime));
	ct = 0;
	for (i = 2; i <= 10000000;i++)
		if (!notprime[i])
		{
			prime[ct] = i;
			ct++;
			for (j = i * 2; j <= 10000000; j = j + i)
				notprime[j] = true;
		}
	while (cin >> n)
	{
		summation(n);
	}
	return 0;
}