#include <bits/stdc++.h>

using namespace std;


#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int main() { _

    int t;
    cin >> t;


    while (t--)
    {
        long long n, k;
        cin >> n >> k;

        long long left = 1, right = n*k;

        while (left < right)
        {
            long long middle = (left + right)/2;

            if(middle/n <= middle - k)
                right = middle;
            else
                left = middle + 1;

        }

        cout << left << '\n';
    }
}

