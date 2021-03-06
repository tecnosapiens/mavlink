// MESSAGE GPS_STATUS PACKING

#define MAVLINK_MSG_ID_GPS_STATUS 27

typedef struct __mavlink_gps_status_t 
{
	uint64_t usec; ///< Timestamp (microseconds since unix epoch)
	uint8_t satellites_visible; ///< Number of satellites visible
	int8_t satellite_prn[20]; ///< Global satellite ID
	int8_t satellite_used[20]; ///< 0: Satellite not used, 1: used for localization
	int8_t satellite_elevation[20]; ///< Elevation (0: right on top of receiver, 90: on the horizon) of satellite
	int8_t satellite_azimuth[20]; ///< Direction of satellite, 0: 0 deg, 255: 360 deg.
	int8_t satellite_snr[20]; ///< Signal to noise ratio of satellite

} mavlink_gps_status_t;

#define MAVLINK_MSG_GPS_STATUS_FIELD_SATELLITE_PRN_LEN 20#define MAVLINK_MSG_GPS_STATUS_FIELD_SATELLITE_USED_LEN 20#define MAVLINK_MSG_GPS_STATUS_FIELD_SATELLITE_ELEVATION_LEN 20#define MAVLINK_MSG_GPS_STATUS_FIELD_SATELLITE_AZIMUTH_LEN 20#define MAVLINK_MSG_GPS_STATUS_FIELD_SATELLITE_SNR_LEN 20

/**
 * @brief Send a gps_status message
 *
 * @param usec Timestamp (microseconds since unix epoch)
 * @param satellites_visible Number of satellites visible
 * @param satellite_prn Global satellite ID
 * @param satellite_used 0: Satellite not used, 1: used for localization
 * @param satellite_elevation Elevation (0: right on top of receiver, 90: on the horizon) of satellite
 * @param satellite_azimuth Direction of satellite, 0: 0 deg, 255: 360 deg.
 * @param satellite_snr Signal to noise ratio of satellite
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint64_t usec, uint8_t satellites_visible, const int8_t* satellite_prn, const int8_t* satellite_used, const int8_t* satellite_elevation, const int8_t* satellite_azimuth, const int8_t* satellite_snr)
{
	msg->msgid = MAVLINK_MSG_ID_GPS_STATUS;
	uint16_t i = 0;

	i += put_uint64_t_by_index(usec, i, msg->payload); //Timestamp (microseconds since unix epoch)
	i += put_uint8_t_by_index(satellites_visible, i, msg->payload); //Number of satellites visible
	i += put_array_by_index(satellite_prn, 20, i, msg->payload); //Global satellite ID
	i += put_array_by_index(satellite_used, 20, i, msg->payload); //0: Satellite not used, 1: used for localization
	i += put_array_by_index(satellite_elevation, 20, i, msg->payload); //Elevation (0: right on top of receiver, 90: on the horizon) of satellite
	i += put_array_by_index(satellite_azimuth, 20, i, msg->payload); //Direction of satellite, 0: 0 deg, 255: 360 deg.
	i += put_array_by_index(satellite_snr, 20, i, msg->payload); //Signal to noise ratio of satellite

	return mavlink_finalize_message(msg, system_id, component_id, i);
}

static inline uint16_t mavlink_msg_gps_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gps_status_t* gps_status)
{
	return mavlink_msg_gps_status_pack(system_id, component_id, msg, gps_status->usec, gps_status->satellites_visible, gps_status->satellite_prn, gps_status->satellite_used, gps_status->satellite_elevation, gps_status->satellite_azimuth, gps_status->satellite_snr);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_gps_status_send(mavlink_channel_t chan, uint64_t usec, uint8_t satellites_visible, const int8_t* satellite_prn, const int8_t* satellite_used, const int8_t* satellite_elevation, const int8_t* satellite_azimuth, const int8_t* satellite_snr)
{
	mavlink_message_t msg;
	mavlink_msg_gps_status_pack(mavlink_system.sysid, mavlink_system.compid, &msg, usec, satellites_visible, satellite_prn, satellite_used, satellite_elevation, satellite_azimuth, satellite_snr);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE GPS_STATUS UNPACKING

/**
 * @brief Get field usec from gps_status message
 *
 * @return Timestamp (microseconds since unix epoch)
 */
