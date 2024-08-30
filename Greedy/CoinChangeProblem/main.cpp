#include <iostream>

using namespace std;

int n;
int main()
{
	cin >> n;
	int v[8] = { 0 };
	int banc[] = { 1, 5, 10, 20, 50, 100, 200, 500 };
	int i = 7;
	while (i >= 0 && n > 0)
	{
		if (n >= banc[i])
		{
			cout << banc[i] << ' ';
			v[i] += n / banc[i];
			n = n % banc[i];
			cout << n << endl;
		}
		 i--;
	}
	for (i = 7; i >= 0; i--)
		printf("We use %d %d lei banknotes\n", v[i], banc[i]);


	return 0;
}