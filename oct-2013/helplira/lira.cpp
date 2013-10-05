#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

main() {
        int test, x1, y1, x2, y2, x3, y3;

        cin >> test;

        double biggest = 0;
        double smallest = numeric_limits<double>::max();

	int biggest_index = 0;
	int smallest_index = 0;

        for (int i = 0; i < test; i++) {
                cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

                double l1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
                double l2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
                double l3 = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

                double p = (l1 + l2 + l3) / 2.0;
		double t = p * (p - l1) * (p - l2) * (p - l3);
                double area = sqrt(t);

                if (area >= biggest) { biggest = area; biggest_index = i + 1; }
                if (area <= smallest) { smallest = area; smallest_index = i + 1; }
        }

        cout << smallest_index << " " << biggest_index << endl;

        return 0;
}
