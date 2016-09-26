#include <SPI.h>
#include <Ethernet.h>
#include <SendCarriots.h>         // You must include the library here in order to use it in the sketch

const String APIKEY="e230195da9528de4425f7d95c0e57e5c2fd6161d4dcfda76f536a6a9bd938d79"; 		// Replace with your Carriots apikey
const String DEVICE="defaultDevice@jcdonelson.jcdonelson"; 		// Replace with the id_developer of your device
      
const int numElements=3;				// Specify the number of rows in your array, in this case 3


SendCarriots sender;              // Instantiate an instance of the SendCarriots library

void setup() {
  Serial.begin(9600);             	// Start serial port
  Serial.println(F("Starting"));

  

}

void loop() {
  String array[numElements][2] = {{"Name", "James"}, {"Age", "28"}, {"Gender", "Male"}};  // Define the values of the array to be sent
  Serial.println(sender.send(array, numElements, APIKEY, DEVICE));                 // Using the instance of the library, call the method send
  delay(5000);                                                                								 // Send this stream every 10 seconds
}
