#include<bits/stdc++.h>
using namespace std;

/* 
stack in C++ does not support range - based for loops(for (auto i : s)).
The reason is that std::stack does not provide iterators, so it cannot be iterated directly.
*/

int32_t main()
{

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    for(auto i : s)
        cout << i << " ";
    cout << endl;

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << s.size() << endl;
    cout << s.empty() << endl;

    return 0;
}