#include <stdexcept>

using namespace std;

struct GuessResult
{
	bool solved;
	int strikes;
	int balls;
};

class Baseball
{
public:
	bool isDuplicatedNumber(const string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1] ||
			guessNumber[0] == guessNumber[2] ||
			guessNumber[1] == guessNumber[2];
	}

	void assertIllegalArgument(const string& guessNumber)
	{
		if(guessNumber.length() != 3)
		{
			throw length_error("Must be three letters.");
		}

		for (char ch : guessNumber)
		{
			if(ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be numbers.");
		}

		if (isDuplicatedNumber(guessNumber))
		{
			throw invalid_argument("Must not have the same number");
		}
	}

	GuessResult guess(const string& guessNumber)
	{
		assertIllegalArgument(guessNumber);

		if (guessNumber == question) {
			return { true, 3, 0 };
		}

		int strikes = 0, balls = 0;
		for (int i = 0; i < 3; i++)
		{
			if (question[i] == guessNumber[i]) strikes++;
		}

		return { false, strikes, balls };
	}

	explicit Baseball(const string& question) : question(question) {}

private:
	string question;
};