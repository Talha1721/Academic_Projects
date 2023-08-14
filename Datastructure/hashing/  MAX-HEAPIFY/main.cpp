MAX-HEAPIFY(A, i, n)
l ← LEFT(i)
r ← RIGHT(i)
if l ≤ n and A[l] > A[i]
   then largest ←l
   else largest ←i
if r ≤ n and A[r] > A[largest]
   then largest ←r
if largest  i
   then exchange A[i] ↔ A[largest]
            MAX-HEAPIFY(A, largest, n)

#include <iostream>

using namespace std;

int main()
{
    int i,n;
    cin>>n;
    int a[n];
    return 0;
}
