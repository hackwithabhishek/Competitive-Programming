#include<bits/stdc++.h>
using namespace std;
int encryp(int n[],int size,int* arr){
    if(size==1) return 1;
    if(size==0) return 1;
    if(arr[size]>0) return arr[size];
    int output=encryp(n,size-1,arr);
    if(n[size-2]*10+n[size-1]<=26)
        output+=encryp(n,size-2,arr);
    arr[size]=output;
    return output;
}
int main(){
    int n[4]={1,2,5,6};
    int* arr=new int[4]();
    cout<<encryp(n,4,arr);
}
