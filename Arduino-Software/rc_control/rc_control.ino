#include<SoftwareSerial.h>

#define AIN1 2

#define AIN2 4

#define BIN1 6

#define BIN2 7



#define LED_1 13

#define LED_2 8

#define RX 10

#define TX 1

char bt = 'S';

SoftwareSerial mySerial(RX, TX);

void setup() {

  pinMode(AIN1, OUTPUT);

  pinMode(BIN1, OUTPUT);

  pinMode(AIN2, OUTPUT);

  pinMode(BIN2, OUTPUT);

  pinMode(LED_1, OUTPUT);

  pinMode(LED_2, OUTPUT);

  mySerial.begin(9600);

  Serial.begin(115200);

}

void loop() {
    
  if (mySerial.available() > 0) {

    Serial.println("Serial available");

    bt = mySerial.read();

    Serial.println(bt);
  }

  switch (bt) {

    case 'F':

      forward();

      break;

    case 'B':

      backward();

      break;

    case 'L':

      left();

      break;

    case 'R':

      right();

      break;

    case 'S':
      short_brake();

      break;

    default:

      break;
      
  }

}

void forward() {

  digitalWrite(LED_1, LOW);   

  digitalWrite(LED_2, LOW);

  digitalWrite(AIN1, LOW);

  digitalWrite(AIN2, HIGH);

  digitalWrite(BIN1, HIGH);

  digitalWrite(BIN2, LOW);

}

void backward() {

  digitalWrite(LED_1, LOW);   

  digitalWrite(LED_2, LOW);

  digitalWrite(AIN1, HIGH);

  digitalWrite(AIN2, LOW);

  digitalWrite(BIN1, LOW);

  digitalWrite(BIN2, HIGH);

}

void short_brake() {

  digitalWrite(LED_1, LOW);   

  digitalWrite(LED_2, LOW);
  
  digitalWrite(AIN1, HIGH);

  digitalWrite(AIN2, HIGH);

  digitalWrite(BIN1, HIGH);

  digitalWrite(BIN2, HIGH);

}

void left() {

  digitalWrite(LED_1, HIGH);   // turn the LED on (HIGH is the voltage level)

  digitalWrite(LED_2, HIGH);

  digitalWrite(AIN1, HIGH);

  digitalWrite(AIN2, LOW);

  digitalWrite(BIN1, HIGH);

  digitalWrite(BIN2, LOW);

}



void right() {

  digitalWrite(LED_1, HIGH);   // turn the LED on (HIGH is the voltage level)

  digitalWrite(LED_2, HIGH);

  digitalWrite(AIN1, LOW);

  digitalWrite(AIN2, HIGH);

  digitalWrite(BIN1, LOW);

  digitalWrite(BIN2, HIGH);

}
