// MESSAGE ACTION PACKING

#define MAVLINK_MSG_ID_ACTION 10

typedef struct __mavlink_action_t 
{
	uint8_t target; ///< The system executing the action
	uint8_t action; ///< The action id

} mavlink_action_t;



/**
 * @brief Send a action message
 *
 * @param target The system executing the action
 * @param action The action id
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_action_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint8_t target, uint8_t action)
{
	msg->msgid = MAVLINK_MSG_ID_ACTION;
	uint16_t i = 0;

	i += put_uint8_t_by_index(target, i, msg->payload); //The system executing the action
	i += put_uint8_t_by_index(action, i, msg->payload); //The action id

	return mavlink_finalize_message(msg, system_id, component_id, i);
}

static inline uint16_t mavlink_msg_action_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_action_t* action)
{
	return mavlink_msg_action_pack(system_id, component_id, msg, action->target, action->action);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_action_send(mavlink_channel_t chan, uint8_t target, uint8_t action)
{
	mavlink_message_t msg;
	mavlink_msg_action_pack(mavlink_system.sysid, mavlink_system.compid, &msg, target, action);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE ACTION UNPACKING

/**
 * @brief Get field target from action message
 *
 * @return The system executing the action
 */
static inline uint8_t mavlink_msg_action_get_target(const mavlink_message_t* msg)
{
	return (uint8_t)(msg->payload)[0];
}

/**
 * @brief Get field action from action message
 *
 * @return The action id
 */
static inline uint8_t mavlink_msg_action_get_action(const mavlink_message_t* msg)
{
	return (uint8_t)(msg->payload+sizeof(uint8_t))[0];
}

static inline void mavlink_msg_action_decode(const mavlink_message_t* msg, mavlink_action_t* action)
{
	action->target = mavlink_msg_action_get_target(msg);
	action->action = mavlink_msg_action_get_action(msg);
}
