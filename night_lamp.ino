#define led 4 
#define sensor 2
int irs ;
int count=1;

void setup()
{
  pinMode (irs,INPUT);
  pinMode(led,OUTPUT);
}

void loop()
{
  irs= digitalRead(sensor);
  
  if ((irs==0)&&(count==1))
  {
    digitalWrite(led,HIGH);
    count=2;
    irs=1;
    delay(300);
   
  }
  if ((irs==0)&&(count==2))
  {
    digitalWrite(led,LOW);
    count=1;
    irs=1;
    delay(300);
  }
  
}

