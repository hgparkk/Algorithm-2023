
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct _item 
{
	char name[41];
	int price;
	char category[41];
	int count;
	int soldCount;
	int del;
}item;

typedef char* region;

typedef struct _edge
{
	region start;
	region end;
	int distance;
	int price;
	// 시간
	char del;
}edge;

int compare(const void* a, const void* b)
{
	item* pa = (item*)a;
	item* pb = (item*)b;

	return strcmp(pa->name, pb->name);
}

int compareReverse(const void* a, const void* b)
{
	item* pa = (item*)a;
	item* pb = (item*)b;

	return strcmp(pb->name, pa->name);
}

int binary_search(item list[], char* key, int low, int high)
{
	int middle;
	if (low <= high)
	{
		middle = (low + high) / 2;
		if (strcmp(key, list[middle].name) == 0)
			return middle;
		else if (strcmp(key, list[middle].name) < 0)
			return binary_search(list, key, low, middle - 1);
		else
			return binary_search(list, key, middle + 1, high);
	}
	return -1;
}

item* itemFileRead()
{
	int size;
	int i = 0;
	item* data;
	item tmp;
	FILE* fp = fopen("item.txt", "r");
	if (fp == NULL)
	{
		printf("fail to open file\n");
	}
	else
	{
		while (!feof(fp))
		{
			fscanf(fp, "%s %d %s %d %d %d", &tmp);
			size++;
		}
		data = (item*)malloc(sizeof(item) * size);
		fp = fopen("item.txt", "r");
		while (!feof(fp))
		{
			fscanf(fp, "%s %d %s %d %d %d", &data[i]);
			i++;
		}
		fclose(fp);
	}
	return data;
}

void itemFileAdd(item additem)
{
	FILE* fp = fopen("item.txt", "a");
	if (fp == NULL)
	{
		printf("fail to open file\n");
	}
	else
	{
		fprintf(fp, "%s %d %s %d %d %d\n", additem.name, additem.price, additem.category, additem.count, additem.soldCount, additem.del);
		fclose(fp);
	}
}

void itemFileWrite(item* data)
{
	int size = _msize(data) / sizeof(item);
	FILE* fp = fopen("item.txt", "w");
	if (fp == NULL)
	{
		printf("fail to open file\n");
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			fprintf(fp, "%s %d %s %d %d %d\n", data[i].name, data[i].price, data[i].category, data[i].count, data[i].soldCount, data[i].del);
		}
		fclose(fp);
	}
}

void inputItem()
{
	item tmpitem;
	tmpitem.count = 0;
	tmpitem.soldCount = 0;
	tmpitem.del = '0';
	printf("물품 이름 : ");
	scanf("%s", tmpitem.name);
	printf("물품 가격 : ");
	scanf("%d", tmpitem.price);
	printf("물품 카테고리 : ");
	scanf("%s", tmpitem.category);
	itemFileAdd(tmpitem);
	item* itemlist = itemFileRead();
	int size = sizeof(itemlist)/sizeof(item);
	qsort(itemlist,size,sizeof(item),compare);
	itemFileWrite(itemlist);
}

void updateItem()
{
	//item* itemlist = itemFileRead("item.txt");
	item item;
	printf("수정할 물품 이름 : ");
}

void deleteItem()
{
	item* itemlist = itemFileRead();
	int size = sizeof(itemlist)/sizeof(item);
	item tmpitem;
	char name[41];
	printf("삭제할 물품 이름 : ");
	scanf("%s", name);
	int findname = binary_search(itemlist, name, 0, size-1);
	if (findname == -1)
	{
		printf("해당 물품이 없습니다");
	}
	else
	{
		itemlist[findname].del = '1';
		printf("%s 를 삭제했습니다.",itemlist[findname].name);
	}
}

void searchItem()
{

}

int main()
{
}

