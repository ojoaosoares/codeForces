#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int interact (vector<int> &v) {

if (v.size() <= 0) return 0;

    cout << "? " << v.size() << ' ';

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';

    cout << '\n';
    cout.flush();

    int maximum;
    cin >> maximum;

    return maximum;
}

vector<int> get_complement(vector<int> &v, int n)
{
    vector<int> ans, oc(n + 1, 0);

    for (int i : v)
        oc[i] = 1;


    for (int i = 1; i <= n; i++)
        if (!oc[i]) ans.push_back(i);

    return ans;
}

bool solve(vector<int> &ask, int maximum)
{   
    return (interact(ask) == maximum);
}

int main() { _

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<vector<int>> subsets(k);

        for (int i = 0; i < k; i++)
        {
            int c;
            cin >> c;
            
            subsets[i].resize(c);

            for (int j = 0; j < c; j++)
                cin >> subsets[i][j];
        }

        vector<int> ask(n);

        for (int i = 1; i <= n; i++)
            ask[i - 1] = i;

        int maximum = interact(ask);

        int left = 0, right = k - 1;

        while (left < right)
        {
            ask.clear();

            int middle = (left + right) / 2;

            for (int i = 0; i <= middle; i++)
                for (int j : subsets[i])
                    ask.push_back(j);
                    
            if(solve(ask, maximum)) right = middle;
            else left = middle + 1;
        }

        ask.clear();

        ask = get_complement(subsets[left], n);

        int second_max = interact(ask);

        cout << "! ";
        
        for (int i = 0; i < k; i++)
        {
            if (i == left) cout << second_max << ' ';
            else cout << maximum << ' ';
        }

        cout << '\n';
        cout.flush();

        string ans;
        cin >> ans;
    }



}