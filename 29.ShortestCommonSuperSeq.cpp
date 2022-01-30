
//  https://leetcode.com/problems/shortest-common-supersequence/
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) 
    {  int n= str1.size();
       int m= str2.size();
     
        vector<vector<string>> dp(str1.size()+1,vector<string>(str2.size()+1,""));
     for(int i=1 ;i<=n;i++)
     {
         for(int j=1;j <=m;j++)
         {
             
             if(str1[i-1]==str2[j-1])
             {
                 dp[i][j]=dp[i-1][j-1]+str1[i-1];
             }
             else {
                 dp[i][j]= dp[i-1][j].size() >dp[i][j-1].size() ? dp[i-1][j]: dp[i][j-1];
             }
         }
     }
     int i= n,j=m;
     string s ="";
     while(i>0 && j>0)
     {
         if(str1[i-1]==str2[j-1])
         {
             s=str1[i-1]+s;
             i--;
             j--;
         }
         else 
         {
             if(dp[i-1][j].size() >dp[i][j-1].size())
             { 
                 s=str1[i-1]+s;
                 i--;
             }
             else{
                 s=str2[j-1]+s;
                 j--;
             }
         }
     }
     while(i>0)
     {
         s=str1[i-1]+s;
         i--;
     }
     while(j>0)
     {
         s=str2[j-1]+s;
         j--;
     }
     return s;
     
    }
    
};
