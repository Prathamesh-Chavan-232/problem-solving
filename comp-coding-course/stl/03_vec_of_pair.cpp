#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void printVec(vector<int> &v) // pass it by reference
{
    printf("size : %d\n", v.size());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }
    cout << "\n";
}
int main()
{
    vector<pair<int, int>> v = {{1, 2}, {2, 3}, {3, 4}};
    printVec(v);
    int n;
    printf("Enter size : ");
    scanf("\n%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        printf("Enter pair %d : ", i + 1);
        cin >> x >> y;
        v.push_back({x, y});
    }
    printVec(v);
    return 0;
}
