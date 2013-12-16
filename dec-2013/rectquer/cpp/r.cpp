#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

int getMid(int s, int e) {  return s + (e -s)/2;  }
 
int getDistinctUtil(int *st, int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        return st[index];
 
    if (se < qs || ss > qe)
        return 0;
 
    int mid = getMid(ss, se);
    return getDistinctUtil(st, ss, mid, qs, qe, 2*index+1) | getDistinctUtil(st, mid+1, se, qs, qe, 2*index+2);
}
 
int getDistinct(int *st, int n, int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
 
    return getDistinctUtil(st, 0, n-1, qs, qe, 0);
}
 
int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
    if (ss == se)
    {
        st[si] = 1 << arr[ss];
        return 1 << arr[ss];
    }
 
    int mid = getMid(ss, se);
    st[si] = st[si] | (constructSTUtil(arr, ss, mid, st, si*2+1) | constructSTUtil(arr, mid+1, se, st, si*2+2));
    return st[si];
}
 
int *constructST(int arr[], int n)
{
    int x = (int)(ceil(log2(n))); //Height of segment tree
    int max_size = 2*(int)pow(2, x) - 1; //Maximum size of segment tree
    int *st = new int[max_size];
 
    constructSTUtil(arr, 0, n-1, st, 0);
 
    return st;
}

int pop(unsigned x)
{
    x = x - ((x >> 1) & 0x55555555);
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x + (x >> 4)) & 0x0F0F0F0F;
    x = x + (x >> 8);
    x = x + (x >> 16);
    return x & 0x0000003F;
}

int main()
{
    int n;
    scanf("%d", &n);

    int array_size = n * n;
    int array[array_size];

    for(int i=0;i<array_size;i++) {
        scanf("%d", &array[i]);
    }

    int *st = constructST(array, array_size); 

    int q;
    scanf("%d", &q);

    int x1, y1, x2, y2;

    for(int i=0;i<q;i++)
    {
        scanf("%d", &x1);
	scanf("%d", &y1);
	scanf("%d", &x2);
	scanf("%d", &y2);

        int startIndex = (n * (x1 - 1)) + (y1 - 1);
        int rowLength = (y2 - y1) + 1;
	int rowCount = (x2 - x1) + 1;
	int offset = n - rowLength;
	int z = startIndex;

	int answer = 0;

	for (int j=0; j<rowCount; j++)
	{
		answer = answer | getDistinct(st, array_size, z, rowLength + z - 1);
		if (answer == 2046) { break; }
		z += offset + rowLength;
	}

	printf("%i\n", answer);
	//printf("%i\n", pop(answer));
    }

    return 0;
}
