#include <DHT.h>
#include <DHT_U.h>
#define MQ_2_SENSOR_PIN A5
#define BUZZER 8
int vib_sensor = A1;
int vib_data = 0;
#define DHTPIN 7
#define DHTTYPE DHT11

  int  BUTTON =4;
DHT dht(DHTPIN,DHTTYPE);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(vib_sensor,INPUT);
  //DHT11
   Serial.begin(9600);
  Serial.println("Testing!!!!");
  dht.begin();
  pinMode(MQ_2_SENSOR_PIN,INPUT);
  pinMode(BUZZER,OUTPUT);
  pinMode(BUTTON,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  vib_data = analogRead(vib_sensor);
  //delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  int analogSensor = analogRead(MQ_2_SENSOR_PIN);
  //int freq = 1000;
  //Serial.println("MQ-2 Sensor Output: ");
  //Serial.println(analogSensor);
  if(digitalRead(BUTTON) == HIGH){
     Serial.println("HIGHHHHHHHHHHH");
     digitalWrite(BUZZER,HIGH);
     delay(3000);
      digitalWrite(BUZZER,LOW);
   }

  if(analogSensor>500){
  //tone(BUZZER,10000);
  Serial.println("DANGEROUS GAS"); 
  delay(300);
  
  }
  else{
     //noTone(BUZZER);
  }
  if(isnan(h) || isnan(t))
  {
    Serial.println("MQ135 Sensor Failed");
    return;
  }
  Serial.println("Vibration Intensity : " + String(vib_data) + "Hz");
  Serial.println("Temperature(in Celcius): " + String(t)  + "°C");
  Serial.println("Relative Humidity : " + String(h) + "RH");
  Serial.println("Air Quality  " + String(analogSensor) + "AQI");
  delay(2000);
}
