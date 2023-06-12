#include "Paragraph.h"
#include "Character.h";
#include "Hofman.h"
int main()
{
	Paragraph OBJ;
	ifstream read;
	read.open("Frequency.txt");
	//................................1 and 2 Fun ...............................
	read >> OBJ; // read Data Done 1
	cout << OBJ; // Write and Display Done 2 and 3
	
	cout << endl;

	//..............................4 
	Paragraph OBJEqual;
	ifstream readEqual;
	readEqual.open("Equal.txt");

	readEqual >> OBJEqual;
	cout << OBJ;

	cout << endl;
	cout << endl;

	// == Overload is Done 4
	if (OBJ == OBJEqual)
	{
		cout << "Both ParaGraph are Equals!" << endl;
	}
	else
	{
		cout << "Both ParaGraph are not Equals!" << endl;
	}
	cout << endl;


	// .....................UpperCase 5............................

	OBJ = OBJ + 32;

	cout << OBJ;
	
	cout << endl << endl;

	OBJ = OBJ - 32;
	cout << OBJ;

	// ..............Punction Character Done 6.....................
	cout << endl;
	cout << "There are " << OBJ.CountPunction() << " Type of English and Punctuation Character!\n";
	cout << endl;


	// ..................ParaGraph Sentence Word Character Counter 7 8 9..................
	OBJ.TotalNumberOfParagraph();
	OBJ.Dsiplay();
	OBJ.countSentenceOfPara();
	OBJ.countWordOFSentence();
	OBJ.countCharacter_OF_Word();

	cout << endl;
	//.....................Encrypt and Decrypt 10.....................

	cout << "Encrytion!\n";
	OBJ = OBJ % 2;
	cout << OBJ;

	cout << endl;

	cout << "Decryption!\n";
	OBJ = OBJ * 2;
	cout << OBJ;

	cout << endl << endl;

	//......................SpellCheck 11......................
	int Word_to_Be_Correction = OBJ.SpellCheck();
	cout << "There are " << Word_to_Be_Correction << " numbers of Word need to be correct!";

	cout << endl << endl;


	////..................................Data Copy in One File 12.........................
	Paragraph intoOne;
	intoOne = OBJ + OBJEqual;
	cout << intoOne;


	//....................................Hofman Coding....................................

	char arr[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	int freq[] = { 5, 1, 6, 3, 5, 1, 6, 3, 5, 1, 6, 3, 5, 1, 6, 3, 5, 1, 6, 3, 5, 1, 6, 3, 5, 1, 6, 3 };

	int size = sizeof(arr) / sizeof(arr[0]);

	cout << "Char | Huffman code ";
	cout << "\n----------------------\n";
	HuffmanCodes(arr, freq, size);

	return 0;
}

