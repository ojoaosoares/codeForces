#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

int main() { _

    int left = 1, right = 1e6;

    while(left < right)
    {
        int middle = (left + right + 1) / 2;

        printf("%d\n", middle);
        fflush(stdout);

        char resp[3];
        scanf("%s", resp);

        if(resp[0] == '<') right = middle - 1;
        else left = middle;
    }

    printf("! %d\n", left);
}