//
//  main.cpp
//  char-frequency-2
//
//  Created by igor on 02.12.2023.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "utils.hpp"


const std::string RESOURCES_PATH = "/Users/igor/Projects/Xcode/poly/char-frequency-2/resources/";
/* оганичение размера строки */
const int STR_MAX_SIZE = 256;
/* максимальное количество символов результата */
const int COUNT_LIMIT = 3;
/* пространство символов ASCII */
const int ASCII_SIZE = 256;


void test(char* testString);

/* Процедура для std string */
void countLeadingEntries (const std::string & s, char* dst, const int limit);
/* Процедура для строки си */
void countLeadingEntries (const char* src, char* dst, const int limit);
/* Сбор статистики вхождений символов строке */
int countFrequency(const std::string &s, char* entries, int* frequency);
/* Сбор статистики по вхождениям символов в си строке */
int countFrequency(const char* s, char* entries, int* frequency);


void countLeadingEntries (const std::string& src, char* dst, const int limit)
{
  /* Массив входящих символов */
  char entries[ASCII_SIZE] = "";
  /* Счетчик вхождений */
  int frequency[ASCII_SIZE] = {};
  /* Вычисляем общее количество вхождений символов */
  countFrequency(src, entries, frequency);
  /* Сортируем результат по количеству вхождений */
  sortEntriesByFrequency(entries, frequency);
  
  /* запоминаем нужное количество символов результата */
  int i;
  for (i = 0; i < limit; i++) {
    dst[i] = entries[i];
  }
  dst[i] = '\0';
  
  /* Сортируем конечный результат */
  sortEntries(dst);
}

void countLeadingEntries (const char* src, char* dst, const int limit) {
  /* Массив входящих символов */
  char entries[ASCII_SIZE] = "";
  /* Счетчик вхождений */
  int frequency[ASCII_SIZE] = {};
  /* Вычисляем общее количество вхождений символов */
  countFrequency(src, entries, frequency);
  /* Сортируем результат по количеству вхождений */
  sortEntriesByFrequency(entries, frequency);
  /* запоминаем нужное количество символов результата */
  int i;
  for (i = 0; i < limit; i++) {
    dst[i] = entries[i];
  }
  dst[i] = '\0';
  
  sortEntries(dst);
}


int countFrequency(const std::string& src, char* entries, int* frequency)
{
  /* Считываем строку посимвольно, заполняем таблицу ASCII (frequency) */
  /* Количество уникальных символов результата */
  int entriesCount = 0;
  
  /* Цикл по строке */
  for (long i = 0; i < src.size(); i++)
  {
    if ( frequency[src[i]] == 0)
    {
      entries[entriesCount] = (char)src[i];
      ++entriesCount;
    }
    ++frequency[src[i]];
  }
  
  entries[entriesCount + 1] = '\0';
  
  return entriesCount;
}

int countFrequency(const char* src, char* entries, int* frequency)
{
  /* Считываем строку посимвольно, заполняем таблицу ASCII (frequency) */
  /* Количество уникальных символов результата */
  int entriesCount = 0;
  
  /* Цикл по строке */
  int i = 0;
  while(src[i])
  {
    if (frequency[(int)src[i]] == 0)
    {
      entries[entriesCount ] = (char)src[i];
      ++entriesCount;
    }
    ++frequency[(int)src[i]];
    ++i;
  }
  
  entries[entriesCount + 1] = '\0';
  
  return entriesCount;
}


void test(char* testCharString)
{
  /* Преобразуем массив символов в строку */
  std::string testString(testCharString);
  /* Массив результата для строки */
  char stringEntries[COUNT_LIMIT + 1] = "";
  /* Массив результата для строки в стиле СИ */
  char charStringEntries[COUNT_LIMIT + 1] = "";
  
  /* Вычисляем результат для строки */
  countLeadingEntries(testString, stringEntries, COUNT_LIMIT);
  /* Вычисляем результат для строки в стиле СИ */
  countLeadingEntries(testCharString, charStringEntries, COUNT_LIMIT);
  
  /* Печать протокола */
  std::cout << "Результат: " << std::endl;
  std::cout << stringEntries << std::endl;
  std::cout << charStringEntries << std::endl;
  std::cout << std::endl;
}


int main(int argc, const char * argv[])
{
  /* Поток данных файла */
  std::ifstream inputStream(RESOURCES_PATH + "data.txt");
  /* Длина строки символов (считывается из файла) */
  int length;
  
  while(true)
  {
    /* Строка символов (считывается из файла) */
    char* processString = nullptr;
    
    if (inputStream >> length)
    {
      /* Переход к следующей строке */
      inputStream.ignore();
      try {
        processString = new char[length + 1];
        /* Считываем следующее значение */
        inputStream.getline(processString, length + 1);
        /* Распечатаем считанное слово */
        std::cout << "Считано слово: " << processString << std::endl;
        /* Вычислим результат, распечатаем протокол */
        test(processString);
        /* Освободим память */
        delete [] processString;
      }
      catch(...)
      {
        delete [] processString;
      }
    }
    else
    {
      break;
    }
    /* Считаем слово */
    
  }
  
  return 0;
}
