#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

int main() { _

    ll datasets;
    cin >> datasets;

    for (ll i = 0; i < datasets; i++)
    {
        ll n, w;
        cin >> n >> w;

        ll bestProfit = 0 , currMin, globalMin, pi;

        cin >> currMin;
        globalMin = currMin;

        for (ll j = 1; j < n; j++)
        {
            cin >> pi;

            if (pi < currMin)
                currMin = pi;

            else
            {
                ll profit = pi - currMin;

                if (profit > bestProfit)
                {
                    globalMin = currMin;
                    bestProfit = profit;

                }
            }
        }

        cout << (ll) ( w / globalMin ) *  bestProfit<< '\n';
        
    }
    


    return 0;
}