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


// defines variables

int data_0;

int data_1;

int data_2;

int data_3;

const int thres = 25;

bool go_forward, go_right, go_left ;


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

  //sensors left to right:
  
  data_0 = analogRead(IR_0);
  
  data_1 = analogRead(IR_1);
  
  data_2 = analogRead(IR_2);
  
  data_3 = analogRead(IR_3);

  Serial.print("data0: ");
  Serial.print(data_0);
  Serial.print("\tdata1: ");
  Serial.print(data_1);
  Serial.print("\tdata2: ");
  Serial.print(data_2);
  Serial.print("\tdata3: ");
  Serial.print(data_3);

  /* motor rotation logic
   * 
   * Forward
   * --> 0 1 1 0
   * --> 0 1 0 0
   * --> 0 0 1 0
   * --> 0 0 0 0
   * 
   * Right
   * --> 0 0 0 1
   * --> 0 0 1 1
   * --> 0 1 1 1
   * 
   * Left
   * --> 1 0 0 0
   * --> 1 1 0 0
   * --> 1 1 1 0
   * 
   * Stop
   * --> Other else
   * 
   */

  go_forward = (data_0 < thres && (data_1 > thres || data_2 > thres) && data_3 < thres) || (data_0 < thres && data_1 < thres && data_2 < thres && data_3 < thres);

  go_right = (data_0 < thres && data_1 < thres && data_2 > thres && data_3 > thres) || (data_0 < thres && data_1 < thres && data_2 < thres && data_3 > thres) || (data_0 < thres && data_1 > thres && data_2 > thres && data_3 > thres);

  go_left = (data_0 > thres && data_1 > thres && data_2 < thres && data_3 < thres) || (data_0 > thres && data_1 < thres && data_2 < thres && data_3 < thres) || (data_0 > thres && data_1 > thres && data_2 > thres && data_3 < thres);

  if (go_forward)
  {
    
    forward();

    Serial.println("\tForward");
    
  }

  else if (go_right)
  {
    
    right();

    Serial.println("\tRight");
    
  }

  else if (go_left)
  {
    
    left();

    Serial.println("\tLeft");
    
  }
  
  // else if ( data_0 > thres && data_1 > thres && data_2 > thres && data_3 > thres )
  else
  {
    
    short_brake();

    Serial.println("\tStop");
    
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
