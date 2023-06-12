#pragma once
#include "Paragraph.h"
class Character
{
	int *CharacterPerPara;
	int Size;
public:
	Character();
	void AddWord_OF_Character(int num);

	void display();
	~Character();
};

