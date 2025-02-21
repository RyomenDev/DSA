#include<bits/stdc++.h>
using namespace std;


int32_t main()
{

    // set<int> s;
    set<int, greater<int>> s;

    s.insert(11);
    s.insert(2);
    s.emplace(7);
    s.emplace(5);
    s.emplace(15);

    for (auto i = s.begin(); i != s.end(); i++)
        cout << *i << " ";
    cout << endl;

    cout << "size: " << s.size() << endl;
    cout << "max_size: " << s.max_size() << endl;

    cout << "isEmpty: " << s.empty() << endl;
    cout << "find 7: " << *s.find(7) << endl;
    cout << "count 7: " << s.count(7) << endl;

    cout << "find 20: " << *s.find(20) << endl;
    if (s.find(20) == s.end())
        cout << "20 not found" << endl;
    else
        cout << "find 21: " << *s.find(21) << endl;
    cout << "count 20: " << s.count(20) << endl;

    cout << endl;

    // 15 11 7 5 2
    // auto itL=s.lower_bound(7);
    // auto itU=s.upper_bound(7);
    // cout << "lower_bound(7): " << *itL << endl;
    // cout << "upper_bound(7): " << *itU << endl;

    // cout << "lower_bound(7)+1: " << *(itL+1) << endl;
    // cout << "upper_bound(7)+1: " << *(itU+1) << endl;

    auto itL = s.lower_bound(7);
    auto itU = s.upper_bound(7);

    cout << "lower_bound(7): " << (itL != s.end() ? to_string(*itL) : "Not found") << endl;
    cout << "upper_bound(7): " << (itU != s.end() ? to_string(*itU) : "Not found") << endl;

    // Using std::next to safely increment iterators
    auto nextItL = next(itL);
    /*
    ! auto nextItL = itL+1;
    ! set in C++ uses bidirectional iterators, which do not support arithmetic operations like itL + 1.
    ! Instead, you must use std::next(itL).
    */
    auto nextItU = next(itU);

    cout << "lower_bound(7)+1: " << (nextItL != s.end() ? to_string(*nextItL) : "Not found") << endl;
    cout << "upper_bound(7)+1: " << (nextItU != s.end() ? to_string(*nextItU) : "Not found") << endl;

    cout << endl;

    s.emplace(25);
    s.emplace(27);
    s.erase(7);
    for (auto i = s.begin(); i != s.end(); i++)
        cout << *i << " ";
    cout << endl;
    s.erase(s.find(11), s.end());
    s.erase((s.begin()));
    for (auto i = s.begin(); i != s.end(); i++)
        cout << *i << " ";
    cout << endl;

    return 0;
}