#include <iostream>
#include <stdlib.h>
using namespace std;

//extended euclid algorithm to get k inverse
int egcd(int a, int b)
{
	int x = 0;
	int y = 1;
	int u = 1;
	int v = 0;
	while(a != 0)
	{
		int q = b/a;
		int r = b%a;
		int m = x-u*q;
		int n = y-v*q;
		b = a;
		a = r;
		x = u;
		y = v;
		u = m;
		v = n;
	}
	return y;
}

//where the magic happens
int main()
{
	int primes[42] = {11,13,17,19,23,29,31,37,41,43,47,
					  53,59,61,67,71,79,83,89,97,101,103,
					  107,109,113,127,131,137,139,149,151,
					  157,163,167,173,179,181,191,193,197,
					  199};
	int index;
	int pq[2];
	int phi;
	int k;
	int m;
	int inverse;
	int i = 0;

	//randomly get two unique prime numbers
	while(i < 2)
	{
		srand(time(NULL));
		index = rand() % 42;
		pq[i] = primes[index];
		if(pq[0] != pq[1])
		{
			i++;
		}
	}

	//calculate m, phi, and k inverse
	m = pq[0] * pq[1];
	phi = (pq[0] - 1) * (pq[1] - 1);
	inverse = egcd(phi,17);

	//show private and public key
	cout << "Private Key:" << endl;
	cout << "p = " << pq[0] << endl;
	cout << "q = " << pq[1] << endl;
	cout << "k inverse = " << inverse << endl << endl;
	cout << "Public Key:" << endl;
	cout << "m = " << m << endl;
	cout << "k = 17" << endl;
}
