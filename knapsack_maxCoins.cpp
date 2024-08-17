#include<bits/stdc++.h>
#define endl '\n'
#define fs first
#define ss second
#define pi acos(-1.0)
#define pb push_back
#define int long long
#define inf 1e18
#define fr(b) for(int i=0;i<b;i++)
#define srt(a) sort(a.begin(),a.end())
#define rsrt(a) sort(a.rbegin(),a.rend())
#define khelaSesh return 0
#define FAST ios_base::sync_with_stdio(false),cin.tie(NULL)
const int N=2e5+10;
const int mod=1e9+7;
using namespace std;
int f(int ind,int tar,vector<int>&arr,vector<vector<int>>&dp)
{
	if(tar==0) return 0;
	if(tar<0 or ind<0) return -inf;
	if(dp[ind][tar]!=-1) return dp[ind][tar];
	int taken=-inf;
	if(arr[ind]<=tar)
	taken=1+f(ind,tar-arr[ind],arr,dp);
	int notTaken=f(ind-1,tar,arr,dp);
	return dp[ind][tar]=max(notTaken,taken);

}
void solve()
{
	int n,a,b,c;cin>>n>>a>>b>>c;
	vector<int>arr={a,b,c};
	vector<vector<int>>dp(3,vector<int>(n+1,-1));
	cout<<f(2,n,arr,dp);
}
int32_t main()
{
   FAST;
	int tc;
	tc=1;
	// cin>>tc;
	while(tc--)
	solve();
	khelaSesh;
}
