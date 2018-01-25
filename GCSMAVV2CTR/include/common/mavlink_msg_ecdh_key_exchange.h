#pragma once
// MESSAGE ECDH_KEY_EXCHANGE PACKING

#define MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE 3

MAVPACKED(
typedef struct __mavlink_ecdh_key_exchange_t {
 uint64_t initial_timestamp; /*< initial timestamp*/
 uint8_t public_key[72]; /*< ECDH public key*/
 uint8_t target_system; /*< system id of the target*/
 uint8_t target_component; /*< component ID of the target*/
 uint8_t padding[14]; /*< Padding for encryption*/
}) mavlink_ecdh_key_exchange_t;

#define MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_LEN 96
#define MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_MIN_LEN 96
#define MAVLINK_MSG_ID_3_LEN 96
#define MAVLINK_MSG_ID_3_MIN_LEN 96

#define MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_CRC 116
#define MAVLINK_MSG_ID_3_CRC 116

#define MAVLINK_MSG_ECDH_KEY_EXCHANGE_FIELD_PUBLIC_KEY_LEN 72
#define MAVLINK_MSG_ECDH_KEY_EXCHANGE_FIELD_PADDING_LEN 14

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ECDH_KEY_EXCHANGE { \
    3, \
    "ECDH_KEY_EXCHANGE", \
    5, \
    {  { "public_key", NULL, MAVLINK_TYPE_UINT8_T, 72, 8, offsetof(mavlink_ecdh_key_exchange_t, public_key) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 80, offsetof(mavlink_ecdh_key_exchange_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 81, offsetof(mavlink_ecdh_key_exchange_t, target_component) }, \
         { "initial_timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_ecdh_key_exchange_t, initial_timestamp) }, \
         { "padding", NULL, MAVLINK_TYPE_UINT8_T, 14, 82, offsetof(mavlink_ecdh_key_exchange_t, padding) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ECDH_KEY_EXCHANGE { \
    "ECDH_KEY_EXCHANGE", \
    5, \
    {  { "public_key", NULL, MAVLINK_TYPE_UINT8_T, 72, 8, offsetof(mavlink_ecdh_key_exchange_t, public_key) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 80, offsetof(mavlink_ecdh_key_exchange_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 81, offsetof(mavlink_ecdh_key_exchange_t, target_component) }, \
         { "initial_timestamp", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_ecdh_key_exchange_t, initial_timestamp) }, \
         { "padding", NULL, MAVLINK_TYPE_UINT8_T, 14, 82, offsetof(mavlink_ecdh_key_exchange_t, padding) }, \
         } \
}
#endif

/**
 * @brief Pack a ecdh_key_exchange message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param public_key ECDH public key
 * @param target_system system id of the target
 * @param target_component component ID of the target
 * @param initial_timestamp initial timestamp
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ecdh_key_exchange_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const uint8_t *public_key, uint8_t target_system, uint8_t target_component, uint64_t initial_timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_LEN];
    _mav_put_uint64_t(buf, 0, initial_timestamp);
    _mav_put_uint8_t(buf, 80, target_system);
    _mav_put_uint8_t(buf, 81, target_component);
    _mav_put_uint8_t_array(buf, 8, public_key, 72);
    _mav_put_uint8_t_array(buf, 82, NULL, 14);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_LEN);
#else
    mavlink_ecdh_key_exchange_t packet;
    packet.initial_timestamp = initial_timestamp;
    packet.target_system = target_system;
    packet.target_component = target_component;
    mav_array_memcpy(packet.public_key, public_key, sizeof(uint8_t)*72);
    mav_array_memcpy(packet.padding, NULL, sizeof(uint8_t)*14);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_MIN_LEN, MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_LEN, MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_CRC);
}

/**
 * @brief Pack a ecdh_key_exchange message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param public_key ECDH public key
 * @param target_system system id of the target
 * @param target_component component ID of the target
 * @param initial_timestamp initial timestamp
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ecdh_key_exchange_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const uint8_t *public_key,uint8_t target_system,uint8_t target_component,uint64_t initial_timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_LEN];
    _mav_put_uint64_t(buf, 0, initial_timestamp);
    _mav_put_uint8_t(buf, 80, target_system);
    _mav_put_uint8_t(buf, 81, target_component);
    _mav_put_uint8_t_array(buf, 8, public_key, 72);
    _mav_put_uint8_t_array(buf, 82, NULL, 14);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_LEN);
#else
    mavlink_ecdh_key_exchange_t packet;
    packet.initial_timestamp = initial_timestamp;
    packet.target_system = target_system;
    packet.target_component = target_component;
    mav_array_memcpy(packet.public_key, public_key, sizeof(uint8_t)*72);
    mav_array_memcpy(packet.padding, NULL, sizeof(uint8_t)*14);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_MIN_LEN, MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_LEN, MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_CRC);
}

/**
 * @brief Encode a ecdh_key_exchange struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ecdh_key_exchange C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ecdh_key_exchange_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ecdh_key_exchange_t* ecdh_key_exchange)
{
    return mavlink_msg_ecdh_key_exchange_pack(system_id, component_id, msg, ecdh_key_exchange->public_key, ecdh_key_exchange->target_system, ecdh_key_exchange->target_component, ecdh_key_exchange->initial_timestamp);
}

/**
 * @brief Encode a ecdh_key_exchange struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ecdh_key_exchange C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ecdh_key_exchange_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ecdh_key_exchange_t* ecdh_key_exchange)
{
    return mavlink_msg_ecdh_key_exchange_pack_chan(system_id, component_id, chan, msg, ecdh_key_exchange->public_key, ecdh_key_exchange->target_system, ecdh_key_exchange->target_component, ecdh_key_exchange->initial_timestamp);
}

/**
 * @brief Send a ecdh_key_exchange message
 * @param chan MAVLink channel to send the message
 *
 * @param public_key ECDH public key
 * @param target_system system id of the target
 * @param target_component component ID of the target
 * @param initial_timestamp initial timestamp
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ecdh_key_exchange_send(mavlink_channel_t chan, const uint8_t *public_key, uint8_t target_system, uint8_t target_component, uint64_t initial_timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_LEN];
    _mav_put_uint64_t(buf, 0, initial_timestamp);
    _mav_put_uint8_t(buf, 80, target_system);
    _mav_put_uint8_t(buf, 81, target_component);
    _mav_put_uint8_t_array(buf, 8, public_key, 72);
    _mav_put_uint8_t_array(buf, 82, NULL, 14);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE, buf, MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_MIN_LEN, MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_LEN, MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_CRC);
#else
    mavlink_ecdh_key_exchange_t packet;
    packet.initial_timestamp = initial_timestamp;
    packet.target_system = target_system;
    packet.target_component = target_component;
    mav_array_memcpy(packet.public_key, public_key, sizeof(uint8_t)*72);
    mav_array_memcpy(packet.padding, NULL, sizeof(uint8_t)*14);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE, (const char *)&packet, MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_MIN_LEN, MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_LEN, MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_CRC);
#endif
}

/**
 * @brief Send a ecdh_key_exchange message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_ecdh_key_exchange_send_struct(mavlink_channel_t chan, const mavlink_ecdh_key_exchange_t* ecdh_key_exchange)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ecdh_key_exchange_send(chan, ecdh_key_exchange->public_key, ecdh_key_exchange->target_system, ecdh_key_exchange->target_component, ecdh_key_exchange->initial_timestamp);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE, (const char *)ecdh_key_exchange, MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_MIN_LEN, MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_LEN, MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_CRC);
#endif
}

#if MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ecdh_key_exchange_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const uint8_t *public_key, uint8_t target_system, uint8_t target_component, uint64_t initial_timestamp)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, initial_timestamp);
    _mav_put_uint8_t(buf, 80, target_system);
    _mav_put_uint8_t(buf, 81, target_component);
    _mav_put_uint8_t_array(buf, 8, public_key, 72);
    _mav_put_uint8_t_array(buf, 82, NULL, 14);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE, buf, MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_MIN_LEN, MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_LEN, MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_CRC);
#else
    mavlink_ecdh_key_exchange_t *packet = (mavlink_ecdh_key_exchange_t *)msgbuf;
    packet->initial_timestamp = initial_timestamp;
    packet->target_system = target_system;
    packet->target_component = target_component;
    mav_array_memcpy(packet->public_key, public_key, sizeof(uint8_t)*72);
    mav_array_memcpy(packet->padding, NULL, sizeof(uint8_t)*14);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE, (const char *)packet, MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_MIN_LEN, MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_LEN, MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_CRC);
#endif
}
#endif

#endif

// MESSAGE ECDH_KEY_EXCHANGE UNPACKING


/**
 * @brief Get field public_key from ecdh_key_exchange message
 *
 * @return ECDH public key
 */
static inline uint16_t mavlink_msg_ecdh_key_exchange_get_public_key(const mavlink_message_t* msg, uint8_t *public_key)
{
    return _MAV_RETURN_uint8_t_array(msg, public_key, 72,  8);
}

/**
 * @brief Get field target_system from ecdh_key_exchange message
 *
 * @return system id of the target
 */
static inline uint8_t mavlink_msg_ecdh_key_exchange_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  80);
}

/**
 * @brief Get field target_component from ecdh_key_exchange message
 *
 * @return component ID of the target
 */
static inline uint8_t mavlink_msg_ecdh_key_exchange_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  81);
}

