#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll n,m;
ull suma=0;
ll mozliwosci=1;
const ll MOD = 1000000007;
const ll N = 2e5+1;
ll silnia[N], inv_silnia[N];
ll zostanie[N], st_sajz[N], biggest_not_taken_sajz[N];
set<ll> st;
set<ll> biggest_not_taken;
vector<pair<char,ll>> lista;
string s;
ll cnt;
char prv = 'A';
ll nie_wybrane = 0;

ll P(ll n, ll r){
  return (silnia[n] * inv_silnia[n-r]) % MOD;
}

ll binpow(ll a, ll b){
  ll res = 1;
  while(b){
    if(b&1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}

void solve(){
  cin >> n >> m >> s;
  for(auto c : s){
    if(c != prv){
      prv = c;
      lista.pb(make_pair(c, 1));
    } else{
      lista.back().second++;
    }
  }
  for(ll i = 1; i <= n; i++) biggest_not_taken.emplace(i);
  ll idx=0;
  for(auto el : lista){
    if(el.first == 'C'){
      for(ll i = 0; i < el.second && st.size() != n; i++){
        st.emplace(*biggest_not_taken.rbegin());
        biggest_not_taken.erase(*biggest_not_taken.rbegin()); 
      }
    } else{
      for(ll i = 0; i < el.second && !st.empty(); i++){
        biggest_not_taken.emplace(*st.rbegin());
        st.erase(*st.rbegin());
      }
    }
    st_sajz[idx] = st.size();
    biggest_not_taken_sajz[idx] = biggest_not_taken.size();
    idx++;
  }

  zostanie[--idx] = st.size();
  // dbg(zostanie[idx]);
  for(ll i = idx-1; i >= 0; i--){
    zostanie[i] = min(st_sajz[i], zostanie[i+1]);
  }
  // for(ll i = 0; i < m; i++) dbg(i, zostanie[i]);
  biggest_not_taken.clear();
  st.clear();
  for(ll i = 1; i <= n; i++) biggest_not_taken.emplace(i);
  idx = -1;
  for(auto el : lista){
    idx++;
    if(el.first == 'C'){
      ll ile_podlewamy_drzew = min((ll)el.second, (ll)biggest_not_taken.size())-(zostanie[idx]-nie_wybrane);
      mozliwosci = (mozliwosci * P(el.second, ile_podlewamy_drzew)) % MOD;
      for(ll i = 0; i < ile_podlewamy_drzew && st.size() != n; i++){
        st.emplace(*biggest_not_taken.rbegin());
        biggest_not_taken.erase(*biggest_not_taken.rbegin()); 
      }
      nie_wybrane = zostanie[idx];
    } else{
      mozliwosci = (mozliwosci * P(el.second, min((ll)el.second, (ll)st.size()))) % MOD;
      for(ll i = 0; i < el.second && !st.empty(); i++){
        suma += *st.rbegin();
        biggest_not_taken.emplace(*st.rbegin());
        st.erase(*st.rbegin());
      }
    }
    // dbg(idx,mozliwosci);
  }
  cout << suma << ' ' << mozliwosci << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../in.in", "r", stdin);
//   freopen("../../out.out", "w", stdout);
// #endif

  ll sil=1;
  silnia[0]=1;
  inv_silnia[0] = binpow(1, MOD-2);
  for(int i = 1; i < N; i++){
    sil = (sil * i) % MOD;
    silnia[i] = sil;
    inv_silnia[i] = binpow(silnia[i], MOD-2);
  }

  solve();
}