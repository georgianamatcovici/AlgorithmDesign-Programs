#include <iostream>

using namespace std;
int profit[500], price[500];
int n;
int i, j;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> profit[i];
	memcpy(profit, price, sizeof(price));
	profit[0] = 0; 
	for (j = 1; j <= n; j++) {
	for (i = 1; i <= j; i++) { 
			if (profit[j] < price[i] + profit[j - i]) {
				profit[j] = price[i] + profit[j - i];
			
			}
		}
	}
    cout<<profit[n];

	return 0;
}