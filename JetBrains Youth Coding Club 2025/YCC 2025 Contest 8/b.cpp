#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n;
const int maxn = 1e5+1;
int lista[maxn][2];
map<int,int> mp;

void solve(){
  cin >> n;
  for(int i = 0; i < n; i++) cin >> lista[i][0] >> lista[i][1];
  for(int i = 0; i < n; i++) mp[lista[i][0]]++;
  for(int i = 0; i < n; i++){
    cout << (n-1) + mp[lista[i][1]] << ' ' << (n-1) - mp[lista[i][1]] << endl;
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

  solve();
}