#include <set>
#include <iostream>

using namespace std;

int main()
{
	int i = 2;
	int j = 5;
	int a = 1;
	int b = 10;
	int k = (1 << (i - 1)) | (1 << (j - 1));
	k =  k | ((1 << (a - 1)) | (1 << (b - 1)));
	cout << k;
}
