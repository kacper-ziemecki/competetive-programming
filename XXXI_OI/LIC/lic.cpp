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

ll n,x,cur,idx=0;
const ll maxn = 5e5+2;
pair<ll,ll> lista[maxn];
pair<ll,ll> nxt[maxn];
vector<ll> res;
bool have_to_change = false;

void solve(){
  cin >> n >> x;
  for(ll i = 0; i < n-1; i++){
    cin >> lista[i].first >> lista[i].second;
  }
  cur = x;
  for(ll i = 0; i < n-1; i++){
    if(i > 0 && ((lista[i-1].first >= lista[i-1].second) != (lista[i].first >= lista[i].second))) break;
    if(abs(lista[idx].first-lista[idx].second) > abs(lista[i].first-lista[i].second)) idx = i;
    // jezeli sa first i second rowne to zakladamy, ze idziemy do gory, pozniej najwyzej to zmienimy
    if(lista[i].first >= lista[i].second) cur++;
    else cur--;
    if(cur < 1 || cur > n){
      have_to_change = true;
      break;
    }
  }
  if(have_to_change){
    if(lista[idx].first >= lista[idx].second) lista[idx].second = LLONG_MAX;
    else lista[idx].first = INT_MAX;
  }
  for(ll i = n-2; i >= 0; i--){
    if(lista[i].first >= lista[i].second){
      nxt[i].second = nxt[i+1].second+1;
    } else{
      nxt[i].first = nxt[i+1].first+1;
    }
  }
  res.pb(x);
  ll cost = 0, pos;
  ll lewo = 1, prawo = n;
  for(ll i = 0; i < n-1; i+=max(nxt[i].first,nxt[i].second)){
    if(lista[i].first >= lista[i].second){ // idziemy do gory
      pos = prawo-nxt[i].second+1;
      if(pos <= x && prawo >= x) pos--;
      prawo = pos-1;
    } else{ //idziemy na dul
      pos = lewo+nxt[i].first-1;
      if(pos >= x && lewo <= x) pos++;
      lewo = pos+1;
    }
    for(ll j = 0; j < max(nxt[i].first,nxt[i].second); j++){
      cost += min(lista[i+j].first, lista[i+j].second);
      if(lista[i].first >= lista[i].second){ // idziemy do gory
        if(pos == x) pos++;
        res.pb(pos);
        pos++;
      } else{ // idziemy na dul
        if(pos == x) pos--;
        res.pb(pos);
        pos--;
      }
    }
  }
  cout << cost << endl;
  for(auto el : res) cout << el << ' ';
  cout << endl;
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