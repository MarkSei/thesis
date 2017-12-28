#pragma once
// MESSAGE OBSTACLE_DISTANCE PACKING

#define MAVLINK_MSG_ID_OBSTACLE_DISTANCE 330

MAVPACKED(
typedef struct __mavlink_obstacle_distance_t {
 uint64_t time_usec; /*< Timestamp (microseconds since system boot or since UNIX epoch)*/
 uint8_t estimator_type; /*< Class id of the distance sensor type.*/
 uint8_t distances[12]; /*< Distance of obstacles in front of the sensor starting on the left side. A value of 0 means no obstacle. In a array element, each unit corresponds to 1m.*/
 uint8_t increment; /*< Angular width in degrees of each array element.*/
 uint8_t padding[10]; /*< Padding for encryption*/
}) mavlink_obstacle_distance_t;

#define MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN 32
#define MAVLINK_MSG_ID_OBSTACLE_DISTANCE_MIN_LEN 32
#define MAVLINK_MSG_ID_330_LEN 32
#define MAVLINK_MSG_ID_330_MIN_LEN 32

#define MAVLINK_MSG_ID_OBSTACLE_DISTANCE_CRC 244
#define MAVLINK_MSG_ID_330_CRC 244

#define MAVLINK_MSG_OBSTACLE_DISTANCE_FIELD_DISTANCES_LEN 12
#define MAVLINK_MSG_OBSTACLE_DISTANCE_FIELD_PADDING_LEN 10

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_OBSTACLE_DISTANCE { \
    330, \
    "OBSTACLE_DISTANCE", \
    5, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_obstacle_distance_t, time_usec) }, \
         { "estimator_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_obstacle_distance_t, estimator_type) }, \
         { "distances", NULL, MAVLINK_TYPE_UINT8_T, 12, 9, offsetof(mavlink_obstacle_distance_t, distances) }, \
         { "increment", NULL, MAVLINK_TYPE_UINT8_T, 0, 21, offsetof(mavlink_obstacle_distance_t, increment) }, \
         { "padding", NULL, MAVLINK_TYPE_UINT8_T, 10, 22, offsetof(mavlink_obstacle_distance_t, padding) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_OBSTACLE_DISTANCE { \
    "OBSTACLE_DISTANCE", \
    5, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_obstacle_distance_t, time_usec) }, \
         { "estimator_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_obstacle_distance_t, estimator_type) }, \
         { "distances", NULL, MAVLINK_TYPE_UINT8_T, 12, 9, offsetof(mavlink_obstacle_distance_t, distances) }, \
         { "increment", NULL, MAVLINK_TYPE_UINT8_T, 0, 21, offsetof(mavlink_obstacle_distance_t, increment) }, \
         { "padding", NULL, MAVLINK_TYPE_UINT8_T, 10, 22, offsetof(mavlink_obstacle_distance_t, padding) }, \
         } \
}
#endif

