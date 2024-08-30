#include <iostream>
#include <algorithm>


using namespace std;

int main()
{
	float points[200], st, dr;
	int i, n, cnt;
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> points[i];
	sort(points+1, points + n+1);
	i = 1; cnt = 0;
	while (i <= n)
	{
		cnt++;
		st = points[i];
		dr = points[i] + 1;
		i++;
		while (i<n && points[i] <= dr) i++;

	}
	cout << cnt;


	return 0;
}