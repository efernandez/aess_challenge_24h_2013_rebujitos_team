/******************************************************************************
 * WireDevice Library - wire_device.cpp                                       *
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

#include "wire_device.h"

WireDevice::WireDevice( byte dev_addr ) :
    _dev_addr( dev_addr )
{
    Wire.begin( /* master */ );
}

size_t WireDevice::readRegister( byte &value )
{
    Wire.requestFrom( _dev_addr, 1U );

    if( Wire.available() )
    {
        value = Wire.read();
        return 1;
    }

    return 0;
}

size_t WireDevice::writeRegister( byte value )
{
    size_t written_bytes;

    Wire.beginTransmission( _dev_addr );
    written_bytes = Wire.write( value );
    Wire.endTransmission();

    return written_bytes;
}

size_t WireDevice::readRegister( byte reg_addr, byte &value )
{
    Wire.beginTransmission( _dev_addr );
    Wire.write( reg_addr );
    Wire.endTransmission();

    Wire.requestFrom( _dev_addr, 1U );

    if( Wire.available() )
    {
        value = Wire.read();
        return 1;
    }

    return 0;
}

size_t WireDevice::writeRegister( byte reg_addr, byte value )
{
    size_t written_bytes;

    Wire.beginTransmission( _dev_addr );
    Wire.write( reg_addr );
    written_bytes = Wire.write( value );
    Wire.endTransmission();

    return written_bytes;
}

size_t WireDevice::readRegister( byte *buffer, size_t num_bytes )
{
    size_t idx = 0;

    Wire.requestFrom( _dev_addr, num_bytes );

    while( Wire.available() and idx < num_bytes )
    {
        buffer[idx++] = Wire.read();
    }

    return idx;
}

size_t WireDevice::writeRegister( byte *buffer, size_t num_bytes )
{
    size_t written_bytes;

    Wire.beginTransmission( _dev_addr );
    written_bytes = Wire.write( buffer, num_bytes );
    Wire.endTransmission();

    return written_bytes;
}

size_t WireDevice::readRegister( byte reg_addr, byte *buffer, size_t num_bytes )
{
    size_t idx = 0;

    Wire.beginTransmission( _dev_addr );
    Wire.write( reg_addr );
    Wire.endTransmission(); 

    Wire.requestFrom( _dev_addr, num_bytes);

    while( Wire.available() and idx < num_bytes )
    {
        buffer[idx++] = Wire.read();
    }

    return idx;
}

size_t WireDevice::writeRegister( byte reg_addr, byte *buffer, size_t num_bytes )
{
    size_t written_bytes;

    Wire.beginTransmission( _dev_addr );
    Wire.write( reg_addr );
    written_bytes = Wire.write( buffer, num_bytes );
    Wire.endTransmission();
                         
    return written_bytes;
}

bool WireDevice::moveToRegister( byte reg_addr )
{
    bool moved;

    Wire.beginTransmission( _dev_addr );
    moved = Wire.write( reg_addr );
    Wire.endTransmission();

    return moved;
}

