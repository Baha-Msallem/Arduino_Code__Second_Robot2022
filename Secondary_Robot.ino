#include <Servo.h>
/////////////////////////Declaration1///////////////////////
int pompe_stat =27;
int ectrovanne =A0;
int pompe_catch =23;
int motor_f=4;
int motor_b=5;
#define resistor A1


/////////////////////////Class Definition///////////////////
class myservo {
  public:
  int minnn;
  int maxxx;
  int pin;
  int initial;
  Servo servo;
  myservo(){}
  myservo(int minn,int maxx,int initial,int pinn){
    this->minnn=minn;
    this->maxxx=maxx;
    this->pin=pinn;
    this->initial=initial;
    } 
///////////Class Functions/////////////////////////////      
    void up(){
      this->servo.attach(this->pin);
      this->servo.write(this->maxxx);
      }
/////////////////////////////       
     void down(){
      this->servo.attach(this->pin);
      this->servo.write(this->minnn);
      }
/////////////////////////////      
      void upFor(int x){
        this->servo.attach(this->pin);
      for(int i=this->servo.read();i<=this->maxxx;i++)
      {
        this->servo.write(i);
        delay(x);}
         }
/////////////////////////////         
      void upFor_i(int x,int y){
        this->servo.attach(this->pin);
      for(int i=this->servo.read();i<=y;i++)
      {
        this->servo.write(i);
        delay(x);}       
      }
/////////////////////////////  
     /* void doIt(){
        this->up();delay(1000);
       digitalWrite(pompe_stat,HIGH);
       this->down();
       delay(1000);
       this->up();
       delay(2000);
       this->down();
       delay(1000);
       digitalWrite(pompe_stat,LOW);
       delay(1000);
       this->up();delay(1000);
      }*/
/////////////////////////////      
      void downFor(int x){
      this->servo.attach(this->pin);
      for(int i=this->servo.read();i>=this->minnn;i--)
      {
        this->servo.write(i);
        delay(x);}
        }
/////////////////////////////          
      void downFor_i(int x,int y){
      this->servo.attach(this->pin);
      for(int i=this->servo.read();i>=y;i--)
      {
        this->servo.write(i);
        delay(x);}
        }
/////////////////////////////          
      void attachIt(){
      this->servo.attach(this->pin);
      }
/////////////////////////////        
      void attachIt_i(int x){
      this->servo.attach(this->pin);
      this->servo.write(x);
      }
/////////////////////////////       
      void detachIt(){
      this->servo.detach();
      }
/////////////////////////////  
      
  };
  
////////////////////Declaration servos/////////////////////
 myservo statuette;
 myservo fouille;
 myservo flip;
 myservo catchR;
 myservo catchL;
 myservo batraR;
 myservo batraL;
int pos = 0;    // variable to store the servo position*/

////////////////////Definition Sequence//////////////////

/////////////////////////////////////
void sequence_batratte(){
        batraR.attachIt_i(140);
        batraL.attachIt_i(40);}
//////////////////////////////////////       
void sequence_batratte_1(){
        batraR.attachIt_i(100);
        batraL.attachIt_i(60);
        }
///////////////////////////////////////
void sequence_batratte_2(){
        batraR.attachIt_i(25);
        batraL.attachIt_i(135);
        delay(700);
        batraR.detachIt();
        batraL.detachIt();
        }
///////////////////////////////////////
void sequence_stat_up(){
  digitalWrite(pompe_stat,HIGH);
  statuette.downFor(10);
  delay(500);
  statuette.upFor(10);
  analogWrite(motor_f,0);    
                     analogWrite(motor_b,170); 
                     delay(100);
                     analogWrite(motor_f,120);
                     analogWrite(motor_b,0);
                     delay(100);
                     
                     analogWrite(motor_f,0);    
                     analogWrite(motor_b,0);
  }
