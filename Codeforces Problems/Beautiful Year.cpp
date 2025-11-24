#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n;
	cin >> n;
	for(int i = n+1;;i++){
		vector<int> list;
		int temp = i;
		bool flag = true;
		while(temp){
			list.push_back(temp%10);
			temp /= 10;
		}
		sort(list.begin(), list.end());
		for(int j = 1; j < list.size(); j++){
			if(list[j] == list[j-1]){
				flag = false;
				break;
			}
		}
		if(flag){
			cout << i << endl;
			return;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 