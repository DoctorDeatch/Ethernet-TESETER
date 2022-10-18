void touch_calibrate()
{
  uint16_t calData[5];
  uint16_t calDatar;
  uint8_t calDataOK = 0;
  // Calibrate
  tft.fillScreen(TFT_BLACK);  tft.setCursor(20, 0);  tft.setTextFont(2);  tft.setTextSize(2);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);  tft.println("Touch corners as indicated");
  tft.setTextFont(1);  tft.println();
  tft.calibrateTouch(calData, TFT_MAGENTA, TFT_BLACK, 15);
  tft.fillScreen(TFT_BLACK);  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.println("Calibration complete!");  tft.println("Calibration code: {");
  for (uint8_t i = 0; i < 5; i++)
  {
    EEPROM.put(100+(i*10),calData[i]); EEPROM.commit();
    tft.print(calData[i]);   tft.print(", ");
  }
   tft.print("}");
 tft.setTouch(calData);
  delay(4000);
  tft.fillRect(0, 0, 480, 25, TFT_GREEN);  
  tft.setTextFont(4);  tft.setTextSize(1);  tft.setTextColor(TFT_RED);  tft.setCursor(100, 2);  tft.print("IP Network Tester");
}