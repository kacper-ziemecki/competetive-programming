#include <bits/stdc++.h>
using namespace std;


void solve()
{
	int n,a;
	string b;
	cin >> n;
	vector<int> lista(n, 0);
	for(auto &el : lista) cin >> el;
	vector<string> napisy(n, "");
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		napisy[i] = b;
	}
	int temp;
	for(int i = 0; i < n; i++){
		temp = 0;
		for(auto el : napisy[i]){
			if(el == 'U'){
				temp--;
			}
			else temp++;
		}
		lista[i] = ((lista[i] + temp) % 10) < 0 ? ((lista[i] + temp) % 10) + 10 : (lista[i] + temp) % 10;
	}
	for(auto el : lista){
		cout << el << " ";
	}
	cout << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while(t--) solve();
}
