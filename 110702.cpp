#include <iostream>
using namespace std;
bool Prime(int n)
{
	int i = 3;
	if (n % 2 == 0) return false;
	while (i*i < n)
	{
		if (n%i == 0)
			return false;
		i=i+2;
	}
	return true;
}
int Fastexp(int a, int n, int m)
{
	int answer=1;
	unsigned int exp[100];
	int i, count;
	exp[0] = 1;
	exp[1] = a;
	i = 1;
	count = 1;
	while (i * 2 <= n)
	{
		count++;
		i = i * 2;
		exp[count] = (exp[count - 1] * exp[count - 1]) % m;
	}
	while (n != 0)
	{
		if (n >= i)
		{
			n = n - i;
			answer = (answer*exp[count]) %m;
		}
		i = i / 2;
		count--;
	}
	return answer;
}
bool Carmichael(int n)
{
	int a = 2,exp,i;
	while (a <= n - 1)
	{
		exp = 1;
		exp = Fastexp(a,n,n) %n;
		if (exp != a) return false;
		a++;
	}
	return true;
}
int main()
{
	int i, j, k, n;
	while (cin >> n &&n != 0)
	{
		if (!Prime(n) && Carmichael(n))
			cout << "The number " << n << " is a Carmichael number." << endl;
		else
			cout << n << " is normal." << endl;		
	}
}