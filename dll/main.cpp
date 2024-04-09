//
//  main.cpp
//  dll
//
//  Created by igor on 30.01.2024.
//

#include <iostream>
#include "dll.hpp"

int main(int argc, const char * argv[])
{
  DoublyLinkedList origin = DoublyLinkedList();
  
  for (int i = 0; i < 10; i++) {
    origin.append(i);
  }
  
  std::cout << "Оригинальный список: " << origin << std::endl;
  
  DoublyLinkedList *copy = new DoublyLinkedList(origin);
  std::cout << "Копия списка: " << *copy << std::endl;
  
  copy->setValue(0, 11);
  std::cout << "Первый элемент равен 11 : " << *copy << std::endl;
  
  copy->insert(1, 12);
  std::cout << "Добавлен второй элемент со значением 12 : " << *copy << std::endl;
  
  copy->remove(10);
  std::cout << "Удален элемент из конца списка : " << *copy << std::endl;
  
  origin.setForward(false);
  std::cout << "Развернутый список: " << origin << std::endl;
  
  std::cout << "Второй элемент : " << origin[1] << std::endl;
  
  origin.clear();
  copy->clear();
  std::cout << "Список очищен: " << origin << std::endl;
  
  return 0;
}
