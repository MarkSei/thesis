#!/usr/bin/python3

import re
import subprocess
import sys
from optparse import OptionParser

parser = OptionParser()
(options, args) = parser.parse_args()

MAVLINK_STX = 253
MAVLINK_STX_V2 = format(MAVLINK_STX, '02x')
print(type(MAVLINK_STX_V2))