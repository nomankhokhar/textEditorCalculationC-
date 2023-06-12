#include "Paragraph.h"
Paragraph::Paragraph()
{
	ParaList = nullptr;
	Size = 0;
	ParagraphNNO = nullptr;
	ParaSize = 0;
}
void Paragraph::TotalNumberOfParagraph()
{
	ifstream read;
	read.open("Frequency.txt");
	char A;
	int CountParagraph = 0;
	while (read.get(A))
	{
		if (A == '\n')
		{
			CountParagraph++;
			countParagraph(CountParagraph);
		}
	}
	read.close();
}
Paragraph &Paragraph::operator + (const Paragraph & OBJ)
{
	Paragraph OBJECT;
	OBJECT.Size = this->Size + OBJ.Size;
	OBJECT.ParaList = new char[OBJECT.Size+1];
	int i;
	for (i = 0; i < this->Size; i++)
	{
		OBJECT.ParaList[i] = this->ParaList[i];
	}

	OBJECT.ParaList[i] = ' ';

	int count = 0;
	for (int k = i; k < OBJECT.Size; k++)
	{
		OBJECT.ParaList[k] = OBJ.ParaList[count];
		count++;
	}
	return *this;
}
int Paragraph::SpellCheck()
{
	int Correction = 0;

	char Diction[10];
	ifstream read;
	read.open("Dictionery.txt");

	char Spell[10];
	ifstream readSpell;
	readSpell.open("Frequency.txt");
	while (read>>Diction)
	{
		while (readSpell >> Spell)
		{
			for (int l = 0; Diction[l]!='\0' ; l++)
			{
				if (Diction[l] = Spell[l])
				{
					continue;
				}
				else
				{
					Correction++;
					break;
				}
			}
		}
		readSpell.close();
	}
	read.close();
	return Correction;
}
Paragraph &Paragraph::operator % (int num)
{

	for (int k = 0; k < this->Size; k++)
	{
		this->ParaList[k] = this->ParaList[k] + num;
	}
	return *this;
}
Paragraph& Paragraph::operator * (int num)
{
	for (int l = 0; l < this->Size; l++)
	{
		this->ParaList[l] = this->ParaList[l] - num;
	}
	return *this;
}
Paragraph::Paragraph(const Paragraph & OBJ)
{
	this->Size = OBJ.Size;
	DeepCopy(this->ParaList, OBJ.ParaList, OBJ.Size);
}
Paragraph &Paragraph::operator = (const Paragraph & OBJ)
{
	this->Size = OBJ.Size;
	DeepCopy(this->ParaList, OBJ.ParaList, OBJ.Size);
	return *this;
}
bool Paragraph::operator == (const Paragraph & OBJ)
{
	bool status = 0;
	if (this->Size == OBJ.Size)
	{
		for (int i = 0; i < this->Size; i++)
		{
			if (this->ParaList[i] == OBJ.ParaList[i])
			{
				status = 1;
			}
			else
			{
				status = 0;
				return status;
			}
		}
	}
	return status;
}
Paragraph  Paragraph::operator + (int num)
{
	for (int i = 0; i < this->Size; i++)
	{
		if (this->ParaList[i] >= 'a' && this->ParaList[i] <= 'z')
		{
			this->ParaList[i] = this->ParaList[i] - 32;
		}
	}
	return *this;
}
Paragraph Paragraph::operator - (int num)
{
	for (int i = 0; i < this->Size; i++)
	{
		if (this->ParaList[i] >= 'A' && this->ParaList[i] <= 'Z')
		{
			this->ParaList[i] = this->ParaList[i] + 32;
		}
	}
	return *this;
}
int Paragraph::CountPunction()
{
	int PunctionCharacterList = 0;
	for (int k = 0; k < Size; k++)
	{
		if (ParaList[k] == '.' || ParaList[k] == ',' || ParaList[k] == ':' || ParaList[k] == ';' || ParaList[k] == '?' || ParaList[k] == '()' || ParaList[k] == '[]' || ParaList[k] == '""' || ParaList[k] == '-' || ParaList[k] == '/' || ParaList[k] == '*')
		{
			PunctionCharacterList++;
		}
	}
	return PunctionCharacterList;
}
void Paragraph::TotalPara(char Num)
{
	regrow(ParaList, Size);
	ParaList[Size - 1] = Num;
}
ostream & operator << (ostream & out, const Paragraph & OBJ) 
{
	ofstream write;
	write.open("Output.txt");
	char *Para = OBJ.Get_ParaLIST();
	int Size = OBJ.Get_Size();
	for (int i = 0; i <Size; i++)
	{
		write << Para[i];
		out << Para[i];
	}
	return out;
	write.close();
}
void operator >> (ifstream & read, Paragraph & OBJ)
{
	char A;
	int para = 0;
	while (read.get(A))
	{
			//cout << A;
			OBJ.TotalPara(A);
		
	}
	read.close();
}
void  Paragraph::countSentenceOfPara()
{
	Sentence OBJ;
	ifstream read;
	read.open("Frequency.txt");                    //......................
	char A;
	int CountSentence = 0;
	while (read.get(A))
	{
		if (A == '.')
		{
			CountSentence++;
		}
	}
	OBJ.AddSentence(CountSentence);
	OBJ.Display();
}
void Paragraph::Dsiplay()
{
	cout <<endl;
	for (int i = 0; i < ParaSize; i++)
	{
		cout << "Paragraph number: " << ParagraphNNO[i];
	}
}
void Paragraph::countParagraph(int num)
{
	regrow(ParagraphNNO, ParaSize);
	ParagraphNNO[ParaSize - 1] = num;
}

void Paragraph::countWordOFSentence()
{
	Word OBJ;
	ifstream read;
	read.open("Frequency.txt");
	char A;
	int totalWord = 0;
	while (read.get(A))
	{
		if (A == ' ' || A == '.')
		{
			totalWord++;
		}
	}
	OBJ.AddWordsofTence(totalWord);
	OBJ.Display();
	read.close();
}
void Paragraph::countCharacter_OF_Word()
{
	char Charator[10];
	Character OBJ;
	ifstream read;
	read.open("Frequency.txt");
	int CharacterCounter = 0;

	while (read >> Charator)          //......................
	{
		CharacterCounter = 0;
		for (int k = 0; Charator[k] != '\0'; k++)
		{
			if (Charator[k] == '.' || Charator[k] == '\n')
			{
				continue;
			}
			CharacterCounter++;
		}
		OBJ.AddWord_OF_Character(CharacterCounter);
	}
	OBJ.display();
	read.close();
}
char * Paragraph::Get_ParaLIST()const
{
	char *Temp = nullptr;
	DeepCopy(Temp, ParaList, Size);
	return Temp;
}
int Paragraph::Get_Size()const
{
	return Size;
}

void DeepCopy(char *&Temp, char* ParaList, int Size)
{
	Temp = new char[Size];
	for (int i = 0; i < Size; i++)
	{
		Temp[i] = ParaList[i];
	}
}
void regrow(int *&arr, int &size)
{
	int *temp = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	delete[] arr;
	size = size + 1;
	arr = 0;
	arr = temp;
}
void regrow(char *&arr, int &size)
{
	char *temp = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	delete[] arr;
	size = size + 1;
	arr = 0;
	arr = temp;
}
Paragraph::~Paragraph()
{
	delete[]ParaList;
	Size = 0;
}