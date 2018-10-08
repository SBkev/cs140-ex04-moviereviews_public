//
// Created by kevinsh on 10/3/2018.
//

#include <cmath>
#include <iostream>
#include "moviereviews.h"

namespace edu {
    namespace sbcc {
        namespace cs140 {

            double cartesianDistance (const int array1[], const int  array2[], const size_t size)
            //precondition: this function is only valid for comparing two arrays with the same size
            //this function will calculate the distance between two arrays using the cartesian method
            {
                double array_sum = 0;
                for (int i=0; i < size; i++)
                {
                    array_sum += pow(array1[i] - array2[i],2);
                }
                return sqrt(array_sum); //return calculated distance
            }

            void addArrays(const int *array1, const int *array2, int *sum, const size_t size)
            // precondition: all array inputs are unique!
            // this function will add two arrays of the same size. result is passed into 'sum'
            {
                for (int i = 0; i < size; i++)
                {
                    sum[i] = array1[i] + array2[i];
                }
            }


            void predictEmptyReviews (const uint8_t reviews [][NUMBER_MOVIES], uint8_t userReviews [NUMBER_MOVIES], const int reviews_count)
            {
                //TODO: consider implementing the zero indexing operations in standalone function

                size_t nonzerocount = 0;
                size_t zerocount = 0;

                //count the number of zero & nonzero entries
                for (int i = 0; i < NUMBER_MOVIES; i++)
                {
                    if (userReviews[i] != 0)
                    {
                        nonzerocount+=1;
                    }
                    else
                    {
                        zerocount+=1;
                    }
                }

                int nonzeroindex[NUMBER_MOVIES];
                int zeroindices[NUMBER_MOVIES];

                //index the zero and nonzero entries
                for (int i = 0, j=0, k=0; i < NUMBER_MOVIES; i++)
                {
                    if (userReviews[i] != 0)
                    {
                        nonzeroindex[j] = i;
                        j+=1;
                    }
                    else
                    {
                        zeroindices[k] = i;
                        k+=1;
                    }
                }

                std::cout << "The nonzero indices are: " << nonzeroindex << ". The zero indices are: " << zeroindices << std::endl;

                // calculate the distance between nonzero entries of user and reviews
                double distance = 0;
                double minDistance = 0;
                int accumCount = 0;

                double accumReviews[NUMBER_MOVIES];
                int reviewIndexed[NUMBER_MOVIES];
                int userReviewIndexed[NUMBER_MOVIES];

                for (int i=0; i < reviews_count; i++) //iterate over reviews. calculate distance for each
                {
                    for (int j=0; j < nonzerocount; j++) //extract the reviews columns for distance calculation
                    {
                        reviewIndexed[j] = reviews[i][nonzeroindex[j]]; //iterate over columns of 1 review. extract the values for comparison
                        userReviewIndexed[j] = userReviews[nonzeroindex[j]]; //extract nonzero values from user reviews TODO: this could be performed once for efficiency's sake
                    }

                    distance = cartesianDistance(userReviewIndexed, reviewIndexed, nonzerocount);
                    std::cout << "Calculated distance for review " << i << " is " << distance;

                    if (i==0 || distance < minDistance) {
                        minDistance = distance;
                        std::memcpy(accumReviews, reviewIndexed, nonzerocount);
                        accumCount = 1;
                    }
                    else if (distance == minDistance) {
                        //int array_temp[nonzerocount]; //this is used to satisfy precondition of 'addArrays' function
                        //addArrays(&reviewIndexed, &accumReviews, &array_temp, nonzerocount);
                        //std::memcpy(accumReviews, array_temp, nonzerocount); //add reviewIndexed to accumReviews
                        // TODO: not sure why I can't call the addArrays function....

                        for (int k = 0; k < nonzerocount; k++)
                        {
                            accumReviews[k] = reviewIndexed[k] + accumReviews[k];
                        }
                        accumCount += 1;
                    }
                }

                double predictedReviews[NUMBER_MOVIES];

                //average values in accumReviews
                for (int i=0; i < nonzerocount; i++) {
                    predictedReviews[i] = accumReviews[i] / accumCount;
                }

                //replace zero entries of user reviews with values from predictedReviews
                for (int i=0; i< zerocount; i++){
                    userReviews[zeroindices[i]] = predictedReviews[i]; //TODO: is the type mismatch OK?
                }
            }

        }
    }
}