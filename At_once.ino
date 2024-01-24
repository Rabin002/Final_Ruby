String str;
int dtr,st,rot,del;//dtr is direction pin and st is step pin, rot is for rotation, del for delay
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()>0)
  {str=Serial.readStringUntil('\n');
  int num=str.length();
  for(int i=0;i<num;i+=3)
  {
  char C=str[i];
  char D=str[i+1];
  char E=str[i+3];
  char F=str[i+4];
    
    if (C=='R')
    {
     dtr=2;
     st=8;
  
  }
   if (C=='L')
    {
     dtr=3;
     st=9;
  
  }
   if (C=='U')
    {
     dtr=4;
     st=10;
  
  }
   if (C=='D')
    {
     dtr=5;
     st=11;
  
  }
   if (C=='F')
    {
     dtr=6;
     st=12;
  
  }
   if (C=='B')
    {
     dtr=7;
     st=13;
  
  }
  if((C=='R' && E=='L')|| (C=='L' && E=='R')||(C=='U' && E=='D')||(C=='D' && E=='U')||(C=='F' && E=='B')||(C=='B' && E=='F'))
  {
    int dtr2, st2;//for second motor


     if (E=='R')
    {
     dtr2=2;
     st2=8;
  
  }
   if (E=='L')
    {
     dtr2=3;
     st2=9;
  
  }
   if (E=='U')
    {
     dtr2=4;
     st2=10;
  
  }
   if (E=='D')
    {
     dtr2=5;
     st2=11;
  
  }
   if (E=='F')
    {
     dtr2=6;
     st2=12;
  
  }
   if (E=='B')
    {
     dtr2=7;
     st2=13;
  
  }
    
     for(int x=0;x<1600;x++)
  { if(D=='1' || D=='2')
    {digitalWrite(dtr2,LOW);}
    else
    {digitalWrite(dtr,HIGH);}
    if((D=='2')||(x<800))
    {digitalWrite(st2,HIGH);
    delayMicroseconds(200);
    digitalWrite(st2,LOW);
    delayMicroseconds(200);}

    if(F=='1' || F=='2')
    {digitalWrite(dtr2,LOW);}
    else
    {digitalWrite(dtr2,HIGH);}
    if((F=='2')||(x<800))
    {digitalWrite(st2,HIGH);
    delayMicroseconds(200);
    digitalWrite(st2,LOW);
    delayMicroseconds(200);}
    
    }
    i+=3;
    delay(500);
    }
   else{
   if(D=='2')
   {
    rot=1600;
   }
   if(D=='1'){
    rot=800;
   }
   if(D=='3')
   {
    for(int x=0;x<800;x++)
  {digitalWrite(dtr,HIGH);
    digitalWrite(st,HIGH);
    delayMicroseconds(200);
    digitalWrite(st,LOW);
    delayMicroseconds(200);}
  delay(500);}
    if(D=='1' || D=='2')
   {for(int x=0;x<rot;x++)
  {digitalWrite(dtr,LOW);
    digitalWrite(st,HIGH);
    delayMicroseconds(200);
    digitalWrite(st,LOW);
    delayMicroseconds(200);}
  delay(500);}}
  }}
  
  }
