#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int a,b;
  cin >> a >> b;
  for(int i = 1;;i++){
    if(i&1){
      a-=i;
    }
    else{
      b-=i;
    }
    if(a < 0){
      cout << "Bob\n";
      return;
    }
    if(b < 0){
      cout << "Limak\n";
      return;
    }
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