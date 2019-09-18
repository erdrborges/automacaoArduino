#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "homesweethome-fc94e.firebaseio.com"
#define FIREBASE_AUTH "KRlR0KVAckwhhrsFLVzbgDSvfm4lMHHGBhfIC2lV"
#define WIFI_SSID "ifdoce"
#define WIFI_PASSWORD "10tifsul"

//#define LED_AZUL 3
//#define LED_VERMELHO 16

void autenticaFirebase(){
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void conectaWifi(){    
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("\nconnecting");
  
  while(WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.print("Connect: ");
  Serial.println(WiFi.localIP());
  autenticaFirebase();
}

void setup() {
  Serial.begin(9600);
//  pinMode(LED_AZUL, OUTPUT);
//  pinMode(LED_VERMELHO, OUTPUT);

  conectaWifi();
}
 

void loop() {
  if(WiFi.status() == WL_CONNECTED){
    if(Firebase.success()){
      FirebaseObject corredor = Firebase.get("casa/corredor");
      FirebaseObject cozinha = Firebase.get("casa/cozinha");
      FirebaseObject garagem = Firebase.get("casa/garagem");
      FirebaseObject living = Firebase.get("casa/living");
      FirebaseObject quarto1 = Firebase.get("casa/quarto1(suite");
      FirebaseObject quarto2 = Firebase.get("casa/quarto2");
      FirebaseObject quarto3 = Firebase.get("casa/quarto3");
      FirebaseObject varanda = Firebase.get("casa/varanda");
  
      //segmento de código para o corredor
      if(corredor.getBool("/lamp_bath")){
        Serial.print("\nLâmpada do banheiro acessa.");
      }else{
        Serial.print("\nLâmpada do banheiro apagada.");
      }
      
      if(corredor.getBool("/lamp_cor")){
        Serial.print("\nLâmpada do corredor acessa.");
      }else{
        Serial.print("\nLâmpada do corredor acessa.");
      }
      //fim do segmento

      //segmento de código para o conjunto cozinha
      if(cozinha.getBool("/lamp_kit")){
        Serial.print("\nLâmpada da cozinha acessa.");
      }else{
        Serial.print("\nLâmpada da cozinha apagada.");
      }

      if(cozinha.getBool("/lamp_laundry")){
        Serial.print("\nLâmpada da lavanderia acessa.");
      }else{
        Serial.print("\nLâmpada da lavanderia desligada.");
      }
      //fim do segmento
      
      //segmento de código para a garagem
      if(garagem.getBool("/gate_garage")){
        Serial.print("\nPortão da garagem aberto.");
      }else{
        Serial.print("\nPortão da garagem fechado.");
      }
    
      if(garagem.getBool("/lamp_garage")){
        Serial.print("\nLâmpada da garagem acesa.");
      }else{
        Serial.print("\nLâmpada da garagem apagada.");
      }
      //fim do segmento
      
      //segmento de código para o conjunto living
      if(living.getBool("/lamp_dining")){
        Serial.print("\nLâmpada da sala de jantar acesa.");
      }else{
        Serial.print("\nLâmpada da sala de jantar apagada.");
      }

      if(living.getBool("/lamp_hall")){
        Serial.print("\nLâmpada do hall de entrada acesa.");
      }else{
        Serial.print("\nLâmpada do hall de entrada apagada.");
      }

      if(living.getBool("/lamp_living")){
        Serial.print("\nLâmpada da sala de estar acesa.");
      }else{
        Serial.print("\nLâmpada da sala de estar apagada.");
      }
      //fim do segmento

      //segmento de código para o quarto1(suite)
      if(quarto1.getBool("/ar_bed")){
        Serial.print("\nAr condicionado do Quarto 1 ligado.");
      }else{
        Serial.print("\nAr condicionado do Quarto 1 desligado.");
      }

      if(quarto1.getBool("/lamp_bed")){
        Serial.print("\nLâmpada do Quarto 1 acessa.");
      }else{
        Serial.print("\nLâmpada do Quarto 1 apagada.");
      }

      if(quarto1.getBool("/lamp_closet")){
        Serial.print("\nLâmpada do closed do Quarto 1 acesa.");
      }else{
        Serial.print("\nLâmpada do closed do Quarto 1 apagada.");
      }

      if(quarto1.getBool("/lamp_wc")){
        Serial.print("\nLâmpada do banheiro do Quarto 1 acesa.");
      }else{
        Serial.print("\nLâmpada do banheiro do Quarto 1 apagada.");
      }
      //fim do segmento

      //segmento de código para o quarto2
      if(quarto2.getBool("/ar_bed")){
        Serial.print("\nAr condicionado do Quarto 2 ligado.");
      }else{
        Serial.print("\nAr condicionado do Quarto 2 desligado.");
      }

      if(quarto2.getBool("/lamp_bed")){
        Serial.print("\nLâmpada do Quarto 2 acesa.");
      }else{
        Serial.print("\nLâmpada do Quarto 2 apagada");
      }
      //fim do segmento

      //segmento de código para o quarto3
      if(quarto3.getBool("/ar_bed")){
        Serial.print("\nAr condicionado do Quarto 3 ligado.");
      }else{
        Serial.print("\nAr condicionado do Quarto 3 desligado.");
      }

      if(quarto3.getBool("/lamp_bed")){
        Serial.print("\nLâmpada do Quarto 3 acesa.");
      }else{
        Serial.print("\nLâmpada do Quarto 3 apagada.");
      }
      //fim do segmento

      //segmento de código para a varanda
      if(varanda.getBool("/lamp_balc_hall")){
        Serial.print("\nLâmpada da varanda do hall acesa.");
      }else{
        Serial.print("\nLâmpada da varanda do hall apagada.");
      }

      if(varanda.getBool("/lamp_balc_liv")){
        Serial.print("\nLâmpada da varanda da sala acesa.");
      }else{
        Serial.print("\nLâmpada da varanda da sala apagada.");
      }

      if(varanda.getBool("/lamp_balc_laundry")){
        Serial.print("\nLâmpada da Saída da Lavanderia acessa.");
      }else{
        Serial.print("\nLâmpada da Saída da Lavanderia apagada.");
      }
     
     
      //Serial.println("Autenticado no Firebase");
    }else{
      Serial.println("Erro na autenticação com o Firebase");
    }
  }else{
    conectaWifi();
  }

  delay(500);
}
