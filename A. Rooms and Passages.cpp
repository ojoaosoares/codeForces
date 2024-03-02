#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int main() { _

    int n;
    cin >> n;

    vector<int> pass(n), cards(n, 1);

    for (int i = 0; i < n; i++)
        cin >> pass[i];

    int left = 0, right = 0;

    while (left < n)
    {
        if (right < n && (cards[abs(pass[right]) - 1] > 0 || pass[right] < 0))
        {
            if (pass[right] < 0) 
                cards[abs(pass[right]) - 1]--;

            right++;
        }
            
        else
        {
            cout << right - left << ' ';

            if (pass[left] < 0)
                cards[abs(pass[left]) -1]++;
            
            left++;
        }
    }

    cout << '\n';
}
