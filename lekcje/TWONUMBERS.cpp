#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define pb push_back
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll lcm(ll a, ll b){
  return (a*b)/__gcd(a,b);
}

void solve(){
  ll n;
  cin >> n;
  if(n == 2){ cout << 0 << endl; return;}

  if(n&1){ cout << (n/2)*((n+1)/2)-1 << endl; }
  else{
    // dbg(lcm(((n/2)-1), ((n/2)+1))-__gcd(((n/2)-1), ((n/2)+1)), lcm(((n/2)-2), ((n/2)+2))-__gcd(((n/2)-2), ((n/2)+2)));
    cout << max(lcm(((n/2)-1), ((n/2)+1))-__gcd(((n/2)-1), ((n/2)+1)), lcm(((n/2)-2), ((n/2)+2))-__gcd(((n/2)-2), ((n/2)+2))) << endl;
  }
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  ll t;
  cin >> t;
  while(t--)
  solve();
}