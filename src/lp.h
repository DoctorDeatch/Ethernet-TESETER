
            void GW(int set_ping) {
                        for (int i = 1; i <= set_ping; i++) {
            tft.setCursor(5, 70+(i*25));
            bool ret = Ping.ping(ETH.gatewayIP());
             tft.print("PING");tft.print(i);tft.print(": ");tft.print(ETH.gatewayIP());tft.print(" ");
             if(ret == 1){
                     float avg_time_ms = Ping.averageTime();
                     tft.print(avg_time_ms);tft.print("mS");
                            } else {tft.print("Request timed out.");} } 
            }    

            void HO(char* host,int set_ping) {
                        for (int i = 1; i <= set_ping; i++) {
            tft.setCursor(5, 70+(i*25));
            bool ret = Ping.ping(host);
             tft.print("PING");tft.print(i);tft.print(": ");tft.print(host);tft.print(" ");
             if(ret == 1){
                     float avg_time_ms = Ping.averageTime();
                     tft.print(avg_time_ms);tft.print("mS");
                            } else {tft.print("Request timed out.");} } 
            }     

            void HL() {
            tft.setCursor(5, 115);
             bool ret1 = Ping.ping(ETH.gatewayIP());
             tft.print("PING ");tft.print(ETH.gatewayIP());tft.print(": ");
              if(ret1 == 1){
                     float avg_time_ms = Ping.averageTime();
                     tft.print(avg_time_ms);tft.print("mS");
                            } else {tft.print("Request timed out.");} 
            tft.setCursor(5, 140);
             bool ret2 = Ping.ping("ya.ru");
             tft.print("PING ya.ru: ");tft.print(" ");
              if(ret2 == 1){
                     float avg_time_ms = Ping.averageTime();
                     tft.print(avg_time_ms);tft.print("mS");
                            } else {tft.print("Request timed out.");} 
            tft.setCursor(5, 165);
             bool ret3 = Ping.ping("googl.com");
             tft.print("PING googl.com: ");tft.print(" ");
             if(ret3 == 1){
                     float avg_time_ms = Ping.averageTime();
                     tft.print(avg_time_ms);tft.print("mS");
                            } else {tft.print("Request timed out.");} 
            }    

            void lp(int rh, int set_ping, char* mask, char** host_name) {
            tft.fillRect (0, 25, 480, 295 , TFT_BLACK);
            tft.setTextSize(2); tft.setTextFont(2);tft.setTextColor(TFT_WHITE);
            button (xb1,yb1,xb2,yb2); tft.setCursor(359, 240); tft.print("HOME");   //BUTTON HOME
            button (x51,y51,x52,y52); tft.setCursor(40, 240); tft.print("REPEAT");   //BUTTON REPEAT
             tft.setTextSize(2); tft.setTextFont(1);tft.setTextColor(TFT_WHITE);
            tft.setCursor(5, 33); tft.print("Link: ");
             float avg_time_ms = Ping.averageTime();
             if (digitalRead(nicCable)==0){ 
             tft.setTextColor(TFT_GREEN);tft.print("OK ");tft.setTextColor(TFT_WHITE);tft.print(ETH.linkSpeed()); tft.print("Mbps");
             tft.setCursor(240, 33); tft.print("DNS: ");tft.print(ETH.dnsIP());
            //sprintf(mask,"%d.%d.%d.%d", ETH.subnetMask());
           // if (mask=="255.255.255.255") pref="/32";
           // if (mask=="255.255.255.0") pref="/24";
             tft.setCursor(5, 60); tft.print("IP: ");tft.print(ETH.localIP());tft.print(" MASK:");tft.print(ETH.subnetMask());tft.setTextColor(TFT_GREEN);
            if (rh==1) GW(set_ping);
            if (rh==2) HO(host_name[0],set_ping);
            if (rh==3) HO(host_name[1],set_ping);
            if (rh==4) HL();   
             } else {tft.setTextColor(TFT_MAGENTA);tft.print("No Cable");tft.print(digitalRead(nicCable));}
            }
