#include<bits/stdc++.h>
#define ll long long
#define forl(i,x,n) for(ll i=x;i<n;i++)
#define forr(i,x,n) for(ll i=n-1;i>=x;i--)
using namespace std;

ll solve(ll sz, vector<ll> fab){
 vector<ll> freak;
		freak.push_back(1);
		forl(i,0,sz){
			freak.push_back(fab[i]);
		}
		freak.push_back(1);
		vector<vector<ll>> dp(sz+2,vector<ll>(sz+2));
		forl(l,3,sz+3){
			forl(i,0,sz+3-l){
				forl(j,i+1,i+l-1){
					dp[i][i+l-1]=max(dp[i][i+l-1],freak[i]*freak[i+l-1]*freak[j]+dp[i][j]+dp[j][i+l-1]);
				}
			}
		}

		return dp[0][sz+1];
}

int main(){
    // #ifndef ONLINE_JUDJE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    ll sz;
    cin >> sz;
    vector<ll> fab(sz);
    forl(i, 0, sz) cin >> fab[i];
    cout << solve(sz, fab) << endl;
    return 0;
  }
