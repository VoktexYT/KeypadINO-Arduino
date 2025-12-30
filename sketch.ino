#include <Keypad.h>


// Create a keypad representation
const byte X = 4;
const byte Y = 4;

char keys[X][Y] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte Xpin[X] = {9, 8, 7, 6};
byte Ypin[Y] = {5, 4, 3, 2};

// Create Keypad instance
Keypad keypad = Keypad(makeKeymap(keys), Xpin, Ypin, X, Y);

// default value
char KeyCode[4];
char Password[4] = {'0', '0', '7', '6'};
int i = 0;
int k = 4;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  char keyp = keypad.getKey();

  if (keyp) {

    if (i < 3) {
      KeyCode[i] = keyp;
      i++;
    }
    else {
      KeyCode[i] = keyp;

      for (int j=0; j<4; j++) {
        if (KeyCode[j] == Password[j]) {
          k--;
        }
      }

      if (!k) {
        digitalWrite(13, HIGH);
      }
      else {
        digitalWrite(13, LOW);
      }

      i = 0;
      k = 4;
      KeyCode[0] = 'a';
      KeyCode[1] = 'a';
      KeyCode[2] = 'a';
      KeyCode[3] = 'a';
    }
  }
}
