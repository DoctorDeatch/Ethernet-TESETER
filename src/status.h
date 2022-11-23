void Status(byte dhcp_on) {
  EEPROM.get(50,cp);
  tft.setTextSize(2); tft.setTextFont(2); tft.setTextColor(TFT_GREEN);
  tft.setCursor(10, 220); tft.print("MAC: "); tft.print(ETH.macAddress());
  if (dhcp_on == 1) tft.print(" DHCP"); else tft.print(" Statik IP");
  tft.setCursor(10, 250); tft.print("Counting tests: ");tft.print(cp);
}

void save_setting() {
  tft.fillRect(400, 0, 480, 25, TFT_BLACK);  
  for (int i = 0; i < 3; i++) {
  tft.setTextSize(2); tft.setCursor(10, 250); tft.setTextColor(TFT_RED); delay(700); 
  tft.print ("Save settings and restart the system");
  tft.setTextSize(2); tft.setCursor(10, 250); tft.setTextColor(TFT_BLACK); delay(700); 
  tft.print ("Save settings and restart the system");
  }
  delay(3000); ESP.restart(); 
  }