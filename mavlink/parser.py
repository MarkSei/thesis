import xml.etree.ElementTree as ET
import re
import subprocess
import sys
from optparse import OptionParser

parser = OptionParser()

parser.add_option("-v", "--version", dest="version",
                  help="mavlink version", metavar="VERSION")

if len(sys.argv) != 3:
	sys.exit("Usage: %s <definition> [options]" % sys.argv[0])

(options, args) = parser.parse_args()

tree = ET.parse(args[0])
root = tree.getroot()

lengths = {
'float'    : 4,
'double'   : 8,
'char'     : 1,
'int8_t'   : 1,
'uint8_t'  : 1,
'uint8_t_mavlink_version'  : 1,
'int16_t'  : 2,
'uint16_t' : 2,
'int32_t'  : 4,
'uint32_t' : 4,
'int64_t'  : 8,
'uint64_t' : 8,
}



for child in root.iter('message'):
	size = 0
	padding = 0
	block_size = 16 # 128 bit aes block
	for stype in child.findall('field'):
		times = 1
		fsize = stype.get('type')
		try:
			start = fsize.index('[')
			end   = fsize.index(']')
			if start >= end or end != len(fsize) - 1:
				raise ValueError('Array has wrong format')

			regex = b"\[([0-9]+)\]$"
			arr_size = re.search(regex, fsize).group(0)
			times = int(arr_size[1:len(arr_size)-1])
			fsize = fsize[:start]

		except ValueError as err:
			print(err.args)

		size += times * lengths[fsize]
	
	padding = block_size - (size % block_size)

	if (size + block_size + padding) <= 255 and options.version == '1.0':

		attrib = {'type': 'uint8_t[{}]'.format(padding), 'name': 'padding'}
		new_field = ET.SubElement(child, 'field', attrib)
		new_field.text = "Padding for encryption"

		attrib = {'type': 'uint8_t[16]', 'name': 'tag'}
		new_field = ET.SubElement(child, 'field', attrib)
		new_field.text = "128 bit message signature"

	elif (size + padding) <= 255 and options.version == '2.0':

		attrib = {'type': 'uint8_t[{}]'.format(padding), 'name': 'padding'}
		new_field = ET.SubElement(child, 'field', attrib)
		new_field.text = "Padding for encryption"


tree.write('common.xml')

subprocess.call(["python","-m","pymavlink.tools.mavgen","--lang=C","--wire-protocol=%s" % options.version, "--output=../include", "common.xml"])
subprocess.call(["rm", "-f", "common.xml"])


# python -m pymavlink.tools.mavgen --lang=C --wire-protocol=2.0 --output=generated/include/mavlink/v2.0 message_definitions/v1.0/common.xml



