	#include <TFT.h>  // Arduino LCD library
	#include <SPI.h>
	
	//Pini ecran
	#define cs   10 
	#define dc  9
	#define rst  8
	
	//pini senzor culoare 
	int red = 0;  
	int green = 0;  
	int blue = 0;
	
	int s_zero = 7;
	int s_unu = 6;
	int s_doi = 5;
	int s_trei = 4;
	int Sensor_out = 12;
	
	// create an instance of the library
	TFT TFTscreen = TFT(cs, dc, rst);
	
	void setup() {
	  //initializam pinii de la senzorul de culoare
	  pinMode(s_zero, OUTPUT);  
	  pinMode(s_unu, OUTPUT);  
	  pinMode(s_doi, OUTPUT);  
	  pinMode(s_trei, OUTPUT);  
	  pinMode(Sensor_out, INPUT);
	
	  digitalWrite(s_zero, HIGH);  
	  digitalWrite(s_unu, HIGH); 
	
	  // Put this line at the beginning of every sketch that uses the GLCD:
	  TFTscreen.begin();
	
	  // clear the screen with a black background
	  TFTscreen.background(0, 0, 0);
	
	  // write the static text to the screen
	  // set the font color to white
	  TFTscreen.stroke(255, 255, 255);
	  // set the font size
	  TFTscreen.setTextSize(2);
	  // write the text to the top left corner of the screen
	  TFTscreen.text("Culoare",22,10);
	  // ste the font size very large for the loop
	  TFTscreen.setTextSize(3);
	}
	
	void loop() {
	  digitalWrite(s_doi, LOW);  
	  digitalWrite(s_trei, LOW);
	
	  //citire de pe senzor
	  red = pulseIn(Sensor_out, digitalRead(Sensor_out) == HIGH ? LOW : HIGH);
	  digitalWrite(s_trei, HIGH);
	  blue = pulseIn(Sensor_out, digitalRead(Sensor_out) == HIGH ? LOW : HIGH);  
	  digitalWrite(s_doi, HIGH);
	  green = pulseIn(Sensor_out, digitalRead(Sensor_out) == HIGH ? LOW : HIGH);
	
	  if (red < blue && red < green && red < 20)//culoare rosie
	{  
	    TFTscreen.stroke(255, 10, 15);//rosu verde albastru
	  // print the sensor value
	    TFTscreen.text("Red", 45, 100);
	    TFTscreen.fill(255, 10, 15);//umplem cercul
	    TFTscreen.circle(65, 60, 30);
	    TFTscreen.fill(255, 255, 255);//umplem cercul
	    TFTscreen.circle(44, 50, 5);//ochii
	    TFTscreen.circle(74, 50, 5);
	
	    TFTscreen.circle(60, 70, 12);//gura
	    TFTscreen.fill(255, 10, 15);
	    TFTscreen.circle(60, 63, 12);
	
	    delay(250);
	    // erase the text you just wrote
	    TFTscreen.stroke(0, 0, 0);
	    TFTscreen.text("Red", 45, 100);
	    TFTscreen.fill(0, 0, 0);
	    TFTscreen.circle(65, 60, 30);
	  }  
	
	  else if (blue < red && blue < green)   //culoare albastru
	  {  
	    TFTscreen.stroke(10, 10, 255);//rosu verde albastru
	  // print the sensor value
	    TFTscreen.text("Blue", 30, 100);
	    TFTscreen.fill(10, 10, 255);//umplem cercul
	    TFTscreen.circle(65, 60, 30);
	    TFTscreen.fill(255, 255, 255);//umplem cercul
	    TFTscreen.circle(44, 50, 5);//ochii
	    TFTscreen.circle(74, 50, 5);
	
	    TFTscreen.circle(60, 70, 12);//gura
	    TFTscreen.fill(10, 10, 255);
	    TFTscreen.circle(60, 63, 12);
	
	    delay(500);
	    // erase the text you just wrote
	    TFTscreen.stroke(0, 0, 0);
	    TFTscreen.text("Blue", 30, 100);
	    TFTscreen.fill(0, 0, 0);
	    TFTscreen.circle(65, 60, 30);
	  }  
	
	  else if (green < red && green < blue)  //culoare verde
	  {  
	    TFTscreen.stroke(10, 240, 10);//rosu verde albastru
	  // print the sensor value
	    TFTscreen.text("Green", 25, 100);
	    TFTscreen.fill(10, 240, 10);//umplem cercul
	    TFTscreen.circle(65, 60, 30);
	
	    TFTscreen.fill(255, 255, 255);//umplem cercul
	    TFTscreen.circle(44, 50, 5);//ochii
	    TFTscreen.circle(74, 50, 5);
	    TFTscreen.circle(60, 70, 12);//gura
	    TFTscreen.fill(10, 240, 10);
	    TFTscreen.circle(60, 63, 12);
	
	    //umplem cercul
	    delay(500);
	    // erase the text you just wrote
	    TFTscreen.stroke(0, 0, 0);
	    TFTscreen.text("Green", 25, 100);
	    TFTscreen.fill(0, 0, 0);
	    TFTscreen.circle(65, 60, 30);
	    
	  }  
	  delay(500);
