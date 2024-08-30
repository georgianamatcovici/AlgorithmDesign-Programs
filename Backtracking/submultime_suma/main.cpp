#include <iostream>

using namespace std;
int n, p;
int sol[200], s[200];
int used[200];

void afis(int k)
{
    for (int i = 1; i <= k; i++)
        cout << sol[i] << ' ';
    cout << "\n";
    exit(0);

}

void bkt(int k, int sum)
{
        for (int i = 1; i <=n; i++)
        {
            if (!used[i])
            {
                used[i] = 1;
                sol[k] = s[i];
                if (sum + s[i] == p) afis(k);
                else if(sum+s[i]<p)
                bkt(k + 1, sum+s[i]);
                used[i] = 0;
               


            }

        }

}

int main()
{
    int i;
    cin >> n >> p;
    for (i = 1; i <= n; i++)
        cin >> s[i];
    

    bkt(1, 0);

    return 0;
}