#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  long double a,b,c,d;
  cin >> a >> b >> c >> d;
  if(a/b == c/d || a/c == b/d || a/d == b/c || a/b == d/c || a/c == d/b || a/d == c/b){
    cout << "Possible\n";
  }
  else{
    cout << "Impossible\n";
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