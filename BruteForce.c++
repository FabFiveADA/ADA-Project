#include<iostream>
#include<vector>
#include <cstring>
using namespace std;


class Solution {
public:
    
    
    
    int coins( vector<int>& arr ){
        if( arr.size() == 1 ){
            return arr[0];
        }
        
        int a , max = 0;
        vector<int> temp = arr;
        for( int i = 0 ; i < arr.size() ; i++ ){
            if( i == 0 ){
                a = 1*arr[i]*arr[i+1];
            }else if( i == arr.size()-1 ){
                a = arr[i-1]*arr[i]*1;
            }else {
                a = arr[i-1]*arr[i]*arr[i+1];
            }
            
            arr.erase(arr.begin()+i);
            a += coins( arr );
            arr = temp;
            if( a > max ){
                max = a ;
            }
        }
        
        return max;
    }
    
    int maxCoins(vector<int>& nums) {
        return coins(nums);
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
	Solution  obj;

	int coin=0;
	coin=obj.maxCoins(b);
	cout<<"maximum coins you can earn is: ";
	cout<<coin<<endl;
	
	return 0;
}

Time complexity of brute force approach we used is O(n!) 
Seeing its complexity we clearly see that it is not a suitable method as it is slow on high constraints
