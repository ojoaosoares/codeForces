#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int main() { _

    int n;
    bool isPossible;
    string a, b, c;

    cin >> n;

    while(n--)
    {
        cin >> a >> b >> c;
        isPossible = true;

        for(int i = 0; i < c.length(); i++)
            if(c[i] != a[i] && c [i] != b[i])
            {
                isPossible = false;
                break;
            }

        if(isPossible) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }


}

