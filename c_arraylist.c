/*
	C ArrayList  (c) sh_akira.
	https://github.com/sh-akira/C_ArrayList
*/

#include "c_arraylist.h"

// 新しいリストを作成
// 戻り値:エラー時 NULL  成功時 新しいリストへのポインタ
LIST_ITEM *list_new()
{
	LIST_ITEM *new_item;
	
	//確保
	if ((new_item = (LIST_ITEM *) malloc(sizeof(LIST_ITEM))) == NULL) {
		printf("LIST_ITEM malloc error\n");
		return NULL;
	}
	new_item->next = NULL;
	return new_item;
}

// リストの解放
// 解放されたリストは再利用できません。list_newで再生成してください
void list_dispose(LIST_ITEM *item)
{
	list_clear(item);
	free(item);
}

// リストにデータを登録
// 戻り値:エラー時 LIST_ERR  成功時:アイテムカウント
int list_add(LIST_ITEM *item, void* value, int valueLength)
{
	LIST_ITEM *new_item;
	
	//確保
	if ((new_item = list_new()) == NULL) {
		return LIST_ERR;
	}
	
	if ((new_item->value = malloc(valueLength)) == NULL) {
		printf("value malloc error\n");
		return LIST_ERR;
	}
	
	// リストアイテムにデータを登録
	new_item->length = valueLength;
	memcpy(new_item->value, value, valueLength);
	
	LIST_ITEM *temp_item = item;
	int count = 0;
	//最終リストアイテムに接続
	while (1) {
		count++;
		if (temp_item->next == NULL) break;
		temp_item = temp_item->next;
	}
	temp_item->next = new_item;
	
	return count;
}

// リストからデータを一つ削除
// 戻り値:エラー時 LIST_ERR  成功時:LIST_OK
int list_removeat(LIST_ITEM *item, int index)
{

	LIST_ITEM *temp_olditem = NULL;
	LIST_ITEM *temp_item = item;
	int count = 0;
	//最終リストアイテムに接続
	while (1) {
		temp_olditem = temp_item;
		temp_item = temp_item->next;
		if (temp_item == NULL) return LIST_ERR;
		if (count == index) break;
		count++;
	}
	temp_olditem->next = temp_item->next;
	free(temp_item->value);
	free(temp_item);
	
	return LIST_OK;
}

// リストから指定位置のLIST_ITEMを取り出す
// 戻り値:エラー時 NULL  成功時:データ
LIST_ITEM* list_itemat(LIST_ITEM *item, int index)
{
	LIST_ITEM *temp_item = item;
	int count = 0;
	//最終リストアイテムに接続
	while (1) {
		temp_item = temp_item->next;
		if (temp_item == NULL) return NULL;
		if (count == index) break;
		count++;
	}
	return temp_item;
}

// リストから指定位置のデータを取り出す
// 戻り値:エラー時 NULL  成功時:データ
void* list_valueat(LIST_ITEM *item, int index)
{
	LIST_ITEM *temp_item = list_itemat(item,index);
	if (temp_item == NULL) return NULL;
	return temp_item->value;
}

// リストから指定位置のデータの長さを取り出す
// 戻り値:エラー時 -1  成功時:データ長
int list_lengthat(LIST_ITEM *item, int index)
{
	LIST_ITEM *temp_item = list_itemat(item,index);
	if (temp_item == NULL) return -1;
	return temp_item->length;
}

// リストの全項目削除
void list_clear(LIST_ITEM *item)
{
	LIST_ITEM *p1, *p2;
	p1 = item->next;

	while (p1 != NULL) { // 次ポインタがNULLまで
		p2 = p1->next;
		free(p1->value);
		free(p1);
		p1 = p2;
	}
	item->next = NULL;
}

// リストのアイテム数取得
// 戻り値:アイテム数
int list_count(LIST_ITEM *item)
{
	LIST_ITEM *temp_item = item;
	int count = 0;
	//最終リストアイテムまでカウント
	while (1) {
		temp_item = temp_item->next;
		if (temp_item == NULL) return count;
		count++;
	}
}


// リストに配列でデータを追加
// 戻り値:エラー時 LIST_ERR  成功時:アイテムカウント
int list_addrange(LIST_ITEM *item, void* value, int valueLength, int count)
{
	LIST_ITEM *new_item;
	
	//確保
	if ((new_item = list_new()) == NULL) {
		return LIST_ERR;
	}
	
	if ((new_item->value = malloc(valueLength)) == NULL) {
		printf("value malloc error\n");
		return LIST_ERR;
	}
	
	// リストアイテムにデータを登録
	new_item->length = valueLength;
	memcpy(new_item->value, value, valueLength);
	
	LIST_ITEM *temp_item = item;
	int retcount = 0;
	//最終リストアイテムに接続
	while (1) {
		retcount++;
		if (temp_item->next == NULL) break;
		temp_item = temp_item->next;
	}
	temp_item->next = new_item;
	count--;
	if (count == 0){
		return retcount;
	} else {
		return list_addrange(item,value+valueLength,valueLength,count);
	}
}

