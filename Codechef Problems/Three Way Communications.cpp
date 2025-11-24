#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  double r;
  cin >> r;
  double a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;
  double one = sqrt(abs(a-c)*abs(a-c)+abs(b-d)*abs(b-d));
  double two = sqrt(abs(a-e)*abs(a-e)+abs(b-f)*abs(b-f));
  double three = sqrt(abs(c-e)*abs(c-e)+abs(d-f)*abs(d-f));
  if(one <= r && two <= r){
    cout << "yes\n";
  }
  else if(one <= r && three <= r){
    cout << "yes\n";
  }
  else if(two <= r && three <= r){
    cout << "yes\n";
  }
  else{
    cout << "no\n";
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) solve();
}