# -*- coding: UTF8 -*-
"""

Wire protocol controller over Arduino.

Valid commands:

r <DEV_ADDR> <REG_ADDR> <LENGTH> <BUFFER[LENGTH]>
R <DEV_ADDR>            <LENGTH> <BUFFER[LENGTH]>
w <DEV_ADDR> <REG_ADDR> <LENGTH> <BUFFER[LENGTH]>
W <DEV_ADDR>            <LENGTH> <BUFFER[LENGTH]>

r, R : read  data
w, W : write data

r, w : read/write given   register
R, W : read/write current register

DEV_ADDR, REG_ADDR, BUFFER[LENGTH] are hexadecimal values (0xXX)
LENGTH is a decimal value
r, R, w, W are characters

"""

import serial
import numpy

if __name__ == '__main__':

    try:
        comm = serial.Serial( '/dev/ttyACM0', 9600 )
    except serial.SerialException as e:
        print( 'Failed to open serial port!' )
        print( e )
        exit()

    while True:

        s = raw_input( '$ ' )
        ss = s.split()

        if len( ss ) < 1:
            continue

        if ss[0] == 'q':
            break

        for i, item in enumerate( ss ):
            if item[0:2] == '0x':
                ss[i] = chr( int( item, 16 ) )
            elif item.isdigit():
                ss[i] = chr( int( item ) )

        s = ''.join( ss ) + '\n'

        try:
            comm.write( s )
        except serial.SerialException as e:
            print( 'Failed to write command to serial port!' )
            print( e )

