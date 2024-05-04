#include "si1145.h"

#include <cmath>

#include "esphome/core/log.h"
#include <Arduino.h>

namespace esphome {
namespace si1145 {

static const char *const TAG = "SI115X.sensor";

void SI1145Component::setup() {
  ESP_LOGCONFIG(TAG, "Setting up SI115X...");

  uint8_t id = read_byte(SI115X_PARTID);
  if (id != 0x51) {
    mark_failed();
    return;
  }

  // Enable 2 channels for proximity measurement
  param_set(CHAN_LIST, 0B000011);
  param_set(ADCCONFIG_0, 0B01100000);
  param_set(MEASCONFIG_0, 0x00);
  param_set(ADCPOST_0, 0x00);
  param_set(ADCCONFIG_1, 0B01101101);
  param_set(MEASCONFIG_1, 0x00);
  param_set(ADCPOST_1, 0x00);

  send_command(SI115X_ALS_START);
}

void SI1145Component::dump_config() {
  ESP_LOGCONFIG(TAG, "SI115X:");
  LOG_I2C_DEVICE(this);
  if (this->is_failed()) {
    ESP_LOGE(TAG, "Communication with SI115X failed!");
  }
}

float SI1145Component::get_setup_priority() const { return setup_priority::DATA; }

void SI1145Component::update() {
  send_command(SI115X_ALS_FORCE);

  int visible = (read_byte(SI115X_HOSTOUT_0) << 8) + read_byte(SI115X_HOSTOUT_1);
  int infrared = (read_byte(SI115X_HOSTOUT_2) << 8) + read_byte(SI115X_HOSTOUT_3);

  if (this->visible_sensor_ != nullptr) {
    this->visible_sensor_->publish_state(visible);
  }

  if (this->infrared_sensor_ != nullptr) {
    this->infrared_sensor_->publish_state(infrared);
  }

//  if (this->illuminance_sensor_ != nullptr) {
//    float lux = illumination_combine_sensors(vis, visible_range_, visible_gain_, ir, infrared_range_, infrared_gain_);
//    this->illuminance_sensor_->publish_state(lux);
//  }
}

uint8_t SI1145Component::read_byte(uint8_t reg) {
  uint8_t d8 = 0;
  read_byte(reg, &d8);
  return d8;
}

void SI1145Component::param_set(uint8_t loc, uint8_t val){
  uint8_t cmd_ctr = read_byte(SI115X_RESPONSE_0);
  write_byte(SI115X_HOSTIN_0, val);
  write_byte(SI115X_COMMAND, loc | (0B10 << 6));    
  while (read_byte(SI115X_RESPONSE_0) != cmd_ctr + 1) {}
}

void SI1145Component::send_command(uint8_t code){
  uint8_t cmd_ctr = read_byte(SI115X_RESPONSE_0);
  write_byte(SI115X_COMMAND, code);    
  while (read_byte(SI115X_RESPONSE_0) != cmd_ctr + 1) {}
}

}  // namespace si1145
}  // namespace esphome

