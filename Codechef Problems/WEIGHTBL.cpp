#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve(){
  int w1,w2,x1,x2,m;
  cin >> w1 >> w2 >> x1 >> x2 >> m;
  int minimum = w1 + x1 * m;
  int maksimum = w1 + x2 * m;
  if(w2 >= minimum && w2 <= maksimum){
    cout << 1 << endl;
  }
  else{
    cout << 0 << endl;
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