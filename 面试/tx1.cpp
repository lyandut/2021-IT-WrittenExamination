#include <iostream>
#include <cstring>
using namespace std;

void test1() {
    char* a[] = {"hello", "the", "world"};
    char** pa = a;
    pa++;
    cout << *pa << endl; // the
}

void GetMemory(char* p) {  // 报错Segmentation fault, 改为引用传参: char*& p
    p = (char*) malloc(100);
}

void test2() {
    char *str=NULL;
    GetMemory(str);
    strcpy(str, "Thunder");
    strcat(str+2, "Downloader"); // +2没用，坑！
    printf(str);
}

struct _THUNDER {
    int iversion; // 4
    char cTag; // 1
    char cAdv; // 1 + 2
    int iUser; // 4
    char cEnd; // 1 + 3
} Thunder;

void test3() {
    uint64_t a = 0x1020304050607080; // 8字节, 大端序
    char* b = (char*)&a;             // 1字节, b -> 0x80
    uint16_t * c =( uint16_t*)(b+1); // 2字节, c -> 0x6070
    printf("0x%x\n", *(c+2));        // 2字节, c+2 -> 0x2030
}

int main(){
    test1();
    test2();
    cout << sizeof(Thunder) << endl;
    test3();
    return 0;
}