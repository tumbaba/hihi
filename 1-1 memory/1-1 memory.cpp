﻿// 01-01.Memory.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
// 프로젝트 속성 -> C/C++ -> 일반 -> 추가 포함 디렉터리
// -> $(ProjectDir)Function
#include "Function.h"

// 전역 변수(Data 영역)
int GInt = 1234;

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    //_CrtSetBreakAlloc(193);

    // Stack memory
    {
        // Stack                                // Heap
        // [4Byte]i1{1}
        // [4Byte]i2{2}
        // [4Byte]i3{3}
        int i1{ 1 };
        int i2{ 2 };
        int i3{ 3 };

        i1 = 10;
    }
    // Pointer, 동적할당
    {
        // 64bit 기준으로 포인터는 8바이트고
        // 8바이트인 이유는 64bit 주소를 모두 표기하기 위해서는
        // 2의64승 값이 필요하다

        // Stack                                // Heap
        // [8Byte]Pointer{nullptr(0)}
        int* Pointer{ nullptr };

        // Stack                                // Heap
        // [8Byte]Pointer{0xHeapAddress} ------> [4byte]*Pointer{444}
        Pointer = new int{ 444 };

        // Stack                                // Heap
        // [8Byte]Pointer{0xHeapAddress} ------> [4byte]*Pointer{555}
        *Pointer = 555;
        *(char*)Pointer = 10;

        std::cout << Pointer << std::endl;
        delete Pointer;
        std::cout << Pointer << std::endl;
        Pointer = nullptr;
        std::cout << Pointer << std::endl;
    }
    // Pointer, 지역 변수
    {
        // Stack                                // Heap
        // [2Byte]A{0} <--------------------┐
        // [6Byte]Padding                   │
        // [8Byte]Pointer{0xVar A Address} -┘
        short A = 0;
        short* Pointer = &A;
        // Stack                                // Heap
        // [2Byte]A{234} <------------------┐
        // [6Byte]Padding                   │
        // [8Byte]Pointer{0xVar A Address} -┘
        *Pointer = 234;
    }
    // Pointer, 전역 변수
    {
        // Stack                                // Data
        // [8Byte]Pointer{0xDataAddress} ---->  [4Byte]GInt{1234}
        int* Pointer = &GInt;
        *Pointer = 231;
    }
    // Double Pointer, 동적 할당
    {
        // Stack                                // Heap
        // [8Byte]Pointer{nullptr(0)}
        int** DoublePointer{ nullptr };

        // Stack                                // Heap
        // [8Byte]Pointer{0xHeapAddress} -----> [8Byte]*DoublePointer{trash(0xcdcdcdcdcdcdcdcd)}
        DoublePointer = new int*;

        // Stack                                // Heap
        // [8Byte]Pointer{0xHeapAddress} -----> [8Byte]*DoublePointer{0xHeapAddress}
        //                                          ∇
        //                                      [4Byte]**DoublePointer{10}
        *DoublePointer = new int{ 10 };

        **DoublePointer = 1234;

        // Stack                                // Heap
        // [8Byte]Pointer{0xHeapAddress} -----> [8Byte]*DoublePointer{0xHeapAddress}
        //                                          ∇
        //                                      delete ! [4Byte]**DoublePointer{10}
        delete* DoublePointer;
        *DoublePointer = nullptr;

        // Stack                                // Heap
        // [8Byte]Pointer{0xHeapAddress} -----> delete ! [8Byte]*DoublePointer{0xHeapAddress}
        delete DoublePointer;
        DoublePointer = nullptr;
    }
    // Double Pointer tip(COM; Component Object Model 공부 해보시면 도움이 됩니다)
    {
        int* Pointer = nullptr;
        /*int* InPointer = Pointer;
        int* InPointer = nullptr;
        InPointer = new int;*/
        //AllocateWrong(Pointer);
        AllocateCorrect(&Pointer);
        int* Pointer2 = nullptr;
        AllocateCorrect2(Pointer2);
        //Deallocate(Pointer);
        Deallocate2(&Pointer);
        Deallocate2(&Pointer2);
        //delete Pointer;
    }
}
