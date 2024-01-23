#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int main() { _

    int n, l, pares = 0;

    map<int,int> lados;

    cin >> n;

    while (n--)
    {
        cin >> l;

        if(lados.find(l) != lados.end()) lados[l]++;

        else lados.insert({l,1});
    }

    for (pair<int,int> p : lados) pares += p.second / 2;

    cout << pares / 2 << '\n' ;

    return 0;
}
