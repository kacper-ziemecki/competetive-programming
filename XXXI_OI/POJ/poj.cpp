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

ll n,k;
pair<ll,ll> tmp,mx,mn;

void solve(){
  cin >> n >> k;
  vector<ll> lista(n);
  vector<vector<ll>> res;
  for(auto &el : lista) cin >> el;
  set<pair<ll,ll>> st;

  for(int i = 0; i < n; i++) st.emplace(make_pair(lista[i], i));

  for(int i = 0; i < n; i++){
    if(st.empty()) break;

    mn = *st.begin();
    mx = *st.rbegin();

    st.erase(st.begin());
    if(mn.second == mx.second) mx.first = 0;
    else st.erase(prev(st.end()));
    // dbg(mn.first,mn.second,mx.first,mx.second);
    ll one = min(k, mn.first);
    ll two = min(k-one, mx.first);
    // dbg(one,two);
    lista[mn.second] -= one;
    lista[mx.second] -= two;
    // dbg(lista[mn.second], lista[mx.second]);
    if(lista[mn.second] != 0) st.emplace(make_pair(lista[mn.second], mn.second));
    if(lista[mx.second] != 0) st.emplace(make_pair(lista[mx.second], mx.second));
    res.pb({mn.second, one, mx.second, two});
  }
  // for(auto el : lista) cout << el << ' ';
  // cout << endl;
  for(auto el : lista){
    if(el > 0){
      cout << "NIE\n";
      return;
    }
  }
  cout << "TAK\n";
  for(auto sub : res){
    if(sub[1] == 0 && sub[3] == 0){
      cout << 0 << endl;
    } else if(sub[3] == 0){
      cout << 1 << ' ' << sub[0]+1 << ' ' << sub[1] << endl;
    } else{
      cout << 2 << ' ' << sub[0]+1 << ' ' << sub[1] << ' ' << sub[2]+1 << ' ' << sub[3] << endl;
    }
  }
  for(int i = 0; i < n-res.size(); i++){
    cout << 0 << endl;
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