#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int main() { _

    int n, s, k, x;
    cin >> n;

    while(n--)
    {
        cin >> s >> k;

        set<int> elementos;

        for (int i = 0; i < s; i++)
        {
            cin >> x;
            elementos.insert(x);
        }

        if (k< (int) elementos.size())
            cout << "-1\n" ;

        else
        {
            cout << s * k << '\n' ;

            for (int i = 0; i < s; i++) {

                for (auto x : elementos)
                    cout << x << ' ' ;
                for (int i = 0; i < k - (int) elementos.size(); i++)
                    cout << "1 " ;

            }
            cout << '\n' ;
        }

    }

}
