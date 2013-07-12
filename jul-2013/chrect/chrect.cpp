#include <iostream>
#include <cmath>
 
using namespace std;
 
main() {
        int test, n, m, k;
 
        cin >> test;
 
        for (int i = 0; i < test; i++) {
                cin >> n >> m >> k;
 
                if (n == 1 && m == 1) {
                        cout << 0 << endl;
                }
                else if (n == 1 && m == 2) {
                        cout << 0 << endl;
                }
                else if (n == 2 && m == 1) {
                        cout << 0 << endl;
                }
                else if (n == 1 || m == 1) {
                        cout << k << endl;
                }
                else {
                        cout << ceil(k / 2.0) << endl;
                }
        }
 
        return 0;
}
