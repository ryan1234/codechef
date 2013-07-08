#include <vector>
#include <cstring>
#include <iostream>

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

int two(vector<unsigned long> primes, int low, int high) {
        int count = 0;

        for (int i = 0; i < primes.size(); i++) {
                int z = 0;

                for (int j = i + 1; j < primes.size(); j++) {
                        int candidate = primes.at(i) * primes.at(j);

                        if (candidate <= high && candidate >= low) { 
                                count++; z++; 
                        }   
                        else if (candidate > high) { break; }
                }   

                if (z == 0) { break; }
        }   

        return count;
}

int three(vector<unsigned long> primes, int low, int high) {
        int count = 0;

        for (int i = 0; i < primes.size(); i++) {
                int z = 0;

                for (int j = i + 1; j < primes.size(); j++) {
			int y = 0;

			for (int k = j + 1; k < primes.size(); k++) {
                        	int candidate = primes.at(i) * primes.at(j) * primes.at(k);

                        	if (candidate <= high && candidate >= low) {
                                	count++; z++; y++;
                        	}
                        	else if (candidate > high) { break; }
			}

			if (y == 0) { break; }
                }

                if (z == 0) { break; }
        }

        return count;
}


main() {
	int low = 2;
	int high = 50;

        vector<unsigned long> primes = get_primes(50000);

	cout << three(primes, low, high) << endl;

	return 0;
}
