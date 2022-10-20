# LDR Sensor

วัดค่าระดับความเข้มของแสง เป็นค่า 0-1023

## connect
Analog In, GND

## code
```C++
int analogPin = <analogPin>;
```
### void setup()
```C++

```
### void loop()
อ่านค่า สว่างมาก -> ค่ามาก
```C++
val = analogRead(analogPin);
```