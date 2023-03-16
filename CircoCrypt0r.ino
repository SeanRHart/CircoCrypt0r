//Sean Hart, March 14, 2023, Microcontroller Project


#include <IRremote.hpp>
#include <Servo.h>
#include <LiquidCrystal.h>

Servo servo; //init servo object

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //initializes LCD object w/ pins

IRrecv rawIR(9); //sets IR pin                                          
decode_results irSignal; //variable for decoded signal

int rawJoyst;

int servAngle;

char chars[26] = "abcdefghijklmnopqrstuvwxyz"; //characters to pull from

void setup() {
  lcd.begin(16, 2); //begins LCD object

  rawIR.enableIRIn();
  
  lcd.setCursor(0,0); //Cute display sequence
  lcd.print("CircoCrypt0r");
  lcd.setCursor(0,1);
  lcd.print("By Sean Hart");
  
  pinMode(A0, INPUT); //connect joystick
  servo.attach(13); //set servo to pin

  Serial.begin(9600);
}

void loop() {
  // Joystick to Servo code largely from instructables
  rawJoyst = analogRead(A0);
  servAngle = map(rawJoyst, 0, 1023, 0, 180);
  servo.write(servAngle);
  //end Joystick to Servo code
  
  //IRremote documentation
  if (rawIR.decode(&irSignal)) {
    if (irSignal.value == 0xFFFFFFFF) {
      int seed = servAngle ^ 3;
      encrypt(seed);
    }
    rawIR.resume();
  }
  delay(200);

 
}

void encrypt(int seed) {
  randomSeed(seed);
  
  lcd.setCursor(0,0); //empty display
  lcd.print("             ");
  lcd.setCursor(0,1);
  lcd.print("             ");
  lcd.setCursor(0,0);

  for (int i = 0; i <= 25; i++) {
    delay(100);
    int psRand1 = random(0,25); //three digits for each letter in cipher
    int psRand2 = random(0,25);
    int psRand3 = random(0,25);
    lcd.setCursor(0,0);
    lcd.print(chars[i]);
    lcd.print(": ");
    lcd.print(chars[psRand1]);
    lcd.print(chars[psRand2]);
    lcd.print(chars[psRand3]);
    delay(1500);
    lcd.setCursor(0,0);
    lcd.print("              ");
  }
  
}
