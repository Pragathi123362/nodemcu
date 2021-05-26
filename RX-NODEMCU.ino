/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>

String apiKey = "43DVNFOLNRCLY83N";     //  Enter your Write API key from ThingSpeak


const char* server = "api.thingspeak.com";

int temp1 = 35, tur = 4, turbid = 50, tds = 60, t = 21, t1 = 49, tds1 = 900,temp=20;
WiFiClient client;
//if ((turbidity > 20) && (turbidity < 50))
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "XRfw6L-UZmjiaILjTGdI33-hjynUy1QD";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "hii";
char pass[] = "Lucky12345";
//Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

WidgetLCD lcd(V1);

void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

}

void loop() {
  int val;
  while (!Serial.available()) {}
  //delay(100); //allows all serial sent to be received together
  byte b1 = Serial.read();
  val = b1  ;
  Blynk.run();

  Serial.println("val:");
  Serial.println(val);

  if ((val > temp) && (val < temp1))
  {
    lcd.clear(); //Use it to clear the LCD Widget
    lcd.print(0, 0, "temp: ");
    lcd.print(8, 0, val); // use: (position X: 0-15, position Y: 0-1, "Message you want to print")
    // lcd.print(4, 1, "World");
    if (client.connect(server, 80))  //   "184.106.153.149" or api.thingspeak.com
    {
      Serial.println("tging");
      String postStr = apiKey;
      postStr += "&field1=";
      postStr += String(val);

      postStr += "\r\n\r\n";

      client.print("POST /update HTTP/1.1\n");
      client.print("Host: api.thingspeak.com\n");
      client.print("Connection: close\n");
      client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
      client.print("Content-Type: application/x-www-form-urlencoded\n");
      client.print("Content-Length: ");
      client.print(postStr.length());
      client.print("\n\n");
      client.print(postStr);

      Serial.print("Temperature: ");
      Serial.print(val);
      //                             Serial.print(" degrees Celcius, Humidity: ");
      //                             Serial.print(h);
      Serial.println("%. Send to Thingspeak.");
    }
    client.stop();

    Serial.println("Waiting...");

    // thingspeak needs minimum 15 sec delay between updates, i've set it to 30 seconds
    delay(6000);
  }
  if (val<=tur)
  {
    lcd.clear(); //Use it to clear the LCD Widget
    lcd.print(0, 0, "turbidity: ");
    lcd.print(11, 0, val); // use
    lcd.print(0, 1, "water is clean");
    if (client.connect(server, 80))  //   "184.106.153.149" or api.thingspeak.com
    {

      String postStr = apiKey;

      postStr += "&field2=";
      postStr += String(val);
      postStr += "\r\n\r\n";

      client.print("POST /update HTTP/1.1\n");
      client.print("Host: api.thingspeak.com\n");
      client.print("Connection: close\n");
      client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
      client.print("Content-Type: application/x-www-form-urlencoded\n");
      client.print("Content-Length: ");
      client.print(postStr.length());
      client.print("\n\n");
      client.print(postStr);

      Serial.print("Turbidity ");
      Serial.print(val);
      //                             Serial.print(" degrees Celcius, Humidity: ");
      //                             Serial.print(h);
      Serial.println("%. Send to Thingspeak.");
    }
    client.stop();

    Serial.println("Waiting...");

    // thingspeak needs minimum 15 sec delay between updates, i've set it to 30 seconds
    delay(6000);
  }
  if (tds < val)
  {
    lcd.clear(); //Use it to clear the LCD Widget
    lcd.print(0, 0, "TDS: ");
    lcd.print(8, 0, val); // use
    lcd.print(0, 1, " good minerals");
    if (client.connect(server, 80))  //   "184.106.153.149" or api.thingspeak.com
    {

      String postStr = apiKey;

      postStr += "&field3=";
      postStr += String(val);
      postStr += "\r\n\r\n";

      client.print("POST /update HTTP/1.1\n");
      client.print("Host: api.thingspeak.com\n");
      client.print("Connection: close\n");
      client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
      client.print("Content-Type: application/x-www-form-urlencoded\n");
      client.print("Content-Length: ");
      client.print(postStr.length());
      client.print("\n\n");
      client.print(postStr);

      Serial.print("Tds: ");
      Serial.print(val);
      //                             Serial.print(" degrees Celcius, Humidity: ");
      //                             Serial.print(h);
      Serial.println("%. Send to Thingspeak.");
    }
    client.stop();

    Serial.println("Waiting...");

    // thingspeak needs minimum 15 sec delay between updates, i've set it to 30 seconds
    delay(6000);
  }
  if (tds1 < val)
  {
    lcd.clear(); //Use it to clear the LCD Widget
    lcd.print(0, 0, "TDS: ");
    lcd.print(8, 0, val); // use
    lcd.print(0, 1, " high minerals");
    if (client.connect(server, 80))  //   "184.106.153.149" or api.thingspeak.com
    {

      String postStr = apiKey;

      postStr += "&field3=";
      postStr += String(val);
      postStr += "\r\n\r\n";

      client.print("POST /update HTTP/1.1\n");
      client.print("Host: api.thingspeak.com\n");
      client.print("Connection: close\n");
      client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
      client.print("Content-Type: application/x-www-form-urlencoded\n");
      client.print("Content-Length: ");
      client.print(postStr.length());
      client.print("\n\n");
      client.print(postStr);

      Serial.print("Tds: ");
      Serial.print(val);
      //                             Serial.print(" degrees Celcius, Humidity: ");
      //                             Serial.print(h);
      Serial.println("%. Send to Thingspeak.");
    }
    client.stop();

    Serial.println("Waiting...");

    // thingspeak needs minimum 15 sec delay between updates, i've set it to 30 seconds
    delay(6000);
  }
  if ((t > 40) && (t1 < 50))
  {
    lcd.clear(); //Use it to clear the LCD Widget
    lcd.print(0, 0, "turbidity: ");
    lcd.print(11, 0, val); // use
    lcd.print(0, 1, "water is cloudy");
    if (client.connect(server, 80))  //   "184.106.153.149" or api.thingspeak.com
    {

      String postStr = apiKey;

      postStr += "&field2=";
      postStr += String(val);
      postStr += "\r\n\r\n";

      client.print("POST /update HTTP/1.1\n");
      client.print("Host: api.thingspeak.com\n");
      client.print("Connection: close\n");
      client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
      client.print("Content-Type: application/x-www-form-urlencoded\n");
      client.print("Content-Length: ");
      client.print(postStr.length());
      client.print("\n\n");
      client.print(postStr);

      Serial.print("Turbidity: ");
      Serial.print(val);
      //                             Serial.print(" degrees Celcius, Humidity: ");
      //                             Serial.print(h);
      Serial.println("%. Send to Thingspeak.");
    }
    client.stop();

    Serial.println("Waiting...");

    // thingspeak needs minimum 15 sec delay between updates, i've set it to 30 seconds
    delay(6000);
  }

}
//void call()
//{
//
//}


