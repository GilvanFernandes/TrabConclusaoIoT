
const int LM35 = 0;
float temperatura = 0; 
int ADClido = 0;

const int LEDYELLOW = 10;
const int LEDGREEN = 11;
const int LEDRED = 12;

int ldr = A1;//Atribui A0 a variável ldr
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


  // LDR
  if(valorldr >= 900){
    Serial.print("STATUS - SEM PRODUTO");  
    Serial.print("STATUS - SEM PRODUTO");
    Serial.println(" ");

    digitalWrite(LEDYELLOW, HIGH);
    digitalWrite(LEDRED, LOW);
    digitalWrite(LEDGREEN, LOW);

  }else{
  
    Serial.println("STATUS - COM PRODUTO");
    
    Serial.print("Temperatura = ");
    Serial.println(temperatura);
    
    digitalWrite(LEDYELLOW, LOW);

    // TEMP.
    if(temperatura > 28){ // setei como 30ºC
      digitalWrite(LEDRED, HIGH);
      digitalWrite(LEDGREEN, LOW);
    }else{
      digitalWrite(LEDRED, LOW);
      digitalWrite(LEDGREEN, HIGH);
    }
    
  }
  
  delay(1000);
}
