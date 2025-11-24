#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve(){
  double a,b,c,d;
  cin >> a >> b >> c >> d;
  if(d != 0){
    a += a * (d/100);
  }
  if(a >= b && a <= c){
    cout << "Yes\n";
  }
  else {
    cout << "No\n";
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  //freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) solve();
}