//connections
//+ve buzzer pin 13
//-ve buzzer pin Gnd
// vcc ultra sonic 5v
// gnd ultra sonic gnd
// trigpin ultra sonic 9
// echoPin ultra sonic 10 

const int trigPin = 9;
const int echoPin = 10;
int const buzzPin = 13;

// defines variables
long duration;
int distance;

void setup()
{
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzPin, OUTPUT); // buzz pin is output to control buzzering
Serial.begin(9600); // Starts the serial communication
}

void loop()
{

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
distance= 21 - duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
if (distance <= 10 && distance >= -5) {
      // Buzz
      digitalWrite(buzzPin, HIGH);
      Serial.println("FUEL level is under 10cm");
     delay(2000);
    } else {
      // Don't buzz
      digitalWrite(buzzPin, LOW);
    Serial.println("FUEL level is more than 10cm");
    delay(2000);
    }
    delay(60);
}
