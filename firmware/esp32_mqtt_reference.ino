#include <WiFi.h>
#include <PubSubClient.h>

const char* WIFI_SSID = "YOUR_WIFI_SSID";
const char* WIFI_PASS = "YOUR_WIFI_PASSWORD";
const char* MQTT_HOST = "broker.emqx.io";
const char* MQTT_TOPIC = "kjsse/iot-lab/telemetry";
const int SENSOR_A_PIN = 34;
const int SENSOR_B_PIN = 27;
const int ACTUATOR_PIN = 23;

WiFiClient network;
PubSubClient mqtt(network);

void setup() {
  Serial.begin(115200);
  pinMode(SENSOR_B_PIN, INPUT);
  pinMode(ACTUATOR_PIN, OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  mqtt.setServer(MQTT_HOST, 1883);
}

void loop() {
  float sensorA = analogRead(SENSOR_A_PIN) * 100.0 / 4095.0;
  bool sensorB = digitalRead(SENSOR_B_PIN);
  bool decision = sensorA < 50 && sensorB;
  digitalWrite(ACTUATOR_PIN, decision ? HIGH : LOW);

  if (WiFi.status() == WL_CONNECTED) {
    if (!mqtt.connected()) mqtt.connect("esp32-kjsse-lab");
    char payload[160];
    snprintf(payload, sizeof(payload),
      "{\"sensorA\":%.1f,\"sensorB\":%s,\"decision\":%s}",
      sensorA, sensorB ? "true" : "false", decision ? "true" : "false");
    mqtt.publish(MQTT_TOPIC, payload);
    mqtt.loop();
  }
  delay(5000);
}
