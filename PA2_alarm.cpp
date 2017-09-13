#include <stdio.h>

int Bsearch( double* a, double* b, double x, double y, int n )
{
	int first = 0;
	int last = n-1;
	int mid;

	if( y >= b[last] - b[last] * x / a[last] )
		return n;

	if( y < b[0] - b[0] * x / a[0] )
		return 0;
	
	while( first <= last )
	{
		mid = (first + last) / 2;

		if( y == b[mid] - b[mid] * x / a[mid] )
			return mid + 1;
		else
		{
			if( y < b[mid] - b[mid] * x / a[mid] )
				last = mid;
			else
				first = mid;

			if ( last == first + 1 )
				return last;
		}
	}
	return 0;
};

int main()
{
	int n,m,i;
	static double a[200001];
	static double b[200001];
	double x;
	double y;
	static int result[200001];

	scanf("%d %d", &n, &m);

	for(i=0;i<n;i++)
	{
		scanf("%lf %lf", &a[i], &b[i]);
	}

	for(i=0;i<m;i++)
	{
		scanf("%lf %lf", &x, &y);

		result[i] = Bsearch( a, b, x, y, n );
	}

	for(i=0;i<m;i++)
	{
		printf("%d\n", result[i]);
	}
	
	return 0;
}