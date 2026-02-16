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

struct Node{
  ll a,b,start;
};

struct cmp{
  bool operator() (const Node &a, const Node &b) const{
    if(a.a*b.b == b.a*a.b) return a.start > b.start;
    return a.a*b.b < b.a*a.b;
  }
};


ll n,X,z;
ll cnt = 0;
priority_queue<Node, vector<Node>, cmp> dist;
Node tmp;
void solve(){
  cin >> n >> X >> z;
  vector<ll> lista(n);
  vector<pair<ll,ll>> zapytania(z);
  vector<pair<ll,ll>> res(z);
  for(auto &el : lista) cin >> el;
  for(ll i = 1; i < n; i++){
    tmp.a = lista[i]-lista[i-1];
    tmp.b = 1;
    tmp.start = lista[i-1];
    dist.push(tmp);
  }
  // for(auto el : dist){
  //   dbg(el[0],el[1],el[2]);
  // }
  for(ll i = 0; i < z; i++){
    cin >> zapytania[i].first;
    zapytania[i].second = i;
  }
  sort(zapytania.begin(), zapytania.end());
  for(auto el : zapytania){
    ll k = el.first;
    while(k > cnt+dist.top().b){
      cnt += dist.top().b;
      tmp = dist.top(); dist.pop();
      tmp.b <<= 1;
      dist.push(tmp);
    }
    k -= cnt;
    // dbg(dist.top().a, dist.top().b, dist.top().start);
    // dbg(k);
    // dbg((*dist.begin())[0],(*dist.begin())[1], (*dist.begin())[2]);
    res[el.second].first = dist.top().start*dist.top().b*2+dist.top().a+(k-1)*2*dist.top().a;
    // res[el.second].first = (*dist.begin())[2]*(*dist.begin())[1]*2+(*dist.begin())[0] + (k-1)*2*(*dist.begin())[0];
    res[el.second].second = dist.top().b*2;
    // res[el.second].second = (*dist.begin())[1]*2;
  }
  for(auto el : res){
    // dbg(el.first,el.second);
    cout << el.first/__gcd(el.first,el.second) << '/' << el.second/__gcd(el.first,el.second) << endl;
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