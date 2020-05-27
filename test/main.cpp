#include "../src/source.h"
#include "gtest/gtest.h"

TEST(TestCheckUserAnswer, WrongInputBellow)
{
    int WrongUserAnswer = 2;
    int result = testCheck(WrongUserAnswer);
    int expected = 0;
    EXPECT_EQ(expected, result);
}

TEST(TestCheckUserAnswer, WrongInputAbove)
{
    int WrongUserAnswer = 4;
    int result = testCheck(WrongUserAnswer);
    int expected = 0;
    EXPECT_EQ(expected, result);
}

TEST(TestChecktUserAnswer, ValidInput)
{
    int UserAnswer = 3;
    int result = testCheck(UserAnswer);
    int expected = 1;
    EXPECT_EQ(expected, result);
}

TEST(YesCheck, WrongInput)
{
    char sym = 'W';
    int result = yesCheck(sym);
    int expected = 0;
    EXPECT_EQ(expected, result);
}

TEST(YesCheck, ValidInputUpCase)
{
    char sym = 'Y';
    int result = yesCheck(sym);
    int expected = 1;
    EXPECT_EQ(expected, result);
}

TEST(YesCheck, ValidInputLowCase)
{
    char sym = 'y';
    int result = yesCheck(sym);
    int expected = 1;
    EXPECT_EQ(expected, result);
}

TEST(VerbCheck, RightInput)
{
    string user = "Valid";
    string verb = "Valid";
    int result = verbCheck(user, verb);
    int expected = 1;
    EXPECT_EQ(expected, result);
}

TEST(VerbCheck, RightInputButInLowCase)
{
    string user = "valid";
    string verb = "valid";
    int result = verbCheck(user, verb);
    int expected = 1;
    EXPECT_EQ(expected, result);
}

TEST(VerbCheck, RightInputWithManyWords)
{
    string user = "Valid + valid";
    string verb = "Valid + valid";
    int result = verbCheck(user, verb);
    int expected = 1;
    EXPECT_EQ(expected, result);
}

TEST(VerbCheck, ExitUserInput)
{
    string user = "exit";
    string verb = "Valid";
    int result = verbCheck(user, verb);
    int expected = 2;
    EXPECT_EQ(expected, result);
}

TEST(VerbCheck, ExitUserInputButUpperCase)
{
    string user = "Exit";
    string verb = "Valid";
    int result = verbCheck(user, verb);
    int expected = 0;
    EXPECT_EQ(expected, result);
}

TEST(VerbCheck, DifferentInput)
{
    string user = "Valid";
    string verb = "Invalid";
    int result = verbCheck(user, verb);
    int expected = 0;
    EXPECT_EQ(expected, result);
}

TEST(VerbCheck, DifferentInputInLowCase)
{
    string user = "valid";
    string verb = "invalid";
    int result = verbCheck(user, verb);
    int expected = 0;
    EXPECT_EQ(expected, result);
}

TEST(VerbCheck, RightInputWithDifferentCases)
{
    string user = "valid";
    string verb = "Valid";
    int result = verbCheck(user, verb);
    int expected = 0;
    EXPECT_EQ(expected, result);
}

TEST(VerbCheck, DifferentInputWithManyWords)
{
    string user = "Valid + valid";
    string verb = "Invalid + valid";
    int result = verbCheck(user, verb);
    int expected = 0;
    EXPECT_EQ(expected, result);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
