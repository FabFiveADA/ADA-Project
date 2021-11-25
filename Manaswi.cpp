#include<iostream>
#include<vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int dp[500][500];
    int solve(vector<int>& arr, int i, int j)
    {
        if(i+1 == j){return 0;}
        if(dp[i][j] != -1){return dp[i][j];}
        int b = 0; 
        for(int k = i+1; k<j; k++)
        {
            int temp = solve(arr, i, k) + solve(arr, k, j) + arr[i]*arr[k]*arr[j] ;
            b = max(b, temp);
        }
        return dp[i][j] = b;
    }
    int maxCoins(vector<int>& nums) 
    {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int sz = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, sz-1);
    }
};

int main(int argc, char** argv) {
	
	int n; cout<<"enter number of balloons:";cin>>n;
	vector<int> nums;
	cout<<"enter value of each balloon:\n";
	for(int a=0;a<n;a++)
	{
		int p;cin>>p;
		nums.push_back(p);
	}
	Solution  obj;

	int coins=0;
	coins=obj.maxCoins(nums);
	cout<<"maximum coins you can earn is: ";
	cout<<coins<<endl;
	
	return 0;
}