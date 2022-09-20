// Main.cpp
#include <iostream>

#include "Data.h"
#include "Tools.h"


//---------------------------------------------------------------------------------------------------------------------
// Assignment 2.4
// 
// 
// ===== Explanation: =====
// 
// Take a look at the arrays in Data.h.  This is an array of integers which are guaranteed to be from 0 - 100, 
// inclusive (i.e. 0 and 100 are valid values as is everything in between, but nothing below 0 or greater than 100 
// will be present in the array).  Notice that there are several long stretches where the same number is repeated 
// over and over.  We can use this to our advantage to compress the array.  The algorithm should work as follows:
// 
//      1) Let A be the input array and B be the output array generated by the algorithm.
//      2) For every element in A, copy that element over the B along with the number of times that element appears 
//         in the array adjacent to the original.
// 
// Example:
//      A = { 2, 2, 2, 2, 2, 4, 4, 4, 2, 2, 2, },
//      B = { 2, 5, 4, 3, 2, 3 },
// 
// Looking at A, we see that there are five 2's followed by three 4's and ending with three 2's.  The B array contains 
// a 2 followed by a 5.  This says that there were five 2's.  Next is a 4 and 3, that means there were three 4's.
// Finally, we have a 2 and a 3, so there are three 2's.
// 
// Note how B is only 6 elements compared to A, which is 11, so it's just over half the size.
// 
// 
// ===== The Assignment: =====
// 
// Your job is to write two functions: The first is called Deflate() and goes from an uncompressed array (A) to a 
// compressed array (B).  The second is called Inflate(), which goes from a compressed array (B) to an uncompressed 
// array (A).
// 
// Here are some notes and additional constraints:
// 
//      1) You cannot use anything in the std namespace except cout and cin.
//      2) The signature of the functions is up to you and is a part of the assignment. Either way, you MUST document 
//         the parameters and any return values.
// ===== Tests: =====
// 
// The following criteria should be used when testing:
// 
//      1) No crashes or other similar issues.
//      2) The size of the output array (B) is <= the size of the input array (A).
//      3) Let C be the result of running Inflate() on the B array.  A should be exactly the same as C.
//      4) The functions should be self-contained.  They can't access global data.
//      5) The interface should be reasonable.
// 
// Note: There are no tests provided.  It's not required for you to write them, but you really should.
// 
// 
// ===== Grading: =====
// 
// C: All tests pass for the g_dataC array.
// B: All tests pass for g_dataC and g_dataB.
// A: All tests pass for g_dataC, g_dataB, and g_dataA.
// D: Some tests pass for g_dataC.
// F: No tests pass.
// 
// Hint for the A and B levels: Can you utilize the fact that the numbers are guaranteed to be between 1 and 100?
// 
// Other things can also help raise your grade, such as memory and/or performance efficiency.  In other words, if you 
// only complete the C requirements, it is still possible to get a higher grade.
//---------------------------------------------------------------------------------------------------------------------

int main()
{
	std::cout << "Compressed Arrays:" << std::endl;
	const int* c = Deflate(g_dataC, kDataCSize);
	const int* b = Deflate(g_dataB, kDataBSize);
	const int* a = Deflate(g_dataA, kDataASize);
	PrintArray(c, 14);
	PrintArray(b, 10);
	PrintArray(a, 10);

	std::cout << "" << std::endl;

	std::cout << "De-Compressed Arrays:" << std::endl;
	const int* inC = Inflate(c, 14);
	const int* inB = Inflate(b, 10);
	const int* inA = Inflate(a, 10);

	PrintArray(inC, kDataCSize);
	PrintArray(inB, kDataBSize);
	PrintArray(inA, kDataASize);
	
    return 0;
}