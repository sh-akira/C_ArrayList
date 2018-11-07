/*
	C ArrayList  (c) sh_akira.
	https://github.com/sh-akira/C_ArrayList
*/

#include "c_arraylist.h"

// �V�������X�g���쐬
// �߂�l:�G���[�� NULL  ������ �V�������X�g�ւ̃|�C���^
LIST_ITEM *list_new()
{
	LIST_ITEM *new_item;
	
	//�m��
	if ((new_item = (LIST_ITEM *) malloc(sizeof(LIST_ITEM))) == NULL) {
		printf("LIST_ITEM malloc error\n");
		return NULL;
	}
	new_item->next = NULL;
	return new_item;
}

// ���X�g�̉��
// ������ꂽ���X�g�͍ė��p�ł��܂���Blist_new�ōĐ������Ă�������
void list_dispose(LIST_ITEM *item)
{
	list_clear(item);
	free(item);
}

// ���X�g�Ƀf�[�^��o�^
// �߂�l:�G���[�� LIST_ERR  ������:�A�C�e���J�E���g
int list_add(LIST_ITEM *item, void* value, int valueLength)
{
	LIST_ITEM *new_item;
	
	//�m��
	if ((new_item = list_new()) == NULL) {
		return LIST_ERR;
	}
	
	if ((new_item->value = malloc(valueLength)) == NULL) {
		printf("value malloc error\n");
		return LIST_ERR;
	}
	
	// ���X�g�A�C�e���Ƀf�[�^��o�^
	new_item->length = valueLength;
	memcpy(new_item->value, value, valueLength);
	
	LIST_ITEM *temp_item = item;
	int count = 0;
	//�ŏI���X�g�A�C�e���ɐڑ�
	while (1) {
		count++;
		if (temp_item->next == NULL) break;
		temp_item = temp_item->next;
	}
	temp_item->next = new_item;
	
	return count;
}

