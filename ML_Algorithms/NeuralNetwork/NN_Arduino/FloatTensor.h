#ifndef _Tensor_H
#define _Tensor_H

class FloatTensor
{
private:
    float *pTensor;
    
public:
    unsigned int row;
    unsigned int col;
    
    FloatTensor(float *pTensor, unsigned int row, unsigned int col);
    float returnOneValue(unsigned int row, unsigned int col);
    void setOneValue(float value, unsigned int row, unsigned int col);
    ~FloatTensor();
};

class ConstFloatTensor
{
private:
    const float *pTensor;
    
public:
    unsigned int row;
    unsigned int col;
    
    ConstFloatTensor(const float *pTensor, unsigned int row, unsigned int col);
    float returnOneValue(unsigned int row, unsigned int col);
    ~ConstFloatTensor();
};




#endif
