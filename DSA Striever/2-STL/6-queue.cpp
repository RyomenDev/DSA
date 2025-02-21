#include<bits/stdc++.h>
using namespace std;


int32_t main()
{

    queue<int> q;
    q.push(1);
    q.push(2);
    q.emplace(3);
    q.emplace(4);
     
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;

    cout<<"Poping the elements"<<endl;

    q.pop(); // first element will be removed
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    cout<<q.size()<<endl;

    return 0;
}