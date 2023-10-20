
// Salidas digitales 
byte led1 = 2;
byte led2 = 3;
byte led3 = 4;
byte led4 = 5;
char orden;

// Potenciómetro
byte pinPot = A0;
int lectura;

unsigned long tiempo1 = 0;
unsigned long t1 = 0;


void setup() {

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  pinMode(pinPot, INPUT);

  Serial.begin(9600);

}

void loop() {

  tiempo1 = millis();

  lectura = analogRead(pinPot);

  
  if (Serial.available() > 0) {
    orden  = Serial.read();
  }


  switch (orden) {
    case '1':
    digitalWrite(led1,HIGH);
    break;
  
    case '2':
    digitalWrite(led1,LOW);
    break;

    case '3':
    digitalWrite(led2,HIGH);
    break;

    case '4':
    digitalWrite(led2,LOW);
    break;

    case '5':
    digitalWrite(led3,HIGH);
    break;

    case '6':
    digitalWrite(led3,LOW);
    break;

    case '7':
    digitalWrite(led4,HIGH);
    break;

    case '8':
    digitalWrite(led4,LOW);
    break;
  }


  if( (tiempo1 - t1 >= 1000)){
    t1 = tiempo1;
    Serial.println(lectura);
  }

}

