#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

bool possible(ll x, ll chute) {
    return (x >= chute + 2);
}

int main() { _

    ll n;
    cin >> n;

    vector<vector<ll>> jedis(n, vector<ll>(3));

    vector<ll> defenses(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> jedis[i][0] >> jedis[i][1] >> jedis[i][2];
        
        defenses[i] = min(jedis[i][0], jedis[i][1]) +
        min(max(jedis[i][0], jedis[i][1]), jedis[i][2]);
    }
    
    sort(defenses.begin(), defenses.end());

    for (ll i = 0; i < n; i++)
    {
        ll atack = jedis[i][0] + jedis[i][1] + jedis[i][2];
        
        ll left = 0, right = n;

        while (left < right)
        {
            ll middle = (left + right + 1) / 2;

            if (possible(atack, defenses[middle - 1])) left = middle;
            else right = middle - 1;
        }

        ll defense = atack - max(max(jedis[i][0],jedis[i][1]), jedis[i][2]);

        if(possible(atack, defense)) left--;
        
        cout << left << ' ';
    }

    cout << '\n';

}