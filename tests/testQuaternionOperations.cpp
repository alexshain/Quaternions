#include <gtest/gtest.h>
#include "../src/Quaternion.h"

#include <iostream>

TEST(testSum, QuaterAndQuater) {
    Quaternion quater1 = Quaternion{1, -2, -3, 4};
    Quaternion quater2 = Quaternion{1, 2, 3, 4};
    Quaternion result = quater1 + quater2;
    Quaternion assert_quater = Quaternion(2, 0, 0, 8);
    EXPECT_EQ(result, assert_quater);
}

TEST(testSum, QuaterAndComplex) {
    Quaternion quater = Quaternion{1, -2, -3, 4};
    std::complex<int> complex(1, 2);
    Quaternion result = quater + complex;
    Quaternion assert_quater = Quaternion(2, 0, -3, 4);
    EXPECT_EQ(result, assert_quater);
}

TEST(testSum, ComplexAndQuater) {
    Quaternion quater = Quaternion{5, -6, -7, 8};
    std::complex<int> complex(9, 10);
    Quaternion result = complex + quater;
    Quaternion assert_quater = Quaternion(14, 4, -7, 8);
    EXPECT_EQ(result, assert_quater);
}

TEST(testSum, QuaterAndScalar) {
    Quaternion quater = Quaternion(6, -7, -8, 9);
    int scalar = 5;
    Quaternion result = quater + scalar;
    Quaternion assert_quater = Quaternion(11, -7, -8, 9);
    EXPECT_EQ(result, assert_quater);
}

TEST(testSum, ScalarAndQuater) {
    Quaternion quater = Quaternion{6, -7, -8, 9};
    int scalar = 10;
    Quaternion result = scalar + quater;
    Quaternion assert_quater = Quaternion(16, -7, -8, 9);
    EXPECT_EQ(result, assert_quater);
}

TEST(testMultiple, QuaterAndQuater) {
    Quaternion quater1 = Quaternion{1, -2, -3, 4};
    Quaternion quater2 = Quaternion{1, 2, 3, 4};
    Quaternion result = quater1 * quater2;
    Quaternion assert_quater = Quaternion(-2, -24, 16, 8);
    EXPECT_EQ(result, assert_quater);
}

TEST(testMultiple, QuaterAndComplex) {
    Quaternion quater = Quaternion{1, -2, -3, 4};
    std::complex<int> complex{1, 2};
    Quaternion result = quater * complex;
    Quaternion assert_quater = Quaternion(5, 0, 5, 10);
    EXPECT_EQ(result, assert_quater);
}

TEST(testMultiple, ComplexAndQuater) {
    Quaternion quater = Quaternion{1, -2, -3, 4};
    std::complex<int> complex{1, 2};
    Quaternion result = complex * quater;
    Quaternion assert_quater = Quaternion(5, 0, -11, -2);
    EXPECT_EQ(result, assert_quater);
}

TEST(testMultiple, QuaterAndScalar) {
    Quaternion quater = Quaternion{6, -7, -8, 9};
    int scalar = 10;
    Quaternion result = quater * scalar;
    Quaternion assert_quater = Quaternion(60, -70, -80, 90);
    EXPECT_EQ(result, assert_quater);
}

TEST(testMultiple, ScalarAndQuater) {
    Quaternion quater = Quaternion{1, 2, 3, 4};
    int scalar = 10;
    Quaternion result = scalar * quater;
    Quaternion assert_quater = Quaternion(10, 20, 30, 40);
    EXPECT_EQ(result, assert_quater);
}

TEST(testUnarMinus, Quater) {
    Quaternion quater = Quaternion{1, -2, -3, 4};
    Quaternion result = -quater;
    Quaternion assert_quater = Quaternion(-1, 2, 3, -4);
    EXPECT_EQ(result, assert_quater);
}

TEST(testMinus, QuaterAndQuater) {
    Quaternion quater1 = Quaternion{1, -2, -3, 4};
    Quaternion quater2 = Quaternion{1, 2, 3, 4};
    Quaternion result = quater2 - quater1;
    Quaternion assert_quater = Quaternion(0, 4, 6, 0);
    EXPECT_EQ(result, assert_quater);

    result = quater1 - quater2;
    assert_quater = Quaternion(0, -4, -6, 0);
    EXPECT_EQ(result, assert_quater);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}