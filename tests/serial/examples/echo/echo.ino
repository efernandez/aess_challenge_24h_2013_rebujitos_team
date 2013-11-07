/******************************************************************************
 * Serial Echo Test - echo.ino                                                *
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

enum Config {
    SERIAL_BAUD_RATE = 9600,  // bps

    DELAY_SETUP      = 1000,  // ms

    ERROR_PIN        = 13
};

void setup()
{
    Serial.begin( SERIAL_BAUD_RATE );

    pinMode( ERROR_PIN, OUTPUT );

    delay( DELAY_SETUP );
}

void loop()
{
    while( Serial.available() )
    {
        if( Serial.write( Serial.read() ) )
        {
            digitalWrite( ERROR_PIN, LOW );
        }
        else
        {
            digitalWrite( ERROR_PIN, HIGH );
        }
    }
}

