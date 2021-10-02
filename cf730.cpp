// Keshav Agarwal, Codechef_handle = agarwal_keshav; codeforces_handle = k_agarwal
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define nl cout<<"\n";
#define fix(f,n) cout<<fixed<<setprecision(n)<<f
const int mod = 1e9+7;
template<typename ...T>
void debug(T&&... args){ ((cerr << args << " "), ...);cerr<<"\n";}
ll gcd(ll a,ll b){ return a?gcd(b%a,a):b; }
ll minv(ll a,ll b){ return a<b?a:b;}
ll maxv(ll a,ll b){ return a>b?a:b;}
void swapv(ll &a,ll &b){a=a+b;b=a-b;a=a-b;}
ll power(ll a, ll b, ll m=mod){
    if(a==0 || b==1) return a;
    if(b==0) return 1;ll ans=1;
    while(b>=1){ if(b&1){b--;ans = (ans*a) % m;}a = (a*a)% m;b = b>>1;}return ans;
}
ll logv(ll x){ll ans =-1;while(x){x = x>>1;ans++;}return ans;}
ll inv(ll a,ll m){return power(a,m-2,m);}
int v;
const double scale = 1e6;

double go(int c,int m,int p,int cnt=0){
    cnt++;
    double ans = (p*cnt/scale);
    if(c>0){
        if(c>v){
            if(m>0){
                ans += (c/scale)*(go(c-v,m + (v)/2,p + (v)/2,cnt));
            }else{
                ans += (c/scale)*(go(c-v,0,(v) + p,cnt));
            }
        }else{
            if(m>0){
                ans += (c/scale)*(go(0,m + c/2 ,p + c/2,cnt));
            }else{
                ans += (c/scale)*(go(0,0,p + c,cnt));
            }
        }
    }
    if(m>0){
        if(m>v){
            if(c>0){
                ans += (m/scale)*(go(c+ (v)/2,m-v,p + (v)/2,cnt));
            }else{
                ans += (m/scale)*(go(0,m-v,(v) + p,cnt));
            }
        }else{
            if(c>0){
                ans += (m/scale)*(go(c + m/2,0 ,p + m/2,cnt));
            }else{
                ans += (m/scale)*(go(0,0,p + m,cnt));
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout);
        freopen("error.txt","w",stderr); 
    #endif 
    ll t=1;
    cin>>t;
    while(t--)
    {
        float c1,m1,p1,v1;
        cin>>c1>>m1>>p1>>v1;
        int c= round(c1*scale);
        int m = round(m1*scale);
        int p = round(p1*scale);
        v = round(v1*scale);
        fix(go(c,m,p),10);nl;
    }
    return 0;
}
