//  Hackerearth question - The monk and class marks
//  Link - https://www.hackerearth.com/problem/algorithm/the-monk-and-class-marks/
//  Soln - Nesting maps with other containers (multiset in this case)
//  Time complexity - O(n*(log(n)^2))
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class soln
{
public:
    void soln_1()
    {
        int n; // no of students
        cin >> n;
        map<int, multiset<string>> students;
        for (int i = 0; i < n; ++i)
        {
            string name;
            int marks;
            cin >> name >> marks;
            students[-1 * marks].insert(name);
        }
        for (auto &pr : students)
        {
            auto &marks = pr.first;
            auto &name = pr.second;
            for (auto na : name)
            {
                cout << na << " " << -1 * marks << endl;
            }
        }
    }
};

bool cmp(pair<int, string> p1, pair<int, string> p2)
{
    if (p1.first != p2.first)
        return (p1.first > p2.first);
    else
        return (p1.second < p2.second);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        // soln s;
        // s.soln_1();

        int n; // no of students
        cin >> n;
        vector<pair<int, string>> v(n);
        for (int i = 0; i < n; ++i)
        {

            cin >> v[i].second >> v[i].first;
        }
        sort(v.begin(), v.end(), cmp);
        for (auto &value : v)
        {
            cout << value.second << " " << value.first <<endl;
        }
    }
    return 0;
}

// Striked-throughed code uses iterators to traverse the map in reverse
// however we dont need to do that if we use our big brain

/*
// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n; // no of students
//     cin >> n;
//     map<int, multiset<string>> students;
//     for (int i = 0; i < n; ++i)
//     {
//         string name;
//         int marks;
//         cin >> name >> marks;
//         students[marks].insert(name);
//     }
//     auto &pr = (--students.end());
//     while (true)
//     {
//         auto &marks = pr->first;
//         auto &name = pr->second;
//         for (auto &na : name)
//         {
//             cout << na << " " << marks << endl;
//         }
//         if (pr == --students.begin())
//         {
//             break;
//         }
//         --pr;
//     }
//     return 0;
// }
*/