
#if ARDUINO >= 100
#   include <Arduino.h>
#else
#   include <WProgram.h>
#endif

int led = 13;

void setup()
{
    pinMode( led, OUTPUT );
}

void loop()
{
    digitalWrite( led, LOW );
    delay(3000);
    digitalWrite( led, HIGH );
    delay(3000);
}

