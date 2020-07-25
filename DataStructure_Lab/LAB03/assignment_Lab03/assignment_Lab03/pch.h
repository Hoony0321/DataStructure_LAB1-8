#ifndef PCH_H
#define PCH_H

// TODO: ���⿡ �̸� �������Ϸ��� ��� �߰�
#include <iostream>
#include <fstream>
#include <string>
using namespace std;



#define LISTMAXSIZE 30
#define QUEUEMAXSIZE 16
#define STACKMAXSIZE 15
#define FILENAMESIZE 1024

//RelationType - primary key(ID) �� Ÿ��
enum RelationType { LESS, EQUAL, GREATER };

//Type
#include "ItemType.h"
#include "SimpleItemType.h"

// List
#include "SortedList.h"
#include "UnsortedList.h"
#include "Stack.h"
#include "Queue.h"



//Type
#include "TempType.h"
#include "ContainerType.h"


// App
#include "Application.h"

#endif //PCH_H

