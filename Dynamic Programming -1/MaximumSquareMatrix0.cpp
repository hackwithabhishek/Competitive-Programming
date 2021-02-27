#include<bits/stdc++.h>
using namespace std;
int findMaxSquareWithAllZeros(int** arr, int row, int col){
	int** dp=new int*[row];
	for(int i=0;i<row;i++){
		dp[i]=new int[col];
	}
	for(int i=0;i<row;i++){
		if(arr[i][0]==0){
			dp[i][0]=1;
		}
		else{
			dp[i][0]=0;
		}
	}
	for(int i=0;i<col;i++){
		if(arr[0][i]==0){
			dp[0][i]=1;
		}
		else{
			dp[0][i]=0;
		}
	}
	int max=0;
	for(int i=1;i<row;i++){
		for(int j=1;j<col;j++){
			if(arr[i][j]==0){
				dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
				if(max<dp[i][j]){
					max=dp[i][j];
				}
			}
			else{
				dp[i][j]=0;
			}
		}
	}
	
	return max;
}


