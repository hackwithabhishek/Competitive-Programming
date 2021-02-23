
#include <bits/stdc++.h>
using namespace std;
int solution(int* A,int* B,int size){
    int m = 1000000007;
    int output=0;
    if((size==0)||(size==1))
    {
        return 1;
    }
    if(B[size]>0)
    {
        return B[size];
    }
    if(A[size-1]!=0)
    output=solution(A,B,size-1)%m;
    if((A[size-2]*10+A[size-1])<=26 && A[size-2]!=0)
    {
        output= (output%m+solution(A,B,size-2)%m)%m;
    }
    B[size]=output%m;
    return output;

}
int main()
{ 
    while(1)
    {
        string s;
        cin>>s;
        //cout<<s<<endl<<s.size()<<endl;
        if(s.size() == 1 && s[0] - '0' == 0)
        {
            break;
        }
        int  size=s.length();
        int* A=new int[s.length()];
        for(int i=0;i<s.length();i++)
        {
            A[i]=s[i]-'0';
        }
        int* B=new int[size+1];
        for(int i=0;i<(size+1);i++)
        {
            B[i]=0;
        }
        int k= solution(A,B,size);
        cout<<k<<endl;      
    }
    return 0;
}
