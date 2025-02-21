#include<bits/stdc++.h>
using namespace std;

int32_t main()
{

    vector<int>v={1,2,3,4,5};
    
    for(auto i = rbegin(v); i!=rend(v); i++)
        cout<<*i<<" ";
    cout<<endl;
    for(auto i = v.rbegin(); i!=v.rend(); i++)
        cout<<*i<<" ";
    cout<<endl;
    for(auto i =begin(v);i!=end(v);i++)
        cout<<*i<<" ";
    cout<<endl;

    return 0;
}