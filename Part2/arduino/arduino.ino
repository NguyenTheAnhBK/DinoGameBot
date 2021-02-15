float threshold = 1010;
int servo_pin = 11, cycle = 0, angle = 90;
unsigned long last = 0; // lưu ý phải để kiểu unsigned long, trước để int chạy một lúc bị tràn làm servo nhảy rất nhanh
float current_value = 0;

void setup() {
  Serial.begin(9600);
  //Serial.println("Dino Game");  
}

void loop() {
  if(cycle == 150)
  {
    current_value = current_value / cycle;
    Serial.print("A0: ");
    Serial.println(current_value);
    
    current_value = 0;
    cycle = 0;
  }
  
  cycle++;
  current_value += analogRead(A0);
}
