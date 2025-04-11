#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void print_Q(queue<string> q)
{
    // printing content of queue
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
int main()
{
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << "Popping from original Stack : ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout<< s.empty() << endl;
    cout << endl;
    queue<string> q;
    q.push("abc");
    q.push("xyz");
    q.push("cde");
    q.push("cde");
    cout << "Printing copy of the queue\n";
    print_Q(q);
    cout << "Emptying original queue : \n";
    while (!q.empty())
    {

        cout << q.front() << endl;
        q.pop();
    }
    cout << q.empty();
    // If we dont want to empty our queue / stack while printing it
    // then we can use call by value to create its copy and print it using the same method
    // Anyway, when using these data structures we shouldn't have the need to frequently print them entirely
    return 0;
}