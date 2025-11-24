#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

bool test(string s){
  for(ll i = 0; i < s.size()/2; i++){
    if(s[i] != s[s.size()-i-1]) return true;
  }
  return false;
}

void solve()
{
  string s;
  cin >> s;
  if(test(s+'a')){
    cout << "YES\n";
    cout << s+'a' << endl;
  } else if(test('a'+s)){
    cout << "YES\n";
    cout << 'a'+s << endl;
  } else{
    cout << "NO\n";
  }
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

  ll t;
  cin >> t;
  while(t--)
  solve();  
  
} 