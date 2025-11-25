#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n,res=0;
vector<int> a,b;

int get_max(int l, int r){
  int cur=INT_MIN;
  for(int i = l; i <= r; i++) cur = max(cur, a[i]);
  return cur;
}
int get_min(int l, int r){
  int cur=INT_MAX;
  for(int i = l; i <= r; i++) cur = min(cur, b[i]);
  return cur;
}

void solve(){
  cin >> n;
  a.resize(n); b.resize(n);
  for(auto &el : a) cin >> el;
  for(auto &el : b) cin >> el;
  for(int i = 0; i < n; i++){
    for(int j = i; j < n; j++){
      int mx = get_max(i,j);
      int mn = get_min(i,j);
      if(mx == mn) res++;
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

  solve();
}