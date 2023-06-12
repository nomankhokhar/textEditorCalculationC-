#pragma once
#include "Paragraph.h"
class Sentence
{
	int *totalSentence;
	int Size;
public:
	Sentence();
	void AddSentence(int Sentence);

	void Display();
	~Sentence();
};

