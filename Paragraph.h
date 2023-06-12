#pragma once
#include <iostream>
#include <fstream>
#include <ostream>
#include "Paragraph.h"
#include "Character.h"
#include "Sentence.h"
#include "Word.h"
using namespace std;
class Paragraph
{
	char *ParaList;
	int Size;
	int *ParagraphNNO;
	int ParaSize;

public:
	Paragraph();
	Paragraph(const Paragraph & OBJ);
	Paragraph &operator = (const Paragraph & OBJ);
	void TotalPara(char Num);
	void TotalNumberOfParagraph();
	//GETTERS
	char * Get_ParaLIST()const;
	int Get_Size()const;
	void countParagraph(int num);
	bool operator == (const Paragraph & OBJ);
	Paragraph  operator + (int num);
	Paragraph operator - (int num);
	int CountPunction();
	void countCharacter_OF_Word();
	void countSentenceOfPara();
	void countWordOFSentence();

	Paragraph &operator % (int num);
	Paragraph &operator * (int num);
	int SpellCheck();

	Paragraph & operator + (const Paragraph & OBJ);
	void Dsiplay();
	~Paragraph();
};
void operator>>(ifstream& read, Paragraph& OBJ);
void regrow(char *&arr, int &size);
void DeepCopy(char *&Temp, char* ParaList, int Size);
ostream & operator << (ostream & out, const Paragraph & OBJ);
void regrow(int *&arr, int &size);