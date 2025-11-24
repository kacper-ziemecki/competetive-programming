#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve(){
  int a,b;
  cin >> a >> b;
  if(b == 0){
    cout << a << endl;
    return;
  }
  int temp = a/b;
  a -= temp *b;
  cout << a << endl;
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