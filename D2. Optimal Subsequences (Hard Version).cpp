#include <bits/stdc++.h>

using namespace std;

const int MAX = 200000;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

bool comp(pair<int,int> &a, pair<int, int> &b)
{
    return (a.first > b.first || (a.first == b.first && a.second < b.second));
}

void update(vector<int> &v, int root, int left, int right, int target)
{
    if (left == right)
    {
        v[root]++;
        return;
    }
    
    int middle = (left + right) / 2;

    if (target <= middle) update(v, root*2 + 1, left, middle, target);
    else update(v, root*2 + 2, middle + 1, right, target);

    v[root] = v[root*2 + 1] + v[root*2 + 2];

    return;
}

int query(vector<int> &v, int root, int left, int right, int target)
{
    if(left == right) return left;

    int middle = (left + right) / 2;

    if(v[root*2 + 1] >= target) return query(v,root*2 + 1, left, middle, target);

    return query(v,root*2 + 2, middle + 1, right, target - v[root*2 + 1]);
     
}


int main () { _

    int n;

    cin >> n;

    vector<int> original(n);
    vector<pair<int, int>> indices(n);

    for (int i = 0; i < n; i++)
    {
        cin >> original[i];
        indices[i] = {original[i], i};
    }

    sort(indices.begin(), indices.end(), comp);

    int qtd_queries;
    cin >> qtd_queries;

    vector<vector<pair<int, int>>> queries(n);
    vector<int> ans (qtd_queries);

    for (int i = 0; i < qtd_queries; i++)
    {
        int size_sub, index;
        cin >> size_sub >> index;

        queries[size_sub - 1].push_back({index, i});
    }

    vector<int> tree(n*4, 0);

    for (int i = 0; i < n; i++)
    {
        update(tree, 0, 0, n - 1,indices[i].second);

        for (auto v : queries[i])
            ans[v.second] = original[query(tree,0,0,n-1,v.first)];
    }

    for (int i = 0; i < qtd_queries; i++)
        cout << ans[i] << '\n' ;
}