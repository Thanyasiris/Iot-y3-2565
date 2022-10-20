# Infrared photoelectric sensor

เซนเซอร์ที่ใช้ลำแสง Infrared ในการตรวจจับวัตถุ

## connect
VCC(brown), GND(blue), DATA Input(black)

## code
```C++
const int e18Pin = <digitalPin>;
```
### void setup()
```C++
pinMode(e18Pin,INPUT);
```
### void loop()
อ่านค่า
```C++
statusVal = digitalRead(e18Pin);
```
- ไม่มีสิ่งกีดขวาง
```C++
statusVal == LOW
```
- มีสิ่งกีดขวาง
```C++
statusVal == HIGH
```