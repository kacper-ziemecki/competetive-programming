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

int n;
const int maxn = 1001;
int parent[maxn];
vector<int> children[maxn];

void solve(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> parent[i];
    children[parent[i]].pb(i+2);
  }
  for(int i = 1; i <= n; i++){
    int cnt = 0;
    if(children[i].size() == 0) continue;
    for(auto child : children[i]){
      cnt += (children[child].size() ? 0 : 1);
    }
    if(cnt < 3){
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
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