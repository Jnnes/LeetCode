/*
 ****   �㷨�����������
 ****   main()����������Solution��run����
 ****   ʵ�ֲ�ͬ���㷨��������봴������̳��Ը���
 ****   ͬʱ����run�ӿڣ���run��ִ�в��Դ��룬��������ʵ���㷨
*/

#pragma once
class BaseSolution {
public:
    BaseSolution() {};
    ~BaseSolution(){};

    virtual void execute(void) final; // ��ֹ��������
    virtual void execute(std::string) final; // ��ֹ��������

    virtual void init(void);
    virtual void run(void);
    virtual void run(std::string);
    virtual void result(void);

    virtual std::string getTAG();

    void setParam(std::string);

    std::string sParam;

private:
    std::string TAG = "BaseSolution";
};


void BaseSolution::setParam(std::string str) {
    this->sParam = str;
}

std::string BaseSolution::getTAG() {
    return TAG;
}

void BaseSolution::init(void) {
    std::cout << "BaseSolution: no init" << std::endl;
}

void BaseSolution::run(void) {
    std::cout << "��ERROR�� can not use BaseSolution::run" << std::endl;
}

void BaseSolution::run(std::string) {
    std::cout << "��ERROR�� can not use BaseSolution::run" << std::endl;
}

void BaseSolution::result(void) {
    std::cout << "BaseSolution: no result" << std::endl;
}

void BaseSolution::execute(void) {
    std::cout << std::endl << " ---------------- ��ʼ������ ---------------- " << std::endl;
    this->init();

    std::cout << std::endl << " ---------------- ��ʼִ������ ---------------- " << std::endl;
    
    if (this->sParam.length() != 0)
        this->run(this->sParam);
    else
        this->run();
    
    std::cout << std::endl << " ----------------   ��ӡ���   ---------------- " << std::endl;
    this->result();

    std::cout << std::endl << " ----------------   ִ�н���  ---------------- " << std::endl << std::endl;
}

void BaseSolution::execute(std::string str) {
    std::cout << std::endl << " ---------------- ��ʼ������ ---------------- " << std::endl;
    this->init();

    std::cout << std::endl << " ---------------- ��ʼִ������ ---------------- " << std::endl;
    this->run(str);

    std::cout << std::endl << " ----------------   ��ӡ���   ---------------- " << std::endl;
    this->result();

    std::cout << std::endl << " ----------------   ִ�н���  ---------------- " << std::endl << std::endl;
}