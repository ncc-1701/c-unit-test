#include "average.h"

float average(float arr[], unsigned int size)
{
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