// リスト内の指定データIndexを取得
// 戻り値:エラー時 -1  成功時:Index
int list_indexat(LIST_ITEM *item, void* value, int valueLength)
{
	LIST_ITEM *temp_item = item;
	int count = 0;
	//最終リストアイテムに接続
	while (1) {
		temp_item = temp_item->next;
		if (temp_item == NULL) return -1;
		if (memcmp(temp_item->value,value,valueLength) == 0) return count;
		count++;
	}
}

// リストからデータを先頭から個数分削除
// 戻り値:エラー時 LIST_ERR  成功時:LIST_OK
int list_removerange(LIST_ITEM *item, int count)
{
	LIST_ITEM *temp_olditem = NULL;
	LIST_ITEM *temp_item = item;
	if (count-- > 0){
		temp_olditem = temp_item;
		temp_item = temp_item->next;
		if (temp_item == NULL) return LIST_ERR;
		temp_olditem->next = temp_item->next;
		free(temp_item->value);
		free(temp_item);
		list_removerange(item,count);
	}
	return LIST_OK;
}

// リストから配列にデータをコピー
// 戻り値:エラー時 LIST_ERR  成功時:LIST_OK
int list_copyto(LIST_ITEM *item, void* value, int valueLength, int count)
{
	LIST_ITEM *temp_item = item;
	//最終リストアイテムに接続
	while (count-- > 0) {
		temp_item = temp_item->next;
		if (temp_item == NULL) return LIST_ERR;
		memcpy(value, temp_item->value, valueLength);
		value += valueLength;
	}
	return LIST_OK;
}

// リストに文字列を分解して格納
// 戻り値:エラー時 LIST_ERR  成功時:LIST_OK
int list_split(LIST_ITEM *item, char* str, char* delimiter)
{
	LIST_ITEM *new_item;
	char* adr;
	int length = 0;
	int isLast = 0;
	//if(str[0] == '\0') return LIST_OK;
	
	adr = strstr(str,delimiter);
	if (adr == NULL){
		if (str != NULL){
			adr = str+strlen(str);
			isLast = 1;
		} else {
			return LIST_OK;
		}
	}
	length = (int)(adr - str) + 1;
	printf("length:%d\n",length);
	
	//確保
	if ((new_item = list_new()) == NULL) {
		return LIST_ERR;
	}
	
	if ((new_item->value = malloc(length)) == NULL) {
		printf("value malloc error\n");
		return LIST_ERR;
	}
	
	// リストアイテムにデータを登録
	new_item->length = length;
	memcpy(new_item->value, str, length);
	((char*)(new_item->value))[length-1] = '\0';
	
	LIST_ITEM *temp_item = item;
	//最終リストアイテムに接続
	while (1) {
		if (temp_item->next == NULL) break;
		temp_item = temp_item->next;
	}
	temp_item->next = new_item;
	if (isLast == 1) return LIST_OK;
	return list_split(item,adr+strlen(delimiter),delimiter);
}

// リストの文字列を結合して格納(開始Indexの文字列以降が結合され、開始Indexの位置に接続されます)
// 戻り値:エラー時 LIST_ERR  成功時:LIST_OK
int list_join(LIST_ITEM *item, int startIndex, char* delimiter)
{
	
	LIST_ITEM *adapter_item = NULL;
	LIST_ITEM *charbuf_list = NULL;
	LIST_ITEM *temp_item = NULL;
	LIST_ITEM *p_item = NULL;
	LIST_ITEM *new_item = NULL;
	int count = 0;
	int length = 0;
	
	adapter_item = item;
	while (1) {
		if (adapter_item == NULL) return LIST_ERR;
		if (count == startIndex) break;
		adapter_item = adapter_item->next;
		count++;
	}
	//adapter_itemは結合開始の一つ手前(結合したらこれに接続する)
	
	//charバッファー確保
	if ((charbuf_list = list_new()) == NULL) {
		return LIST_ERR;
	}
	
	//指定位置から後ろの文字列をすべてcharバッファーにdelimiter付きで入れながら開放
	temp_item = adapter_item->next;
	while (1) {
		if (temp_item == NULL) break;
		//文字列をバッファに入れる
		if(temp_item->length>1) list_addrange(charbuf_list, temp_item->value, 1, temp_item->length-1);//null文字じゃなければ追加
		if((strlen(delimiter) > 0) && (temp_item->next != NULL)) list_addrange(charbuf_list, (void*)delimiter, 1, strlen(delimiter));//delimiterがnull文字じゃなく、次の文字列があれば追加
		//開放
		p_item = temp_item->next;
		free(temp_item->value);
		free(temp_item);
		
		temp_item = p_item;
	}
	
	//charバッファーを結合して、接続
	
	length = list_count(charbuf_list) + 1;
	
	//結合文字列領域確保
	if ((new_item = list_new()) == NULL) {
		return LIST_ERR;
	}
	
	if ((new_item->value = malloc(length)) == NULL) {
		printf("value malloc error\n");
		return LIST_ERR;
	}
	
	// リストアイテムにデータを登録
	new_item->length = length;
	
	count = 0;
	temp_item = charbuf_list;
	while (1) {
		temp_item = temp_item->next;
		if (temp_item == NULL) break;
		((char*)(new_item->value))[count] = ((char*)temp_item->value)[0];
		count++;
	}
	((char*)(new_item->value))[length-1] = '\0';
	
	adapter_item->next = new_item;
	return LIST_OK;
}