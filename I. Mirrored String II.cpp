#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

bool possible(string s, int chute, vector<int> &evens, vector<int> &odds)
{   
    string allowed = "AHIMOTUVWXY";

    if (chute % 2)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (i - ((chute - 1) / 2) < 0 || i + ((chute - 1) / 2) >= s.length() || allowed.find(s[i]) == string::npos) continue;

            int j;
            for (j = ((odds[i] - 1) / 2) + 1; j <= (chute - 1) / 2; j++)
                if(s[i - j] != s[i + j] || allowed.find(s[i - j]) == string::npos) break;
            
            odds[i] = 1 + (j - 1) * 2;

            if(odds[i] >= chute) return true;
        }
    }

    else
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (i - ((chute/2) - 1) < 0 || (i + 1) + ((chute/2) - 1) >= s.length()) continue;
            
            int j;
            for (j = evens[i] / 2; j < chute/2; j++)
                if(s[i - j] != s[(i + 1) + j] || allowed.find(s[i - j]) == string::npos) break;

            evens[i] = j * 2;

            if(evens[i] >= chute) return true;
        }
    }

    return false;
}

// int solve(string s) {

//     string allowed = "AHIMOTUVWXY";

//     int max_odd = 0;

//     for (int i = 0; i < s.length(); i++)
//     {
//         if (allowed.find(s[i]) == string::npos) continue;

//         int j = 1;

//         while (i - j >= 0 && i + j < s.length())
//         {
//             if(s[i - j] != s[i + j] || allowed.find(s[i - j]) == string::npos) break;

//             j++;
//         }    

//         max_odd = max(max_odd, 1 + (j - 1) * 2);

//     }
    

//     int max_even = 0;
//     for (int i = 0; i < s.length(); i++)
//     {
//         int j = 0;

//         while (i - j >= 0 && (i + 1) + j < s.length())
//         {
//             if(s[i - j] != s[(i + 1) + j] || allowed.find(s[i - j]) == string::npos) break;

//             j++;
//         }

//         max_even = max(max_even, j * 2);
//     }

//     return max(max_even, max_odd);

// }

int main() { _

    int n;
    cin >> n;

    while(n--)
    {
        string s;
        cin >> s;

        int left = 0, right = s.length();

        vector<int> max_odds(s.length(), 0);
        vector<int> max_evens(s.length(), 0);

        while (left < right)
        {
            int middle = (left + right + 1) / 2;

            if (possible(s, middle, max_evens, max_odds)) left = middle;
            else if (possible(s, middle + 1, max_evens, max_odds)) left = middle + 1;
            else right = middle - 1;    
        }

        cout << left << '\n';

        // if(left != right || left != solve(s))
        // {
        //     cout << s << '\n';
        //     cout << left << ' ' << right << ' ' << solve(s) << '\n';
        // }
    }    
}