//Youtube|Tech at Home
int beepPin = 9;
int trig=8;
int echo=7;
int alertLight= 11;
int vibrateAlert =10;

long timeInMicro;

long distanceInCm;
double meter;

void setup() 
{
  Serial.begin(9600);
  pinMode(beepPin,OUTPUT);
  pinMode(alertLight,OUTPUT);
  pinMode(vibrateAlert, OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,INPUT);
}

void loop()  
{
 digitalWrite(trig,LOW);
 delayMicroseconds(2);
 digitalWrite(trig,HIGH);
 delayMicroseconds(10);
 digitalWrite(trig,LOW);
 digitalWrite(beepPin, LOW);
 digitalWrite(alertLight,LOW);
 digitalWrite(vibrateAlert, HIGH);
 timeInMicro= pulseIn(echo,HIGH);

 distanceInCm = ((timeInMicro/29)/2);
 Serial.println("available");
 
 

 if(distanceInCm < 10) {
   Serial.println("sorry");
   digitalWrite(vibrateAlert, LOW);
   analogWrite(beepPin, 127);
   digitalWrite(alertLight,HIGH);
   delay(500);
   digitalWrite(alertLight,LOW);
   analogWrite(beepPin, 210);
   delay(500);
   digitalWrite(alertLight,HIGH);
   analogWrite(beepPin, 57);
   delay(500);
   digitalWrite(alertLight,LOW);
   analogWrite(beepPin, 12);
   delay(500);
   digitalWrite(alertLight,HIGH);
   analogWrite(beepPin, 85);
   delay(500);
   digitalWrite(alertLight,LOW);
   analogWrite(beepPin, 171);
   delay(500);

 }
 delay(100);
 
}
