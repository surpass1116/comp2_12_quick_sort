#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

void qsort_parts(item* begin, item* end)
{
	if (end - begin < 1) return;

	bool beginflag = 0, endflag = 0;
	item  *keepend = (end-1);
	item* keepbegin = begin;
	item  *pivot = begin;


	while (1) {
		if (!beginflag) {
			begin++;
			if (begin->key > pivot->key) {
				beginflag = 1;
			}
		}
		if (!endflag) {
			end--;
			if (end->key < pivot->key) {
				endflag = 1;
			}
		}
		if (begin > end) {
			item a = *pivot;
			*pivot = *end;
			*end = a;

			if (end - keepbegin > 1)
				qsort_parts(keepbegin, end);

			if ((end+1) - (keepbegin+1) > 1)
				qsort_parts(end + 1, keepend+1);

			break;
		}
		else {
			if (beginflag && endflag) {
				item a = *begin;
				*begin = *end;
				*end = a;
				beginflag = 0;
				endflag = 0;
			}

		}
	}
}

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください
	if (begin == NULL)return false;
	if (end == NULL)return false;
	if (end < begin)return false;

	/*item* n, * m;


	n = begin;
	m = begin + (end - begin);*/



	//qsort_parts(n, m);
	bool beginflag = 0, endflag = 0;
	item* keepend = (begin + (end - begin) - 1);
	item* keepbegin = begin;
	item* pivot = begin;


	while (1) {
		if (!beginflag) {
			begin++;
			if (begin->key > pivot->key) {
				beginflag = 1;
			}
		}
		if (!endflag) {
			end--;
			if (end->key < pivot->key) {
				endflag = 1;
			}
		}
		if (begin > end) {
			item a = *pivot;
			*pivot = *end;
			*(begin + (end - begin)) = a;

			if (end - keepbegin > 1)
				quick_sort(keepbegin, begin + (end - begin));

			if ((end + 1) - (keepbegin + 1) > 1)
				quick_sort((begin + (end - begin)) + 1, keepend + 1);

			break;
		}
		else {
			if (beginflag && endflag) {
				item a = *begin;
				*begin = *end;
				*(begin + (end - begin)) = a;
				beginflag = 0;
				endflag = 0;
			}

		}
	}

	return true;
}
