#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll b_number, n_number, e_number;
ll b_strength, n_strength, e_strength;

bool check(vector<ll> &k, ll &chute)
{
    ll b = b_number, n = n_number, e = e_number;

    if(n_strength + n_strength >= b_strength + e_strength)
    {
        for (ll &x : k)
        {
            if (b >= 2 && b_strength * 2 * x >= chute) b -= 2;
            
            else if (b >= 1 && n >= 1 && (b_strength + n_strength) * x >= chute)
            {
                b--; 
                n--;
            } 

            else if (b >= 1 && e >= 1 && (b_strength + e_strength) * x >= chute)
            {
                b--;
                e--;
            }

            else if (n >= 2 && n_strength * 2 * x >= chute) n -= 2;

            else if (n >= 1 && e >= 1 && (n_strength + e_strength) * x >= chute)
            {
                n--;
                e--;
            }

            else if (e >= 2 && e_strength * 2 * x >= chute) e -= 2;


            else return false;
        }
    }

    else
    {
        for (ll &x : k)
        {
            if (b >= 2 && b_strength * 2 * x >= chute) b -= 2;
            
            else if (b >= 1 && n >= 1 && (b_strength + n_strength) * x >= chute)
            {
                b--; 
                n--;
            } 

            else if (n >= 2 && n_strength * 2 * x >= chute) n -= 2;

            else if (b >= 1 && e >= 1 && (b_strength + e_strength) * x >= chute)
            {
                b--;
                e--;
            }

            else if (n >= 1 && e >= 1 && (n_strength + e_strength) * x >= chute)
            {
                n--;
                e--;
            }

            else if (e >= 2 && e_strength * 2 * x >= chute) e -= 2;


            else return false;
        }
    }

    return true;
}




#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int main() { _

    cin >> b_number >> n_number >> e_number;
    cin >> b_strength >> n_strength >> e_strength;

    ll kayak_number = (b_number + n_number + e_number) / 2;
    vector<ll> kayaks(kayak_number);

    for (ll i = 0; i < kayak_number; i++) cin >> kayaks[i];

    sort(kayaks.begin(), kayaks.end());

    ll left = 2, right = 1e9 + 10;

    while (left < right)
    {
        ll middle = (left + right + 1) / 2;

        if (check(kayaks, middle)) left = middle;
        else right = middle - 1;

    }

    cout << left << '\n';   
}