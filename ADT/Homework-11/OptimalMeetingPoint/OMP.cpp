#include <iostream>
#include "Node.h"

using namespace std;

int find_meetup_city(int **adj_matrix, int your_city, int friend_city, int n);
// The main function

int main(int argc, char const *argv[])
{
	int **adj_matrix;
	int yourCity, friendCity, num;

	//Asking the user for the input of the cities
	cout << "Welcome to Optimal Meeting Point Program \n " << endl;
	cout << "Enter the number of Cities : ";
	cin >> num;

	adj_matrix = (int **)malloc(sizeof(int *) * num);
	if (!adj_matrix)
	{
		// Check if the matrix is created properly
		exit(1);
	}

	for (int i = 0; i < num; ++i)
	{
		adj_matrix[i] = (int *)malloc(sizeof(int) * num);
		if (!adj_matrix[i])
			// Check if the matrix is created properly
			exit(1);
	}

	for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j < num; ++j)
		{
			adj_matrix[i][j] = 0;
		}
	}
	//Asking the user for the values
	for (int i = 0; i < num; ++i)
	{
		for (int j = i + 1; j < num; ++j)
		{
			printf("Enter the distance between city %d, and %d: ", (i + 1), (j + 1));
			cin >> adj_matrix[i][j];
			adj_matrix[j][i] = adj_matrix[i][j];
		}
	}

	cout << endl
		 << "Enter your city: ";
	cin >> yourCity;

	cout << endl
		 << "Enter Friend city: ";
	cin >> friendCity;

	// Printing the Optimal meeting point
	cout << "The index for the optimal place to meet is : " << find_meetup_city(adj_matrix, yourCity - 1, friendCity - 1, num) << endl;

	//Freeing the allocated memory
	for (int i = 0; i < num; ++i)
	{
		free(adj_matrix[i]);
	}
	free(adj_matrix);

	return 0;
}

// The find_meetup_city function
int find_meetup_city(int **adj_matrix, int your_city, int friend_city, int n)
{
	//Creating a priority queue to keep track of the Nodes
	priority_queue<Node> pQueue;
	Node mainVector[n];

	for (int i = 0; i < n; ++i)
		mainVector[i].idxSet(i);

	mainVector[your_city].set(0);
	pQueue.push(mainVector[your_city]);
	Node curNode;

	//Here we use the dijkstra’s algorithm to find the min distance between the cities in distance_a
	while (!pQueue.empty())
	{
		curNode = pQueue.top();
		pQueue.pop();
		for (int i = 0; i < n; ++i)
		{
			if ((i != curNode.idx) && (adj_matrix[curNode.idx][i]))
			{
				int newdistance = curNode.distance_a + adj_matrix[curNode.idx][i];
				if (newdistance < mainVector[i].distance_a)
				{
					mainVector[i].set(newdistance);
					pQueue.push(mainVector[i]);
				}
			}
		}
	}

	// Change the status of the Nodes after they are visited
	for (int i = 0; i < n; ++i)
		mainVector[i].changeSet();

	mainVector[friend_city].set(0);
	pQueue.push(mainVector[friend_city]);

	//Here we use the dijkstra’s algorithm to find the min distance between the cities in distance_b
	while (!pQueue.empty())
	{
		curNode = pQueue.top();
		pQueue.pop();
		for (int i = 0; i < n; ++i)
		{
			if ((i != curNode.idx) && (adj_matrix[curNode.idx][i]))
			{
				int newdistance = curNode.distance_b + adj_matrix[curNode.idx][i];
				if (newdistance < mainVector[i].distance_b)
				{
					mainVector[i].set(newdistance);
					pQueue.push(mainVector[i]);
				}
			}
		}
	}

	// Check for the min value of the distance_c between all the Nodes
	int idx = friend_city;
	double sample = mainVector[idx].distance_c;
	for (int i = 0; i < n; ++i)
	{
		if (mainVector[i].distance_c < sample)
		{
			sample = mainVector[i].distance_c;
			idx = i;
		}
	}
	return (idx + 1);
}