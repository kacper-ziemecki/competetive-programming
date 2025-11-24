#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll  long long unsigned int

int calculate(vector<vector<ll>> &list, int i, int j){
	return list[i] + calculate(list, i-1,j-1) 
}

void solve(vector<vector<ll>> &list){
	int n;
	cin >> n;
	n--;
	int i = 1, j = 1;
	while(n){
		n--;
		if(j == i){
			i++;
			j = 1;
		}
		else{
			j++;
		}
	}
	// cout << i << " " << j << endl;
	cout << list[i][j] << endl;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("input.txt", "r", stdin);
	vector<vector<ll>> list(101, vector<ll>(101, 0)), calc(101, vector<ll>(101, 0));
	list[1][1] = 1;
	int x = 1;
	for(int i = 2; i < 101; i++){
		for(int j = 1; j <= i; j++){
			x++;
			list[i][j] = (x * x);
			cout << list[i][j] << " ";
			calc[i][j] = calculate(list, i, j);
		}
		cout << endl;
	}
	int t;
	cin >> t;
	while(t--) solve(list);	
} 