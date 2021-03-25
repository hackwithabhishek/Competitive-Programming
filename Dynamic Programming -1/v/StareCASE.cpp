#include<bits/stdc++.h>
using namespace std;
int starecase(int n,int* &dp)
{
    if(n==0) return 1;
    if(n==1) return 1;
    if(n==2) return 2;
    if(n==3) return 4;
    if(dp[n]>0)
        return dp[n];
    dp[n]=starecase(n-1,dp)+starecase(n-2,dp)+starecase(n-3,dp);
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    int* dp=new int[n+1]();
    cout<<starecase(n,dp);
}
