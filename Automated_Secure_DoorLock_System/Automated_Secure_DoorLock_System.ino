#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>
#define pos_ini 0
#define pos_ini1 0
#define pos_ini2 0
#define pos_ini3 0
#define pos_ini4 0
#define pos_ini5 0
#define SS_PIN 10
#define RST_PIN 9
String UID = "2A FE 96 1A";
String UID1 ="5A 34 E9 80";
String UID2 ="3E FE 90 50";
String UID3 ="BE D7 24 50";
String UID4 ="8E ED 56 50";
String UID5 ="30 83 A7 1F";
byte lock = 0;
int c=1;
Servo servo;
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
LiquidCrystal_I2C lcd(0x27, 16, 2);
MFRC522 rfid(SS_PIN, RST_PIN);
void setup() {
  Serial.begin(9600);
  servo.write(pos_ini);
  servo1.write(pos_ini1);
  servo2.write(pos_ini2);
  servo3.write(pos_ini3);
  servo4.write(pos_ini4);
  servo5.write(pos_ini5);
  lcd.init();
  lcd.backlight();
  servo.attach(3);
  servo1.attach(4);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(7);
  servo5.attach(8);
  SPI.begin();
  rfid.PCD_Init();
}

void loop() {
  lcd.setCursor(4, 0);
  lcd.print("Welcome!");
  lcd.setCursor(1, 1);
  lcd.print("place your card");

  if ( ! rfid.PICC_IsNewCardPresent())
    return;
  if ( ! rfid.PICC_ReadCardSerial())
    return;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scanning...");
  Serial.print("NUID tag is :");
  String ID = "";
  for (int i = 0; i < rfid.uid.size; i++) {
    lcd.print(".");
    ID.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
    ID.concat(String(rfid.uid.uidByte[i], HEX));
    delay(300);
  }
  ID.toUpperCase();
 if (ID.substring(1) == UID && lock == 1 )
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door is open");
    delay(1500);
    for(int pos=90;pos>=0;pos--)
    {
    servo.write(pos);
      delay(10);
      }
    lcd.clear();
    lock = 0;
  }
   else if (ID.substring(1) == UID && lock == 0 ) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door is locked");
    delay(1500);
    for(int pos=0;pos<=90;pos++){
    servo.write(pos);
    delay(10);
}
    lcd.clear();
    lock = 1;
  }
    else if (ID.substring(1) == UID1 && lock == 1 ) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door is open");
    delay(1500);
   for(int pos=90;pos>=0;pos--)
   {
    servo1.write(pos);
    delay(10);
   }
    lcd.clear();
    lock = 0;
  }
   else if (ID.substring(1) == UID1 && lock == 0) {
   
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door is locked");
    delay(1500);
    lcd.clear();
    lock = 1;
    for(int pos=0;pos<=90;pos++){
    servo1.write(pos);
    delay(10);
    }
    lcd.clear();
    lock = 1;
   }
    else if (ID.substring(1) == UID2 && lock == 1 ) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door is open");
    delay(1500);
   for(int pos=90;pos>=0;pos--)
   {
    servo2.write(pos);
    delay(10);
   }
    lcd.clear();
    lock = 0;
  }
   else if (ID.substring(1) == UID2 && lock == 0) {
   
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door is locked");
    delay(1500);
    lcd.clear();
    lock = 1;
    for(int pos=0;pos<=90;pos++){
    servo2.write(pos);
    delay(10);
    }
    lcd.clear();
    lock = 1;
   }
   else if (ID.substring(1) == UID3 && lock == 1 ) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door is open");
    delay(1500);
   for(int pos=90;pos>=0;pos--)
   {
    servo3.write(pos);
    delay(10);
   }
    lcd.clear();
    lock = 0;
  }
   else if (ID.substring(1) == UID3 && lock == 0) {
   
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door is locked");
    delay(1500);
    lcd.clear();
    lock = 1;
    for(int pos=0;pos<=90;pos++){
    servo3.write(pos);
    delay(10);
    }
    lcd.clear();
    lock = 1;
   }
    else if (ID.substring(1) == UID4 && lock == 1 ) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door is open");
    delay(1500);
   for(int pos=90;pos>=0;pos--)
   {
    servo4.write(pos);
    delay(10);
   }
    lcd.clear();
    lock = 0;
  }
   else if (ID.substring(1) == UID4 && lock == 0) {
   
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door is locked");
    delay(1500);
    lcd.clear();
    lock = 1;
    for(int pos=0;pos<=90;pos++){
    servo4.write(pos);
    delay(10);
    }
    lcd.clear();
    lock = 1;
   }
   else if (ID.substring(1) == UID5 && lock == 1 ) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door is open");
    delay(1500);
   for(int pos=90;pos>=0;pos--)
   {
    servo5.write(pos);
    delay(10);
   }
    lcd.clear();
    lock = 0;
  }
   else if (ID.substring(1) == UID5 && lock == 0) {
   
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door is locked");
    delay(1500);
    lcd.clear();
    lock = 1;
    for(int pos=0;pos<=90;pos++){
    servo5.write(pos);
    delay(10);
    }
    lcd.clear();
    lock = 1;
   }
    else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Wrong card!");
    delay(1500);
    lcd.clear();
  }
}
