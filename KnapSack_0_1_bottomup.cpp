// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    // Returns the value of maximum profit
    


int knapSack(int W, int wt[], int val[], int n)
{
	// double pointer to declare the
	// table dynamically
	vector<vector<int>> dp(n+1,vector<int>(W+1,0));
	
	for(int i=0;i<=n;i++)
	{
	    for(int w=0;w<=W;w++)
	    {
	        if(i==0 ||w==0)
	        {
	            dp[i][w]=0;
	        }
	        else if(wt[i-1]<=w)//capacity mein hai
	        {
	            dp[i][w]=max(val[i-1]+dp[i-1][w-wt[i-1]],dp[i-1][w]);
	        }
	        else
	        {
	            dp[i][w]=dp[i-1][w];// can't choose as weight not less than available weight
	        }
	    }
	}
	return dp[n][W] ;
 }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends