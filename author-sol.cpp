#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		char a[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}
		/*
			 view the image in this repository for better understanding
			 create two possible grids with alternating asterisks (this would produce many islands)
			 
			 grid 1 = asterisk will be placed in the starting cell (cells will be placed in odd positions)
			 grid 2 = asterisk will be placed in the second cell (cells will be placed in even positions)
			 
			 the answer would depend on the size of the grid:
			 
			 if n x m is even:
			 the answer will be the same since it contains equal even and odd numbered cells
			 but we need to choose the smallest number of operations in this case
			 
			 if n x m is odd:
			 the answer will always be grid 1 since the asterisks will be placed in the 
			 odd-numbered cells (in a grid with a total of odd-numbered cells, the cells which
			 are in the odd positions are larger by 1 than the cells in even positions) 
		*/
		int cnt1 = 0;
		int cnt2 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cnt1 += (a[i][j] != ((i + j) % 2 == 0 ? '*' : '.'));
				cnt2 += (a[i][j] != ((i + j) % 2 == 0 ? '.' : '*'));
			}
		}
		int ans = cnt1;
		if ((n * m) % 2 == 0) {
			ans = min(cnt1, cnt2);
		}
		cout << ans << '\n';
	}
	return 0;
}
