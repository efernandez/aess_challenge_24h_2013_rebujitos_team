/******************************************************************************
 * WireDevice Library - master_writer.ino                                     *
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

#include <Wire.h>
#include "wire_device.h"

WireDevice wire_device( 0x04  );
byte x = 0;

void setup(){}

void loop()
{
    wire_device.writeRegister( x++ );

    delay( 500 );
}

