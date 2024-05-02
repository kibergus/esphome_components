import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import i2c, sensor
from esphome.const import (
    CONF_ID,
    CONF_RANGE,
    CONF_GAIN,
    CONF_MODE,
    DEVICE_CLASS_ILLUMINANCE,
    STATE_CLASS_MEASUREMENT,
    UNIT_EMPTY,
    UNIT_LUX,
    ICON_BRIGHTNESS_5,
    CONF_CALCULATED_LUX,
    CONF_INFRARED,
    CONF_VISIBLE,
)

DEPENDENCIES = ["i2c"]

si1145_ns = cg.esphome_ns.namespace("si1145")

SI1145Component = si1145_ns.class_(
    "SI1145Component", cg.PollingComponent, i2c.I2CDevice
)

CONFIG_SCHEMA = (
    cv.Schema(
        {
            cv.GenerateID(): cv.declare_id(SI1145Component),
            cv.Optional(CONF_VISIBLE): sensor.sensor_schema(
                unit_of_measurement=UNIT_EMPTY,
                accuracy_decimals=0,
                device_class=DEVICE_CLASS_ILLUMINANCE,
                state_class=STATE_CLASS_MEASUREMENT,
                icon=ICON_BRIGHTNESS_5,
            ),
            cv.Optional(CONF_INFRARED): sensor.sensor_schema(
                unit_of_measurement=UNIT_EMPTY,
                accuracy_decimals=0,
                device_class=DEVICE_CLASS_ILLUMINANCE,
                state_class=STATE_CLASS_MEASUREMENT,
                icon=ICON_BRIGHTNESS_5,
            ),
            cv.Optional(CONF_CALCULATED_LUX): sensor.sensor_schema(
                unit_of_measurement=UNIT_LUX,
                accuracy_decimals=0,
                device_class=DEVICE_CLASS_ILLUMINANCE,
                state_class=STATE_CLASS_MEASUREMENT,
                icon=ICON_BRIGHTNESS_5,
            ),
        }
    )
    .extend(cv.polling_component_schema("60s"))
    .extend(i2c.i2c_device_schema(0x60))
)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await i2c.register_i2c_device(var, config)

    if CONF_VISIBLE in config:
        conf = config[CONF_VISIBLE]
        sens = await sensor.new_sensor(conf)
        cg.add(var.set_visible_sensor(sens))

    if CONF_INFRARED in config:
        conf = config[CONF_INFRARED]
        sens = await sensor.new_sensor(conf)
        cg.add(var.set_infrared_sensor(sens))

    if CONF_CALCULATED_LUX in config:
        conf = config[CONF_CALCULATED_LUX]
        sens = await sensor.new_sensor(conf)
        cg.add(var.set_illuminance_sensor(sens))