static inline uint64_t mavlink_msg_gps_status_get_usec(const mavlink_message_t* msg)
{
	generic_64bit r;
	r.b[7] = (msg->payload)[0];
	r.b[6] = (msg->payload)[1];
	r.b[5] = (msg->payload)[2];
	r.b[4] = (msg->payload)[3];
	r.b[3] = (msg->payload)[4];
	r.b[2] = (msg->payload)[5];
	r.b[1] = (msg->payload)[6];
	r.b[0] = (msg->payload)[7];
	return (uint64_t)r.ll;
}

/**
 * @brief Get field satellites_visible from gps_status message
 *
 * @return Number of satellites visible
 */
static inline uint8_t mavlink_msg_gps_status_get_satellites_visible(const mavlink_message_t* msg)
{
	return (uint8_t)(msg->payload+sizeof(uint64_t))[0];
}

/**
 * @brief Get field satellite_prn from gps_status message
 *
 * @return Global satellite ID
 */
static inline uint16_t mavlink_msg_gps_status_get_satellite_prn(const mavlink_message_t* msg, int8_t* r_data)
{

	memcpy(r_data, msg->payload+sizeof(uint64_t)+sizeof(uint8_t), 20);
	return 20;
}

/**
 * @brief Get field satellite_used from gps_status message
 *
 * @return 0: Satellite not used, 1: used for localization
 */
static inline uint16_t mavlink_msg_gps_status_get_satellite_used(const mavlink_message_t* msg, int8_t* r_data)
{

	memcpy(r_data, msg->payload+sizeof(uint64_t)+sizeof(uint8_t)+20, 20);
	return 20;
}

/**
 * @brief Get field satellite_elevation from gps_status message
 *
 * @return Elevation (0: right on top of receiver, 90: on the horizon) of satellite
 */
static inline uint16_t mavlink_msg_gps_status_get_satellite_elevation(const mavlink_message_t* msg, int8_t* r_data)
{

	memcpy(r_data, msg->payload+sizeof(uint64_t)+sizeof(uint8_t)+20+20, 20);
	return 20;
}

/**
 * @brief Get field satellite_azimuth from gps_status message
 *
 * @return Direction of satellite, 0: 0 deg, 255: 360 deg.
 */
static inline uint16_t mavlink_msg_gps_status_get_satellite_azimuth(const mavlink_message_t* msg, int8_t* r_data)
{

	memcpy(r_data, msg->payload+sizeof(uint64_t)+sizeof(uint8_t)+20+20+20, 20);
	return 20;
}

/**
 * @brief Get field satellite_snr from gps_status message
 *
 * @return Signal to noise ratio of satellite
 */
static inline uint16_t mavlink_msg_gps_status_get_satellite_snr(const mavlink_message_t* msg, int8_t* r_data)
{

	memcpy(r_data, msg->payload+sizeof(uint64_t)+sizeof(uint8_t)+20+20+20+20, 20);
	return 20;
}

static inline void mavlink_msg_gps_status_decode(const mavlink_message_t* msg, mavlink_gps_status_t* gps_status)
{
	gps_status->usec = mavlink_msg_gps_status_get_usec(msg);
	gps_status->satellites_visible = mavlink_msg_gps_status_get_satellites_visible(msg);
	mavlink_msg_gps_status_get_satellite_prn(msg, gps_status->satellite_prn);
	mavlink_msg_gps_status_get_satellite_used(msg, gps_status->satellite_used);
	mavlink_msg_gps_status_get_satellite_elevation(msg, gps_status->satellite_elevation);
	mavlink_msg_gps_status_get_satellite_azimuth(msg, gps_status->satellite_azimuth);
	mavlink_msg_gps_status_get_satellite_snr(msg, gps_status->satellite_snr);
}
