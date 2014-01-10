#include<iostream>
#include<stdio.h>
#include<tuple>
#include<vector>
#include<algorithm>
using namespace std;

typedef tuple<unsigned long,unsigned long> interval;

bool mycompare (const interval &lhs, const interval &rhs){
  return get<1>(lhs) < get<1>(rhs);
}

int main() {
	int tests;
	unsigned long n,k,s,f,p;
	scanf("%d", &tests);

	for (int i = 0; i < tests; i++) {
		scanf("%lu", &n);
		scanf("%lu", &k);

		vector<interval> spots[k];
/*
		for (long long j = 0; j < n; j++) {
			scanf("%lld", &s);
			scanf("%lld", &f);
			scanf("%lld", &p);

			spots[p-1].push_back(make_tuple(s,f));
		}

		long long total = 0;
		
		for (long long j = 0; j < k; j++) {
			sort(spots[j].begin(), spots[j].end(), mycompare);

			long long finish = 0;
			
			for (vector<interval>::iterator iter = spots[j].begin(); iter != spots[j].end(); iter++) {
				if (finish <= get<0>(*iter)) {
					finish = get<1>(*iter);
					total += 1;
				}
				//cout << get<0>(*iter) << "\t" << get<1>(*iter) << endl;
  			}
		}

		printf("%lld\n", total);
*/
	}
}
