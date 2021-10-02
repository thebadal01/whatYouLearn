#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i,j,n) for(ll i=j;i<n;i++)
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
ll inv(ll a,ll m){return power(a,m-2,m);}

class sol{
    public:
    int i,j,x,y;
};

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif 
    ll t=1;
    cin>>t;
    ll n;
    while(t--)
    {
        cin>>n;
        ll a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        ll mine = a[0];
        ll pos = 0;
        for(int i=1;i<n;i++){
            if(a[i]<mine){
                mine = a[i];
                pos = i;
            }
        }
        ll tem = pos;
        tem = tem-2;
        sol ans[n-1];
        int point = 0;
        while(tem>=0){
            ans[point].i = tem;
            ans[point].j = pos;
            ans[point].x = mine;
            ans[point].y = mine;
            tem -=2;
            point++;
        }
        tem = pos + 2;
        while(tem<n){
            ans[point].i = tem;
            ans[point].j = pos;
            ans[point].x = mine;
            ans[point].y = mine;
            tem +=2;
            point++;
        }
        tem = pos-1;
        while(tem>=0){
            ans[point].i = tem;
            ans[point].j = pos;
            ans[point].x = mine+1;
            ans[point].y = mine;
            tem -=2;
            point++;
        }
        tem = pos + 1;
        while(tem<n){
            ans[point].i = tem;
            ans[point].j = pos;
            ans[point].x = mine+1;
            ans[point].y = mine;
            tem +=2;
            point++;
        }
        cout<<n-1<<"\n";
        for(int i=0;i<(n-1);i++)
        {
            cout<<(ans[i].i+1)<<" "<<(ans[i].j+1)<<" "<<ans[i].x<<" "<<ans[i].y<<"\n";
        }
    }
    return 0;
}
