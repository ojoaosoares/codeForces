#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() { _

    int n;
    cin >> n;

    vector<string> chat;

    while(n--)
    {
        string target;
        cin >> target;;

        chat.push_back(target);

    }

    set<string> used;

    for (int i = chat.size() - 1; i >= 0; i--)
        if(used.find(chat[i]) == used.end())
        {
            cout << chat[i] << '\n';
            used.insert(chat[i]);
        }
}
