
#include <iostream>
#include <cmath>

using namespace std;

const int prime = 101;

int hash1(char P[], int m, int mod) {
    int hash = 0;
    for (int i = 0; i < m; i++) {
        hash = (hash * 27 + (P[i] - 'a' + 1)) % mod;
    }
    return hash;
}
int hash2(char P[], int m, int mod) {
    int hash = 0;
    for (int i = 0; i < m; i++) {
        hash = (hash * 27 + (P[i] - 'a' + 1) % mod) % mod;
    }
    return hash;
}

int main() {
    char T[1005], P[1005];
    cin.getline(T, 1000);
    cin.getline(P, 1000);
    int m = strlen(P);
    int n = strlen(T);
    int hp = hash2(P, m, prime);
    int ht = hash2(T, m, prime);
    int ind = -1;
    int mod_pow = 1;
    for (int i = 0; i < m - 1; i++) {
        mod_pow = (mod_pow * 27) % prime;
    }
    for (int i = 0; i <= n - m; i++) {
        if (hp == ht) {
            bool ok = true;
            for (int j = 0; j < m; j++) {
                if (P[j] != T[i + j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ind = i;
                break;
            }
        }
        if (i < n - m) {
            ht = ((ht - (T[i] - 'a' + 1) * mod_pow) * 27 + (T[i + m] - 'a' + 1)) % prime;
            if (ht < 0) ht += prime;
        }
    }
    if (ind == -1) cout << "not found";
    else cout << ind;
    return 0;
}