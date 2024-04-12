#include <iostream>
#include <string>
using namespace std;
class Score {
public:
	friend void print(const Score& score);
	
	typedef enum {
		GREAT,
		GOOD,
		NOTBAD,
		BAD,
	}Label;

	Score(int score,  char* detail, Label label);
	Score() {};
	Score(Score& s);

	void setID_generator(int id_g);
	int getScore();
	string getDetail();
	int getID();
	Score& operator=(const Score&  score);
private:
	int score;
	Label label;
	string detail;
	const int ID;
	static int ID_generator;
};



