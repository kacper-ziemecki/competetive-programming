#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void solve()
{
  string text;
  cin >> text;
  if(text == "()"){
    cout << "NO\n";
    return;
  }
  else{
    cout << "YES\n";
  }
  ll n = text.size();
  string one, two;
  for(ll i = 0; i < n*2; i++){
    if(i&1){
      one+=')';
    }
    else{
      one+='(';
    }

    if(i < n){
      two+='(';
    }
    else{
      two+=')';
    }
  }
  for(ll i = 0; i < n;i++){
    if(one.substr(i, n) == text ){
      cout << two << endl;
      return;
    }
    if(two.substr(i, n) == text){
      cout << one << endl;
      return;
    }
  }
  cout << one << endl;
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