#ifndef WIRE_H
#define WIRE_H

#include <stdint.h>

struct WireMock {
  void (*begin)();
  void (*beginTransmission)(uint8_t addr);
  void (*write)(uint16_t data);
  void (*endTransmission)();
};

extern struct WireMock Wire;
#endif
