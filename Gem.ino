#include <Adafruit_CircuitPlayground.h>
int presets[2][2][3] = { {{0, 255, 0}, {255, 0, 0}}, {{0, 0, 255}, {128, 128, 0}}
};
int preset = 0;

void setup() {
  Serial.begin(9600); CircuitPlayground.begin();
}
void loop() {
  float total =  abs(CircuitPlayground.motionY()) + abs(CircuitPlayground.motionZ());

  if (total > 13) {
    preset = (preset+1)%3; 

    }
    if (total < 10) {
    for (int i = 0; i < 10; i++) {
      CircuitPlayground.setPixelColor(i, presets[preset][i % 2][0], presets[preset][i % 2][1], presets[preset][i % 2][2]);
      delay(1);
    }

  }
  Serial.println(total);
}

  
  
