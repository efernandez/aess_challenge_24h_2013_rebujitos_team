/******************************************************************************
 * WireDevice Library - wire_device.h                                         *
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

#ifndef WIRE_DEVICE_H
#define WIRE_DEVICE_H

#if ARDUINO < 100
#   include <WProgram.h>
#else
#   include <Arduino.h>
#endif

#include <Wire.h>

class WireDevice {
public:

    WireDevice( byte dev_addr );

    // Single byte - Current register:
    size_t readRegister ( byte &value );
    size_t writeRegister( byte  value );

    // Single byte - Given register:
    size_t readRegister ( byte reg_addr, byte &value );
    size_t writeRegister( byte reg_addr, byte  value );

    // Multiple bytes - Current register (and following):
    size_t readRegister ( byte *buffer, size_t num_bytes );
    size_t writeRegister( byte *buffer, size_t num_bytes );

    // Multiple bytes - Given register:
    size_t readRegister ( byte reg_addr, byte *buffer, size_t num_bytes );
    size_t writeRegister( byte reg_addr, byte *buffer, size_t num_bytes );

    // Move to register:
    bool moveToRegister( byte reg_addr );

private:

    byte _dev_addr;

};

#endif // WIRE_DEVICE_H

