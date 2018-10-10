// Copyright 2018, Allan Knight.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Allan Knight nor the names of other
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// A unit tester for EX05-String in CS140 at Santa Barbara City College.
//
// Author: ahknight@pipeline.sbcc.edu (Allan Knight)


// Includes for google test and the unit under test.

#include <climits>

#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <functional>

#include "gtest/gtest.h"

#include "moviereviews.h"
#include "GTestNoDeath.h"

namespace {

using edu::sbcc::cs140::predictEmptyReviews;
using edu::sbcc::cs140::NUMBER_MOVIES;
using edu::sbcc::cs140::MAX_REVIEWS;

void readMovieReviews(const std::string &filename, uint8_t reviews[1000][6]) {
    std::ifstream in(filename);

    size_t count = 0;
    for (; !in.eof(); count++) {
        for (size_t j = 0; j < NUMBER_MOVIES; j++) {
            uint32_t value;
            in >> value;
            reviews[count][j] = static_cast<uint8_t >(value);
        }
    }
}

// Tests edu::sbcc:cs140::String.

using std::istringstream;
using std::ostringstream;
using std::string;

using namespace ::testing_internal;

class MovieReviewsTest : public ::testing::Test {
protected:
    static const uint8_t MAX_TESTED_SCORE = 20;
    static const uint8_t MAX_OVERALL_SCORE = 25;
    static uint8_t _testScore;

protected:
    static void TearDownTestCase() {
        if (_testScore == MAX_TESTED_SCORE) {
            std::cout << std::endl << "Your unit test score is "
                      << _testScore << " out of "
                      << MAX_TESTED_SCORE << std::endl;
        } else {
            std::cout << "Your unit test score is "
                      << _testScore << " out of "
                      << MAX_TESTED_SCORE << " ("<< (int)(_testScore - MAX_TESTED_SCORE)
                      << ")" << std::endl;
        }

        std::cout << "The assignment is worth a total of " << MAX_OVERALL_SCORE
                  << " where the remaining points" << std::endl;
        std::cout << "comes from grading related to documentation, algorithms, and other"
                  << std::endl;
        std::cout << "criteria." << std::endl << std::endl;
    }
};

uint8_t MovieReviewsTest::_testScore = 0;

uint8_t DEFAULT_REVIEWS[][NUMBER_MOVIES] = {
        {3, 1, 5, 2, 1, 5},
        {4, 2, 1, 4, 2, 4},
        {3, 1, 2, 4, 4, 1},
        {5, 1, 4, 2, 4, 2}
};

TEST_F(MovieReviewsTest, DefaultCase) {
    // This test is named "Identity", it checks that the basic identity
    // complex number, i, has the correct values for real and imaginary
    // parts.

    uint8_t userReview1[] = {0, 1, 0, 2, 0, 3};
    predictEmptyReviews(DEFAULT_REVIEWS, userReview1, 4);

    ASSERT_EQ(5, userReview1[0]);
    ASSERT_EQ(1, userReview1[1]);
    ASSERT_EQ(4, userReview1[2]);
    ASSERT_EQ(2, userReview1[3]);
    ASSERT_EQ(4, userReview1[4]);
    ASSERT_EQ(3, userReview1[5]);

    uint8_t userReview2[] = {5, 0, 4, 0, 3, 0};
    predictEmptyReviews(DEFAULT_REVIEWS, userReview2, 4);

    ASSERT_EQ(5, userReview2[0]);
    ASSERT_EQ(1, userReview2[1]);
    ASSERT_EQ(4, userReview2[2]);
    ASSERT_EQ(2, userReview2[3]);
    ASSERT_EQ(3, userReview2[4]);
    ASSERT_EQ(2, userReview2[5]);

    _testScore += 5;
}

TEST_F(MovieReviewsTest, ThousandReviews) {
    uint8_t reviews[MAX_REVIEWS][NUMBER_MOVIES];
    readMovieReviews("../reviews.txt", reviews);

    uint8_t userReview1[] = {0, 1, 0, 2, 0, 3};
    predictEmptyReviews(reviews, userReview1, MAX_REVIEWS);

    ASSERT_EQ(4, userReview1[0]);
    ASSERT_EQ(1, userReview1[1]);
    ASSERT_EQ(4, userReview1[2]);
    ASSERT_EQ(2, userReview1[3]);
    ASSERT_EQ(3, userReview1[4]);
    ASSERT_EQ(3, userReview1[5]);

    uint8_t userReview2[] = {5, 0, 4, 0, 3, 0};
    predictEmptyReviews(reviews, userReview2, MAX_REVIEWS);

    ASSERT_EQ(5, userReview2[0]);
    ASSERT_EQ(3, userReview2[1]);
    ASSERT_EQ(4, userReview2[2]);
    ASSERT_EQ(3, userReview2[3]);
    ASSERT_EQ(3, userReview2[4]);
    ASSERT_EQ(3, userReview2[5]);

    _testScore += 10;
}

TEST_F(MovieReviewsTest, ErrorCheckingSizeTooBig) {
    uint8_t reviews[1000][6];
    readMovieReviews("../reviews.txt", reviews);

    uint8_t userReview1[] = {0, 1, 0, 2, 0, 3};

    ASSERT_NO_DEATH(predictEmptyReviews(reviews, userReview1, 10001), "");

    predictEmptyReviews(reviews, userReview1, 10001);
    ASSERT_EQ(4, userReview1[0]);
    ASSERT_EQ(1, userReview1[1]);
    ASSERT_EQ(4, userReview1[2]);
    ASSERT_EQ(2, userReview1[3]);
    ASSERT_EQ(3, userReview1[4]);
    ASSERT_EQ(3, userReview1[5]);

    _testScore += 2;
}

TEST_F(MovieReviewsTest, ErrorCheckingNullReviews) {
    uint8_t userReview2[] = {0, 1, 0, 2, 0, 3};

    ASSERT_NO_DEATH(predictEmptyReviews(nullptr, userReview2, 1000), "");

    predictEmptyReviews(nullptr, userReview2, 1000);
    ASSERT_EQ(0, userReview2[0]);
    ASSERT_EQ(1, userReview2[1]);
    ASSERT_EQ(0, userReview2[2]);
    ASSERT_EQ(2, userReview2[3]);
    ASSERT_EQ(0, userReview2[4]);
    ASSERT_EQ(3, userReview2[5]);

    _testScore += 2;
}

TEST_F(MovieReviewsTest, ErrorCheckingNullUserReview) {
    ASSERT_NO_DEATH(predictEmptyReviews(DEFAULT_REVIEWS, NULL, 4), "");
    _testScore += 1;
}

}