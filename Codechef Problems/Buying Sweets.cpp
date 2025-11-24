#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int a,b;
  cin >> a >> b;
  int sum = 0, minimum = INT_MAX,temp;
  for(int i = 0; i < a; i++){
    cin >> temp;
    sum += temp;
    minimum = min(minimum, temp);
  }
  cout << (sum - (sum/b * b) >= minimum ? -1 : sum/b) << endl;
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