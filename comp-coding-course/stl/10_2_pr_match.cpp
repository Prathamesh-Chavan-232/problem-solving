#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string isBalanced(string exp)
{
    unordered_map<char, int> symbols = {{'(', -1}, {'[', -2}, {'{', -3}, {')', 1}, {']', 2}, {'}', 3}};
    stack<char> s;
    for (char x : exp)
    {
        if (symbols[x] < 0)
        {
            s.push(x);
        }
        else
        {
            if (s.empty())
            {
                return "NO";
            }
            if (symbols[x] + symbols[s.top()] != 0)
            {
                return "NO";
            }
            s.pop();
        }
    }
    if (!s.empty())
    {
        return "NO";
    }
    else
    {
        return "YES";
    }
}
int main()
{

    string exp = "({)";
    cout << isBalanced(exp) << endl;
    return 0;
}