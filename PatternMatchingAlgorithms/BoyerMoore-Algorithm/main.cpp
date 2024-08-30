#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void calc_failure(char P[500], int f[500])
{
	int i, m, k;
	m = strlen(P);
	f[0] = -1;
	for (i = 1; i <= m; i++)
	{
		k = f[i - 1];
		while (k >= 0 && P[k] != P[i - 1])
		{
			k = f[k];
		}
		if (k == -1) f[i] = 0;
		else f[i] = k + 1;
	}
}

int main()
{
	char T[1005], P[1005], R[1005];
	int BC[27], GS[1005], f[1005], g[1005];
	int i, k, n, m, shiftbc, shiftgs;
	int nr_comp = 0;

	cin.getline(T, 1000);
	cin.getline(P, 1000);

	n = strlen(T);
	m = strlen(P);


	i = 0; k = 0;
	for (i = 0; i <= 1; i++)
		BC[i] = -1;
	for (i = 0; i < m; i++)
		BC[P[i] - '0'] = i;

	strcpy_s(R, P);
	_strrev(R);
	calc_failure(P, f);
	calc_failure(R, g);
	int j;
	for (i = 0, j = m; i <= j; i++, j--)
		swap(g[i], g[j]);
	for (i = 0; i < m; i++)
		GS[i] = -(m - i - f[m]);
	for (i = 0; i < m; i++)
	{
		int l = g[i];
		GS[m - l] = i;
	}

	i = 0; k = 0; nr_comp = 0;
	while (i <= n - m && k < m)
	{
		nr_comp++;
		if (T[i + m - 1 - k] == P[m - 1 - k])
		{
			k++;
		}
		else
		{
			shiftbc = m - k - 1 - BC[T[i + m - 1 - k] - '0'];
			shiftgs = m - k - GS[m - k];
			i += max(shiftbc, shiftgs);
			/*if (shiftbc == shiftgs) cout << "both\n";
			else if (max(shiftbc, shiftgs) == shiftbc) cout << "bad charcater\n";
			else cout << " good suffix\n";*/
			k = 0;
		}
	}

	if (k == m)
		cout << "Found at index: " << i;
	else cout << "not found";
	return 0;
}