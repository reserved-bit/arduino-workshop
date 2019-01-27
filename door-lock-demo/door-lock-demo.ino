#include<SoftwareSerial.h>
int relay=6;
char rx_byte=0;
SoftwareSerial bt(2,3);

void setup() {
  bt.begin(9600);
  Serial.begin(9600);
  pinMode(relay,OUTPUT);
  digitalWrite(relay,HIGH);
  Serial.print("Enter the password to open/close door (Hint: it's 1234!)\n");
}

void loop() {
  String r;
  if (bt.available()) {
    r=bt.readStringUntil('\n');
    String msg="DEBUG:Received from BT:\'";
    msg.concat(r);
    msg.concat("\'\n");
    Serial.write (msg.c_str());
    
    if (r[0] == '1' && r[1] == '2' && r[2] == '3' && r[3] == '4') {
        Serial.write("Success\n");
        digitalWrite (relay,LOW);
        delay(600);
        digitalWrite (relay,HIGH);
    }
    else {
        Serial.write("Invalid Password\n");
    }
  }
}
