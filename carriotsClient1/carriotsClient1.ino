#include <SendCarriots.h>

/*
  Web client

 This sketch connects to a website (http://www.google.com)
 using a WiFi shield.

 This example is written for a network using WPA encryption. For
 WEP or WPA, change the Wifi.begin() call accordingly.

 This example is written for a network using WPA encryption. For
 WEP or WPA, change the Wifi.begin() call accordingly.

 Circuit:
 * WiFi shield attached

 created 13 July 2010
 by dlf (Metodo2 srl)
 modified 31 May 2012
 by Tom Igoe
 */


#include <SPI.h>
#include <WiFi101.h>

#include "../../../../secure/data.cpp"
int keyIndex = 0;            // your network key Index number (needed only for WEP)
const String APIKEY="e230195da9528de4425f7d95c0e57e5c2fd6161d4dcfda76f536a6a9bd938d79";     // Replace with your Carriots apikey
const String DEVICE="defaultDevice@jcdonelson.jcdonelson";    // Replace with the id_developer of your device
      
const int numElements=3;        // Specify the number of rows in your array, in this case 3


SendCarriots sender;              // Instantiate an instance of the SendCarriots library

int status = WL_IDLE_STATUS;
// if you don't want to use DNS (and reduce your sketch size)
// use the numeric IP instead of the name for the server:
//IPAddress server(74,125,232,128);  // numeric IP for Google (no DNS)
char server[] = "www.google.com";    // name address for Google (using DNS)

// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
WiFiClient client;

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue:
    while (true);
  }

  // attempt to connect to Wifi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
     while (status != WL_CONNECTED) {
       delay(1000);
     }
  }
  Serial.println("Connected to wifi");
  printWifiStatus();

  
}


void loop() {
  String array[numElements][2] = {{"Name", "Jim D."}, {"Age", "62"}, {"Gender", "Male"}};  // Define the values of the array to be sent
  Serial.println(sender.send(client,array, numElements, APIKEY, DEVICE));                 // Using the instance of the library, call the method send
  delay(5000);                                                                                 // Send this stream every 10 seconds

}


void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}





