#ifndef AD7147_H
#define AD7147_H

#include <stdint.h>
struct power_control_s {
  union{
    uint16_t pwr_control;
    struct {
      uint16_t cdc_bias      : 2; // 0==normal, 1==norm+20%, 2==norm+35%, 3==norm+50%
      uint16_t rsvd          : 1;
      uint16_t ext_source    : 1; // 0==enable excitation src to CINx pins
      uint16_t int_pol       : 1; // 0=active low, 1==active high
      uint16_t sw_reset      : 1; // 1==clear regs to default vals
      uint16_t decimation    : 2; // 0==256, 1==128, 2==64, 3==64
      uint16_t n_stages      : 4; // num stages == n_stages+1 (max val 11, which is 12 stages)
      uint16_t lp_conv_delay : 2; // 00=200ms, 1==400ms, 3==600ms, 4==800ms
      uint16_t power_mode    : 2; // 0==fullpwr, 1=full_shtdwn, 2==LPM (autowake), 3==1
    };
  };
};

struct stage_cal_en_s {
  union {
    uint16_t stage_cal_en;
  };
};

struct amb_comp_ctrl0_s {
  union {
    uint16_t amb_comp_ctrl0;
  };
};

struct amb_comp_ctrl1_s {
  union {
    uint16_t amb_comp_ctrl1;
  };
};

struct amb_comp_ctrl2_s {
  union {
    uint16_t amb_comp_ctrl2;
  };
};

struct stage_low_int_enable_s {
  union {
    uint16_t stage_low_int_enable;
  };
};

struct stage_high_int_enable_s {
  union {
    uint16_t stage_high_int_enable;
  };
};

struct stage_complete_int_enable_s {
  union {
    uint16_t stage_complete_int_enable;
  };
};

struct stage_low_int_status_s {
  union {
    uint16_t stage_low_int_status;
  };
};

struct stage_high_int_status_s {
  union {
    uint16_t stage_high_int_status;
  };
};

struct stage_complete_int_status_s {
  uint16_t stage_complete_int_status;
};

// ADDR 0x00B -> 0x016 (incl)
struct cdc_conv_data_s {
  uint16_t conv_data;
};

struct device_id_s {
  uint16_t device_id;
  union {
    uint16_t revision_code : 4;
    uint16_t devid         : 12; // 0001 0100 0111
  };
};

struct proximity_status_s {
  uint16_t prox_status;
  union {
    uint16_t stage0_prox_status  : 1;
    uint16_t stage1_prox_status  : 1;
    uint16_t stage2_prox_status  : 1;
    uint16_t stage3_prox_status  : 1;
    uint16_t stage4_prox_status  : 1;
    uint16_t stage5_prox_status  : 1;
    uint16_t stage6_prox_status  : 1;
    uint16_t stage7_prox_status  : 1;
    uint16_t stage8_prox_status  : 1;
    uint16_t stage9_prox_status  : 1;
    uint16_t stage10_prox_status : 1;
    uint16_t stage11_prox_status : 1;
  };
};

struct Bank1Config {
  struct power_control_s pwr_control; // ADDR 0
  struct stage_cal_en_s stage_cal_en; // ADDR 1
  struct amb_comp_ctrl0_s amb_comp_ctrl0; // ADDR 2
  struct amb_comp_ctrl1_s amb_comp_ctrl1; // ADDR 3
  struct amb_comp_ctrl2_s amb_comp_ctrl2; // ADDR 4
  struct stage_low_int_enable_s stage_low_int_enable; // ADDR 5
  struct stage_high_int_enable_s stage_high_int_enable; // ADDR 6
  struct stage_complete_int_enable_s stage_complete_int_enable; // ADDR 7
  struct stage_low_int_status_s stage_low_int_status; // ADDR 8
  struct stage_high_int_status_s stage_high_int_status; // ADDR 9
  struct stage_complete_int_status_s stage_complete_int_status; // ADDR A
  struct cdc_conv_data_s cdc_conv_data[12]; // ADDR 0xB -> 0x16 (incl)
  struct device_id_s device_id; // ADDR 0x17
  struct proximity_status_s proximity_status; // ADDR 0x42
};

struct Bank2Config {

};

// Config struct
struct AD7147Config {
  struct Bank2Config bank2Conf;
  struct Bank1Config bank1Conf;
};

int AD7147_Init(struct AD7147Config *cfg);

#endif
