#include <Arduboy2.h>

Arduboy2 arduboy;

void setup() {

  arduboy.boot();
  pinMode(5, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(5, LOW);
  digitalWrite(13, LOW);
  
  arduboy.setFrameRate(30);
  arduboy.setCursor(43,28);

  beepboop();
}

int brightness = 230;

void loop() {

  if (!(arduboy.nextFrame()))
    return;
  arduboy.clear();

  if( arduboy.pressed(A_BUTTON) || arduboy.pressed(B_BUTTON) || arduboy.pressed(UP_BUTTON) || arduboy.pressed(DOWN_BUTTON) || arduboy.pressed(LEFT_BUTTON) || arduboy.pressed(RIGHT_BUTTON)) {

    beepboop();

  }
  arduboy.display();
}


void beepboop() {

  
    arduboy.setCursor(43,28);
    arduboy.write(219);
    arduboy.display();
    delay(100);

    
    
    tone(PIN_SPEAKER_1, 784, 100);
    arduboy.setCursor(43,28);
    arduboy.print("A");
    arduboy.write(219);
    arduboy.display();
    analogWrite(9,brightness);
    delay(100);
    
    tone(PIN_SPEAKER_1, 698, 100);
    arduboy.setCursor(49,28);
    arduboy.print("R");
    arduboy.write(219);
    arduboy.display();
    analogWrite(10,brightness);
    delay(100);
    
    tone(PIN_SPEAKER_1, 587, 100);
    arduboy.setCursor(55,28);
    arduboy.print("D");
    arduboy.write(219);
    arduboy.display();
    digitalWrite(9,1);
    delay(100);
    
    tone(PIN_SPEAKER_1, 698, 100);
    arduboy.setCursor(61,28);
    arduboy.print("U");
    arduboy.write(219);
    arduboy.display();
    analogWrite(11,brightness);
    delay(100);
    
    tone(PIN_SPEAKER_1, 988, 100);
    arduboy.setCursor(67,28);
    arduboy.print("B");
    arduboy.write(219);
    arduboy.display();
    digitalWrite(10,1);
    delay(100);
    
    tone(PIN_SPEAKER_1, 784, 100);
    arduboy.setCursor(73,28);
    arduboy.print("O");
    arduboy.write(219);
    arduboy.display();
    analogWrite(9,brightness);
    delay(100);
    
    tone(PIN_SPEAKER_1, 1047, 100);
    digitalWrite(9,1);
    digitalWrite(11,1);
    
    for(int i=0;i<4;i++){
      
      arduboy.setCursor(43,28);
      arduboy.print("ARDUBOY");
      arduboy.write(219);
      arduboy.display();
      delay(200);
      
      arduboy.clear();
      arduboy.setCursor(43,28);
      arduboy.print("ARDUBOY");
      arduboy.display();
      delay(200);
      
    }


}



