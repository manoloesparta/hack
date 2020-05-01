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
    int desirednot[] = {1,1,0,0,1,0,1,0,0,0,1,1,1,0,1,0};
    int innot[] = {0,0,1,1,0,1,0,1,1,1,0,0,0,1,0,1};
    TEST_ASSERT_EQUAL_INT_ARRAY(desirednot, Multi16BitNOT(innot), 16);

    int inaor[] = {1,1,0,0,1,0,1,0,0,0,1,1,1,0,1,0};
    int inbor[] = {0,1,0,1,1,0,1,1,1,0,0,0,1,0,0,1};
    int resor[] = {1,1,0,1,1,0,1,1,1,0,1,1,1,0,1,1};
    TEST_ASSERT_EQUAL_INT_ARRAY(resor, Multi16BitOR(inaor, inbor), 16);

    int resand[]= {0,1,0,0,1,0,1,0,0,0,0,0,1,0,0,0};
    TEST_ASSERT_EQUAL_INT_ARRAY(resand, Multi16BitAND(inaor, inbor), 16);

    TEST_ASSERT_EQUAL_INT_ARRAY(inaor, Multi16BitMUX(inaor, inbor, 0), 16);
    TEST_ASSERT_EQUAL_INT_ARRAY(inbor, Multi16BitMUX(inaor, inbor, 1), 16);
}

void test_multiway(void)
{
    int input0[] = {0,0,0,0,0,0,0,0};
    int input1[] = {0,0,1,0,0,1,1,0};
    int input2[] = {0,0,0,0,0,1,0,0};
    int input3[] = {0,0,0,0,1,0,0,0};
    int input4[] = {0,0,0,1,0,0,0,0};
    int input5[] = {0,0,1,0,0,0,0,0};
    int input6[] = {0,1,0,0,0,0,0,0};
    int input7[] = {1,0,0,0,0,0,0,0};

    TEST_ASSERT_EQUAL_INT(0, Multi8WayOR(input0));
    TEST_ASSERT_EQUAL_INT(1, Multi8WayOR(input1));

    int sel1[] = {1,1};
    TEST_ASSERT_EQUAL_INT_ARRAY(input3, Multi4WayMUX(input0, input1, input2, input3, sel1), 8);
    int sel2[] = {0,0};
    TEST_ASSERT_EQUAL_INT_ARRAY(input0, Multi4WayMUX(input0, input1, input2, input3, sel2), 8);

    int sel5[] = {0,0,0};
    TEST_ASSERT_EQUAL_INT_ARRAY(input0, Multi8WayMUX(input0, input1, input2, input3, input4, input5, input6, input7, sel5), 8);
    int sel6[] = {0,1,1};
    TEST_ASSERT_EQUAL_INT_ARRAY(input3, Multi8WayMUX(input0, input1, input2, input3, input4, input5, input6, input7, sel6), 8);

    int sel01[] = {0,0};
    int res1[] = {1,0,0,0};
    TEST_ASSERT_EQUAL_INT_ARRAY(res1, Multi4WayDMUX(1, sel01), 4);
    int sel02[] = {1,0};
    int res2[] = {0,0,1,0};
    TEST_ASSERT_EQUAL_INT_ARRAY(res2, Multi4WayDMUX(1, sel02), 4);

    int sel03[] = {0,0,0};
    int res3[] = {1,0,0,0,0,0,0,0};
    TEST_ASSERT_EQUAL_INT_ARRAY(res3, Multi8WayDMUX(1, sel03), 8);
    int sel04[] = {0,1,1};
    int res4[] = {0,0,0,1,0,0,0,0};
    TEST_ASSERT_EQUAL_INT_ARRAY(res4, Multi8WayDMUX(1, sel04), 8);
}