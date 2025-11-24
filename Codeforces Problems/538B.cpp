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
  string s,cur;
  cin >> s;
  vector<string> res;
  for(ll i = 0; i < 9; i++){
    cur.clear();
    for(ll j = 0; j < s.size(); j++){
      if(s[j]>'0'){
        cur += '1';
        s[j] -= 1;
      }
      else if(s[j]=='0' && !cur.empty()){
        cur += '0';
      }
    }
    if(!cur.empty()) res.push_back(cur);
  }
  cout << res.size() << endl;
  for(auto el : res) cout << el << " ";
  cout << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../in.in", "r", stdin);
  freopen("../out.out", "w", stdout);
#endif

  solve();  
  
} 