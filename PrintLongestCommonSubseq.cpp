
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;


void lcs( string x, string y, int m, int n )
{

   int dp[m+1][n+1];
   for(int i=0; i<=m;i++)
   {
       for(int j=0; j<=n;j++)
       {
           if(j==0 || i==0 )
           {
               dp[i][j]=0;
           }
           else if(x[i-1]==y[j-1])
           {
               dp[i][j]=1+dp[i-1][j-1];
           }
           else 
           {
               dp[i][j]= max(dp[i][j-1], dp[i-1][j]);
           }
       }
   }
   cout<<dp[m][n]<<endl;
  string s =" ";
   int i=m ;
   int j=n;
   while(i>0 && j>0)
   {
       if(x[i-1]==y[j-1])//x is of size m and y is of size n
       {  
           s =x[i-1]+s;
           i--;
           j--;
           
       }
       else 
       {
           if (dp[i][j-1]>dp[i-1][j])
           {
               j--;
           }
           else{
               i--;
           }
       }
   }
  





 // Print the lcs
 cout << "LCS of " << x << " and " << y << " is " << s;
}

/* Driver program to test above function */
int main()
{
   string x = "AGGTAB";
    string y = "GXTXAYB";
   int m = x.size();
   
  int n = y.size();
  cout<<"m and n"<<m <<" "<<n<<endl;
  lcs(x, y, m, n);
return 0;
}


