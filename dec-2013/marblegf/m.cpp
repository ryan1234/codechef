#include <stdio.h>
#include <math.h>
#include <iostream> 

using namespace std;

#define getcx getchar_unlocked

typedef long long ll;

inline void s( ll &n )
{
    n=0;

    ll ch=getcx();
    while( ch < '0' || ch > '9' )
    {
        ch=getcx();

    }

    while(  ch >= '0' && ch <= '9' )
        n = (n<<3)+(n<<1) + ch-'0', ch=getcx();

}

inline void s( int &n )
{
    n=0;

    int ch=getcx();
    while( ch < '0' || ch > '9' )
    {
        ch=getcx();

    }

    while(  ch >= '0' && ch <= '9' )
        n = (n<<3)+(n<<1) + ch-'0', ch=getcx();

}

int getMid(int s, int e) {  return s + (e -s)/2;  }
 
int getSumUtil(int *st, int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        return st[index];
 
    if (se < qs || ss > qe)
        return 0;
 
    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*index+1) +
           getSumUtil(st, mid+1, se, qs, qe, 2*index+2);
}
 
void updateValueUtil(int *st, int ss, int se, int i, int diff, int index)
{
    if (i < ss || i > se)
        return;
 
    st[index] = st[index] + diff;
    if (se != ss)
    {
        int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*index + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*index + 2);
    }
}
 
void updateValue(int arr[], int *st, int n, int i, int new_val)
{
    if (i < 0 || i > n-1)
    {
        printf("Invalid Input");
        return;
    }
 
    int diff = (arr[i] + new_val) - arr[i];
 
    arr[i] = arr[i] + new_val;
 
    updateValueUtil(st, 0, n-1, i, diff, 0);
}
 
int getSum(int *st, int n, int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
 
    return getSumUtil(st, 0, n-1, qs, qe, 0);
}
 
int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    int mid = getMid(ss, se);
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) +
              constructSTUtil(arr, mid+1, se, st, si*2+2);
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
 
int main()
{
    int n;
    int q;

    cin >> n >> q;

    int array[n];

    for(int i=0;i<n;i++)
        s(array[i]);

    char op;
    int j, k;

    int *st = constructST(array, n);

    for(int i = 0; i < q; i++) {
        cin >> op >> j >> k;
        if (op == 'S')
            cout << getSum(st, n, j, k) << endl;

        if (op == 'G')
            updateValue(array, st, n, j, k);

        if (op == 'T')
            updateValue(array, st, n, j, k * -1);
    }

    return 0;
}
