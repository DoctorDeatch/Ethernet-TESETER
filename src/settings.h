void set_ip(int menu)    
{
    tft.fillRect (0, 25, 480, 295 , TFT_BLACK);
     if (menu == 2) {

    for (int i = 0; i < 10; i++) {
     keyb (kx[i], kc[i], i);
    }
    tft.setTextSize(2); tft.setTextFont(2); tft.setTextColor(TFT_ORANGE);

}
else {
              tft.setTextSize(2); tft.setTextFont(2); tft.setTextColor(TFT_ORANGE);
              tft.setCursor(70, 40); tft.print("IP: "); tft.print(ETH.localIP());
              tft.setCursor(70, 70); tft.print("Mask: "); tft.print(ETH.subnetMask());
              tft.setCursor(70, 100); tft.print("GW: "); tft.print(ETH.gatewayIP());
}

    tft.setTextSize(2);
   if (menu != 2){ button (x91,y91,x92,y92); tft.setCursor(180, 240); tft.print("SET DHCP"); }  //BUTTON DHCP
    button (xb1,yb1,xb2,yb2); tft.setCursor(359, 240); tft.print("HOME");   //BUTTON HOME
   if (menu == 2){ button (x51,y51,x52,y52); tft.setCursor(40, 240); tft.print("SAVE");}    //BUTTON SAVE 
   else {button (x51,y51,x52,y52); tft.setCursor(32, 240); tft.print("Static IP");}    //BUTTON IP 
    tft.setCursor(110, 40);
}
int check_ip(const int f[3][4])
{   
   for ( int row  = 0; row  <= 2; ++row ){
   for ( int column = 0; column <=3 ; ++column ){
    if (f[row][column] > 255 or f[0][0]  == 0 or f[0][0]  > 254 or f[2][0]  > 254 or f[2][0] == 0)
    {
        tft.fillRect (0, 25, 480, 295 , TFT_BLACK); tft.setTextSize(3); tft.setCursor(40, 40); tft.setTextColor(TFT_RED); tft.print ("EROR Enter IP Static"); 
        delay(4000); e=1; tft.fillRect (0, 25, 480, 120 , TFT_BLACK); menu=2; break;}
   }
   }
   if (e==0){
              tft.fillRect (0, 25, 480, 170 , TFT_BLACK);
              tft.setCursor(70, 40); tft.print("IP: "); tft.print(IPAddress(f[0][0],f[0][1],f[0][2],f[0][3]));
              tft.setCursor(70, 70); tft.print("Mask: "); tft.print(IPAddress(f[1][0],f[1][1],f[1][2],f[1][3]));
              tft.setCursor(70, 100); tft.print("GW: "); tft.print(IPAddress(f[2][0],f[2][1],f[2][2],f[2][3]));
              menu=5;
              }else {menu=2; set_ip(menu);}
              return menu;
   }