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
#define MAXSTACK 5
#define MAXCONTAINER 10

#include "Base.h"



// List
#include "CHeapBase.h"
#include "CMinHeap.h"
#include "CMaxHeap.h"

#include "UnsortedList.h"
#include "SortedList.h"
#include "CircularQueue.h"
#include "Stack.h"
#include "SingleLinkedList.h"

#include "DoublySortedLinkedList.h"




// Type
#include "ItemType.h"
#include "TempType.h"
#include "SimpleItemType.h"
#include "ContainerType.h"
#include "StorageType.h"

// App
#include "Application.h"



#endif //PCH_H
