# Ultrasonic Sensor HY-SRF05

วัดความชื้นในดิน อ่านค่าความชื้นได้ตั้งแต่ 0 ถึง 1024

## connect
VCC, GND, 2 Digital

## code
```C++
const unsigned int TRIG_PIN = <digitalPin>;
const unsigned int ECHO_PIN = <digitalPin>;
```
e.g.
```
const unsigned int TRIG_PIN=4;
const unsigned int ECHO_PIN=2;
```
### void setup()
```C++
pinMode(ECHO_PIN, INPUT);
pinMode(TRIG_PIN, OUTPUT);
```
### void loop()
```C++
long duration, distance;
digitalWrite(TRIG_PIN, LOW);
delayMicroseconds(2);
digitalWrite(TRIG_PIN,HIGH);
delayMicroseconds(10);
digitalWrite(TRIG_PIN,LOW);
```
คำนวณระยะทาง
```
duration = pulseIn(ECHO_PIN, HIGH);
```
- cm
```
distance = (duration/2) / 29.1;
```
- inch
```
distance = (duration/2) / 74;
```