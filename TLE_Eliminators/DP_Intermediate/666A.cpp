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

string s;
int n;
const int maxn = 1e4+1;
bool vis[maxn][2];
set<string> res;

void helper(int idx, string prev=""){
  // dbg(idx);
  if(vis[idx][(prev.size() > 2 ? 1 : 0)]) return;
  if(idx <= 4) return;
  vis[idx][(prev.size() > 2 ? 1 : 0)] = true;

  if(idx-2 > 4 && prev != s.substr(idx-2,3)){
    helper(idx-3, s.substr(idx-2,3));
    // dbg(idx-2);
    res.emplace(s.substr(idx-2,3));
  }
  if(idx-1 > 4 && prev != s.substr(idx-1,2)){
    helper(idx-2, s.substr(idx-1,2));
    // dbg(idx-1);
    res.emplace(s.substr(idx-1,2));
  }
}

void solve(){
  cin >> s;
  n = s.size();
  // 0 -> nic nie dodajemy, 1-> dodajemy dlugosc 2, 2-> dodajemy dlugosc 3
  helper(n-1);
  cout << res.size() << endl;
  for(auto el : res) cout << el << endl;
  cout << endl;
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

  solve();
}