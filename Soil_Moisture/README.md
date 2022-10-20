# Soil Moisture Sensor 

วัดความชื้นในดิน อ่านค่าความชื้นได้ตั้งแต่ 0 ถึง 1024

## connect
VCC, GND, Analog In

## code
```C++
int sensorPin = <analogPin>;
```
e.g.
```
int sensorPin = A0;
```
### void setup()
```C++

```
### void loop()
อ่านค่า
```C++
sensorValue = analogRead(sensorPin);
```