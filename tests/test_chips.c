#include "unity.h"
#include "computer.h"

void test_HalfAdder();
void test_FullAdder();
void test_Add16();
void test_Inc16();
void test_ALU();

void setUp(void){}
void tearDown(void){}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_HalfAdder);
    RUN_TEST(test_FullAdder);
    RUN_TEST(test_Add16);
    RUN_TEST(test_Inc16);
    RUN_TEST(test_ALU);

    return UNITY_END();
}

void test_HalfAdder()
{   
    int res0[] = {0,1};
    TEST_ASSERT_EQUAL_INT_ARRAY(res0, HalfAdder(1,1), 2);
    int res1[] = {1,0};
    TEST_ASSERT_EQUAL_INT_ARRAY(res1, HalfAdder(0,1), 2);
    TEST_ASSERT_EQUAL_INT_ARRAY(res1, HalfAdder(1,0), 2);
}

void test_FullAdder()
{
    int res0[] = {1,1};
    TEST_ASSERT_EQUAL_INT_ARRAY(res0, FullAdder(1,1,1), 2);
    int res1[] = {1,0};
    TEST_ASSERT_EQUAL_INT_ARRAY(res1, FullAdder(0,0,1), 2);
    int res2[] = {0,1};
    TEST_ASSERT_EQUAL_INT_ARRAY(res2, FullAdder(0,1,1), 2);
}

void test_Add16()
{
    int a[] = {1,0,1,0,1,0,0,0,1,0,1,0,1,1,0,0};
    int b[] = {1,0,0,1,0,1,1,1,1,0,1,1,0,1,1,0};
    int d[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int c[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    int res0[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    TEST_ASSERT_EQUAL_INT_ARRAY(res0, Add16(c,c), 16);
    int res1[] = {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    TEST_ASSERT_EQUAL_INT_ARRAY(res1, Add16(d,d), 16);
    int res2[] = {0,1,1,1,1,1,1,1,0,1,0,0,0,1,0,1};
    TEST_ASSERT_EQUAL_INT_ARRAY(res2, Add16(a, b), 16);
    TEST_ASSERT_EQUAL_INT_ARRAY(res2, Add16(b, a), 16);
    TEST_ASSERT_EQUAL_INT_ARRAY(a, Add16(c,a), 16);
    TEST_ASSERT_EQUAL_INT_ARRAY(b, Add16(b,c), 16);
}

void test_Inc16()
{
    int a[] = {1,0,1,0,1,0,0,0,1,0,1,0,1,1,0,0};
    int b[] = {1,0,0,1,0,1,1,1,1,0,1,1,0,1,1,0};
    int d[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

    int res0[] = {0,1,1,0,1,0,0,0,1,0,1,0,1,1,0,0};
    TEST_ASSERT_EQUAL_INT_ARRAY(res0, Inc16(a), 16);
    int res1[] = {0,1,0,1,0,1,1,1,1,0,1,1,0,1,1,0};
    TEST_ASSERT_EQUAL_INT_ARRAY(res1, Inc16(b), 16);
    int res2[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    TEST_ASSERT_EQUAL_INT_ARRAY(res2, Inc16(d), 16);
}

void test_ALU()
{
    int a[] = {1,0,1,0,1,0,0,0,1,0,1,0,1,1,0,0};
    int b[] = {1,0,0,1,0,1,1,1,1,0,1,1,0,1,1,0};
}