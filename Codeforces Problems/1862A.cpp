#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

bool helper(ll i, vector<string> list, string text, ll j){
  // dbg(i, j);
  if(j < 0) return true; //we found a possibility
  if(i < 0) return false; //we did not found a possibility

  //not take
  if(helper(i-1, list, text, j)) return true;

  //take
  for(int x = 0; x < list.size(); x++){
    if(list[x][i]==text[j] && helper(i-1, list, text, j-1)) return true;
  }
  return false;
}

void solve()
{
  ll n,m;
  cin >> n >> m;
  string text = "vika";
  vector<string> list(n, " ");
  for(auto &el : list) cin >> el;

  cout << (helper(m-1, list, text, 3) ? "YES" : "NO") << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
#endif

  ll t;
  cin >> t;
  while(t--) solve();
  
}