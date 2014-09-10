// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2014
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <utility>  // make_pair, pair


// ------------
// collatz_read
// ------------

std::pair<int, int> collatz_read (std::istream& r) {
    int i;
    r >> i;
    if (!r)
        return std::make_pair(0, 0);
    int j;
    r >> j;
    return std::make_pair(i, j);}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    // <your code>
	assert(i > 0);
	assert(j > 0);
	
	int store[1000000];
	int count = 1;
	
	for(int k = i; k <= j; k++)
	{
		count = 1;
		int n = k;
		while(n > 1)
		{
			if(n%2 != 0)
			{
				n = 3*n + 1;
				++count;
			}
			else
			{
				n = n/2;
				++count;
			}
		}
		store[k] = count;			
	}
	
	int max = store[i];
	for (int a = i; a <= j; a++)
	{
		//std::cout << store[a] << " , ";
		if(store[a] >= max)
		{
			max = store[a];			
		}
		
	}
	
    return max;}

// -------------
// collatz_print
// -------------

void collatz_print (std::ostream& w, int i, int j, int v) {
	assert(i > 0);
	assert(j > 0);
	assert(v > 0);
    w << i << " " << j << " " << v << std::endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (std::istream& r, std::ostream& w) {
    while (true) {
        const std::pair<int, int> p = collatz_read(r);
        if (p == std::make_pair(0, 0))
            return;
        const int i = p.first;
        const int j = p.second;
        const int v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
		
		
int main () {
    using namespace std;
    collatz_solve(cin, cout);
    return 0;}
