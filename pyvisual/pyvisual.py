import re
import subprocess
import sys
from optparse import OptionParser
from collections import OrderedDict



parser = OptionParser()
(options, args) = parser.parse_args()

MAVLINK_STX = 253
MAVLINK_STX_V2 = format(MAVLINK_STX, '02x')
MAVLINK_STX_V1 = 'fe'

if args[0] == '1.0':
	mavlink_msg = subprocess.check_output(["../GroundControlStation/bin/groundcontrolstation", "localhost", "8080"])
else:
	mavlink_msg = subprocess.check_output(["../GCSMavV2/bin/gcsmavv2"])


if mavlink_msg[0:2] == MAVLINK_STX_V1:

	message = {
		"magic": MAVLINK_STX_V1,
		"len": mavlink_msg[2] + mavlink_msg[3],
		"seq": mavlink_msg[4] + mavlink_msg[5],
		"sysid": mavlink_msg[6] + mavlink_msg[7],
		"compid": mavlink_msg[8] + mavlink_msg[9],
		"msgid": mavlink_msg[10] + mavlink_msg[11],
		"payload": mavlink_msg[12:len(mavlink_msg)-4],
		"crc": mavlink_msg[len(mavlink_msg)-4:len(mavlink_msg)]
	}

	to_protocol = "%s:%d,%s:%d,%s:%d,%s:%d,%s:%d,%s:%d" % (	message["magic"], 8 * len(message["magic"]) / 2,
															message["len"], 8 * len(message["len"]) / 2,
															message["seq"], 8 * len(message["seq"]) / 2,
															message["sysid"], 8 * len(message["sysid"]) / 2,
															message["compid"], 8 * len(message["compid"]) / 2,
															message["msgid"], 8 * len(message["msgid"]) / 2)



	output = subprocess.check_output(["../protocol/protocol", to_protocol, "--no-numbers", "-b", "16"])

	spaces = '    '.join([message["payload"][i:i+2] for i in range(0, len(message["payload"]), 2)])
	newlines = [spaces[i:i+22] for i in range(0, len(spaces), 30)]

	payload_out = ''

	for line in newlines:
		payload_out += (line + ":16,")
		

	payload = subprocess.check_output(["../protocol/protocol", payload_out[0:len(payload_out)-1], "--no-numbers", "-b", "16", "--evenchar", " ", "--oddchar", " "])
	crc = subprocess.check_output(["../protocol/protocol", message["crc"]+":16", "--no-numbers", "-b", "16"])

	final = output+payload[34:len(payload)-34]+crc

elif mavlink_msg[0:2] == MAVLINK_STX_V2:

	message = {
		"magic": MAVLINK_STX_V1,
		"len": mavlink_msg[2] + mavlink_msg[3],
		"incom": mavlink_msg[4] + mavlink_msg[5],
		"comp": mavlink_msg[6] + mavlink_msg[7],
		"seq": mavlink_msg[8] + mavlink_msg[9],
		"sysid": mavlink_msg[10] + mavlink_msg[11],
		"compid": mavlink_msg[12:14],
		"dialect": mavlink_msg[14:16],
		"msgid": mavlink_msg[16:20],
		"payload": mavlink_msg[20:len(mavlink_msg)-30],
		"crc": mavlink_msg[len(mavlink_msg)-30:len(mavlink_msg)-26],
		"linkid": mavlink_msg[len(mavlink_msg)-26:len(mavlink_msg)-24],
		"timestamp": mavlink_msg[len(mavlink_msg)-24:len(mavlink_msg)-12],
		"signature": mavlink_msg[len(mavlink_msg)-12:len(mavlink_msg)]
	}
	
	to_protocol = "%s:%d,%s:%d,%s:%d,%s:%d,%s:%d,%s:%d,%s:%d,%s:%d,%s:%d" % (	message["magic"], 8 * len(message["magic"]) / 2,
																				message["len"], 8 * len(message["len"]) / 2,
																				message["incom"], 8 * len(message["incom"]) / 2,
																				message["comp"], 8 * len(message["comp"]) / 2,
																				message["seq"], 8 * len(message["seq"]) / 2,
																				message["sysid"], 8 * len(message["sysid"]) / 2,
																				message["compid"], 8 * len(message["compid"]) / 2,
																				message["dialect"], 8 * len(message["dialect"]) / 2,
																				message["msgid"], 8 * len(message["dialect"]) / 2)

	output = subprocess.check_output(["../protocol/protocol", to_protocol, "--no-numbers", "-b", "24"])

	spaces = '    '.join([message["payload"][i:i+2] for i in range(0, len(message["payload"]), 2)])
	newlines = [spaces[i:i+20] for i in range(0, len(spaces), 24)]


	payload_out = ''

	for line in newlines:
		payload_out += (line + ":24,")

	payload = subprocess.check_output(["../protocol/protocol", payload_out[0:len(payload_out)-1], "--no-numbers", "-b", "24", "--evenchar", " ", "--oddchar", " "])

	tail = "%s:%d,%s:%d,%s:%d,%s:%d" % (message["crc"], 8 * len(message["crc"]) / 2,
										message["linkid"], 8 * len(message["linkid"]) / 2,
										message["timestamp"], 8 * len(message["timestamp"]) / 2,
										message["signature"], 8 * len(message["signature"]) / 2)

	crc = subprocess.check_output(["../protocol/protocol", tail, "--no-numbers", "-b", "24"])

	final = output + payload[50:len(payload)-50] + crc


print(final)


