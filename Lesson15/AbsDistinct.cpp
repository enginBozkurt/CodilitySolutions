
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int>& A) {
	// write your code in C++14 (g++ 6.2.0)  

	int L{ 0 }, R{ (int)A.size() - 1 }, count{ 0 };

	while (L <= R) {

		long abs_L = abs((long)A[L]);
		long abs_R = abs((long)A[R]);

		//skip if the same abs value is found in the new position.  
		if (abs_L >= abs_R) {
			while (L < (int)A.size() && abs_L == abs(A[L]))
				L++;
		}
		//skip if the same abs value is found in the new position.  
		if (abs_R >= abs_L) {
			while (R > 0 && abs_R == abs(A[R]))
				R--;
		}
		count++;
	}

	return count;
}

int main()

{
	vector<int> array;

	array.push_back(-5);
	array.push_back(-3);
	array.push_back(-1);
	array.push_back(0);
	array.push_back(3);
	array.push_back(6);



    std::cout << solution(array) <<endl;

	return 0;
}
