/******************************************************************************
 * Servo Futaba S3003 Test - sweep.ino                                        *
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

#include <Servo.h>

Servo servo;
int servo_pin = 2;
int servo_delay = 10; // ms

int pos = 0;

void setup()
{
    Serial.begin( 9600 );

    servo.attach( servo_pin );
}

void loop()
{
    for( ; pos < 180; ++pos )
    {
        Serial.println( "Servo pos = " + String( pos ) );

        servo.write( pos );

        delay( servo_delay );
    }

    for( ; pos > 0; --pos )
    {
        Serial.println( "Servo pos = " + String( pos ) );

        servo.write( pos );

        delay( servo_delay);
    }
}

