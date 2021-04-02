#include "NeuralNetwork.h"
#include "FloatTensor.h"
#include "weight.h"
#include <miniOled.h>

#define LED 4

#define sensorPin A0
#define maxVoltage 5.0f
#define flex5 A5
#define flex4 A3
#define flex3 A2
#define flex2 A1
#define flex1 A0
#define div 1023.0f
#define BUTTON 2

#define inputRow 2
#define inputCol 5

void printMatrix(FloatTensor *t);
unsigned int retMax(FloatTensor *tensor);

unsigned int LED1_value = 0;

//OLED* myOLED;

void setup() 
{
  //prepare(); 
  Serial.begin(9600);
  OLED *myOLED = new OLED();
  //OLED_Init();
  myOLED->init();  //initialze OLED display
	myOLED->wideFont = true;
	myOLED->chrSpace=3;
  
  delete(myOLED);
  myOLED = new OLED();
  delay(200);
  myOLED->printString("Result is", 5, 2, 9);
  delete(myOLED);
  pinMode(BUTTON, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON), int_ISR, FALLING);
}

void loop() 
{
  
  unsigned int flexValue5 = analogRead(flex5);
  unsigned int flexValue4 = analogRead(flex4);
  unsigned int flexValue3 = analogRead(flex3);
  unsigned int flexValue2 = analogRead(flex2);
  unsigned int flexValue1 = analogRead(flex1);
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
  
  //Serial.println(" ");
  float orig_x[inputRow][inputCol];
  orig_x[0][0] = (float)flexValue1/div;
  orig_x[0][1] = (float)flexValue2/div;
  orig_x[0][2] = (float)flexValue3/div;
  orig_x[0][3] = (float)flexValue4/div;
  orig_x[0][4] = (float)flexValue5/div;

  FloatTensor x = FloatTensor(&orig_x[0][0], inputRow, inputCol);
  FloatTensor *px = &x;

  //----Output Tensor1
  float orig_out_1[inputRow][layerOutSize_1];
  FloatTensor o1 = FloatTensor(&orig_out_1[0][0], inputRow, layerOutSize_1);
  FloatTensor *po1 = &o1;

  //----------------------------------------Layer initialisation
  ConstFloatTensor w1 = ConstFloatTensor(&layer_1[0][0], layerInSize_1, layerOutSize_1);
  ConstFloatTensor *pw1 = &w1;
  const float *pb1 = &layer_bias_1[0];

  //----Output Tensor2
  float orig_out_2[inputRow][layerOutSize_2];
  FloatTensor o2 = FloatTensor(&orig_out_2[0][0], inputRow, layerOutSize_2);
  FloatTensor *po2 = &o2;

  //----------------------------------------Layer initialisation
  ConstFloatTensor w2 = ConstFloatTensor(&layer_2[0][0], layerInSize_2, layerOutSize_2);
  ConstFloatTensor *pw2 = &w2;
  const float *pb2 = &layer_bias_2[0];

  //Calculation
  NeuralNetwork* nn = new NeuralNetwork();
  nn->DenseForward(px, pw1, pb1, po1);
  nn->ReLu(po1);
  nn->DenseForward(po1, pw2, pb2, po2);
  nn->SoftMax(po2);
  delete(nn);
  register unsigned int re = retMax(po2);
  unsigned char s[] = "0.96' OLED TEST";
  //Serial.println(re);
  delay(200);
  long k = 0;
  OLED *myOLED = new OLED();
  //OLED_Init();
  //myOLED->printChar('R', 5, 3);
  //myOLED->printChar('e', 6, 3);
  
  myOLED->printChar(48 + re, 5, 5);
  delete(myOLED);
}

uint8_t LED_value = 0;

void int_ISR(){
  delay(20);
  if (digitalRead(BUTTON) == 0)
  {
    LED_value ^= 1;
    digitalWrite(LED, LED_value);
    //testValue++;
    
  }
  
  
}

void printMatrix(FloatTensor *t){
  for(int row = 0; row < t->row; row++){
    for(int col = 0; col < t->col; col++){
      Serial.print(t->returnOneValue(row, col));
      Serial.print("   ");
    }
    Serial.println("   ");
  }
}

unsigned int retMax(FloatTensor *tensor){
  unsigned int max = 0; //assume it is 0
  for(int col = 1; col < tensor->col; col++){
    if(tensor->returnOneValue(0, max) < tensor->returnOneValue(0, col)){
      max = col;
    }
  }
  return max;
}
