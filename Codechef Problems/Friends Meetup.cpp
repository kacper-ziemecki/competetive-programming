#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  ll a,b;
  cin >> a >> b;
  ll i=0,j=0;
  
  while(true){
    if(a == b){
      cout << "YES\n";
      return;
    }
    if(a < b){
      cout << "NO\n";
      return;
    }
    i++;
    j+=2;
    a += i;
    b += j;
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("input.txt", "r", stdin);
  ll t;
  cin >> t;
  while(t--) solve();
}