#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>
#include <queue>
#include <unordered_set>
#include "ListNode.h"
#include "TreeNode.h"
#include "Node.h"
#include <set>


using namespace std;

class Solution204CountPrimes
{
public:
	int countPrimes1(int n) {
		vector<int> primes;
		vector<bool> isPrimes(n, 1);
		for (int i = 2; i < n; i++)
		{
			if (isPrimes[i]) {
				primes.push_back(i);
			}
			int primesSize = primes.size();
			for (int j = 0; j < primesSize && i * primes[j] < n; j++)
			{
				isPrimes[i * primes[j]] = 0;
				if (i % primes[j] == 0) {
					break;
				}
			}
		}

		return primes.size();
	}

	typedef long long ll;
	ll prime_pi(const ll N) {
		if (N <= 1) return 0;
		if (N == 2) return 1;
		const int v = sqrtl(N);
		int s = (v + 1) / 2;
		vector<int> smalls(s);
		for (int i = 1; i < s; ++i) {
			smalls[i] = i;
		}
		vector<int> roughs(s); 
		for (int i = 0; i < s; ++i)
		{
			roughs[i] = 2 * i + 1;
		}
		vector<ll> larges(s); 
		for (int i = 0; i < s; ++i) {
			larges[i] = (N / (2 * i + 1) - 1) / 2;
		}
		vector<bool> skip(v + 1);
		const auto divide = [](ll n, ll d) -> int { return double(n) / d; };
		const auto half = [](int n) -> int { return (n - 1) >> 1; };
		int pc = 0;
		for (int p = 3; p <= v; p += 2) if (!skip[p]) {
			int q = p * p;
			if (ll(q) * q > N) break;
			skip[p] = true;
			for (int i = q; i <= v; i += 2 * p) skip[i] = true;
			int ns = 0;
			for (int k = 0; k < s; ++k) {
				int i = roughs[k];
				if (skip[i]) continue;
				ll d = ll(i) * p;
				larges[ns] = larges[k] - (d <= v ? larges[smalls[d >> 1] - pc] : smalls[half(divide(N, d))]) + pc;
				roughs[ns++] = i;
			}
			s = ns;
			for (int i = half(v), j = ((v / p) - 1) | 1; j >= p; j -= 2) {
				int c = smalls[j >> 1] - pc;
				for (int e = (j * p) >> 1; i >= e; --i) smalls[i] -= c;
			}
			++pc;
		}
		larges[0] += ll(s + 2 * (pc - 1)) * (s - 1) / 2;
		for (int k = 1; k < s; ++k) larges[0] -= larges[k];
		for (int l = 1; l < s; ++l) {
			int q = roughs[l];
			ll M = N / q;
			int e = smalls[half(M / q)] - pc;
			if (e < l + 1) break;
			ll t = 0;
			for (int k = l + 1; k <= e; ++k) t += smalls[half(divide(M, roughs[k]))];
			larges[0] += t - ll(e - l) * (pc + l - 1);
		}
		return larges[0] + 1;
	}

	int countPrimes2(int n) {
		return prime_pi(n - 1);
	}


	int countPrimes(int n) {
		if (n <= 2) {
			return 0;
		}

		vector<bool> primes(n, 1);
		int result = 1;

		int maxMultiple = (n - 1) / 2;
		for (int i = 2; i <= maxMultiple; i++)
		{
			primes[2 * i] = false;
		}

		for (int i = 3; i < n; i++)
		{
			if (primes[i]) {
				result++;
				if ((long long)i * i < n) {
					int multiple = 2 * i;
					for (int j = i * i; j < n; j += multiple) {
						primes[j] = false;
					}
				}
			}
		}

		return result;
	}
};

//int main() {
//	Solution204CountPrimes solution;
//	cout << solution.countPrimes1(17) << endl;
//	cout << solution.countPrimes1(2) << endl;
//	cout << solution.countPrimes1(1) << endl;
//	cout << solution.countPrimes1(0) << endl;
//	cout << solution.countPrimes1(1500000) << endl;
//	cout << solution.countPrimes(10000) << endl;
//}