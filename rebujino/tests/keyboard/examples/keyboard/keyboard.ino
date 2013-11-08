
#if ARDUINO >= 100
#   include <Arduino.h>
#else
#   include <WProgram.h>
#endif

int led = 13;

char c;

void setup()
{
    Serial.begin(9600);

    pinMode( led, OUTPUT );
}

void loop()
{
    c = Serial.read();

    if (c != -1)
    {
        switch(c)
        {
            case 'w':
                digitalWrite(led, HIGH);
                break;
            case 's':
                digitalWrite(led, LOW);
                break;
        }
    }
}

