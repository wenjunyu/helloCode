#include<iostream>

//Iterator模式  参考 https://blog.csdn.net/xiaoyaohuqijun/article/details/50909611
using namespace std;

class Iterater;

// 容器的抽象基类
class Aggregate {
public:
    virtual ~Aggregate(){}

    virtual Iterater* CreateIterater(Aggregate* pAggregate) = 0 ;
    virtual int GetSize() = 0;
    virtual int GetItem(int nIndex) = 0;
};

// 迭代器的抽象基类
class Iterater {
public:
    virtual ~Iterater(){}

    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() = 0;
    virtual int CurrentItem() = 0;
};

// 一个具体的容器类,这里是用数组表示
class ConcreateAggregate : public Aggregate {
public:
    ConcreateAggregate(int nSize);
    virtual ~ConcreateAggregate();

    virtual Iterater* CreateIterater(Aggregate* pAggregate);
    virtual int GetSize();
    virtual int GetItem(int nIndex);

private:
    int m_nSize;
    int* m_pData;
};

// 访问ConcreateAggregate容器类的迭代器类
class ConcreateIterater : public Iterater {
public:
    ConcreateIterater(Aggregate* pAggregate);
    virtual ~ConcreateIterater(){}

    virtual void First();
    virtual void Next();
    virtual bool IsDone();
    virtual int CurrentItem();

private:
    Aggregate* m_pConcreateAggregate;
    int        m_nIndex;
};

// 容器以数组为例
ConcreateAggregate::ConcreateAggregate(int nSize)
    :m_nSize(nSize)
    ,m_pData(NULL) 
{
    m_pData = new int[m_nSize];

    for (int i = 0; i < nSize; ++i) {
        m_pData[i] = i;
    }
}

ConcreateAggregate::~ConcreateAggregate() {
    delete [] m_pData;
    m_pData = NULL;
}

Iterater* ConcreateAggregate::CreateIterater(Aggregate *pAggregate)
{
    return new ConcreateIterater(this);
}

int ConcreateAggregate::GetSize() {
    return m_nSize;
}

int ConcreateAggregate::GetItem(int nIndex) {
    if (nIndex < m_nSize) {
        return m_pData[nIndex];
    } else {
        return -1;
    }
}

ConcreateIterater::ConcreateIterater(Aggregate* pAggregate): m_pConcreateAggregate(pAggregate), m_nIndex(0) {

}

void ConcreateIterater::First() {
    m_nIndex = 0;
}

void ConcreateIterater::Next() {
    if (m_nIndex < m_pConcreateAggregate->GetSize()) {
        ++m_nIndex;
    }
}

bool ConcreateIterater::IsDone() {
    return m_nIndex == m_pConcreateAggregate->GetSize();
}

int ConcreateIterater::CurrentItem() {
    return m_pConcreateAggregate->GetItem(m_nIndex);
}

int main()
{
    Aggregate* pAggregate = new ConcreateAggregate(4);
    Iterater* pIterater = new ConcreateIterater(pAggregate);

    for (; false == pIterater->IsDone(); pIterater->Next()) {
        cout << pIterater->CurrentItem() << endl;
    }

    return 0;
}