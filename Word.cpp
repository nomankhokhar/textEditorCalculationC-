#include "Word.h"


Word::Word()
{
	word = nullptr;
	size = 0;
}
void Word::AddWordsofTence(int num)
{
	regrow(word,size);
	word[size - 1] = num;
}
void Word::Display()
{
	for (int k = 0; k < size; k++)
	{
		cout << "Words in Sentence no " << k + 1 << " : " << word[k] << endl;
	}
}

Word::~Word()
{
	delete[]word;
	size = 0;
}
