#define lm 5//l motor
#define rm 6//r motor
int obstacleThreshold = 10;
int trigPin = 7;
int echoPin = 8;
void setup() {
  pinMode(A0,INPUT);//left IR sensor
  pinMode(A1,INPUT);//middle IR sensor
  pinMode(A2,INPUT);//right IR sensor
  pinMode(5,OUTPUT);//left motor
  pinMode(6,OUTPUT);//right motor
  pinMode(9,OUTPUT);//left motor
  pinMode(10,OUTPUT);//right motor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  analogWrite(9,220);
  analogWrite(10,220);
   Serial.begin(9600);
}
void loop() {
  int LIR,MIR,RIR;
   LIR=digitalRead(A0);//left IR sensor
   MIR=digitalRead(A1); //middle IR sensor
   RIR=digitalRead(A2);//right IR sensor

          digitalWrite(trigPin, LOW);
          delayMicroseconds(2);
          digitalWrite(trigPin, HIGH);
          delayMicroseconds(10);
          digitalWrite(trigPin, LOW);
          int duration = pulseIn(echoPin, HIGH);
          int distance = (duration *0.034) / 2;
        
     if (distance < obstacleThreshold) {
            // Stop the bot
            digitalWrite(lm, LOW);
            digitalWrite(rm, LOW);
           Serial.println("stop");
          }
    else{
   if((LIR==1 && MIR==0 && RIR==1)){
    Serial.println(" forward ");
    digitalWrite(lm,1);
    digitalWrite(rm,1);
    }
    
    else if((LIR==0 && MIR==1 && RIR==1) || (LIR==0 && MIR==0 && RIR==1) ){
    Serial.println("left");
    digitalWrite(lm,0);
    digitalWrite(rm,1);
    }
    else if((LIR==1 && MIR==1 && RIR==0) ||(LIR==1 && MIR==0 && RIR==0)){
    Serial.println("right");
    digitalWrite(lm,1);
    digitalWrite(rm,0);
    }
}}
