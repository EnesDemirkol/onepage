#include <SoftwareSerial.h>
int led1 = 7;
int led2 = 6;
int led3 = 5;
int led4 = 4;

void giris()
{
  for(int i=4 ; i<=7;i++){
   
    digitalWrite(i, LOW);
    delay(500);
    digitalWrite(i,HIGH);

   digitalWrite(led1 , HIGH);
  digitalWrite(led2 , HIGH);
  digitalWrite(led3 , HIGH);
}
  
}
  
   
  


SoftwareSerial mySerial(10, 11); // 10RX, 11TX çapraz takılcaklar arduinodaki rx-->btmodulündeki tx bacağına
String isim = "Bluetooth Enes";
int sifre = 1234;
String uart = "9600,0,0";

void setup() {
 pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  /*ledlere çıkış foksiyorn atandı.*/
  Serial.begin(38400);
  Serial.println("HC-05 Modul Ayarlaniyor...");
  Serial.println("Lutfen 5 sn icinde HC-05 modulun uzerindeki butona basili tutarak baglanti yapiniz.");
  mySerial.begin(9600);
  delay(2000);
  mySerial.print("Bluetoth modulu haberleşme sistemi");
  mySerial.print("AT+NAME=");
  mySerial.println(isim);
  Serial.print("Isim ayarlandi: ");
  Serial.println(isim);
  delay(1000);
  mySerial.print("AT+PSWD=");
  mySerial.println(sifre);
  mySerial.print("Sifre ayarlandi: ");
  mySerial.println(sifre);
  delay(1000);
  mySerial.print("AT+UART=");
  mySerial.println(uart);
  mySerial.print("Baud rate ayarlandi: ");
  mySerial.println(uart);
  delay(2000);
  mySerial.println("Islem tamamlandi.");
  giris();

}

void loop()
{   
 //mySerial.print("Mesajjj");
  
  if(mySerial.available() >0)
  {
      String renk= mySerial.readString();
     //char ch = mySerial.read();
      mySerial.println(renk + " girdiniz.");
       if (renk.equalsIgnoreCase("kirmizi"))
      {
        digitalWrite(led1 , LOW);
        digitalWrite(led2 , HIGH);
        digitalWrite(led3 , HIGH);
        mySerial.println("Kirmizi led yakildi");
      }
      
     else if(renk.equalsIgnoreCase("yesil"))
     {
        digitalWrite(led1 , HIGH);
        digitalWrite (led2 ,LOW);
        digitalWrite(led3 , HIGH);
        mySerial.println("Yesil led yakildi");
        
     }  
        
     else if(renk.equalsIgnoreCase("mavi"))
      {
        digitalWrite(led1 , HIGH);
        digitalWrite(led2 , HIGH);
        digitalWrite(led3,LOW);
        mySerial.println("Mavi led yakildi");
        
      }
      
        else if (renk.equalsIgnoreCase("ikili"))
        {   
         digitalWrite (led1 ,LOW);
         digitalWrite (led2 ,LOW);
         digitalWrite (led3 ,HIGH);
         mySerial.println("Kirmizi ve Yesil ledi yaktiniz.");
        }

         else if (renk.equalsIgnoreCase("rgb"))
        {   
         digitalWrite (led1 ,LOW);
         digitalWrite (led2 ,LOW);
         digitalWrite (led3 ,LOW);
         mySerial.println("Kirmizi, Mavi ve Yesil ledi yaktiniz.");
        }
        else if(renk.equalsIgnoreCase("off"))
     {
        digitalWrite(led1 , HIGH);
        digitalWrite (led2 ,HIGH);
        digitalWrite(led3 , HIGH);
        mySerial.println("Butun ledler kapatildi."); 
     }  

         
     
      /*else
      {
        digitalWrite(led1 , HIGH);
        digitalWrite(led2 , HIGH);
        digitalWrite(led3 , HIGH);
        mySerial.println( "Tum ledler kapatildi.");
      }*/
  }
}
