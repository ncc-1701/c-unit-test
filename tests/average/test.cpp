// Include cpp-u-test's headers.
#include "CppUTest/TestHarness.h"

// Module's includes.
extern "C" {
	#include "average.h"
}

// Create a test group
TEST_GROUP(average_test_group)
{
	void setup()
	{
		// Initialize before each test
		
	}
	
	void teardown()
	{
		// Deinitialize after each test
	}
};

// Test the average functions.
TEST(average_test_group, sipmle_test)
{
	float arr[] = {-1.0, 0.0, 1.0, 2.0, 3.0};
	float result = average(arr, sizeof(arr)/sizeof(float));
	CHECK_EQUAL(result, 1.0);
}

// Test the error limit condition with average functions.
TEST(average_test_group, null_test)
{
	float arr[] = {1.0};
	float result = average(arr, 0);
	CHECK_EQUAL(result, 0.0);
}
