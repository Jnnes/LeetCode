/*
 ****   算法解决方案基类
 ****   main()会主动调用Solution的run函数
 ****   实现不同的算法解决方案请创建基类继承自该类
 ****   同时重载run接口，在run内执行测试代码，在子类中实现算法
*/

#pragma once
class BaseSolution {
public:
    BaseSolution() {};
    ~BaseSolution(){};

    virtual void execute(void) final; // 禁止子类重载

    virtual void init(void);
    virtual void run(void);
    virtual void result(void);

    virtual std::string getTAG();

private:
    std::string TAG = "BaseSolution";
};

std::string BaseSolution::getTAG() {
    return TAG;
}

void BaseSolution::init(void) {
    std::cout << "BaseSolution: no init" << std::endl;
}

void BaseSolution::run(void) {
    std::cout << "【ERROR】 can not use BaseSolution::run" << std::endl;
}

void BaseSolution::result(void) {
    std::cout << "BaseSolution: no result" << std::endl;
}

void BaseSolution::execute(void) {
    std::cout << std::endl << " ---------------- 初始化数据 ---------------- " << std::endl;
    this->init();

    std::cout << std::endl << " ---------------- 开始执行用例 ---------------- " << std::endl;
    this->run();
    
    std::cout << std::endl << " ----------------   打印结果   ---------------- " << std::endl;
    this->result();

    std::cout << std::endl << " ----------------   执行结束  ---------------- " << std::endl << std::endl;
}