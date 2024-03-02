#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);


bool possible(int size, int d, string &s)
{
    int i = -1;
    while(true)
    {
        if(i + d >= size) return true;

        for (int j = d; j >= 0; j--)
        {    
            if (j == 0)
                return false;
            
            else if(s[i + j] == 'R')
            {
                i += j;
                break;
            }
        }   
    }
}

int main() { _

    int n;
    cin >> n;

    while(n--)
    {
        string s;
        cin >> s;

        int left = 1, right = s.length() + 1;

        int middle;
        while (left < right)
        {
            middle = (left + right)/ 2;

            if(possible(s.length(), middle, s)) right = middle;
            else left = middle + 1;

        }

        cout << left << '\n';
    }
}
