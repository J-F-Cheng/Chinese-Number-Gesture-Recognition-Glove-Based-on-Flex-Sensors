#ifndef _NeuralNetwork_H
#define _NeuralNetwork_H

#include "FloatTensor.h"
#include "math.h"




class NeuralNetwork{
    private:

    public:
        void MatrixMul(FloatTensor* input, ConstFloatTensor *layer, FloatTensor* output);
        void DenseForward(FloatTensor* input, ConstFloatTensor *layer, const float *layerBias, FloatTensor* output);
        void ReLu(FloatTensor *input);
        void SoftMax(FloatTensor *input);
};



#endif
