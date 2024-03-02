#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

ll sqr(ll x)
{
    return x * x;
}

ll tri(ll x)
{
    return (x + 1) * x / 2;
}

ll solve(ll x, ll y, ll n, ll t)
{
    ll l = x - 1, r = n - x, u = y - 1, d = n - y;

    ll sum = t * t + (t + 1) * (t + 1);
    if (t > l) sum -= sqr(t - l);
    if (t > r) sum -= sqr(t - r);
    if (t > u) sum -= sqr(t - u);
    if (t > d) sum -= sqr(t - d);
    if (t > l + d) sum += tri(t - (l + d) - 1);
    if (t > l + u) sum += tri(t - (l + u) - 1);
    if (t > r + d) sum += tri(t - (r + d) - 1);
    if (t > r + u) sum += tri(t - (r + u) - 1);
    
    return sum;
}

int main() { _

    ll n, x, y, c;
    cin >> n >> x >> y >> c;

    ll left = 0, right = 2* n;

    while (left < right)
    {
        ll middle = (left + right) / 2;

        if (solve(x, y, n, middle) >= c) right = middle;
        else left = middle + 1;

    }

    cout << left << '\n';
}