#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int main() { _


    int n, m;

    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    cin >> m;
    vector<int> B(m);
    for (int i = 0; i < m; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    cout << A.back() << " " << B.back() << '\n';


    return 0;

}
