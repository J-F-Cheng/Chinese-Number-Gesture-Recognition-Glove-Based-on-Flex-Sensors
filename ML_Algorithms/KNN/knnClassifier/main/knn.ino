#include <avr/pgmspace.h>
#include "dataset.h"
#include "KNNClassifier.h"
#include <miniOled.h>

#define LED1 4

#define sensorPin A0
#define maxVoltage 5.0f
#define flex5 A5
#define flex4 A3
#define flex3 A2
#define flex2 A1
#define flex1 A0
//#define div 1023.0f

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


void loop() 
{
  unsigned int timecnt;
  timecnt = micros();
  int k = 5; // The hypeparameter of knn
  // for sorting
  int temp0 = 0;
  int temp1 = 0;
  // The following code is for baseline - Junfeng's glove
  //unsigned int flexValue5 = analogRead(flex5);
  //unsigned int flexValue4 = analogRead(flex4);
  //unsigned int flexValue3 = analogRead(flex3);
  //unsigned int flexValue2 = analogRead(flex2);
  //unsigned int flexValue1 = analogRead(flex1);
  //
  //for (int i = 0; i < 5; i++){
  //flexValue5 =   flexValue5 + analogRead(flex5);
  //flexValue4 =   flexValue4 + analogRead(flex4);
  //flexValue3 =   flexValue3 + analogRead(flex3);
  //flexValue2 =   flexValue2 + analogRead(flex2);
  //flexValue1 =   flexValue1 + analogRead(flex1);
  //}
  // The following code is for my glove 
  unsigned int flexValue5 = analogRead(flex5)-70;
  unsigned int flexValue4 = analogRead(flex4)+100;
  unsigned int flexValue3 = analogRead(flex3)+100;
  unsigned int flexValue2 = analogRead(flex2)+50;
  unsigned int flexValue1 = analogRead(flex1)+30;
  
  for (int i = 0; i < 5; i++){
  flexValue5 =   flexValue5 + analogRead(flex5)-70;
  flexValue4 =   flexValue4 + analogRead(flex4)+100;
  flexValue3 =   flexValue3 + analogRead(flex3)+100;
  flexValue2 =   flexValue2 + analogRead(flex2)+50;
  flexValue1 =   flexValue1 + analogRead(flex1)+30;
  }

  flexValue5 =   flexValue5/6;
  flexValue4 =   flexValue4/6;
  flexValue3 =   flexValue3/6;
  flexValue2 =   flexValue2/6;
  flexValue1 =   flexValue1/6;
  // Test
  // x = x-xmin/xmax-xmin
  //flexValue5 = (flexValue5-520)/ (700-480)
  //flexValue4 = (flexValue4-550)/ (715-530)
  //flexValue3 = (flexValue3-650)/ (715-530)
  //flexValue2 = (flexValue2-705)/ (710-530)
  //flexValue1 = (flexValue1-320)/ (400-295)
  
  //float flex5 = (static_cast<float>(flexValue5)-295)/ (400-295);
  //float flex4 = (static_cast<float>(flexValue4)-530)/ (710-530);
  //float flex3 = (static_cast<float>(flexValue3)-530)/ (710-530);
  //float flex2 = (static_cast<float>(flexValue2)-530)/ (710-530);
  //float flex1 = (static_cast<float>(flexValue1)-480)/ (680-480);
  
  //flexValue1 = (flexValue1-320)/ (400-295)
  float flex5 = (static_cast<float>(flexValue5));
  float flex4 = (static_cast<float>(flexValue4));
  float flex3 = (static_cast<float>(flexValue3));
  float flex2 = (static_cast<float>(flexValue2));
  float flex1 = (static_cast<float>(flexValue1));
  
  //int input1[5] = {714,722,744,515,286};
  //flexValue1 = input1[0];
  //flexValue2 = input1[1];
  //flexValue3 = input1[2];
  //flexValue4 = input1[3];
  //flexValue5 = input1[4];
  //
  // const int label = 3;

  int* distanceClusterOut = new int [6] {183,183,183,183,183,183};
  float* distanceMatrixOut = new float[6]{1000,1000,1000,1000,1000,1000};

  // Calculate 3 samples with minimum distance
  KNNClassifier(flex1, flex2, flex3, flex4, flex5, gesture0, distanceClusterOut, distanceMatrixOut);
  KNNClassifier(flex1, flex2, flex3, flex4, flex5, gesture1, distanceClusterOut, distanceMatrixOut);
  KNNClassifier(flex1, flex2, flex3, flex4, flex5, gesture2, distanceClusterOut, distanceMatrixOut);
  KNNClassifier(flex1, flex2, flex3, flex4, flex5, gesture3, distanceClusterOut, distanceMatrixOut);
  KNNClassifier(flex1, flex2, flex3, flex4, flex5, gesture4, distanceClusterOut, distanceMatrixOut);
  KNNClassifier(flex1, flex2, flex3, flex4, flex5, gesture5, distanceClusterOut, distanceMatrixOut);
  KNNClassifier(flex1, flex2, flex3, flex4, flex5, gesture6, distanceClusterOut, distanceMatrixOut);
  KNNClassifier(flex1, flex2, flex3, flex4, flex5, gesture7, distanceClusterOut, distanceMatrixOut);
  KNNClassifier(flex1, flex2, flex3, flex4, flex5, gesture8, distanceClusterOut, distanceMatrixOut);
  KNNClassifier(flex1, flex2, flex3, flex4, flex5, gesture9, distanceClusterOut, distanceMatrixOut);

  // Select the nearst k samples
  sort(distanceMatrixOut, distanceClusterOut,temp0,temp1,k);

  // Set the cluster
  int cluster_ = 100;
  cluster_ = cluster(distanceClusterOut, k);
  Serial.print("Flex sensor reading is : \n");
  Serial.print(flex5);
  Serial.print(",");
  Serial.print(flex4);
  Serial.print(",");
  Serial.print(flex3);
  Serial.print(",");
  Serial.print(flex2);
  Serial.print(",");
  Serial.print(flex1);
  // Serial.print(",");
  // Serial.println(label);
  Serial.print("\n");
    Serial.print( analogRead(flex5));
  Serial.print(",");
  Serial.print( analogRead(flex4));
  Serial.print(",");
  Serial.print( analogRead(flex3));
  Serial.print(",");
  Serial.print( analogRead(flex2));
  Serial.print(",");
  Serial.print( analogRead(flex1));
  // Serial.print(",");
  // Serial.println(label);
  Serial.print("\n");

  Serial.print("The nearst 6 distance is : \n");
  Serial.print(distanceMatrixOut[0]);
  Serial.print("; ");
  Serial.print(distanceMatrixOut[1]);
  Serial.print("; ");
  Serial.print(distanceMatrixOut[2]);
  Serial.print("; ");
  Serial.print(distanceMatrixOut[3]);
  Serial.print("; ");
  Serial.print(distanceMatrixOut[4]);
  Serial.print("; ");
  Serial.print(distanceMatrixOut[5]);
  Serial.print("\n");

  Serial.print("The nearst 6 class is : \n");
  Serial.print(distanceClusterOut[0]);
  Serial.print("; ");
  Serial.print(distanceClusterOut[1]);
  Serial.print("; ");
  Serial.print(distanceClusterOut[2]);
  Serial.print("; ");
  Serial.print(distanceClusterOut[3]);
  Serial.print("; ");
  Serial.print(distanceClusterOut[4]);
  Serial.print("; ");
  Serial.print(distanceClusterOut[5]);
  Serial.print("\n");

  Serial.print("k is : \n");
  Serial.print(k);
  Serial.print("\n");
  
  Serial.print("prediction is : \n");
  Serial.print(cluster_);
  Serial.print("\n");
    
  delete distanceClusterOut;
  distanceClusterOut = nullptr;
  delete distanceMatrixOut;
  distanceMatrixOut = nullptr;
  
  //Serial.println(" ");
  
  OLED *myOLED = new OLED();
  //OLED_Init();
  //myOLED->printChar('R', 5, 3);
  //myOLED->printChar('e', 6, 3);
  
  myOLED->printChar(48 + cluster_, 5, 5);
  //delay(1000);
  delete(myOLED);
  timecnt = micros()-timecnt;
  Serial.print("timecnt=\n");
  Serial.print(timecnt);
  Serial.print("\n");
}
