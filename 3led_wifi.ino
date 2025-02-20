#include <WiFi.h>
#include "DHT.h"
#define DHTPIN 18
#define DHTTYPE DHT11
const char* ssid = "hotspot";
const char* password = "11223344";
DHT dht(DHTPIN, DHTTYPE);

int ledPin1 = 32;
int ledPin2 = 33; 
int ledPin3 = 15; 


WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);
  dht.begin();
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }

  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  // Match the request
  int value = LOW;
  //temperature and humidity
  float h=dht.readHumidity();
  float t=dht.readTemperature();

  // Control LED 1
  if (request.indexOf("/LED1=ON") != -1)  {
    digitalWrite(ledPin1, HIGH);
    value = HIGH;
  } else if(request.indexOf("/LED1=OFF") != -1) {
    digitalWrite(ledPin1, LOW);
    value = LOW;
  }

  // Control LED 2
  if (request.indexOf("/LED2=ON") != -1)  {
    digitalWrite(ledPin2, HIGH);
    value = HIGH;
  } else if(request.indexOf("/LED2=OFF") != -1) {
    digitalWrite(ledPin2, LOW);
    value = LOW;
  }

  // Control LED 3
  if (request.indexOf("/LED3=ON") != -1)  {
    digitalWrite(ledPin3, HIGH);
    value = HIGH;
  } else if(request.indexOf("/LED3=OFF") != -1) {
    digitalWrite(ledPin3, LOW);
    value = LOW;
  }

  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); // do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");

  // if(digitalRead(ledPin1) == HIGH) {
  //   client.print("On");
  // } 
  // client.println("<br><br>");

  // if(digitalRead(ledPin2) == HIGH) {
  //   client.print("On");
  // } 
  // client.println("<br><br>");

  // if(digitalRead(ledPin3) == HIGH) {
  //   client.print("On");
  // } 
  client.println("<br><br>");

  // Buttons to control each LED
  client.println("<a href=\"/LED1=ON\"><button>Turn On</button></a>");
  client.println("<a href=\"/LED1=OFF\"><button>Turn Off</button></a><br />");

  client.println("<a href=\"/LED2=ON\"><button>Turn On</button></a>");
  client.println("<a href=\"/LED2=OFF\"><button>Turn Off</button></a><br />");

  client.println("<a href=\"/LED3=ON\"><button>Turn On</button></a>");
  client.println("<a href=\"/LED3=OFF\"><button>Turn Off</button></a><br />");

 
  client.println("</html>");

  delay(1);
  Serial.println("Client disconnected");
  Serial.println("");

  
  Serial.println(F("Humidity: "));
  Serial.println(h);
  Serial.println(F("% Temperature "));
  Serial.print(t);
  Serial.println(F("C "));

}
