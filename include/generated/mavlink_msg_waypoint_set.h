// MESSAGE WAYPOINT_SET PACKING

#define MAVLINK_MSG_ID_WAYPOINT_SET 40

typedef struct __mavlink_waypoint_set_t 
{
	uint8_t target_system; ///< System ID
	uint8_t target_component; ///< Component ID
	uint16_t seq; ///< Sequence
	uint8_t type; ///< 0: global (GPS), 1: local, 2: global orbit, 3: local orbit
	uint8_t orbit; ///< Orbit to circle around the waypoint, in meters
	uint8_t current; ///< false:0, true:1
	float x; ///< local: x position, global: latitude
	float y; ///< y position: global: longitude
	float z; ///< z position: global: altitude
	float yaw; ///< yaw orientation in radians, 0 = NORTH
	uint16_t autocontinue; ///< autocontinue to next wp

} mavlink_waypoint_set_t;



/**
 * @brief Send a waypoint_set message
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param seq Sequence
 * @param type 0: global (GPS), 1: local, 2: global orbit, 3: local orbit
 * @param orbit Orbit to circle around the waypoint, in meters
 * @param current false:0, true:1
 * @param x local: x position, global: latitude
 * @param y y position: global: longitude
 * @param z z position: global: altitude
 * @param yaw yaw orientation in radians, 0 = NORTH
 * @param autocontinue autocontinue to next wp
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_waypoint_set_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint8_t target_system, uint8_t target_component, uint16_t seq, uint8_t type, uint8_t orbit, uint8_t current, float x, float y, float z, float yaw, uint16_t autocontinue)
{
	msg->msgid = MAVLINK_MSG_ID_WAYPOINT_SET;
	uint16_t i = 0;

	i += put_uint8_t_by_index(target_system, i, msg->payload); //System ID
	i += put_uint8_t_by_index(target_component, i, msg->payload); //Component ID
	i += put_uint16_t_by_index(seq, i, msg->payload); //Sequence
	i += put_uint8_t_by_index(type, i, msg->payload); //0: global (GPS), 1: local, 2: global orbit, 3: local orbit
	i += put_uint8_t_by_index(orbit, i, msg->payload); //Orbit to circle around the waypoint, in meters
	i += put_uint8_t_by_index(current, i, msg->payload); //false:0, true:1
	i += put_float_by_index(x, i, msg->payload); //local: x position, global: latitude
	i += put_float_by_index(y, i, msg->payload); //y position: global: longitude
	i += put_float_by_index(z, i, msg->payload); //z position: global: altitude
	i += put_float_by_index(yaw, i, msg->payload); //yaw orientation in radians, 0 = NORTH
	i += put_uint16_t_by_index(autocontinue, i, msg->payload); //autocontinue to next wp

	return mavlink_finalize_message(msg, system_id, component_id, i);
}

static inline uint16_t mavlink_msg_waypoint_set_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_waypoint_set_t* waypoint_set)
{
	return mavlink_msg_waypoint_set_pack(system_id, component_id, msg, waypoint_set->target_system, waypoint_set->target_component, waypoint_set->seq, waypoint_set->type, waypoint_set->orbit, waypoint_set->current, waypoint_set->x, waypoint_set->y, waypoint_set->z, waypoint_set->yaw, waypoint_set->autocontinue);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_waypoint_set_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint16_t seq, uint8_t type, uint8_t orbit, uint8_t current, float x, float y, float z, float yaw, uint16_t autocontinue)
{
	mavlink_message_t msg;
	mavlink_msg_waypoint_set_pack(mavlink_system.sysid, mavlink_system.compid, &msg, target_system, target_component, seq, type, orbit, current, x, y, z, yaw, autocontinue);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE WAYPOINT_SET UNPACKING

/**
 * @brief Get field target_system from waypoint_set message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_waypoint_set_get_target_system(const mavlink_message_t* msg)
{
	return (uint8_t)(msg->payload)[0];
}

/**
 * @brief Get field target_component from waypoint_set message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_waypoint_set_get_target_component(const mavlink_message_t* msg)
{
	return (uint8_t)(msg->payload+sizeof(uint8_t))[0];
}

/**
 * @brief Get field seq from waypoint_set message
 *
 * @return Sequence
 */
