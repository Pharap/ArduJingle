#include <Arduboy2.h>

Arduboy2 arduboy;

void setup() {

  arduboy.boot();
  arduboy.flashlight();
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

PROGMEM const char logo[] = "ARDUBOY";

PROGMEM const uint16_t logoSounds[] =
{
	784, 880, 587, 698, 988, 698, 988, 784
};

const uint8_t boxCharacter = 219;
const uint8_t logoLength = 7;
const uint8_t charWidth = 5;
const uint8_t charHeight = 8;
const uint8_t logoX = 43;
const uint8_t logoY = 28;
const uint8_t logoEndX = logoX + (logoLength * (charWidth + 1));
const uint8_t logoEndY = logoY;

void beepboop()
{  
    arduboy.setCursor(logoX, logoY);
    arduboy.write(boxCharacter);
    
    arduboy.display();
    delay(100);

	for(uint8_t i = 0, x = logoX; i < logoLength; ++i, x += 6)
	{
		const uint16_t sound = pgm_read_byte(&(logoSounds[i]));
		tone(PIN_SPEAKER_1, sound, 100);
		
    	arduboy.setCursor(x, logoY);
    	
    	const char c = (char)pgm_read_byte(&(logo[i]));
	    arduboy.print(c);
	    arduboy.write(boxCharacter);
	    
	    arduboy.display();	    
	    delay(100);
	}
    
    tone(PIN_SPEAKER_1, 1047, 100);

	{
	    bool toggle = false;
	    for(uint8_t i = 0; i < 8; ++i)
	    {
	    	toggle = !toggle;
	    	if(toggle)
	    	{
				arduboy.setCursor(logoEndX, logoEndY);
				arduboy.write(boxCharacter);	 
	    	}
	    	else
	    	{
				arduboy.fillRect(logoEndX, logoEndY, charWidth, charHeight, BLACK);   		
	    	}
	    	
			arduboy.display();
			delay(200); 
	    }
	}
}
