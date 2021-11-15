// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
  
    bool isSubsetSum(int n, int arr[], int sum){
        // code here 
        bool dp[n+1][sum+1];//sum+1 kyuki last me d[n][sum] return krna h
        // 0  1  2  3  4  5  6
        for(int i=0;i<n;i++)// dp [0] [0] =0 hoga kyuki sum =0 hai
        {
            dp[i][0]=true;
        }
        for(int i=1;i<=sum;i++)
        {
            dp[0][i]=false;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                
                if(arr[i-1]<=j)
                {
                     dp[i][j]= dp[i-1][j] ||  dp[i-1][j-arr[i-1]];
                }
                 else{ dp[i][j]=dp[i-1][j]; }
            }
        }
        return dp[n][sum];
      /*  Recursive approach
        if (sum == 0)
        return true;
       if (n == 0)
           return false;
 
       // If last element is greater than sum,
       // then ignore it
       if (set[n - 1] > sum)
           return isSubsetSum(set, n - 1, sum);
 
        /* else, check if sum can be obtained by any
                                                of the following:
         (a) including the last element
         (b) excluding the last element   */
    return isSubsetSum(set, n - 1, sum)    || isSubsetSum(set, n - 1, sum - set[n - 1]);
      
      */
        
    }
        
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
