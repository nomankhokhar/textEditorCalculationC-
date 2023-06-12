#pragma once
#include "Paragraph.h"
class Word
{
	int *word;
	int size;
public:
	Word();
	void AddWordsofTence(int num);
	void Display();
	~Word();
};

