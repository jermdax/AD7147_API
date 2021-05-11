#include "AD7147.h"

// Init function to intialize the HW with the Config struct, and an I2C object
// ISR for data-ready
// callback to call when data is received
const uint8_t i2cID;

#include "Wire.h"

int writeData(uint8_t addr, uint16_t data)
{
  Wire.beginTransmission(i2cID);
  Wire.write(addr);
  Wire.write(data);
  Wire.endTransmission();
}

int AD7147_Init(struct AD7147Config *cfg)
{
  Wire.begin();
  // Write Bank 2 regs 0x080 -> 0x0DF
  writeData(0x80, 0xFFFE); // CIN0 connected to pos input
  writeData(0x81, 0x1FFF); // TODO is this the correct SE_CONNECTION_SETUP val?
  // Write Bank 1 regs 0x000 -> 0x007
  writeData(0x00, 0x82b2); // literal vals are from the datasheet
  writeData(0x01, 0);
  writeData(0x02, cfg->bank1Conf.amb_comp_ctrl0.amb_comp_ctrl0);
  writeData(0x03, 0x419);
  writeData(0x04, 832);
  writeData(0x05, cfg->bank1Conf.stage_low_int_enable.stage_low_int_enable);
  writeData(0x06, cfg->bank1Conf.stage_high_int_enable.stage_high_int_enable);
  writeData(0x07, cfg->bank1Conf.stage_complete_int_enable.stage_complete_int_enable);

  return 0;
}
