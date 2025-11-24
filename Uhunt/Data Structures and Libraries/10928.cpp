#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void solve()
{
  ll n;
  cin >> n;
  cin.ignore();
  vector<vector<ll>> al(n, vector<ll>());
  for(ll i = 0; i < n; i++){
    string text;
    stringstream line;
    getline(cin, text);
    line << text;
    while(!line.eof()){
      ll tmp;
      line >> tmp;
      al[i].push_back(tmp);
    }
  }
  ll minimum = LONG_LONG_MAX;
  for(ll i = 0; i < n; i++){
    minimum = min(minimum, (ll)al[i].size());
  }
  vector<ll> res;
  for(ll i = 0; i < n; i++){
    if(al[i].size() == minimum){
      res.push_back(i+1);
    }
  }
  for(ll i = 0; i < res.size(); i++){
    if(i > 0) cout << " ";
    cout << res[i];
  }
  
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../input.txt", "r", stdin);
// #endif

  ll t;
  cin >> t;
  for(ll i = 0; i < t; i++){
    if(i > 0) cout << endl;
    solve();
  }
}