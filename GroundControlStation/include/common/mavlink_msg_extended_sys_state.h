#pragma once
// MESSAGE EXTENDED_SYS_STATE PACKING

#define MAVLINK_MSG_ID_EXTENDED_SYS_STATE 245

MAVPACKED(
typedef struct __mavlink_extended_sys_state_t {
 uint8_t vtol_state; /*< The VTOL state if applicable. Is set to MAV_VTOL_STATE_UNDEFINED if UAV is not in VTOL configuration.*/
 uint8_t landed_state; /*< The landed state. Is set to MAV_LANDED_STATE_UNDEFINED if landed state is unknown.*/
 uint8_t padding[14]; /*< Padding for encryption*/
 uint8_t tag[16]; /*< 128 bit message signature*/
}) mavlink_extended_sys_state_t;

#define MAVLINK_MSG_ID_EXTENDED_SYS_STATE_LEN 32
#define MAVLINK_MSG_ID_EXTENDED_SYS_STATE_MIN_LEN 32
#define MAVLINK_MSG_ID_245_LEN 32
#define MAVLINK_MSG_ID_245_MIN_LEN 32

#define MAVLINK_MSG_ID_EXTENDED_SYS_STATE_CRC 232
#define MAVLINK_MSG_ID_245_CRC 232

