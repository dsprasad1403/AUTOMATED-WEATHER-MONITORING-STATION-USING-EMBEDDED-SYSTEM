# 🌦️ Automated Weather Monitoring Station using Embedded Systems

This project demonstrates a low-cost, real-time **weather monitoring system** using **NodeMCU (ESP8266)**, multiple sensors, and **IoT integration** for remote data access. It can monitor parameters like **temperature**, **humidity**, **rainfall**, and **light intensity** both locally and over the internet.

---

## 🔧 Features

- 🌡️ Real-time temperature and humidity monitoring (DHT11)
- 🌫️ Atmospheric pressure monitoring (BMP180)
- 🌧️ Rain detection
- ☀️ Light intensity monitoring (LDR)
- 📺 Local data display via LCD (I2C)
- 📲 Remote monitoring via Blynk app
- 🔁 Auto-reconnect feature on Wi-Fi failure

---

## 🔩 Hardware Components

| Component          | Purpose                           |
|--------------------|-----------------------------------|
| NodeMCU ESP8266    | Wi-Fi-enabled microcontroller     |
| DHT11 Sensor       | Temperature & Humidity sensing    |
| BMP180 Sensor      | Pressure sensing                  |
| Rain Sensor        | Rainfall detection                |
| LDR Sensor         | Light intensity measurement       |
| LCD Display + I2C  | Local display of sensor values    |
| Breadboard + Wires | Circuit prototyping               |

---

## 🖥 Software & Tools

- Arduino IDE
- Blynk IoT Platform (Mobile app for remote monitoring)
- C/C++ Embedded Programming

---

## 🧭 System Flow

1. Sensors are connected to the NodeMCU and begin collecting real-time weather data.
2. Data is displayed on an LCD screen using the I2C module.
3. The ESP8266 sends the data to the Blynk platform via Wi-Fi.
4. Users can view live data from their smartphone through the Blynk dashboard.

---

## 📊 Results & Observations

- ✅ Real-time data was successfully transmitted and displayed remotely.
- ✅ Local LCD also reliably showed current weather values.
- 🔄 Auto-reconnect functionality ensured continuous monitoring even during network disruptions.
- 📱 Blynk platform enabled remote, mobile-based monitoring.

---

## 🗂 Block Diagram

🖼️ View the full system architecture in the file:  
[`Minor Project 2 PPT.pptx`](Minor%20Project%202%20PPT.pptx)

---

## 📚 References

A few of the sources that inspired this work:
- Karthik et al., “Arduino Based Weather Monitoring System”, IJERGS, 2015
- Rao et al., “Stratosphere Sudden Warming and Prediction”, JGR, 2019
- Catsoulis, J., “Designing Embedded Hardware”, O’Reilly Media, 2005
- Aloi et al., “IoT Interoperability with Smartphones”, Journal of Network & Comp. Apps

---

## 🛡 License

This project is licensed under the [MIT License](LICENSE).

---

## 🙌 Contributions

Feedback and contributions are welcome!  
Feel free to fork this repo and suggest improvements.
