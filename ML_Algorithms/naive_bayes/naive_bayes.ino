#include <Arduino.h>
#include <miniOled.h>
#include <math.h>

#define flex5 A5
// #define flex4 A3
#define flex3 A2
#define flex2 A1
#define flex4 A4
#define flex1 A0
#define div 1023.0f
#define div 1023.0f


const float sigma[10][5] = {
  {0.00132962,0.00062944,0.0008008, 0.00296825,0.0009937},
  {0.00130228,0.00034435,0.00389967,0.00061536,0.00074416},
  {0.00083522,0.00034296,0.00060446,0.00027329,0.00031056},
  {0.0010332,0.00028525,0.00495519,0.00032094,0.00038592},
  {0.00060954,0.00020019,0.00042023,0.00030564,0.00119816},
  {0.00073857,0.00012316,0.00057649,0.00043563,0.00011596},
  {0.00078642,0.00067329,0.00051905,0.0003964,0.00039362},
  {0.000533,0.00117292,0.00080385,0.00052073,0.00077222},
  {0.00132215,0.00027355,0.00047443,0.00038114,0.00011825},
  {0.00123097,0.00125514,0.00192722,0.0076452,0.00102985}
};

const float theta[10][5]={
  {0.4585793 ,0.51173657 ,0.49624342, 0.4744346 , 0.29857348},
  {0.4735585 ,0.52812687, 0.53010685, 0.6795072 , 0.31335086},
  {0.4865984 , 0.52990835, 0.68996086, 0.68527203 ,0.31853972},
  {0.64872239, 0.67939728, 0.66703714, 0.50787252, 0.30032461},
  {0.64773514 ,0.68370819, 0.68779306 ,0.68706587,0.28603283},
  {0.6463258 , 0.68742687 ,0.69368549 ,0.68697265, 0.39195296},
  {0.61172354 ,0.551114 ,  0.52917024, 0.52683517, 0.38022984},
  {0.47195202, 0.53934366, 0.60318017, 0.61589846, 0.36914159},
  {0.4643906 , 0.52919082, 0.52168136 ,0.68288631 ,0.38416352},
  {0.45818187, 0.51397158, 0.49603774 ,0.51018 ,   0.28754519}
};

const float log_prior[10]={
    -2.213204579630663,
    -2.3479134126361236,
    -2.3237036641288973,
    -2.332017799781164,
    -2.3255452852755467,
    -2.332017799781164,
    -2.339466623794155,
    -2.3413375317299665,
    -2.342274299948353,
    -2.1493870761892606
};


//OLED* myOLED; 
void setup()  
 { 
 //prepare();  
 Serial.begin(9600); 
 OLED *myOLED = new OLED(); 
 //OLED_Init(); 
 myOLED->init(); //initialze OLED display 
 myOLED->wideFont = true; 
 myOLED->chrSpace=3; 
   delete(myOLED); 
 myOLED = new OLED(); 
 delay(200); 
 myOLED->printString("Result is", 5, 2, 9); 
 delete(myOLED); 
 }


void loop() 
{
  unsigned int flexValue5 = analogRead(flex5)-70;
  unsigned int flexValue4 = analogRead(flex4)+100;
  unsigned int flexValue3 = analogRead(flex3)+100;
  unsigned int flexValue2 = analogRead(flex2)+50;
  unsigned int flexValue1 = analogRead(flex1)+30;
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
  

  float fingerdata[5];
  fingerdata[0] = (float)flexValue1/div;
  fingerdata[1] = (float)flexValue2/div;
  fingerdata[2] = (float)flexValue3/div;
  fingerdata[3] = (float)flexValue4/div;
  fingerdata[4] = (float)flexValue5/div; //big thumb

  //float fingerdata[5] = {0.458455522971652, 0.52297165200391,0.5004887585532747,0.4975562072336266,0.2541544477028348};
  //Serial.print(fingerdata[1]);
  //Serial.println(" ");
  
  
    float number_1;
    float number_2;
    float accum_1 = 0.0f;
    float accum_2 = 0.0f;
    float n_ij;
    float result[10];


    for (int i=0; i<10; i=i+1)
    {
      for(int j=0; j<5; j=j+1)
      {
        number_1 = log(2. * M_PI * sigma[i][j]);
        accum_1 = accum_1 + number_1;
      }
        
        n_ij = -0.5 * accum_1;
                
        for(int m=0; m<5; m=m+1)
        {
            number_2 = (fingerdata[m] - theta[i][m])*(fingerdata[m] - theta[i][m])/sigma[i][m];
            accum_2 = accum_2 + number_2;
        }
        
        n_ij -= 0.5 * accum_2;
        n_ij = n_ij + log_prior[i];
        
        result[i]=n_ij;
                        
        accum_1 = 0.0f;
        accum_2 = 0.0f;
    }


    float max=0;
    int maxdex=0;
    
    for(int i=0;i<10;i++)
    {
    if (result[i]>max)
    {
    max=result[i];
    maxdex=i;
    }
    }


  Serial.print(maxdex);

  Serial.println(" ");
  delay(200);
}
