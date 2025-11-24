#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n,temp1,temp2;
  cin >> n;
  vector<int> list(n, 0);
  for(auto &el : list) cin >> el;
  int res = 0;
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
        temp1 = list[i] * list[j];
        temp2 = 0;
        while(temp1){
          temp2 += temp1 % 10;
          temp1 /= 10;
        }
        res = max(res, temp2);
    }
  }
  cout << res << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while(t--) solve();
}