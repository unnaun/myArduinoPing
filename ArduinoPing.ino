//define pin 5 as trig and pin 6 as echo
const int TRIG = 5;
const int ECHO = 6;
//define value to keep track of: duration of pulse
//and the final distance in cm
int pulse_duration;
int distance_cm;

void setup() {
  // begin serial comms
  Serial.begin(9600);
  //set echo as receiver and trig as trigger
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop() {
  // setting echo and trig to low to init
  digitalWrite(TRIG, LOW);
  digitalWrite(ECHO, LOW);
  delayMicroseconds(5);
  //10 microseconds trigger pulse
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  //reading time of the counter using pulseIn
  //https://www.arduino.cc/reference/en/language/functions/advanced-io/pulsein/
  pulse_duration = pulseIn(ECHO, HIGH);
  //Sound travels at 343 meters per second, which means it needs 29.155 microseconds per centimeter. 
  //So, we have to divide the duration by 29 and then by 2, because the sound has to travel the distance twice
  distance_cm = pulse_duration/29/2;
  Serial.print("Distance in cm is: ");
  Serial.print(distance_cm);
  Serial.print("\n");
  delay(1000);

}
