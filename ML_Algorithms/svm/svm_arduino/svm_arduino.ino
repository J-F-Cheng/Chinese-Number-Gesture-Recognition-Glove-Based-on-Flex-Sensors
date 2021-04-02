#include <miniOled.h>
#include <stdio.h>

#define flex5 A5
#define flex4 A3
#define flex3 A2
#define flex2 A1
#define flex1 A0


void setup() 
{
  Serial.begin(9600);
  
  OLED *myOLED = new OLED();
  //OLED_Init();
  myOLED->init();  //initialze OLED display
  myOLED->wideFont = true;
  myOLED->chrSpace=3;
  
  delete(myOLED);
  myOLED = new OLED();
  //delay(200);
  myOLED->printString("Result is", 5, 2, 9);
  delete(myOLED);
}

// SDA 9 SCL 8
void loop() 
{
  unsigned int flexValue5 = analogRead(flex5)+50;
  unsigned int flexValue4 = analogRead(flex4)+30;
  unsigned int flexValue3 = analogRead(flex3)+43;
  unsigned int flexValue2 = analogRead(flex2)+40;
  unsigned int flexValue1 = analogRead(flex1)-60;
  const int label = 9;
  Serial.print(flexValue1);
  Serial.print(",");
  Serial.print(flexValue2);
  Serial.print(",");
  Serial.print(flexValue3);
  Serial.print(",");
  Serial.print(flexValue4);
  Serial.print(",");
  Serial.print(flexValue5);
  Serial.print(",");
  Serial.println(label);
  
  //float input1[5]={526, 537, 676, 669, 359};
  //flexValue1 = input1[0];
  //flexValue2 = input1[1];
  //flexValue3 = input1[2];
  //flexValue4 = input1[3];
 // flexValue5 = input1[4];
   float g0,g1,g2,g3,g4,g5,g6,g7,g8,g9;
   float g[10];
   g[0] = -5.37560261f*flexValue1/1023 -4.85661530f*flexValue2/1023 +5.00373131f*flexValue3/1023 -11.3481306f*flexValue4/1023 +1.65414790f*flexValue5/1023 +7.30461178f;
   g[1] = -50.60101717f*flexValue1/1023 +29.36033828f*flexValue2/1023 -54.75714909f*flexValue3/1023 +104.21404171f*flexValue4/1023 -95.68064656f*flexValue5/1023 -0.19015655f;
   g[2] = -18.62201499f*flexValue1/1023   -2.44123798f*flexValue2/1023  +22.94568101f*flexValue3/1023  +22.89679894f*flexValue4/1023   -4.38149587f*flexValue5/1023 -18.36015102f;
   g[3] = 15.49456955f*flexValue1/1023   +18.69425868f*flexValue2/1023    +11.64123206f*flexValue3/1023   -29.32659667f*flexValue4/1023   -6.88786861f*flexValue5/1023 -10.94606478;
   g[4] = -58.11441739f*flexValue1/1023   +138.06492437f*flexValue2/1023    -18.98487221f*flexValue3/1023    +83.82729984f*flexValue4/1023  -89.4221121f*flexValue5/1023 -70.11342845f;
   g[5] = -0.1873184f*flexValue1/1023  +36.4372093f*flexValue2/1023   +13.45876681f*flexValue3/1023   -2.80328214f*flexValue4/1023   +105.80681626f*flexValue5/1023 -70.31739507f;
   g[6] = 65.071235f*flexValue1/1023  -54.28979713f*flexValue2/1023   -15.30534383f*flexValue3/1023  -13.23331916f*flexValue4/1023   +54.48296443f*flexValue5/1023 -10.39062152f;
   g[7] = -19.50005984f*flexValue1/1023  -4.10818806f*flexValue2/1023   +23.65402946f*flexValue3/1023   -20.82057432f*flexValue4/1023   +40.39137331f*flexValue5/1023 -4.87774695f;
   g[8] = 8.48073223f*flexValue1/1023  -42.5417683f*flexValue2/1023  -66.32388263f*flexValue3/1023   +64.2533739f*flexValue4/1023   +145.81947639f*flexValue5/1023 -43.37841274f;
   g[9] = -0.00887229f*flexValue1/1023  -0.0284477f*flexValue2/1023  -0.03393221f*flexValue3/1023    -0.01023362f*flexValue4/1023  -0.09516481f*flexValue5/1023 -0.92863564f;
   
   //g0 = -66.61541906f*flexValue1/1023 +21.46043157f*flexValue2/1023 +49.95588409f*flexValue3/1023 -65.37260614f*flexValue4/1023 -26.54488772f*flexValue5/1023 +33.68835648f;
   //g1 = -27.45605482f*flexValue1/1023 -2.21564921f*flexValue2/1023 -54.52904399f*flexValue3/1023 +158.41782383f*flexValue4/1023 -106.57556133f*flexValue5/1023 -29.26182918f;
   //g2 = -33.10563954f*flexValue1/1023   -7.94028393f*flexValue2/1023  +156.30421041f*flexValue3/1023  -13.46476292f*flexValue4/1023   +16.25857977f*flexValue5/1023 -85.83219424f;
   //g3 = 7.25670218f*flexValue1/1023   +11.17784458f*flexValue2/1023    +0.5758665f*flexValue3/1023   -16.17642062f*flexValue4/1023   -1.37786578f*flexValue5/1023 -3.16787448f;
   //g4 = 19.00505711f*flexValue1/1023   +34.73076404f*flexValue2/1023    +3.1067403f*flexValue3/1023    +36.49707115f*flexValue4/1023  -58.46238981f*flexValue5/1023 -43.79769608f;
   //g5 = 58.17489983f*flexValue1/1023  -13.29917653f*flexValue2/1023   +28.10795159f*flexValue3/1023   -0.51627735f*flexValue4/1023   +77.40073516f*flexValue5/1023 -75.24528559f;
   //g6 = 28.15397499f*flexValue1/1023  -39.35753646f*flexValue2/1023   -3.14898528f*flexValue3/1023  -10.86349645f*flexValue4/1023  +42.35861377f*flexValue5/1023 -2.08688596f;
   //g7 = -4.65707554f*flexValue1/1023  -18.52838012f*flexValue2/1023   +10.35541703f*flexValue3/1023   -5.93893163f*flexValue4/1023   +18.37206594f*flexValue5/1023 +2.00573827f;
   //g8 = 8.07977679f*flexValue1/1023  -17.98908274f*flexValue2/1023  -18.06964648f*flexValue3/1023   +36.78973302f*flexValue4/1023   +70.8391266f*flexValue5/1023 -35.76964969f;
   //g9 = 19.40909538f*flexValue1/1023  -31.57166153f*flexValue2/1023  -28.09963939f*flexValue3/1023    +0.52539466f*flexValue4/1023  -21.21133019f*flexValue5/1023 +26.67518599f;

    float max=g[0];
    int maxdex=0;
    
    for(int i=1;i<10;i++)
    {
    if (g[i]>max)
    {
    max=g[i];
    maxdex=i;
    }
    }
    OLED *myOLED = new OLED();
  
  
  myOLED->printChar(48 + maxdex, 5, 5);
  //delay(1000);
  delete(myOLED);

  Serial.print(maxdex);
 
  Serial.println(" ");
  delay(500);
}