// ���X�g����f�[�^����폜
// �߂�l:�G���[�� LIST_ERR  ������:LIST_OK
int list_removeat(LIST_ITEM *item, int index)
{

	LIST_ITEM *temp_olditem = NULL;
	LIST_ITEM *temp_item = item;
	int count = 0;
	//�ŏI���X�g�A�C�e���ɐڑ�
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

// ���X�g����w��ʒu��LIST_ITEM�����o��
// �߂�l:�G���[�� NULL  ������:�f�[�^
LIST_ITEM* list_itemat(LIST_ITEM *item, int index)
{
	LIST_ITEM *temp_item = item;
	int count = 0;
	//�ŏI���X�g�A�C�e���ɐڑ�
	while (1) {
		temp_item = temp_item->next;
		if (temp_item == NULL) return NULL;
		if (count == index) break;
		count++;
	}
	return temp_item;
}

// ���X�g����w��ʒu�̃f�[�^�����o��
// �߂�l:�G���[�� NULL  ������:�f�[�^
void* list_valueat(LIST_ITEM *item, int index)
{
	LIST_ITEM *temp_item = list_itemat(item,index);
	if (temp_item == NULL) return NULL;
	return temp_item->value;
}

// ���X�g����w��ʒu�̃f�[�^�̒��������o��
// �߂�l:�G���[�� -1  ������:�f�[�^��
int list_lengthat(LIST_ITEM *item, int index)
{
	LIST_ITEM *temp_item = list_itemat(item,index);
	if (temp_item == NULL) return -1;
	return temp_item->length;
}

// ���X�g�̑S���ڍ폜
void list_clear(LIST_ITEM *item)
{
	LIST_ITEM *p1, *p2;
	p1 = item->next;

	while (p1 != NULL) { // ���|�C���^��NULL�܂�
		p2 = p1->next;
		free(p1->value);
		free(p1);
		p1 = p2;
	}
	item->next = NULL;
}

// ���X�g�̃A�C�e�����擾
// �߂�l:�A�C�e����
int list_count(LIST_ITEM *item)
{
	LIST_ITEM *temp_item = item;
	int count = 0;
	//�ŏI���X�g�A�C�e���܂ŃJ�E���g
	while (1) {
		temp_item = temp_item->next;
		if (temp_item == NULL) return count;
		count++;
	}
}


// ���X�g�ɔz��Ńf�[�^��ǉ�
// �߂�l:�G���[�� LIST_ERR  ������:�A�C�e���J�E���g
int list_addrange(LIST_ITEM *item, void* value, int valueLength, int count)
{
	LIST_ITEM *new_item;
	
	//�m��
	if ((new_item = list_new()) == NULL) {
		return LIST_ERR;
	}
	
	if ((new_item->value = malloc(valueLength)) == NULL) {
		printf("value malloc error\n");
		return LIST_ERR;
	}
	
	// ���X�g�A�C�e���Ƀf�[�^��o�^
	new_item->length = valueLength;
	memcpy(new_item->value, value, valueLength);
	
	LIST_ITEM *temp_item = item;
	int retcount = 0;
	//�ŏI���X�g�A�C�e���ɐڑ�
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

// ���X�g���̎w��f�[�^Index���擾
// �߂�l:�G���[�� -1  ������:Index
int list_indexat(LIST_ITEM *item, void* value, int valueLength)
{
	LIST_ITEM *temp_item = item;
	int count = 0;
	//�ŏI���X�g�A�C�e���ɐڑ�
	while (1) {
		temp_item = temp_item->next;
		if (temp_item == NULL) return -1;
		if (memcmp(temp_item->value,value,valueLength) == 0) return count;
		count++;
	}
}

// ���X�g����f�[�^��擪��������폜
// �߂�l:�G���[�� LIST_ERR  ������:LIST_OK
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

// ���X�g����z��Ƀf�[�^���R�s�[
// �߂�l:�G���[�� LIST_ERR  ������:LIST_OK
int list_copyto(LIST_ITEM *item, void* value, int valueLength, int count)
{
	LIST_ITEM *temp_item = item;
	//�ŏI���X�g�A�C�e���ɐڑ�
	while (count-- > 0) {
		temp_item = temp_item->next;
		if (temp_item == NULL) return LIST_ERR;
		memcpy(value, temp_item->value, valueLength);
		value += valueLength;
	}
	return LIST_OK;
}

// ���X�g�ɕ�����𕪉����Ċi�[
// �߂�l:�G���[�� LIST_ERR  ������:LIST_OK
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
	
	//�m��
	if ((new_item = list_new()) == NULL) {
		return LIST_ERR;
	}
	
	if ((new_item->value = malloc(length)) == NULL) {
		printf("value malloc error\n");
		return LIST_ERR;
	}
	
	// ���X�g�A�C�e���Ƀf�[�^��o�^
	new_item->length = length;
	memcpy(new_item->value, str, length);
	((char*)(new_item->value))[length-1] = '\0';
	
	LIST_ITEM *temp_item = item;
	//�ŏI���X�g�A�C�e���ɐڑ�
	while (1) {
		if (temp_item->next == NULL) break;
		temp_item = temp_item->next;
	}
	temp_item->next = new_item;
	if (isLast == 1) return LIST_OK;
	return list_split(item,adr+strlen(delimiter),delimiter);
}

// ���X�g�̕�������������Ċi�[(�J�nIndex�̕�����ȍ~����������A�J�nIndex�̈ʒu�ɐڑ�����܂�)
// �߂�l:�G���[�� LIST_ERR  ������:LIST_OK
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
	//adapter_item�͌����J�n�̈��O(���������炱��ɐڑ�����)
	
	//char�o�b�t�@�[�m��
	if ((charbuf_list = list_new()) == NULL) {
		return LIST_ERR;
	}
	
	//�w��ʒu������̕���������ׂ�char�o�b�t�@�[��delimiter�t���œ���Ȃ���J��
	temp_item = adapter_item->next;
	while (1) {
		if (temp_item == NULL) break;
		//��������o�b�t�@�ɓ����
		if(temp_item->length>1) list_addrange(charbuf_list, temp_item->value, 1, temp_item->length-1);//null��������Ȃ���Βǉ�
		if((strlen(delimiter) > 0) && (temp_item->next != NULL)) list_addrange(charbuf_list, (void*)delimiter, 1, strlen(delimiter));//delimiter��null��������Ȃ��A���̕����񂪂���Βǉ�
		//�J��
		p_item = temp_item->next;
		free(temp_item->value);
		free(temp_item);
		
		temp_item = p_item;
	}
	
	//char�o�b�t�@�[���������āA�ڑ�
	
	length = list_count(charbuf_list) + 1;
	
	//����������̈�m��
	if ((new_item = list_new()) == NULL) {
		return LIST_ERR;
	}
	
	if ((new_item->value = malloc(length)) == NULL) {
		printf("value malloc error\n");
		return LIST_ERR;
	}
	
	// ���X�g�A�C�e���Ƀf�[�^��o�^
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