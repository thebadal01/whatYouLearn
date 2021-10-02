#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define newline cout<<"\n";
const ll mod = 998244353 ;
ll gcd(ll a,ll b){ return a?gcd(b%a,a):b; }
ll minv(ll a,ll b){ return a<b?a:b;}
ll maxv(ll a,ll b){ return a>b?a:b;}
void swapv(ll &a,ll &b){a=a+b;b=a-b;a=a-b;}
ll power(ll a, ll b, ll m=mod){
    if(a==0 || b==1) return a;
    if(b==0) return 1;
    ll ans=1;
    while(b>=1){ if(b&1){b--;ans = (ans*a) % m;}a = (a*a)% m;b = b>>1;}
    return ans;
}
ll logv(ll x){ll ans =-1;while(x){x = x>>1;ans++;}return ans;}
ll inv(ll a,ll m){return power(a,m-2,m);}


const ll mn = 1e6 + 5;
ll factor[mn];
void sieve()
{
    for(int i=1;i<mn;i++) factor[i] = 2;
    factor[1] = 1;
    for(int i=2;i<mn;i++)
    {
            for(int j = 2*i;j<mn;j+=i)
            factor[j]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
    sieve();
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif 
    ll n;
    cin>>n;
    ll dp[n+1];
    if(n==1){
        cout<<"1";
    }else if(n==2){
        cout<<"3";
    }else{
        dp[1] = 1;
        dp[2] = 3;
        ll sum = 4;
        // cout<<factor[100];newline
        for(int i=3;i<=n;i++)
        {
            dp[i] = (sum + factor[i])%mod;
            sum = (sum + dp[i])%mod;
        }
        cout<<dp[n];
    }
    return 0;
}
