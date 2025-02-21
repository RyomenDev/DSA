#include<bits/stdc++.h>
using namespace std;


int32_t main()
{

    // priority_queue<int> pq; // max heap
    priority_queue<int, vector<int>, greater<int>> pq; // min heap

    pq.push(1);
    pq.push(12);
    pq.emplace(7);
    pq.push(5);
    pq.emplace(13);

    cout << pq.top() << endl; // 1
    pq.pop();
    cout << pq.top() << endl; // 5

    cout << pq.size() << endl; // 4
    cout << pq.empty() << endl;

    return 0;
}