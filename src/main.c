/* Standard includes. */
#include <stdio.h>

/* Module's includes. */
#include "average.h"


int main()
{
	float arr[] = {-1.0, 0.0, 1.0, 2.0, 3.0};
	float result = average(arr, sizeof(arr)/sizeof(float));
	printf("Average = %f", result);
	
	return 0;
}
