# 🌾 Field Monitoring System for Smart Agriculture using IoT

## 📌 Overview

This project aims to automate and remotely monitor agricultural fields using **Arduino** and **ESP8266** microcontrollers. With the integration of multiple sensors and the **Blynk IoT App**, farmers can get real-time updates and control irrigation systems directly from their smartphones.

> **Goal:** To build a smart, energy-efficient, and cost-effective field monitoring and irrigation system to improve agricultural productivity.

---

## ⚙️ Components Used

| Component | Description |
|----------|-------------|
| **Arduino UNO** | Main microcontroller for sensor data processing |
| **ESP8266 WiFi Module** | Enables Wi-Fi connectivity for remote monitoring and control |
| **Blynk App** | IoT platform to control and monitor the system via smartphone |
| **Soil Moisture Sensor** | Measures moisture level in the soil to prevent under/over-watering |
| **DHT11 Sensor** | Captures temperature and humidity data from the environment |
| **Ultrasonic Sensor** | Detects the presence of animals or obstacles near the field |
| **LDR Sensor** | Monitors ambient light levels to optimize resource usage |
| **LED** | Indicates system status (e.g., irrigation ON/OFF) |
| **Buzzer** | Gives audible alerts for warnings or critical sensor values |
| **Water Pump** | Automates irrigation process when soil is dry |

---

## 🧠 How It Works

1. **Sensor Readings:**
   - Soil moisture level is continuously monitored.
   - Temperature, humidity, and light levels are logged.
   - Ultrasonic sensor detects motion (e.g., animals near the crops).

2. **Decision Making:**
   - If soil moisture is below a certain threshold, the **water pump** is activated.
   - If any unusual activity is detected by the ultrasonic sensor, an **alert** is triggered via **buzzer**.
   - Light levels control operations depending on day/night conditions.

3. **Remote Control & Monitoring:**
   - All sensor data is sent to the **Blynk App** using the **ESP8266** module.
   - Users can manually control the water pump, view sensor data, and receive alerts.

---

## 🔌 Sensor & Component Details (Used in Our Project)

### 1. 🌱 Soil Moisture Sensor  
- **Purpose:** To detect the moisture level of the soil.  
- **Working:** The sensor measures the resistance between its probes—dry soil offers more resistance, while wet soil offers less.  
- **Use in Project:**  
  - If the soil is **too dry**, it sends a signal to turn **ON the water pump** for irrigation.  
  - Once the moisture level is sufficient, the pump is automatically **turned OFF**.  
  - This helps in **saving water** and ensures crops get enough moisture.

---

### 2. 🌡️ DHT11 Sensor (Temperature & Humidity)  
- **Purpose:** To monitor the environmental temperature and humidity.  
- **Working:** It uses a thermistor for temperature and a capacitive humidity sensor.  
- **Use in Project:**  
  - Sends **real-time data** to the **Blynk app**.
  - Helps farmers understand current weather conditions and make decisions accordingly.
  - Can be used in the future to **automatically activate shade nets or fans**.

---

### 3. 🧭 Ultrasonic Sensor (Animal/Obstacle Detection)  
- **Purpose:** To detect movement of animals or obstacles near the field.  
- **Working:** It sends out ultrasonic waves and measures the time taken for the echo to return.  
- **Use in Project:**  
  - If an animal or intruder is detected within a certain distance, a **buzzer sounds** an alert.
  - This can **prevent crop damage** from stray animals or theft.
  - The detection status is also shown on the **Blynk app**.

---

### 4. 💡 LDR Sensor (Light Intensity Detection)  
- **Purpose:** To detect the intensity of surrounding light.  
- **Working:** The resistance of the LDR decreases as light increases.  
- **Use in Project:**  
  - Used to **detect night-time** conditions.
  - Automatically **turns ON the LED** when it gets dark.
  - Useful to simulate **automatic field lighting** or a scarecrow light to deter animals at night.

---

### 5. 🔦 LED (Night Light Indicator)  
- **Purpose:** To act as a light source when needed.  
- **Use in Project:**  
  - Controlled by the **LDR sensor**.
  - Automatically **turns ON at night** and **OFF during daytime**.
  - Can help in **indicating the system is running** or deter pests in actual use.

---

### 6. 🔊 Buzzer (Alert System)  
- **Purpose:** To provide audible alerts.  
- **Use in Project:**  
  - Activated when the **ultrasonic sensor** detects movement near the field.
  - Can be used as a **scare alert for animals**.
  - Helps in **real-time awareness** even if you're not checking the app constantly.

---

### 7. 💧 Water Pump  
- **Purpose:** To irrigate the field.  
- **Use in Project:**  
  - **Controlled automatically** by the soil moisture sensor.
  - Can also be **manually operated** via a **button in the Blynk app**.
  - Provides **smart irrigation** and **reduces water wastage**.

---

## 📱 Blynk App Integration

- **Project Settings:**
  - Auth Token: (Paste your token in code)
  - Add widgets:
    - Gauge (Soil Moisture)
    - Value Display (Temperature, Humidity)
    - Button (Pump Control)
    - Notification (Alerts)
  
- **Connectivity:**
  - ESP8266 is programmed to send and receive data via Blynk Cloud.

---

## 🔧 Circuit Diagram

*(You can attach a circuit image or Fritzing diagram here)*

---

## 📚 Required Libraries

To successfully compile and run the project code on the **Arduino IDE**, make sure you have the following libraries installed:

| Library Name | Purpose | Installation |
|--------------|---------|--------------|
| **ESP8266WiFi** | Enables Wi-Fi connectivity for the ESP8266 module | Built-in or install via Board Manager |
| **Blynk** | Communicates with Blynk Cloud/App | Install from Library Manager or via ZIP |
| **DHT sensor library** | Used to read temperature and humidity from DHT11 | Install from Library Manager |
| **Adafruit Unified Sensor** | Required by the DHT library | Install from Library Manager |
| **SimpleTimer / BlynkTimer** | Handles timed operations in Blynk sketches | Comes with Blynk library |
| **SoftwareSerial** | Enables serial communication on other digital pins | Built-in in Arduino IDE |

### 🔧 How to Install Libraries:
1. Open Arduino IDE.
2. Go to **Sketch > Include Library > Manage Libraries…**
3. Search and install each library listed above.
4. Alternatively, download the libraries as `.zip` files and use **Sketch > Include Library > Add .ZIP Library…**

---

## 💻 Code

The Arduino code for sensor reading, decision logic, and Blynk communication is provided in the `code` folder.

> 🔑 Make sure to replace your **Wi-Fi credentials** and **Blynk Auth Token** before uploading to the Arduino.

---

## 📈 Future Improvements

- Add **Rain Sensor** to detect rainfall
- Integrate **Solar Power Supply**
- Use **ESP32** for more processing power and features
- Implement **data logging** to SD card or cloud storage
- Add **ML-based prediction model** for better irrigation scheduling

---

## 📸 Project Images

*(Upload photos of your actual working system here)*

---

## 🤝 Contributors

- **Jan** – Developer, Circuit Design, IoT Integration
- Team Members – Testing, Documentation, Assembly

---

## 📜 License

This project is open-source and available under the [MIT License](LICENSE).
