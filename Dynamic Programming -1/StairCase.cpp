typedef long long ll;
long calculate(int n,ll* A)
{   
    if(n==1 || n==0){
         return 1;
    }
    if(n==2){
        return 2;
    }
    if(A[n]>0){
        return A[n]; 
    }
    long long ways=(calculate(n-1,A)+calculate(n-2,A)+calculate(n-3,A));
    
    A[n]=ways;
    
    return ways;
}
long staircase(int n){
    ll* A=new ll[n+1];
	return calculate(n,A);
}
