#!/bin/bash

# Usage:
# ./view_serial.sh [baud_rate] [dev0 dev1 ...]
#
# Example:
# ./view_serial.h 9600 /dev/ttyACM*
#
# We use minicom, but for hex data it is recommended to use
# cutecom (a GUI).
# Note that for cutecom you must configure everythin in the GUI.

if [[ $# -gt 0  ]]
then

    BAUD_RATE=$1

else

    BAUD_RATE="9600"

fi

if [[ $# -gt 1 ]]
then

    shift
    DEVICES=($@)

else

    DEVICES[0]="/dev/ttyACM0"

fi

SERIAL_TERMINAL="minicom -o -w -b ${BAUD_RATE} -D "

TERMINAL="gnome-terminal -e"

for i in ${DEVICES[@]}
do

    echo "Open serial terminal for ${i}"
    ${TERMINAL} "${SERIAL_TERMINAL} ${i}"

done

