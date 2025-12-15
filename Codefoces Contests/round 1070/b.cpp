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


void solve(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int lewo=0,prawo=0;
  for(int i = 0; i < n; i++){
    if(s[i] == '1') break;
    lewo++;
  }
  for(int i = n-1; i >= 0; i--){
    if(s[i] == '1') break;
    prawo++;
  }
  int cur=0,maks=0;
  for(int i = 0; i < n; i++){
    if(s[i] == '1'){
      cur = 0;
    } else{
      cur++;
    }
    maks = max(maks,cur);
  }
  
  cout << max(maks, lewo+prawo) << endl;
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

  int t;
  cin >> t;
  while(t--)
  solve();
}