#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include <NewPing.h>
#define SONAR_NUM 1      // Number of sensors.
#define MAX_DISTANCE 700
NewPing sonar[SONAR_NUM] = {   // Sensor object array.
  NewPing(9, 9, MAX_DISTANCE), // Each sensor's trigger pin, echo pin, and max distance to ping. 
};
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

SoftwareSerial mySerial(7, 10); // RX, TX

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
 pinMode(8, INPUT);
 pinMode(6, OUTPUT);
 digitalWrite(6,HIGH);
  digitalWrite(13,HIGH);
 delay(1000);
  lcd.begin(16, 2);
  lcd.print("   SCANNING");
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(115200);
 // mySerial.println("Hello, world?");
}

void loop(){
for (uint8_t i = 0; i < SONAR_NUM; i++) { // Loop through each sensor and display results.
    delay(30); // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
    Serial.print(i);
    Serial.print("=");
    Serial.print(sonar[i].ping_cm());
    Serial.print("cm ");
  }


/////////////////////////////////////



int s1=sonar[0].ping_cm();
Serial.print(sonar[0].ping_cm());
Serial.print(' ');
int a= digitalRead(8);
if(a==0)
{
   digitalWrite(13,LOW);
  mySerial.write('2');
  lcd.setCursor(4, 0);
 lcd.print(" CRACK! ");
 lcd.setCursor(4,1);
 lcd.print("DETECTED!");
 delay(1000);
  digitalWrite(13,HIGH);
 lcd.clear();
}
if(s1<50)
{
   digitalWrite(13,LOW);
  mySerial.write('1');
 digitalWrite(6,LOW);
 lcd.setCursor(4,0);
 lcd.print("OBSTACLE");
 // delay(1000);
 lcd.setCursor(4, 1);
 lcd.print("DETECTED");
 
 delay(2000);
 lcd.clear();
 lcd.print("    stopped");
 delay(2000);
 lcd.clear();
 
}


lcd.clear();
lcd.setCursor(4, 0);
 lcd.print("SCANNING");
 lcd.setCursor(0, 1);
lcd.print("                "); 
//lcd.clear();
delay(2000);
Serial.print(a);
Serial.println();

}
