#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n;
  cin >> n;
  int sum1 = 0, sum2 = 0, zero=0;
  int temp;
  for(int i = 0; i < n; i++){
    cin >> temp;
    if(temp == 0) zero++;
    if(temp > 0) sum1++;
    if(temp < 0) sum2++;
  }
  if(sum1 == 0 || sum2 == 0){
    cout << max(sum1+zero, sum2+zero) << " " << max(sum1+zero, sum2+zero) << endl;
  }
  else{
    cout << max(sum1+zero, sum2+zero) << " " << min(sum1, sum2) << endl;
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