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
        ll n;cin>>n;
        ll a[n+1];
        for(int i=1;i<=n;i++) cin>>a[i];
        ll ans[n+1]={0};
        bool visit[n+1];
        memset(visit,false,sizeof(visit));
        int k=0;
        vector<int> v2;
        queue<int> v1;
        for(int i=1;i<=n;i++){
            if(!visit[a[i]]){
                ans[i] = a[i];
                k++;
                visit[a[i]] = true;
            }else{
                v1.push(i);
            }
        }
        for(int i=1;i<=n;i++){
            if(!visit[i]) v2.push_back(i);
        }
        int i=0,j= v2.size()-1;
        while(!v1.empty()){
            int top = v1.front();
            if(top!=v2[i]){
                ans[top] = v2[i];i++;
            }else if(i!=j){
                ans[top] = v2[j];
                j--;
            }else{
                int tem = a[top];
                for(int p=1;p<=n;p++){
                    if(p!=top && a[p]==tem){
                        ans[top] = ans[p];
                        ans[p] = v2[i];
                        break;
                    }
                }
            }
            v1.pop();
        }
        cout<<k;nl;
        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        nl;
    }
    return 0;
}
