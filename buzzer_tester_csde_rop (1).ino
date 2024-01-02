//Red 1
const int button1Pin = 3;     // the number of the pushbutton pin
const int led1Pin = 9;        // the number of the LED pin

//Red 2
const int button2Pin = 12;     // the number of the pushbutton pin
const int led2Pin = 13;       // the number of the LED pin

//Red3
const int button3Pin = 5;     // the number of the pushbutton pin
const int led3Pin = 10;       // the number of the LED pin

//Red 4
const int button4Pin = 7;     // the number of the pushbutton pin
const int led4Pin = 11;       // the number of the LED pin

//Blue 1
const int button5Pin = 23;     // the number of the pushbutton pin
const int led5Pin = 53;       // the number of the LED pin

//Blue 2
const int button6Pin = 52;     // the number of the pushbutton pin
const int led6Pin = 8;       // the number of the LED pin
const int resetbuttonPin = 46;
const int speakerPin = 50;

int bluetone = 400;
int redtone = 400;

// variables will change:
int button1State = 0;         // variable for reading the pushbutton status
int led1State = 0;          // variable for holding the LED state
int button2State = 0;
int led2State = 0;
int button3State = 0;
int led3State = 0;
int button4State = 0;
int led4State = 0;
int button5State = 0;
int led5State = 0;
int button6State = 0;
int led6State = 0;
int resetbuttonState = 0;
int speakerState = 0;

int speakerDuration = 300;

bool pressed = false;

void setup() {
  pinMode(led1Pin, OUTPUT);      // initialize LED as an output
  pinMode(button1Pin, INPUT);    // initialize pushbutton as an input
  pinMode(led2Pin, OUTPUT);      // initialize LED as an output
  pinMode(button2Pin, INPUT);    // initialize pushbutton as an input
  pinMode(led3Pin, OUTPUT);      // initialize LED as an output
  pinMode(button3Pin, INPUT);    // initialize pushbutton as an input
  pinMode(led4Pin, OUTPUT);      // initialize LED as an output
  pinMode(button4Pin, INPUT);    // initialize pushbutton as an input
  pinMode(led5Pin, OUTPUT);      // initialize LED as an output
  pinMode(button5Pin, INPUT);    // initialize pushbutton as an input
  pinMode(led6Pin, OUTPUT);      // initialize LED as an output
  pinMode(button6Pin, INPUT);    // initialize pushbutton as an input
  pinMode(resetbuttonPin, INPUT); 
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);
}

void printButtonStates() {
  Serial.print("pressed=");
  Serial.print(pressed);
  Serial.print(", b1=");
  Serial.print(button1State);  
  Serial.print(", b2=");
  Serial.print(button2State);  
  Serial.print(", b3=");
  Serial.print(button3State);  
  Serial.print(", b4=");
  Serial.print(button4State);  
  Serial.print(", b5=");
  Serial.print(button5State);  
  Serial.print(", b6=");
  Serial.print(button6State);  
  Serial.print(", reset=");
  Serial.println(resetbuttonState);
}

void loop() {

  
  button1State = digitalRead(button1Pin);   // read the state of the pushbutton
  Serial.print("pressed = ");
  Serial.print(pressed);
  if (button1State == HIGH && pressed == false) {              // check if pushbutton is pressed
   if (led1State == LOW) {                // check if LED is off
      led1State = HIGH;                    // turn LED on
      pressed = true;
      tone(speakerPin, bluetone, speakerDuration);
    }
  }
  
  //led2 and button2
  
   button2State = digitalRead(button2Pin);   // read the state of the pushbutton
  if (button2State == HIGH  && pressed == false) {              // check if pushbutton is pressed
    if (led2State == LOW) {                // check if LED is off
      led2State = HIGH;                    // turn LED on
      pressed = true;
      tone(speakerPin, bluetone, speakerDuration);
    }
  }

  //led3 and button3
  
  button3State = digitalRead(button3Pin);   // read the state of the pushbutton
  Serial.print(", button3State = ");
  Serial.print(button3State);
  if (button3State == HIGH && pressed == false) {              // check if pushbutton is pressed
    if (led3State == LOW) {                // check if LED is off
      led3State = HIGH;                    // turn LED on
      pressed = true;
      tone(speakerPin, bluetone, speakerDuration);
    }
  }

  //led 4 and button 4
  
  button4State = digitalRead(button4Pin);   // read the state of the pushbutton
  //button4State = HIGH;

  if (button4State == HIGH && pressed == false) {              // check if pushbutton is pressed
    if (led4State == LOW) {                // check if LED is off
      led4State = HIGH;                    // turn LED on
      pressed = true;
      tone(speakerPin, redtone, speakerDuration);
    }
  }
  
  //led 5 and button 5
  
  button5State = digitalRead(button5Pin);   // read the state of the pushbutton

  if (button5State == HIGH && pressed == false) {              // check if pushbutton is pressed
    if (led5State == LOW) {                // check if LED is off
      led5State = HIGH;                    // turn LED on
      pressed = true;
      tone(speakerPin, redtone, speakerDuration);
    }
  }

   button6State = digitalRead(button6Pin);   // read the state of the pushbutton
  if (button6State == HIGH && pressed == false) {              // check if pushbutton is pressed
    if (led6State == LOW) {                // check if LED is off
      led6State = HIGH;                    // turn LED on
      pressed = true;
      tone(speakerPin, redtone, speakerDuration);
    }
  }
  
  resetbuttonState = digitalRead(resetbuttonPin);
  printButtonStates();
  int otherButtonsState = button1State || button2State || button3State || button4State || button5State || button6State;
  if (resetbuttonState == HIGH && otherButtonsState == LOW) {
  //if (resetbuttonState == HIGH) {
    led1State = LOW;
    led2State = LOW;
    led3State = LOW;
    led4State = LOW;
    led5State = LOW;
    led6State = LOW;
    pressed = false;
  }
  digitalWrite(led1Pin, led1State); // update LED state
  digitalWrite(led2Pin, led2State); // update LED state
  digitalWrite(led3Pin, led3State); // update LED state
  digitalWrite(led4Pin, led4State); // update LED state
  digitalWrite(led5Pin, led5State); // update LED state
  digitalWrite(led6Pin, led6State); // update LED state
  
 
}
