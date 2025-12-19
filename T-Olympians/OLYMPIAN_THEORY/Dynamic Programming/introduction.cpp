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

int a,b;

int helper(int a, int b){ // minimalna ilosc podzielen aby otrzymac same kwadraty z a i b
  int jeden = helper(a-1,b);// minimalna ilosc podzielen aby otrzymac same kwadraty z a-1 i b
  int dwa = helper(1,b); // minimalna ilosc podzielen aby otrzymac same kwadraty z 1 i b
  int wynik = jeden+dwa+1;
  dp[a][b]  = wynik;
  return wynik;
}

void solve(){
  cin >> a >> b; 
  cout << helper(a,b) << endl;
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