#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n;
  cin >> n;
  vector<vector<int>> lista(n, vector<int> (n, 1));
  for(int i = 1; i < n; i++){
  	int x = 1, y = i;
  	while(x < n && y > 0){
  		lista[y][x] = lista[y-1][x] + lista[y][x-1];
  		x++;
  		y--;
	  }
  }
  for(int i = 2; i < n; i++){
  	int x = i, y = n-1;
  	while(x < n){
  		lista[y][x] = lista[y-1][x] + lista[y][x-1];
  		x++;
  		y--;
	  }
  }
  for(auto sublist : lista){
  	for(auto el : sublist){
  		cout << el << " ";
	  }
	  cout << endl;
  }
  cout << lista[n-1][n-1] << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
