#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

bool search(vector<string>& list, vector<vector<bool>>& vis, string s, ll i, ll j, ll k=0){
  if(k == s.size()) return true;
  if(i < 0 || j < 0 || i >= 4 || j >= 4) return false;
  if(list[i][j] != s[k]) return false;
  if(vis[i][j]) return false;
  vis[i][j] = true;
  vector<ll> dx{-1,0,1,1,1,0,-1,-1}, dy{-1,-1,-1,0,1,1,1,0};
  for(ll x = 0; x < 8; x++){
    if(search(list,vis,s,i+dy[x],j+dx[x],k+1)) return true;
  }
  vis[i][j] = false;
  return false;
}

ll length(string s){
  if(s.size() == 3 || s.size() == 4) return 1;
  else if(s.size() == 5) return 2;
  else if(s.size() == 6) return 3;
  else if(s.size() == 7) return 5;
  else if(s.size() >= 8) return 11;
  else return 0;
}

void solve()
{
  vector<string> one(4);
  for(auto &el : one) cin >> el;
  ll n;
  cin >> n;
  vector<string> two(n);
  for(auto& el : two) cin >> el;
  ll res = 0;
  for(auto text : two){
    bool flag = false;
    for(ll i = 0; i < 4; i++){
      for(ll j = 0; j < 4; j++){
        vector<vector<bool>> vis(4, vector<bool>(4, false));
        if(search(one,vis,text,i,j)){
          res += length(text);
          flag = true;
          break;
        }
      }
      if(flag) break;
    }
  }
  cout << res << endl;
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
  for(ll i = 1; i <= t; i++){
    cout << "Score for Boggle game #" << i << ": ";
    solve();
  }
}