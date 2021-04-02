#include "FloatTensor.h"

FloatTensor::FloatTensor(float* pTensor, unsigned int row, unsigned int col){
    this->pTensor = pTensor;
    this->row = row;
    this->col = col;
}

float FloatTensor::returnOneValue(unsigned int row, unsigned int col){
    return *(this->pTensor + row * this->col + col);
}

void FloatTensor::setOneValue(float value, unsigned int row, unsigned int col){
    *(this->pTensor + row * this->col + col) = value;
}

FloatTensor::~FloatTensor(){
    //Serial.println("Has been deleted");
    //Serial.println("The tensor has been deleted.");
}

//------------------------------------------------
ConstFloatTensor::ConstFloatTensor(const float *pTensor, unsigned int row, unsigned int col){
    this->pTensor = pTensor;
    this->row = row;
    this->col = col;
}

float ConstFloatTensor::returnOneValue(unsigned int row, unsigned int col){
    return *(this->pTensor + row * this->col + col);
}

ConstFloatTensor::~ConstFloatTensor(){
    //Serial.println("Has been deleted");
    //Serial.println("The tensor has been deleted.");
}