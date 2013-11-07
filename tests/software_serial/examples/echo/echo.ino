/******************************************************************************
 * Software Serial Echo Test - echo.ino                                       *
 *                                                                            *
 * Copyright (C) 2013                                                         *
 * Enrique Fernández Perdomo (enrique.fernandez.perdomo@gmail.com)            *
 *                                                                            *
 * License GPLv3+: GNU GPL version 3 or later                                 *
 * <http://gnu.org/licenses/gpl.html>                                         *
 * This is free software: you are free to change and redistribute it.         *
 * There is NO WARRANTY, to the extent permitted by law.                      *
 *                                                                            *
 ******************************************************************************/

#if ARDUINO >= 100
#   include <Arduino.h>
#else
#   include <WProgram.h>
#endif

#include <SoftwareSerial.h>

// Taken from arduino.cc/forum:
//
// Specifically for the Arduino Mega 2560 (or 1280 on the original Arduino Mega)
// A majority of the pins are NOT PCINTs, SO BE WARNED (i.e. you cannot use them as receive pins)
// Only pins available for RECEIVE (TRANSMIT can be on any pin):
// (I've deliberately left out pin mapping to the Hardware USARTs - seems senseless to me)
// Pins: 10, 11, 12, 13,  50, 51, 52, 53,  62, 63, 64, 65, 66, 67, 68, 69
enum Pin {
    PIN_RX = 10,
    PIN_TX = 11
};

enum Config {
    ECHO_BAUD_RATE   = 9600,  // bps
    SERIAL_BAUD_RATE = 9600,  // bps

    DELAY_SETUP      = 1000,  // ms
    ERROR_PIN        = 13
};

SoftwareSerial echo( PIN_RX, PIN_TX );

void setup()
{
    echo.begin( ECHO_BAUD_RATE );

    Serial.begin( SERIAL_BAUD_RATE );

    pinMode( ERROR_PIN, OUTPUT );

    delay( DELAY_SETUP );
}

void loop()
{
    while( Serial.available() )
    {
        if( echo.write( Serial.read() ) )
        {
            digitalWrite( ERROR_PIN, LOW );
        }
        else
        {
            digitalWrite( ERROR_PIN, HIGH );
        }
    }

    while( echo.available() )
    {
        Serial.write( echo.read() );
    }
}

