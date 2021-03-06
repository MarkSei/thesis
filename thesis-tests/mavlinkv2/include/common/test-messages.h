/** @file
 *  @brief MAVLink comm protocol generated from test-messages.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_TEST-MESSAGES_H
#define MAVLINK_TEST-MESSAGES_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_TEST-MESSAGES.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 0

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{0, 77, 16, 0, 0, 0}, {1, 149, 32, 0, 0, 0}, {2, 231, 64, 0, 0, 0}, {3, 90, 128, 0, 0, 0}, {4, 180, 224, 0, 0, 0}}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_TEST-MESSAGES

// ENUM DEFINITIONS



// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 3
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 3
#endif

// MESSAGE DEFINITIONS
#include "./mavlink_msg_test-16-bytes.h"
#include "./mavlink_msg_test-32-bytes.h"
#include "./mavlink_msg_test-64-bytes.h"
#include "./mavlink_msg_test-128-bytes.h"
#include "./mavlink_msg_test-224-bytes.h"

// base include


#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 0

#if MAVLINK_THIS_XML_IDX == MAVLINK_PRIMARY_XML_IDX
# define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_TEST-16-BYTES, MAVLINK_MESSAGE_INFO_TEST-32-BYTES, MAVLINK_MESSAGE_INFO_TEST-64-BYTES, MAVLINK_MESSAGE_INFO_TEST-128-BYTES, MAVLINK_MESSAGE_INFO_TEST-224-BYTES}
# define MAVLINK_MESSAGE_NAMES {{ "TEST-128-BYTES", 3 }, { "TEST-16-BYTES", 0 }, { "TEST-224-BYTES", 4 }, { "TEST-32-BYTES", 1 }, { "TEST-64-BYTES", 2 }}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_TEST-MESSAGES_H
