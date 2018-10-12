//
// Created by kevinsh on 10/3/2018.
//

#include <cmath>
#include <iostream>
#include "moviereviews.h"

namespace edu {
    namespace sbcc {
        namespace cs140 {
            void predictEmptyReviews (const uint8_t reviews [][NUMBER_MOVIES], uint8_t user_reviews [NUMBER_MOVIES], int reviews_count)
            //predict the empty reviews using the cartesian distance method
            {
                if (reviews == nullptr || user_reviews == nullptr)
                    return;
                if (reviews_count > MAX_REVIEWS)
                    reviews_count = MAX_REVIEWS;

                double distance = 0;
                double distance_min = 0; //minimum distance calculated
                double nearest_reviews[NUMBER_MOVIES]; //this accumulates values of nearest reviews. should be divided by nearest_count at end to yield predicted reviews
                int nearest_count = 0; //number of reviews with the same distance
                int reviews_row [NUMBER_MOVIES];

                for (int i=0; i < reviews_count; i++) //rows of reviews
                {
                    distance = 0;
                    for (int j = 0; j < NUMBER_MOVIES; j++) //columns of reviews
                    {
                        reviews_row[j] = reviews[i][j];
                        if (user_reviews[j] != 0) //only process non-zero reviews
                        {
                            distance += pow(reviews[i][j] - user_reviews[j], 2);
                        }
                    }
                    distance = sqrt(distance); //final distance calculation
                    //std::cout << "Calculated distance for review " << i << " is: " << distance << std::endl;

                    if (i==0 || distance < distance_min)
                    {
                        distance_min = distance;
                        //std::memcpy(nearest_reviews, reviews_row, NUMBER_MOVIES); //set nearest review to value of review row
                        for (int k=0; k < NUMBER_MOVIES; k++)
                        {
                            nearest_reviews[k] = reviews_row[k];
                        }
                        nearest_count = 1;
                    }
                    else if (distance == distance_min)
                    {
                        for (int k = 0; k < NUMBER_MOVIES; k++) //add columns of current review row to nearest_reviews
                        {
                            nearest_reviews[k] = reviews_row[k] + nearest_reviews[k];
                        }
                        nearest_count += 1;
                    }
                }

                std::cout << "Minimum distance is " << distance_min << std::endl;
                std::cout << "Nearest count is " << nearest_count << std::endl;
                std::cout << "Nearest reviews (averaged) are: ";
                for (int i = 0; i < NUMBER_MOVIES; i++)
                {
                    nearest_reviews[i] = nearest_reviews[i] / nearest_count; //average values in nearest_reviews
                    std::cout << nearest_reviews[i] << " ";
                }
                std::cout << std::endl;

                //replace values of user_reviews with predictions
                std::cout << "Predicted review is: ";
                for (int i = 0; i < NUMBER_MOVIES; i++)
                {
                    if (user_reviews[i] == 0) //only process zero value reviews
                    {
                        user_reviews[i] = uint8_t (std::round(nearest_reviews[i]));
                    }
                    std::cout << unsigned(user_reviews[i]) << " ";
                }
                std::cout << std::endl << std::endl << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << std::endl;
            }
        }
    }
}

