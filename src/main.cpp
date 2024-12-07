#include <Arduino.h>
#include <Wifi.h>
#include <PubSubClient.h>
#include "credentials.h"

#define LED 5
#define fwd_btn 34
#define bwd_btn 35
#define pwm_motor 25
#define fwd_motor 26
#define bwd_motor 27

#define ssid ssid
#define pass pass
#define brokerUser brokerUser
#define brokerPass brokerPass
#define broker broker
const char* outTopic = "";

WiFiClient espClient;
PubSubClient client(espClient);

void setupWifi(){
   delay(100);
   Serial.print("\nConnecting to");
   Serial.println(ssid);
   Wifi.begin(ssid, pass);

   while(Wifi.status() != WL_CONNECTED){
    delay(100);
    Serial.println("-");
   }
   Serial.print("\nConnected to");
   Serial.println(ssid);
   client.setServer(broker, 1883);
}

void reconnect(){
  while(!client.connected()){
    Serial.print("\nConnecting to");
    Serial.println(broker);
    if(client.connect("ladidadi", brokerUser, brokerPass)){
      Serial.print("\nConnected to");
      Serial.println(broker);
    } else {
      Serial.println("\nTrying to connect again");
      delay(5000);
    }
  }
}

void setup(){
  pinMode(LED, OUTPUT);
  pinMode(fwd_btn, INPUT);
  pinMode(bwd_btn, INPUT);
  pinMode(pwm_motor, OUTPUT);
  pinMode(fwd_motor, OUTPUT);
  pinMode(bwd_motor, OUTPUT);

  Serial.begin(115200);
  setupWifi();
}

void loop(){
  if(!client.connected()){
    reconnect();
  }
  client.loop();

  if (digitalRead(fwd_btn) == HIGH){
    digitalWrite(pwm_motor, HIGH);
    digitalWrite(fwd_motor, HIGH);
    digitalWrite(LED,HIGH);
    Serial.println("fwd");
  }
  else if (digitalRead(bwd_btn) == HIGH){
    digitalWrite(pwm_motor, HIGH);
    digitalWrite(bwd_motor, HIGH);
    Serial.println("bwd");
    digitalWrite(LED,HIGH);
  }
  else{
    digitalWrite(pwm_motor, LOW);
    digitalWrite(fwd_motor, LOW);
    digitalWrite(bwd_motor, LOW);
    digitalWrite(LED, LOW);
  }
  //delay(1000);
}