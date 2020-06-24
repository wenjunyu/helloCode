#include<cstddef>
#include<iostream>
// 工厂模式  创建并返回一个新对象的方法，
// 基类定义方法，方法可在子类中重写，由子类决定如何创建一个对象
// 工厂是一个可以创建其他对象的对象，抽象工厂模式将工厂的实现与使用该工厂的代码分开
// 参考连接： https://blog.csdn.net/u010993820/article/details/80968933
using namespace std;

/*
enum Direction {North, South, East, West};


// 迷宫组件的公共抽象类
class MapSite {
    public:
        virtual void Enter() = 0;
};

// 房间的类
class Room : public MapSite {
public:
    Room(int roomNo);

    MapSite * GetSide(Direction) const;
    void SetSide(Direction, MapSite*);

    virtual void Enter();

private:
    MapSite* _sides[4];
    int _roomNumber;
};

// 墙的类
class Wall : public MapSite {
public:
    Wall();

    virtual void Enter();

};

// 门的类
class Door : public MapSite {
private:
    Room* _room1;
    Room* _room2;
    bool _isOpen;
public:
    Door(Room* = 0, Room* =  0);

    virtual void Enter();

    Room* OtherSideFrom(Room *);

};

// 房间集合的类
class Maze
{
public:
    Maze();
    
    void AddRoom(Room *);
    Room* RoomNo(int) const ;
};

// 定义一个创建产品对象的工厂接口，将产品对象的实际创建工作推迟到具体子工厂类当中。
// 这满足创建型模式中所要求的“创建与使用相分离”的特点
class MazeFactory{
public:
    MazeFactory();

    virtual Maze* MakeMaze() const
        { return new Maze;}
    virtual Wall* MakeWall() const
        { return new Wall;}
    virtual Room* MakeRoom() const
        { return new Room(n);}
    virtual Door* MakeDoor(Room* r1, Room* r2) const
        { return new Door(r1, r2);}
};


// 创建迷宫的类
class MazeGame: public Maze
{
public:
    MazeGame();
    Maze* CreateMaze();
    Maze* CreateMaze(MazeFactory& factory)
};

Maze* MazeGame::CreateMaze()
{
    Maze* aMaze = new Maze();
    Room* r1 = new Room(1);
    Room* r2 = new Room(2);
    Door* theDoor = new Door(r1, r2);

    aMaze->AddRoom(r1);
    aMaze->AddRoom(r2);

    r1->SetSide(North, new Wall);
    r1->SetSide(East, theDoor);
    r1->SetSide(South, new Wall);
    r1->SetSide(West, new Wall);

    r2->SetSide(North, new Wall);
    r2->SetSide(East, new Wall);
    r2->SetSide(South, new Wall);
    r2->SetSide(West, theDoor);

    return aMaze;
}

Maze* MazeGame::CreateMaze(MazeFactory& factory) {
    Maze* aMaze = factory.MakeMaze();
    Room* r1 = factory.MakeRoom(r1);
    Room* r2 = factory.MakeRoom(r2);
    Door* aDoor = factory.MakeDoor(r1, r2);

    aMaze->AddRoom(r1);
    aMaze->AddRoom(r2);

    r1->SetSide(North, factory.MakeWall());
    r1->SetSide(East, aDoor);
    r1->SetSide(South, factory.MakeWall());
    r1->SetSide(West, factory.MakeWall());

    r2->SetSide(North, factory.MakeWall());
    r2->SetSide(East, factory.MakeWall());
    r2->SetSide(South, factory.MakeWall());
    r2->SetSide(West, aDoor);

    return aMaze;
}

*/
typedef enum ProductTypeTag
{
    TypeA,
    TypeB,
    TypeC
}PRODUCTTYPE;

