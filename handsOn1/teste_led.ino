String minhaString;
String comando;
String valor;
int brilho = 10;
int pino = 11;

void setup() {
  Serial.begin(9600);
  pinMode(pino, OUTPUT);
  analogWrite(pino,brilho);
}

void loop() {
  if(Serial.available() != 0){
    minhaString = Serial.readStringUntil('\n');
    for(int i = 0; i < minhaString.length(); i++){
      if(minhaString[i] != ' '){
        comando += minhaString[i];
      }else{
        valor += minhaString.substring(i+1);
        break;
      }
    }
    Serial.print("Meu comando é: ");
    Serial.println(comando);
    Serial.print("Meu valor é: ");
    Serial.println(valor);
    int valor_inteiro = valor.toInt();
    if(comando == "SET_LED"){
      Serial.print("Mudando brilho do led para: ");
      Serial.print(valor_inteiro);
      analogWrite(pino,valor_inteiro);
    }
    else if(comando == "GET_LED"){
     //Implementar 
    }else{ //LDR
      //Implementar
    }


    
    comando = "";
    valor = "";
    
      
  }
}

