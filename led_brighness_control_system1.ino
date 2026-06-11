// Variable declarations
String mes = "MENU Options\n on\n off\n max\n min\n percent\n brightness\n";
String ip = "";
float curbri=0.0;
int ledpin = 6;
int potpin = A5;
int potval;
float per;
float ledval;

void setup() {
  pinMode(ledpin, OUTPUT);
  pinMode(potpin, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  // Display menu and wait for user input
  Serial.println(mes);
  while (Serial.available() == 0) {}
  ip = Serial.readString();
  ip.trim();

  // Brightness (0-255) to percentage calculation
  per = (100.0 / 255.0) * curbri;
  
// Process the user's menu selection  
  if (ip == "on") {
    curbri=255;
    analogWrite(ledpin, 255);
  }
  else if (ip == "off") {
    curbri=0;
    analogWrite(ledpin, 0);
  }
  else if (ip == "max") {
    curbri=255;
    analogWrite(ledpin, 255);
  }
  else if (ip == "min") {
    curbri=10;
    analogWrite(ledpin, 10);
  }
  else if (ip == "percent") {
    delay(100);
    Serial.print(per);
    Serial.println("%");
    Serial.print("\n");
    delay(100);
  }

  else if (ip == "brightness"){
  // Allow brightness control using the potentiometer
  Serial.println("Turn knob to adjust brightness. To exit, enter any key.");
  while (Serial.available() == 0) {
    // Read potentiometer value and map it to PWM brightness
    potval = analogRead(potpin);
    ledval = (255.0 / 1023.0) * potval;
    curbri=ledval;
    analogWrite(ledpin, ledval);
  }
    
  // Clear the exit character from the serial buffer
  Serial.readString(); 
 }
}