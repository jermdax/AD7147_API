#include "Wire.h"
#include <stdint.h>

static void mockBegin()
{

}

static void mockBeginTransmission(uint8_t addr)
{

}

static void mockWrite(uint16_t data)
{

}

static void mockEndTransmission()
{

}

struct WireMock Wire = {
  .begin = mockBegin,
  .beginTransmission = mockBeginTransmission,
  .write = mockWrite,
  .endTransmission = mockEndTransmission
};
