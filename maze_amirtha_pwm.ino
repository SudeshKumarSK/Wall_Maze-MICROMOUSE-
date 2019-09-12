#include<NewPing.h>
int trig1 = 5;
int echo1 = 2;                //left

int trig2 = 7;
int echo2 = 4;                  //mid


int trig3 = 8;
int echo3 = 3;                //right

int rm1=10;                          //motor pins
int rm2=11;
int lm1=6;
int lm2=9;

int tdelay;
int fdelay;

float maxi= 400;

NewPing sonar1(trig1,echo1,maxi);
NewPing sonar2(trig2,echo2,maxi);
NewPing sonar3(trig3,echo3,maxi);
float u1,u2,u3;

void setup() {
  //Serial.begin(115200);
 }
void Stop()                          //stop
{
  analogWrite(lm1,0);
  analogWrite(lm2,0);
  analogWrite(rm1,0);
  analogWrite(rm2,0);
}
void forward()                        //forward
{
  analogWrite(lm1,255);
  analogWrite(lm2,0);
  analogWrite(rm1,255);
  analogWrite(rm2,0);
} 
void smallright()                  //small right
{
  analogWrite(lm1,255);
  analogWrite(lm2,0);
  analogWrite(rm1,0);
  analogWrite(rm2,0); 
}
void smallleft()                    //small left
{
  analogWrite(lm1,0);
  analogWrite(lm2,0);
  analogWrite(rm1,255);
  analogWrite(rm2,0);
}
void right()                        //right
{
  analogWrite(lm1,255);
  analogWrite(lm2,0);
  analogWrite(rm1,0);
  analogWrite(rm2,150);
}
void left()                          //left
{
  analogWrite(lm1,0);
  analogWrite(lm2,255);
  analogWrite(rm1,255);
  analogWrite(rm2,0);
}
void inch()
{
  Stop();              //stop
  delay(500);
  forward();           //forward
  delay(600);
  Stop();
  delay(500);          //read the value of sensors
}

void readsens() {
 u1 = sonar1.ping_cm();
//Serial.print("a :");
//Serial.println(u1);
 
  u2 = sonar2.ping_cm();
//  Serial.print("b :");
 // Serial.println(u2);
  
  u3 = sonar3.ping_cm();
  //Serial.print("c :");
//  Serial.println(u3);
  
}
void loop(){
readsens();

if(((u1>=10)&&(u1<=13)&&((u3>=10)&&(u3<=13))&&((u2>8)&&(u2<400))))
{
forward();
}

else if(((u1<10)&&(u1>=0))&&((u3>10)&&(u3<=30))&&((u2>8)&&(u2<400)))
{
smallright();
}

else if(((u1>10)&&(u1<=30))&&((u3<10)&&(u3>=0))&&((u2>8)&&(u2<400)))
{
smallleft();
}

//else if(((u1>12)&&(u1<20))&&((u3>12)&&(u3<20))&&((u2>8)&&(u2<300)))

/*else if(((u3>35)&&(u3<400))&&((u1>8)&&(u1<=25))&&((u2>8)&&(u2<35)))      //right only
{
  inch();
  right();
  delay(370);
  inch();
}
else if(((u1>8)&&(u1<=400))&&((u3>35)&&(u3<400))&&((u2>8)&&(u2<35)))      // T intersection
{
  inch();
  right();
  delay(350);
  inch();
}

else if(((u1>8)&&(u1<=400))&&((u3>35)&&(u3<400))&&((u2>8)&&(u2<400)))      // 4-way
{
  inch();
  right();
  delay(350);
 inch();
}*/
  
else if(((u1>8)&&(u1<=25))&&((u3>35)&&(u3<400))&&((u2>8)&&(u2<400)))      // Straight and right
{
  inch();
  readsens();
  while(u3>14)
  {
   readsens();
    right();
  }
  
}

else if(((u2>2&&(u2<=8)) && ((u1>6)&&(u1<=25)) && ((u3>6)&&(u3<=25)))) //uturn
{
  right();
  delay(800);
  

  
}
else if(((u1>35)&&(u1<400))&&((u3>8)&&(u3<=25))&&((u2>8)&&(u2<35)))  // left
{
  inch();
  left();
  delay(370);
 inch();
}
else if(((u3>=8)&&(u3<=25))&&((u1>35)&&(u1<400))&&((u2>8)&&(u2<400)))      // Straight and left
{
  readsens();
  while((u1>35))
  {
    readsens();
    if(u3>12)
    {
      smallright();
    }
    forward();
  }
}

}
