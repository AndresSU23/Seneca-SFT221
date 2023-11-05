#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_FACTORIALS 10000
#define NUM_FACTS 100
struct FactorialResults
{
	long double results[MAX_FACTORIALS];
	int numResults;
};

void computeFactorials(struct FactorialResults *results, int numFactorials)
{
	int i;
	for (i = 0; i < numFactorials; i++)
	{
		results->results[i] = (i) ? i * results->results[i - 1] : 1;
	}
	results->numResults = numFactorials;
}
int main(void)
{
	struct FactorialResults results = { {0}, 0 };
	int i;
	computeFactorials(&results, NUM_FACTS);
	for (i = 0; i < NUM_FACTS; i++)
	{
		printf("%5d %12Lf\n", i, results.results[i]);
	}
	return 0;
}
