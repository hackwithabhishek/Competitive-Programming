#include <bits/stdc++.h>
using namespace std;
int kadane(int* sum,int row){
       int max_so_far = INT_MIN, max_ending_here = 0; 
  
    for (int i = 0; i<row; i++) 
    { 
        max_ending_here = max_ending_here + sum[i]; 
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here; }
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far;
}
void max_ractangle_sum(int** input,int row,int col){
    int maxSum = INT_MIN;
	int currsum = 0;
    int* sum=new int[row];
    
    for(int left=0;left<col;left++){
        for(int i=0;i<row;i++){
        	sum[i]=0;
    	}
         for(int right=left;right<col;right++){
             for(int i=0; i<row; i++){
                 sum[i]+=input[i][right];
             }
             
             currsum = kadane(sum, row);
             cout<<currsum<<endl;
             if(currsum>maxSum)
                 maxSum = currsum;
         }
    }
   cout<<maxSum<<endl;
}
int main()
{
    int row,col;
    cin>>row>>col;
    int** input=new int*[row];
    for(int i=0;i<row;i++){
        input[i]=new int[col];
        for(int j=0;j<col;j++){
            cin>>input[i][j];
        }
    }
    max_ractangle_sum(input,row,col);
    return 0;
}
