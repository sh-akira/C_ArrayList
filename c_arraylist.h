/*
	C ArrayList  (c) sh_akira.
	https://github.com/sh-akira/C_ArrayList
*/


#ifndef C_ARRAYLIST_H__
#define C_ARRAYLIST_H__


#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

typedef struct list_item {
	int length;
	void* value;			//値
	struct list_item *next;	//次のデータへのポインタ
}LIST_ITEM;

#define LIST_OK 0
#define LIST_ERR -1

#define LIST_ADD(listitem,value) list_add(listitem,(void*)value,sizeof(value))

//---- 関数一覧 ----

// 新しいリストを作成
// 戻り値:エラー時 NULL  成功時 新しいリストへのポインタ
LIST_ITEM *list_new();

// リストの解放
// 解放されたリストは再利用できません。list_newで再生成してください
void list_dispose(LIST_ITEM *item);

// リストにデータを登録
// 戻り値:エラー時 LIST_ERR  成功時:アイテムカウント
int list_add(LIST_ITEM *item, void* value, int valueLength);

// リストからデータを一つ削除
// 戻り値:エラー時 LIST_ERR  成功時:LIST_OK
int list_removeat(LIST_ITEM *item, int index);

// リストから指定位置のLIST_ITEMを取り出す
// 戻り値:エラー時 NULL  成功時:データ
LIST_ITEM* list_itemat(LIST_ITEM *item, int index);

// リストから指定位置のデータを取り出す
// 戻り値:エラー時 NULL  成功時:データ
void* list_valueat(LIST_ITEM *item, int index);

// リストから指定位置のデータの長さを取り出す
// 戻り値:エラー時 -1  成功時:データ長
int list_lengthat(LIST_ITEM *item, int index);

// リストの全項目削除
void list_clear(LIST_ITEM *item);

// リストのアイテム数取得
// 戻り値:アイテム数
int list_count(LIST_ITEM *item);


// リストに配列でデータを追加
// 戻り値:エラー時 LIST_ERR  成功時:アイテムカウント
int list_addrange(LIST_ITEM *item, void* value, int valueLength, int count);

// リスト内の指定データIndexを取得
// 戻り値:エラー時 -1  成功時:Index
int list_indexat(LIST_ITEM *item, void* value, int valueLength);

// リストからデータを先頭から個数分削除
// 戻り値:エラー時 LIST_ERR  成功時:LIST_OK
int list_removerange(LIST_ITEM *item, int count);

// リストから配列にデータをコピー
// 戻り値:エラー時 LIST_ERR  成功時:LIST_OK
int list_copyto(LIST_ITEM *item, void* value, int valueLength, int count);

// リストに文字列を分解して格納
// 戻り値:エラー時 LIST_ERR  成功時:LIST_OK
int list_split(LIST_ITEM *item, char* str, char* delimiter);


// リストの文字列を結合して格納(開始Indexの文字列以降が結合され、開始Indexの位置に接続されます)
// 戻り値:エラー時 LIST_ERR  成功時:LIST_OK
int list_join(LIST_ITEM *item, int startIndex, char* delimiter);

/* Example:


void show_list(LIST_ITEM *item);

int main(void)
{
	LIST_ITEM *str_list;

	str_list = list_new();
	
	LIST_ADD(str_list, "test1");
	LIST_ADD(str_list, "test2");
	LIST_ADD(str_list, "test3");
	LIST_ADD(str_list, "test4");
	LIST_ADD(str_list, "test5");
	LIST_ADD(str_list, "test6");
	LIST_ADD(str_list, "test7");
	LIST_ADD(str_list, "test8");
	
	printf("show all\n");
	show_list(str_list);
	printf("get item count:%d\n",list_count(str_list));
	
	printf("get item at 7:%s\n",list_valueat(str_list,7));
	
	printf("remove at 3\n");
	list_removeat(str_list,3);
	printf("show all\n");
	show_list(str_list);
	printf("get item count:%d\n",list_count(str_list));
	
	printf("get item at 7:%s\n",list_valueat(str_list,7));
	
	printf("clear all\n");
	list_clear(str_list);
	printf("show all\n");
	show_list(str_list);
	
	printf("dispose\n");
	list_dispose(str_list);

	return 0;
	
// 実行結果：
// show all
// test1
// test2
// test3
// test4
// test5
// test6
// test7
// test8
// get item count:8
// get item at 7:test8
// remove at 3
// show all
// test1
// test2
// test3
// test5
// test6
// test7
// test8
// get item count:7
// get item at 7:(null)
// clear all
// show all
// dispose

	
}


// リスト全ての表示
void show_list(LIST_ITEM *item)
{
	LIST_ITEM *p = item->next;
	while (p != NULL) { // 次ポインタがNULLまで処理
		printf("%s\n", p->value);
		p = p->next;
	}
}
*/


#endif // C_ARRAYLIST_H__