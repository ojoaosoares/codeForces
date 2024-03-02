#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll pa_sum(ll n)
{
    return ((1 + n) * n) / 2;
}

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() { _

    ll n;
    cin >> n;

    vector<ll> arr(n);

    for (ll i = 0; i < n; i++)
        cin >> arr[i];

    ll sum = 0, left = 0, right = 1;

    while (left < n)
    {
        if (right < n && arr[left] == arr[right]) right++;
        
        else
        {
            sum += pa_sum(right - left);
            left = right; right++;
        }
    }

    cout << sum << '\n';
}
