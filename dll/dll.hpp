//
//  dll.hpp
//  dll
//
//  Created by igor on 30.01.2024.
//

#ifndef dll_hpp
#define dll_hpp

#include <stdio.h>
#include <iostream>

#endif /* dll_hpp */

/* NODE */

class Node {
  int data;
  Node *next;
  Node *prev;
  
public:
  Node();
  Node(int);
  ~Node() = default;
  friend class DoublyLinkedList;
};


class DoublyLinkedList {
  
  
public:
  DoublyLinkedList();
  DoublyLinkedList(DoublyLinkedList const &);
  ~DoublyLinkedList();
  
  /* Установить значение по индексу */
  void setValue(const int, int);
  /* Добавление элемента в начало (конец) списка */
  void append(int);
  /* Добавление элемента по номеру */
  void insert(const int, int);
  /* Удаление элемента по номеру */
  void remove(const int);
  /* Очистить список */
  void clear();
  /* Установить направление */
  void setForward(bool);
  /* Получение текущего размера */
  int size() const;
  /* Получение элемента по индексу */
  int operator[](const int);
  /* Печать содержимого */
  friend std::ostream &operator<<(std::ostream &, DoublyLinkedList &);
  
private:
  Node *head;
  Node *tail;
  Node *current;
  bool forward;
  int currentIndex;
  int length;
  /* Переход к следующему */
  void moveNext();
  /* Переход к пердыдущему */
  void movePrev();
  /* Переход в начало списка */
  void moveBegin();
  /* Переход в конец списка */
  void moveEnd();
  /* Обновить current по индексу и направлению */
  void syncCurrent();
  /* Устанавливает индекс current */
  void setCurrentIndex(const int);
  /* Устанавливает значение current по индексу */
  void setCurrentValue(const int, int *);
  /* Получает значение current */
  int getCurrentValue() const;
};
