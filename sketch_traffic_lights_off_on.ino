// multiple state handling
// 20230515

#define BUTTON 3
#define LED1 5
#define LED2 6
#define LED3 7

int state = 0;
int old=0;
int buttonPoll = 0;

void setup() {
  pinMode(BUTTON, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
}

void loop() {
  buttonPoll=digitalRead(BUTTON);
  if (buttonPoll ==1){
    delay(50);
    buttonPoll = digitalRead(BUTTON);
    if(buttonPoll==0){
      state = old + 1;
    }
  }else{
    delay(100);
  } switch(state){
    case 1 :
      digitalWrite(LED1,HIGH);
      digitalWrite(LED2,LOW);
      digitalWrite(LED3,LOW);
      old = state;
      break;
    case 2 :
      digitalWrite(LED1,LOW);
      digitalWrite(LED2,HIGH);
      digitalWrite(LED3,LOW);
      old = state;
      break;
    case 3 :
      digitalWrite(LED1,LOW);
      digitalWrite(LED2,LOW);
      digitalWrite(LED3,HIGH);
      old = state;
      break;
    default:
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      old= 0;
    break;
  }
}