#include "pch.h"
#include "laba4_1.h"
#include "laba4_3.h"

TEST(zadacha_1, quick_sort1) {
	const int n = 6;
	int array_to_sort[n] = { 5,6,8,2,4,6 };
	int sorted_array[n] = { 2,4,5,6,6,8 };
	
	printArr(array_to_sort, n);
	quicksort(array_to_sort, 0, n - 1);
	printArr(array_to_sort, n);

	for (int i = 0; i < 6; ++i) {
		EXPECT_TRUE(array_to_sort[i] == sorted_array[i]);
	}
}

TEST(zadacha_1, quick_sort2) {
	const int n = 7;
	int array_to_sort[n] = { -52, -23, 5, 0, 2, -12, 56 };
	int sorted_array[n] = { -52, -23, -12, 0, 2, 5, 56 };

	printArr(array_to_sort, n);
	quicksort(array_to_sort, 0, n - 1);
	printArr(array_to_sort, n);

	for (int i = 0; i < 6; ++i) {
		EXPECT_TRUE(array_to_sort[i] == sorted_array[i]);
	}
}

// =======================================

TEST(zadacha_3, angles_tests) {
	EXPECT_EQ(angle(1, 1), 45);
	EXPECT_EQ(angle(4, 8), 27);
	EXPECT_EQ(angle(3, 4), 37);
}
