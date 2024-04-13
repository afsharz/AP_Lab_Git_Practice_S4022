//test
#include "Score.h"

Score::Score(int score,char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;

}

void Score::setID_generator(int id_g)
{
	ID_generator = id_g;
}
int Score::getScore()
{
	return score;
}
string Score::getDetail() {
	return detail;
}
int Score::getID() {
	return ID;
}
void print(const Score& score) 
{
	cout << score.score;

}
Score::Score(Score& s):ID(s.getScore())
{
	score = s.getScore();
	detail = s.getDetail();
}
Score& Score::operator=(const Score&  s)
{
	score = s.getScore();
	detail = s.getDetail();
	return this;
}





