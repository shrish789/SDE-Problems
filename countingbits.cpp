/*

Count number of set bits from 1 to n.

*/


// Log n approach
#include <bits/stdc++.h> 

// A O(Logn) complexity program to count 
// set bits in all numbers from 1 to n 
using namespace std; 

/* Returns position of leftmost set bit. 
The rightmost position is considered 
as 0 */
unsigned int getLeftmostBit(int n) 
{ 
	int m = 0; 
	while (n > 1) 
	{ 
		n = n >> 1; 
		m++; 
	} 
	return m; 
} 

/* Given the position of previous leftmost 
set bit in n (or an upper bound on 
leftmost position) returns the new 
position of leftmost set bit in n */
unsigned int getNextLeftmostBit(int n, int m) 
{ 
	unsigned int temp = 1 << m; 
	while (n < temp) { 
		temp = temp >> 1; 
		m--; 
	} 
	return m; 
} 

// The main recursive function used by countSetBits() 
unsigned int _countSetBits(unsigned int n, int m); 

// Returns count of set bits present in 
// all numbers from 1 to n 
unsigned int countSetBits(unsigned int n) 
{ 
	// Get the position of leftmost set 
	// bit in n. This will be used as an 
	// upper bound for next set bit function 
	int m = getLeftmostBit(n); 

	// Use the position 
	return _countSetBits(n, m); 
} 

unsigned int _countSetBits(unsigned int n, int m) 
{ 
	// Base Case: if n is 0, then set bit 
	// count is 0 
	if (n == 0) 
		return 0; 

	/* get position of next leftmost set bit */
	m = getNextLeftmostBit(n, m); 

	// If n is of the form 2^x-1, i.e., if n 
	// is like 1, 3, 7, 15, 31, .. etc, 
	// then we are done. 
	// Since positions are considered starting 
	// from 0, 1 is added to m 
	if (n == ((unsigned int)1 << (m + 1)) - 1) 
		return (unsigned int)(m + 1) * (1 << m); 

	// update n for next recursive call 
	n = n - (1 << m); 
	return (n + 1) + countSetBits(n) + m * (1 << (m - 1)); 
} 

// Driver code 
int main() 
{ 
	int n = 17; 
	cout<<"Total set bit count is "<< countSetBits(n); 
	return 0; 
} 




// DP Approach

// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return the count of 
// set bits in all the integers 
// from the range [1, n] 
int countSetBits(int n) 
{ 

	// To store the required count 
	// of the set bits 
	int cnt = 0; 

	// To store the count of set 
	// bits in every integer 
	vector<int> setBits(n + 1); 

	// 0 has no set bit 
	setBits[0] = 0; 

	// 1 has a single set bit 
	setBits[1] = 1; 

	// For the rest of the elements 
	for (int i = 2; i <= n; i++) { 

		// If current element i is even then 
		// it has set bits equal to the count 
		// of the set bits in i / 2 
		if (i % 2 == 0) { 
			setBits[i] = setBits[i / 2]; 
		} 

		// Else it has set bits equal to one 
		// more than the previous element 
		else { 
			setBits[i] = setBits[i - 1] + 1; 
		} 
	} 

	// Sum all the set bits 
	for (int i = 0; i <= n; i++) { 
		cnt = cnt + setBits[i]; 
	} 

	return cnt; 
} 

// Driver code 
int main() 
{ 
	int n = 6; 

	cout << countSetBits(n); 

	return 0; 
} 
