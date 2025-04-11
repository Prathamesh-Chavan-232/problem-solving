#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void printVec(vector<int> &v) // pass it by reference
{
    printf("size : %d\n", v.size());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}
int main()
{
    int N, n1;
    printf("Enter the initial size of the vector : ");
    cin >> N;
    vector<vector<int>> v;
    for (int i = 0; i < N; i++)
    {
        printf("Enter size of vector %d : ", i + 1);
        cin >> n1;
        v.push_back(vector<int>()); // Inserting empty vector to access v[i]
        // alternatively make a 2nd temp vector - vector<int> temp 
        for (int j = 0; j < n1; j++)
        {
            printf("Enter element %d of vector %d : ", j + 1, i + 1);
            int a;
            cin >> a;
            v[i].push_back(a);
        }
    }
    v[0].push_back(10);
    v.push_back(vector<int>());
    for (int i = 0; i < v.size(); i++)
    {
        printVec(v[i]);
    }
    cout << v[0][1] << endl;
    return 0;
}