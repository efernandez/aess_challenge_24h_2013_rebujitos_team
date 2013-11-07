/******************************************************************************
 * SPI Echo Test - echo.ino                                                   *
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

#include <SPI.h>

enum Config {
    ECHO_BAUD_RATE = 9600,  // bps
    SLAVE_ADDR     = 0x1e,

    DELAY_SETUP    = 1000   // ms
};

Wire echo;

void setup()
{
    echo.begin( /* master */ );

    Serial.begin( SERIAL_BAUD_RATE );

    delay( DELAY_SETUP );
}

void loop()
{
    if( Serial.available() )
    {
        echo.beginTransmission( SLAVE_ADDR );

        while( Serial.available() )
        {
            echo.write( Serial.read() );
        }

        echo.endTransmission();
    }

    while( echo.available() )
    {
        Serial.write( echo.read() );
    }
}

