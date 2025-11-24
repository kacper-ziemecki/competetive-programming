#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

bool inBounds(ll x, ll y, ll n, ll m){
  if(x >= 0 && x < n && y >= 0 && y < m) return true;
  return false;
}

ll dfs(ll x, ll y, ll n, ll m, vector<string> &adj){
  adj[x][y] = '1';
  // for(auto el : adj) cout << el << endl;
  // cout << "---------\n";
  ll cnt = 1;
  vector<ll> dx{-1, 0, 1, 0};
  vector<ll> dy{0, 1, 0, -1};
  for(ll i = 0; i < 8; i++){
    if(inBounds(x+dx[i], y+dy[i], n, m) && adj[x+dx[i]][y+dy[i]] == '0') cnt += dfs(x+dx[i], y+dy[i], n, m, adj);
  }
  return cnt;
}

ll number(string s){
  if(s.size()==1) return s[0]-'0';
  else return (s[0]-'0')*10+(s[1]-'0');
}
void solve(){
  string s1,s2;
  cin >> s1 >> s2;
  ll a = number(s1)-1, b = number(s2)-1;
  vector<string> adj;
  string s;
  ll n=0,m=0;
  for(ll i = 0;; i++){
    if(i==0) getline(cin >> ws, s);
    else getline(cin, s);

    if(s.size() == 1) break;
    adj.push_back(s);
    n++;
    if(cin.eof()) break;
  }
  if(n) m = adj[0].size();
  cout << dfs(a, b, n, m, adj) << endl;
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