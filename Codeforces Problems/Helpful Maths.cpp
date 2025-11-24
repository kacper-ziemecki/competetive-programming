#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	string text;
	cin >> text;
	vector<int> list;
	for(int i = 0; i < text.size(); i+= 2){
		list.push_back(text[i] - '0');
	}
	sort(list.begin(), list.end());
	for(int i = 0; i < list.size(); i++){
		if(i == list.size() - 1){
			cout << list[i];
		}
		else{
			cout << list[i] << "+";
		}
	}
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 