#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	scanf("%d", &n);
	if (n < 3)
	{
		printf("LIGHT\n");
	}
	else if (n < 7)
	{
		printf("MODERATE\n");
	}
	else
	{
		printf("HEAVY\n");
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		solve();
	}
}