// 基类
/*
class Product{
public:
    virtual void Show() = 0;
};

// ABC 三个组件
class ProductA : public Product{
public:
    void Show() {
        cout << "I`m Produce A" << endl;
    }
};

class ProductB : public Product{
public:
    void Show() {
        cout << "I`m Produce B" << endl;
    }
};

class ProductC : public Product{
public:
    void Show() {
        cout << "I`m Produce C" << endl;
    }
};
*/
// 简单工厂类
// 简单工厂是工厂模式最简单的一种实现，对于不同产品的创建定义一个工厂类，
// 将产品的类型作为参数传入到工厂的创建函数，
// 根据类型分支选择不同的产品构造函数。
// 简单工厂模式只是一个简单的对创建过程封装
/*
class Factory{
public:
    Product * CreateProduct(PRODUCTTYPE type){
        switch(type)
        {
            case TypeA:
            {
                return new ProductA();
            }
            case TypeB:
            {
                return new ProductB();
            }
            case TypeC:
            {
                return new ProductC();
            }
            default:
                return NULL;
        }
    }
};


// 简单工厂类
int main()
{
    // 可以将子类赋值给父类，但反过来赋值则不行
    Factory productCreator;
    Product* ProductA = productCreator.CreateProduct(TypeA);
    Product* ProductB = productCreator.CreateProduct(TypeB);
    Product* ProductC = productCreator.CreateProduct(TypeC);

    ProductA->Show();
    ProductB->Show();
    ProductC->Show();

    if (ProductA) {
        delete ProductA;
        ProductA = NULL;
    }

    if (ProductB) {
        delete ProductB;
        ProductB = NULL;
    }

    if (ProductC) {
        delete ProductC;
        ProductC = NULL;
    }

    return 0;
}

*/

// 工厂方法模式在简单工厂模式的基础上增加对工厂的基类抽象，
// 不同的产品创建采用不同的工厂创建（从工厂的抽象基类派生），
// 这样创建不同的产品过程就由不同的工厂分工解决
// 相对于简单工厂模式的优势在于：便于后期产品种类的扩展。
/*
class Factory {
public:
    virtual Product* CreateProduct() = 0;
};

class FactoryA : public Factory {
public:
    Product* CreateProduct() {
        return new ProductA();
    }
};

class FactoryB : public Factory {
public:
    Product* CreateProduct() {
        return new ProductB();
    }
};

class FactoryC : public Factory {
public:
    Product* CreateProduct() {
        return new ProductC();
    }
};

int main()
{
    Factory* factoryA = new FactoryA();
    Factory* factoryB = new FactoryB();
    Factory* factoryC = new FactoryC();

    Product* productA = factoryA->CreateProduct();
    Product* productB = factoryB->CreateProduct();
    Product* productC = factoryC->CreateProduct();

    productA->Show();
    productB->Show();
    productC->Show();


    if (factoryA)
    {
        delete factoryA;
        factoryA = NULL;
    }

    if (factoryB)
    {
        delete factoryB;
        factoryB = NULL;
    }

    if (productA)
    {
        delete productA;
        productA = NULL;
    }

    if (productB)
    {
        delete productB;
        productB = NULL;
    }

    return 0;
}

*/
// 抽象工厂模式
// 抽象工厂模式对工厂方法模式进行了更加一般化的描述。
// 工厂方法模式适用于产品种类结构单一的场合，为一类产品提供创建的接口；
// 而抽象工厂方法适用于产品种类结构多的场合，就是当具有多个抽象产品类型时，
// 抽象工厂便可以派上用场。
// 抽象工厂模式更适合实际情况，受生产线所限，让低端工厂生产不同种类的低端产品，
// 高端工厂生产不同种类的高端产品。
class ProductA {
public:
    virtual void Show() = 0;
};

//A类低端产品
class ProductA1 : public ProductA {
public:
    void Show(){
        cout << "I`m ProductA1" << endl;
    }
};

//A类高端产品
class ProductA2 : public ProductA {
public:
    void Show(){
        cout << "I`m ProductA2" << endl;
    }
};

class ProductB {
public:
    virtual void Show() = 0;
};

//B类低端产品
class ProductB1 : public ProductB {
public:
    void Show(){
        cout << "I`m ProductB1" << endl;
    }
};

//B类高端产品
class ProductB2 : public ProductB {
public:
    void Show(){
        cout << "I`m ProductB2" << endl;
    }
};

class Factory {
public:
    virtual ProductA* CreateProductA() = 0;
    virtual ProductB* CreateProductB() = 0;
};

//1号工厂用于生产低端产品
class Factory1 : public Factory {
public:
    ProductA* CreateProductA() {
        return new ProductA1();
    }
    ProductB* CreateProductB() {
        return new ProductB1();
    }
};

//2号工厂用于生产高端产品
class Factory2 : public Factory {
public:
    ProductA* CreateProductA() {
        return new ProductA2();
    }
    ProductB* CreateProductB() {
        return new ProductB2();
    }
};

int main()
{
    Factory* factory1 = new Factory1();
    ProductA* productA1 = factory1->CreateProductA();
    ProductB* productB1 = factory1->CreateProductB();

    productA1->Show();
    productB1->Show();

    Factory* factory2 = new Factory2();
    ProductA* productA2 = factory2->CreateProductA();
    ProductB* productB2 = factory2->CreateProductB();
    productA2->Show();
    productB2->Show();
    return 0;
}




