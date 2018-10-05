//
// Created by kevinsh on 10/3/2018.
//

#ifndef EX04_MOVIEREVIEWS_MOVIEREVIEWS_H
#define EX04_MOVIEREVIEWS_MOVIEREVIEWS_H

namespace edu {
    namespace sbcc {
        namespace cs140 {
            static constexpr size_t NUMBER_MOVIES = 6;
            static constexpr size_t MAX_REVIEWS = 1000;
            void predictEmptyReviews (int reviewsExisting [1000] [6], int reviewsUser [6] [1], int maxSize);
            double cartesianDistance (const int a[], const int b[], int size);
        }
    }
}

#endif //EX04_MOVIEREVIEWS_MOVIEREVIEWS_H
