#include<bits/stdc++.h>
using namespace std;


int32_t main()
{
    unordered_set<int> s;

    s.insert(1);
    s.insert(12);
    s.emplace(3);
    s.emplace(3);
    s.insert(14);
    s.insert(5);

    for (auto i : s)
        cout << i << " ";
    cout << endl;

    s.erase(14);
    for (auto i : s)
        cout << i << " ";
    cout << endl;

    cout << s.size() << endl;
    cout << s.max_size() << endl;
    cout << s.empty() << endl;
    cout << s.count(3) << endl;
    // cout << s.find(3) << endl; // Error
    // auto it = s.find(7); // Find element 7
    auto it = s.find(3); // Find element 7
    if (it != s.end())
        cout << "Found element: " << *it << endl;

    cout << endl;

    cout << "bucket_count : " << s.bucket_count() << endl;
    cout << s.max_bucket_count() << endl;

    s.rehash(10); // 10 is the minimum number of buckets
    cout << s.bucket_count() << endl;

    s.erase(3);
    for (auto i : s)
        cout << i << " ";
    cout << endl;

    return 0;
}