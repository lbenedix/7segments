#include <Adafruit_NeoPixel.h>
// Declare our NeoPixel strip object:
#define LED_PIN   2
#define LED_COUNT 84
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ400);

#include <ESP8266WiFi.h>

// CONFIGURATION HERE
char ssid[] = "Camp2019-things"; //SSID of your Wi-Fi router
char pass[] = "camp2019"; //Password of your Wi-Fi router

int brightness = 100;
uint32_t color = strip.Color(140, 0, 255);

bool rnd = true; // this overrules the color and lets each segment have it's own random color
bool more_rnd = true; // each led get's it's own color

const long interval = 1000; 
// 



#include <WiFiUdp.h>
WiFiUDP ntpUDP;

#include <NTPClient.h>
NTPClient timeClient(ntpUDP);
String formattedDate;
String dayStamp;
String timeStamp;


unsigned long previousMillis = 0;


void setup() {
  Serial.begin(115200);

  // Setup strip
  strip.begin();
  strip.show();
  strip.setBrightness(brightness);

  // Connect to WiFi
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println(WiFi.status());
    glitter(150);
  }
  Serial.print("Connected to WiFi: ");
  Serial.println(WiFi.localIP());

  // Setup NTP client
  Serial.println("updating time from ntp server...");
  // start ntp client
  timeClient.begin();
  timeClient.setTimeOffset(3600 * 2);

  // Reset strip
  turn_off();
}


void loop() {
  unsigned long currentMillis = millis();

  while (!timeClient.update()) {
    Serial.println("updating time...");
    timeClient.forceUpdate();
  }

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    formattedDate = timeClient.getFormattedDate();
    int splitT = formattedDate.indexOf("T");
    timeStamp = formattedDate.substring(splitT + 1, formattedDate.length() - 4);

    String t = timeStamp.substring(0, 2);
    t += timeStamp.substring(3, 5);

    print_number(t, color, rnd, more_rnd);
  }

}
