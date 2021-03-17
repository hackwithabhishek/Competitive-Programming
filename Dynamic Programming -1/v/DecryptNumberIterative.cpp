#include<bits/stdc++.h>
using namespace std;
int encryp(int n[],int size){
    int* arr=new int[size];
    arr[0]=1;
    arr[1]=1;
    for(int i=2;i<=size;i++){
        arr[i]=arr[i-1];
        if(n[i-2]*10+n[i-1]<=26){
            arr[i]+=arr[i-2];
        }
    }
    return arr[size];

}
int main(){
    int n[4]={1,2,5,6};
    cout<<encryp(n,4);
}
