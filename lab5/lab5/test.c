#include "test.h"

//задание 1

MU_TEST(test_calc_sum) {
    mu_assert_double_eq(5.0, sum(2.0, 3.0));
    mu_assert_double_eq(-1.0, sum(2.0, -3.0));
}

MU_TEST(test_calc_sub) {
    mu_assert_double_eq(10.0, sub(15.0, 5.0));
}

MU_TEST(test_calc_mul) {
    mu_assert_double_eq(6.0, mul(2.0, 3.0));
}

MU_TEST(test_calc_div) {
    mu_assert_double_eq(2.5, dv(5.0, 2.0));
    
    mu_assert_double_eq(0.0, dv(5.0, 0.0));
}

MU_TEST(test_calc_pow) {
    mu_assert_double_eq(8.0, pwr(2.0, 3.0));
}

// задание 2

MU_TEST(test_sort_int) {
    int arr[] = { 3, 1, 2 };
    universal_sort(arr, 3, sizeof(int), swapInt, cmpInt);

    mu_assert_int_eq(1, arr[0]);
    mu_assert_int_eq(2, arr[1]);
    mu_assert_int_eq(3, arr[2]);
}

MU_TEST(test_sort_double) {
    double arr[] = { 3.3, 1.1, 2.2 };
    universal_sort(arr, 3, sizeof(double), swapDouble, cmpDouble);

    mu_assert_double_eq(1.1, arr[0]);
    mu_assert_double_eq(2.2, arr[1]);
    mu_assert_double_eq(3.3, arr[2]);
}

MU_TEST(test_sort_string) {
    
    char* arr[] = { "CCC", "AAA", "BBB" };
    universal_sort(arr, 3, sizeof(char*), swapStr, cmpStr);

    mu_assert_int_eq(0, strcmp("AAA", arr[0]));
    mu_assert_int_eq(0, strcmp("BBB", arr[1]));
    mu_assert_int_eq(0, strcmp("CCC", arr[2]));
}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_calc_sum);
    MU_RUN_TEST(test_calc_sub);
    MU_RUN_TEST(test_calc_mul);
    MU_RUN_TEST(test_calc_div);
    MU_RUN_TEST(test_calc_pow);

    MU_RUN_TEST(test_sort_int);
    MU_RUN_TEST(test_sort_double);
    MU_RUN_TEST(test_sort_string);
}

void run_tests(void) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
}