// motor driver pin defination:

#define AIN1 2

#define AIN2 4

#define BIN1 6

#define BIN2 7


// led pins:

#define LED_1 13

#define LED_2 8


// sensor pins:

#define IR_0 A0

#define IR_1 A1

#define IR_2 A2

#define IR_3 A3


void setup() {

  pinMode(AIN1, OUTPUT);

  pinMode(BIN1, OUTPUT);

  pinMode(AIN2, OUTPUT);

  pinMode(BIN2, OUTPUT);



  pinMode(LED_1, OUTPUT);

  pinMode(LED_2, OUTPUT);



  // Sensor pins:
  
  
  Serial.begin(9600); // Starts the serial communication

}

void loop() {

  forward();
  delay(10000);
  short_brake();
  delay(1000);  
  
  left();
  delay(5000);
  short_brake();
  delay(1000);
  
  right();
  delay(2*5000);
  short_brake();
  delay(1000);

  backward();
  delay(2*5000);
  short_brake();
  delay(1000);

}


void forward() {

  digitalWrite(LED_1, LOW);   

  digitalWrite(LED_2, LOW);

  digitalWrite(AIN1, HIGH);

  digitalWrite(AIN2, LOW);

  digitalWrite(BIN1, HIGH);

  digitalWrite(BIN2, LOW);

}

void backward() {

  digitalWrite(LED_1, LOW);   

  digitalWrite(LED_2, LOW);

  digitalWrite(AIN1, LOW);

  digitalWrite(AIN2, HIGH);

  digitalWrite(BIN1, LOW);

  digitalWrite(BIN2, HIGH);

}

void short_brake() {

  digitalWrite(LED_1, LOW);   

  digitalWrite(LED_2, LOW);
  
  digitalWrite(AIN1, LOW);

  digitalWrite(AIN2, LOW);

  digitalWrite(BIN1, LOW);

  digitalWrite(BIN2, LOW);

}

void left() {

  digitalWrite(LED_1, HIGH);   // turn the LED on (HIGH is the voltage level)

  digitalWrite(LED_2, HIGH);

  digitalWrite(AIN1, LOW);

  digitalWrite(AIN2, HIGH);

  digitalWrite(BIN1, HIGH);

  digitalWrite(BIN2, LOW);

}



void right() {

  digitalWrite(LED_1, HIGH);   // turn the LED on (HIGH is the voltage level)

  digitalWrite(LED_2, HIGH);

  digitalWrite(AIN1, HIGH);

  digitalWrite(AIN2, LOW);

  digitalWrite(BIN1, LOW);

  digitalWrite(BIN2, HIGH);

}
