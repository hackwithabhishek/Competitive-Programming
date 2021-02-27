#include<bits/stdc++.h>
using namespace std;

int minHealth(int r,int c,int** magrid)
{
	
	int** dp = new int*[r+1];
	for(int i=1;i<=r;i++)
	{
		dp[i] = new int[c+1];
	}
	for(int i =1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			dp[i][j]=1;
		}
	}
	dp[r][c] =1;
	
	for(int i=r-1;i>=1;i--)
	{
		dp[i][c] = dp[i+1][c]-magrid[i][c];
        if(dp[i][c]<1)
        {
            dp[i][c]=1;
        }
	}
	
	for(int j=c-1;j>=1;j--)
	{
		dp[r][j] = dp[r][j+1]-magrid[r][j];
         if(dp[r][j]<1)
         {
            dp[r][j]=1;
         }
	}
	for(int i= r-1;i>=1;i--)
	{
		for(int j=c-1;j>=1;j--)
		{
			dp[i][j] = min(dp[i+1][j],dp[i][j+1])-magrid[i][j];
			if(dp[i][j]<=0)
			{
				dp[i][j]=1;
			}
		}
	}
	int ans = dp[1][1];
	delete[] dp;
	return ans;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int r,c;
		cin>>r>>c;
		int** magrid = new int*[r+1];
		for(int i=1;i<=r;i++)
		{
			magrid[i] = new int[c+1];
		}
		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++)
			{
				cin>>magrid[i][j];
			}
		}
		int ans = minHealth(r,c,magrid);
		delete[] magrid;
		cout<<ans<<endl;
	}
}
