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
bool isEqual(int n,ll a[]){
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1]) return false;
    }
    return true;
}
bool isExist(ll val,ll n,ll a[]){
    for(int i=0;i<n;i++) if(a[i]==val) return true;
    return false;
}
ll countVal(ll val,ll n,ll a[]){
    int count =-1;
    int ans=0;
    for(int i=n-1;i>=0;i--){
        if(a[i]==val){count =0;continue;}
        if(count==-1) continue;
        count++;
        ans+=count;
        a[i] = val;
    }
    for(int i=n-1;i>=0;i--){
        if(a[i]==val){count =0;continue;}
        count++;
        ans+=count;
    }
    return ans;
}
vector<ll> seg;
void create(int start,int end,ll a[],int cur){
    if(start==end){
        seg[cur] = a[start];return;
    }
    int mid = start + (end - start)/2;
    create(start,mid,a,2*cur + 1);
    create(mid+1,end,a,2*cur + 2);
    seg[cur] = gcd(seg[2*cur + 1],seg[2*cur + 2]);
    return;
}
void createSeg(int n,ll a[]){
    ll size = 1<<logv(n);
    if(size!=n) size = 2*size;
    seg.resize(2*size);
    create(0,n-1,a,0);
}
// 
ll query(int start,int end,int left,int right,int cur){
    if(start > right || end < left) return -1;
    if(start<=left && end >=right) return seg[cur];
    int mid = left + (right - left)/2;
    int a1 = query(start,end,left,mid,2*cur + 1);
    int a2 = query(start,end,mid + 1,right,2*cur +2 );
    if(a1!=-1 && a2!=-1) return gcd(a1,a2);
    if(a1!=-1) return a1;
    return a2;
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
        ll n;cin>>n;
        ll a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        createSeg(n,a);
        int start = 0,end = n;
        int ans;
        while(start<=end){
            int mid = start + (end-start)/2;
            int b[n];
            for(int i=0;i<n;i++){
                int second = (i + mid)%n;
                if(i <= second){
                    b[i] = query(i,second,0,n-1,0);
                }else{
                    b[i] = gcd(query(i,n-1,0,n-1,0),query(0,second,0,n-1,0));
                }
            }   
            bool flag = true;
            for(int i=1;i<n;i++){
                if(b[i]!=b[i-1]){flag = false;break;}
            }
            if(flag){
                ans = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        cout<<ans;nl;
    }
    return 0;
}
