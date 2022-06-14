#include "pch.h"

#include "laba5_1.h"
#include "laba5_2.h"
#include "laba5_3.h"

TEST(zadacha_1, check_coins) {
	int
		results[6][6] = {
			{ 1,0,0,0,0,0 },
			{ 0,1,0,0,0,0 },
			{ 0,0,1,0,0,0 },
			{ 0,0,0,1,0,0 },
			{ 0,0,0,0,1,0 },
			{ 0,0,0,0,0,1 }
		},

		sums[6] = { 50,25,10,5,2,1 },
		tmp[6];

	int* pointer;

	for (int i = 0; i < 6; ++i) {
		printf("-=-=-[ TEST %d ]-=-=-\n", i);

		for (int j = 0; j < 6; ++j) tmp[j] = 0;

		pointer = &tmp[0];
		convert_coins(sums[i], pointer);
		for (int j = 0; j < 6; ++j) {
			EXPECT_TRUE(tmp[j] == results[i][j]);
		}
	}
}

TEST(zadacha1, random_numbers) {
	int
		results[2][6] = {
			{0,1,0,1,1,1},
			{5,0,0,1,0,0}
		},
		sums[2] = {
			33, 255
		},
		tmp[6];

	int* pointer;

	for (int i = 0; i < 2; ++i) {
		printf("-=-=-[ RANDOM TEST %d ]-=-=-\n", i);

		for (int j = 0; j < 6; ++j) tmp[j] = 0;

		pointer = &tmp[0];
		convert_coins(sums[i], pointer);
		for (int j = 0; j < 6; ++j) {
			EXPECT_TRUE(tmp[j] == results[i][j]);
		}
	}
}

// ========================================

TEST(zadacha_2, tests) {
	int
		arrTest1[3] = { 156, 32, 183 },
		arrTest2[5] = { 123, 133, 31, 21, 26 },
		arrTest3[9] = { 524, 134, 31, 63, 123, 66, 26, 86, 194 },
		arrTest4 = 256,
		i = 1,

		counts[2] = { 0, },
		resCounts[2] = { 0, };

	int * countPtr = &counts[0];

	printf("-=-=-=[ COMPARE TEST %d ]=-=-=-\n", i);
	compare_count(&arrTest1[0], countPtr, 3);
	resCounts[0] = 1; resCounts[1] = 2;
	EXPECT_TRUE((counts[0] == resCounts[0] && counts[1] == resCounts[1]));
	counts[0] = 0; counts[1] = 0; i++;

	printf("-=-=-=[ COMPARE TEST %d ]=-=-=-\n", i);
	compare_count(&arrTest2[0], countPtr, 5);
	resCounts[0] = 3; resCounts[1] = 2;
	EXPECT_TRUE((counts[0] == resCounts[0] && counts[1] == resCounts[1]));
	counts[0] = 0; counts[1] = 0; i++;

	printf("-=-=-=[ COMPARE TEST %d ]=-=-=-\n", i);
	compare_count(&arrTest3[0], countPtr, 9);
	resCounts[0] = 5; resCounts[1] = 3;
	EXPECT_TRUE((counts[0] == resCounts[0] && counts[1] == resCounts[1]));
	counts[0] = 0; counts[1] = 0; i++;
	
	printf("-=-=-=[ COMPARE TEST %d ]=-=-=-\n", i);
	compare_count(&arrTest4, countPtr, 0);
	resCounts[0] = 0; resCounts[1] = 0;
	EXPECT_TRUE((counts[0] == resCounts[0] && counts[1] == resCounts[1]));
}

// =====================================

TEST(zadacha_4, equals_tests) {
	int i = 1;
	int matrix1[4][4] = {
		{1,2,3,4},
		{0,1,2,0},
		{0,1,2,0},
		{1,2,3,4}
	};
	int matrix2[5][5] = {
		{1,2,3,4,5},
		{0,1,2,3,0},
		{0,0,1,0,0},
		{0,1,2,3,0},
		{1,2,3,4,5}
	};
	int matrix3[7][7] = {
		{1,2,3,4,5,6,7},
		{0,1,2,3,4,5,0},
		{0,0,1,2,3,0,0},
		{0,0,0,1,0,0,0},
		{0,0,1,2,3,0,0},
		{0,1,2,3,4,5,0},
		{1,2,3,4,5,6,7}
	};
	
	printf("-=-=-=[ EQ TEST %d ]=-=-=-\n", i);
	EXPECT_EQ(check_triangles(&matrix1[0][0], 4), 1);

	printf("-=-=-=[ EQ TEST %d ]=-=-=-\n", i + 1);
	EXPECT_EQ(check_triangles(&matrix2[0][0], 5), 1);

	printf("-=-=-=[ EQ TEST %d ]=-=-=-\n", i + 2);
	EXPECT_EQ(check_triangles(&matrix3[0][0], 7), 1);
}

TEST(zadacha_4, does_not_equals_tests) {
	int i = 0;

	int matrix1[4][4] = {
		{1,2,3,4},
		{0,1,2,0},
		{0,1,3,0},
		{1,5,7,4}
	};
	int matrix2[5][5] = {
		{1,2,3,4,5},
		{0,1,2,3,0},
		{0,0,1,0,0},
		{0,6,5,3,0},
		{1,2,7,4,5}
	};
	int matrix3[7][7] = {
		{1,2,3,4,5,6,7},
		{0,1,2,3,4,5,0},
		{0,0,1,2,3,0,0},
		{0,0,0,1,0,0,0},
		{0,0,2,3,3,0,0},
		{0,3,8,3,5,5,0},
		{1,2,3,4,5,6,7}
	};

	printf("-=-=-=[ NOT EQ TEST %d ]=-=-=-\n", i);
	EXPECT_EQ(check_triangles(&matrix1[0][0], 4), 0);

	printf("-=-=-=[ NOT EQ TEST %d ]=-=-=-\n", i + 1);
	EXPECT_EQ(check_triangles(&matrix2[5][5], 5), 0);

	printf("-=-=-=[ NOT EQ TEST %d ]=-=-=-\n", i + 2);
	EXPECT_EQ(check_triangles(&matrix3[0][0], 7), 0);
}
