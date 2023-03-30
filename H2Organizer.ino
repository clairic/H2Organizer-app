#include <SoftwareSerial.h>
int bluetoothTx = 2;
int bluetoothRx = 3;
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

int sensorPin = A0;
int thresholdUp = 400;
int thresholdDown = 250;

void setup()
{
 //Setup usb serial connection to computer
 Serial.begin(9600);
 //Setup Bluetooth serial connection to android
 bluetooth.begin(115200);
 bluetooth.print("$$$");
 delay(100);
 bluetooth.println("U,9600,N");
 bluetooth.begin(9600);
}
void loop()
{
  int sensorValue;
  sensorValue = analogRead(sensorPin);
  String DisplayWords_a;
  String DisplayWords_b;
  String DisplayWords_c;
  Serial.println(sensorValue);
  delay(2000);
  
 //Read from bluetooth and write to usb serial
 if(bluetooth.available())
 {
 char toSend = (char)bluetooth.read();
 //bluetooth.print(sensorValue);
 
  if (sensorValue <= thresholdDown){
      
      DisplayWords_a = "This plant is thirsty!\nYou have to water it.";
      bluetooth.println("\n");
      bluetooth.println(DisplayWords_a);
  
  } else if (sensorValue >= thresholdUp){ 
      
      DisplayWords_b = "This plant is alright!";  
      bluetooth.println(DisplayWords_b);
  
  } else {

      DisplayWords_c = "Error";
      bluetooth.println(DisplayWords_c);
  
  }

 Serial.print(toSend);
 delay(1000);

 }
 //Read from usb serial to bluetooth
 if(Serial.available())
 {
 char toSend = (char)Serial.read();
 bluetooth.print(toSend);
 Serial.print(toSend);
 }
}
