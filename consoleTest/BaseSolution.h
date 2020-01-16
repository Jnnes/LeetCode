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

    virtual void init(void);
    virtual void run(void);
    virtual void result(void);
    
};

void BaseSolution::init(void) {
    std::cout << "BaseSolution: no init" << std::endl;
}

void BaseSolution::run(void) {
    std::cout << "��ERROR�� can not use BaseSolution::run" << std::endl;
}

void BaseSolution::result(void) {
    std::cout << "BaseSolution: no result" << std::endl;
}

void BaseSolution::execute(void) {
    std::cout << std::endl << " ---------------- ��ʼ������ ---------------- " << std::endl;
    init();

    std::cout << std::endl << " ---------------- ��ʼִ������ ---------------- " << std::endl;
    run();
    
    std::cout << std::endl << " ----------------   ��ӡ���   ---------------- " << std::endl;
    result();

    std::cout << std::endl << " ----------------   ִ�н���  ---------------- " << std::endl << std::endl;
}