////////////////////////////////////// 
void sequence_stat_down(){
  statuette.downFor(10);
  digitalWrite(pompe_stat,LOW);
  delay(500);
  statuette.upFor(10);
  statuette.detachIt();
  }
/////////////////////////////////////////////////////////
void catch_down(int x){ //Y
  digitalWrite(ectrovanne,HIGH);
  digitalWrite(pompe_catch,HIGH);

      catchL.servo.attach(catchL.pin);
      catchR.servo.attach(catchR.pin);
      int r=catchR.servo.read();
      int l=catchL.servo.read();

      while(r < catchR.maxxx || l > catchL.minnn ) {
        if(r < catchR.maxxx){
        catchR.servo.write(r);
        r=r+1;
        }
        if(l > catchL.minnn){
        catchL.servo.write(l);
        l=l-1;
        }
        delay(x);
        } }
/////////////////////////////////////////////////////////

  void catch_up(int x){
 
      catchL.servo.attach(catchL.pin);
      catchR.servo.attach(catchR.pin);
      int r=catchR.servo.read();
      int l=catchL.servo.read();

      while(r > catchR.minnn || l < catchL.maxxx ) {
        if(r > catchR.minnn){
        catchR.servo.write(r);
        r=r-1;
        }
        if(l < catchL.maxxx ){
        catchL.servo.write(l);
        l=l+1;
        }
        delay(x);
        }}
///////////////////////////////////
   void sequence_catch_hex(){
    digitalWrite(ectrovanne,LOW);
  digitalWrite(pompe_catch,HIGH);
  catchR.upFor(10);
   catchR.downFor(10);
  }
////////////////////////////////////// 
  void sequence_catch_hex_down(){
 catchR.upFor(10);
  digitalWrite(pompe_catch,LOW);
  delay(500);
  catchR.downFor(10);
  catchR.detachIt();
  }
///////////////////////////////
   void sequence_catch_down(){ //y
    catchL.downFor(10);
  catchR.upFor(10);
  
  digitalWrite(pompe_catch,LOW);
  delay(500);
  catchR.downFor(10);
  catchL.upFor(10);
  catchR.detachIt();
  catchL.detachIt();
}
//////////////////////////////////////////////
  void initialisation(){ //i
    /////////////////////////////  
    statuette.servo.attach(statuette.pin);
    statuette.servo.write(statuette.initial);
    delay(500);
    statuette.servo.detach();
/////////////////////////////  
    flip.servo.attach(flip.pin);
    flip.servo.write(flip.initial);
    delay(500);
    flip.servo.detach();
/////////////////////////////  
   sequence_batratte_2();
/////////////////////////////     
      catchR.servo.attach(catchR.pin);
      for(int i=catchR.maxxx;i>=catchR.minnn;i--)
      {                 
        catchR.servo.write(i);
        delay(10);}
         catchL.servo.attach(catchL.pin);
      for(int i=catchL.minnn;i<=catchL.maxxx;i++)
      {
        catchL.servo.write(i);
        delay(10);}
/////////////////////////////  
    catchR.servo.detach();
    catchL.servo.detach();
/////////////////////////////     
    fouille.servo.attach(fouille.pin);
    fouille.servo.write(fouille.initial);
    delay(500);
    fouille.servo.detach();
      }
////////////////////////////////////
 
