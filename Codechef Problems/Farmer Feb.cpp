#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int a,b;
  cin >> a >> b;
  int sum = a+b;
  for(int i = sum+1;;i++){
    bool prime = true;
    for(int j = 2; j*j <= i; j++){
      if(i%j == 0){
        prime = false;
        break;
      }
    }
    if(prime){
        cout << i - sum << endl;
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