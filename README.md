# สรุป Arduino

ฉบับจำง่ายๆ ถูกมั้ยไม่รู้

## connect
อิงจาก arduino uno
- GND หรือที่เรียกว่า ground ที่บอร์ดก็เขียน GND ที่โมดูลก็เขียน GND
- VCC ที่บอร์ดเขียน 5V ที่โมดูลเขียน VCC
- Digital อยู่ฝั่งเลขเฉยๆเป็นได้ทั้ง input,output ใช้กับสัญญาณ digital
- Analog อยู่ฝั่งที่มี A ก่อนเลข มักใช้กับ input ที่ได้ค่าเป็นตัวเลข

2 อันหลังตอนเสียบเลือกเลขที่ชอบได้เลย แต่ต้องมากำหนดในโค้ดให้ถูก

*LED จำว่า ขาสั้น GND ขายาว Digital
## code
มีหลักๆ 3 ส่วน
- [นอกทุกอย่าง](####1.-ด้านนอก) ปกติไว้กำหนด pin
- [ใน void setup()](####2.void-setup()) มักใช้กำหนด digital pin ว่าเป็น input หรือ output
- [void loop()](####3.void-loop()) ไว้ใส่โค้ดสั่งงาน

โครงคร่าวๆ
```
/* 1. code */
void setup() {
  /* 2. code */
  Serial.begin(9600);
  /* 2. code */
}

void loop() {
  /* 3. code */
  delay(1000);
}
```
### ตัวอย่าง
#### 1. ด้านนอก
input analog ไม่ชัวร์ว่าแต่ละอันต่างกันยังไง
```C++
const int e18Pin =3;
```
```C++
int sensorPin = A0;
```
digital
```C++
int ledPin = 8;
```
```C++
int analogPin = 5;
```
```C++
const unsigned int TRIG_PIN=4;
const unsigned int ECHO_PIN=2;
```
#### 2.void setup()
digital input
```
pinMode(e18Pin, INPUT);
```
digital output
```
pinMode(ledPin, OUTPUT);
```
#### 3.void loop()
อ่านค่า
```
val = digitalRead(e18Pin);
```
```
val = analogRead(analogPin);
```
print
```
Serial.print("val = ");
Serial.println(val);
```
เปิดไฟ
```
digitalWrite(ledPin1, HIGH);
```
ปิดไฟ
```
digitalWrite(ledPin2, LOW);
```
