#include<bits/stdc++.h>
using namespace std;
int getMaxMoney(int arr[], int n){
    int* dp=new int[n];
    dp[0]=arr[0];
    dp[1]=max(arr[0],arr[1]);
        for(int i=2;i<n;i++){
        dp[i]=max((arr[i]+dp[i-2]),dp[i-1]);}
    
    return dp[n-1];
}
