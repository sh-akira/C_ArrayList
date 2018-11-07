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
	void* value;			//�l
	struct list_item *next;	//���̃f�[�^�ւ̃|�C���^
}LIST_ITEM;

#define LIST_OK 0
#define LIST_ERR -1

#define LIST_ADD(listitem,value) list_add(listitem,(void*)value,sizeof(value))

//---- �֐��ꗗ ----

// �V�������X�g���쐬
// �߂�l:�G���[�� NULL  ������ �V�������X�g�ւ̃|�C���^
LIST_ITEM *list_new();

// ���X�g�̉��
// ������ꂽ���X�g�͍ė��p�ł��܂���Blist_new�ōĐ������Ă�������
void list_dispose(LIST_ITEM *item);

// ���X�g�Ƀf�[�^��o�^
// �߂�l:�G���[�� LIST_ERR  ������:�A�C�e���J�E���g
int list_add(LIST_ITEM *item, void* value, int valueLength);

// ���X�g����f�[�^����폜
// �߂�l:�G���[�� LIST_ERR  ������:LIST_OK
int list_removeat(LIST_ITEM *item, int index);

// ���X�g����w��ʒu��LIST_ITEM�����o��
// �߂�l:�G���[�� NULL  ������:�f�[�^
LIST_ITEM* list_itemat(LIST_ITEM *item, int index);

// ���X�g����w��ʒu�̃f�[�^�����o��
// �߂�l:�G���[�� NULL  ������:�f�[�^
void* list_valueat(LIST_ITEM *item, int index);

// ���X�g����w��ʒu�̃f�[�^�̒��������o��
// �߂�l:�G���[�� -1  ������:�f�[�^��
int list_lengthat(LIST_ITEM *item, int index);

// ���X�g�̑S���ڍ폜
void list_clear(LIST_ITEM *item);

// ���X�g�̃A�C�e�����擾
// �߂�l:�A�C�e����
int list_count(LIST_ITEM *item);


// ���X�g�ɔz��Ńf�[�^��ǉ�
// �߂�l:�G���[�� LIST_ERR  ������:�A�C�e���J�E���g
int list_addrange(LIST_ITEM *item, void* value, int valueLength, int count);

// ���X�g���̎w��f�[�^Index���擾
// �߂�l:�G���[�� -1  ������:Index
int list_indexat(LIST_ITEM *item, void* value, int valueLength);

// ���X�g����f�[�^��擪��������폜
// �߂�l:�G���[�� LIST_ERR  ������:LIST_OK
int list_removerange(LIST_ITEM *item, int count);

// ���X�g����z��Ƀf�[�^���R�s�[
// �߂�l:�G���[�� LIST_ERR  ������:LIST_OK
int list_copyto(LIST_ITEM *item, void* value, int valueLength, int count);

// ���X�g�ɕ�����𕪉����Ċi�[
// �߂�l:�G���[�� LIST_ERR  ������:LIST_OK
int list_split(LIST_ITEM *item, char* str, char* delimiter);


// ���X�g�̕�������������Ċi�[(�J�nIndex�̕�����ȍ~����������A�J�nIndex�̈ʒu�ɐڑ�����܂�)
// �߂�l:�G���[�� LIST_ERR  ������:LIST_OK
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
	
// ���s���ʁF
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


// ���X�g�S�Ă̕\��
void show_list(LIST_ITEM *item)
{
	LIST_ITEM *p = item->next;
	while (p != NULL) { // ���|�C���^��NULL�܂ŏ���
		printf("%s\n", p->value);
		p = p->next;
	}
}
*/


#endif // C_ARRAYLIST_H__