void sequence_carre(){ //g
  fouille.up();
    int res;
   while(true){
    if(Serial.available()){
      char c=Serial.read();
      if(c=='G'){
        flip.up();
        fouille.down();
       
        delay(500);
        fouille.detachIt();
        flip.detachIt();
        }
      break;
      }
  res=analogRead(resistor);
  if(res<420 && res>100){
    //Serial.println("VIOLET");
    if(flip.servo.read()!= flip.maxxx){
      flip.up();
      }
    }
    else if(res<670 && res>420){
      //Serial.println("JAUNE");
      fouille.down();
      if(flip.servo.read()!= flip.minnn){
      flip.down();
      delay(500);
      }
 
      }else if(res>670 && res< 900){
        //Serial.println("5TAR MAWT");
        if(flip.servo.read()!= flip.maxxx){
      flip.up();
      }
     
        }
        else {
          if(flip.servo.read()!= flip.maxxx){
      flip.up();
      }
        //Serial.println("7ot resistance w yezzi melbladaa");
      
        }

   }
  }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() {
  
  //pince.attach(10); for(int i=40;i<=200;i++){pince.write(i); delay(30);}
  Serial.begin(9600);
  pinMode(pompe_stat,OUTPUT);
  pinMode(pompe_catch,OUTPUT);
  pinMode(ectrovanne,OUTPUT);
  pinMode(motor_f,OUTPUT);
  pinMode(motor_b,OUTPUT);
  
  digitalWrite(pompe_stat,LOW);
  digitalWrite(pompe_catch,LOW);
  digitalWrite(ectrovanne,LOW);


//declaration servos 
statuette=myservo(30,113,113,9);
flip=myservo(60,152,152,11);
batraR=myservo(35,140,35,8);
fouille=myservo(10,90,10,10);
catchL=myservo(10,90,105,13);
batraL=myservo(150,40,150,12); 
catchR=myservo(50,130,35,7);//MA3KOUUUUUS                         
}

String s;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {
  if(Serial.available()>0){
    char c=Serial.read();
    s=s+c;
    switch (c) {

      case 'S':statuette.upFor(10);break;
      case 's':statuette.downFor(10);break;
      
      case 'B':batraR.up();break;
      case 'b':batraR.down();break;

      case 'Z':batraL.up();break;
      case 'z':batraL.down();break;

      case 'C':catchR.up();break;
      case 'c':catchR.down();break;

      case 'D':catchL.up();break;
      case 'd':catchL.down();break;

      case 'F':flip.up();break;
      case 'f':flip.down();break;

      case 'T':fouille.up();break;
      case 't':fouille.down();break;

      case 'P': digitalWrite(pompe_stat,HIGH);break;
      case 'p': digitalWrite(pompe_stat,LOW);break;

      case 'V' : digitalWrite(ectrovanne,HIGH);break;
      case 'v' : digitalWrite(ectrovanne,LOW);break; 
      
      case 'Q' : digitalWrite(pompe_catch,HIGH);break; 
      case 'q' : digitalWrite(pompe_catch,LOW);break; 
      
      case 'm' :     analogWrite(motor_f,100);    
                     analogWrite(motor_b,0); 
                     delay(100);
                     analogWrite(motor_f,0);    
                     analogWrite(motor_b,0); break;
                      
      case 'M' :analogWrite(motor_f,0);
                     analogWrite(motor_b,100);
                     delay(100);
                     analogWrite(motor_f,0);    
                     analogWrite(motor_b,0);break;
                     
/////////////////////////////  Case Sequences /////////////////////////////      
               
       case 'h' : sequence_batratte();break;
       case 'H' : sequence_batratte_1();break;
       case 'e' : sequence_batratte_2();break;
       case 'a' : sequence_stat_up();break;
       case 'A' : sequence_stat_down();break;
       case 'y' : catch_down(10);break;
       case 'Y' : catch_up(10);break;
       case 'n' : sequence_catch_down();break;
       case 'j' : sequence_catch_hex();break;
       case 'J' : sequence_catch_hex_down();break;
       case 'i' : initialisation();break;
       case 'g' : sequence_carre();break;
                   
           
      case 'w' : batraR.detachIt();batraL.detachIt();fouille.detachIt();statuette.detachIt();flip.detachIt();
                 catchR.detachIt();catchL.detachIt();digitalWrite(pompe_stat,LOW);digitalWrite(pompe_catch,LOW);digitalWrite(ectrovanne,LOW);break; 
}
}

}
