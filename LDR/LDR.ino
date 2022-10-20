//LDR Sensor 
//วัดค่าระดับความเข้มของแสง เป็นค่า 0-1023
/*
ให้แบ่งระดับค่าความสว่างเป็น 4 ระดับซึ่งแต่ละช่วงระดับ จะมีหลอด LED ไว้สำหรับการแสดงผล โดยมีข้อกำหนดดังนี้
 ระดับที่ 1 ให้ LED1 ติด / LED2, LED3, LED4 ดับ
 ระดับที่ 2 ให้ LED1, LED2 ติด / LED3, LED4 ดับ
 ระดับที่ 3 ให้ LED1, LED2, LED3 ติด / LED4 ดับ
 ระดับที่ 4 ให้ LED1, LED2, LED3, LED4 ติด 
*/
//หลอดไฟ
int ledPin1 = 3;
int ledPin2 = 4;
int ledPin3 = 5;
int ledPin4 = 6;
//ค่าสูงสุดที่วัดได้คือ 1023 แบ่งเป็น 4 ระดับ จึงให้ con = 1023/4
float con = 1023/4;
//LDR Sensor
int analogPin = 5;
int val = 0;
void setup() {
  // put your setup code here, to run once:
  //หลอดไฟ
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //อ่านค่าความเข้มของแสงจาก LDR Sensor ยิ่งสว่งมากค่ายิ่งมาก
  val = analogRead(analogPin);
  Serial.print("LDR = ");
  Serial.println(val);

  if(val < con ){
    //ระดับที่ 1 ค่า 0-255 ให้ LED1 ติด / LED2, LED3, LED4 ดับ
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    Serial.println("LED ON 1");
    Serial.println();
  }
  else if(val < con*2){
    //ระดับที่ 2 ค่า 256-511 ให้ LED1, LED2 ติด / LED3, LED4 ดับ
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    Serial.println("LED ON 1,2");
    Serial.println();
  }
  else if(val < con*3){
    //ระดับที่ 3 ค่า 512-767 ให้ LED1, LED2, LED3 ติด / LED4 ดับ
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, LOW);
    Serial.println("LED ON 1,2,3");
    Serial.println();
  }
  else{
    //ระดับที่ 4 ค่า 768-1023 ให้ LED1, LED2, LED3, LED4 ติด 
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    Serial.println("LED ON 1,2,3,4");
    Serial.println();
  }
  delay(1000);
}
