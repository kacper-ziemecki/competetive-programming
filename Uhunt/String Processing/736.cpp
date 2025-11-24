#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


bool search(vector<string>& list, vector<vector<bool>>& vis, string& s, ll i, ll j, vector<tuple<ll,ll,string>>& res, ll k=0, ll poprzedni=0){
  if(k==s.size()) return true;
  if(i < 0 || i >= list.size() || j < 0 || j >= list[0].size()) return false;
  if(list[i][j] != s[k] && list[i][j] != ' ') return false;
  if(vis[i][j]) return false;
  vis[i][j] = true;
  vector<ll> dx{-1,0,1,1,1,0,-1,-1},dy{-1,-1,-1,0,1,1,1,0};
  vector<string> dir{"NW", "N", "NE", "E", "SE", "S", "SW", "W"};
  bool ans=false;
  if(list[i][j] == ' '){
    if(search(list,vis,s,i+dy[poprzedni],j+dx[poprzedni],res,(list[i][j] == ' ' ? k : k+1), poprzedni)){
      if(k==0) res.push_back(make_tuple(i, j, dir[poprzedni]));
      ans = true;
    }
    vis[i][j] = false;
    return ans;
  }
  for(ll x = 0; x < 8; x++){
    if(search(list,vis,s,i+dy[x],j+dx[x],res,(list[i][j] == ' ' ? k : k+1), x)){
      if(k==0) res.push_back(make_tuple(i, j, dir[x]));
      ans = true;
    }
  }
  vis[i][j]=false;
  return ans;
}

ll conversion(string s){
  map<string, ll> mp{{"N", 1}, {"NE", 2}, {"E", 3}, {"SE", 4}, {"S", 5}, {"SW", 6}, {"W", 7}, {"NW", 8}};
  return mp[s];
}

bool comparison(tuple<ll, ll, string>& one, tuple<ll, ll, string>& two){
  if(get<0>(one) != get<0>(two)) return get<0>(one) <= get<0>(two);
  else if(get<1>(one) != get<1>(two))  return get<1>(one) <= get<1>(two);
  else{
    ll uno = conversion(get<2>(one)), dos = conversion(get<2>(two));
    return uno <= dos;
    // return get<2>(one) <= get<2>(two);
  }
}

void solve()
{
  ll n;
  cin >> n;
  vector<string> list(n);
  cin.ignore();
  for(auto &el : list) getline(cin, el);
  string s;
  while(getline(cin, s), !s.empty()){
    // dbg(s.size(), s);
    vector<tuple<ll,ll,string>> res;
    for(ll i = 0; i < n; i++){
      for(ll j = 0; j < n; j++){
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        if(list[i][j] == s[0]) search(list, vis, s, i, j, res);
      }
    }
    sort(res.begin(), res.end(), comparison);
    cout << s << endl;
    if(res.empty()){
      cout << "not found\n";
    }
    for(auto el : res){
      cout << "(" << get<0>(el)+1 << "," << get<1>(el)+1 << ") - " << get<2>(el) << endl;
    }
    cout << endl;
    s.clear();
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
  while(t--) solve();
}