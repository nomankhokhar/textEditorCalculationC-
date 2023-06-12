#include "Sentence.h"

Sentence::Sentence()
{
	totalSentence = nullptr;
	Size = 0;
}
void Sentence::AddSentence(int Sentence)
{
	regrow(totalSentence, Size);
	totalSentence[Size - 1] = Sentence;
}
void Sentence::Display()
{
	cout << endl;
	for (int i = 0; i < Size; i++)
	{
		cout << "Sentences in Paragraph 1 : " << totalSentence[i] << endl;
	}
}
Sentence::~Sentence()
{
	delete[]totalSentence;
	Size = 0;
}
