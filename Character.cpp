#include "Character.h"

Character::Character()
{
	CharacterPerPara = nullptr;
	Size = 0;
}
void Character::AddWord_OF_Character(int num)
{
	regrow(CharacterPerPara, Size);
	CharacterPerPara[Size - 1] = num;
}
void Character::display()
{
	cout << endl;
	for (int k = 0; k < Size; k++)
	{
		cout << "Characters in Word no " << k+1 <<" of Sentence no " << CharacterPerPara[k] << endl;
	}
}
Character::~Character()
{
	delete[]CharacterPerPara;
	Size = 0;
}
