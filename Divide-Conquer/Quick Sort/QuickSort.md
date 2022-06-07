## Time complexity: 
> [Best case & Avarage case : O(n*logn)],[Worst case: O(n^2)]
## Space complexity: 
> O(1)
## stable and in palce algo
## More efficient when randomized pivot used
## Recurrence relation: 
> T(n) = 2T(n/2) + θ(n)**
> Time taken by QuickSort, in general, can be written as following.

> T(n) = T(k) + T(n-k-1) + \theta (n)

> The first two terms are for two recursive calls, the last term is for the partition process. k is the number of elements which are  smaller than pivot.
> The time taken by QuickSort depends upon the input array and partition strategy. Following are three cases.

> **Worst Case:**
> The worst case occurs when the partition process always picks greatest or smallest element as pivot. If we consider above partition  strategy where last element is always picked as pivot, the worst case would occur when the array is already sorted in increasing or  decreasing order. Following is recurrence for worst case.

>      T(n) = T(0) + T(n-1) + θ(n)which is equivalent to  T(n) = T(n-1) + θ(n)

> The solution of above recurrence is   n<sup>2</sup>.

> **Best Case:**
> The best case occurs when the partition process always picks the middle element as pivot. Following is recurrence for best case.

>      T(n) = 2T(n/2) + θ(n)

