#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> kamyki;
int skok(int kam){
  if(kam == n-1) return 0;
  return min(abs(kamyki[kam+1]-kamyki[kam])+skok(kam+1), (kam+2 < n ? abs(kamyki[kam+2]-kamyki[kam])+skok(kam+2) : INT_MAX));
}

int main()
{

  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);

  cin >> n;
  kamyki.resize(n);
  for(int i = 0; i < n; i++) cin >> kamyki[i];

  cout << skok(0) << endl;

} 