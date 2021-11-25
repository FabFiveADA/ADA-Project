#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class sol{
	public:
		
int solve(vector<int>& ball,int i,int j,int n)
{    	int dp[n][n];
         memset(dp,-1,sizeof(dp));
	if(i<0||j<0||i>j)//i->start,j->end,k->current
	{return 0;
	}
	//computing subprob which balloon will burst at the end//
	for(int len=1;len<=n;len++)
	{
		for(i=0;i<=n-len;i++)                                               /* for 3 1 5 8
		                                                                          0   1   2   3
																				0  3  30      167
																				1  x   15  135 159
																				2 x    x    40  
																				3  x   x    x    40 */
		{
			j=i+len-1;
			for(int k=i;k<=j;k++)
			{
				int right=(i==k?0:dp[i][k-1]);
				int left=(j==k?0:dp[k+1][j]);
				int coin=(i==0?1:ball[i-1])ball[k](j==n-1?1:ball[j+1]);
				dp[i][j]=max(right+coin+left,dp[i][j]);
				
			}
		}
	}
	
	return dp[0][n-1];
}	
};




int main(int argc, char** argv) {
	
	int n; cout<<"enter number of balloons:";cin>>n;
	vector<int> b;
	cout<<"enter value of each balloon:\n";
	for(int a=0;a<n;a++)
	{
		int p;cin>>p;
		b.push_back(p);
	}
	sol obj;

	int coins=0;
	coins=obj.solve(b,0,0,n);
	cout<<"maximum coins you can earn is: ";
	cout<<coins<<endl;
	
	return 0;
}
