#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n,a;
  cin >> n;
  vector<int> list(n, 0), temp(n, 0);
  for(int i = 0; i < n; i++){
    cin >> a;
    list[i] = a;
    temp[i] = a;
  }
  for(int i = 0; i < n-1; i++){
    if(list[i] > list[i+1]){
      int t = list[i+1];
      list[i+1] = list[i];
      list[i] = t;
      break;
    }
  }
  sort(temp.begin(), temp.end());
  for(int i = 0; i < n; i++){
    if(list[i] != temp[i]){
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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