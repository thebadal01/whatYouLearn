// Jai Shree Ram⛳⛳⛳
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

ll giveNum(int a[],int start,int end){
    ll ans =0;
    for(int i=start;i<=end;i++){
        ans = ans*10 + a[i];
    }
    return ans;
}

ll giveMaxNum(int val,int digit){
    ll ans =0;
    for(int i=0;i<digit;i++) ans = ans*10 + val;
    return ans;
}

bool isExist(int a[],int end,int num){
    for(int i=0;i<=end;i++){
        if(a[i]==num) return true;
    }
    return false;
}

void makeChange(int newa[],set<int> st,int start,int end){
    int a[12];
    for(int i=start;i<=end;i++) a[i] = newa[i];
    for(int i=end;i>=start;i--){
        if((a[i]/10)!=0){
            a[i-1]++;a[i] = a[i]%10;
        }
        if(a[i] > *st.rbegin()){
            a[i]= *st.begin();
            a[i-1]++;
        }else{
            a[i] = *(st.lower_bound(a[i]));
        }
    }
    for(int i=start;i<=end;i++){
        if(a[i]!=newa[i]){
            for(int j=i+1;j<=end;j++){
                a[j] = *st.begin();
            }
            break;
        }
    }
    for(int i=start;i<=end;i++) newa[i] = a[i];
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
        ll n,k;cin>>n>>k;
        int count =0;
        ll tem = n;
        set<int> st;
        while(tem){
            count++;tem = tem/10;
        }
        int a[count];
        tem = n;
        for(int i=count-1;i>=0;i--){
            a[i] = tem%10;
            tem = tem/10;
        }
        int last;
        for(int i=0;i<count;i++){
            st.insert(a[i]);
            if(st.size()<=k) last = i;
            else{
                st.erase(a[i]);
                break;
            }
        }
        if(last==count-1){
            cout<<n;nl;continue;
        }
        while(last>=0){
            vector<int> pos;
            if(isExist(a,last-1,a[last])){
                for(auto x:st){
                    if(x>=a[last]) pos.push_back(x);
                }
            }else{
                st.erase(a[last]);
                for(int i=a[last];i<=9;i++) pos.push_back(i);
            }
            bool flag = false;
            for(int i=0;i<pos.size();i++){
                ll num1 = giveNum(a,last+1,count-1);
                ll mxn  = giveMaxNum(maxv(pos[i],st.empty()?0:(*st.rbegin())),count-last-1);
                if(st.size()==k-1 && isExist(a,last-1,pos[i])){
                    a[last] = pos[i];
                    for(int j=last+1;j<count;j++) a[j] =0;
                    flag = true;break;
                }
                if(pos[i]!=a[last]){
                    a[last] = pos[i];
                    st.insert(pos[i]);
                    for(int j=last+1;j<count;j++) a[j] = *(st.begin());
                    flag = true;break;
                }
                if(num1 > mxn){
                    continue;
                }
                st.insert(pos[i]);
                flag = true;
                a[last] = pos[i];
                makeChange(a,st,last+1,count-1);
                break;
            }
            if(flag) break;
            last--;
        }
        for(int i=0;i<count;i++){
            cout<<a[i];
        }
        nl;
    }
    return 0;
}
