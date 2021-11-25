#include "/Users/stdc++.h"
#define pb push_back
using namespace std;

  int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector < vector<int> > dp(n,vector<int>(n,0));
        for(int g=0;g<n;g++)  {

            for(int i=0,j=g;j<n;i++,j++){
                int maxi=INT_MIN;
                for(int k=i;k<=j;k++){
                int left= k==i?0: dp[i][k-1] ;  
                int right= k==j?0: dp[k+1][j] ; 
                int val = (i==0?1:nums[i-1])nums[k](j==n-1?1:nums[j+1]);  
                maxi=max(left+right+val,maxi);
                    
                }
                  dp[i][j]=maxi;
            }
            
        }
        return dp[0][n-1];
    }

    int main() {

      vector <int> v1{3,1,5,8};
      vector <int> v2{1,5};
      vector <int> v3{5,1,9};
      vector <int> v4{7};
      vector <int> v5{2,6}; 
      vector <int> v6{35,16,83,87,84,59,48,41,20,54};  
      vector <int> v7{8,2,6,8,9,8,1,4,1,5,3,0,7,7,0,4,2,2};  

      cout<<maxCoins(v1)<<"\n";
      cout<<maxCoins(v2)<<"\n";
      cout<<maxCoins(v3)<<"\n";
      cout<<maxCoins(v4)<<"\n";
      cout<<maxCoins(v5)<<"\n";
      cout<<maxCoins(v6)<<"\n"; 
      cout<<maxCoins(v7)<<"\n"; 
    
      return 0;
  }
