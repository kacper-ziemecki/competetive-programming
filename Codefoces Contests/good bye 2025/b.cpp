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
  string s;
  cin >> s;
  int a=0,b=0;
  for(auto el : s){
    if(el == 's') a++;
    else b++;
  }
  if(b == 0){
    cout << 0 << endl;
    return;
  }
  int res = 0;
  bool flag = true;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == 'u'){
      if(i == s.size()-1){
        res++;
        break;
      }
      if(flag){
        res++;
        flag = false;
      } else{
        flag = true;
      }
    } else{
      flag = false;
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

  int t;
  cin >> t;
  while(t--)
  solve();
}