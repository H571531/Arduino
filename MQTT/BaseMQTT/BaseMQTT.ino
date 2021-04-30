#include <ESP8266WiFi.h>
#include <PubSubClient.h>

//Variables
const char* mqttServer="";
const char* ssid="";
const char* wiFiPass="";
const char* commandTopic="command";

//Connections
WiFiClient espClient;
PubSubClient client(espClient);



void setup(){
  Serial.begin(9600);
  client.setServer(mqttServer, 1883);
  client.setCallback(callback);
  WiFi.begin(ssid, wiFiPass);
  Serial.println(); //Cleanup debug
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if (!client.connected()) {
    reconnectMqtt();
  }
  client.loop();
}


void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");

}

void reconnectMqtt() {
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");

    if (client.connect("ESP32Client")) {

      Serial.println("connected");
      client.subscribe(commandTopic);

    } else {

      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
    }
  }
}
