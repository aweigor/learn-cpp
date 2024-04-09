#include <iostream>
#include <list>
#include <string>

using std::cout;
using std::endl;
using std::list;
using std::string;

// Structure to represent a phonebook record
struct PhonebookRecord {
    string name;
    string phoneNumber;
};

class Phonebook {
public:
    Phonebook();

    void ShowCurrentRecord();
    void NextRecord();
    void PreviousRecord();
    void InsertRecordFront(const PhonebookRecord& record);
    void InsertRecordBack(const PhonebookRecord& record);
    void ReplaceCurrentRecord(const PhonebookRecord& record);
    void InsertRecordFrontOfList(const PhonebookRecord& record);
    void InsertRecordEndOfList(const PhonebookRecord& record);
    void WalkThroughNRecords(int n, bool forward);

private:
    list<PhonebookRecord> records;
    list<PhonebookRecord>::iterator currentRecordIterator;
};

Phonebook::Phonebook() {
    records = {
        {"Джек Ролло", "123-456-7890"},
        {"Чарли Бонс", "456-789-0123"},
        {"Дэвид Холмс", "789-012-3456"}
    };
    currentRecordIterator = records.begin();
}

void Phonebook::ShowCurrentRecord() {
    cout << "Имя: " << currentRecordIterator->name << endl;
    cout << "Номер телефона: " << currentRecordIterator->phoneNumber << endl;
}

void Phonebook::NextRecord() {
    if (next(currentRecordIterator) != records.end()) {
        ++currentRecordIterator;
    } else {
        cout << "Конец книги." << endl;
    }
}

void Phonebook::PreviousRecord() {
    if (currentRecordIterator != records.begin()) {
        --currentRecordIterator;
    } else {
        cout << "Начало книги." << endl;
    }
}

void Phonebook::InsertRecordFront(const PhonebookRecord& record) {
    records.insert(currentRecordIterator, record);
}

void Phonebook::InsertRecordBack(const PhonebookRecord& record) {
    records.insert(next(currentRecordIterator), record);
}

void Phonebook::ReplaceCurrentRecord(const PhonebookRecord& record) {
    *currentRecordIterator = record;
}

void Phonebook::InsertRecordFrontOfList(const PhonebookRecord& record) {
    records.push_front(record);
    currentRecordIterator = records.begin();
}

void Phonebook::InsertRecordEndOfList(const PhonebookRecord& record) {
    records.push_back(record);
    currentRecordIterator = prev(records.end());
}

void Phonebook::WalkThroughNRecords(int n, bool forward) 
{
    auto it = currentRecordIterator;
    for (int i = 0; i < n; ++i) {

        if (forward) {
            if (next(it) != records.end()) {
                ++it;
            } else {
                cout << "Конец книги." << endl;
                break;
            }
        } else {
            if (prev(it) != records.begin()) {
                --it;
            } else {
                cout << "Начало книги." << endl;
                break;
            }
        }
    }
    currentRecordIterator = it;
}

int main() {
    Phonebook phonebook;

    // Тесты:
    // 1. Текущая
    // 2. Следующая
    // 3. Предыдущая

    cout << "Текущая запись:" << endl;
    phonebook.ShowCurrentRecord();
    cout << endl;

    cout << "Следующая запись:" << endl;
    phonebook.NextRecord();
    phonebook.ShowCurrentRecord();
    cout << endl;

    cout << "Предыдущая запись:" << endl;
    phonebook.PreviousRecord();
    phonebook.ShowCurrentRecord();
    cout << endl;

    cout << "Вставка после просматриваемой:" << endl;
    PhonebookRecord newRecord = {"Вилли Диган", "111-222-333"};
    phonebook.InsertRecordFront(newRecord);
    phonebook.ShowCurrentRecord();
    cout << endl;

    cout << "Вставка перед текущей:" << endl;
    PhonebookRecord newRecord2 = {"Пол Джонсон", "444-555-6666"};
    phonebook.InsertRecordBack(newRecord2);
    phonebook.ShowCurrentRecord();
    cout << endl;

    cout << "Замена текущей записи:" << endl;
    PhonebookRecord newRecord3 = {"Киеран Хебден", "777-888-9999"};
    phonebook.ReplaceCurrentRecord(newRecord3);
    phonebook.ShowCurrentRecord();
    cout << endl;

    cout << "Вставка в конец списка:" << endl;
    PhonebookRecord newRecord4 = {"Мария Соммервиль", "000-111-2222"};
    phonebook.InsertRecordEndOfList(newRecord4);
    phonebook.ShowCurrentRecord();
    cout << endl;

    cout << "Назад на 2 записи:" << endl;
    phonebook.WalkThroughNRecords(2, false);
    phonebook.ShowCurrentRecord();
    cout << endl;

    return 0;
}