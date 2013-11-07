/******************************************************************************
 * Wire Echo Test - echo.ino                                                  *
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

/******************************************************************************
 * r <DEV_ADDR> <REG_ADDR> <LENGTH> <BUFFER[LENGTH]>                          *
 * R <DEV_ADDR>            <LENGTH> <BUFFER[LENGTH]> [NOT SUPPORTED!]         *
 * w <DEV_ADDR> <REG_ADDR> <LENGTH> <BUFFER[LENGTH]>                          *
 * W <DEV_ADDR>            <LENGTH> <BUFFER[LENGTH]> [NOT SUPPORTED!]         *
 *                                                                            *
 * r, R : read  data                                                          *
 * w, W : write data                                                          *
 *                                                                            *
 * r, w : read/write given   register                                         *
 * R, W : read/write current register                                         *
 ******************************************************************************/

#if ARDUINO >= 100
#   include <Arduino.h>
#else
#   include <WProgram.h>
#endif

#include <Wire.h>

enum Config {
    SERIAL_BAUD_RATE = 9600,  // bps
    DELAY_SETUP      = 1000,  // ms
    ERROR_PIN        = 13
};

class Instruction {
public:

    Instruction() :
        cmd ( '\0' ),
        addr( 0    ),
        reg ( 0    ),
        len ( 0    ),
        data( NULL )
    {}
    ~Instruction(){}

    void parse( byte* buf )
    {
        size_t idx = 0;

        cmd = buf[idx++];

        if( cmd == 'w' or cmd == 'r' )
        {
            addr = buf[idx++];
            reg  = buf[idx++];
        }

        len = buf[idx++];
        data = buf + idx;
    }

    bool execute() const
    {
        switch( cmd )
        {
            case 'r': return execute_read_register ();
            case 'w': return execute_write_register();
            default : return false;
        }
    }

private:

    bool execute_read_register() const
    {
        Wire.beginTransmission( addr );
        Wire.write( reg );
        Wire.endTransmission();

        Wire.requestFrom( addr, len );

        int idx = 0;
        while( Wire.available() and idx < len )
        {
            data[idx++] = Wire.read();
        }

        return idx == len;
    }

    bool execute_write_register() const
    {
        int idx = 0;

        Wire.beginTransmission( addr );
        Wire.write( reg );
        idx = Wire.write( data, len );
        Wire.endTransmission();

        return idx == len;
    }

private:
    char  cmd;
    byte  addr;
    byte  reg;
    byte  len;
    byte* data;
};

class SerialSentenceReader {
public:

    enum Constant {
        BUFFER_LENGTH_MAX  = 16,
        SENTENCE_DELIMITER = '\n'
    };
    
public:

    SerialSentenceReader() :
        idx( 0 ),
        ready( false )
    {}
    ~SerialSentenceReader(){}

    void read()
    {
        if( not ready )
        {
            while( Serial.available() and idx < BUFFER_LENGTH_MAX )
            {
                buf[idx++] = Serial.read();
            }

            if( buf[idx-1] == SENTENCE_DELIMITER )
            {
                ready = true;
            }
            else if( idx == BUFFER_LENGTH_MAX )
            {
                Serial.flush();
                //digitalWrite( ERROR_PIN, HIGH );
            }
        }
    }

    byte* getSentence()
    {
        return buf;
    }

    bool isReady() const
    {
        return ready;
    }

    bool clear()
    {
        idx = 0;
        ready = false;
    }


private:
    byte buf[BUFFER_LENGTH_MAX];
    byte idx;
    bool ready;
};

Instruction instr;
SerialSentenceReader ssr;

void serialEvent()
{
    ssr.read();
}

void setup()
{
    Wire.begin( /* master */ );

    Serial.begin( SERIAL_BAUD_RATE );

    pinMode( ERROR_PIN, OUTPUT );

    delay( DELAY_SETUP );
}

bool ret;

void loop()
{
    if( ssr.isReady() )
    {
        instr.parse( ssr.getSentence() );
        ret = instr.execute();

        digitalWrite( ERROR_PIN, ret ? LOW : HIGH );

        ssr.clear();
    }
}

