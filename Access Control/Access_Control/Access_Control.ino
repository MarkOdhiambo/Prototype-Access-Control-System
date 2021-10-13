// C++ code
//
#include <Key.h>
#include <Keypad.h>
//#include <LiquidCrystal.h>
//Lcd code
//const int rs = 11, en = 10, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Keypad code
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}, 
  };

byte colPins[ROWS] = {33,32,35,34}; // connect to the row pinouts
byte rowPins[ROWS] = {12,14,26,25}; // connect to the column pinouts

char password[]="12345";
Keypad keypad = Keypad (makeKeymap(keys), rowPins, colPins, ROWS, COLS);
void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  //lcd.begin(16, 2);
  //lcd.print("Password: ");
  pinMode(23,OUTPUT);//RED
  pinMode(22,OUTPUT);//YELLOW
}
int att=0;
int trial=3;
int corr=0;
void loop() {
  //lcd.setCursor(0, 1);
  //lcd.print(millis() / 1000);
  //put your main code here, to run repeatedly:
  //char pw[]="";;
  char key = keypad.getKey();
  if(key){
    //lcd.print(key);
    if(password[att]==key){
      digitalWrite(23,HIGH);
        delay(500);
        digitalWrite(23,LOW);
        corr++;
    }else if(password[att]!=key){
      digitalWrite(22,HIGH);
        delay(500);
        digitalWrite(22,LOW);
    }
    att++;
  }
  if(att==5){
    if(corr==5){
        digitalWrite(23,HIGH);
        delay(10000);
        digitalWrite(23,LOW);
      //lcd.print("Enter");
    }else{
        digitalWrite(22,HIGH);
        delay(10000);
        digitalWrite(22,LOW);
      //lcd.print("TRIAL:"+trial);
    }
  }
  //if(key){
    //Serial.println(key);
    //lcd.print(key);
  //}
}
