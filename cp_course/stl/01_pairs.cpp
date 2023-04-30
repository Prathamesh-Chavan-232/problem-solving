#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    pair<int, string> p;
    p = make_pair(2, "abcd");
    pair<int, string> p1 = p;
    cout << p.first << "\n";
    cout << p.second << "\n";
    int a[] = {1, 2, 3};
    int b[] = {2, 3, 4};
    pair<int, int> p_arr[3];
    p_arr[0] = {1, 2};
    p_arr[1] = {2, 3};
    p_arr[2] = {3, 4};
    for (int i = 0; i < 3; i++)
    {
        cout << p_arr[i].first << " " << p_arr[i].second << "\n";
    }
    pair<int, int> p_arr1[3];
    for (int i = 0; i < 3; i++)
    {
        printf("Enter element %d of pair : ", i + 1);
        cin >> p_arr1[i].first >> p_arr1[i].second;
    }
    for (int i = 0; i < 3; i++)
    {
        cout << p_arr1[i].first << " " << p_arr1[i].second << "\n";
    }
    return 0;
}