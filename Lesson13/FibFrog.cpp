// FibFrog.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// calculate fibonacci numbers
vector<int> dynamicFibs(int n)
{
	vector<int> fibs;

	fibs.push_back(0);
	fibs.push_back(1);

	for (int i = 2; i <= n + 2; i++)
	{
		int tmp = fibs[i - 1] + fibs[i - 2];

		if (tmp > n + 2)
		{
			break;
		}

		fibs.push_back(tmp);
	}

	return fibs;
}


// struct to store the status of position and the number of steps
struct State
{
	int pos;
	int step;
};


int solution(vector<int>& A)
{
	if (A.size() == 0)
		return 1;

	// boolean visted array for BFS 
	// Were we in this position before?
	bool* visited = new bool[A.size()];

	// all elements of the boolean array are assigned to false value
	fill(visited, visited + A.size(), false);

	//Fibonacci numbers
	vector<int> fibs = dynamicFibs(A.size());

	//n max moves
	int maxAction = fibs.size();

	// Initially we are at position -1 with 0 move
	State start = { -1, 0 }; 

	// our queue with state struct type elements
	queue<State> q;

	// add source vertex (initial pos and number of steps) to the queue
	q.push(start);

	while (!q.empty()) {

		// add source vertex to the queue
		State s = q.front();

		// remove the  least recently added (oldest) element to the queue
		q.pop();

		for (int i = maxAction - 1; i >= 1; i--) {

			//  Obtain the next attemp's status
			int nextPos = s.pos + fibs[i];


			if (nextPos == A.size())
			{
				//We are at the goal position!
				return s.step + 1;
			}


			//  Three conditions are moving too far, no leaf available for moving, 
			// and being here before respectively.
			if (nextPos > A.size() || A[nextPos] == 0 || visited[nextPos] == true)
			{
				continue;
			}


			//  Enqueue for later attemp.
			State next;

			next.pos = nextPos;

			next.step = s.step + 1;

			// add unvisited neighbors
			q.push(next);
			// and mark them as visited
			visited[nextPos] = true;

		}
	}

	// There is no unprocessed attemp. And we did not
	// find any path yet. So no path exists.
	return -1;


}
