#include <iostream>
#include <cmath>
using namespace std;
int n, f[11], v[11], gasit = 0;

int ok(int k)
{
    int i;
    for (i = 1; i < k; i++)
    {
        if (k - i == abs(v[k] - v[i])) return 0;
    }
    return 1;
}

void afisare()
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            if (v[i] == j) cout << "* ";
            else cout << "_ ";
        cout << endl;
    }


}

void back(int k)
{
    int i;
    if (gasit == 0)
    {
        for (i = 1; i <= n; i++)
        {
            if (f[i] == 0)
            {
                f[i] = 1;
                v[k] = i;
                if (ok(k) == 1)
                {
                    if (k < n) back(k + 1);
                    else { afisare(); gasit = 1; }
                }

                f[i] = 0;
            }
        }

    }
}

int main()
{
    cin >> n;
    back(1);

    return 0;
}