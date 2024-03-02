#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int main() { _

   int t;
   cin >> t;

   while (t--)
   {
       string s;
       cin >> s;

       int minimum = INT_MAX, left = 0, right = 0;

        vector<int> has(3, 0);

        bool new_position = true;

        while (right < (int) s.length() && minimum != 3)
        {
            if (new_position)
                has[(int) s[right] - 49]++;

            if (has[0] > 0 && has[1] > 0 && has[2] > 0)
            {
                minimum = min(minimum, right - left + 1);
                has[(int) s[left] - 49]--;
                new_position = false;
                left++;
            }

            else
            {
                new_position = true;
                right++;
            }

        }

        if (minimum == INT_MAX) cout << "0 \n";
        else cout << minimum << '\n';
   }

}
