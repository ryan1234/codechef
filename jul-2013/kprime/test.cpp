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
				cout << "Considering: " << primes.at(i) << "," << primes.at(j) << "," << primes.at(k) << endl;
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

int four(vector<unsigned long> primes, int low, int high) {
        int count = 0;

        for (int i = 0; i < primes.size(); i++) {
                int z = 0;

                for (int j = i + 1; j < primes.size(); j++) {
                        int y = 0;

                        for (int k = j + 1; k < primes.size(); k++) {
				int x = 0;

				for (int l = k + 1; l < primes.size(); l++) {
        	                        int candidate = primes.at(i) * primes.at(j) * primes.at(k) * primes.at(l);

                	                if (candidate <= high && candidate >= low) {
                        	                count++; z++; y++; x++;
                                	}
	                                else if (candidate > high) { break; }
				}

				if (x == 0) { break; }
                        }

                        if (y == 0) { break; }
                }

                if (z == 0) { break; }
        }

        return count;
}

int five(vector<unsigned long> primes, int low, int high) {
        int count = 0;

        for (int i = 0; i < primes.size(); i++) {
                int z = 0;

                for (int j = i + 1; j < primes.size(); j++) {
                        int y = 0;

                        for (int k = j + 1; k < primes.size(); k++) {
                                int x = 0;

                                for (int l = k + 1; l < primes.size(); l++) {
					int w = 0;

					for (int m = l + 1; m < primes.size(); m++) {
	                                        int candidate = primes.at(i) * primes.at(j) * primes.at(k) * primes.at(l) * primes.at(m);

        	                                if (candidate <= high && candidate >= low) {
                	                                count++; z++; y++; x++; w++;
                        	                }
                                	        else if (candidate > high) { break; }
					}

					if (w == 0) { break; }
                                }

                                if (x == 0) { break; }
                        }

                        if (y == 0) { break; }
                }

                if (z == 0) { break; }
        }

        return count;
}


main() {
	int low = 2;
	int high = 300;

        vector<unsigned long> primes = get_primes(50000);

	cout << four(primes, low, high) << endl;

	return 0;
}
