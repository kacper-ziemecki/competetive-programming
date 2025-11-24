#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n;
	cin >> n;
	int one = INT_MAX, zero = INT_MAX, two = INT_MAX;
	bool jeden = false, dwa = false, trzy = false;
	int temp;
	string temp1;
	for(int i = 0; i < n; i++){
		cin >> temp >> temp1;
		if(temp1[0] == '1' && temp1[1] == '1'){
			two = min(two, temp);
			jeden = true;
		}
		else if(temp1[0] == '1'){
			zero = min(zero, temp);
			dwa = true;
		}
		else if(temp1[1] == '1'){
			one = min(one, temp);
			trzy = true;
		}
	}
	if((dwa&&trzy) && jeden){
		cout << min(one+zero, two) << endl;
	}
	else if(jeden){
		cout << two << endl;
	}
	else if((dwa&&trzy)){
		cout << one+zero << endl;
	}
	else{
		cout << -1 << endl;
	}
	
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--) solve();	
} 