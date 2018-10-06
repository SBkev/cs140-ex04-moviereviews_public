//
// Created by kevinsh on 10/3/2018.
//

#include <cmath>
#include <iostream>
#include "moviereviews.h"

namespace edu {
    namespace sbcc {
        namespace cs140 {

            double cartesianDistance (const int array1[], const int  array2[], int size)
            {
                //precondition: this function is only valid for comparing two arrays with the same size
                double array_sum = 0;
                for (int i=0; i < size; i++)
                {
                    array_sum += pow(array1[i] - array2[i],2);
                }
                return sqrt(array_sum); //return calculated distance
            }

            void predictEmptyReviews (uint8_t reviews [][NUMBER_MOVIES], uint8_t user_reviews [NUMBER_MOVIES], const int reviews_count)
            {
                int nonzerocount = 0;
                int zerocount = 0;

                //count the number of zero & nonzero entries
                for (int i = 0; i < NUMBER_MOVIES; i++)
                {
                    if (user_reviews[i] != 0)
                    {
                        nonzerocount+=1;
                    }
                    else
                    {
                        zerocount+=1;
                    }
                }

                int nonzeroindex[nonzerocount];
                int zeroindex[zerocount];

                //index the zero and nonzero entries
                for (int i = 0, j=0, k=0; i < NUMBER_MOVIES; i++)
                {
                    if (user_reviews[i] != 0)
                    {
                        nonzeroindex[j] = i;
                        j+=1;
                        i+=1;
                    }
                    else
                    {
                        zeroindex[k] = i;
                        k+=1;
                        i+=1;
                    }
                }

                std::cout << "The nonzero indices are: " << nonzeroindex << ". The zero indices are: " << zeroindex << std::endl;

                //now calculate the distance between nonzero entries of user and reviews
                double distance = 0;
                int nonzerouser
                for (int i=0; i < reviews_count; i++)
                {
                    distance = cartesianDistance()
                }



            }


            //above was defined by the assignment




        }
    }
}