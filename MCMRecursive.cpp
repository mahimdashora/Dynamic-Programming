
//https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1/#
class Solution{
public:
    int mul(int arr[],int i ,int j)
    {
        if(i==j){
            return 0;
        }
        int ans=INT_MAX;
        for(int k=i;k<j;k++)
        {
           int tp= mul(arr,i,k)+mul(arr,k+1,j)+arr[i-1]*arr[j]*arr[k];
            ans=min(ans,tp);
        }
        return ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        int r =mul(arr,1,N-1);
        return r;
    }
    
};
