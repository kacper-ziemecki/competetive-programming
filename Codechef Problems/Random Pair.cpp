#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n;
  cin >> n;
  unordered_map<int, int> list;
  int temp;
  int maks = 0;
  for(int i = 0; i < n; i++){
    cin >> temp;
    list[temp]++;
    maks = max(maks, temp);
  }
  if(list[maks] > 1){
    
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