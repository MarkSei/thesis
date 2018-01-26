#pragma once
// MESSAGE TEST-64-BYTES PACKING

#define MAVLINK_MSG_ID_TEST-64-BYTES 2

MAVPACKED(
typedef struct __mavlink_test-64-bytes_t {
 uint8_t u8_array[64]; /*< uint8_t_array*/
}) mavlink_test-64-bytes_t;

#define MAVLINK_MSG_ID_TEST-64-BYTES_LEN 64
#define MAVLINK_MSG_ID_TEST-64-BYTES_MIN_LEN 64
#define MAVLINK_MSG_ID_2_LEN 64
#define MAVLINK_MSG_ID_2_MIN_LEN 64

#define MAVLINK_MSG_ID_TEST-64-BYTES_CRC 231
#define MAVLINK_MSG_ID_2_CRC 231

#define MAVLINK_MSG_TEST-64-BYTES_FIELD_U8_ARRAY_LEN 64

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_TEST-64-BYTES { \
    2, \
    "TEST-64-BYTES", \
    1, \
    {  { "u8_array", NULL, MAVLINK_TYPE_UINT8_T, 64, 0, offsetof(mavlink_test-64-bytes_t, u8_array) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_TEST-64-BYTES { \
    "TEST-64-BYTES", \
    1, \
    {  { "u8_array", NULL, MAVLINK_TYPE_UINT8_T, 64, 0, offsetof(mavlink_test-64-bytes_t, u8_array) }, \
         } \
}
#endif

/**
 * @brief Pack a test-64-bytes message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param u8_array uint8_t_array
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_test-64-bytes_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const uint8_t *u8_array)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TEST-64-BYTES_LEN];

    _mav_put_uint8_t_array(buf, 0, u8_array, 64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TEST-64-BYTES_LEN);
#else
    mavlink_test-64-bytes_t packet;

    mav_array_memcpy(packet.u8_array, u8_array, sizeof(uint8_t)*64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TEST-64-BYTES_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TEST-64-BYTES;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_TEST-64-BYTES_MIN_LEN, MAVLINK_MSG_ID_TEST-64-BYTES_LEN, MAVLINK_MSG_ID_TEST-64-BYTES_CRC);
}

/**
 * @brief Pack a test-64-bytes message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param u8_array uint8_t_array
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_test-64-bytes_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const uint8_t *u8_array)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TEST-64-BYTES_LEN];

    _mav_put_uint8_t_array(buf, 0, u8_array, 64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_TEST-64-BYTES_LEN);
#else
    mavlink_test-64-bytes_t packet;

    mav_array_memcpy(packet.u8_array, u8_array, sizeof(uint8_t)*64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_TEST-64-BYTES_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_TEST-64-BYTES;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_TEST-64-BYTES_MIN_LEN, MAVLINK_MSG_ID_TEST-64-BYTES_LEN, MAVLINK_MSG_ID_TEST-64-BYTES_CRC);
}

/**
 * @brief Encode a test-64-bytes struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param test-64-bytes C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_test-64-bytes_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_test-64-bytes_t* test-64-bytes)
{
    return mavlink_msg_test-64-bytes_pack(system_id, component_id, msg, test-64-bytes->u8_array);
}

/**
 * @brief Encode a test-64-bytes struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param test-64-bytes C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_test-64-bytes_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_test-64-bytes_t* test-64-bytes)
{
    return mavlink_msg_test-64-bytes_pack_chan(system_id, component_id, chan, msg, test-64-bytes->u8_array);
}

/**
 * @brief Send a test-64-bytes message
 * @param chan MAVLink channel to send the message
 *
 * @param u8_array uint8_t_array
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_test-64-bytes_send(mavlink_channel_t chan, const uint8_t *u8_array)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_TEST-64-BYTES_LEN];

    _mav_put_uint8_t_array(buf, 0, u8_array, 64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEST-64-BYTES, buf, MAVLINK_MSG_ID_TEST-64-BYTES_MIN_LEN, MAVLINK_MSG_ID_TEST-64-BYTES_LEN, MAVLINK_MSG_ID_TEST-64-BYTES_CRC);
#else
    mavlink_test-64-bytes_t packet;

    mav_array_memcpy(packet.u8_array, u8_array, sizeof(uint8_t)*64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEST-64-BYTES, (const char *)&packet, MAVLINK_MSG_ID_TEST-64-BYTES_MIN_LEN, MAVLINK_MSG_ID_TEST-64-BYTES_LEN, MAVLINK_MSG_ID_TEST-64-BYTES_CRC);
#endif
}

/**
 * @brief Send a test-64-bytes message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_test-64-bytes_send_struct(mavlink_channel_t chan, const mavlink_test-64-bytes_t* test-64-bytes)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_test-64-bytes_send(chan, test-64-bytes->u8_array);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEST-64-BYTES, (const char *)test-64-bytes, MAVLINK_MSG_ID_TEST-64-BYTES_MIN_LEN, MAVLINK_MSG_ID_TEST-64-BYTES_LEN, MAVLINK_MSG_ID_TEST-64-BYTES_CRC);
#endif
}

#if MAVLINK_MSG_ID_TEST-64-BYTES_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_test-64-bytes_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const uint8_t *u8_array)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;

    _mav_put_uint8_t_array(buf, 0, u8_array, 64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEST-64-BYTES, buf, MAVLINK_MSG_ID_TEST-64-BYTES_MIN_LEN, MAVLINK_MSG_ID_TEST-64-BYTES_LEN, MAVLINK_MSG_ID_TEST-64-BYTES_CRC);
#else
    mavlink_test-64-bytes_t *packet = (mavlink_test-64-bytes_t *)msgbuf;

    mav_array_memcpy(packet->u8_array, u8_array, sizeof(uint8_t)*64);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_TEST-64-BYTES, (const char *)packet, MAVLINK_MSG_ID_TEST-64-BYTES_MIN_LEN, MAVLINK_MSG_ID_TEST-64-BYTES_LEN, MAVLINK_MSG_ID_TEST-64-BYTES_CRC);
#endif
}
#endif

#endif

// MESSAGE TEST-64-BYTES UNPACKING


/**
 * @brief Get field u8_array from test-64-bytes message
 *
 * @return uint8_t_array
 */
static inline uint16_t mavlink_msg_test-64-bytes_get_u8_array(const mavlink_message_t* msg, uint8_t *u8_array)
{
    return _MAV_RETURN_uint8_t_array(msg, u8_array, 64,  0);
}

/**
 * @brief Decode a test-64-bytes message into a struct
 *
 * @param msg The message to decode
 * @param test-64-bytes C-struct to decode the message contents into
 */
static inline void mavlink_msg_test-64-bytes_decode(const mavlink_message_t* msg, mavlink_test-64-bytes_t* test-64-bytes)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_test-64-bytes_get_u8_array(msg, test-64-bytes->u8_array);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_TEST-64-BYTES_LEN? msg->len : MAVLINK_MSG_ID_TEST-64-BYTES_LEN;
        memset(test-64-bytes, 0, MAVLINK_MSG_ID_TEST-64-BYTES_LEN);
    memcpy(test-64-bytes, _MAV_PAYLOAD(msg), len);
#endif
}
