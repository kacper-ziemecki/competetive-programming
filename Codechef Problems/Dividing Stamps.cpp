#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  ll n,a,res=0;
  cin >> n;
  for(ll i = 0; i < n; i++){
    cin >> a;
    res+=a;
  }
  if(res == (n * (n+1))/2){
    cout << "YES\n";
  }
  else{
    cout << "NO\n";
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // freopen("input.txt", "r", stdin);
  solve();
}