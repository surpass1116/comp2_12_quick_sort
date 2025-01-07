#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

static void swap(item* a, item* b)
{
	item t = *a;
	*a = *b;
	*b = t;
}

static item* searchFront(int key, item* begin, const item* end)
{
	while (begin->key <= key && begin < end)begin++;
	return begin;
}

static item* searchRear(int key, const item* begin, item* end)
{
	while (end->key >= key && end > begin)end--;
	return  end;
}

item* partition(item* begin, const item* end)
{
	int key = begin->key;
	item* head = searchFront(key, begin + 1, end);
	item* tail = searchRear(key, begin, begin + (end - begin) - 1);

	while (head < tail) {
		swap(head, tail);
		searchFront(key, head+1, end);
		searchRear(key, begin, tail - 1);
	}

	swap(tail,begin);
	return tail;
}

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください
	if (begin == NULL)return false;
	if (end == NULL)return false;
	if (end < begin)return false;
	if (end - begin <= 1) return true;

	item* pivot = partition(begin, end);
	quick_sort(begin, pivot);
	quick_sort(pivot + 1, end);

	return true;
}
