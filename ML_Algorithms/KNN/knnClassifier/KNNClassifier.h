#ifndef _KNN_CLASSIFIER_H_
#define _KNN_CLASSIFIER_H_

#include "dataset.h"

// double distanceCalculation(){}
void KNNClassifier(float finger1, float finger2, float finger3, float finger4, float finger5, const int gesture[6], int distanceCluster[14], float distanceMatrix[14]);
void sort(float matrix[14], int cluster[14], int temp0, int temp1, int k);
int cluster(int cluster[14], int k);


#endif