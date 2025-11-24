#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n;
  cin >> n;
  vector<int> list(n, 0);
  for(auto &el : list) cin >> el;
  while(list.size() > 2){
    if(list[0] <= list[1] && list[0] >= list[2]){
      list.erase(list.begin(), list.begin() + 1);
    }
    else if(list[1] <= list[0] && list[1] >= list[2]){
      list.erase(list.begin() + 1, list.begin() + 2);
    }
    else if(list[0] >= list[1] && list[0] <= list[2]){
      list.erase(list.begin() , list.begin() + 1);
    }
    else if(list[1] >= list[0] && list[1] <= list[2]){
      list.erase(list.begin() + 1, list.begin() + 2);
    }
    else if(list[2] <= list[1] && list[2] >= list[0]){
      list.erase(list.begin() + 2, list.begin() + 3);
    }
    else if(list[2] <= list[0] && list[2] >= list[1]){
      list.erase(list.begin() + 2, list.begin() + 3);
    }
  }
  cout << list[0] << " " << list[1] << endl;
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