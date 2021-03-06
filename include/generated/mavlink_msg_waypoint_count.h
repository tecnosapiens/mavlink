// MESSAGE WAYPOINT_COUNT PACKING

#define MAVLINK_MSG_ID_WAYPOINT_COUNT 44

typedef struct __mavlink_waypoint_count_t 
{
	uint8_t target_system; ///< System ID
	uint8_t target_component; ///< Component ID
	uint16_t count; ///< Number of Waypoints in the Sequence

} mavlink_waypoint_count_t;



/**
 * @brief Send a waypoint_count message
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @param count Number of Waypoints in the Sequence
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_waypoint_count_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint8_t target_system, uint8_t target_component, uint16_t count)
{
	msg->msgid = MAVLINK_MSG_ID_WAYPOINT_COUNT;
	uint16_t i = 0;

	i += put_uint8_t_by_index(target_system, i, msg->payload); //System ID
	i += put_uint8_t_by_index(target_component, i, msg->payload); //Component ID
	i += put_uint16_t_by_index(count, i, msg->payload); //Number of Waypoints in the Sequence

	return mavlink_finalize_message(msg, system_id, component_id, i);
}

static inline uint16_t mavlink_msg_waypoint_count_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_waypoint_count_t* waypoint_count)
{
	return mavlink_msg_waypoint_count_pack(system_id, component_id, msg, waypoint_count->target_system, waypoint_count->target_component, waypoint_count->count);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_waypoint_count_send(mavlink_channel_t chan, uint8_t target_system, uint8_t target_component, uint16_t count)
{
	mavlink_message_t msg;
	mavlink_msg_waypoint_count_pack(mavlink_system.sysid, mavlink_system.compid, &msg, target_system, target_component, count);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE WAYPOINT_COUNT UNPACKING

/**
 * @brief Get field target_system from waypoint_count message
 *
 * @return System ID
 */
static inline uint8_t mavlink_msg_waypoint_count_get_target_system(const mavlink_message_t* msg)
{
	return (uint8_t)(msg->payload)[0];
}

/**
 * @brief Get field target_component from waypoint_count message
 *
 * @return Component ID
 */
static inline uint8_t mavlink_msg_waypoint_count_get_target_component(const mavlink_message_t* msg)
{
	return (uint8_t)(msg->payload+sizeof(uint8_t))[0];
}

/**
 * @brief Get field count from waypoint_count message
 *
 * @return Number of Waypoints in the Sequence
 */
static inline uint16_t mavlink_msg_waypoint_count_get_count(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload+sizeof(uint8_t)+sizeof(uint8_t))[0];
	r.b[0] = (msg->payload+sizeof(uint8_t)+sizeof(uint8_t))[1];
	return (uint16_t)r.s;
}

static inline void mavlink_msg_waypoint_count_decode(const mavlink_message_t* msg, mavlink_waypoint_count_t* waypoint_count)
{
	waypoint_count->target_system = mavlink_msg_waypoint_count_get_target_system(msg);
	waypoint_count->target_component = mavlink_msg_waypoint_count_get_target_component(msg);
	waypoint_count->count = mavlink_msg_waypoint_count_get_count(msg);
}
