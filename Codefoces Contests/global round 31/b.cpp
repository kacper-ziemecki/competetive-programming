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

bool ending(string &s, string &t){
  for(int i = 0; i < s.size(); i++){
    if(s[i] < t[i]) return true;
    else if(s[i] > t[i]) return false;
  }
  return true;
}

void solve(){
  string s;
  string jeden,dwa;
  int n;
  cin >> n;
  vector<string> lista(n);
  for(auto &el : lista) cin >> el;
  for(auto &el : lista){
    jeden = s+el;
    dwa = el+s;
    if(ending(jeden,dwa)){
      s += el;
    } else{
      s = el + s;
    }
  }
  cout << s << endl;
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