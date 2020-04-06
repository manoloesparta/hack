#include "unity.h"
#include "computer.h"

void test_basic(void);
void test_multibit(void);
void test_multiway(void);

void setUp(void){}
void tearDown(void){}

int main(void) 
{
    UNITY_BEGIN();

    RUN_TEST(test_basic);
    RUN_TEST(test_multibit);
    RUN_TEST(test_multiway);

    return UNITY_END();
}

void test_basic(void) 
{
    TEST_ASSERT_EQUAL_INT(XOR(1,1), 0);
    TEST_ASSERT_EQUAL_INT(XOR(1,0), 1);

    TEST_ASSERT_EQUAL_INT(MUX(1,0,0), 1);
    TEST_ASSERT_EQUAL_INT(MUX(1,0,1), 0);

    int desired1[] = {1, 0};
    TEST_ASSERT_EQUAL_INT_ARRAY(desired1, DMUX(1, 0), 2);
    int desired2[] = {0, 1};
    TEST_ASSERT_EQUAL_INT_ARRAY(desired2, DMUX(1, 1), 2);
}

void test_multibit(void)
{
}

void test_multiway(void)
{

}

