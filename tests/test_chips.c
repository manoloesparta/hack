#include "unity.h"
#include "computer.h"

void test_HalfAdder();
void test_FullAdder();
void test_Incrementer16();
void test_Full16Adder();
void test_ALU();

void setUp(void){}
void tearDown(void){}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_HalfAdder);
    RUN_TEST(test_FullAdder);
    // RUN_TEST(test_Incrementer16);
    // RUN_TEST(test_Full16Adder);
    // RUN_TEST(test_ALU);

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