#include "AD7147.h"

int main(int argc, char* argv[])
{
  struct AD7147Config cfg;
  struct Bank1Config *data = &(cfg.bank1Conf);
  data->pwr_control.power_mode = 0x2;
  AD7147_Init(&cfg);
  return 0;
}
