#include <iostream>

using namespace std;

int main()
{
	char S[500];
	cin >> S;
	int i = 0;
	int cnt = 0;
	while (i <= strlen(S) - 3)
	{
		if (S[i] == '1' && S[i + 1] == '0' && S[i + 2] == '1')
		{
			S[i + 2] = '0';
			cnt++;
			
	    }
		i++;
	}
	cout << cnt;



	return 0;
}