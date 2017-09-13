// #include <stdio.h>
// #include <stdlib.h>
// #define MAX 500010

// int S[MAX];

// int compare(const void *a, const void *b)
// {
//     return *((int*)a) - *((int*)b);
// }

// int GetPosition(int lo,int hi,int e){
//     // return the highest rank <= e, return -1 if less than S[0]
//     while(lo<hi){
//         int mid=(lo+hi)/2;
//         //int mid = lo + ((hi - lo)>>1);
//         (e<S[mid])?hi=mid:lo = mid+1;
//     }
//     return --lo;
// }

// int main()
// {
//     int n, m, i;

//     scanf("%d", &n);
//     scanf("%d", &m);

//     for(i=0;i<n;i++){
//         scanf("%d",&S[i]);
//     }

//     qsort(S, m, sizeof(int), compare);

//     for(i=0;i<m;i++){
//         int a,b;
//         scanf("%d",&a);
//         scanf("%d",&b);

//         int p1 = GetPosition(0,n,a);
//         while(S[p1]==a && p1>=0)
//             p1--;
//         int p2 = GetPosition(0,n,b);
//         int count = p2-p1;
//         printf("%d\n",count);
//     }

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *((int*)a) - *((int*)b);
}

int binary_search(int *a, int e, int lo, int hi)
{
    int mid;
    while(lo<hi)
    {
        mid = lo + ((hi - lo)>>1);
        (e<a[mid])?hi=mid:lo = mid+1;
    }
    return --lo;
}

int main(int argc, char * argv[])
{
    int m, n, x, y, l, r, i, cnt;
    scanf("%d %d", &m, &n);
    int *a = (int*)malloc(m*sizeof(int));

    for(i = 0; i < m; i++)
        scanf("%d", &a[i]);
    qsort(a, m, sizeof(int), cmp);

    while(n--)
    {
        cnt = 0;
        scanf("%d %d", &l, &r);
        y = binary_search(a, r, 0, m);
        x = binary_search(a, l, 0, m);
        if(a[x] == l)
            cnt = y - x + 1;
        else cnt = y - x;
        if(x == -1)
            cnt = y + 1;
        printf("%d\n", cnt );
    }
    return 0;
}