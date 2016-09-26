#ifndef SENDCARRIOTS_H_
#define SENDCARRIOTS_H_

#include <Arduino.h>
#include <Client.h>
#include <WiFi101.h>

class SendCarriots{
	public:
		//definition of a public class that will form a JSON from the array sent
		String send(WiFiClient client, String array[][2], int elements, String apikey, String device);
};

#endif
