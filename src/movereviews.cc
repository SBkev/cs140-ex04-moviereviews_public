//
// Created by kevinsh on 10/3/2018.
//

#include <cmath>
#include <iostream>

namespace edu {
    namespace sbcc {
        namespace cs140 {
            static constexpr size_t NUMBER_MOVIES = 6;
            static constexpr size_t MAX_REVIEWS = 1000;
            void predictEmptyReviews (int reviewsExisting [1000] [6], int reviewsUser [6] [1], int maxSize) {
                //figure this out later
            }
            //above was defined by the assignment


            double cartesianDistance (const int array1[], const int  array2[], int size){
                //this function is only valid for comparing two arrays with the same size
                using namespace std;
                
//                for (int i=0; i < size-1; i++) {
//                    array1[i] = a[i];
//                    array2[i] = b[i];
//                    //this loop populates array1 and array2 with the values from a[] and b[]
//                    //TODO is this for loop even necessary? I think this is how full arrays must be passed
//                }

//                double squared_diff [size];
//                for (int i=0; i < size-1; i++) {
//                    squared_diff[i] = pow(array1[i] - array2[i], 2);
//                    //this calculates the squared difference between each corresponding array element of array1 and 2
//                }

                double array_sum = 0;
                for (int i=0; i < size-1; i++){
                    array_sum += pow(array1[i] - array2[i],2);
                }

                double distance;
                distance = sqrt(array_sum);
                return distance;
            }

        }
    }
}