#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <streambuf>
#include <sys/time.h>
#include <ctime>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<unsigned long> get_primes(unsigned long max){
    vector<unsigned long> primes;
    char *sieve;
    sieve = new char[max/8+1];
    // Fill sieve with 1  
    memset(sieve, 0xFF, (max/8+1) * sizeof(char));
    for(unsigned long x = 2; x <= max; x++)
        if(sieve[x/8] & (0x01 << (x % 8))){
            primes.push_back(x);
            // Is prime. Mark multiplicates.
            for(unsigned long j = 2*x; j <= max; j += x)
                sieve[j/8] &= ~(0x01 << (j % 8));
        }
    delete[] sieve;
    return primes;
}

int is_prime(vector<unsigned long> primes, int num) {
	if(find(primes.begin(), primes.end(), num) != primes.end()) {
		return 1;
	} else {
		return 0;
	}
}

main()
{
	vector<unsigned long> primes = get_primes(100000);

	long int x, z, m, n, count = 0;
	cout << "Output square free integers from m to n: ";
	cin >> m >> n;
	x = m - 1;
	do
	{
		x++;
		z = 1;
		while (z <= x/2)
		{
			z++;
			if (x % (z * z) == 0)
				z = x + 3;
		}
		if (z != x + 3 && is_prime(primes, x) == 1)
			count++;
	}while (x < n);

	cout << count << endl;

	return 0;
}
