#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM math
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int t=0;
int ok=1;
char s;
void image1() {


byte image18[8] = {B00000, B00000, B00000, B10001, B01010, B00100, B00000, B00000};
byte image19[8] = {B01000, B10000, B00000, B00000, B00000, B00000, B00000, B00000};
byte image17[8] = {B00010, B00001, B00000, B00000, B00000, B00000, B00000, B00000};
byte image03[8] = {B00000, B00000, B00000, B10000, B01000, B00100, B00100, B00100};
byte image01[8] = {B00000, B00000, B00000, B00001, B00010, B00100, B00100, B00100};
byte image02[8] = {B00000, B00000, B00000, B10001, B01010, B00100, B00000, B00000};


lcd.createChar(0, image18);
lcd.createChar(1, image19);
lcd.createChar(2, image17);
lcd.createChar(3, image03);
lcd.createChar(4, image01);
lcd.createChar(5, image02);


lcd.setCursor(1, 1);
lcd.write(byte(0));
lcd.setCursor(2, 1);
lcd.write(byte(1));
lcd.setCursor(0, 1);
lcd.write(byte(2));
lcd.setCursor(2, 0);
lcd.write(byte(3));
lcd.setCursor(0, 0);
lcd.write(byte(4));
lcd.setCursor(1, 0);
lcd.write(byte(5));

}

void image2() {


byte image02[8] = {B00000, B00000, B00000, B10001, B01010, B00100, B00000, B00000};
byte image03[8] = {B00000, B00000, B00000, B10000, B01000, B01000, B01000, B10000};
byte image01[8] = {B00000, B00000, B00000, B00001, B00010, B00010, B00010, B00001};
byte image18[8] = {B10001, B00100, B00000, B00000, B00000, B00000, B00000, B00000};


lcd.createChar(0, image02);
lcd.createChar(1, image03);
lcd.createChar(2, image01);
lcd.createChar(3, image18);


lcd.setCursor(1, 0);
lcd.write(byte(0));
lcd.setCursor(2, 0);
lcd.write(byte(1));
lcd.setCursor(0, 0);
lcd.write(byte(2));
lcd.setCursor(1, 1);
lcd.write(byte(3));

}

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT); // setarea pinului analogic A0 ca si pin de input
  pinMode(10,INPUT);
  pinMode(11,INPUT);

  
  lcd.init();
  lcd.clear();
  lcd.backlight();
}

void loop() {
    if(t==0) {
    Serial.write("A\n");
    t++;
    }
    if(t>=1 && t<=24){
    Serial.println(analogRead(A0));
    t++;
    }
    if(t>24) {
      Serial.write("F\n");
      s = Serial.read();
      if(s=='a'){
        lcd.clear();
        lcd.setCursor(4,0);
        lcd.println("Relaxat");
        lcd.setCursor(8,1);
        image1();
      }else if(s=='b'){
        lcd.clear();
        lcd.setCursor(4,0);
        lcd.println("Stresat");
        lcd.setCursor(0,0);
        image2();
      }
      
      t=0;
    }

  delay(100); 

}
