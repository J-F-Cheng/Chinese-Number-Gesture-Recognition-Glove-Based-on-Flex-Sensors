#include <avr/pgmspace.h>
#include <math.h>
#include "KNNClassifier.h"
#include "dataset.h"

// double distanceCalculation(int finger1, int finger2, int finger3, int finger4, int finger5, const float gesture[]){
  //float distance = (finger1 - pgm_read_word_near(gesture110[0])*finger1 - pgm_read_byte_near(gesture110+0) + (finger2 - pgm_read_byte_near(gesture110+1))*(finger2 - pgm_read_byte_near(gesture110+1))+(finger3 - pgm_read_byte_near(gesture110+2))*(finger3 - pgm_read_byte_near(gesture110+2))+(finger4 - pgm_read_byte_near(gesture110+3))*(finger4 - pgm_read_byte_near(gesture110+3))+_(finger5 - pgm_read_byte_near(gesture110+4))*(finger5 - pgm_read_byte_near(gesture110+4));
//  double distance = sqrt((finger1 - pgm_read_word_near(gesture+6*number+0))*(finger1 - pgm_read_word_near(gesture+6*number+0)) +  (finger2 - pgm_read_word_near(gesture+6*number+1))*(finger2 - pgm_read_word_near(gesture+6*number+1)) + (finger3 - pgm_read_word_near(gesture+6*number+2))*(finger3 - pgm_read_word_near(gesture+6*number+2))  + (finger4 - pgm_read_word_near(gesture+6*number+3))*(finger4 - pgm_read_word_near(gesture+6*number+3))  + (finger5 - pgm_read_word_near(gesture+6*number+4))*(finger5 - pgm_read_word_near(gesture+6*number+4))) ;
//  return distance;
//  }

