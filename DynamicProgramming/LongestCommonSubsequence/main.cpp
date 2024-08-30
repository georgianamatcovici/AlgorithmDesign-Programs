#include <iostream>
#include <cstring>
using namespace std;

// formula: LCS[i][j]= LCS[i-1][j-1]+1, X[i]=Y[j]
//                     max{LCS[i-1][j], LCS[i][j-1]}

int main()
{   

	int i, j;
	char X[256], Y[256];
	int LCS[300][300];
	int n, m;

	cin >> X;
	cin >> Y;
	n = strlen(X);
	m = strlen(Y);
	for (i = 0; i <= n; i++)
		LCS[i][0] = 0;
	for (i = 0; i <= m; i++)
		LCS[0][i] = 0;

	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			if (X[i] == Y[j])
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			else
				LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
		}

	cout << LCS[n][m];

	return 0;
}