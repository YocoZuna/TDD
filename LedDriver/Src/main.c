#include "stdio.h"
#include "unity_fixture.h"
#include "unity.h"
#include "LedDriver.h"
#include "RunTimeErrorStub.h"


TEST_GROUP(LedDriver);

static uint16_t virtualLeds;
TEST_SETUP(LedDriver)
{
    LedDriver_Create(&virtualLeds);

}
TEST_TEAR_DOWN(LedDriver)
{}
TEST(LedDriver,Init)
{
    uint16_t virtualLeds = 0xffff;
    LedDriver_Create(&virtualLeds);
    TEST_ASSERT_EQUAL_HEX16(0,virtualLeds);
}
TEST(LedDriver,TurnOn)
{
    uint16_t ledToTurnOn = 1;
    LedDriver_TurnOn(ledToTurnOn);
    /* Adding mask to check if the right bit is set*/

    TEST_ASSERT_EQUAL_HEX16(ledToTurnOn,virtualLeds);
    
}
TEST(LedDriver,TurnOnOff)
{
    uint16_t ledToTurnOn = 1;
    
    
    LedDriver_TurnOn(ledToTurnOn);
    LedDriver_TurnOff(ledToTurnOn);
    /* Adding mask to check if the right bit is set*/

    TEST_ASSERT_EQUAL_HEX16(0,virtualLeds);
    
}
TEST(LedDriver,TestMultipleLeds)
{
    LedDriver_TurnOn(9);
    LedDriver_TurnOn(8);
    TEST_ASSERT_EQUAL_HEX16(0X180,virtualLeds);
}
TEST(LedDriver,UpperAndLowerBounds)
{
    LedDriver_TurnOn(1);
    LedDriver_TurnOn(16);
    TEST_ASSERT_EQUAL_HEX16(0x8001,virtualLeds);
}

TEST(LedDriver,OutOfBoundsChangesNothing)
{
    LedDriver_TurnOn(-1);
    LedDriver_TurnOn(0);
    LedDriver_TurnOn(3141);
    LedDriver_TurnOn(17);
    TEST_ASSERT_EQUAL_HEX16(0,virtualLeds);
}

TEST(LedDriver,OutOfBoundsProducesRunTimeError)
{
    LedDriver_TurnOn(-1);   
    
    TEST_ASSERT_EQUAL_STRING("LED Driver: out-of-bounds LED",RunTimeErrorStube_GetLastError());
    TEST_ASSERT_EQUAL(-1,RunTimeErrorStub_GetLastParameter());
}

TEST(LedDriver,TurnOnAll)
{
    LedDriver_TurnOnAll();
    TEST_ASSERT_EQUAL_HEX16(0xffff,virtualLeds);
}
TEST(LedDriver,TurnOffAll)
{
    LedDriver_TurnOnAll();
    LedDriver_TurnOffAll();
    TEST_ASSERT_EQUAL_HEX16(0x0,virtualLeds);
}
TEST(LedDriver,TurnOffMultipleLeds)
{
    LedDriver_TurnOnAll();
    LedDriver_TurnOff(8);
    LedDriver_TurnOff(9);
    TEST_ASSERT_EQUAL_HEX16((~0x180)&0xffff,virtualLeds);
}
TEST(LedDriver,TurnOnMultipleLeds)
{
    LedDriver_TurnOffAll();
    LedDriver_TurnOn(8);
    LedDriver_TurnOn(9);
    TEST_ASSERT_EQUAL_HEX16(0x180,virtualLeds);

}
TEST_GROUP_RUNNER(LedDriver)
{
    RUN_TEST_CASE(LedDriver,Init);
    RUN_TEST_CASE(LedDriver,TurnOn);
    RUN_TEST_CASE(LedDriver,TurnOnOff);
    RUN_TEST_CASE(LedDriver,TestMultipleLeds);
    RUN_TEST_CASE(LedDriver,UpperAndLowerBounds);
    RUN_TEST_CASE(LedDriver,OutOfBoundsChangesNothing);
    RUN_TEST_CASE(LedDriver,OutOfBoundsProducesRunTimeError);
    RUN_TEST_CASE(LedDriver,TurnOnAll);
    RUN_TEST_CASE(LedDriver,TurnOffAll);
    RUN_TEST_CASE(LedDriver,TurnOffMultipleLeds);
    RUN_TEST_CASE(LedDriver,TurnOnMultipleLeds);
}




int main(int argc, char** argv){
    UNITY_BEGIN();
    RUN_TEST_GROUP(LedDriver);
    UNITY_END();

}
