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
    ll n;cin>>n;
    string s,t;cin>>s>>t;
    int zeros = 0,ones = 0;
    queue<int> que;
    set<int> st1,st2;
    for(int i=0;i<n;i++){
        if(s[i]!=t[i]){
            que.push(s[i]-'0');
            if(s[i]=='0') {zeros++;st1.insert(i);}
            else {ones++;st2.insert(i);};
        }
    }
    if(ones!=zeros){
        cout<<"-1";nl;return 0;
    }
    //0101
    //1010
    int ans =0;
    while(!st1.empty()){
        ans++;
        if(*st1.begin() < *st2.begin()){
            int first = *st1.begin();
            st1.erase(st1.begin());
            bool one = true;
            int pre = first;
            set<int>::iterator it;
            while(true){
                if(one){
                    it = st2.lower_bound(pre);
                    if(it==st2.end()) break;
                    pre = *it;
                    st2.erase(it);
                    one = false;
                }else{
                   it = st1.lower_bound(pre);
                   if(it==st1.end()) break;
                   pre = *it;
                   st1.erase(it);
                    one = true;
                }
            }
            if(one){
                st1.insert(first);
            }
        }else{
            int first = *st2.begin();
            st2.erase(st2.begin());
            bool one = false;
            int pre = first;
            set<int>::iterator it;
            while(true){
                if(one){
                    it = st2.lower_bound(pre);
                    if(it==st2.end()) break;
                    pre = *it;
                    st2.erase(it);
                    one = false;
                }else{
                   it = st1.lower_bound(pre);
                   if(it==st1.end()) break;
                   pre = *it;
                   st1.erase(it);
                    one = true;
                }
            }
            if(!one){
                st2.insert(first);
            }
        }
    }
    cout<<ans;
    return 0;
}
