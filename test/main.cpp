#include "../src/source.h"
#include "gtest/gtest.h"


TEST(TestCheck, WrongInputBellow)
{
	int rand = 2;
    int result = testCheck(rand);
    int expected = 0;
    EXPECT_EQ(expected, result);
}

TEST(TestCheck, WrongInputAbove)
{
	int rand = 4;
    int result = testCheck(rand);
    int expected = 0;
    EXPECT_EQ(expected, result);
}

TEST(TestCheckt, ValidInput)
{
    int result = testCheck(3);
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

TEST(VerbCheck, SameInput)
{
	string user = "Valid";
	string verb = "Valid";
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

TEST(VerbCheck, DifferentInput)
{
	string user = "Valid";
	string verb = "Invalid";
    int result = verbCheck(user, verb);
    int expected = 0;
    EXPECT_EQ(expected, result);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
