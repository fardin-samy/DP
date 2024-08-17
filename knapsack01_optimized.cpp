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

int f(int ind,int cap,vector<int>&a,vector<int>&b) 
{

	vector<int>prev(cap+1,0),cur(cap+1,0);
	for(int i=a[0];i<=cap;i++)
	{	
		if(a[0]<=cap) prev[i]=b[0];
		else prev[i]=0;
	}
   for(int i=1;i<=ind;i++)
   {
   	for(int j=0;j<=cap;j++)
   	{
   		int notTaken=prev[j];
   		int taken=0;
   		if(a[i]<=j)
   		{
   			taken=b[i]+prev[j-a[i]];
   		}
   		cur[j]=max(taken,notTaken);
   	}
   	prev=cur;
   }
   return prev[cap];
}
 
void solve()
{
	int n,m;
	cin>>n>>m;
	std::vector<int> a(n),b(n);
	fr(n) cin>>a[i];
	fr(n) cin>>b[i];
	cout<<f(n-1,m,a,b)<<endl;
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