static inline uint16_t mavlink_msg_waypoint_set_get_seq(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(uint8_t)+sizeof(uint8_t))[0];
	r.b[0] = (msg->payload+sizeof(uint8_t)+sizeof(uint8_t))[1];
	return (uint16_t)r.s;
}

/**
 * @brief Get field type from waypoint_set message
 *
 * @return 0: global (GPS), 1: local, 2: global orbit, 3: local orbit
 */
static inline uint8_t mavlink_msg_waypoint_set_get_type(const mavlink_message_t* msg)
{
	return (uint8_t)(msg->payload+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint16_t))[0];
}

/**
 * @brief Get field orbit from waypoint_set message
 *
 * @return Orbit to circle around the waypoint, in meters
 */
static inline uint8_t mavlink_msg_waypoint_set_get_orbit(const mavlink_message_t* msg)
{
	return (uint8_t)(msg->payload+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint16_t)+sizeof(uint8_t))[0];
}

/**
 * @brief Get field current from waypoint_set message
 *
 * @return false:0, true:1
 */
static inline uint8_t mavlink_msg_waypoint_set_get_current(const mavlink_message_t* msg)
{
	return (uint8_t)(msg->payload+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint16_t)+sizeof(uint8_t)+sizeof(uint8_t))[0];
}

/**
 * @brief Get field x from waypoint_set message
 *
 * @return local: x position, global: latitude
 */
static inline float mavlink_msg_waypoint_set_get_x(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint16_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint8_t))[0];
	r.b[2] = (msg->payload+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint16_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint8_t))[1];
	r.b[1] = (msg->payload+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint16_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint8_t))[2];
	r.b[0] = (msg->payload+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint16_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint8_t))[3];
	return (float)r.f;
}

/**
 * @brief Get field y from waypoint_set message
 *
 * @return y position: global: longitude
 */
static inline float mavlink_msg_waypoint_set_get_y(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint16_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint16_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint16_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint16_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(float))[3];
	return (float)r.f;
}

/**
 * @brief Get field z from waypoint_set message
 *
 * @return z position: global: altitude
 */
static inline float mavlink_msg_waypoint_set_get_z(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint16_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(float)+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint16_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(float)+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint16_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(float)+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint16_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(float)+sizeof(float))[3];
	return (float)r.f;
}

/**
 * @brief Get field yaw from waypoint_set message
 *
 * @return yaw orientation in radians, 0 = NORTH
 */
static inline float mavlink_msg_waypoint_set_get_yaw(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint16_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(float)+sizeof(float)+sizeof(float))[0];
	r.b[2] = (msg->payload+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint16_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(float)+sizeof(float)+sizeof(float))[1];
	r.b[1] = (msg->payload+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint16_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(float)+sizeof(float)+sizeof(float))[2];
	r.b[0] = (msg->payload+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint16_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(float)+sizeof(float)+sizeof(float))[3];
	return (float)r.f;
}

/**
 * @brief Get field autocontinue from waypoint_set message
 *
 * @return autocontinue to next wp
 */
static inline uint16_t mavlink_msg_waypoint_set_get_autocontinue(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint16_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[0];
	r.b[0] = (msg->payload+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint16_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(float)+sizeof(float)+sizeof(float)+sizeof(float))[1];
	return (uint16_t)r.s;
}

static inline void mavlink_msg_waypoint_set_decode(const mavlink_message_t* msg, mavlink_waypoint_set_t* waypoint_set)
{
	waypoint_set->target_system = mavlink_msg_waypoint_set_get_target_system(msg);
	waypoint_set->target_component = mavlink_msg_waypoint_set_get_target_component(msg);
	waypoint_set->seq = mavlink_msg_waypoint_set_get_seq(msg);
	waypoint_set->type = mavlink_msg_waypoint_set_get_type(msg);
	waypoint_set->orbit = mavlink_msg_waypoint_set_get_orbit(msg);
	waypoint_set->current = mavlink_msg_waypoint_set_get_current(msg);
	waypoint_set->x = mavlink_msg_waypoint_set_get_x(msg);
	waypoint_set->y = mavlink_msg_waypoint_set_get_y(msg);
	waypoint_set->z = mavlink_msg_waypoint_set_get_z(msg);
	waypoint_set->yaw = mavlink_msg_waypoint_set_get_yaw(msg);
	waypoint_set->autocontinue = mavlink_msg_waypoint_set_get_autocontinue(msg);
}
