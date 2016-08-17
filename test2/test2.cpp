// test2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <malloc.h>
#include <Windows.h>

class T
{
public:
    T()
        :a(100)
    {
        printf("a=%d\n", a);
    }

    ~T()
    {

    }

private:
    int a;
};

T t;

#include <string>

int CalcStringLength(const std::wstring& str)
{
    const wchar_t *p = str.c_str();
    if (!p)
        return 0;

    int len = 0;
    while (*p)
    {
        if (*p > 255)
            len++;

        p++;
        len++;
    }

    return (len >> 1);
}

int _tmain(int argc, _TCHAR* argv[])
{
    //void *p = malloc(121);

    const char *data = "1零一1二三1四五1六七1八九1";
    int len = lstrlenA(data);

    std::string s(data);
    auto len1 = s.length();

    // 13, 16
    const wchar_t *data2 = L"1零一1二三1四五1六七1八九1";
    int l = lstrlenW(data2);

    std::wstring s2(data2);
    auto ll = s2.length();
    auto l2 = CalcStringLength(s2);
    const wchar_t *p = data2;
    int lenlen = 0;
    while (*p)
    {
        
        auto j = *p;

        if (j > 255)
            lenlen++;

        p++;
        lenlen++;
    }

    lenlen /= 2;

    //free(p);
  //  VirtualFree(p, 0, MEM_RELEASE);
  //  ::HeapFree((HANDLE)1, 0, p);
	return 0;
}

