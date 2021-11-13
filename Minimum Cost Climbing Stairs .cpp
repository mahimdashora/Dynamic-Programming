at i=2 aney  me kitna cost lgega .
 ek to cost[i] khukda , plus yaa to dp[i-1] ya to dp[i-2] jo chota  h uska rasta liya jaega
 hence ,
 ``
 for i=2 i<n
    dp[i]=min(dp[i-1],dp[i-2]) +cost[i];
 
 
 baadme 
 return min(dp[n-1] ,dp[n-2]); 
 ``
