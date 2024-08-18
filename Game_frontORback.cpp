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
 
int dp[5005][5005];
vector<int>a;
int f(int i,int j)
{
	if(i==j) return a[i];
	if(i>j) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
 
	int choice1=a[i]+min(f(i+2,j),f(i+1,j-1));//rem coins:[i+1,....j]
	int choice2=a[j]+min(f(i,j-2),f(i+1,j-1));// rem coins:[i,.....j-1]
	return dp[i][j]=max(choice1,choice2);
 
}
void solve()
{
	memset(dp,-1,sizeof(dp));
	int n;cin>>n;
	a.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<f(0,n-1);
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
