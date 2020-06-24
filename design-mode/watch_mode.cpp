#include<iostream>
#include<vector>
#include<string>

using namespace std;

// Subject: 目标
// ConcreteSubject: 具体目标
// Observer: 观察者
// ConcreteObserver: 具体观察者
// 其主要缺点在于如果一个观察目标对象有很多直接和间接的观察者的话，
// 将所有的观察者都通知到会花费很多时间，而且如果在观察者和观察目标之间有循环依赖的话，
// 观察目标会触发它们之间进行循环调用，可能导致系统崩溃。
// 观察者模式适用情况包括：一个抽象模型有两个方面，其中一个方面依赖于另一个方面；
// 一个对象的改变将导致其他一个或多个对象也发生改变，而不知道具体有多少对象将发生改变；
// 一个对象必须通知其他对象，而并不知道这些对象是谁；需要在系统中创建一个触发链。

// 优化：
// 要众多的属性发生变化时，只需要将对某个属性变化的消息发送给感兴趣的观察者，
// 思考：如何处理多个线程间的更新，及如何避免死锁的条件

//observer 观察者基类
class Observer {
public:
    Observer(){};
    virtual ~Observer(){};
    //规范接口 观察者收到状态刷新后，采取的动作
    virtual void update() = 0;
};

// Subject 被观察者（目标）基类
class Subject {
public:
    Subject(){};
    virtual ~Subject(){};

    // 当前目标的观察者列表
    void addObserver(Observer* observer);
    void deleteObserver(Observer* observer);
    
    //向观察者发送目标属性发生变化的通知
    void notifyObserver();

    // 目标的属性刷新，父类规范接口，由子类定义
    virtual int getStatus() = 0;
    virtual void setStatus(int status) = 0;

private:
    vector<Observer*> m_observer;
};

void Subject::addObserver(Observer* observer) {
    m_observer.push_back(observer);
}

void Subject::deleteObserver(Observer* observer) {
    for (vector<Observer*>::iterator iter = m_observer.begin();
        iter != m_observer.end(); iter++) {
            if (*iter == observer) {
                m_observer.erase(iter);
                return ;
            }
        }
}


void Subject::notifyObserver() {
    for (vector<Observer*>::iterator iter = m_observer.begin();
        iter != m_observer.end(); iter++) {
            (*iter)->update();
        }
}

//具体观察者
class ConcreateObserver : public Observer {
public:
    ConcreateObserver(string name, Subject* subject) : m_observerName(name), m_subject(subject) {};
    ~ConcreateObserver(){};
    void update();

private:
    string m_observerName;
    Subject* m_subject;
};

void ConcreateObserver::update() {
    cout << "update observer[" << m_observerName << "]status :" << m_subject->getStatus() << endl;
}

// 具体目标（被观察者）
class ConcreateSubject : public Subject {
public:
    ConcreateSubject(string name):m_subjectName(name) {};
    ~ConcreateSubject(){};

    void setStatus(int Status);
    int getStatus();

private:
    // 目标名称
    string m_subjectName;
    int m_status = 0;
};

void ConcreateSubject::setStatus(int status) {
    m_status = status;
    cout << "setStatus subject[" << m_subjectName << "] status: " << m_status << endl;
}

int ConcreateSubject::getStatus() {
    return m_status;
}

int main(int argc, char* argv[])
{
    //创建目标
    Subject* SubjectA = new ConcreateSubject("SubjectA");
    Subject* SubjectB = new ConcreateSubject("SubjectB");

    //创建观察者并与目标绑定
    Observer* observerA = new ConcreateObserver("ObserverA", SubjectA);
    Observer* observerB = new ConcreateObserver("ObserverB", SubjectB);

    // 观察者与目标进行绑定
    SubjectA->addObserver(observerA);
    SubjectB->addObserver(observerB);

    //修改目标状态，目标状态的改变通知观察者
    SubjectA->setStatus(1);
    SubjectA->notifyObserver();

    SubjectB->setStatus(2);
    SubjectB->notifyObserver();

    cout << "************************" <<endl;

    //在目标上新增观察者
    SubjectA->addObserver(observerB);
    SubjectA->setStatus(2);
    SubjectA->notifyObserver();

    delete SubjectA;
    delete SubjectB;
    delete observerA;
    delete observerB;

    return 0;
}