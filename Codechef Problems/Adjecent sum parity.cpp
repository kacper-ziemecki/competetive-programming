#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n,a;
  cin >> n;
  vector<bool> list(n, false);
  for(int i = 0; i < n; i++){
    cin >> a;
    if(i == n-1){
      if(list[i] ^ list[0] != a){
        cout << "NO" << endl;
      }
      else{
        cout << "YES" << endl;
      }
    }
    if(i == 0){
      if(a == 1){
        list[0] = true;
      }
    }
    else{
      if(a == 1){
        if(list[i] == false){
          list[i+1] = true;
        }
      }
      if(a == 0){
        if(list[i] == true){
          list[i+1] = true;
        }
      }
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