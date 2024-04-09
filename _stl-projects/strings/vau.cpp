#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::ostringstream;
using std::istringstream;
using std::string;
using std::vector;

// знаки пунктуации
const string PUNC = ".,!?:;";

/**
 * проверяет наличие знаков препинания в тексте
 * в случае совпадения добавляет пробел перед следующим
 * обычным символом
 * **/
string breakWords(string text) 
{	
	bool needBreakWord = false;

	for (auto i = 0; i < text.size(); i++) 
	{
		// если символ пунктуации найден,
		if (PUNC.find(text[i]) != string::npos) 
		{
			// выставим флаг необходимости пробела
			needBreakWord = true;

		} else if (needBreakWord) 
		{
			// и добавим пробел перед следующим обычным символом
			text.replace(i, 1, string(" ") + text.at(i));
			needBreakWord = false;
		}
	}

	return text;
} 

string formatText(string text) 
{
	istringstream iss(text);
	ostringstream oss;
	string word;

	while (iss >> word) 
	{
		if (word.size() > 10) 
		{
      // замена на Vau если слово больше 10 символов
      word = "Vau!!!";
    }
		oss << word <<  " ";
	}

	return oss.str();
}

// разделяет на строки по 40 символов
vector<string> splitIntoRows(string text) 
{
  vector<string> rows;
  istringstream iss(text);  
	string row, word;

  while (iss >> word) 
	{
    if (row.size() + word.size() + 1 <= 40) 
		{
      row += word + " ";
    } else 
		{
      rows.push_back(row);
      row = word + " ";
    }
  }
  rows.push_back(row); // добавить последнюю строку
  return rows;
}

int main() 
{
	// определим операцию чтения
	ifstream inputFile("vau.cpp");
	if (!inputFile) 
	{
		cerr << "Произошла ошибка при открытии файла" << endl;
		return 1;
	}

	// определим поток строковых данных
	// поместим данные в память
	ostringstream textStream;
	textStream << inputFile.rdbuf();
	string text = textStream.str();

	// отформатируем текст
	text = breakWords(text);
	text = formatText(text);

	// разделим на строки
  vector<string> rows = splitIntoRows(text);

  // печать результата, конец
  for (const string& row : rows) 
	{
    cout << row << endl;
  }

	return 0;
}