#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define newline cout<<"\n";
const int mod = 1e9+7;
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

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif 
    ll n;
    cin>>n;
    ll tem;
    multiset<ll> st;
    ll sum =0,ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>tem;
        st.insert(tem);
        sum +=tem;
        // cout<<"Sum : "<<sum;newline
        while(sum<0){
            sum -= *(st.begin());
            st.erase(st.begin());
        }
        // cout<<"Size  : "<<st.size();newline
        ans = maxv(ans,st.size());
    }
    cout<<ans;
    return 0;
}
