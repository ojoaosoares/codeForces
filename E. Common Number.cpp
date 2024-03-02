#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);


// ll solve(ll chute, ll maximum)
// {
//     ll i, total;

//     if (chute % 2) { i = 1, total = 1; }

//     else { i = 0, total = 0; }

//     while (chute * pow(2, i) <= maximum)
//     {
//         if((chute * pow(2, i)) + 1 <= maximum)
//             total += solve((chute * pow(2, i)) + 1, maximum);

//         total++;
//         i++;   
//     }

//     return total;
// } TME


// ll solve (ll chute, ll maximum)
// {
//     set<int> reg;
//     reg.insert(chute);

//     ll total = 1;
//     for (ll i = chute; i < maximum; i++)
//     {
//         ll x = i + 1;

//         if (x % 2) x--;
//         else x /= 2;

//         if (reg.find(x) != reg.end())
//         {
//             reg.insert(i + 1);
//             total++;
//         }        
//     }

//     return total;
// } TME and TLE

bool solve (ll chute, ll maximum, ll wanted)
{
    ll large, nodes, i;

    if (chute&1)
    {
        large = chute;
        nodes = 1;
        i = 1;

        while (large < maximum)
        {
            nodes += pow(2,i);
            large += large + 1;
            i++;
        }
    }

    else
    {
        large = chute + 1;
        nodes = 2;
        i = 2;

        while (large < maximum)
        {
            nodes += pow(2,i);
            large += large + 1;
            i++;
        }
    }

    ll remove, lower_bound = large - (long long) pow(2, i - 1);
    if (lower_bound < maximum) remove = large - maximum;
    else remove = pow(2, i - 1);

    return (nodes - remove) >= wanted;

}

int main() { _
    
    ll n, k;
    cin >> n >> k;

    ll left = 1, right = n;

    while (left < right)
    {
        ll middle = (left + right + 1) / 2;
        if (solve(middle, n, k)) left = middle;
        else if (solve(middle + 1, n, k)) left = middle + 1;
        else right = middle - 1;
    }

    cout << left << '\n';


}