// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 TESTDLL_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// TESTDLL_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef TESTDLL_EXPORTS
#define TESTDLL_API __declspec(dllexport)
#else
#define TESTDLL_API __declspec(dllimport)
#endif

// 此类是从 dll 导出的
class TESTDLL_API CTestDLL {
public:
	CTestDLL(void);
	// TODO: 在此处添加方法。
};

extern TESTDLL_API int nTestDLL;

TESTDLL_API int fnTestDLL(void);


// 声明
/*
当C++代码包含C函数或C库的头文件时，由于C++和C语言在函数名称的处理方式上有所不同，C++编译器会将这些C函数或库中的函数名称按照C++的方式进行重整，这会导致函数名称被修改并在链接时找不到函数。
通过在C++代码中使用extern "C"说明符来修饰C函数，可以告诉C++编译器对函数名进行C语言风格的链接，从而避免函数名被重整导致链接错误。

*/
extern "C" TESTDLL_API int add(int a, int b);
extern "C" TESTDLL_API void openBrowser(char* str);