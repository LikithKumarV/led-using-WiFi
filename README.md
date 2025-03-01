# led-using-WiFi
This project demonstrates how to control LEDs and read temperature and humidity data using a web interface served by an ESP32. It uses the DHT11 sensor for temperature and humidity readings and allows the user to control three LEDs through a web page.

Features
Web-based LED control: You can turn on and off three LEDs using a simple web interface.
Temperature and Humidity Monitoring: The DHT11 sensor reads the temperature and humidity, and the data is printed in the Serial Monitor.
Wi-Fi Connectivity: The ESP32 connects to a Wi-Fi network and hosts a local server for controlling LEDs and displaying sensor data.
Components
ESP32 Development Board: The microcontroller for the project.
DHT11 Sensor: For measuring temperature and humidity.
3 x LEDs: Controlled through the web interface.
Resistors and Breadboard: For connecting the LEDs and sensor.
Pin Configuration
DHT11: Pin 18
LED1: Pin 32
LED2: Pin 33
LED3: Pin 15
Installation
Hardware Setup
DHT11 Sensor: Connect the DHT11 sensor to Pin 18 on the ESP32.
LEDs:
Connect LED1 to Pin 32.
Connect LED2 to Pin 33.
Connect LED3 to Pin 15.
Resistors: Use appropriate resistors (typically 220-330 ohms) to limit current to the LEDs.
Software Setup
Arduino IDE: Install the ESP32 board support in Arduino IDE by following the official ESP32 setup guide.
Install DHT Sensor Library: Go to Sketch > Include Library > Manage Libraries and search for DHT sensor library by Adafruit. Install it.
Upload Code: Open the provided code in the Arduino IDE and upload it to your ESP32.
Wi-Fi Configuration
Set your Wi-Fi credentials (SSID and password) in the code by replacing "hotspot" and "11223344" with your own Wi-Fi details:

cpp
Copy
const char* ssid = "your-SSID";
const char* password = "your-PASSWORD";
After uploading the code, open the Serial Monitor. The ESP32 will print the local IP address, which you can use to access the web interface.

Web Interface
Once the ESP32 is connected to the Wi-Fi, you can access the web interface from any device on the same network by visiting the IP address printed in the Serial Monitor (e.g., http://192.168.1.100/).

The web page will have buttons to turn each LED on or off, as well as display the current temperature and humidity readings.

Available Controls
LED1, LED2, LED3: Buttons to turn the LEDs on and off.
Temperature and Humidity: Current readings from the DHT11 sensor.
Code Explanation
DHT11 Sensor: The sensor reads the temperature and humidity data in the loop() function and prints it to the Serial Monitor.
Wi-Fi Connection: The ESP32 connects to a Wi-Fi network with the provided credentials (ssid and password).
Web Server: The ESP32 runs a simple web server on port 80. It listens for HTTP requests and serves a page with buttons to control the LEDs. It also displays the temperature and humidity values.
LED Control: The LEDs are controlled by appending LEDx=ON or LEDx=OFF to the URL, such as http://<ESP32_IP>/LED1=ON.
Web Interface Example
Turning LED1 on: http://<ESP32_IP>/LED1=ON
Turning LED1 off: http://<ESP32_IP>/LED1=OFF
Same for LED2 and LED3.
Troubleshooting
Unable to connect to Wi-Fi: Make sure the SSID and password in the code are correct. Double-check your network connection.
LED not responding: Ensure the LEDs are connected to the correct pins (32, 33, 15) and that the pin mode is set as OUTPUT.
Sensor data not displayed: If the temperature and humidity values are not reading correctly, check the wiring of the DHT11 sensor and make sure it is connected to Pin 18.
Future Improvements
Mobile App: Develop a mobile app to control the LEDs and monitor the sensor data.
Multiple Sensors: Integrate more sensors, like light, gas, or motion sensors, to expand the functionality.
Data Logging: Store the temperature and humidity readings in a cloud database or SD card.
