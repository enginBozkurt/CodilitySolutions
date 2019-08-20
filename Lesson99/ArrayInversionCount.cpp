/* The counting is done during the merge procedure of merge sort using the trick: 
* for two sorted sub sequence split from A[low, high]: [low, mid] and [mid + 1, high], at each merge    
*  step, the relative order in the original array is reserved between 
* any element with index i in [low, mid] and j in [mid + 1, high]. Therefore, if A[i] > A[j], then we     
* could say that all elements in the first half from i to mid have the inverse order with A[j],  
* there are mid - i + 1 of them 
*/  
  
/* This funt merges two sorted arrays   
and returns inversion count in the arrays.*/  
  
/* i is index for left subarray 
* j is index for right subarray 
* k is index for resultant merged subarray 
*/  
  
static int merge(vector<int> &A, vector<int> &B, int left, int mid, int right)  
{  
	int count = 0;  
	int i = left, j = mid+1, k = left;  
	  
	while (i <= mid && j <= right)  
	{  
		if (A[i] <= A[j])  
			B[k++] = A[i++];  
		else  
		{  
			B[k++] = A[j++];  
			count += mid - i +1;  
		}  
	}  
	  
	/* Copy the remaining elements of left subarray   
	 (if there are any) to B */  
	while (i <= mid)  
		B[k++] = A[i++];  
		  
		  
	/* Copy the remaining elements of right subarray   
	(if there are any) to B */  
	while (j <= right)  
		B[k++] = A[j++];  
		  
	return count;  
}  
  
/* An auxiliary recursive function that sorts the input array and returns the number of inversions in the array. */  
static int mergeSort(vector<int> &A, vector<int> &B, int start, int end)    
{    
	int cnt = 0, tmp = 0;    
	int mid;    
	if (start < end)    
	{    
		  
		 /* Divide the array into two parts and   
		call mergeSort   
		for each of the parts */  
		mid = start + (end - start) / 2;   
		  
		  
		/* Inversion count will be sum of   
		inversions in left-part, right-part   
		and number of inversions in merging */  
		  
		cnt = mergeSort(A, B, start, mid);    
		if (cnt == -1) return -1;    
		  
		tmp = mergeSort(A, B, mid + 1, end);    
		if (tmp == -1) return -1;   
	  
		cnt += tmp;    
		  
		/*Merge the two parts*/  
		tmp = merge(A, B, start, mid, end);    
		  
		if (tmp == -1) return -1;    
		cnt += tmp;    
		  
		if (cnt > 1e9) return -1;  
		  
		/*Copy back the merged elements to original array*/  
		std::copy(B.begin() + start, B.begin() + end + 1, A.begin() + start);    
	}    
	return cnt;    
}   
  
  
/* This function sorts the input array and returns the   
number of inversions in the array */  
  
  
int solutionArrayInversionCount(vector<int> &A)    
{    
	vector<int> B(A.size(), 0);    
	return mergeSort(A, B, 0, A.size() - 1);    
}    
  
  
int solution(vector<int> &A) {	
   solutionArrayInversionCount(A);    
}    
