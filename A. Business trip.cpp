#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int main() { _

    int minimum;
    vector<int> months(12);

    cin >> minimum;

    for (int i = 0; i < 12; i++) cin >> months[i];

    if(minimum <= 0)
    {
        cout << 0 << '\n';
        return 0;
    }

    sort(months.begin(), months.end(), greater<int>());

    for(int i = 0; i < 12; i++)
    {
        minimum -= months[i];

        if(minimum <= 0) {
            cout << i + 1 << '\n';
            return 0;

        }
    }

    cout << -1 << '\n';

    return 0;

}

