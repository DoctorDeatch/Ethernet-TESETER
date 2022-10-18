int x11=10; int y11=40; int x12=140; int y12=70;    //Button Left UP
int x21=168; int y21=40; int x22=140; int y22=70;   //Button Center UP
int x31=326; int y31=40; int x32=140; int y32=70;   //Button Right UP
int x71=10; int y71=130; int x72=140; int y72=70;   //Button Left Center
int x41=168; int y41=130; int x42=140; int y42=70;  //Button Center Center
int x81=326; int y81=130; int x82=140; int y82=70;  //Button Right Center
int x51=10; int y51=220; int x52=140; int y52=70;   //Button Left Down
int x91=168; int y91=220; int x92=140; int y92=70;  //Button Centre Dowan
int xb1=326; int yb1=220; int xb2=140; int yb2=70;  //Button Right Dowan
int kx[] = {0, 48, 96, 144, 192, 240,288, 336, 384, 432};
int kc[] = {10, 57, 106, 155, 204, 253, 300, 349, 397, 444};

void button(int x1, int y1, int x2, int y2) //Draw button
{
  //tft.setColor(0, 0, 255);
  tft.fillRoundRect (x1,y1,x2,y2,2,TFT_BLUE);
  //tft.setColor(255, 255, 255);
  tft.drawRoundRect (x1,y1,x2,y2,2,TFT_WHITE);
  //tft.drawRoundRect ((x1+1),(y1+1),(x2-1),(y2-1),2,TFT_RED);
}

void keyb (int x1, int c1, int p1)
{    tft.setTextSize(3);    tft.setTextFont(2);    tft.setTextColor(TFT_WHITE);
    tft.drawRoundRect(x1, 150, 45, 45, 3, TFT_WHITE); tft.setCursor(c1, 148);tft.print(p1);
    }