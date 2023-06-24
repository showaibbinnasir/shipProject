int trig = 8;
int echo = 7;
long timeInMicro;

long distanceInCm;
double meter;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig,LOW);
 delayMicroseconds(1000);
 digitalWrite(trig,HIGH);
 delayMicroseconds(1000);
 digitalWrite(trig,LOW);
 timeInMicro= pulseIn(echo,HIGH);
 delay(500);

 distanceInCm = ((timeInMicro/29)/2);

 if(distanceInCm < 10){
   Serial.println("Sorry");
 }
 else{
    Serial.println("Available");
 }



}
