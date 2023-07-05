#include "pch.h"
#include "../Baseball/baseball.cpp"

using namespace std;

TEST(BaseballGame, ThrowExceptionWhenInputLengthIsUnmatched) {
	Baseball game;
	EXPECT_THROW(game.guess("12"), length_error);
}

TEST(BaseballGame, ThrowExceptionWhenInvalidChar) {
	Baseball game;
	EXPECT_THROW(game.guess("12s"), invalid_argument);
}