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

ll n,m,x;
bool flag = true;

void solve(){
  cin >> n >> m;
  vector<pair<ll,ll>> poczotek(n);
  vector<ll> last(n);
  for(ll i = 0; i < n; i++) cin >> poczotek[i].first;
  for(ll i = 0; i < n; i++) cin >> poczotek[i].second;
  sort(poczotek.begin(), poczotek.end(), greater());
  for(ll i = 0; i < n; i++) last[i] = poczotek[i].second;
  multiset<ll> st;
  for(ll i = 0; i < m; i++){
    for(ll j = 0; j < n; j++){
      cin >> x;
      st.emplace(x);
    }
    for(int j = 0; j < n; j++){
      ll el = last[j];
      if(st.lower_bound(el) == st.end()){
        // nie ma wyniku
        flag = false;
      } else{
        last[j] = *st.lower_bound(el);
        st.erase(st.lower_bound(el));
      }
    }
    // for(auto el : last) cout << el << ' ';
    // cout << endl;
  }
  if(!flag){
    cout << "NIE\n";
  } else{
    ll res = 0;
    for(ll i = 0; i < n; i++){
      res += poczotek[i].first * (last[i] - poczotek[i].second);
    }
    cout << res << endl;
  }
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

  solve();
}