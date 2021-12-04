int encoder1 = A0; // Endoer 1 is connected to Analog Pin A0
int encoder2 = A1; // Endoer 2 is connected to Analog Pin A1
int encoder3 = A2; // Endoer 3 is connected to Analog Pin A2

int step1; int step2; int step3; // Values of encoder is stored in these steps
int val1; int val2; int val3;   // Mapped vales from Encoder to stepper motors
int data; // Data from Python 


int stepPin1 = 6;  // Stepper motor 1 Pull+ is connected to Digital Pin 6 
int dirPin1  = 7;  // Stepper motor 1 Direction Pin is connected to Digital Pin 7 
int stepPin2 = 8;  // Stepper motor 2 Pull+ is connected to Digital Pin 8 
int dirPin2  = 9;  // Stepper motor 2 Direction Pin is connected to Digital Pin 9
int stepPin3 = 10; // Stepper motor 3 Pull+ is connected to Digital Pin 10 
int dirPin3  = 11; // Stepper motor 3 Direction Pin is connected to Digital Pin 11

void setup(){
  Serial.begin(9600); // Serial connection 
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1,  OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2,  OUTPUT);
  pinMode(stepPin3, OUTPUT);
  pinMode(dirPin3,  OUTPUT);
}

void loop(){
  step1 = analogRead(encoder1);
  step2 = analogRead(encoder2);
  step3 = analogRead(encoder3);

  while(Serial.available())
  {
    data = Serial.read();
  }
  if(data == '0'){
    digitalWrite(stepPin1 ,LOW);
    digitalWrite(stepPin2 ,LOW);
    digitalWrite(stepPin3 ,LOW); 
  }
  if(data == '1'){
    digitalWrite (dirPin1 ,HIGH); // Change to Low if you need the motor to change the direction
    val1 = map(val1, 0, step1, 0, 200);
    for (int x = 0; x<val1; x++){  // 
    digitalWrite(stepPin1 ,HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin1 ,LOW);
    delayMicroseconds(2000);
  }if(data == '2'){
    digitalWrite (dirPin2 ,HIGH); // Change to Low if you need the motor to change the direction
    val2 = map(val2, 0, step2, 0, 200);
    for (int x = 0; x<val2; x++){  
    digitalWrite(stepPin2 ,HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin2 ,LOW);
    delayMicroseconds(2000);
  }if(data == '3'){
    digitalWrite (dirPin3 ,HIGH); // Change to Low if you need the motor to change the direction
    val3 = map(val3, 0, step3, 0, 200);
    for (int x = 0; x<val3; x++){  
    digitalWrite(stepPin3 ,HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin3 ,LOW);
    delayMicroseconds(2000);
    }if(data == '4'){
    digitalWrite (dirPin3 ,HIGH); // Change to Low if you need the motor to change the direction
    for (int x = 0; 200; x++){  
    digitalWrite(stepPin1 ,HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin1 ,LOW);
    delayMicroseconds(2000); 
    digitalWrite(stepPin2 ,HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin2 ,LOW);
    delayMicroseconds(2000);
    digitalWrite(stepPin3 ,HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin3 ,LOW);
    delayMicroseconds(2000);
    }
   }
  }
 }
}
}
