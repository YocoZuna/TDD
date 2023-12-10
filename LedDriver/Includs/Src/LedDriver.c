#include "LedDriver.h"
#include "RunTimeErrorStub.h"
#include <stdbool.h>
enum {FIRST_LED = 1,LAST_LED =16};
static uint16_t* ledsAddres;
static bool IsLEDOutOfBounds(int led)
{
    return (led<FIRST_LED) || (led> LAST_LED);
}

static uint16_t convertLEDToBit(uint16_t led)
{
    return (1<<led-1);
}

static void setLEDBit(int led)
{
    *ledsAddres |= convertLEDToBit(led);
}
static void setAllBitsToOne()
{
    *ledsAddres |= 0xFFFF;
}
static void setAllBitsToZero()
{
    *ledsAddres  = 0;
}
static void clearLEDBit(int led)
{
    *ledsAddres &=~convertLEDToBit(led);
}


void LedDriver_Create(uint16_t * const addres)
{
    ledsAddres = addres;
    *ledsAddres = 0;
}
void LedDriver_Destroy(void)
{

}

void LedDriver_TurnOn(const uint16_t led)
{
    if (IsLEDOutOfBounds(led))
    {
    RUNTIME_ERROR("LED Driver: out-of-bounds LED",-1);
        return;
    }
    setLEDBit(led);
}
void LedDriver_TurnOff(const uint16_t led)
{
    if (IsLEDOutOfBounds(led))
    {
    RUNTIME_ERROR("LED Driver: out-of-bounds LED",-1);
        return;
    }
    clearLEDBit(led);
}
void LedDriver_TurnOnAll(void)
{
    setAllBitsToOne();
}
void LedDriver_TurnOffAll(void)
{
    setAllBitsToZero();
}