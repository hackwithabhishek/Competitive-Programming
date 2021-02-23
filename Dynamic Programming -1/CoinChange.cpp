
int c(int denominations[], int numDenominations, int value, int** output)
{
    if(value==0)
    {
    return 1;
    }
    if(value<0){
        return 0;
    }
    if(numDenominations==0)
    {
        return 0;
    }
    if(output[value][numDenominations])
    {
        return output[value][numDenominations];
    }
    int first=c(denominations,numDenominations,value-denominations[0],output);
    int second=c(denominations+1,numDenominations-1,value,output);
    output[value][numDenominations]=first+second;
    return (first+second);
}

int countWaysToMakeChange(int denominations[], int numDenominations, int value)
{   
    int** output=new int*[value+1];
    for(int i=0;i<=value;i++)
    {
        output[i]=new int[numDenominations+1]();
    }
    return c(denominations,numDenominations,value,output);
}