#define MAVLINK_MSG_EXTENDED_SYS_STATE_FIELD_PADDING_LEN 14
#define MAVLINK_MSG_EXTENDED_SYS_STATE_FIELD_TAG_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_EXTENDED_SYS_STATE { \
    245, \
    "EXTENDED_SYS_STATE", \
    4, \
    {  { "vtol_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_extended_sys_state_t, vtol_state) }, \
         { "landed_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_extended_sys_state_t, landed_state) }, \
         { "padding", NULL, MAVLINK_TYPE_UINT8_T, 14, 2, offsetof(mavlink_extended_sys_state_t, padding) }, \
         { "tag", NULL, MAVLINK_TYPE_UINT8_T, 16, 16, offsetof(mavlink_extended_sys_state_t, tag) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_EXTENDED_SYS_STATE { \
    "EXTENDED_SYS_STATE", \
    4, \
    {  { "vtol_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_extended_sys_state_t, vtol_state) }, \
         { "landed_state", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_extended_sys_state_t, landed_state) }, \
         { "padding", NULL, MAVLINK_TYPE_UINT8_T, 14, 2, offsetof(mavlink_extended_sys_state_t, padding) }, \
         { "tag", NULL, MAVLINK_TYPE_UINT8_T, 16, 16, offsetof(mavlink_extended_sys_state_t, tag) }, \
         } \
}
#endif

/**
 * @brief Pack a extended_sys_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param vtol_state The VTOL state if applicable. Is set to MAV_VTOL_STATE_UNDEFINED if UAV is not in VTOL configuration.
 * @param landed_state The landed state. Is set to MAV_LANDED_STATE_UNDEFINED if landed state is unknown.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_extended_sys_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t vtol_state, uint8_t landed_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EXTENDED_SYS_STATE_LEN];
    _mav_put_uint8_t(buf, 0, vtol_state);
    _mav_put_uint8_t(buf, 1, landed_state);
    _mav_put_uint8_t_array(buf, 2, NULL, 14);
    _mav_put_uint8_t_array(buf, 16, NULL, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EXTENDED_SYS_STATE_LEN);
#else
    mavlink_extended_sys_state_t packet;
    packet.vtol_state = vtol_state;
    packet.landed_state = landed_state;
    mav_array_memcpy(packet.padding, NULL, sizeof(uint8_t)*14);
    mav_array_memcpy(packet.tag, NULL, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EXTENDED_SYS_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EXTENDED_SYS_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_EXTENDED_SYS_STATE_MIN_LEN, MAVLINK_MSG_ID_EXTENDED_SYS_STATE_LEN, MAVLINK_MSG_ID_EXTENDED_SYS_STATE_CRC);
}

/**
 * @brief Pack a extended_sys_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param vtol_state The VTOL state if applicable. Is set to MAV_VTOL_STATE_UNDEFINED if UAV is not in VTOL configuration.
 * @param landed_state The landed state. Is set to MAV_LANDED_STATE_UNDEFINED if landed state is unknown.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_extended_sys_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t vtol_state,uint8_t landed_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EXTENDED_SYS_STATE_LEN];
    _mav_put_uint8_t(buf, 0, vtol_state);
    _mav_put_uint8_t(buf, 1, landed_state);
    _mav_put_uint8_t_array(buf, 2, NULL, 14);
    _mav_put_uint8_t_array(buf, 16, NULL, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EXTENDED_SYS_STATE_LEN);
#else
    mavlink_extended_sys_state_t packet;
    packet.vtol_state = vtol_state;
    packet.landed_state = landed_state;
    mav_array_memcpy(packet.padding, NULL, sizeof(uint8_t)*14);
    mav_array_memcpy(packet.tag, NULL, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EXTENDED_SYS_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EXTENDED_SYS_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_EXTENDED_SYS_STATE_MIN_LEN, MAVLINK_MSG_ID_EXTENDED_SYS_STATE_LEN, MAVLINK_MSG_ID_EXTENDED_SYS_STATE_CRC);
}

/**
 * @brief Encode a extended_sys_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param extended_sys_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_extended_sys_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_extended_sys_state_t* extended_sys_state)
{
    return mavlink_msg_extended_sys_state_pack(system_id, component_id, msg, extended_sys_state->vtol_state, extended_sys_state->landed_state);
}

/**
 * @brief Encode a extended_sys_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param extended_sys_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_extended_sys_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_extended_sys_state_t* extended_sys_state)
{
    return mavlink_msg_extended_sys_state_pack_chan(system_id, component_id, chan, msg, extended_sys_state->vtol_state, extended_sys_state->landed_state);
}

/**
 * @brief Send a extended_sys_state message
 * @param chan MAVLink channel to send the message
 *
 * @param vtol_state The VTOL state if applicable. Is set to MAV_VTOL_STATE_UNDEFINED if UAV is not in VTOL configuration.
 * @param landed_state The landed state. Is set to MAV_LANDED_STATE_UNDEFINED if landed state is unknown.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_extended_sys_state_send(mavlink_channel_t chan, uint8_t vtol_state, uint8_t landed_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EXTENDED_SYS_STATE_LEN];
    _mav_put_uint8_t(buf, 0, vtol_state);
    _mav_put_uint8_t(buf, 1, landed_state);
    _mav_put_uint8_t_array(buf, 2, NULL, 14);
    _mav_put_uint8_t_array(buf, 16, NULL, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXTENDED_SYS_STATE, buf, MAVLINK_MSG_ID_EXTENDED_SYS_STATE_MIN_LEN, MAVLINK_MSG_ID_EXTENDED_SYS_STATE_LEN, MAVLINK_MSG_ID_EXTENDED_SYS_STATE_CRC);
#else
    mavlink_extended_sys_state_t packet;
    packet.vtol_state = vtol_state;
    packet.landed_state = landed_state;
    mav_array_memcpy(packet.padding, NULL, sizeof(uint8_t)*14);
    mav_array_memcpy(packet.tag, NULL, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXTENDED_SYS_STATE, (const char *)&packet, MAVLINK_MSG_ID_EXTENDED_SYS_STATE_MIN_LEN, MAVLINK_MSG_ID_EXTENDED_SYS_STATE_LEN, MAVLINK_MSG_ID_EXTENDED_SYS_STATE_CRC);
#endif
}

/**
 * @brief Send a extended_sys_state message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_extended_sys_state_send_struct(mavlink_channel_t chan, const mavlink_extended_sys_state_t* extended_sys_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_extended_sys_state_send(chan, extended_sys_state->vtol_state, extended_sys_state->landed_state);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXTENDED_SYS_STATE, (const char *)extended_sys_state, MAVLINK_MSG_ID_EXTENDED_SYS_STATE_MIN_LEN, MAVLINK_MSG_ID_EXTENDED_SYS_STATE_LEN, MAVLINK_MSG_ID_EXTENDED_SYS_STATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_EXTENDED_SYS_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_extended_sys_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t vtol_state, uint8_t landed_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, vtol_state);
    _mav_put_uint8_t(buf, 1, landed_state);
    _mav_put_uint8_t_array(buf, 2, NULL, 14);
    _mav_put_uint8_t_array(buf, 16, NULL, 16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXTENDED_SYS_STATE, buf, MAVLINK_MSG_ID_EXTENDED_SYS_STATE_MIN_LEN, MAVLINK_MSG_ID_EXTENDED_SYS_STATE_LEN, MAVLINK_MSG_ID_EXTENDED_SYS_STATE_CRC);
#else
    mavlink_extended_sys_state_t *packet = (mavlink_extended_sys_state_t *)msgbuf;
    packet->vtol_state = vtol_state;
    packet->landed_state = landed_state;
    mav_array_memcpy(packet->padding, NULL, sizeof(uint8_t)*14);
    mav_array_memcpy(packet->tag, NULL, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EXTENDED_SYS_STATE, (const char *)packet, MAVLINK_MSG_ID_EXTENDED_SYS_STATE_MIN_LEN, MAVLINK_MSG_ID_EXTENDED_SYS_STATE_LEN, MAVLINK_MSG_ID_EXTENDED_SYS_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE EXTENDED_SYS_STATE UNPACKING


/**
 * @brief Get field vtol_state from extended_sys_state message
 *
 * @return The VTOL state if applicable. Is set to MAV_VTOL_STATE_UNDEFINED if UAV is not in VTOL configuration.
 */
static inline uint8_t mavlink_msg_extended_sys_state_get_vtol_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field landed_state from extended_sys_state message
 *
 * @return The landed state. Is set to MAV_LANDED_STATE_UNDEFINED if landed state is unknown.
 */
static inline uint8_t mavlink_msg_extended_sys_state_get_landed_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field padding from extended_sys_state message
 *
 * @return Padding for encryption
 */
static inline uint16_t mavlink_msg_extended_sys_state_get_padding(const mavlink_message_t* msg, uint8_t *padding)
{
    return _MAV_RETURN_uint8_t_array(msg, padding, 14,  2);
}

/**
 * @brief Get field tag from extended_sys_state message
 *
 * @return 128 bit message signature
 */
static inline uint16_t mavlink_msg_extended_sys_state_get_tag(const mavlink_message_t* msg, uint8_t *tag)
{
    return _MAV_RETURN_uint8_t_array(msg, tag, 16,  16);
}

/**
 * @brief Decode a extended_sys_state message into a struct
 *
 * @param msg The message to decode
 * @param extended_sys_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_extended_sys_state_decode(const mavlink_message_t* msg, mavlink_extended_sys_state_t* extended_sys_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    extended_sys_state->vtol_state = mavlink_msg_extended_sys_state_get_vtol_state(msg);
    extended_sys_state->landed_state = mavlink_msg_extended_sys_state_get_landed_state(msg);
    mavlink_msg_extended_sys_state_get_padding(msg, extended_sys_state->padding);
    mavlink_msg_extended_sys_state_get_tag(msg, extended_sys_state->tag);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_EXTENDED_SYS_STATE_LEN? msg->len : MAVLINK_MSG_ID_EXTENDED_SYS_STATE_LEN;
        memset(extended_sys_state, 0, MAVLINK_MSG_ID_EXTENDED_SYS_STATE_LEN);
    memcpy(extended_sys_state, _MAV_PAYLOAD(msg), len);
#endif
}
