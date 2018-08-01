#include <Servo.h>

class Servo2
{
  public:
    Servo2( int restingPos, int foreLim, int backLim) {
      this->currentPos = restingPos;
      this->restingPos = restingPos;
      this->foreLim = foreLim;
      this->backLim = backLim;
    }
    void attach(int i) {
      servo.attach(i);
      write(restingPos);
    }
    void write(int i) {
      servo.write(i);
      currentPos = i;
      Serial.println(currentPos);
    }

    void step(){
      if (currentPos == restingPos) currentPos = foreLim;
      else if (currentPos == foreLim) currentPos = backLim;
      else if (currentPos == backLim) currentPos = foreLim;
      write(currentPos);
    }

    void rest(){
      currentPos = restingPos;
      write(currentPos);
    }

    void forward(){
      currentPos = foreLim;
      write(currentPos);
    }

    void backward(){
      currentPos = backLim;
      write(currentPos);
    }
    
    Servo servo;
    int currentPos;
    int restingPos;
    int foreLim;
    int backLim;
};

// setup: servo( int restingPos, int foreLim, int backLim) //

// old attributes
//Servo2 servoFR(75,90,60); 
//Servo2 servoBR(80,100,60);  
//Servo2 servoFL(75,55,85);  
//Servo2 servoBL(65,50,90);  

// new attributes
Servo2 servoFR(75,85,65); 
Servo2 servoBR(80,90,70);  
Servo2 servoFL(75,65,85);  
Servo2 servoBL(65,58,78);  

/////////////////////////////////////////////////////////////

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  servoFR.attach(9);              // tell servo to go to position in variable 'pos'
  servoBR.attach(8);              // tell servo to go to position in variable 'pos'

  servoFL.attach(7);              // tell servo to go to position in variable 'pos'
  servoBL.attach(6);              // tell servo to go to position in variable 'pos'


}

bool go = false;

void loop() {
  if (go) {

//    danceDanceYeah();
    testBed();

  }
    
}

void testBed() {
    int timeD = 90;

    servoFR.step(); 
    delay(timeD);
    
      
    servoBL.step();
    delay(timeD);

    servoFL.step(); 
    delay(timeD);
    

    servoFR.step(); 
    delay(timeD);    
    
    servoBR.step();
    delay(timeD);
    
    servoBL.step();
    delay(timeD);   

    servoFL.step(); 
    delay(timeD);
        
    servoBR.step();
    delay(timeD);
    
}


void danceDanceYeah() {
    // Right side oscillate 
    int timeD = 200;
    servoFR.step(); 
    delay(timeD);
    servoFR.step(); 
    delay(timeD);    
    servoBR.step();
    delay(timeD);
    servoBR.step();
    delay(timeD);

    // Left side oscillate 
    servoFL.step(); 
    delay(timeD);
    servoFL.step(); 
    delay(timeD);    
    servoBL.step();
    delay(timeD);
    servoBL.step();
    delay(timeD);    
}


void goBackward() {
    int timeD = 150;
    servoFL.step(); 
    delay(timeD);
    servoFR.step(); 
    delay(timeD);    
    servoBL.step();
    delay(timeD);   
    servoBR.step();
    delay(timeD);
    
    servoFL.step(); 
    delay(timeD);    
    servoFR.step(); 
    delay(timeD);
    servoBL.step();
    delay(timeD);
    servoBR.step();
    delay(timeD);  
}


void serialEvent() {
  char ch;
//  int input;
  if (Serial.available()) {
//    input = Serial.parseInt();
//    servoBL.write(input);
    ch = Serial.read();
  }
  switch (ch) {
    case 'q': // front left
      servoFL.step(); 
      break;
      
    case 'e': // front right
      servoFR.step(); 
      break;

    case 'z': // back left
      servoBL.step(); 
      break;

    case 'c': // back right
      servoBR.step(); 
      break;   

    case 'f': //push all legs forward
      servoFL.forward(); 
      servoFR.forward(); 
      servoBL.forward();
      servoBR.forward();
      break;

    case 'b': //push all legs forward
      servoFL.backward(); 
      servoFR.backward(); 
      servoBL.backward();
      servoBR.backward();
      break;

    case 's': // start program / stop program
      go = !go; 
      break;   

    case 'r': // reset
      servoFR.rest();              // tell servo to go to position in variable 'pos'
      servoBR.rest();              // tell servo to go to position in variable 'pos'

      servoFL.rest();              // tell servo to go to position in variable 'pos'
      servoBL.rest();              // tell servo to go to position in variable 'pos'
     
    break;   
  
  }

}

