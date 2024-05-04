#pragma once

#include "esphome/components/i2c/i2c.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/core/component.h"

namespace esphome {
namespace si1145 {

constexpr uint8_t SI115X_PARTID = 0x00;
constexpr uint8_t SI115X_RESPONSE_0 = 0x11;
constexpr uint8_t SI115X_RESPONSE_1 = 0x10;
constexpr uint8_t SI115X_COMMAND = 0x0B;
constexpr uint8_t SI115X_HOSTIN_0 = 0x0A;
constexpr uint8_t SI115X_HOSTOUT_0 = 0x13;
constexpr uint8_t SI115X_HOSTOUT_1 = 0x14;
constexpr uint8_t SI115X_HOSTOUT_2 = 0x15;
constexpr uint8_t SI115X_HOSTOUT_3 = 0x16;
constexpr uint8_t SI115X_ALS_FORCE = 0x11;
constexpr uint8_t SI115X_ALS_START = 0x13;

constexpr uint8_t CHAN_LIST = 0x01;
constexpr uint8_t ADCCONFIG_0 = 0x02;
constexpr uint8_t MEASCONFIG_0 = 0x05;
constexpr uint8_t ADCPOST_0 = 0x04;
constexpr uint8_t ADCCONFIG_1 = 0x06;
constexpr uint8_t MEASCONFIG_1 = 0x09;
constexpr uint8_t ADCPOST_1 = 0x08;

#define OVERFLOW_VALUE 0x7FFF

/// This class implements support for the SI115X i2c sensor.
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
  // Aux RW fns
  uint8_t read_byte(uint8_t reg);

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
