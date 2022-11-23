
const int LM35 = 0;
float temperatura = 0; 
int ADClido = 0;

const int LEDYELLOW = 10;
const int LEDGREEN = 11;
const int LEDRED = 12;

int ldr = A0;//Atribui A0 a variável ldr
int valorldr = 0;

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
  

  // LDR
  if(valorldr >= 900){
    Serial.print("STATUS - SEM PRODUTO");
    Serial.println(valorldr);
  
    digitalWrite(LEDYELLOW, HIGH);
  }else{
    Serial.print("STATUS - COM PRODUTO");
    Serial.println(valorldr);
  
    digitalWrite(LEDYELLOW, LOW);
  }

  // TEMP.
  if(temperatura > 27){ // setei como 30ºC
    digitalWrite(LEDRED, HIGH);
    digitalWrite(LEDGREEN, LOW);
  }else{
    digitalWrite(LEDRED, LOW);
    digitalWrite(LEDGREEN, HIGH);
  }
  
  delay(1000);
}
