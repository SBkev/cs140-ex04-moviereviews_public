//
// Created by kevinsh on 10/3/2018.
//

#ifndef EX04_MOVIEREVIEWS_MOVIEREVIEWS_H
#define EX04_MOVIEREVIEWS_MOVIEREVIEWS_H

#include <cstdint>

namespace edu {
    namespace sbcc {
        namespace cs140 {
            static constexpr size_t NUMBER_MOVIES = 6;
            static constexpr size_t MAX_REVIEWS = 1000;
            void predictEmptyReviews (const uint8_t reviews [MAX_REVIEWS] [NUMBER_MOVIES], uint8_t user_reviews [NUMBER_MOVIES], const int review_number);
        }
    }
}

#endif //EX04_MOVIEREVIEWS_MOVIEREVIEWS_H
