#include <SPI.h>
#include <TFT_eSPI.h>
#include <ETH.h>
#include <EEPROM.h>
#include <ESP32Ping.h>
TFT_eSPI tft = TFT_eSPI();
#define nicCable 34   //Ethernt Cable Sensor
#define BUZZER 21 
int set_ping = 3;  //Cont step ping, not up 6
int x, y, menu, rh, ret, key, a, b, c[3][4], d, e, f, n, count, cp;
const char* pref ;
char* mask ;
char* host_name[5] = {"ya.ru","googl.com"}; // sequential check of hosts , no more than 6
byte dhcp_on;
uint16_t calDatar;
uint16_t calData[5];
#include <status.h>
#include <button.h>
#include <main_menu.h>
#include <settings.h>
#include <lp.h>
#include <calibrate.h>
static uint32_t timer;

void setup() {
 pinMode(nicCable, INPUT_PULLUP);
  EEPROM.begin(512);  EEPROM.get(1,dhcp_on);  EEPROM.get(50,count);
  randomSeed(analogRead(0));
  static bool eth_connected = false;
  tft.init();  tft.setRotation(1);
  for (uint8_t i = 0; i < 5; i++)
  {
    EEPROM.get(100+(i*10),calData[i]);
  }
  //uint16_t calData[5] = { 369, 3275, 388, 2929, 5 }; // enabling static touch screen calibration parameters
    pinMode(NRST, OUTPUT);
    digitalWrite(NRST, 0);
    delay(200);
    digitalWrite(NRST, 1);
    delay(200);
    digitalWrite(NRST, 0);
    delay(200);
    digitalWrite(NRST, 1);  
  ETH.begin();
  if (dhcp_on==0){
IPAddress local_IP(EEPROM.read(10), EEPROM.read(11), EEPROM.read(12), EEPROM.read(13));
IPAddress subnet(EEPROM.read(20), EEPROM.read(21), EEPROM.read(22), EEPROM.read(23));
IPAddress gateway(EEPROM.read(30), EEPROM.read(31), EEPROM.read(32), EEPROM.read(33));
IPAddress primaryDNS(8, 8, 8, 8);
IPAddress secondaryDNS(8, 8, 4, 4);  
ETH.config(local_IP,gateway,subnet,primaryDNS,secondaryDNS);
  }
  ETH.setHostname("IP-TESTER");
  tft.fillScreen(TFT_BLACK);
  tft.fillRect(0, 0, 480, 25, TFT_GREEN);  
  tft.setTextFont(4);  tft.setTextSize(1);  tft.setTextColor(TFT_RED);  tft.setCursor(100, 2);  tft.print("IP Network Tester");
  tft.setTextColor(TFT_YELLOW);  tft.setTextFont(4);  tft.setTextSize(2);  tft.setCursor(40, 50);  tft.println("Network IP Tester");
  tft.print("                  v 3.01");  delay(2000);    
  tft.setCursor(100, 215);  tft.setTextFont(4);  tft.setTextSize(1);  tft.print("Technical support by Doc");  delay(1000);    
  tft.setCursor(120, 250);  tft.print("CopyRight @2022"); 
  tft.setCursor(80, 280);  tft.setTextFont(4);  tft.setTextSize(1); tft.setTextColor(TFT_SILVER); tft.print("Web: https://radio-portal.su"); delay(5000);
 //  touch_calibrate(); // enabling forced calibration of the touch screen
  if (EEPROM.read(100) == 255 && EEPROM.read(110) == 255 && EEPROM.read(120) == 255 && EEPROM.read(130) == 255 && EEPROM.read(150) == 255) touch_calibrate(); else tft.setTouch(calData);
  menu=1; main_menu(); Status(dhcp_on);
  }

