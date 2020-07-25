#ifndef PCH_H
#define PCH_H

// TODO: 여기에 미리 컴파일하려는 헤더 추가
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define FILENAMESIZE 1024
#define ADDSIZE 3
#define MAXQUEUE 31
#define MAXSTACK 30

// Type
#include "ItemType.h"
#include "PlayItemType.h"

// List
#include "UnsortedList.h"
#include "SortedList.h"
#include "CircularQueue.h"
#include "Stack.h"

// App
#include "Application.h"

#endif //PCH_H
