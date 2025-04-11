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
    int N = 4, n1;
    printf("Enter the size of the array : ");
    cin >> N;
    vector<int> v[N];
    for (int i = 0; i < N; i++)
    {
        printf("Enter size of vector %d : ", i + 1);
        cin >> n1;
        for (int j = 0; j < n1; j++)
        {
            printf("Enter element %d of vector %d : ", j + 1, i + 1);
            int a;
            cin >> a;
            v[i].push_back(a);
        }
    }
    for (int i = 0; i < N; i++)
    {
        printVec(v[i]);
    }
    cout << v[0][0] << " "
         << v[1][1] << " "
         << v[2][1] << "\n";
    return 0;
}