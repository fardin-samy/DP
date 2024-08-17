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
void f(vector<int>&a,int ind,int tar,vector<vector<int>>&dp)
{
	// if(tar==0) return 1;
	// if(ind==0) return a[0]==tar;
	for(int i=0;i<=ind;i++)
	{
		dp[i][0]=1;
	}
	for(int i=0;i<=tar;i++)
	{
		dp[0][a[0]]=1;
	}
	// if(dp[ind][tar]!=-1) return dp[ind][tar];
	for(int i=1;i<=ind;i++)
	{
		for(int j=1;j<=tar;j++)
		{
			int taken=0;
			if(a[i]<=j)
			taken=dp[i-1][j-a[i]];
			int notTaken=dp[i-1][j];
			dp[i][j]=taken || notTaken;
		}
	}
	// return dp[ind][tar];
}
void solve()
{
	int n;cin>>n;
	vector<int>coins(n);
	int tar=0;
	for(int i=0;i<n;i++) cin>>coins[i],tar+=coins[i];
	vector<vector<int>>dp(n,vector<int>(tar+1,0));
	f(coins,n-1,tar,dp);
	int cnt=0;
	for(int i=1;i<=tar;i++)
	{
		if(dp[n-1][i]!=0) cnt++;
	}
	cout<<cnt<<endl;
	for(int i=1;i<=tar;i++)
	{
		if(dp[n-1][i]!=0) cout<<i<<' '; 
	}
	cout<<endl;
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
