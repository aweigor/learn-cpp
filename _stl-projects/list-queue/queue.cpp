#include <iostream>
#include <list>
#include <deque>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::list;


// приоритет очереди
typedef enum {
    LOW,
    NORMAL,
    HIGH
} ElementPriority;

typedef struct {
    string name;
} QueueElement;

typedef struct {
    QueueElement element;
    ElementPriority priority;
} QueueItem;

class QueueWithPriority {
public:
    QueueWithPriority();
    ~QueueWithPriority();
    void PutElementToQueue(const QueueElement& element, ElementPriority priority);
    QueueElement GetElementFromQueue();
    void Accelerate();

private:
    list<QueueItem> lowPriorityList;
    list<QueueItem> normalPriorityList;
    list<QueueItem> highPriorityList;
};

QueueWithPriority::QueueWithPriority() {}

QueueWithPriority::~QueueWithPriority() {}

// Размещает элемент в очереди согласно приоритету
void QueueWithPriority::PutElementToQueue(const QueueElement& element, ElementPriority priority) 
{
    QueueItem item;
    item.element = element;
    item.priority = priority;

    switch (priority) {
        case LOW:
            lowPriorityList.push_back(item);
            break;
        case NORMAL:
            normalPriorityList.push_back(item);
            break;
        case HIGH:
            highPriorityList.push_back(item);
            break;
        default:
            cout << "Приоритет не определен" << endl;
    }
}

// Извлекает элемент из очереди
QueueElement QueueWithPriority::GetElementFromQueue() 
{
    if (!highPriorityList.empty()) {
        QueueElement extractedElement = highPriorityList.front().element;
        highPriorityList.pop_front();
        return extractedElement;
    } else if (!normalPriorityList.empty()) {
        QueueElement extractedElement = normalPriorityList.front().element;
        normalPriorityList.pop_front();
        return extractedElement;
    } else if (!lowPriorityList.empty()) {
        QueueElement extractedElement = lowPriorityList.front().element;
        lowPriorityList.pop_front();
        return extractedElement;
    } else {
        cout << "Нет элементов в очереди" << endl;
        return QueueElement(); // пустой элемент
    }
}

bool CompareQueueElement(QueueItem item1, QueueItem item2) {
    return true;
}

void QueueWithPriority::Accelerate() 
{
    highPriorityList.merge(lowPriorityList, CompareQueueElement);
    lowPriorityList.clear();
}

int main() 
{
    QueueWithPriority queue;

    QueueElement element1 = {"Element 1"};
    QueueElement element2 = {"Element 2"};
    QueueElement element3 = {"Element 3"};

    queue.PutElementToQueue(element1, HIGH);
    queue.PutElementToQueue(element2, NORMAL);
    queue.PutElementToQueue(element3, LOW);

    QueueElement extractedElement;

    extractedElement = queue.GetElementFromQueue();
    cout << "Получен элемент очереди: " << extractedElement.name << endl;

    //queue.Accelerate();

    extractedElement = queue.GetElementFromQueue();
    cout << "Получен элемент очереди: " << extractedElement.name << endl;

    return 0;
}