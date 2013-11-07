#!/bin/bash

# Usage:
# ./view_serial.sh [baud_rate | hex] [dev0 dev1 ...]
#
# Example:
# ./view_serial.h 9600 /dev/ttyACM*
#
# We use minicom, but for hex data it is recommended to use
# cutecom (a GUI).
# Note that for cutecom you must configure everythin in the GUI.
# To use cutecom just do:
# ./view_serial.sh hex /dev/ttyACM*
#
# Although it cannot configure the device, it will open as many
# instances of cutecom as devices given.

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

if [[ "$BAUD_RATE" == "hex" ]]
then

    SERIAL_TERMINAL="cutecom "

else

    SERIAL_TERMINAL="minicom -o -w -b ${BAUD_RATE} -D "

fi

TERMINAL="gnome-terminal -e"

for i in ${DEVICES[@]}
do

    echo "Open serial terminal for ${i}"
    ${TERMINAL} "${SERIAL_TERMINAL} ${i}"

done

