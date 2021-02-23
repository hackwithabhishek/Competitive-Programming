#include<bits/stdc++.h>
using namespace std;
int longestBitonicSubarray(int *input, int n) 
{
   int* output=new int[n];
   output[0]=1;
    for(int i=1;i<n;i++)
    {
        output[i]=1;
        for(int j=i-1;j>=0;j--)
        {
            if(input[i]>input[j])
            {
                int possible=output[j]+1;
                if(possible>output[i])
                {
                    output[i]=possible;
                }
            }
        }
    }
    
int* output1=new int[n];
    output1[n-1]=1;
    int k=0;
    for(int i=n-2;i>=0;i--)
    {
        output1[i]=1;
        for(int j=i+1;j<n;j++)
        {          
            if(input[i]>input[j])
            {
                int possible=output1[j]+1;
                if(possible>output1[i])
                {
                    output1[i]=possible;
                } 
            }
        }
    }
    int max=output[0]+output1[0]-1;
    for (int i = 1; i < n; i++)
        if (output[i] + output1[i] - 1 > max)
            max = output[i] + output1[i] - 1;
        return max;
          	
}

