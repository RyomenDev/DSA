#include<bits/stdc++.h>
using namespace std;

int32_t main()
{

    deque<int> dq;
    dq.push_back(1); // 1
    dq.push_back(2); // 1 2
    dq.push_front(4);// 4 1 2
    dq.insert(dq.begin() + 1, 3); // 4 3 1 2
    for (auto i : dq)
        cout << i << " ";
    cout << endl;

    dq.pop_back(); // 4 3 1
    dq.pop_front(); // 3 1

    for (auto i = dq.begin(); i != dq.end(); i++)
        cout << *i << " ";
    cout << endl;

    dq.emplace_back(5);
    dq.emplace_front(6);

    cout << dq.size() << endl; // 4
    dq.clear();
    cout << dq.size() << endl;// 0

    return 0;
}