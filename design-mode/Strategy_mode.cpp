// 策略模式
// 策略模式与工厂模式的区别： https://blog.csdn.net/lmx125254/article/details/86625960
// 总结下。 工厂模式中只管生产实例，具体怎么使用工厂实例由调用方决定，
// 策略模式是将生成实例的使用策略放在策略类中配置后才提供调用方使用。 
// 工厂模式调用方可以直接调用工厂实例的方法属性等，
// 策略模式不能直接调用实例的方法属性，需要在策略类中封装策略后调用。
// /////******
// 我的理解是工厂模式就是成产对像，至于你要用这个对象做哪些行为他不管。 
// 策略模式是把对象和对象的方法封装了起来，按照逻辑实现一种行为。
// 所以如果有多种逻辑就会有多个策略类
// 工厂模式关注实例，策略模式关注方法

#include<iostream>
using namespace std;
#define free_ptr(p) \
        if (p) { delete p; p = NULL; }

class IWind {
public:
    virtual ~IWind(){};
    virtual void blowWind() = 0;
};

class ColdWind : public IWind {
public:
    void blowWind() {
            cout << "BlowWing Cold Wind!" << endl;
    }
};

class WarmWind : public IWind {
public:
    void blowWind() {
            cout << "BlowWing Warm Wind!" << endl;
    }
};

class NoWind : public IWind {
public:
    void blowWind() {
            cout << "No Wind!" << endl;
    }
};

class WindMode {
public:
    WindMode(IWind* wind): m_wind(wind){};//成员列表初始化
    ~WindMode(){free_ptr(m_wind);}
    void blowWind(){
            m_wind->blowWind();
    };
private:
    IWind* m_wind;
};

int main()
{
    WindMode* warmWind = new WindMode(new WarmWind());
    WindMode* coldWind = new WindMode(new ColdWind());
    WindMode* noWind = new WindMode(new NoWind());

    warmWind->blowWind();
    coldWind->blowWind();
    noWind->blowWind();

    free_ptr(warmWind);
    free_ptr(coldWind);
    free_ptr(noWind);


    return 0;
}

        