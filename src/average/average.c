#include "average.h"

float average(float arr[], unsigned int size)
{
	/* Validate the input parameters. */
	/* Check for zero size. */
	if(size == 0) return 0.0;
	
	float result = 0;
	float *pArr = arr;
	for(unsigned int i = 0; i < size; i++)
	{
		result += *pArr;
		pArr++;
	}
	
	result /= (float)size;
	return result;
}
