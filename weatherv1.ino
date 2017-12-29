
// Include required libraries
#include <DHT.h>
#include <LiquidCrystal.h>

// DHT11 sensor pin
#define DHTPIN A1     
#define DHTTYPE DHT22   // Define type of DHT module, DHT11 or DHT22 for example
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal lcd (7,8,9,10,11,12);


void setup() {
dht.begin();  //starts dht hardware
Serial.begin(9600);  //starts serial output to computer

lcd.begin(16,2);  //defines LCD size
}

void loop() {

float t = dht.readTemperature(); //temp in C
float h = dht.readHumidity();
float tf = ((t*1.8)+32); //temp in F


// LCD output ----- This is the data output to the LCD
lcd.clear();
lcd.setCursor(0,0);   //sets cursor for Temp
lcd.print("Temp:      ");
lcd.print(tf,1);
lcd.print("F");

lcd.setCursor(0,1);  //sets cursor for Humidity
lcd.print("Humidity:    ");
lcd.print(h,0);
lcd.print("%");

delay (4000);
}


