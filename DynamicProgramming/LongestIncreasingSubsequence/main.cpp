#include <iostream>

using namespace std;
int n, v[500], k, LIS[500];
int main()
{
	int i, j;
	int pmax;
	int prev[500];
	int vp[500];
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> v[i];
	k = 0;
	pmax = 0;
	for (i = 1; i <= n; i++)
	{
		LIS[i] = 1;
		prev[i] = 0;
		for (j = 1; j < i; j++)
		{
			if (v[j]<v[i] && (LIS[j] + 1)>LIS[i]) {
				LIS[i] = LIS[j] + 1;
				prev[i] = j;
			}
		}
		if (LIS[i] > LIS[pmax]) { pmax = i; }

	}
	k = LIS[pmax];
	for (i = pmax; i > 0; i = prev[i]) { vp[LIS[i]] = v[i]; }
	cout << "The lenght of LIS: " << k << endl;
	cout << "The elements:\n ";
	for (i = 1; i <= k; i++)
	{
		cout << vp[i] << ' ';
	}








	return 0;
}