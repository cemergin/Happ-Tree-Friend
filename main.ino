// This #include statement was automatically added by the Particle IDE.
#include <neopixel.h>

// ANALOG IO
int photoCellPin = A0;
int tempPin = A1;
int soilPin = A2;

// DIGITAL IO
int ledPin = D2;
int soilPower = D3;
int pirPin = D4;

// PHOTOCELL 
int photoCellReading = 0;

// TEMPERATURE
double temperature = 0.0;
double temperatureF = 0.0;

// SOIL MOISTURE
int soilReading = 0;

// LED
int ledBrightness = 0;

// PIR SENSOR
int pirState = LOW;
int pirVal = 0;
int pirCalibrationTime = 10;

// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_COUNT 1
#define PIXEL_PIN D5
#define PIXEL_TYPE WS2812B
Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

// RGB 
int redValue = 255;
int greenValue = 0;
int blueValue = 0;

// ALERTS 
bool tempAlert = false;
bool brightnessAlert = false;
bool soilAlert = false;

// TIME 
unsigned int lastUpdate = 0 ;

void setup() {
    // PIN MODES
    pinMode(photoCellPin, INPUT);
    pinMode(tempPin, INPUT);
    pinMode(pirPin, INPUT);
    pinMode(ledPin,OUTPUT);
    pinMode(soilPower, OUTPUT);
    pinMode(PIXEL_PIN, OUTPUT);
    
    // PARTICLE COMMUNICATION
    Particle.variable("light", &photoCellReading, INT);
    Particle.variable("temperature", &temperature, DOUBLE);
    Particle.variable("temperatureF", &temperatureF, DOUBLE);
    Particle.variable("soilReading", &soilReading, INT);
    Particle.variable("pirState", &pirState, INT);
    
    // PIR CALIBRATION
    strip.begin();
    setRGBColor(255,255,255);
    calibratePIR();
    setRGBColor(0,0,0);
    
    // INITIAL CHECKUP
    brightnessAlert = checkBrightness();
    tempAlert = checkTemperature();
    soilAlert = checkSoil(); 
    lastUpdate = checkTime();
}

void loop() {
    checkPIR();
    if (pirState == HIGH){
    analogWrite(ledPin, HIGH);
    setRGBColor(0,0,255);
    delay(100);
    } else {
    analogWrite(ledPin, LOW);
    setRGBColor(255,0,0);
    }
}

// MAIN FEEDBACK FUNCTION

void main() {
    
    
}

// TEMPERATURE SENSOR

double checkTemperature() {
    delay(10);
    int reading = analogRead(tempPin);
    double voltage = (reading * 3.3) / 4095.0;
    temperature = (voltage - 0.5) * 100;
    temperatureF = ((temperature * 9.0) / 5.0) + 32.0;
    delay(10);
    return temperature;
}

bool setTempAlert(int min, int max){
    double tF = int(checkTemperature());
    if(tF > max || tF < min){
        return true; 
    } else
    {
        return false;
    }
}

// PHOTOCELL FUNCTIONS

int checkBrightness() {
    delay(10);
    photoCellReading = analogRead(photoCellPin);
    ledBrightness = map(photoCellReading, 0, 4095, 0, 255);
    delay(10);
    return ledBrightness;
}

bool setBrightnessAlert(int min){
    int b = checkBrightness();
    int t = Time.hour();
    if(b < min && (t < 18 || t > 8)){
        return true;
    } else 
    {
        return false;
    }
}

// SOIL MOISTURE SENSOR FUNCTIONS

int checkSoil() {
    digitalWrite(soilPower, HIGH);
    delay(10);
    soilReading = analogRead(soilPin);
    digitalWrite(soilPower, LOW);
    delay(10);
    return soilReading;
}

bool setSoilAlert(int min, int max){
    int s = checkSoil();
    if(s > max || s < min){
        return true;
    } else 
    {
        return false;
    }
}

// PIR FUNCTIONS

bool checkPIR() {
    pirVal = digitalRead(pirPin);
    if (pirVal == HIGH) {
        if(pirState == LOW) {
            pirState = HIGH;
        }
    return true;   
    } else 
    {
    if (pirState == HIGH) {
        pirState = LOW;
    } 
    return false;    
    }
}

void calibratePIR(){
    for(int i = 0; i < pirCalibrationTime; i++){
    delay(1000);
    }
}

// NEOPIXEL FUNCTIONS

void setRGBColor( int r, int g, int b ){
    redValue = r;
    greenValue = g;
    blueValue = b;
    strip.setPixelColor(0, redValue, greenValue, blueValue);
    strip.show();
}

void flashRGBColor(int r, int g, int b, int dly, int rep){
    for (int i = 0; i<rep; i++) {
        setRGBColor(r,g,b);
        delay(dly);
        setRGBColor(0,0,0);
        delay(dly/2);
    }
    setRGBColor(0,0,0);
}
   
// TIME FUNCTINOS

unsigned int checkTime() {
    return Time.now();
}

bool tDifference(unsigned int a, unsigned int b, unsigned int d) {
    if (a>b) {
          unsigned int c = a-b;  
        if(c>=d) {
            return true;
            } else {
                return false; 
            }
        } else {
            return false;
    }
}
    
