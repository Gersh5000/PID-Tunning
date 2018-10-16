#include <SoftwareSerial.h>

int Kp = 0;
int Kd = 0;
int Ki = 0;

char c=' ';
boolean NL = true;
SoftwareSerial BTSerial (12,13);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (BTSerial.available()) {
    c = BTSerial.read();
    switch (c) {
      case 'kpadd10':
        Serial.write("Command <kpadd10> recieved");
        Values();
        Kp += 10;
        break;
      case 'kdadd1':
        Serial.write("Command <kdadd1> recieved");
        Kd += 1;
        Values();
        break;
      case 'kiadd10':
        Serial.write("Command <kiadd10> recieved");
        Ki += 10;
        Values();
        break;
      case 'kpadd1':
        Serial.write("Command <kpadd1> recieved");
        Values();
        Kp += 1;
        break;
      case 'kdadd01':
        Serial.write("Command <kdadd01> recieved");
        Kd += 0.1;
        Values();
        break;
      case 'kiadd1':
        Serial.write("Command <kiadd1> recieved");
        Ki += 1;
        Values();
        break;
      case 'kpadd01':
        Serial.write("Command <kpadd01> recieved");
        Values();
        Kp += 0.1;
        break;
      case 'kdadd001':
        Serial.write("Command <kdadd001> recieved");
        Kd += 0.01;
        Values();
        break;
      case 'kiadd01':
        Serial.write("Command <kiadd01> recieved");
        Ki += 0.1;
        Values();
        break;

      case 'kpsub10':
        Serial.write("Command <kpsub10> recieved");
        Values();
        Kp -= 10;
        break;
      case 'kdsub1':
        Serial.write("Command <kdsub1> recieved");
        Kd -= 1;
        Values();
        break;
      case 'kisub10':
        Serial.write("Command <kisub10> recieved");
        Ki -= 10;
        Values();
        break;
      case 'kpsub1':
        Serial.write("Command <kpsub1> recieved");
        Values();
        Kp -= 1;
        break;
      case 'kdsub01':
        Serial.write("Command <kdsub01> recieved");
        Kd -= 0.1;
        Values();
        break;
      case 'kisub1':
        Serial.write("Command <kisub1> recieved");
        Ki -= 1;
        Values();
        break;
      case 'kpsub01':
        Serial.write("Command <kpsub01> recieved");
        Values();
        Kp -= 0.1;
        Values();
        break;
      case 'kdsub001':
        Serial.write("Command <kdsub001> recieved");
        Kd -= 0.01;
        Values();
        break;
      case 'kisub01':
        Serial.write("Command <kisub01> recieved");
        Ki -= 0.1;
        Values();
        break;
    }
    Serial.write(c);
  }
  if (Serial.available())
    {
        c = Serial.read();
 
        // do not send line end characters to the HM-10
        if (c!=10 & c!=13 ) 
        {  
             BTSerial.write(c);
        }
 
        // Echo the user input to the main window. 
        // If there is a new line print the ">" character.
        if (NL) { Serial.print("\r\n>");  NL = false; }
        Serial.write(c);
        if (c==10) { NL = true; }
    }
}
void Values() {
  char out = "Kp = ";
  AppendChar(out, Kp);
  AppendChar(out, " Kd = ");
  AppendChar(out, Kd);
  AppendChar(out, " Ki = ");
  AppendChar(out, Ki);
  BTSerial.write(out);
}

char AppendChar(char c, char v) {
  char value [sizeof(c) + sizeof(v)] = "";
  strcat(value, c);
  strcat(value, v);
  return value;
}
