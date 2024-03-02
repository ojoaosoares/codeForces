#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int main() { _

    int n;
    cin >> n;

    vector<pair<long, long>> horarios(n);

    for (int i = 0; i < n; i++)
        cin >> horarios[i].second >> horarios[i].first;

    sort(horarios.begin(), horarios.end());

    int cont = 0, last;

    for(int i = 0; i < n; i++)
        if(i == 0 ||  horarios[i].second > last)
        {
            last = horarios[i].first;
            cont++;
        }

    cout << cont << '\n';


}
