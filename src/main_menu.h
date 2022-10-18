
void main_menu()    // MAIN MENU
{
  tft.fillRect (0, 25, 480, 295 , TFT_BLACK); 
  tft.setTextSize(2);  tft.setTextFont(2);   tft.setTextColor(TFT_WHITE);
  button (x11,y11,x12,y12); tft.setCursor(30, 60); tft.print("Ping GW");  //BUTTON Ping getwey
  button (x81,y81,x82,y82); tft.setCursor(340, 150); tft.print("Ping ALL");  //BUTTON Ping getwey
  button (x71,y71,x72,y72); tft.setCursor(23, 150); tft.print("SETTINGS"); //BUTTON Set settings
  button (x21,y21,x22,y22); tft.setCursor(210, 44); tft.print("Ping"); tft.setCursor(175, 71); tft.print("yandex.ru"); //BUTTON Ping ya
  button (x31,y31,x32,y32); tft.setCursor(370, 44); tft.print("Ping"); tft.setCursor(334, 71); tft.print("googl.com"); //BUTTON Ping googl
}