void KNNClassifier(float finger1, float finger2, float finger3, float finger4, float finger5, const int gesture[6], int distanceCluster[14], float distanceMatrix[14]){
  int number = 0;
  for (int number = 0; number<118; number++){
    /*
  double distance = sqrt(
    pow( finger1 - (static_cast<float>(pgm_read_word_near(gesture+6*number+0))-480) / (680-480),2 )
   + pow( finger2 - (static_cast<float>(pgm_read_word_near(gesture+6*number+1))-530)/ (710-530) ,2 )
    + pow( finger3 - (static_cast<float>(pgm_read_word_near(gesture+6*number+2))-530 )/ (710-530),2 )
      + pow( finger4 - (static_cast<float>(pgm_read_word_near(gesture+6*number+3))-530 )/ (710-530),2 )
        + pow( finger5 - (static_cast<float>(pgm_read_word_near(gesture+6*number+4))-295 )/ (400-295),2 ));
  */
   double distance = sqrt(
   pow( finger1 - static_cast<float>(pgm_read_word_near(gesture+6*number+0)),2 )
  + pow( finger2 - static_cast<float>(pgm_read_word_near(gesture+6*number+1)) ,2 )
   + pow( finger3 - static_cast<float>(pgm_read_word_near(gesture+6*number+2)),2 )
     + pow( finger4 - static_cast<float>(pgm_read_word_near(gesture+6*number+3)),2 )
       + pow( finger5 - static_cast<float>(pgm_read_word_near(gesture+6*number+4)),2 ));

  // double distance = distanceCalculation(flexValue1, flexValue2, flexValue3, flexValue4, flexValue5, gesture[6]);

  //double distance = sqrt(
 //   pow( finger1 - (static_cast<float>(pgm_read_word_near(gesture+6*number+0))-390) / (470-390),2 )
 //  + pow( finger2 - (static_cast<float>(pgm_read_word_near(gesture+6*number+1))-505) / (610-505) ,2 )
 //   + pow( finger3 - (static_cast<float>(pgm_read_word_near(gesture+6*number+2))-470 )/ (605-470),2 )
 //     + pow( finger4 - (static_cast<float>(pgm_read_word_near(gesture+6*number+3))-510 )/ (645-510),2 )
 //       + pow( finger5 - (static_cast<float>(pgm_read_word_near(gesture+6*number+4))-475 )/ (640-475),2 ));
  
  if (distance < distanceMatrix[0]){
    distanceMatrix[0] = distance;
    distanceCluster[0] = pgm_read_word_near(gesture+6*number+5);
  }
  else{
    if (distance < distanceMatrix[1]){
      distanceMatrix[1] = distance;
      distanceCluster[1] = pgm_read_word_near(gesture+6*number+5);
    }
    else{
      if (distance < distanceMatrix[2]){
        distanceMatrix[2] = distance;
        distanceCluster[2] = pgm_read_word_near(gesture+6*number+5);
      }
      else{
        if (distance < distanceMatrix[3]){
          distanceMatrix[3] = distance;
          distanceCluster[3] = pgm_read_word_near(gesture+6*number+5);
        }
        else{
          if (distance < distanceMatrix[4]){
            distanceMatrix[4] = distance;
            distanceCluster[4] = pgm_read_word_near(gesture+6*number+5);
          }else{
            if (distance < distanceMatrix[5]){
              distanceMatrix[5] = distance;
              distanceCluster[5] = pgm_read_word_near(gesture+6*number+5);
            }else{
            if (distance < distanceMatrix[6]){
              distanceMatrix[6] = distance;
              distanceCluster[6] = pgm_read_word_near(gesture+6*number+5);
              }else{
            if (distance < distanceMatrix[7]){
              distanceMatrix[7] = distance;
              distanceCluster[7] = pgm_read_word_near(gesture+6*number+5);
              }else{
            if (distance < distanceMatrix[8]){
              distanceMatrix[8] = distance;
              distanceCluster[8] = pgm_read_word_near(gesture+6*number+5);
              }else{
            if (distance < distanceMatrix[9]){
              distanceMatrix[9] = distance;
              distanceCluster[9] = pgm_read_word_near(gesture+6*number+5);
              }else{
            if (distance < distanceMatrix[10]){
              distanceMatrix[10] = distance;
              distanceCluster[10] = pgm_read_word_near(gesture+6*number+5);
              }else{
            if (distance < distanceMatrix[11]){
              distanceMatrix[11] = distance;
              distanceCluster[11] = pgm_read_word_near(gesture+6*number+5);
              }else{
            if (distance < distanceMatrix[12]){
              distanceMatrix[12] = distance;
              distanceCluster[12] = pgm_read_word_near(gesture+6*number+5);
                            }else{
            if (distance < distanceMatrix[13]){
              distanceMatrix[13] = distance;
              distanceCluster[13] = pgm_read_word_near(gesture+6*number+5);
                            }
                 } // 14           
                } // 13
                } // 12            
              } // 11
              } // 10
              } // 9 
              } // 8
              } // 7    
          } // The sixth distance
        } // The fifth distance
      } // The fourth distance
    }  // The third distance
  } // The second distance
  } // This is the loop for all element in each array
  
}

void sort(float matrix[14], int cluster[14], int temp0, int temp1, int k){
  for (int j=0; j<k-1; j++){
  for (int i=0; i<k-1; i++){
    if (pow(matrix[i],2) > pow(matrix[i+1],2)){
      temp0 = matrix[i];
      matrix[i] = matrix[i+1];
      matrix[i+1] = temp0;
      temp1 = cluster[i];
      cluster[i] = cluster[i+1];
      cluster[i+1] = temp1;
    }
  }
  }
}

int cluster(int cluster[14], int k){
  int number = cluster[0];
  int mode = number;
  int count = 1;
  int countMode = 0;
  int temp3 = 0;

  for (int j=0; j<k; j++){
    count = 0;
    number = cluster[j];
  // Calculate the times of one number
    for (int i=0; i<k; i++){
      if (number == cluster[i]){
        count ++;
      }
      // Compare the times it occurs with the maximum number
      if (count > countMode){
        countMode = count;
        // If true, mode = that number
        mode = number;
      }
    }
  }
  return mode;
}


// int cluster(int cluster[6], int k){
//   std::unordered_map<int, int> table; // map of items in "x" to the number of times observed.
//   for (int i = 0; i < k; i++){
//        table[cluster[i]]++;
//   }
//   
//   int mode = 0;
//   int mode_freq = 0;
//   for (auto itor = table.begin(); itor != table.end(); itor++){
//       if (itor->second > mode_freq)
//       {
//           mode = itor->first;
//           mode_freq = itor->second;
//       }
//   }
//     return mode;
// }