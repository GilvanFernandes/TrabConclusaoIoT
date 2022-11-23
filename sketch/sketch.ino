
const int LM35 = 0;

float temperatura = 0; 
int ADClido = 0;

const int LEDRED = 12;
const int LEDGREEN = 11;
const int LEDYELLOW = 12;


int ldr = A0;//Atribui A0 a variável ldr
int valorldr = 0;//Declara a variável valorldr como inteiro



void setup() {
  Serial.begin(9600);

  analogReference(INTERNAL);
  pinMode(LEDRED, OUTPUT);
  pinMode(LEDGREEN, OUTPUT);
  pinMode(LEDYELLOW, OUTPUT);
  pinMode(ldr, INPUT);//Define ldr (pino analógico A0) como saída

}

void loop() {

  valorldr    = analogRead(ldr);
  ADClido     = analogRead(LM35);
  temperatura = ADClido * 0.1075268817204301;
  
  Serial.print("Temperatura = ");
  Serial.println(temperatura);
  Serial.print("LDR = ");
  Serial.println(valorldr);
    
  if(valorldr >= 900){
    digitalWrite(LEDYELLOW, HIGH);
  }else{
    digitalWrite(LEDYELLOW, LOW);
  }
  
  if(temperatura > 27){ // setei como 30ºC
    digitalWrite(LEDRED, HIGH);
  }else{
    digitalWrite(LEDRED, LOW);
  }
  
  if(temperatura <= 26.5){
    digitalWrite(LEDGREEN, HIGH);
  }else{
    digitalWrite(LEDGREEN, LOW);
  }

}
