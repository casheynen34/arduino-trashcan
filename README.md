# Humanized Trash Bin 🤖🗑️

This is an Arduino-based project that transforms a regular trash bin into a **humanized, interactive experience**. It uses two screens as animated "eyes", a sensor to detect interaction, and a counter to track usage.

---

## 📁 Project Structure

The project is split into two main folders for modularity:

/arduino_trashcan/ # arduino_trashcan.ino # Logic for animating eye expressions
/sensor/sensor.ino # Logic for detecting presence and incrementing a counter


---

## ⚙️ Hardware Requirements

To build this project, you'll need:

- 3x Arduino boards (Uno)
  - 2 for the displays (one per eye)
  - 1 for the sensor and usage counter
- 2x Arduino 2.4 inch TFT display Shield (one per Arduino controlling eyes)
- 1x LCD Display 1602A (to display the counter)
- 1x Ultrasone sensor HC-SR04 / HY-SRF05 (e.g., HC-SR04)
- 2x microSD cards (one for each display)
- 2x microSD card modules (if not integrated into the display)
- 1x button (to reset the counter)
- Jumper wires
- Breadboard or custom PCB
- Trash bin

---

## 🧠 Software Requirements

- [Arduino IDE](https://www.arduino.cc/en/software)
- C++ (Arduino Sketches)

---

## 🚀 Getting Started

1. **Download or clone** this repository.
2. Open the **Arduino IDE**.
3. Navigate to the folder you need:
   - `/arduino_trashcan/` → open `arduino_trashcan.ino` for eye animation logic.
   - `/sensor/` → open `sensor.ino` for sensor and counter logic.
4. For each Arduino:
   - Connect the correct components (display or sensor).
   - Insert a **microSD card** into the SD card module connected to the Arduino controlling the displays.
   - Upload the respective code via USB.
5. Select the correct **board** and **port** in the IDE.
6. Click **Upload**.

---

## 🖼️ Display Images

The project uses **predefined images** (e.g., blinking, happy, surprised eyes) to animate expressions.  
These must be stored on **2 microSD cards** (one per display Arduino).  
Insert each SD card into the module or screen connected to the corresponding Arduino.

✅ Ensure:
- The images are in BMP format (or format expected by your display library).
- File names and paths match what’s used in `display.ino`.
