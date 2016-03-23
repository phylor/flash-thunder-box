int ledPin = 13;
int buttonApin = 8;

int segmentA = A4; // pin 11
int segmentB = A0; // pin 7
int segmentC = 5; // pin 4
int segmentD = 3; // pin 2
int segmentE = 2; // pin 1
int segmentF = A3; // pin 10
int segmentG = 6; // pin 5
int segmentDp = 4; // pin 3
int digit1 = A5; // pin 12
int digit2 = A2; // pin 9
int digit3 = A1; // pin 8
int digit4 = 7; // pin 6

int delayForNextDigit = 2;
int delayBetweenRefresh = 50;

void clearDisplay();
void zero();
void one();
void two();
void three();
void four();
void five();
void six();
void seven();
void eight();
void nine();
void ten();
void setDigit(int);
void testSegment(int);
void loading();
void displayDigit(int);
void calculateNumber(int);
void displayNumber();

void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT);  

  pinMode(segmentA, OUTPUT);
  pinMode(segmentB, OUTPUT);
  pinMode(segmentC, OUTPUT);
  pinMode(segmentD, OUTPUT);
  pinMode(segmentE, OUTPUT);
  pinMode(segmentF, OUTPUT);
  pinMode(segmentG, OUTPUT);
  pinMode(segmentDp, OUTPUT);

  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);
  pinMode(digit4, OUTPUT);
  
  Serial.begin(9600);
}
 
int lastButtonState = 0;
bool isPressed = false;
int ledState = 0;
bool timeRunning = false;
int firstDigit = 0, secondDigit = 0, thirdDigit = 0, fourthDigit = 0;
bool decimalPoint = false;

void buttonToggled();

void loop() 
{
  int buttonState = digitalRead(buttonApin);

  if(buttonState != lastButtonState) {
    if(buttonState == HIGH) {
      digitalWrite(ledPin, LOW);
      isPressed = true;
    }
    else {
      digitalWrite(ledPin, HIGH);
      if(isPressed) {
        ledState = ledState == HIGH ? LOW : HIGH;
        digitalWrite(ledPin, ledState);

        isPressed = false;
        buttonToggled();
      }
    }
  }

  lastButtonState = buttonState;

  if(firstDigit + secondDigit + thirdDigit + fourthDigit > 0) {
    displayNumber();
    delayMicroseconds(delayBetweenRefresh);
  }
  else
    clearDisplay();
}

void clearDisplay() {
  digitalWrite(segmentA, LOW);
  digitalWrite(segmentB, LOW);
  digitalWrite(segmentC, LOW);
  digitalWrite(segmentD, LOW);
  digitalWrite(segmentE, LOW);
  digitalWrite(segmentF, LOW);
  digitalWrite(segmentG, LOW);
  digitalWrite(segmentDp, LOW);

  digitalWrite(digit1, LOW);
  digitalWrite(digit2, LOW);
  digitalWrite(digit3, LOW);
  digitalWrite(digit4, LOW);
}

void zero() {
  digitalWrite(segmentA, HIGH);
  digitalWrite(segmentB, HIGH);
  digitalWrite(segmentC, HIGH);
  digitalWrite(segmentD, HIGH);
  digitalWrite(segmentE, HIGH);
  digitalWrite(segmentF, HIGH);
  digitalWrite(segmentG, LOW);
  digitalWrite(segmentDp, LOW);
}

void one() {
  digitalWrite(segmentA, LOW);
  digitalWrite(segmentB, HIGH);
  digitalWrite(segmentC, HIGH);
  digitalWrite(segmentD, LOW);
  digitalWrite(segmentE, LOW);
  digitalWrite(segmentF, LOW);
  digitalWrite(segmentG, LOW);
  digitalWrite(segmentDp, LOW);
}

void two() {
  digitalWrite(segmentA, HIGH);
  digitalWrite(segmentB, HIGH);
  digitalWrite(segmentC, LOW);
  digitalWrite(segmentD, HIGH);
  digitalWrite(segmentE, HIGH);
  digitalWrite(segmentF, LOW);
  digitalWrite(segmentG, HIGH);
  digitalWrite(segmentDp, LOW);
}

void three() {
  digitalWrite(segmentA, HIGH);
  digitalWrite(segmentB, HIGH);
  digitalWrite(segmentC, HIGH);
  digitalWrite(segmentD, HIGH);
  digitalWrite(segmentE, LOW);
  digitalWrite(segmentF, LOW);
  digitalWrite(segmentG, HIGH);
  digitalWrite(segmentDp, LOW);
}

void four() {
  digitalWrite(segmentA, LOW);
  digitalWrite(segmentB, HIGH);
  digitalWrite(segmentC, HIGH);
  digitalWrite(segmentD, LOW);
  digitalWrite(segmentE, LOW);
  digitalWrite(segmentF, HIGH);
  digitalWrite(segmentG, HIGH);
  digitalWrite(segmentDp, LOW);
}