/**
 * @brief Pack a obstacle_distance message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec Timestamp (microseconds since system boot or since UNIX epoch)
 * @param estimator_type Class id of the distance sensor type.
 * @param distances Distance of obstacles in front of the sensor starting on the left side. A value of 0 means no obstacle. In a array element, each unit corresponds to 1m.
 * @param increment Angular width in degrees of each array element.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_obstacle_distance_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, uint8_t estimator_type, const uint8_t *distances, uint8_t increment)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint8_t(buf, 8, estimator_type);
    _mav_put_uint8_t(buf, 21, increment);
    _mav_put_uint8_t_array(buf, 9, distances, 12);
    _mav_put_uint8_t_array(buf, 22, NULL, 10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN);
#else
    mavlink_obstacle_distance_t packet;
    packet.time_usec = time_usec;
    packet.estimator_type = estimator_type;
    packet.increment = increment;
    mav_array_memcpy(packet.distances, distances, sizeof(uint8_t)*12);
    mav_array_memcpy(packet.padding, NULL, sizeof(uint8_t)*10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_OBSTACLE_DISTANCE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_MIN_LEN, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_CRC);
}

/**
 * @brief Pack a obstacle_distance message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec Timestamp (microseconds since system boot or since UNIX epoch)
 * @param estimator_type Class id of the distance sensor type.
 * @param distances Distance of obstacles in front of the sensor starting on the left side. A value of 0 means no obstacle. In a array element, each unit corresponds to 1m.
 * @param increment Angular width in degrees of each array element.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_obstacle_distance_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,uint8_t estimator_type,const uint8_t *distances,uint8_t increment)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint8_t(buf, 8, estimator_type);
    _mav_put_uint8_t(buf, 21, increment);
    _mav_put_uint8_t_array(buf, 9, distances, 12);
    _mav_put_uint8_t_array(buf, 22, NULL, 10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN);
#else
    mavlink_obstacle_distance_t packet;
    packet.time_usec = time_usec;
    packet.estimator_type = estimator_type;
    packet.increment = increment;
    mav_array_memcpy(packet.distances, distances, sizeof(uint8_t)*12);
    mav_array_memcpy(packet.padding, NULL, sizeof(uint8_t)*10);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_OBSTACLE_DISTANCE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_MIN_LEN, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_CRC);
}

/**
 * @brief Encode a obstacle_distance struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param obstacle_distance C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_obstacle_distance_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_obstacle_distance_t* obstacle_distance)
{
    return mavlink_msg_obstacle_distance_pack(system_id, component_id, msg, obstacle_distance->time_usec, obstacle_distance->estimator_type, obstacle_distance->distances, obstacle_distance->increment);
}

/**
 * @brief Encode a obstacle_distance struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param obstacle_distance C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_obstacle_distance_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_obstacle_distance_t* obstacle_distance)
{
    return mavlink_msg_obstacle_distance_pack_chan(system_id, component_id, chan, msg, obstacle_distance->time_usec, obstacle_distance->estimator_type, obstacle_distance->distances, obstacle_distance->increment);
}

/**
 * @brief Send a obstacle_distance message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec Timestamp (microseconds since system boot or since UNIX epoch)
 * @param estimator_type Class id of the distance sensor type.
 * @param distances Distance of obstacles in front of the sensor starting on the left side. A value of 0 means no obstacle. In a array element, each unit corresponds to 1m.
 * @param increment Angular width in degrees of each array element.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_obstacle_distance_send(mavlink_channel_t chan, uint64_t time_usec, uint8_t estimator_type, const uint8_t *distances, uint8_t increment)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint8_t(buf, 8, estimator_type);
    _mav_put_uint8_t(buf, 21, increment);
    _mav_put_uint8_t_array(buf, 9, distances, 12);
    _mav_put_uint8_t_array(buf, 22, NULL, 10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_OBSTACLE_DISTANCE, buf, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_MIN_LEN, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_CRC);
#else
    mavlink_obstacle_distance_t packet;
    packet.time_usec = time_usec;
    packet.estimator_type = estimator_type;
    packet.increment = increment;
    mav_array_memcpy(packet.distances, distances, sizeof(uint8_t)*12);
    mav_array_memcpy(packet.padding, NULL, sizeof(uint8_t)*10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_OBSTACLE_DISTANCE, (const char *)&packet, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_MIN_LEN, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_CRC);
#endif
}

/**
 * @brief Send a obstacle_distance message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_obstacle_distance_send_struct(mavlink_channel_t chan, const mavlink_obstacle_distance_t* obstacle_distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_obstacle_distance_send(chan, obstacle_distance->time_usec, obstacle_distance->estimator_type, obstacle_distance->distances, obstacle_distance->increment);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_OBSTACLE_DISTANCE, (const char *)obstacle_distance, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_MIN_LEN, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_CRC);
#endif
}

#if MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_obstacle_distance_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, uint8_t estimator_type, const uint8_t *distances, uint8_t increment)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint8_t(buf, 8, estimator_type);
    _mav_put_uint8_t(buf, 21, increment);
    _mav_put_uint8_t_array(buf, 9, distances, 12);
    _mav_put_uint8_t_array(buf, 22, NULL, 10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_OBSTACLE_DISTANCE, buf, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_MIN_LEN, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_CRC);
#else
    mavlink_obstacle_distance_t *packet = (mavlink_obstacle_distance_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->estimator_type = estimator_type;
    packet->increment = increment;
    mav_array_memcpy(packet->distances, distances, sizeof(uint8_t)*12);
    mav_array_memcpy(packet->padding, NULL, sizeof(uint8_t)*10);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_OBSTACLE_DISTANCE, (const char *)packet, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_MIN_LEN, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_CRC);
#endif
}
#endif

#endif

// MESSAGE OBSTACLE_DISTANCE UNPACKING


/**
 * @brief Get field time_usec from obstacle_distance message
 *
 * @return Timestamp (microseconds since system boot or since UNIX epoch)
 */
static inline uint64_t mavlink_msg_obstacle_distance_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field estimator_type from obstacle_distance message
 *
 * @return Class id of the distance sensor type.
 */
static inline uint8_t mavlink_msg_obstacle_distance_get_estimator_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field distances from obstacle_distance message
 *
 * @return Distance of obstacles in front of the sensor starting on the left side. A value of 0 means no obstacle. In a array element, each unit corresponds to 1m.
 */
static inline uint16_t mavlink_msg_obstacle_distance_get_distances(const mavlink_message_t* msg, uint8_t *distances)
{
    return _MAV_RETURN_uint8_t_array(msg, distances, 12,  9);
}

/**
 * @brief Get field increment from obstacle_distance message
 *
 * @return Angular width in degrees of each array element.
 */
static inline uint8_t mavlink_msg_obstacle_distance_get_increment(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  21);
}

/**
 * @brief Get field padding from obstacle_distance message
 *
 * @return Padding for encryption
 */
static inline uint16_t mavlink_msg_obstacle_distance_get_padding(const mavlink_message_t* msg, uint8_t *padding)
{
    return _MAV_RETURN_uint8_t_array(msg, padding, 10,  22);
}

/**
 * @brief Decode a obstacle_distance message into a struct
 *
 * @param msg The message to decode
 * @param obstacle_distance C-struct to decode the message contents into
 */
static inline void mavlink_msg_obstacle_distance_decode(const mavlink_message_t* msg, mavlink_obstacle_distance_t* obstacle_distance)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    obstacle_distance->time_usec = mavlink_msg_obstacle_distance_get_time_usec(msg);
    obstacle_distance->estimator_type = mavlink_msg_obstacle_distance_get_estimator_type(msg);
    mavlink_msg_obstacle_distance_get_distances(msg, obstacle_distance->distances);
    obstacle_distance->increment = mavlink_msg_obstacle_distance_get_increment(msg);
    mavlink_msg_obstacle_distance_get_padding(msg, obstacle_distance->padding);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN? msg->len : MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN;
        memset(obstacle_distance, 0, MAVLINK_MSG_ID_OBSTACLE_DISTANCE_LEN);
    memcpy(obstacle_distance, _MAV_PAYLOAD(msg), len);
#endif
}