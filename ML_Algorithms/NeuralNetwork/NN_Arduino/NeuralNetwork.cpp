#include "NeuralNetwork.h"
#include <HardwareSerial.h>

// NeuralNetwork::NeuralNetwork(){
//     //this->layers = layers;
// }


void NeuralNetwork::MatrixMul(FloatTensor* input, ConstFloatTensor *layer, FloatTensor* output){
    for(int row = 0; row < input->row; row++){
        for(int col = 0; col < layer->col; col++){
            float acc = 0;
            for(int vectorN = 0; vectorN < input->col; vectorN++){
                acc += input->returnOneValue(row, vectorN) * layer->returnOneValue(vectorN, col);
            }
            output->setOneValue(acc, row, col);
        }
    }
}

void NeuralNetwork::DenseForward(FloatTensor* input, ConstFloatTensor *layer, const float *layerBias, FloatTensor* output){
    for(int row = 0; row < input->row; row++){
        for(int col = 0; col < layer->col; col++){
            float acc = 0;
            for(int vectorN = 0; vectorN < input->col; vectorN++){
                acc += input->returnOneValue(row, vectorN) * layer->returnOneValue(vectorN, col);
            }
            output->setOneValue(acc + *(layerBias + col), row, col);
        }
    }
}

void NeuralNetwork::ReLu(FloatTensor *input){
    for(int row = 0; row < input->row; row++){
        for(int col = 0; col < input->col; col++){
            if(input->returnOneValue(row, col) < 0){
                input->setOneValue(0, row, col);
            }
        }
    }
}

void NeuralNetwork::SoftMax(FloatTensor *input){
    for(int row = 0; row < input->row; row++){
        float expAcc = 0;
        for(int col = 0; col < input->col; col++){
            float expValue = (float)exp(input->returnOneValue(row, col));
            input->setOneValue(expValue, row, col);
            expAcc += expValue;
            //Serial.println(expAcc);
        }
        for(int col = 0; col < input->col; col++){  //Set the value
            float expValue = input->returnOneValue(row, col);
            input->setOneValue(expValue/expAcc, row, col);
        }
    }
}

//NeuralNetwork::~NeuralNetwork(){
    //Serial.println("neural network has been deleted");
//}