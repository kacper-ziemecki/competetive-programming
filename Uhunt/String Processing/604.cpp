#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void search(vector<vector<char>>& list, vector<vector<bool>>& vis, map<string, bool>& mp, ll i, ll j, string s = "", ll cnt=0){
  if(s.size()==4){ mp[s] = (cnt==2); return; }
  if(i < 0 || j < 0 || i >= 4 || j >= 4) return;
  if(vis[i][j]) return;
  s += list[i][j];
  vis[i][j]=true;
  if(list[i][j] == 'A' || list[i][j] == 'E' || list[i][j] == 'I' || list[i][j] == 'O' || list[i][j] == 'U' || list[i][j] == 'Y') cnt++;
  vector<ll> dx{-1,0,1,1,1,0,-1,-1}, dy{-1,-1,-1,0,1,1,1,0};
  for(ll x = 0; x < 8; x++) search(list,vis,mp,i+dy[x],j+dx[x],s,cnt);
  vis[i][j]=false;
}

void solve(ll t)
{
  vector<vector<char>> one(4, vector<char>(4, ' ')), two(4, vector<char>(4, ' '));
  char a;
  for(ll i = 0; i < 4; i++){
    for(ll j = 0; j < 4; j++){
      cin >> a;
      if(a == '#') return;
      one[i][j] = a;
    }
    for(ll j = 0; j < 4; j++){
      cin >> a;
      two[i][j] = a;
    }
  }
  map<string, bool> mp1,mp2;
  for(ll i = 0; i < 4; i++){
    for(ll j = 0; j < 4; j++){
      vector<vector<bool>> vis(4, vector<bool>(4, false));
      search(one, vis, mp1, i, j);
    }
  }
  for(ll i = 0; i < 4; i++){
    for(ll j = 0; j < 4; j++){
      vector<vector<bool>> vis(4, vector<bool>(4, false));
      search(two, vis, mp2, i, j);
    }
  }
  // for(auto el : mp2) cout << el.first << " " << el.second << endl;
  vector<string> res;
  for(auto el : mp1){
    if(mp2[el.first]) res.push_back(el.first);
  } 
  if(t) cout << endl;
  if(res.empty()){
    cout << "There are no common words for this pair of boggle boards.\n";
    return;
  }
  for(auto el : res) cout << el << endl;
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

  for(ll i = 0; !cin.eof(); i++){
    solve(i);
  }
}