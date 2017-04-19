int blanket = D0; 
int fan = D1; 
int output1 = D2;
int output2 = D3;

void setup()
{
    pinMode(blanket, OUTPUT);
    pinMode(fan, OUTPUT);
    pinMode(output1, OUTPUT);
    pinMode(output2, OUTPUT);

    Particle.function("setFanLevel", setFanLevel);
    Particle.function("setOutput1", setOutput1);
    Particle.function("setOutput2", setOutput2);
}

unsigned long int ulFanLevel = 0;

int setFanLevel(String level)
{
   char *ptr;
   long ret;

   ulFanLevel = strtoul((const char *)level, &ptr, 0);
}

int setOutput1(String state)
{
    if (state.toLowerCase() == "on")
    {
        digitalWrite(output1, HIGH);
    }
    else if (state.toLowerCase() == "off")
    {
        digitalWrite(output1, LOW);
    } 
}

int setOutput2(String state)
{
    if (state.toLowerCase() == "on")
    {
        digitalWrite(output2, HIGH);
    }
    else if (state.toLowerCase() == "off")
    {
        digitalWrite(output2, LOW);
    } 
}

void loop() 
{
    for (unsigned long ulIndex=1; ulIndex < 11; ulIndex++)
    {
        if (ulIndex <= ulFanLevel)
        {
            // To blink the LED, first we'll turn it on...
            digitalWrite(fan, HIGH);
        }
        else
        {
             // Then we'll turn it off...
            digitalWrite(fan, LOW);
        }
    

        // We'll leave it on for 1 second...
        delay(20);
    }
}