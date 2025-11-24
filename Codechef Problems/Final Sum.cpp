#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int a,b;
  cin >> a >> b;
  int sum = 0;
  int temp;
  for(int i = 0; i < a; i++){
    cin >> temp;
    sum += temp;
  }
  int temp2;
  for(int i = 0; i < b; i++){
    cin >> temp >> temp2;
    if(!((temp2-temp)&1)){
      sum++;
    }
  }
  cout << sum << endl;
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