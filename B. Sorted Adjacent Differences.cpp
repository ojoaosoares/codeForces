#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int main() { _


    long long n, s, before, after;

    cin >> n;

    while (n--)
    {
        cin >> s;

        vector<long long> v(s);

        for (int i = 0; i < s; i++) cin >> v[i];

        sort(v.begin(), v.end());

        if(s % 2)
        {
            before = s/2;
            after = before + 1;
        }

        else
        {
            after = s/2;
            before = after - 1;
        }

        while(before >= 0 || after < s)
        {
            if(before >= 0) cout << v[before--] << " " ;

            if(after < s) cout << v[after++] << " " ;
        }

        cout << '\n' ;




    }



}
