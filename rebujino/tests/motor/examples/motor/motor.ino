
#if ARDUINO >= 100
#   include <Arduino.h>
#else
#   include <WProgram.h>
#endif

class MotorShieldChannel
{
public:

  enum
  {
    DIRECTION       = 12,
    PWM             =  3,
    BRAKE           =  9,
    CURRENT_SENSING =  0,

    CHANNEL_B_DIRECTION       = 13,
    CHANNEL_B_PWM             = 11,
    CHANNEL_B_BRAKE           =  8,
    CHANNEL_B_CURRENT_SENSING =  1
  };

  enum Direction
  {
    FORWARD  = LOW,
    BACKWARD = HIGH
  };

  void setDirection(Direction direction)
  {
    digitalWrite(DIRECTION, direction);
  }

  void setForward()
  {
    setDirection(FORWARD);
  }

  void setBackward()
  {
    setDirection(BACKWARD);
  }

  void setPWM(byte pwm)
  {
    digitalWrite(PWM, pwm);
  }

  void brake()
  {
    // @todo LOW or HIGH?!
    digitalWrite(BRAKE, LOW);
  }

private:



};


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
            case '+':
                if (pwm < 255){
                  ++pwm;
                }
                setPWM(pwm);
                break;
            case '-':
                if (pwm > 0)
                {
                  --pwm;
                }
                setPWM(pwm);
                break;
            case '0':
                brake();
                break;
            case 'f':
                setForward();
                break;
            case 'b':
                setBackward();
                break;
        }
    }

    // @todo print current!
}

