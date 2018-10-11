//
// Created by kevinsh on 10/3/2018.
//

#include "moviereviews.h"
#include <iostream>

int main(){
    using namespace edu::sbcc::cs140;
    int reviews_count = 4;
    uint8_t reviews [4][6] = {
            {3,1,5,2,1,5},
            {4,2,1,4,2,4},
            {3,1,2,4,4,1},
            {5,1,4,2,4,2},
    };
    uint8_t user_reviews[] = {0, 0, 5, 0, 2, 5};

    std::cout << "The user reviews are: " << std::endl;
    for (int i = 0; i < NUMBER_MOVIES; i++)
    {
        std::cout << unsigned(user_reviews[i]) << " ";
    }
    std::cout << std::endl;

    predictEmptyReviews(reviews, user_reviews, reviews_count);
    //std::cout << "print 4: " << user_reviews << std::endl;
    std::cout << "The predicted review is: ";
    for (int i = 0; i < NUMBER_MOVIES; i++)
    {
        std::cout << unsigned(user_reviews[i]) << " ";
    }
    std::cout << std::endl;
}
