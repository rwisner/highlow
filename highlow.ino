/*
  High Low Game

  Using the up and down arrows choose whether the next random number
  is going to be higher or lower then the previous number

  https://github.com/rwisner/highlow
  rwisner@gmail.com
*/

#include <Arduboy.h>

Arduboy arduboy;

byte x;
byte y;
long oldRand;
long newRand;
int currScore;
int highScore;

void drawTable() {
  arduboy.clear();
  arduboy.drawRect(0,0,128,64,1);
  arduboy.drawLine(50,0,50,64,1);
  arduboy.drawLine(100,0,100,64,1);
  arduboy.drawLine(100,32,128,32,1);
  arduboy.display();
}

void drawQuestion() {
  arduboy.setTextSize(2);
  x = 16; y = 27;
  arduboy.setCursor(x, y);
  arduboy.print(oldRand);
}

void drawAnswer() {
  arduboy.setTextSize(2);
  x = 66; y = 27;
  arduboy.setCursor(x, y);
  arduboy.print(newRand);
}

void drawHighOrLow() {
  arduboy.setTextSize(1);
  x = 65; y = 20;
  arduboy.setCursor(x, y);
  arduboy.print("High");
  x = 65; y = 30;
  arduboy.setCursor(x, y);
  arduboy.print("or");
  x = 65; y = 40;
  arduboy.setCursor(x, y);
  arduboy.print("Low?");
}

void drawScores() {
  arduboy.setTextSize(1);
  x = 112; y = 14;
  arduboy.setCursor(x, y);
  arduboy.print(currScore);
  x = 112; y = 46;
  arduboy.setCursor(x, y);
  arduboy.print(highScore);
}

void downButton() {
  delay(100);
  arduboy.clear();
  drawTable();
  drawQuestion();
  drawAnswer();
  if (newRand < oldRand) {
    youWin();
  } else {
    youLose();
  }
  drawScores();
  arduboy.display();
  delay(2000);
  oldRand = newRand;
  newRand = random(1,101);
  arduboy.clear();
  drawTable();
  drawQuestion();
  drawHighOrLow();
  drawScores();
  arduboy.display();
}

void upButton() {
  delay(100);
  arduboy.clear();
  drawTable();
  drawQuestion();
  drawAnswer();
  if (newRand > oldRand) {
    youWin();
  } else {
    youLose();
  }
  drawScores();
  arduboy.display();
  delay(2000);
  oldRand = newRand;
  newRand = random(1,101);
  arduboy.clear();
  drawTable();
  drawQuestion();
  drawHighOrLow();
  drawScores();
  arduboy.display();
}

void youWin() {
  arduboy.setTextSize(1);
  x = 56; y = 53;
  arduboy.setCursor(x, y);
  arduboy.print("YOU WIN");
  currScore += 1;
  if (currScore > highScore) {
    highScore = currScore;
  }
}

void youLose() {
  arduboy.setTextSize(1);
  x = 52; y = 53;
  arduboy.setCursor(x, y);
  arduboy.print("YOU LOSE");
  currScore = 0;
}

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(10);
  currScore = 0;
  highScore = 0;
  arduboy.initRandomSeed();
  oldRand = random(1,101);
  newRand = random(1,101);
  arduboy.clear();
  drawTable();
  drawQuestion();
  drawHighOrLow();
  drawScores();
  arduboy.display();
}

void loop() {
  if (!(arduboy.nextFrame())) {
    return;
  }
  if (arduboy.pressed(UP_BUTTON)) {
    upButton();
  }
  if (arduboy.pressed(DOWN_BUTTON)) {
    downButton();
  }
}
