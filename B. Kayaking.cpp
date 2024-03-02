#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int main() { _

    int n;
    cin >> n;

    vector<int> weights(2*n);

    for (int i = 0; i < 2*n; i++)
        cin >> weights[i];

    sort(weights.begin(), weights.end());

    int minimum = INT_MAX;

    for (int i = 0; i < 2*n; i++)
    {
        for (int j = i + 1; j < 2*n; j++)
        {
            int sum = 0;

            bool subtrair = false;
            int first_pair;

            for (int k = 2*n - 1; k >= 0; k--)
            {
                if (k == i || k == j) continue;

                if (subtrair)
                {
                    sum += first_pair - weights[k];
                    subtrair = false;
                }

                else
                {
                    first_pair = weights[k];
                    subtrair = true;
                }

                if(sum >= minimum) break;
            }

            minimum = min(sum, minimum);
        }
    }

    cout << minimum << '\n';


}