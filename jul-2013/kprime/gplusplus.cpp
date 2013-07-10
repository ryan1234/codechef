#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <sys/time.h>
#include <inttypes.h>

using namespace std;

uint64_t GetTimeMs64()
{
	struct timeval tv;

	gettimeofday(&tv, NULL);

	uint64_t ret = tv.tv_usec;
	/* Convert from micro seconds (10^-6) to milliseconds (10^-3) */
	ret /= 1000;

	/* Adds the seconds (10^0) after converting them to milliseconds (10^-3) */
	ret += (tv.tv_sec * 1000);

	return ret;
}

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

vector<int> get_nums(vector<unsigned long> primes) {
	vector<int> nums(100001);
       
	// The number of primes is static.
	for (int i = 0; i < 9592; i++) {
        	for (int j = 1; j <= ceil(100001 / primes[i]); j++) {
                	nums[primes[i] * j] = nums[primes[i] * j] + 1;
                }
        }	
	
	return nums;
}

int distinct_k_count(vector<int>& nums, int low, int high, int k) {
	int count = 0;

	for (int i = low; i <= high; i++) {
		if (nums[i] == k) { count++; }
	}

	return count;
}

main() {
	uint64_t start = 0;
	uint64_t end = 0;	

	start = GetTimeMs64();
	vector<unsigned long> primes = get_primes(100000);
	end = GetTimeMs64();
	cout << "Prime generation: " << end - start << endl;

	start = GetTimeMs64();
	vector<int> nums = get_nums(primes);
	end = GetTimeMs64();
	cout << "K table generation: " << end - start << endl;

	int test, low, high, k;

	cin >> test;

	start = GetTimeMs64();
	for (int i = 0; i < test; i++) {
		cin >> low >> high >> k;

		//int j = distinct_k_count(nums, low, high, k);
		cout << distinct_k_count(nums, low, high, k) << endl;
	}
	end = GetTimeMs64();
	cout << "Count: " << end - start << endl;

	return 0;
}
