
#include <Keypad.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);


const byte ROWS =4;
const byte COLS =4;

char keys[ROWS][COLS]={
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'C','0','=','/'}
};

byte rowPins[ROWS]={0,1,2,3};
byte colPins[COLS]={4,5,6,7};

Keypad kep = Keypad( makeKeymap(keys), rowPins, colPins, ROWS , COLS);

char allNum[]="1234567890";
int Num[]={1,2,3,4,5,6,7,8,9,0};
char data[17];
char data1[17];
char data2[17];
byte i=0;
char cKey;
byte state = 1;
byte length;
byte j=0;
float val1=0;
float val2=0;
char op;
int result;
int z,x,a=0;

void setup(){
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("By - Syed Tamal");
  delay(2000);
  lcd.clear();
}
void loop(){
  lcd.setCursor(0,0);
  cKey = kep.getKey();
  if(cKey != NO_KEY){


      if( cKey == '='){
      val1 = ToInt(data1);
      val2 = ToInt(data2);
      switch(op){
        case '+': 
          result = val1+val2;
          break;
        case '-':
          result = val1-val2;
          break;
        case '*':
          result = val1*val2;
          break;
        case '/':
          result = val1/val2;
          break;
      }
      lcd.setCursor(0,1);
      lcd.print(result);
    }
  
    
    lcd.setCursor(i,0);
    lcd.print(cKey);
    data[i]=cKey;
    i++;

  if(cKey == '+' || cKey == '-' || cKey == '*' || cKey == '/' || cKey == 'C' || cKey == '='){
      state = 0;
      op=cKey;
  }

  if(state == 1){
    data1[a] = cKey;
    a++;
  }

  if(state == 0 && cKey != '=' && cKey != 'C'){
    data2[j]= cKey;
    j++;
  }




    if(cKey == 'C'){
      lcd.clear();
      data[17]=" ";
      data1[17]=" ";
      data2[17]=" ";
      i=0;
      cKey=NO_KEY;
      state = 1;
      length=0;
      j=0;
      val1=0;
      val2=0;
      op=NO_KEY;
      result=0;
      z=0;
      x=0;
      a=0;
    }
  }
}


int ToInt(char str[]){
  float value=0;
  int len=strlen(str);
  for(z=0;z<len;z++){
    for(x=0;x<10;x++){
      if(str[z]==allNum[x]) value = value + Num[x]*pow(10,len-z-1) ;
    }
  }
  return value;
}
