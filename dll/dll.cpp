//
//  dll.cpp
//  dll
//
//  Created by igor on 30.01.2024.
//

#include "dll.hpp"
#include <iostream>

/* NODE CONSTRUCTORS */

Node::Node():
  data(0),
  next(nullptr),
  prev(nullptr)
{}

Node::Node(int data):
  data(data),
  next(nullptr),
  prev(nullptr)
{}



/* LIST CONSTRUCTORS */

DoublyLinkedList::DoublyLinkedList():
  head(nullptr),
  tail(nullptr),
  current(nullptr),
  forward(true)
{}


/* Конструктор копирования */
DoublyLinkedList::DoublyLinkedList(DoublyLinkedList const &origin)
{
  forward = origin.forward;
  if (origin.head != nullptr) {
    Node *source = origin.head;
    Node *copy = new Node(source->data);
    Node *current = copy;
    head = copy;
    while(source->next != nullptr) {
      source = source->next;
      copy = new Node(source->data);
      copy->prev = current;
      current->next = copy;
      current = copy;
      tail = current;
    }
  }
  length = origin.length;
}

DoublyLinkedList::~DoublyLinkedList()
{
  clear();
};



/* LIST PUBLIC */

/* Установить значение по индексу */
void DoublyLinkedList::setValue(const int index, int data)
{
  setCurrentIndex(index);
  syncCurrent();
  current->data = data;
};

/* Добавление элемента в начало (конец) списка */
void DoublyLinkedList::append(int data)
{
  if (head == nullptr) {
    current = new Node(data);
    tail = current;
    head = current;
  } else {
    moveEnd();
    Node *newNode = new Node(data);
    if (forward) {
      current->next = newNode;
      newNode->prev = current;
      tail = newNode;
    } else {
      current->prev = newNode;
      newNode->next = current;
      head = newNode;
    }
  }
  length++;
};

/* Вставка элемента по номеру */
void DoublyLinkedList::insert(const int index, int data)
{
  if (index == 0) {
    /* первый элемент - переиспользуем append */
    if (head == nullptr) {
      return append(data);
    }
    moveBegin();
    Node *newNode = new Node(data);
    if (forward) {
      current->prev = newNode;
      head = current->prev;
    } else {
      current->next = newNode;
      tail = current->next;
    }
  } else {
    setCurrentIndex(index-1); // предыдущий
    syncCurrent();
    Node *newNode = new Node(data);
    if (forward) {
      newNode->prev = current;
      newNode->next = current->next;
      current->next = newNode;
    } else {
      newNode->prev = current->prev;
      newNode->next = current;
      current->prev = newNode;
    }
  }
  length++;
};

/* Удаление элемента по номеру */
void DoublyLinkedList::remove(const int index) {
  setCurrentIndex(index);
  syncCurrent();
  if (index == 0) {
    if (forward) {
      Node *next = current->next;
      delete head;
      head = next;
    } else {
      Node *prev = current->prev;
      delete tail;
      tail = prev;
    }
  } else {
    if (current->prev != nullptr) {
      current->prev->next = current->next;
    }
    if (current->next != nullptr) {
      current->next->prev = current->prev;
    }
    delete current;
  }
  length--;
};

/* Очистить список */
void DoublyLinkedList::clear()
{
  Node *current = head;
  Node *next = current;
  while (current != nullptr) {
    next = current->next;
    delete current;
    current = next;
  }
  head = nullptr;
  tail = nullptr;
  length = 0;
};

/* Установить направление */
void DoublyLinkedList::setForward(bool direction)
{
  forward = direction;
};
/* Получение текущего размера */
int DoublyLinkedList::size() const
{
  return length;
};


/* LIST PRIVATE */

/* Переход к следующему */
void DoublyLinkedList::moveNext()
{
  if (current == nullptr) return;
  if (forward) {
    current = current->next;
  } else {
    current = current->prev;
  }
};
/* Переход к пердыдущему */
void DoublyLinkedList::movePrev()
{
  if (current == nullptr) return;
  if (forward) {
    current = current->prev;
  } else {
    current = current->next;
  }
};
/* Переход в начало списка */
void DoublyLinkedList::moveBegin()
{
  if (forward) {
    current = head;
  } else {
    current = tail;
  }
};
/* Переход в конец списка */
void DoublyLinkedList::moveEnd()
{
  if (forward) {
    current = tail;
  } else {
    current = head;
  }
};
/* Обновить current по индексу и направлению */
void DoublyLinkedList::setCurrentValue(const int index, int *data)
{
  if (index != currentIndex) {
    currentIndex = index;
    syncCurrent();
  }
  current->data = *data;
};
/* Устанавливает индекс current */
void DoublyLinkedList::setCurrentIndex(const int index)
{
  if (index < 0 || index >= length) {
    throw std::out_of_range("Index out of range.");
  }
  currentIndex = index;
};

void DoublyLinkedList::syncCurrent()
{
  moveBegin();
  for(int i = 0; i < currentIndex; i++) {
    moveNext();
  }
};

int DoublyLinkedList::getCurrentValue() const
{
  if (current == nullptr) return NULL;
  return current->data;
}

/* Получение значения через скобки */
int DoublyLinkedList::operator[](const int index)
{
  setCurrentIndex(index);
  syncCurrent();
  return getCurrentValue();
}

/* Печать списка */
std::ostream &operator<<(std::ostream &os, DoublyLinkedList &list)
{
  list.moveBegin();

  while (list.current != nullptr)
  {
    os << list.getCurrentValue();
    list.moveNext();
    if (list.current != nullptr) {
      os << ", ";
    }
  }

  return os;
}
