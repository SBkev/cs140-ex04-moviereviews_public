## Exercise: Movie Reviews (25 Points)

The objective of this project is to familiarize your self with arrays and passing arrays to functions.

The first thing you will need to do is fork and clone this assignment
from GitHub. Follow the instructions 
[here](https://github.com/sbcc-cs140-fall2018/Course-Information/wiki)
to get started. 

Be sure that you fork the project first and use the URL from
the forked project when you clone it in CLion.

This assignment is based on the Programming Project 14 from Chapter 5 of the text book, Absolute C++, on page 236 (5th Edition). 

Wikipedia can help you understand the [nearest neighbor](https://en.wikipedia.org/wiki/Nearest_neighbor_search) problem if the 
explanation in the project explanation is not enough.

This project acted as a basis for this assignment, and as such the description here is the source of truth. Remember: when in doubt consult this assignment description.

### Writing the code for this Project

Writing the code for this project is very simple. You will create three files: a header and implementation of a function, and an implementation of main to test your personally test your code.

You will write one function called `predictEmptyReviews` that takes all the reviews we already have,
a set of user reviews, and the total number of reviews. There are only six movies, and only one user review, for each of the 6 movies.

#### predictEmptyReviews

This function, called `predictEmptyReviews` and in the `edu::sbcc::cs140` namespace, will take in two arrays, a two dimensional array with all the existing reviews, a Maximum of 1000, for the 6 movies, a user review with 6 reviews, including 0's where there is no review from the user, and to total number of reviews that already exist.

You will then use the nearest neighbor method to predict what rating the user gave for the movies that have a review score of 0. In the case where the multiple reviews from the full collection of reviews is the same distance, then take the average of all the scores with the same distance to make the predicted user rating.

To create this function you'll need a header file with a declaration so it can be used in other code, and an implementation file with the C++ code of this function.

##### moviereviews.h

First you'll need to create `moviereviews.h`. This is the only file that must be named exactly this. If you misspell, or use differenct capitalization, the test program will not compile.

In CLion in the project explorer, right-click the `include` directory
and chose `New => C++ Header File`. 

Under **Name** fill in
moviereviews. CLion will add the `.h` extension. Press **OK**. You should now see the file `windchillindex.h` in
the project explorer in the `include` directory.

Write your declaration of the `sort` in here in the `edu::sbcc::cs140` namespace.

In addition, I want you to get used to using constants. Add the following declarations within the `edu::sbcc::cs140` namespace, just above the function declaration: 
```cpp
static constexpr size_t NUMBER_MOVIES = 6;
static constexpr size_t MAX_REVIEWS = 1000;
```

##### Implementation

Next you'll need to create the implementation, separately from the declaration of the `predictEmptyReviews`. This can be done in any file in the `src` directory as long as it has the extension `.cc` and is not named `main.cc`. 

In CLion in the project explorer, right-click the `src` directory
and chose `New => C++ Source File`. 

Under **Name** fill in
moviereviews (or any other name besides `main`). CLion will add the extension, but by default 
adds the `.cpp` extension. All projects in this class will
use the `.cc` extension. Select `.cc` in the **Type** drop-down
and press **OK**. You should now see the file `moviereviews.cc` (or whatever you named the file) in
the project explorer in the `src` directory.

Write your implementation of the `sort` in here in the `edu::sbcc::cs140` namepspace.

#### main()

If you want to test this code yourself, without using the unit tests, which I recommend for at least the first few projects, then you will need to create a `main()` function in a file named `main.cc` in the `src` directory. It is very important that you name it exactly this way, or things might not compile properly.

In CLion in the project explorer, right-click the `src` directory
and chose `New => C++ Source File`. 

Under **Name** fill in
main. CLion will add the extension, but by default 
adds the `.cpp` extension. All projects in this class will
use the `.cc` extension. Select `.cc` in the **Type** drop-down
and press **OK**. You should now see the file `main.cc` in
the project explorer in the `src` directory.

### Running the code for this project

Running this code should be straightforward. In the drop-down 
menu in the upper right-hand corner you should see a *Run
Configuration* called `MovieReviews | Debug`. Make sure this 
configuration is selected and press the play button next to it.
In the **Run** view below the code you should see the output 
of running the program. It should look something like this:

```bash
Actual reviews: { 0 1 0 2 0 3 }
Predicted reviews: { 4 1 4 2 3 3 }

Process finished with exit code 0
```
Success! Now you can move on to testing your code.

### Testing the code for this project

Testing the code for this project is similar to running your code
as outlined above. In the drop-down menu in the upper right-hand
corner select the configuration `MovieReviews_Gtest` and press the 
play button next to it. In the **Run** view below the code you should
see the output of running these tests. It should look something
like this:

```bash
Running main() from gtest_main.cc
[==========] Running 5 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 5 tests from MovieReviewsTest
[ RUN      ] MovieReviewsTest.DefaultCase
[       OK ] MovieReviewsTest.DefaultCase (0 ms)
[ RUN      ] MovieReviewsTest.ThousandReviews
[       OK ] MovieReviewsTest.ThousandReviews (1 ms)
[ RUN      ] MovieReviewsTest.ErrorCheckingSizeTooBig
[       OK ] MovieReviewsTest.ErrorCheckingSizeTooBig (14 ms)
[ RUN      ] MovieReviewsTest.ErrorCheckingNullReviews
[       OK ] MovieReviewsTest.ErrorCheckingNullReviews (5 ms)
[ RUN      ] MovieReviewsTest.ErrorCheckingNullUserReview
[       OK ] MovieReviewsTest.ErrorCheckingNullUserReview (1 ms)

Your unit test score is 20 out of 20
The assignment is worth a total of 25 where the remaining points
comes from grading related to documentation, algorithms, and other
criteria.

[----------] 5 tests from MovieReviewsTest (21 ms total)

[----------] Global test environment tear-down
[==========] 5 tests from 1 test case ran. (21 ms total)
[  PASSED  ] 5 tests.

Process finished with exit code 0
```

Remember, You should also see your score for this
assignment minus code styling points which I will add later.

### Submitting the code for this project

First, right click on the project name, then select `Git -> Commit Directory...`. 
Make sure only the files you want to push are selected, `main.cc`, `moviereviews.h` and `moviereviews.cc`.
Then uncheck `Perform code analysis` and `Check TODO`. It's OK to leave them checked,
but committing will take longer. Leave `Run git hooks` checked. Put a message in `Commit Message`
and then press the **Commit** button. If anything goes wrong check the _Version Control_ view
in the lower left corner and select the _Console_ tab.
 
Finally, right click on the project name,
then select `Git -> Repository -> Push...`. Follow the onscreen directions
and press **OK**. This step will run the tests again, check that everything is OK
and then submit them to the cloud to have the tests run for grading.

If you do not understand these directions, or wish to do them on the command
line rather than in CLion, then read these [directions](https://github.com/sbcc-cs140-fall2018/Course-Information/wiki/How-to-Turn-In-Every-Project).
