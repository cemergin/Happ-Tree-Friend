//frameObject Definition & Functions
typedef struct {
    int index; // 0 = TOP, 1 = RIGHT, 2 = BOTTOM, 3 = LEFT
    int colors[4]; //R,G,B,Brightness
    long pressed[3]; //Last, Red, Blue
    bool lightOn;// Status
} frameObject;
frameObject fObj[4];
int frames = 4;

frameObject initializeFrameObject(int i) {
    frameObject a = {
        .index = i,
        .colors = {0,0,0,0}, //R,G,B,Brightness
        .pressed = {millis(),millis(),millis()}, //Last, Red, Blue
        .lightOn = false
    };
    return a;
}
frameObject setColors(frameObject a, int r, int g, int b, int brightness) {
    a.colors[0] = r;
    a.colors[1] = g;
    a.colors[2] = b;
    a.colors[3] = brightness;
    return a;
}
frameObject setPressed(frameObject a, long last, long red, long blue) {
    a.pressed[0] = last;
    a.pressed[1] = red;
    a.pressed[2] = blue;
    return a;
}
frameObject setLightOn(frameObject a, bool b) {
    a.lightOn= b;
    return a;
}