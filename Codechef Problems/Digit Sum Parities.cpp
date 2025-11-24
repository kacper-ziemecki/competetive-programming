#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int 

void solve()
{
  int n,temp;
  cin >> n;
  int sum = 0;
  temp = n;
  while(temp){
    sum += temp % 10;
    temp /= 10;
  }
  int i = n;
  while(true){
    i++;
    int sum2 = 0;
    int temp2 = i;
    while(temp2){
      sum2 += temp2 % 10;
      temp2 /= 10;
    }
    if(sum2 % 2 != sum % 2){
      cout << i << endl;
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