#include "stdint.h"
void LedDriver_Create(uint16_t * const addres);
void LedDriver_Destroy(void);
void LedDriver_TurnOn( const uint16_t led);
void LedDriver_TurnOff(const uint16_t led);
void LedDriver_TurnOnAll(void);
void LedDriver_TurnOffAll(void);