void loop() {
    uint16_t x = 0, y = 0;
    bool pressed = tft.getTouch(&x, &y);
  if (pressed) 
     { 
     // tft.fillCircle(x, y, 2, TFT_WHITE);
            if ((y>=yb1) && (y<=yb2+yb1) && (x>=xb1) && (x<=xb2+xb1) && (menu>1))             // Button: HOME
        {  
            menu=1; main_menu(); Status(dhcp_on); delay(300);
        }   
           if ((y>=y71) && (y<=y72+y71) && (x>=x71) && (x<=x72+x71) && (menu==1))             // Button: SET IP
        {     
            menu = 3; set_ip(menu); delay(300);
        } 
            if ((y>=y91) && (y<=y92+y91) && (x>=x91) && (x<=x92+x91) && (menu==3))             // Button: DHCP
        {  
            ETH.config(INADDR_NONE, INADDR_NONE, INADDR_NONE, INADDR_NONE);
            EEPROM.put(1,1);  EEPROM.commit();
            dhcp_on = EEPROM.read(1);
            menu=1; main_menu();  Status(dhcp_on); delay(300); save_setting();
        }   
           if ((y>=y51) && (y<=y52+y51) && (x>=x51) && (x<=x52+x51) && (menu==3))             // Button: Set static IP
        {  
            menu=2;  set_ip(menu); delay(300); a=0; b=0;
        }  
            if ((y>=y11) && (y<=y12+y11) && (x>=x11) && (x<=x12+x11) && (menu==1))             // Button: PING GW
        {  
            menu=4; rh=1;  lp(rh,set_ping,mask,host_name); count=count+1; delay(300); EEPROM.put(50,count); EEPROM.commit();
        }   
            if ((y>=y21) && (y<=y22+y21) && (x>=x21) && (x<=x22+x21) && (menu==1))             // Button: PING YANDEX
        {  
            menu=4; rh=2;  lp(rh,set_ping,mask,host_name); count=count+1; delay(300); EEPROM.put(50,count); EEPROM.commit();
        }   
            if ((y>=y31) && (y<=y32+y31) && (x>=x31) && (x<=x32+x31) && (menu==1))             // Button: PING GOOGLE
        {  
            menu=4; rh=3;  lp(rh,set_ping,mask,host_name); count=count+1; delay(300); EEPROM.put(50,count); EEPROM.commit();
        }  
            if ((y>=y81) && (y<=y82+y81) && (x>=x81) && (x<=x82+x81) && (menu==1))             // Button: PING ALL
        {  
            menu=4; rh=4;  lp(rh,set_ping,mask,host_name); count=count+1; delay(300); EEPROM.put(50,count); EEPROM.commit();
        }  
           if ((y>=y51) && (y<=y52+y51) && (x>=x51) && (x<=x52+x51) && (menu==4))             // Button: PING REPEAT
        {  
            menu=4; lp(rh,set_ping,mask,host_name); delay(300);
        }  
        for (int i = 0; i < 10; i++) {
           if ((y>=150) && (y<=195) && (x>=kx[i]) && (x<=kx[i]+45) && (menu==2))              // Keybord
           {
             if (a==3) {a=0; c[d][f]=n; b=b+1; n=0; f=f+1; if (b!=4 && b!=8 && b!=12)tft.print(".");}
             if (b==0 && a==0) {tft.setCursor(70, 40); d=0; f=0; tft.print("IP: ");}
             if (b==4 && a==0) {tft.setCursor(70, 70); d=1; f=0; tft.print("Mask: ");}
             if (b==8 && a==0) {tft.setCursor(70, 100); d=2; f=0; tft.print("GW: ");}
             if (b<12) {tft.print(i); delay(200); a=a+1; if (n==0) n=i; else n=(n*10)+i; }else{n=0; f=0; a=0; b=0; check_ip(c);}
           }
                                     }
            if ((y>=y51) && (y<=y52+y51) && (x>=x51) && (x<=x52+x51) && (menu==5))            // Button: SAVE
        {  
        for ( int row  = 0; row  <= 2; ++row ){
        for ( int column = 0; column <=3 ; ++column ){
            EEPROM.put(10+(row*10)+column, c[row][column]);
        }}
        EEPROM.put(1,0);  EEPROM.commit();
        EEPROM.get(1,dhcp_on);
        menu=1; main_menu(); Status(dhcp_on); delay(300); save_setting();
        }           
                                      
     } 

}
