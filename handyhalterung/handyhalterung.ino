#include<BleKeyboard.h>

BleKeyboard bleKeyboard;
bool isPressed;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(32, OUTPUT);

  bleKeyboard.setName("Nshuti");
  bleKeyboard.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(bleKeyboard.isConnected()){
  
  int touchVal = touchRead(T6);
  int touchVal2 = touchRead(T8);
  int touchVal3 = touchRead(T7);

  
  if(touchVal <= 40 && isPressed==false){
     Serial.println(touchVal);
     //bleKeyboard.print("A");
     bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
     delay(100);
     digitalWrite(13, HIGH);
     isPressed=true;
     }


  if(touchVal2 <= 40 && isPressed==false){
     Serial.println(touchVal2);
     //bleKeyboard.print("A");
     bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
     delay(100);
     digitalWrite(32, HIGH);
     isPressed=true;
     } 
     

  if(touchVal3 <= 50 && isPressed == false){
     Serial.println(touchVal);
     //bleKeyboard.print("A");
     bleKeyboard.write(KEY_MEDIA_MUTE);
     isPressed=true;
     }
     
  if(touchVal>50 && touchVal2 > 40 && touchVal3 > 50){
    isPressed=false;  
    }
  
} 
}

/**
#include<BleKeyboard.h>

BleKeyboard bleKeyboard;
bool isPressed;
bool isPressed2;
bool isPressed3;

const int SHORT_PRESS_TIME = 500; // 1000 milliseconds

unsigned long pressedTime  = 0;
unsigned long releasedTime = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);

  
  pinMode(32, OUTPUT);
