#include <iostream>
#include <string.h>

using namespace std;
char P[300], T[300];
int n, m;

int main()
{
	cin.getline(T, 300);
	cin.getline(P, 300);
	n = strlen(T);
	m = strlen(P);
	int f[50] = { 0 };
	f[0] = -1;
	int k = 0;
	for (int i = 1; i < m; ++i)
	{
		k = f[i - 1];
		while (k >= 0 && P[k] != P[i - 1])
		{
			k = f[k];
		}
		if (k == -1)
			f[i] = 0;
		else f[i] = k + 1;

	}
	int i = 0;
	k = 0;

	while (i <= n - m && k < m)
	{
		if (T[i + k] == P[k])
		{
			k++;

		}
		else if (k == 0)
		{
			i = i + 1;
		}
		else
		{
			i = i + k - f[k];
			k = f[k];
		}
	}


	if (k == m)
		cout << "Pattern found at index: " << i;
	else
		cout << "Pattern not found";
	return 0;
}