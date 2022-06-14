#include "pch.h"
#include "laba3_1.h"
#include "laba3_2.h"
#include "laba3_3.h"
#include "laba3_4.h"

TEST(zadacha_1, repeat_1) {
  EXPECT_EQ(check_repeated_digits(272767), 1);
}

TEST(zadacha_1, no_repeat_1) {
	EXPECT_EQ(check_repeated_digits(13689), 0);
}

TEST(zadacha_1, repeat_2) {
	EXPECT_EQ(check_repeated_digits(33330002), 1);
}

// ===========================================

TEST(zadacha_2, get_sum_test_1) {
	int arr[] = { -5, 6, 7, 3, 2 };
	EXPECT_EQ(get_sum(arr, 7), 12);
}

TEST(zadacha_2, get_sum_test_2) {
	int arr[] = { -5, -3, -1, -1, 5 };
	EXPECT_EQ(get_sum(arr, 5), 0);
}

TEST(zadacha_2, get_sum_test_3) {
	int arr[] = { 5, -1, 9, -2, 3, -1 };
	EXPECT_EQ(get_sum(arr, 6), 0);
}

// ===========================================

TEST(zadacha_3, test1) {
	int arr[7][7] = {
		{1,0,1,0,1,0,1},
		{1,0,1,0,1,0,1},
		{1,0,1,0,1,0,1},
		{1,0,1,0,1,0,1},
		{1,0,1,0,1,0,1},
		{1,0,1,0,1,0,1},
		{1,0,1,0,1,0,1}
	};
	EXPECT_EQ(get_sum_12(arr), 16);
	EXPECT_EQ(determinant(arr), 0);
}

TEST(zadacha_3, test2) {
	int arr[7][7] = {
		{1,0,1,0,1,0,1},
		{0,1,0,1,0,1,0},
		{5,1,8,0,1,0,1},
		{1,3,1,1,0,1,0},
		{1,1,2,0,1,0,1},
		{0,1,0,1,0,1,0},
		{1,0,1,0,1,0,1}
	};
	EXPECT_EQ(get_sum_12(arr), 39);
	EXPECT_EQ(determinant(arr), 8);
}

// ===========================================

TEST(zadacha_4, test1) {
	char players[3][6][2] = {
			{ {'1','\x06'}, {'5','\x06'}, {'2','\x06'}, {'8','\x06'}, {'3','\x06'}, {'9','\x06'} },
			{ {'1','\x05'}, {'5','\x06'}, {'2','\x06'}, {'8','\x06'}, {'3','\x06'}, {'9','\x06'} },
			{ {'1','\x06'}, {'5','\x06'}, {'2','\x04'}, {'8','\x06'}, {'3','\x06'}, {'9','\x06'} },
	};

	EXPECT_EQ(debug_main4(players), 1);
}

TEST(zadacha_4, test2) {
	char players[3][6][2] = {
			{ {'1','\x04'}, {'5','\x04'}, {'2','\x06'}, {'8','\x05'}, {'3','\x06'}, {'9','\x04'} },
			{ {'1','\x05'}, {'5','\x06'}, {'2','\x04'}, {'8','\x06'}, {'3','\x05'}, {'9','\x04'} },
			{ {'1','\x06'}, {'5','\x06'}, {'2','\x04'}, {'8','\x06'}, {'3','\x04'}, {'9','\x06'} },
	};

	EXPECT_EQ(debug_main4(players), 0);
}