#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// void printVec(vector<int> v) // This vector is passed by value
// never pass a vector by value since it takes O(n) to make a copy
void printVec(vector<int> &v) // pass it by reference
{
    printf("size : %d\n", v.size());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}
void pass_by_value(vector<int> v) // call by value
{
    v.push_back(69);
}
void pass_by_ref(vector<int> &v) // call by reference
{
    v.push_back(69);
}
int main()
{
    int a[10];
    vector<int> v;
    int n = 3;
    printf("Enter the elements of vectors : ");
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    printVec(v);
    vector<int> v1(7);
    printVec(v1);
    v1.push_back(5);
    printVec(v1);
    v1.pop_back();
    printVec(v1);
    
    vector<int> v2 = v; // O(n) time complexity
    v2.push_back(6);
    printVec(v);
    printVec(v2);
    pass_by_value(v);
    printVec(v);
    pass_by_ref(v); 
    printVec(v);
    return 0;
}