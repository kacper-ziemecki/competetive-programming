#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve()
{
  string number;
  ll n,res=0, index=0;
  cin >> number >> n;
  ll suma=0;
  for(auto &el : number) suma += el-'0';
  if(suma <= n){ cout << 0 << endl; return; }
  suma = 0;
  for(ll i = 0; i < n; i++){
    suma += number[i]-'0';
    if(suma >= n){
      index = i;
      break;
    }
  }
  string newNumber = number.substr(index, number.size()-index);
  // dbg(pow(10, newNumber.size()), stoll(newNumber));
  cout << fixed  << setprecision(0) << ((ull)pow((ull)10, newNumber.size())-stoull(newNumber)) << endl;
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
  while(t--) solve();
}