#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n;
	cin >> n;
	vector<int> list(n, 0);
	for(auto &el : list) cin >> el;
	int one = 0, two = 0;
	int begin = 0, end = n-1;
	for(int i = 0; i < n; i++){
		if(i&1){
			if(list[begin] >= list[end]){
				two += list[begin];
				begin++;
			}
			else{
				two += list[end];
				end--;
			}
		}
		else{
			if(list[begin] >= list[end]){
				one += list[begin];
				begin++;
			}
			else{
				one += list[end];
				end--;
			}
		}
	}
	cout << one << " " << two << endl;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 