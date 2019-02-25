// HeapExample.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>

#define HEAP_MAX 100

typedef struct Elements {
	int key;
};

typedef struct HeapInfo {
	Elements elem[HEAP_MAX];
	int size;
};

bool CheckPowerOfTwo(int nNum)
{
	int nResult = nNum & (nNum - 1);

	if (nResult == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int InsertHeap(HeapInfo *heapinfo) {
	int InsKey;
	printf("추가할 값 : ");
	scanf("%d", &InsKey);

	int index = heapinfo->size;
	if (index == 1) {
		heapinfo->elem[index].key = InsKey;
		heapinfo->size++;
		return 0;
	}
	else {
		while (InsKey >= heapinfo->elem[index / 2].key && index/2 != 0) {
			heapinfo->elem[index].key = heapinfo->elem[index / 2].key;
			index /= 2;
		}
		heapinfo->elem[index].key = InsKey;
		heapinfo->size++;
		return 0;
	}
}

int DeleteHeap(HeapInfo *heapinfo) {
	int last = heapinfo->size - 1;
	int lastkey = heapinfo->elem[last].key;
	heapinfo->elem[last].key = -100;
	int index = 1;
	while ((lastkey<heapinfo->elem[index * 2].key) || (lastkey < heapinfo->elem[(index * 2) + 1].key)) {
		if (heapinfo->elem[index * 2].key > heapinfo->elem[(index * 2) + 1].key) {
			heapinfo->elem[index].key = heapinfo->elem[index * 2].key;
			index = index * 2;
		}
		else if (heapinfo->elem[index * 2].key < heapinfo->elem[(index * 2) + 1].key) {
			heapinfo->elem[index].key = heapinfo->elem[(index * 2) + 1].key;
			index = (index * 2) + 1;
		}
	}
	heapinfo->elem[index].key = lastkey;
	heapinfo->size--;
	return 0;
}

int getlevel(int x) {
	int level = 1;
	while (x != 1) {
		x /= 2;
		level++;
	}
	return level;
}

int main()
{
	HeapInfo heapinfo;
	int inputtype, rtn;
	heapinfo.size = 1;

	while (1) {
		printf("0. 종료    1. 추가    2. 삭제    3. 보기\n");
		scanf("%d", &inputtype);

		switch (inputtype) {
		case 0: return 0;
		case 1:
			rtn = InsertHeap(&heapinfo);
			if (rtn == 0) {
				printf("추가완료\n");
			}
			break;
		case 2:
			rtn = DeleteHeap(&heapinfo);
			if (rtn == 0) {
				printf("삭제완료\n");
			}
			break;
		case 3:
			int temp = 4;
			int blank = 3;
			int size = heapinfo.size;
			int level = getlevel(heapinfo.size);
			int l;

			for (l = 1; l <= level - 2; l++) {
				blank *= 2;
				blank += 1;
			}

			for (int i = 0; i < blank; i++) {
				printf(" ");
			}

			printf("%d\n", heapinfo.elem[1].key);
			for (int i = 2; i < heapinfo.size; i++) {
				bool power = CheckPowerOfTwo(i);
				if (power == true) {
					int id = i;
					for (int j = 0; j < id; j++) {
						if (j == 0) {
							for (int k = 0; k < (blank-1)/2; k++) {
								printf(" ");
							}
						}
						if (j < id - 1) {
							printf("%d", heapinfo.elem[i].key);
							if (heapinfo.elem[i].key > 99) {
								for (int k = 0; k < blank - 2; k++) {
									printf(" ");
								}
							}

							if (heapinfo.elem[i].key > 9) {
								for (int k = 0; k < blank-1; k++) {
									printf(" ");
								}
							}
							else {
								for (int k = 0; k < blank; k++) {
									printf(" ");
								}
							}
						}
						else {
							printf("%d\n", heapinfo.elem[i].key);
						}
						i++;
						if (i>heapinfo.size-1) {
							break;
						}
					}
					blank -= 1;
					blank /= 2;
					i--;
				}
			}
			printf("\n\n");
			break;
		}
	}
	return 0;
}