#include <iostream>

using namespace std;

int n, m;
int G[200][200];
int MIS[200], used[200];

bool ok(int k)
{
	for (int i = 1; i < k; i++)
		if (G[MIS[i]][MIS[k]] == 1)
			return false;
	return true;
}

int maxim = 0, final[200];
void bkt(int k)
{
	for (int i = 1; i <= n; i++)
	{
		if (!used[i])
		{
			used[i] = 1;
			MIS[k] = i;
			if (ok(k))
			{
				if (k > maxim)
					maxim = k;
				memcpy(final, MIS, sizeof(MIS));
				bkt(k + 1);
			}
			used[i] = 0;
			

	}

    }
}
int x, y;
int main()
{
	int x, y;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y;
		G[x][y] = 1;
		G[y][x] = 1;
	}
	bkt(1);
	for (int i = 1; i <= maxim; i++)
		cout << final[i]<<' ';
	return 0;
}