/**
 * @brief Get field initial_timestamp from ecdh_key_exchange message
 *
 * @return initial timestamp
 */
static inline uint64_t mavlink_msg_ecdh_key_exchange_get_initial_timestamp(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field padding from ecdh_key_exchange message
 *
 * @return Padding for encryption
 */
static inline uint16_t mavlink_msg_ecdh_key_exchange_get_padding(const mavlink_message_t* msg, uint8_t *padding)
{
    return _MAV_RETURN_uint8_t_array(msg, padding, 14,  82);
}

/**
 * @brief Decode a ecdh_key_exchange message into a struct
 *
 * @param msg The message to decode
 * @param ecdh_key_exchange C-struct to decode the message contents into
 */
static inline void mavlink_msg_ecdh_key_exchange_decode(const mavlink_message_t* msg, mavlink_ecdh_key_exchange_t* ecdh_key_exchange)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    ecdh_key_exchange->initial_timestamp = mavlink_msg_ecdh_key_exchange_get_initial_timestamp(msg);
    mavlink_msg_ecdh_key_exchange_get_public_key(msg, ecdh_key_exchange->public_key);
    ecdh_key_exchange->target_system = mavlink_msg_ecdh_key_exchange_get_target_system(msg);
    ecdh_key_exchange->target_component = mavlink_msg_ecdh_key_exchange_get_target_component(msg);
    mavlink_msg_ecdh_key_exchange_get_padding(msg, ecdh_key_exchange->padding);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_LEN? msg->len : MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_LEN;
        memset(ecdh_key_exchange, 0, MAVLINK_MSG_ID_ECDH_KEY_EXCHANGE_LEN);
    memcpy(ecdh_key_exchange, _MAV_PAYLOAD(msg), len);
#endif
}
