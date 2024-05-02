#pragma once

#include "esphome/components/i2c/i2c.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/core/component.h"

namespace esphome {
namespace si1145 {

static const uint8_t SI1145_PARAM_QUERY = 0x80;
static const uint8_t SI1145_PARAM_SET = 0xA0;
static const uint8_t SI1145_NOP = 0x0;
static const uint8_t SI1145_RESET = 0x01;
static const uint8_t SI1145_BUSADDR = 0x02;
static const uint8_t SI1145_PS_FORCE = 0x05;
static const uint8_t SI1145_ALS_FORCE = 0x06;
static const uint8_t SI1145_PSALS_AUTO = 0x0F;
static const uint8_t SI1145_PS_PAUSE = 0x09;
static const uint8_t SI1145_GET_CAL = 0x12;
static const uint8_t SI1145_PARAM_I2CADDR = 0x00;
static const uint8_t SI1145_PARAM_CHLIST = 0x01;
static const uint8_t SI1145_PARAM_CHLIST_ENUV = 0x80;
static const uint8_t SI1145_PARAM_CHLIST_ENAUX = 0x40;
static const uint8_t SI1145_PARAM_CHLIST_ENALSIR = 0x20;
static const uint8_t SI1145_PARAM_CHLIST_ENALSVIS = 0x10;
static const uint8_t SI1145_PARAM_CHLIST_ENPS1 = 0x01;
static const uint8_t SI1145_PARAM_CHLIST_ENPS2 = 0x02;
static const uint8_t SI1145_PARAM_CHLIST_ENPS3 = 0x04;
static const uint8_t SI1145_PARAM_PSLED12SEL = 0x02;
static const uint8_t SI1145_PARAM_PSLED12SEL_PS2NONE = 0x00;
static const uint8_t SI1145_PARAM_PSLED12SEL_PS2LED1 = 0x10;
static const uint8_t SI1145_PARAM_PSLED12SEL_PS2LED2 = 0x20;
static const uint8_t SI1145_PARAM_PSLED12SEL_PS2LED3 = 0x40;
static const uint8_t SI1145_PARAM_PSLED12SEL_PS1NONE = 0x00;
static const uint8_t SI1145_PARAM_PSLED12SEL_PS1LED1 = 0x01;
static const uint8_t SI1145_PARAM_PSLED12SEL_PS1LED2 = 0x02;
static const uint8_t SI1145_PARAM_PSLED12SEL_PS1LED3 = 0x04;
static const uint8_t SI1145_REG_PSLED21 = 0x0F;
static const uint8_t SI1145_PARAM_PSENCODE = 0x05;
static const uint8_t SI1145_PARAM_ALSENCODE = 0x06;
static const uint8_t SI1145_PARAM_PS1ADCMUX = 0x07;
static const uint8_t SI1145_PARAM_PS2ADCMUX = 0x08;
static const uint8_t SI1145_PARAM_PS3ADCMUX = 0x09;
static const uint8_t SI1145_PARAM_PSADCMISC_RANGE = 0x20;
static const uint8_t SI1145_PARAM_PSADCMISC_PSMODE = 0x04;
static const uint8_t SI1145_PARAM_ALSVISADCOUNTER = 0x10;
static const uint8_t SI1145_PARAM_ALSVISADCGAIN = 0x11;
static const uint8_t SI1145_PARAM_ALSVISADCMISC = 0x12;
static const uint8_t SI1145_PARAM_ALSVISADCMISC_VISRANGE_HIGH = 0x20;
static const uint8_t SI1145_PARAM_ALSVISADCMISC_VISRANGE_LOW = 0x00;
static const uint8_t SI1145_PARAM_ALSIRADCMISC_RANGE_HIGH = 0x20;
static const uint8_t SI1145_PARAM_ALSIRADCMISC_RANGE_LOW = 0x00;
static const uint8_t SI1145_PARAM_ADCCOUNTER_511CLK = 0x70;
static const uint8_t SI1145_PARAM_ADCMUX_SMALLIR = 0x00;
static const uint8_t SI1145_PARAM_ADCMUX_LARGEIR = 0x03;
static const uint8_t SI1145_REG_PARTID = 0x00;
static const uint8_t SI1145_REG_REVID = 0x01;
static const uint8_t SI1145_REG_SEQID = 0x02;
static const uint8_t SI1145_REG_INTCFG = 0x03;
static const uint8_t SI1145_REG_INTCFG_INTOE = 0x01;
static const uint8_t SI1145_REG_INTCFG_INTMODE = 0x02;
static const uint8_t SI1145_REG_IRQEN = 0x04;
static const uint8_t SI1145_REG_IRQEN_ALSEVERYSAMPLE = 0x01;
static const uint8_t SI1145_REG_IRQEN_PS1EVERYSAMPLE = 0x04;
static const uint8_t SI1145_REG_IRQEN_PS2EVERYSAMPLE = 0x08;
static const uint8_t SI1145_REG_IRQEN_PS3EVERYSAMPLE = 0x10;
static const uint8_t SI1145_REG_IRQMODE1 = 0x05;
static const uint8_t SI1145_REG_IRQMODE2 = 0x06;
static const uint8_t SI1145_REG_HWKEY = 0x07;
static const uint8_t SI1145_REG_MEASRATE0 = 0x08;
static const uint8_t SI1145_REG_MEASRATE1 = 0x09;
static const uint8_t SI1145_REG_PSLED3 = 0x10;
static const uint8_t SI1145_REG_UCOEFF0 = 0x13;
static const uint8_t SI1145_REG_UCOEFF1 = 0x14;
static const uint8_t SI1145_REG_UCOEFF2 = 0x15;
static const uint8_t SI1145_REG_UCOEFF3 = 0x16;
static const uint8_t SI1145_REG_PARAMWR = 0x17;
static const uint8_t SI1145_REG_COMMAND = 0x18;
static const uint8_t SI1145_REG_RESPONSE = 0x20;
static const uint8_t SI1145_REG_IRQSTAT = 0x21;
static const uint8_t SI1145_REG_IRQSTAT_ALS = 0x01;
static const uint8_t SI1145_REG_ALSVISDATA0 = 0x22;
static const uint8_t SI1145_REG_ALSVISDATA1 = 0x23;
static const uint8_t SI1145_REG_ALSIRDATA0 = 0x24;
static const uint8_t SI1145_REG_ALSIRDATA1 = 0x25;
static const uint8_t SI1145_REG_PS1DATA0 = 0x26;
static const uint8_t SI1145_REG_PS1DATA1 = 0x27;
static const uint8_t SI1145_REG_PS2DATA0 = 0x28;
static const uint8_t SI1145_REG_PS2DATA1 = 0x29;
static const uint8_t SI1145_REG_PARAMRD = 0x2E;
static const uint8_t SI1145_REG_CHIPSTAT = 0x30;
static const uint16_t VALUE_AT_ZERO_HIGH = 260;
static const uint16_t VALUE_AT_ZERO_LOW = 270;

static const uint8_t SI115X_RESPONSE_0 = 0x11;
static const uint8_t SI115X_RESPONSE_1 = 0x10;
static const uint8_t SI115X_COMMAND = 0x0B;
static const uint8_t SI115X_HOSTIN_0 = 0x0A;
static const uint8_t HOSTOUT_0 = 0x13;
static const uint8_t HOSTOUT_1 = 0x14;
static const uint8_t HOSTOUT_2 = 0x15;
static const uint8_t HOSTOUT_3 = 0x16;
static const uint8_t SI115X_ALS_FORCE = 0x11;
static const uint8_t SI115X_ALS_START = 0x13;

static const uint8_t CHAN_LIST = 0x01;
static const uint8_t ADCCONFIG_0 = 0x02;
static const uint8_t MEASCONFIG_0 = 0x05;
static const uint8_t ADCPOST_0 = 0x04;
static const uint8_t ADCCONFIG_1 = 0x06;
static const uint8_t MEASCONFIG_1 = 0x09;
static const uint8_t ADCPOST_1 = 0x08;

#define SI1145_REG_UVINDEX0 0x2C
#define SI1145_REG_UVINDEX1 0x2D
#define SI1145_PARAM_PSADCGAIN 0x0B
#define SI1145_PARAM_PSADCOUNTER 0x0A
#define SI1145_PARAM_PSADCMISC 0x0C
#define SI1145_PARAM_ALSIRADCMUX 0x0E
#define SI1145_PARAM_ALSIRADCOUNTER 0x1D
#define SI1145_PARAM_ALSIRADCGAIN 0x1E
#define SI1145_PARAM_ALSIRADCMISC 0x1F

#define OVERFLOW_VALUE 0x7FFF

/// This class implements support for the SI1145 i2c sensor.
class SI1145Component : public PollingComponent, public i2c::I2CDevice {
 public:
  void set_visible_sensor(sensor::Sensor *visible_sensor) { visible_sensor_ = visible_sensor; }
  void set_infrared_sensor(sensor::Sensor *infrared_sensor) { infrared_sensor_ = infrared_sensor; }
  void set_illuminance_sensor(sensor::Sensor *illuminance_sensor) { illuminance_sensor_ = illuminance_sensor; }

  // ========== INTERNAL METHODS ==========
  // (In most use cases you won't need these)
  void setup() override;
  void dump_config() override;
  float get_setup_priority() const override;
  void update() override;

 protected:
  // Begin
  bool begin_();

  // Aux RW fns
  void write8_(uint8_t reg, uint8_t val);
  uint8_t read8_(uint8_t reg);

  void param_set(uint8_t loc, uint8_t val);
  void send_command(uint8_t code);

  // Sensors
  sensor::Sensor *visible_sensor_;
  sensor::Sensor *infrared_sensor_;
  sensor::Sensor *uvindex_sensor_;
  sensor::Sensor *illuminance_sensor_;
};

}  // namespace si1145
}  // namespace esphome
