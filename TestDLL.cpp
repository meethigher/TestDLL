// TestDLL.cpp : 定义 DLL 的导出函数。
//

#include "pch.h"
#include "framework.h"
#include "TestDLL.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
using namespace std;


// 这是导出变量的一个示例
TESTDLL_API int nTestDLL=0;

// 这是导出函数的一个示例。
TESTDLL_API int fnTestDLL(void)
{
    return 0;
}

TESTDLL_API int add(int a, int b) {
    int value = a + b;
   //c++打印
    cout << "C++打印: TestDLL add: " << value << endl;
    //c打印
    printf("C打印: TestDLL add: %d", value);
    // 线程休眠5秒
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return value;
}


TESTDLL_API void openBrowser(char* str) {
    std::string cmd = "start " + std::string(str);
    system(cmd.c_str());
}

// 这是已导出类的构造函数。
CTestDLL::CTestDLL()
{
    return;
}
