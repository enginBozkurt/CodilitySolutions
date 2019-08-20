// Sort by the end points. (in the problem end points are sorted)  
  
//Iterate through the segments, picking whichever segments doesn't cause overlap with the previous segments   
//(this can be checked by simply keeping track of the last end point and checking that the starting point // is after that point).  
// This will always give the optimal solution.  
  
int solution(vector<int> &A, vector<int> &B) {  
	  
	int N = A.size();  
	   
	 if (N <= 1) {  
			return N;  
		}  
	  
	int cnt = 1;  
	int prev_end = B[0];  
	  
	for(int curr=1; curr < N; curr++){  
		if (A[curr] > prev_end) {  
			cnt++;  
			prev_end = B[curr];  
		}  
	}  
	  
	return cnt;  
}  
