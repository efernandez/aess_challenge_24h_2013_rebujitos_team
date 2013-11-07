/******************************************************************************
 * Sentence Serial Echo Test - sentence.ino                                   *
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

    ERROR_PIN        = 13,

    MAX_LENGTH       = 8,

    SENTENCE_LENGTH    = 16,
    SENTENCE_DELIMITER = '\n'
};

byte sentence[SENTENCE_LENGTH];
byte sentence_index;
bool sentence_ready;

void serialEvent()
{
    while( Serial.available() and sentence_index < SENTENCE_LENGTH )
    {
        sentence[sentence_index++] = Serial.read();
    }

    if( sentence[serial_index-1] == SENTENCE_DELIMITER )
    {
        sentence_ready = true;
    }
    else
    {
        _sentence_ready = false;
        
        if( sentence_index == SENTENCE_LENGTH )
        {
            Serial.flush();

            digitalWrite( ERROR_PIN, HIGH );
        }
    }
}

void setup()
{
    Serial.begin( SERIAL_BAUD_RATE );

    pinMode( ERROR_PIN, OUTPUT );

    delay( DELAY_SETUP );
}

void loop()
{
}

