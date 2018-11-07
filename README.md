# C_ArrayList
C ArrayList Like C# ArrayList

# Example
```
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
	
// Result：
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


// Show all data
void show_list(LIST_ITEM *item)
{
	LIST_ITEM *p = item->next;
	while (p != NULL) { // loop for null pointer
		printf("%s\n", p->value);
		p = p->next;
	}
}
```
