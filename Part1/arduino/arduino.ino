#include<Servo.h>

float threshold = 1010;
int servo_pin = 11, cycle = 0, angle = 90;
unsigned long last = 0; // lưu ý phải để kiểu unsigned long, trước để int chạy một lúc bị tràn làm servo nhảy rất nhanh
float current_value = 0;
Servo servo;

void setup() {
  Serial.begin(9600);
  Serial.println("Dino Game");  

  servo.attach(servo_pin);
  servo.write(90);
}

void loop() {
  if(cycle == 100)
  {
    current_value = current_value / cycle;
    Serial.print("A0: ");
    Serial.println(current_value);
  
    if(current_value <= threshold)
    {
      if(angle == 60 && millis() - last >= 200)
      {
        angle = 90;
      }
    }
    else
    {
      angle = 60;
      last = millis();
    }
    servo.write(angle);
    
    current_value = 0;
    cycle = 0;
  }
  
  cycle++;
  current_value += analogRead(A0);
}
