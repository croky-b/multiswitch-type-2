/*================= TDB USM  ========================
   Commande 10 fonctions pour piloter un USM-RC2
======================================================*/
int pinplus = 12;  // position D
int pinmoins = 13;    //position A


#define NBR_ENTREES    16
uint8_t IdxToPin[NBR_ENTREES] ={2,3,4,5,6,7,8,9,10,11,A0,A1,A2,A3,A4,A5};
int cmd;
 
void setup()
{

  uint8_t Idx;
  for(Idx = 0;Idx < NBR_ENTREES;Idx++)
  {
    pinMode(IdxToPin[Idx], INPUT_PULLUP);
   
  }
  pinMode(pinplus, OUTPUT); 
  pinMode(pinmoins, OUTPUT);
}
 
void loop()
{
  uint8_t  Idx;
  for(Idx = 0;Idx < NBR_ENTREES;Idx++)
    {
      if(digitalRead(IdxToPin[Idx]))
      {
        cmd = 0;
      } else {
        cmd = Idx+1;
 
switch (cmd) { // on faite un test de la valeur de cet octet
      case 1 : 
      impuls(pinplus,1);
    
      break;
      case 2 : 
       impuls(pinmoins,2);
      break;
      case 3 : 
     impuls(pinmoins,3);
      break;
      case 4 : 
     impuls(pinplus,4);
      break;
      case 5 : 
     impuls(pinplus,5);
      break;
      case 6 : 
     impuls(pinmoins,6);
      break;
      case 7 : 
     impuls(pinplus,7);
      break;
    case 8 : 
     impuls(pinmoins,8);
      break;
    case 9 : 
     impuls(pinmoins,9);
      break;
     case 10 : 
     impuls(pinplus,10);
      break;
     case 11 : 
     impuls(pinmoins,11);
      break;
    case 12 : 
     impuls(pinplus,12);
      break;
    case 13 : 
     impuls(pinmoins,13);
      break;
     case 14 : 
     
     impuls(pinplus,14);

     break;
     case 15 : 
     
     impuls(pinplus,15);
      break;
    case 16 : 
      
     impuls(pinplus,16);
      break;
    
    
       default:
     cmd=0;
   
    }
      }   
  }
  delay(20);
}
 
void impuls(int x,int y)
{
  uint8_t  Idx;
  for(Idx = 0;Idx < y;Idx++)
    {
      digitalWrite(x, HIGH);
      digitalWrite(13, HIGH);
      delay(200);
      digitalWrite(x, LOW);
      digitalWrite(13, LOW);
      delay(200);
    }
    delay(250);
}
