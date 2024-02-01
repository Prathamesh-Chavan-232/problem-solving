#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string ans = "";
        int i = num1.size() - 1, j = num2.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry)
        {
            int sum = 0;
            if (i >= 0)
                sum += num1[i--] - '0';
            if (j >= 0)
                sum += num2[j--] - '0';
            sum += carry;
            if (sum > 9)
            {
                sum = sum % 10;
                carry = 1;
            }
            else
                carry = 0;
            ans += (sum + '0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};