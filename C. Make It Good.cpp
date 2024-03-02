#include <bits/stdc++.h>

using namespace std;


#define _ ios_base::sync_with_stdio(0); cin.tie(0);


bool possible(vector<int> &v, int chute, int max)
{
    int left_max = chute;
    for (int i = chute + 1; i < max; i++)
    {
        if(v[i] >= v[i - 1]) left_max = i;
        else break;
    }

    int right_max = max - 1;
    for (int j = max - 2; j >= chute; j--)
    {
        if(v[j] >= v[j + 1]) right_max = j;
        else break;
    }

    return left_max >= right_max;
}

int main() { _

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int left = 0, right = n;
        while (left < right)
        {
            int middle = (left + right) / 2;

            if(possible(arr, middle, n)) right = middle;
            else left = middle + 1;

        }

        cout << left << '\n';

    }
}

