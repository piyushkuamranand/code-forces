#include <bits/stdc++.h>
 
constexpr int MAX = 5e5;
int dp[MAX + 1];
 
int main() {
	int n, c;
	std::cin >> n >> c;
 
	int num_c = 0;
	int best_sub = 0;
	for (int i = 0; i < n; i++) {
		int a;
		std::cin >> a;
 
		if (a == c) {
			// we have one more total c element
			// note that we don't care about dp[c]
			num_c++;
		} else {
			// here, we care about dp[a]
			// like Kadane's, we 'reset' here or we add on
			dp[a] = std::max(num_c, dp[a]) + 1;
		}
 
		// the contribution a subarray operation adds is the max # of
		// elements with the same value, minus the number of c values
		best_sub = std::max(best_sub, dp[a] - num_c);
	}
 
	std::cout << num_c + best_sub << '
';
}