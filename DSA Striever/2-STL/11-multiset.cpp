#include<bits/stdc++.h>
using namespace std;


int32_t main()
{
    multiset<int> s;
    // multiset<int, greater<int>> s; // for decreasing order

    s.insert(1);
    s.insert(15);
    s.insert(12);
    s.emplace(12);
    s.emplace(17);
    s.insert(4);

    for (auto i : s)
        cout << i << " ";
    cout << endl;

    cout<<s.count(12)<<endl;
    
    // cout<<s.find(12)<<endl; // returns iterator
    auto it = s.find(12);
    if(it!=s.end())
        cout<<(*it)<<endl;
    else
        cout<<"Not found"<<endl;

    auto itL = s.lower_bound(12); // 12
    auto itU = s.upper_bound(12); // 15

    cout<<(*itL)<<" "<<(*itU)<<endl;

    cout<<endl;

    auto it2 = s.equal_range(12); // pair of lower and upper bound
    cout<<(*it2.first)<<" "<<(*it2.second)<<endl;

    auto itL2=s.lower_bound(5); // 12
    auto itU2=s.upper_bound(5); // 12
    cout<<(*itL2)<<" "<<(*itU2)<<endl;

    return 0;
}