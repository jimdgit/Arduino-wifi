#include <WiFi101.h>
#include <WiFiClient.h>
#include <WiFiMDNSResponder.h>
#include <WiFiServer.h>
#include <WiFiSSLClient.h>
#include <WiFiUdp.h>


#include <SPI.h>


#include <UbidotsArduino.h>

#define ID  "57e8172c7625420c757e27e8"  // Put here your Ubidots variable ID
#include "../../../../secure/data.cpp"
int keyIndex = 0;            // your network key Index number (needed only for WEP)

int status = WL_IDLE_STATUS;

Ubidots client(TOKEN);

void setup(){
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
        while (status != WL_CONNECTED)
        delay(1000);
    }
        
}
float counter = 10;
void loop(){
        float value = counter;
        ++counter;
        Serial.print("Value: ");
        Serial.println(value);
        Serial.print("To: ");
        Serial.println(ID);        
        client.add(ID, value);
        client.sendAll();
        delay(60000);
}
