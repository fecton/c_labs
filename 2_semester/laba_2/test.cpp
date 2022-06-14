#include "pch.h"
#include "laba2_1.c"
#include "laba2_2.h"

TEST(zadacha_1, tests) {
	EXPECT_FLOAT_EQ(func(0.2), 0.541683);
	EXPECT_FLOAT_EQ(func(0.5), 1.0731019);
	EXPECT_FLOAT_EQ(func(0.6), 1.8209883);
	EXPECT_FLOAT_EQ(func(0.8), 9.3592043);
}

// =============================================

TEST(zadacha_2, tg_test) {
	EXPECT_DOUBLE_EQ(tangence(0), 0);
	EXPECT_DOUBLE_EQ(tangence(45), 1);
}

TEST(zadacha_2, modul_test) {
	EXPECT_DOUBLE_EQ(modul(-23), 23);
	EXPECT_DOUBLE_EQ(modul(-999), 999);
}

TEST(zadacha_2, sqrt3_test) {
	EXPECT_DOUBLE_EQ(sqrt3(27), 3);
	EXPECT_DOUBLE_EQ(sqrt3(64), 4);
	EXPECT_DOUBLE_EQ(sqrt3(125),5);
}
