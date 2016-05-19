/*
  High Low game
*/

#include <Arduboy.h>

Arduboy arduboy;

byte x;
byte y;
long oldRand;
long newRand;
int points;

void setup() {

  arduboy.begin();

  arduboy.setFrameRate(10);

  /*Serial.begin(9600);*/

  x=0;
  y=0;
  points = 0;
  randomSeed(999);
  oldRand = random(1,101);
  newRand = random(1,101);

  arduboy.clear();

  x=0;
  arduboy.setCursor(x, y);
  arduboy.print(oldRand);

  x=40;
  arduboy.setCursor(x, y);
  arduboy.print(points);

  arduboy.display();

}

void loop() {

  if (!(arduboy.nextFrame())) {
    return;
  }

  if(arduboy.pressed(UP_BUTTON)) {
  delay(100);
  x=20;
  arduboy.setCursor(x, y);
  arduboy.print(newRand);
  if(newRand>oldRand) {
    points++;
  } else {
    points=0;
    x=60;
    arduboy.setCursor(x,y);
    arduboy.print("YOU LOSE");
    arduboy.display();
  }

  x=40;
  arduboy.setCursor(x, y);
  arduboy.print(points);

  arduboy.display();
  delay(2000);

  oldRand=newRand;
  newRand = random(1,101);

  arduboy.clear();

  x=0;
  arduboy.setCursor(x, y);
  arduboy.print(oldRand);

  x=40;
  arduboy.setCursor(x, y);
  arduboy.print(points);

  arduboy.display();
  }

  if(arduboy.pressed(DOWN_BUTTON)) {
    delay(100);
    x=20;
    arduboy.setCursor(x, y);
    arduboy.print(newRand);
    if(newRand<oldRand) {
      points++;
    } else {
      points=0;
      x=60;
      arduboy.setCursor(x,y);
      arduboy.print("YOU LOSE");
      arduboy.display();
    }

    x=40;
    arduboy.setCursor(x, y);
    arduboy.print(points);

    arduboy.display();
    delay(2000);

    oldRand=newRand;
    newRand = random(1,101);

    arduboy.clear();

    x=0;
    arduboy.setCursor(x, y);
    arduboy.print(oldRand);

    x=40;
    arduboy.setCursor(x, y);
    arduboy.print(points);

    arduboy.display();
  }

}
