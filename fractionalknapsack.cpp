/*

Given weights and values of n items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.

In the 0-1 Knapsack problem, we are not allowed to break items. We either take the whole item or don’t take it.

nput:
Items as (value, weight) pairs
arr[] = {{60, 10}, {100, 20}, {120, 30}}
Knapsack Capacity, W = 50;
Output:
Maximum possible value = 240
by taking items of weight 10 and 20 kg and 2/3 fraction
of 30 kg. Hence total price will be 60+100+(2/3)(120) = 240

*/

#include <bits/stdc++.h> 

using namespace std; 

struct Item 
{ 
	int value, weight; 

	Item(int value, int weight) : value(value), weight(weight) 
	{} 
}; 


// sorting according to ratio
bool cmp(struct Item a, struct Item b) 
{ 
	double r1 = (double)a.value / a.weight; 
	double r2 = (double)b.value / b.weight; 
	return r1 > r2; 
} 

double fractionalKnapsack(int W, struct Item arr[], int n) 
{ 
	sort(arr, arr + n, cmp); 

	int curWeight = 0;
	double finalvalue = 0.0;

	for (int i = 0; i < n; i++) 
	{ 
		if (curWeight + arr[i].weight <= W) 
		{ 
			curWeight += arr[i].weight; 
			finalvalue += arr[i].value; 
		} 

		else
		{ 
			int remain = W - curWeight; 
			finalvalue += arr[i].value * ((double) remain / arr[i].weight); 
			break; 
		} 
	} 

	return finalvalue; 
} 

int main() 
{ 
	int W = 50; // Weight of knapsack 
	Item arr[] = {{60, 10}, {100, 20}, {120, 30}}; 

	int n = sizeof(arr) / sizeof(arr[0]); 

	cout << "Maximum value we can obtain = "
		<< fractionalKnapsack(W, arr, n); 
	return 0; 
} 
