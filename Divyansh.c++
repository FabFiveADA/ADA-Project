class Solution {
public:
int maxCoins(vector<int>& nums) {

    int n=nums.size();
    
    vector<int>arr(n+2);
    
    arr[0]=1;
    arr[n+1]=1;
    
    for(int i=1;i<=n;i++){
        arr[i]=nums[i-1];
    }
    
    vector<vector<long long>>dp(n+2,vector<long long>(n+2,0));
    
    for(int L=1;L<=n;L++){
        
        for(int i=1;i<=n-L+1;i++){
            
            int j=i+L-1;
            
           // dp[i][j]=LONG_MIN;
            
            for(int k=i;k<=j;k++){
                
                
         dp[i][j]=max(dp[i][j],dp[i][k-1]+dp[k+1][j]+(arr[i-1]*arr[k]*arr[j+1]));
                
                
            }
            
        }
        
    }
    
  /*  for(int i=0;i<n+2;i++){
        
        for(int j=0;j<n+2;j++){
            
            cout<<dp[i][j]<<" ";
            
        }
        cout<<endl;
        
    }*/
    
    return dp[1][n];
    
}
};
