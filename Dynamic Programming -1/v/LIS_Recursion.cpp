#include<bits/stdc++.h>
using namespace std;
void LCS(int* arr,int st,int n,int* arr1){
    if(st>n) return;
    for(int i=st-1;i>=0;i--){
        if(arr[st]>arr[i]){
            int k=arr1[i]+1;
            if(arr1[st]<k){
                arr1[st]=k;
            }
        }
    }
    LCS(arr,st+1,n,arr1);
}
int main(){
    int n;
    cin>>n;
    int* arr=new int[n];
     for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int* arr1=new int[n]();
    for(int i=0;i<n;i++){
        arr1[i]=1;
    }
    LCS(arr,1,n-1,arr1);
    int max=1;
    for(int i=0;i<n;i++){
        if(arr1[i]>max)
            max=arr1[i];
    }
    cout<<max;
}
