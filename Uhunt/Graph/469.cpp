#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

map<pair<ll, ll>, ll> mp;

ll dfs(ll x, ll y, vector<string>& adj, ll n, ll m, ll el = 0){
  ll cnt = 1;
  adj.at(x).at(y) = '0';
  if(el){ 
    mp[{x,y}] = el;
    adj.at(x).at(y) = '1';
  }
  vector<pair<ll,ll>> dirs{{-1,-1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
  for(auto dir : dirs){
    if(x+dir.first >= 0 && x+dir.first < n && y+dir.second >= 0 && y+dir.second < m && adj[x+dir.first][y+dir.second] != 'L' && (el ? adj[x+dir.first][y+dir.second] != '1' : adj[x+dir.first][y+dir.second] != '0')) cnt += dfs(x+dir.first, y+dir.second, adj, n, m, el);
  }
  return cnt;
}

void solve(){
  mp.clear();
  vector<string> one;
  vector<pair<ll, ll>> two;
  pair<ll, ll> tmp;
  string s;
  while(getline(cin >> ws, s), s[0] == 'W' || s[0] == 'L'){
    // dbg(s);
    one.push_back(s);
  }
  stringstream stream;
  stream << s;
  stream >> tmp.first >> tmp.second;
  two.push_back(tmp);
  while(getline(cin, s), s.size() != 1 && !cin.eof()){
    // dbg(s, s.size(), s[0]);
    stream << s;
    stream >> tmp.first >> tmp.second;
    // dbg(tmp.first, tmp.second);
    two.push_back(tmp);
  }
  ll n = one.size(), m = one.at(0).size()-1;
  // dbg(n, m);
  ll cnt;
  for(ll i = 0; i < n; i++){
    for(ll j = 0; j < m; j++){
      if(one[i][j] == 'W'){
        cnt = dfs(i, j, one, n, m);
        // for(auto el : one) cout << el << endl;
        // dbg(cnt);
        dfs(i, j, one, n, m, cnt);
        // for(auto el : one) cout << el << endl;
        // cout << "----------\n";
      }
    }
  }
  // cout << "one:\n";
  // for(auto el : one) cout << el << endl;
  for(auto el : two){
    // dbg(el.first, el.second);
    cout << mp[{el.first-1, el.second-1}] << endl;
  }
}
 
int main()
{
 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 
#ifndef ONLINE_JUDGE
  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);
#endif
  
  ll t;
  cin >> t;
  for(ll i = 0; i < t; i++){
    if(i!=0) cout << endl;
    solve();
  }
}