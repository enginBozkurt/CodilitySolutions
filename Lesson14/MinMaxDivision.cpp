// MinMaxDivision.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <climits>

using namespace std;


bool valid_block_sum(const vector<int>& A, int max_block_cnt, int max_block_size) {

	int block_sum = 0;
	int block_cnt = 0;

	for (size_t i = 0; i < A.size(); i++) {
		if ((block_sum + A[i]) > max_block_size) {
			block_sum = A[i];
			block_cnt++;
		}
		else
			block_sum += A[i];

		if (block_cnt >= max_block_cnt)
			return false;
	}
	return true;
}


int solution(int K, int M, vector<int> &A) {

	int max_item = INT_MIN; 
	// Max item of the array
	for (size_t i = 0; i < A.size(); i++)
		if (A[i] > max_item)
			max_item = A[i];

	int item_sum = 0; 
	// Sum of all array items
	for (size_t i = 0; i < A.size(); i++)
		item_sum += A[i];

	int lower_bound = max_item;
	int upper_bound = item_sum;

	const int max_block_cnt = K;

	// Checking border conditions
	if (max_block_cnt == 1)
		return upper_bound;
	if (max_block_cnt >= int(A.size()))
		return lower_bound;


	// Binary searching for the minimal block sum
	while (lower_bound <= upper_bound) {

		int candidate_mid = (lower_bound + upper_bound) / 2;
		if (valid_block_sum(A, max_block_cnt, candidate_mid))
			upper_bound = candidate_mid - 1;
		else
			lower_bound = candidate_mid + 1;
	}

	return lower_bound;

}




int main()
{
	vector<int> array;

	array.push_back(2);
	array.push_back(1);
	array.push_back(5);
	array.push_back(1);
	array.push_back(2);
	array.push_back(2);
	array.push_back(2);

	
	cout << solution(3, 5, array) << endl;
  
}
