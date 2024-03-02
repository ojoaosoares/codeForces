#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

bool possible(vector<int> &v, int n, int per, double chute)
{
    double out = 0, in = 0;

    for (int i = 0; i < n; i++)
    {
        if ((double) v[i] >= chute) out += (((double) v[i] - chute) * ((double)(100 - per)/ 100));
        else in += (chute - (double) v[i]);
    }

    return (out >= in);
}

int main() { _

    int n, k;

    cin >> n >> k;

    vector<int> cells(n);

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> cells[i];
        sum += cells[i];
    }

    double left = 0, right = sum / (double) n;


    for (int i = 0; i < 300; i++)
    {
        double middle = (left + right) / 2;

        if(possible(cells, n, k, middle)) left = middle;
        else right = middle;

    }

    cout << fixed << setprecision(9);
    cout << left << '\n';


}