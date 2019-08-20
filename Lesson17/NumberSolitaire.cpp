

#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int solutionNumberSolitaire(const vector<int>& A) {

	int len = A.size();
	vector<long> memo(len, numeric_limits<long>::min());

	memo[0] = A[0];

	for (int i = 1; i < len; ++i)
	{
		for (int j = 1; j < 7; ++j)
		{
			if (i - j >= 0)
				memo[i] = std::max(memo[i], A[i] + memo[i - j]);  // keep the biggest one 
		}
	}
	return memo[len - 1];
}