void five() {
  digitalWrite(segmentA, HIGH);
  digitalWrite(segmentB, LOW);
  digitalWrite(segmentC, HIGH);
  digitalWrite(segmentD, HIGH);
  digitalWrite(segmentE, LOW);
  digitalWrite(segmentF, HIGH);
  digitalWrite(segmentG, HIGH);
  digitalWrite(segmentDp, LOW);
}

void six() {
  digitalWrite(segmentA, HIGH);
  digitalWrite(segmentB, LOW);
  digitalWrite(segmentC, HIGH);
  digitalWrite(segmentD, HIGH);
  digitalWrite(segmentE, HIGH);
  digitalWrite(segmentF, HIGH);
  digitalWrite(segmentG, HIGH);
  digitalWrite(segmentDp, LOW);
}

void seven() {
  digitalWrite(segmentA, HIGH);
  digitalWrite(segmentB, HIGH);
  digitalWrite(segmentC, HIGH);
  digitalWrite(segmentD, LOW);
  digitalWrite(segmentE, LOW);
  digitalWrite(segmentF, LOW);
  digitalWrite(segmentG, LOW);
  digitalWrite(segmentDp, LOW);
}

void eight() {
  digitalWrite(segmentA, HIGH);
  digitalWrite(segmentB, HIGH);
  digitalWrite(segmentC, HIGH);
  digitalWrite(segmentD, HIGH);
  digitalWrite(segmentE, HIGH);
  digitalWrite(segmentF, HIGH);
  digitalWrite(segmentG, HIGH);
  digitalWrite(segmentDp, LOW);
}

void nine() {
  digitalWrite(segmentA, HIGH);
  digitalWrite(segmentB, HIGH);
  digitalWrite(segmentC, HIGH);
  digitalWrite(segmentD, HIGH);
  digitalWrite(segmentE, LOW);
  digitalWrite(segmentF, HIGH);
  digitalWrite(segmentG, HIGH);
  digitalWrite(segmentDp, LOW);
}

void setDigit(int digit) {
  digitalWrite(digit1, digit == 1 ? LOW : HIGH);
  digitalWrite(digit2, digit == 2 ? LOW : HIGH);
  digitalWrite(digit3, digit == 3 ? LOW : HIGH);
  digitalWrite(digit4, digit == 4 ? LOW : HIGH);
}

void testSegment(int segment) {
  digitalWrite(segmentA, segment == 1 ? HIGH : LOW);
  digitalWrite(segmentB, segment == 2 ? HIGH : LOW);
  digitalWrite(segmentC, segment == 3 ? HIGH : LOW);
  digitalWrite(segmentD, segment == 4 ? HIGH : LOW);
  digitalWrite(segmentE, segment == 5 ? HIGH : LOW);
  digitalWrite(segmentF, segment == 6 ? HIGH : LOW);
  digitalWrite(segmentG, segment == 7 ? HIGH : LOW);
  digitalWrite(segmentDp, segment == 8 ? HIGH : LOW);
}

void loading() {
  int i;
  for(i = 1; i <= 6; ++i) {
    testSegment(i);
    delay(500);
  }
}

void displayDigit(int digit) {
  switch(digit) {
    case 0: zero(); break;
    case 1: one(); break;
    case 2: two(); break;
    case 3: three(); break;
    case 4: four(); break;
    case 5: five(); break;
    case 6: six(); break;
    case 7: seven(); break;
    case 8: eight(); break;
    case 9: nine(); break;
  }
}

unsigned long startTime = 0;

void buttonToggled() {
  if(timeRunning) {
    // calculate and display
    float secondsRun = (millis() - startTime) / 1000.;

    int distance = (int) (secondsRun * 340.29 + 0.5);

    timeRunning = false;
    calculateNumber(distance);
  }
  else {
    // start time
    startTime = millis();
    timeRunning = true;
    firstDigit = secondDigit = thirdDigit = fourthDigit = 0;
  }
}

void calculateNumber(int number) {
  Serial.println(number);
  
  if(number > 9999) {
    number /= 100.;
    decimalPoint = true;
  }
  else {
    decimalPoint = false;
  }
  
  firstDigit = number / 1000 % 10;
  secondDigit = number / 100 % 10;
  thirdDigit = number / 10 % 10;
  fourthDigit = number % 10;
}

void displayNumber() {
    if(firstDigit != 0) {
      clearDisplay();
      setDigit(1);
      displayDigit(firstDigit);
      delayMicroseconds(delayForNextDigit);
    }
    
    if(firstDigit != 0 || secondDigit != 0 || thirdDigit != 0) {
      clearDisplay();
      setDigit(3);
      displayDigit(thirdDigit);
      if(decimalPoint)
        digitalWrite(segmentDp, HIGH);
      else
        digitalWrite(segmentDp, LOW);
      delayMicroseconds(delayForNextDigit);
    }
    
    if(firstDigit != 0 || secondDigit != 0) {
      clearDisplay();
      setDigit(2);
      displayDigit(secondDigit);
      delayMicroseconds(delayForNextDigit);
    }
    
    clearDisplay();
    setDigit(4);
    displayDigit(fourthDigit);
    delayMicroseconds(delayForNextDigit);
}

