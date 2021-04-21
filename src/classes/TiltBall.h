#ifndef _CLASS_TILTBALL
#define _CLASS_TILTBALL

class TiltBall {
  private:
    int pin = -1;
    int state = HIGH;
    unsigned long lastChange = 0;
    unsigned long shakeStart = 0;
    unsigned long shakeDuration = 0;
    bool shaking = false;
    bool shaken = false;

  public:
    void update();
    void setPin(int pin);
    bool getShaken();
    unsigned long getShakeDuration();
};

#endif
