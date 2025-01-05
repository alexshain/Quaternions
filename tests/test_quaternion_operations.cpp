#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "../src/Quaternion.h"

#include <iostream>

void testSumQuaterAndQuater() {
    Quaternion quater1 = Quaternion{1, -2, -3, 4};
    Quaternion quater2 = Quaternion{1, 2, 3, 4};
    Quaternion result = quater1 + quater2;
    Quaternion assert_quater = Quaternion(2, 0, 0, 8);
    CU_ASSERT_EQUAL(result, assert_quater);
}

void testSumQuaterAndComplex() {
    Quaternion quater = Quaternion{1, -2, -3, 4};
    std::complex<int> complex(1, 2);
    Quaternion result = quater + complex;
    Quaternion assert_quater = Quaternion(2, 0, -3, 4);
    CU_ASSERT_EQUAL(result, assert_quater);
}

void testSumComplexAndQuater() {
    Quaternion quater = Quaternion{5, -6, -7, 8};
    std::complex<int> complex(9, 10);
    Quaternion result = quater + complex;
    Quaternion assert_quater = Quaternion(14, 4, -7, 8);
    CU_ASSERT_EQUAL(result, assert_quater);
}

void testSumQuaterAndScalar(){
    Quaternion quater = Quaternion(6, -7, -8, 9);
    int scalar = 5;
    Quaternion result = quater + scalar;
    Quaternion assert_quater = Quaternion(11, -7, -8, 9);
    CU_ASSERT_EQUAL(result, assert_quater);
}

void testSumScalarAndQuater(){
    Quaternion quater = Quaternion{6, -7, -8, 9};
    int scalar = 10;
    Quaternion result = scalar + quater;
    Quaternion assert_quater = Quaternion(16, -7, -8, 9);
    CU_ASSERT_EQUAL(result, assert_quater);
}

void testMultipleQuaterAndQuater() {
    Quaternion quater1 = Quaternion{1, -2, -3, 4};
    Quaternion quater2 = Quaternion{1, 2, 3, 4};
    Quaternion result = quater1 * quater2;
    Quaternion assert_quater = Quaternion(-2, -24, 16, 8);
    CU_ASSERT_EQUAL(result, assert_quater);
}


void testMultipleQuaterAndComplex() {
    Quaternion quater = Quaternion{1, -2, -3, 4};
    std::complex<int> complex{1, 2};
    Quaternion result = quater * complex;
    Quaternion assert_quater = Quaternion(5, 0, 5, 10);
    CU_ASSERT_EQUAL(result, assert_quater);
}

void testMultipleComplexAndQuater() {
    Quaternion quater = Quaternion{1, -2, -3, 4};
    std::complex<int> complex{1, 2};
    Quaternion result = complex * quater;
    Quaternion assert_quater = Quaternion(5, 0, -11, -2);
    CU_ASSERT_EQUAL(result, assert_quater);
}

void testMultipleQuaterAndScalar(){
    Quaternion quater = Quaternion{6, -7, -8, 9};
    int scalar = 10;
    Quaternion result = quater * scalar;
    Quaternion assert_quater = Quaternion(60, -70, -80, 90);
    CU_ASSERT_EQUAL(result, assert_quater);
}

void testMultipleScalarAndQuater(){
    Quaternion quater = Quaternion{1, 2, 3, 4};
    int scalar = 10;
    Quaternion result = scalar * quater;
    Quaternion assert_quater = Quaternion(10, 20, 30, 40);
    CU_ASSERT_EQUAL(result, assert_quater);
}

void testUnarMinus() {
    Quaternion quater = Quaternion{1, -2, -3, 4};
    Quaternion result = -quater;
    Quaternion assert_quater = Quaternion(-1, 2, 3, -4);
    CU_ASSERT_EQUAL(result, assert_quater);
}

void testMinusQuaterAndQuater() {
    Quaternion quater1 = Quaternion{1, -2, -3, 4};
    Quaternion quater2 = Quaternion{1, 2, 3, 4};
    Quaternion result = quater2 - quater1;
    Quaternion assert_quater = Quaternion(0, 4, 6, 0);
    CU_ASSERT_EQUAL(result, assert_quater);

    result = quater1 - quater2;
    assert_quater = Quaternion(0, -4, -6, 0);
    CU_ASSERT_EQUAL(result, assert_quater);
}

int main() {
    //Инициализация CUnit
    if (CUE_SUCCESS != CU_initialize_registry()) {
        return CU_get_error();
    }

    // Создание тестового набора
    CU_pSuite pSuite = CU_add_suite("QuaternionOperationsTest", 0, 0);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Добавление тестов в набор
    if ((NULL == CU_add_test(pSuite, "testSumQuaterAndQuater()", testSumQuaterAndQuater)) ||
        (NULL == CU_add_test(pSuite, "testSumQuaterAndComplex()", testSumQuaterAndComplex)) || 
        (NULL == CU_add_test(pSuite, "testSumComplexAndQuater()", testSumComplexAndQuater)) ||
        (NULL == CU_add_test(pSuite, "testSumQuaterAndScalar()", testSumQuaterAndScalar)) ||
        (NULL == CU_add_test(pSuite, "testSumScalarAndQuater()", testSumScalarAndQuater)) ||
        (NULL == CU_add_test(pSuite, "testMultipleQuaterAndQuater()", testMultipleQuaterAndQuater)) ||
        (NULL == CU_add_test(pSuite, "testMultipleQuaterAndComplex()", testMultipleQuaterAndComplex)) ||
        (NULL == CU_add_test(pSuite, "testMultipleComplexAndQuater()", testMultipleComplexAndQuater)) ||
        (NULL == CU_add_test(pSuite, "testMultipleQuaterAndScalar()", testMultipleQuaterAndScalar)) ||
        (NULL == CU_add_test(pSuite, "testMultipleScalarAndQuater()", testMultipleScalarAndQuater)) ||
        (NULL == CU_add_test(pSuite, "testUnarMinus()", testUnarMinus)) ||
        (NULL == CU_add_test(pSuite, "testMinusQuaterAndQuater()", testMinusQuaterAndQuater))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Запуск тестов с использованием базового интерфейса
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    unsigned int num_failures = CU_get_number_of_failures();
    // Очистка
    CU_cleanup_registry();

    return (num_failures == 0) ? 0 : 1;
}
