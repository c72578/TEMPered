#ifndef TEMPER_TYPE_HID_H
#define TEMPER_TYPE_HID_H

#include "../tempered.h"
#include "type-info.h"

/** Initialize the HID TEMPer types. */
bool temper_type_hid_init( char **error );

/** Finalize the HID TEMPer types. */
bool temper_type_hid_exit( char **error );

/** Enumerate the HID TEMPer devices. */
struct tempered_device_list* temper_type_hid_enumerate( char **error );

/** Method for opening HID devices. */
bool temper_type_hid_open( tempered_device* device );

/** Method for closing HID devices. */
void temper_type_hid_close( tempered_device* device );

/** Method for initializing subtype device data for HID devices. */
bool temper_type_hid_subtype_open( tempered_device* device );

/** Method for getting the subtype ID from HID devices. */
bool temper_type_hid_get_subtype_id(
	tempered_device* device, unsigned char* subtype_id
);

/** Method for getting the number of sensors that a HID device has. */
int temper_type_hid_get_sensor_count( tempered_device* device );

/** Method for reading the sensors on a HID device. */
bool temper_type_hid_read_sensors( tempered_device* device );

/** Method for reading data from the device for a given sensor group. */
bool temper_type_hid_read_sensor_group(
	tempered_device* device, struct tempered_type_hid_sensor_group* group,
	struct tempered_type_hid_query_result* group_data
);

/** Method for getting the temperature from HID devices. */
bool temper_type_hid_get_temperature(
	tempered_device* device, int sensor, float* tempC
);

/** Method for getting the relative humidity from HID devices. */
bool temper_type_hid_get_humidity(
	tempered_device* device, int sensor, float* rel_hum
);

#endif
