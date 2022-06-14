#include "pch.h"

#include "laba6_1.h"
#include "laba6_2.h"
#include "laba6_3.h"
#include "laba6_4.h"

#include <string.h>

// In IDE Visual Studio 2022 it could raise an error
// be careful
extern "C" {
#include "sds.h"
}


TEST(zadacha_1, no_test) {
	print_my_name();
	EXPECT_TRUE(true);
}

// ======================================

TEST(zadacha_2, tests) {
	char 
		test1[20], 
		test2[20], 
		test3[20];
	
	strcpy(test1, "Roman No. 123");
	strcpy(test2, "515");
	strcpy(test3, "127.0.0.1");

	char
		* tp1 = &test1[0],
		* tp2 = &test2[0],
		* tp3 = &test3[0];

	EXPECT_EQ(encode_digits(tp1), 3);
	EXPECT_EQ(encode_digits(tp2), 3);
	EXPECT_EQ(encode_digits(tp3), 4);

	printf("%s\n", tp1);
	printf("%s\n", tp2);
	printf("%s\n", tp3);
}

// ======================================
// it does not work in IDE VS 2022 trust me :D
TEST(zadacha_3, tests) {
	EXPECT_EQ(encode_digits3("Roman No. 123"), 3);
	EXPECT_EQ(encode_digits3("515"), 3);
	EXPECT_EQ(encode_digits3("127.0.0.1"), 6);
}

// ======================================

TEST(zadacha_4, test1) {
	char* arr1[5] = { "test", "Roman No. 123", "515", "127.0.0.1" };
	EXPECT_EQ(show_table(5, arr1), 0);
}

TEST(zadacha_4, test2) {
	char* arr2[2] = { "./a.out", "-?" };
	EXPECT_EQ(show_table(2, arr2), 0);
}

TEST(zadacha_4, test3) {
	char* arr3[2] = { "./a.out", "/?" };
	EXPECT_EQ(show_table(2, arr3), 0);
}

TEST(zadacha_4, test4) {
	char* arr4[1] = { "./a.out" };
	EXPECT_EQ(show_table(1, arr4), 0);
}


