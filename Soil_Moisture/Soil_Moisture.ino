//Soil Moisture Sensor 
//วัดความชื้นในดิน อ่านค่าความชื้นได้ตั้งแต่ 0 ถึง 1024
/*
ให้แสดงค่าความชื้นในดินที่ตรวจวัดได้ จากนั้นนำค่าความชื้นในดินมาเปรียบเทียบกับค่าระดับความชื้น ซึ่งมีค่าระดับความชื้นในการเปรียบเทียบที่ 50%   โดยมีหลอด LED ไว้สำหรับการแสดงผล  2  หลอด มีข้อกำหนดดังนี้
	1 มีค่าความชื้นในดิน > 50 % ให้ LED1 ติด / LED2 ดับ
  2 มีค่าความชื้นในดิน <= 50 % ให้ LED1 ดับ/ LED2 ติด
 ** กรณีไม่มีค่าความชื้นเลย ให้ LED1 และ LED2 ดับ
*/

//LED
int ledPin1 = 8;
int ledPin2 = 9;
//Soil Moisture Sensor
int sensorPin = A0;
int sensorValue;
//อ่านค่าความชื้นได้สูงสุด 1024
int max = 1024;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //LED
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin);
  if(sensorValue == 0){
    //กรณีไม่มีค่าความชื้นเลย ให้ LED1 และ LED2 ดับ
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
  }
  else if(sensorValue < max*0.5){
    //1 มีค่าความชื้นในดิน > 50 % ให้ LED1 ติด / LED2 ดับ
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
  }
  else{
    //2 มีค่าความชื้นในดิน <= 50 % ให้ LED1 ดับ/ LED2 ติด
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
  }
  Serial.print("Analog Value : ");
  Serial.println(sensorValue);
  delay(1000);
}

//ไม่ได้ลองเพราะไม่มี Soil Moisture Sensor