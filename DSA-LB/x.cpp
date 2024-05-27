#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x,m;
        cin >> x>>m;
        vector<int>v;
        long long totalProduct=1;
        for (int i = 0; i < x; i++)
        {
            int temp;
            cin>>temp;
            totalProduct*=temp;
            v.push_back(temp);
        }
        string s;
        cin>>s;

        int start=0,end=x-1;
        for(int i=0;i<s.size();i++){
            cout<<totalProduct%m<<" ";
            if(s[i]=='L'){
                totalProduct/=v[start];
                start++;
            }
            if(s[i]=='R'){
                totalProduct/=v[end];
                end--;
            }
        }
        cout<<endl;
    }
    return 0;
}