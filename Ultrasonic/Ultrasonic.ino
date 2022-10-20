//Ultrasonic Sensor HY-SRF05
//วัดระยะระยะห่างจากอุปกรณ์ได้ตั้งแต่ 2cm ถึง 450cm 
/*
ให้แสดงค่า distance แบบ inch จากนั้นแบ่งระดับระยะของ distance เป็น 4 ระยะ โดยมีหลอด LED ไว้สำหรับการแสดงผล มีข้อกำหนดดังนี้
 ระยะที่ 1 มีค่าระยะห่างจากวัตถุ อยู่ที่ 0-25%ของระยะห่างสูงสุด  ให้ LED1 ติด / LED2, LED3, LED4 ดับ
 ระดับที่ 2 มีค่าระยะห่างจากวัตถุ อยู่ที่ 26%-50%ของระยะห่างสูงสุด ให้ LED1, LED2 ติด / LED3, LED4 ดับ
 ระดับที่ 3 มีค่าระยะห่างจากวัตถุ อยู่ที่ 51%-75%ของระยะห่างสูงสุด ให้ LED1, LED2, LED3 ติด / LED4 ดับ
 ระดับที่ 4 มีค่าระยะห่างจากวัตถุ อยู่ที่ 76%-100%ของระยะห่างสูงสุด ให้ LED1, LED2, LED3, LED4 ติด 
*/

//Ultrasonic
const unsigned int TRIG_PIN=4;
const unsigned int ECHO_PIN=2;
//LED
int ledPin1 = 8;
int ledPin2 = 9;
int ledPin3 = 10;
int ledPin4 = 11;
//ระยะห่างสูงสุดที่วัดได้
int max = 450;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Ultrasonic
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  //LED
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, distance, distanceInch;
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN,LOW);

  /*
    การคำนวณระยะห่างระหว่างวัตถุเป้าหมายกับเซ็นเซอร์ 
    ใช้สูตร D=1/2 T×C 
    โดยที่ T คือ เวลาระหว่างตัวส่งและตัวรับ 
          C คือ ความเร็วของเสียง
    แปลงเป็น Centimeter 1/29.1
    แปลงเป็น inch 1/74
  */
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration/2) / 29.1;

  //แสดงค่า distance แบบ inch
  distanceInch = (duration/2) / 74;
  Serial.print("distance(inch): ");
  Serial.println(distanceInch);
  if(distance < max*0.25 ){
    //ระยะที่ 1 มีค่าระยะห่างจากวัตถุ อยู่ที่ 0-25%ของระยะห่างสูงสุด  ให้ LED1 ติด / LED2, LED3, LED4 ดับ
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    Serial.println("LED ON 1 \n");
  }
  else if(distance < max*0.50){
    //ระดับที่ 2 มีค่าระยะห่างจากวัตถุ อยู่ที่ 26%-50%ของระยะห่างสูงสุด ให้ LED1, LED2 ติด / LED3, LED4 ดับ
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    Serial.println("LED ON 1,2 \n");
    Serial.println();
  }
  else if(distance < max*0.75){
    //ระดับที่ 3 มีค่าระยะห่างจากวัตถุ อยู่ที่ 51%-75%ของระยะห่างสูงสุด ให้ LED1, LED2, LED3 ติด / LED4 ดับ
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, LOW);
    Serial.println("LED ON 1,2,3 \n");
  }
  else{
    //ระดับที่ 4 มีค่าระยะห่างจากวัตถุ อยู่ที่ 76%-100%ของระยะห่างสูงสุด ให้ LED1, LED2, LED3, LED4 ติด 
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    Serial.println("LED ON 1,2,3,4 \n");
  }

  delay(1000);
}
