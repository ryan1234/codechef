#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
 
using namespace std;

int isOverlucky(long int x) {
        if(x > 10) {
                if (isOverlucky(x / 10) == 1) {
                        return 1;
                }
        }

        int digit = x % 10;

        if (digit == 4 || digit == 7) {
                return 1;
        }
        else {
                return 0;
        }
}

int getFactors(long int n) {
	int count = 0;

	for (long int i = 2; i <= n; i++) {
		if (n % i == 0) {
			if (isOverlucky(i)) {
				count++;
			}
		}
	}

	return count;
}

main() {

	int tests;
	long int n;

	cin >> tests;

	for (int i = 0; i < tests; i++) {
		cin >> n;
		cout << getFactors(n) << endl;
	}

	return 0;
}
