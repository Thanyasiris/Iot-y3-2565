//Infrared photoelectric sensor

/* สงสัยว่าตัวอย่างน่าจะผิด เพราะจากโค้ดแสดงผล Collision Detected. ตอนไม่มีอะไรขวาง แล้วแสดงค่า No Collision Detected. ตอนมีสิ่งกีดขวาง
const int e18Pin =3;
int statusVal = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(e18Pin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  statusVal = digitalRead(e18Pin);
  if(statusVal == LOW){
    Serial.println("Collision Detected. ");
  }else{
    Serial.println("No Collision Detected. ");
  }
}
*/

//LED
int ledPin = 13;
//Infrared
const int e18Pin =3;
int statusVal = 0;

void setup() {
  // put your setup code here, to run once:
  //Infrared
  pinMode(e18Pin,INPUT);
  //LED
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  statusVal = digitalRead(e18Pin);
  if(statusVal == LOW){
    //ไม่มีสิ่งกีดขวาง ให้ไฟดับ
    Serial.println("No Collision Detected. ");
    digitalWrite(ledPin, LOW);
  }else{
    //มีสิ่งกีดขวาง ให้ไฟสว่าง
    Serial.println("Collision Detected. ");
    digitalWrite(ledPin, HIGH);
  }
  delay(100);
}