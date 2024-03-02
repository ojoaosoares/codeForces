#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

bool solve(ll k, ll n, ll chute) {

    ll max = -(chute - 1) + (chute * (k + (k - (chute - 1)))) / 2;
        
    if (n > max) return false;
    return true;

}

int main() { _

    ll n, k;
    cin >> n >> k;

    ll left = 0, right = k;

    while (left < right)
    {
        ll middle = (left + right) / 2;

        if (solve(k, n, middle)) right = middle;
        else left = middle + 1;

    }

    if (left == k) cout << -1 << '\n';
    else cout << left << '\n';

}