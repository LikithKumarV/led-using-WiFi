# LED Control and Sensor Monitoring with ESP32

This project demonstrates how to control LEDs and monitor temperature and humidity using an ESP32 and a web interface. It uses a DHT11 sensor for temperature and humidity readings, and lets you control three LEDs from a web page.

### Features
- **Web-based LED control:** Turn on or off three LEDs from a web interface.
- **Temperature and humidity monitoring:** The DHT11 sensor provides temperature and humidity data, which is shown on the web interface.
- **Wi-Fi connectivity:** The ESP32 connects to a Wi-Fi network and hosts a server to control the LEDs and display sensor data.

### Components
- **ESP32 Development Board**
- **DHT11 Sensor** (for temperature and humidity readings)
- **3 x LEDs**
- **Resistors & Breadboard** (for connections)

### Pin Setup
- **DHT11 Sensor:** Pin 18
- **LED1:** Pin 32
- **LED2:** Pin 33
- **LED3:** Pin 15

### Installation

#### Hardware Setup
1. **DHT11 Sensor:** Connect to Pin 18 of the ESP32.
2. **LEDs:** 
   - LED1 to Pin 32
   - LED2 to Pin 33
   - LED3 to Pin 15
3. **Resistors:** Use 220-330 ohm resistors for LEDs.

#### Software Setup
1. **Arduino IDE:** Install ESP32 board support by following the official guide.
2. **Install DHT Sensor Library:** Go to `Sketch > Include Library > Manage Libraries`, search for "DHT sensor" by Adafruit, and install it.
3. **Upload Code:** Upload the provided code to the ESP32.

#### Wi-Fi Configuration
- Replace `"your-SSID"` and `"your-PASSWORD"` with your Wi-Fi credentials in the code:

```cpp
const char* ssid = "your-SSID";
const char* password = "your-PASSWORD";
```

After uploading, open the **Serial Monitor**. The ESP32 will display its IP address, which you can use to access the web interface.

### Web Interface
Once connected to Wi-Fi, visit the ESP32's IP address in your browser (e.g., `http://192.168.1.100/`) to access the web interface.

It will show buttons to control each LED and display the current temperature and humidity.

#### Available Controls:
- **LED1, LED2, LED3:** Buttons to turn LEDs on/off.
- **Temperature & Humidity:** Real-time data from the DHT11 sensor.

### Code Explanation
- **DHT11 Sensor:** Reads temperature and humidity in the `loop()` function and prints to the Serial Monitor.
- **Wi-Fi Connection:** Connects the ESP32 to your Wi-Fi using the credentials provided.
- **Web Server:** The ESP32 hosts a server on port 80. It serves a page with buttons to control the LEDs and display sensor data.
- **LED Control:** Control the LEDs by accessing URLs like `http://<ESP32_IP>/LED1=ON` or `http://<ESP32_IP>/LED1=OFF`.

### Example Commands
- Turn LED1 on: `http://<ESP32_IP>/LED1=ON`
- Turn LED1 off: `http://<ESP32_IP>/LED1=OFF`

Repeat for LED2 and LED3.

### Troubleshooting
- **Can't connect to Wi-Fi:** Check that your SSID and password are correct.
- **LED not working:** Verify the LEDs are connected to the correct pins (32, 33, 15) and set as OUTPUT.
- **No sensor data:** Check the DHT11 wiring and ensure it’s connected to Pin 18.

### Future Ideas
- **Mobile App:** Create an app to control LEDs and monitor sensor data.
- **Multiple Sensors:** Add more sensors like light, motion, or gas.
- **Data Logging:** Store temperature and humidity readings in a cloud database or SD card.
