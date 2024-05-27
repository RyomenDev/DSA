// minimum bit flips to convert a number

#include <bits/stdc++.h>
using namespace std;

int minBitFlip(int a, int b){
    int ans = a^b;
    return __builtin_popcount(ans);
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<minBitFlip(a,b);
    return 0;
} 