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
int lis(int i,vector<int>&a,vector<int>&dp)
{
	if(dp[i]!=-1) return dp[i];
	int ans=1;
	for(int j=0;j<i;j++)
	{
		if(a[i]>a[j]) 
		{
			ans=max(ans,1+lis(j,a,dp));
		}
	}
	return dp[i]=ans;

}
void solve()
{
	int n;cin>>n;
	vector<int>a(n);
	fr(n) cin>>a[i];
	vector<int>dp(n,-1);
	int mx=0;
	for(int i=0;i<n;i++)
	{
		mx=max(mx,lis(i,a,dp));
	}
	cout<<mx<<endl;


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
