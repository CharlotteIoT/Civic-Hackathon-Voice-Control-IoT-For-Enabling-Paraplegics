int fan = D1; 
int output1 = D2;
int output2 = D3;
int light = D0;

int _fanLevel = 0;
int _lightLevel = 100;
int _output1Level = 0;
int _output2Level = 0;

void setup()
{
    pinMode(light, OUTPUT);
    pinMode(fan, OUTPUT);
    pinMode(output1, OUTPUT);
    pinMode(output2, OUTPUT);

    Particle.function("setFan", setFanLevel);
    Particle.function("setLight", setLightLevel);
    Particle.function("setOutput1", setOutput1);
    Particle.function("setOutput2", setOutput2);
    
    Particle.variable("fanLevel", _fanLevel);
    Particle.variable("lightLevel",_lightLevel);
    Particle.variable("Output1Level",_output1Level);
    Particle.variable("output2Level",_output2Level);
    
    setLevels();
}

void setLevels() {
    analogWrite(fan, _fanLevel * 2, 500);
    analogWrite(light, _lightLevel * 2, 500);
    analogWrite(output1, _output1Level * 2, 500);
    analogWrite(output2, _output2Level * 2, 500);
}

int stoi(String number) {
    char inputStr[64];
    number.toCharArray(inputStr,64);
    return atoi(inputStr);
}

/*---------------------------------------------------------------
 * translateLevel takes a string input from the Alexa controller
 *  and converts it into a level between 0 and 100
/---------------------------------------------------------------*/
int translateLevel(String level, int currentLevel)
{
    level = level.toUpperCase();
    if (level == "ON") {
         currentLevel = 100;
    } else if (level == "OFF") {
        currentLevel = 0;
    } else if (level.substring(0,1) == "+") {
        level = level.substring(1,level.length());
        currentLevel += stoi(level);
    } else if (level.substring(0,1) == "-") {
        level = level.substring(1,level.length());
        currentLevel -= stoi(level);
    } else {
        currentLevel = stoi(level);
    }
   
    //If the current level is out of range, return top or bottom of the range.
    if (currentLevel > 100) return 100;
    if (currentLevel < 0) return 0;
    return currentLevel;
}

int setLightLevel(String level)
{
    _lightLevel = translateLevel(level, _lightLevel);
    setLevels();
    return _lightLevel;
}

int setFanLevel(String level)
{
    _fanLevel = translateLevel(level, _fanLevel);
    setLevels();
    return _fanLevel;
}

int setOutput1(String level)
{
    _output1Level = translateLevel(level, _output1Level);
    setLevels();
    return _output1Level;
}

int setOutput2(String level)
{
    _output2Level = translateLevel(level, _output2Level);
    setLevels();
    return _output2Level;
}


void loop() 
{
   //Do Nothing.
}