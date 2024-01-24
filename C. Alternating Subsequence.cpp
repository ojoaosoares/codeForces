#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

bool sameSign(long long a, long long b)
{
    return (a * b) > 0;
}

int main() { _

    long long n, s;
    cin >> n;

    while(n--)
    {

        cin >> s;
        vector<long long> sequence(s);

        for (int i = 0; i < s; i++)
            cin >> sequence[i];

        long long maximo, sum = 0;

        for (int i = 0; i < s; i++)
        {
            if (i == 0) maximo = sequence[i];

            if (sameSign(maximo, sequence[i])) maximo = max(maximo, sequence[i]);

            else
            {
                sum += maximo;
                maximo = sequence[i];
            }
        }

        sum += maximo;

        cout << sum << '\n';
    }
}
