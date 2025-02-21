#include<bits/stdc++.h>
using namespace std;

int32_t main()
{

    list<int> l1; // empty list of integers
    list<int> l2(5, 100); // 5 elements with value 100
    list<int> l3(l2.begin(), l2.end()); // copy of l2
    list<int> l4(l3); // copy of l3

    for (auto x : l2)
        cout << x << " ";
    cout << endl;

    l1.push_back(5);
    l1.push_back(10);
    l1.push_back(15);
    for (auto i = l1.begin(); i != l1.end(); i++)
        cout << *i << " ";
    cout << endl;

    l1.pop_back();
    for (auto i = l1.begin(); i != l1.end(); i++)
        cout << *i << " ";
    cout << endl;

    l1.emplace_back(3);
    l1.emplace_back(20);
    l1.emplace_back(7);

    cout<<l1.back()<<endl;
    
    l1.sort();
    cout << l1.back() << endl;

    cout<<l1.front()<<endl;
    l1.pop_front();
    l1.reverse();
    cout<<l1.back()<<endl;

    cout<<"size:"<<l1.size()<<endl;
    cout<<"isEmpty:"<<l1.empty()<<endl;

    l1.clear();
    cout << "size:" << l1.size() << endl;
    cout << "isEmpty:" << l1.empty() << endl;

    return 0;
}