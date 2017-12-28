# Thesis Repo
Analysis and design of secure drone communication protocols

## Completed tasks:

  1. Encryption in MAVLink v1.0
  2. General key generation helper-function
  3. Chaskey signatures in MAVLink v1.0
  4. Parser that adds padding and tag fields for appr. messages (payload length <= (255 - padding - 128bit tag))
  5. Added appr. header data to signature

## TODO prio. 1:

  1. Add key exchange messages and capabilities for MAVLink v1.0 and v2.0 (DH vs ECDH)
  2. Add encryption scheme to MAVLink v2.0
  3. Change signature scheme to Chaskey in MAVLink v2.0

## TODO prio. 2:
  
  1. Add authenticated encryption for comparison
