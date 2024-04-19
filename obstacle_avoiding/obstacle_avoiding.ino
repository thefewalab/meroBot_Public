#define AIN1 2

#define AIN2 4

#define BIN1 6

#define BIN2 7


#define LED_1 13

#define LED_2 8

const int trigPin = 12;

const int echoPin = 11; //mosi 11



// defines variables

long duration;

int distance;

int left_distance;

int right_distance;

int turnDelay = 400; // for v1.7.1/

//int turnDelay = 850; // for v1.7/

void setup() {

  pinMode(AIN1, OUTPUT);

  pinMode(BIN1, OUTPUT);

  pinMode(AIN2, OUTPUT);

  pinMode(BIN2, OUTPUT);



  pinMode(LED_1, OUTPUT);

  pinMode(LED_2, OUTPUT);



  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output

  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  
  
  Serial.begin(9600); // Starts the serial communication

}

void loop() {

  distance = cal_distance();

  if (distance <= 6) {

    short_brake();

    Serial.println("someone on the way!");

    delay(500);
    
    Serial.println("go left");
    
    left();

    delay(turnDelay);

    short_brake();

    delay(500);

    left_distance = cal_distance();

    Serial.println("go right");

    right();

    delay(turnDelay*2 - 50); // avoid overturn

    short_brake();

    delay(500);

    right_distance = cal_distance();

    if( right_distance <= left_distance ){
      left();

      delay(turnDelay*2 - 50); // avoid overturn
    }

  }

  else {

    Serial.println("forward");

    forward();

  }

}

int cal_distance(){
  // Clears the trigPin

  digitalWrite(trigPin, LOW);

  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds

  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds

  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance

  int dist = duration * 0.034 / 2;

  // Prints the distance on the Serial Monitor

  Serial.print("Distance: ");

  Serial.println(dist);

  return dist;
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
