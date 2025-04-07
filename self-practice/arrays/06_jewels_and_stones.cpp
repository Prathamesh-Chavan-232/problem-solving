
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        int ans = 0;
        for (int i = 0; jewels[i] != '\0'; i++)
        {
            for (int j = 0; j < stones[j] != '\0'; j++)
            {
                if (jewels[i] == stones[j])
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};