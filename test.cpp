#include "gtest/gtest.h"
#include "HashTable.h"
#include "BinominalHeap.h"


#ifndef LINKEDLIST
#define LINKEDLIST
#include "LinkedList.h"
#endif



TEST(LINKED_LIST, MAKING_LIST) {
	LinkedList<int> list = LinkedList<int>();
	EXPECT_EQ(NULL, list.getHead());
	EXPECT_EQ(NULL, list.getTail());
	EXPECT_EQ(list.getHead(), list.getTail());
}

TEST(LINKED_LIST_INSERT, INSERT_TO_EMPTY) {
	LinkedList<int> list = LinkedList<int>();
	int element = 1;
	list.insert(&element, 1);
	
	EXPECT_EQ(1, *list.getHead()->item);
	EXPECT_EQ(1, *list.getTail()->item);
	EXPECT_EQ(NULL, list.getHead()->next);
	EXPECT_EQ(list.getTail(), list.getHead());	
}
TEST(LINKED_LIST_INSERT, INSERT_TWO_ELEMENTS) {
	LinkedList<int> list = LinkedList<int>();
	int one = 1, two = 2;
	list.insert(&one, 1);
	list.insert(&two, 2);

	EXPECT_EQ(1, *list.getHead()->item);
	EXPECT_EQ(2, *list.getHead()->next->item);
	EXPECT_EQ(2, *list.getTail()->item);
	EXPECT_EQ(NULL, list.getHead()->next->next);
}
TEST(LINKED_LIST_INSERT, INSERT_THREE_ELEMENTS) {
	LinkedList<int> list = LinkedList<int>();
	int one = 1, two = 2, three = 3;
	list.insert(&one, 1);
	list.insert(&two, 2);
	list.insert(&three, 3);


	EXPECT_EQ(1, *list.getHead()->item);
	EXPECT_EQ(list.getTail(), list.getHead()->next->next);
	EXPECT_EQ(NULL, list.getTail()->next);
	EXPECT_EQ(2, *list.getHead()->next->item);
}
#define SIZE 1000
TEST(LINKED_LIST_SEARCH, SEARCH_ELEMENTS) {
	LinkedList<int> list = LinkedList<int>();

	int array[SIZE];
	for(int i = 0; i < SIZE; i++) {
	    array[i] = i;
	    list.insert(&array[i], i);
	}
	EXPECT_EQ(0, *list.getHead()->item);
	EXPECT_EQ(SIZE-1, *list.getTail()->item);
	
	
	for(int i = 0; i < SIZE; i++) {
	    int search = *list.search(i);
	    EXPECT_EQ(search, i);
	}
}
TEST(LINKED_LIST_REMOVING, REMOVING_FIRST_AND_ONLY_NODE) {
	LinkedList<int> list = LinkedList<int>();
	int element = 1;
	list.insert(&element, 1);
	list.remove(1);
	EXPECT_EQ(NULL, list.getHead());
	EXPECT_EQ(NULL, list.getTail());
}
TEST(LINKED_LIST_REMOVING, REMOVING_FIRST_ELEMENT_FROM_MANY) {
	LinkedList<int>  list = LinkedList<int>();
	int one = 1, two = 2, three = 3;
	
	list.insert(&one, 1);
	list.insert(&two, 2);
	list.insert(&three, 3);
	
	list.remove(1);
	EXPECT_EQ(2, *list.getHead()->item);
	EXPECT_EQ(3, *list.getTail()->item);
}

TEST(LINKED_LIST_REMOVING, REMOVING_MIDDLE_ELEMENT) {
	LinkedList<int> list = LinkedList<int>();
	int one = 1, two = 2, three = 3;

	list.insert(&one, 1);
	list.insert(&two, 2);
	list.insert(&three, 3);

	list.remove(2);

	EXPECT_EQ(1, *list.getHead()->item);
	EXPECT_EQ(3, *list.getHead()->next->item);
	EXPECT_EQ(3, *list.getTail()->item);


}
TEST(LINKED_LIST_REMOVING, REMOVING_LAST_ELEMNT) {
	LinkedList<int> list = LinkedList<int>();
	int one = 1, two = 2, three = 3;
	
	list.insert(&one, 1);
	list.insert(&two, 2);
	list.insert(&three, 3);
	
	list.remove(3);

	EXPECT_EQ(1, *list.getHead()->item);
	EXPECT_EQ(2, *list.getTail()->item);
	EXPECT_EQ(2, *list.getHead()->next->item);

}
TEST(LIST_POP_HEAD, SINGLE_NODE) {
	LinkedList<int> list = LinkedList<int>();
	int one = 1;
	list.insert(&one, 1);
	EXPECT_EQ(1, *list.popFront());
	EXPECT_EQ(NULL, list.getHead());
	EXPECT_EQ(NULL, list.getTail());
}
TEST(LIST_POP_HEAD, TWO_NODES) {
	LinkedList<int> list = LinkedList<int>();
	int one = 1, two = 2;
	list.insert(&one,1);
	list.insert(&two,2);
	EXPECT_EQ(1, *list.popFront());
	EXPECT_EQ(2, *list.getHead()->item);
	EXPECT_EQ(2, *list.getTail()->item);

}
TEST(LIST_POP_TAIL, SINGLE_NODE) {
	LinkedList<int> list = LinkedList<int>();
	int one = 1;
	list.insert(&one, 1);
	EXPECT_EQ(1, *list.popTail());
	EXPECT_EQ(NULL, list.getHead());
	EXPECT_EQ(NULL, list.getTail());
}
TEST(LIST_POP_TAIL, MANY_NODES) {
	LinkedList<int> list = LinkedList<int>();
	int one = 1, two = 2;
	list.insert(&one, 1);
	list.insert(&two, 2);
	EXPECT_EQ(2, *list.popTail());
	EXPECT_EQ(1, *list.getTail()->item);
	EXPECT_EQ(1, *list.getHead()->item);
}
TEST(HASH_TABLE_INSERT, JUST_INSERT) {
	HashTable<int> Table = HashTable<int>(100);
	int array[SIZE];
	for(int i = 0; i < SIZE; i++) {
		array[i] = i;
		Table.insert(&array[i], i);
	}

}
TEST(HASH_TABLE_SEARCH, SEARCH_EVERY) {
	HashTable<int> Table = HashTable<int>(100);
	int array[SIZE];
	for(int i = 0; i < SIZE; i++) {
		array[i] = i;
		Table.insert(&array[i], i);
	}
	for(int i = 0; i < SIZE; i++) {
		EXPECT_EQ(i, *Table.search(i));
	}
}
TEST(HASH_TABLE_POP, POPING_NODES) {
	HashTable<int> Table = HashTable<int>(100);
	int array[SIZE];
	for(int i = 0; i < SIZE; i++) {
		array[i] = i;
		Table.insert(&array[i], i);

	}
	for(int i = 0; i < SIZE; i++) {
		EXPECT_EQ(i,*Table.pop(i));
		EXPECT_EQ(NULL, Table.search(i));
	}
}
TEST(HASH_TABLE_REMOVE, REMOVING_NODES) {
	HashTable<int> Table = HashTable<int>(SIZE); 
	int array[SIZE];
	for(int i = 0; i < SIZE; i++) {
		array[i] = i;
		Table.insert(&array[i], i);
	}		
	for(int i = 0; i < SIZE; i++) {
		Table.remove(i);
		EXPECT_EQ(NULL, Table.search(i));
	}

}

TEST(NODE, NODE_CONSTRUCTOR) {
	Node * n = new Node();

	EXPECT_EQ(NULL, n->parent);
	EXPECT_EQ(NULL, n->child);
	EXPECT_EQ(NULL, n->sibling);
	EXPECT_EQ(0, n->key);
	EXPECT_EQ(0, n->depth);

}

TEST(MAKE_BINOMINAL_HEAP, FIRST) {
	Node * n = makeBinominalHeap();

	EXPECT_EQ(NULL, n->parent);
	EXPECT_EQ(NULL, n->child);
	EXPECT_EQ(NULL, n->sibling);
	EXPECT_EQ(0, n->key);
	EXPECT_EQ(0, n->depth);

}
TEST(FIND_MAXIMUM_NODE_IN_BINOMINAL_HEAP, EMPTY_HEAP) {
	EXPECT_THROW(findBinominalHeapMaximumNode(NULL), EmptyHeap);	


}

TEST(FIND_MAXIMUM_NODE_IN_BINOMINAL_HEAP, MAXIMUM_IS_HEAD) {
	Node * one = new Node();
	Node * two = new Node();
	Node * three = new Node();
	one->key = 10;
	two->key = 5;
	three->key = 3;
	one->sibling = two;
	two->sibling = three;
	three->sibling = NULL;
	EXPECT_EQ(10, findBinominalHeapMaximumNode(one)->key);
}

TEST(FIND_MAXIMUM_NODE_IN_BINOMINAL_HEAP, MAXIMUM_IS_IN_LIST) {
	Node * one = new Node();
	Node * two = new Node();
	Node * three = new Node();
	Node * four = new Node();
	one->key = 5;
	two->key = 3;
	three->key = 10;
	four->key = 9;

	one->sibling = two;
	two->sibling = three;
	three->sibling = four;
	four->sibling = NULL;


	EXPECT_EQ(10, findBinominalHeapMaximumNode(one)->key);

}
TEST(FIND_MAXIMUM_NODE_IN_BINOMINAL_HEAP, MAXIMUM_IS_AT_END) {
	Node * one = new Node();
	Node * two = new Node();
	Node * three = new Node();
	Node * four = new Node();
	one->key = 5;
	two->key = 3;
	three->key = 10;
	four->key = 13;

	one->sibling = two;
	two->sibling = three;
	three->sibling = four;
	four->sibling = NULL;


	EXPECT_EQ(13, findBinominalHeapMaximumNode(one)->key);

}

TEST(LINKING_TWO_TREES, LINKING_NULLS) {
	EXPECT_ANY_THROW(linkTwoBinominalTrees(NULL, NULL));
}

TEST(LINKING_TWO_TREES, LINKING_TWO_ONE) {
	Node * one = new Node();
	Node * two = new Node();
	one->key = 10;
	two->key = 5;
	Node * head = linkTwoBinominalTrees(one,two);
	EXPECT_EQ(10, head->key);
	EXPECT_EQ(1, head->depth);
	EXPECT_EQ(NULL, head->parent);
	EXPECT_EQ(NULL, head->sibling);
	EXPECT_EQ(5, head->child->key);
	EXPECT_EQ(0, head->child->depth);
	EXPECT_EQ(NULL, head->child->sibling);
	EXPECT_EQ(NULL, head->child->child);
	EXPECT_EQ(head, head->child->parent);
	
}
TEST(LINKING_TWO_TREES, LINKING_TWO_TWO) {
	Node * one = new Node();
	one->key = 4;
	Node * two = new Node();
	two->key = 3;
	Node * three = new Node();
	three->key = 2;
	Node * four = new Node();
	four->key = 1;
	Node * xTwo = linkTwoBinominalTrees(one, two);
	Node * yTwo = linkTwoBinominalTrees(three, four);
	Node * head = linkTwoBinominalTrees(xTwo, yTwo);
	EXPECT_EQ(4, head->key);
	EXPECT_EQ(NULL, head->parent);
	EXPECT_EQ(NULL, head->sibling);
	EXPECT_EQ(2, head->depth);
	EXPECT_EQ(2, head->child->key);
	EXPECT_EQ(3, head->child->sibling->key);
	EXPECT_EQ(1, head->child->child->key);
	EXPECT_EQ(NULL, head->child->child->child);
	EXPECT_EQ(NULL, head->child->child->sibling);
	EXPECT_EQ(4, head->child->parent->key);
	EXPECT_EQ(2, head->child->child->parent->key);
	EXPECT_EQ(0, head->child->child->depth);
	EXPECT_EQ(1, head->child->depth);
}
TEST(MERGING_TWO_HEAPS, TWO_NULL) {
	EXPECT_ANY_THROW(mergeBinominalHeaps(NULL, NULL));
}

TEST(MERGIGNG_TWO_HEAPS, TWO_ZERO) {
	Node * one = new Node(); 
	Node * two = new Node();
	one->key = 1;
	two->key = 2;
	Node * head = mergeBinominalHeaps(one, two);
	EXPECT_EQ(0, head->depth);
	EXPECT_EQ(2, head->key);
	EXPECT_EQ(0, head->sibling->depth);
	EXPECT_EQ(1, head->sibling->key);
}

TEST(MERGING_TWO_HEAPS, ZERO_ONE_AND_ZERO_ONE) {
	Node * one = new Node(1);
	Node * two = new Node(2);
	Node * three = new Node(3);
	Node * four = new Node(4);
	Node * five = new Node(5);
	Node * six = new Node(6);

	Node * firstZERO = one;
	Node * firstONE = linkTwoBinominalTrees(three, two);
	EXPECT_EQ(3, firstONE->key);
	Node *secondZERO = four;
	Node * secondONE = linkTwoBinominalTrees(six, five);
	EXPECT_EQ(6, secondONE->key);
	firstZERO->sibling = firstONE;
	secondZERO->sibling = secondONE;

	Node * newHead = mergeBinominalHeaps(firstZERO, secondZERO);
	EXPECT_EQ(0, newHead->depth);
	EXPECT_EQ(0, newHead->sibling->depth);
	EXPECT_EQ(1, newHead->sibling->sibling->depth);
	EXPECT_EQ(1, newHead->sibling->sibling->sibling->depth);

}


TEST(MERGING_TWO_HEAPS, ZERO_ONE_TWO_AND_ONE) {
	Node ** array = new Node*[12];
	for(int i = 0; i < 12; i++) {
		 array[i] = new Node();
	}

	Node * ZERO = array[0];
	Node * ONE = linkTwoBinominalTrees(array[1], array[2]);
	Node * a = linkTwoBinominalTrees(array[3], array[4]);
	Node * b = linkTwoBinominalTrees(array[5], array[6]);
	Node * TWO = linkTwoBinominalTrees(a,b);

	Node * headOne = ZERO;
	headOne->sibling = ONE;
	headOne->sibling->sibling = TWO;


	Node * c = linkTwoBinominalTrees(array[7], array[8]);
	Node * d = linkTwoBinominalTrees(array[9], array[10]);
	Node *  SecondTwo = linkTwoBinominalTrees(c,d);
	
	Node * headTwo = SecondTwo;

	Node * newHead = mergeBinominalHeaps(SecondTwo, headOne);
	EXPECT_EQ(0, newHead->depth);
	EXPECT_EQ(1, newHead->sibling->depth);
	EXPECT_EQ(2, newHead->sibling->sibling->depth);
	EXPECT_EQ(2, newHead->sibling->sibling->sibling->depth);

}

TEST(MERGING_TWO_HEAPS,ONE_AND_ZERO_ONE_TWO) {
	Node ** array = new Node*[12];
	for(int i = 0; i < 12; i++) {
		 array[i] = new Node();
	}

	Node * ZERO = array[0];
	Node * ONE = linkTwoBinominalTrees(array[1], array[2]);
	Node * a = linkTwoBinominalTrees(array[3], array[4]);
	Node * b = linkTwoBinominalTrees(array[5], array[6]);
	Node * TWO = linkTwoBinominalTrees(a,b);

	Node * headOne = ZERO;
	headOne->sibling = ONE;
	headOne->sibling->sibling = TWO;


	Node * c = linkTwoBinominalTrees(array[7], array[8]);
	Node * d = linkTwoBinominalTrees(array[9], array[10]);
	Node *  SecondTwo = linkTwoBinominalTrees(c,d);
	
	Node * headTwo = SecondTwo;

	Node * newHead = mergeBinominalHeaps(headOne, SecondTwo);
	EXPECT_EQ(0, newHead->depth);
	EXPECT_EQ(1, newHead->sibling->depth);
	EXPECT_EQ(2, newHead->sibling->sibling->depth);
	EXPECT_EQ(2, newHead->sibling->sibling->sibling->depth);

}
TEST(MERGING_TWO_HEAPS, ONE_AND_NULL) {
	Node * a = new Node();
	Node * b = new Node();
	Node * ONE = linkTwoBinominalTrees(a,b);
	Node * head = mergeBinominalHeaps(ONE, NULL);
	EXPECT_EQ(1, head->depth);
	EXPECT_EQ(NULL, head->sibling);
	
}

TEST(UNION_TWO_HEAPS, ZERO_AND_ZERO) {
	Node * a = new Node();
	Node * b = new Node();
	Node * newHead = unionBinominalHeaps(a, b);
	EXPECT_EQ(1, newHead->depth);


}
#include <iostream>
TEST(UNION_TWO_HEAPS, ZER_ONE_TWO_AND_ZERO_ONE_TWO) {
	Node * head = new Node();
	Node * headTwo = new Node();
	for(int i = 1; i <= 15; i++) {
		head = unionBinominalHeaps(head, new Node());
	}
	for(int i = 1; i <= 20; i++) {
		headTwo = unionBinominalHeaps(headTwo, new Node());
	}

	head = unionBinominalHeaps(head, headTwo);

	EXPECT_EQ(0, head->depth);
	EXPECT_EQ(2, head->sibling->depth);
	EXPECT_EQ(5, head->sibling->sibling->depth);
	
}
TEST(INSERT_BINOMINAL_HEAP, INSERTING_ONE_IN_ONE_TWO_THREE_HEAP) {
	
	Node * head = makeBinominalHeap(0);
	for(int i = 1; i < 7; i++) {
		head = unionBinominalHeaps(head, makeBinominalHeap(i));
	}


	EXPECT_EQ(0, head->depth);
	EXPECT_EQ(1, head->sibling->depth);
	EXPECT_EQ(2, head->sibling->sibling->depth);

	insertBinominalHeap(head, 8);
	
	
}
TEST(REVERSE_LIST, REVERSING_EMPTY_LIST) {
	Node * tmp = NULL;
	tmp = reverseList(tmp);
	EXPECT_EQ(NULL, tmp);
}
TEST(REVERSE_LIST, REVERSE_SINGLE_ELEMENT_LIST) {
	Node * one = new Node(10);
	one = reverseList(one);
	EXPECT_EQ(10, one->key);
	EXPECT_EQ(NULL, one->sibling);
}
TEST(REVERSE_LIST, REVERSE_TWO_ELEMENTS_LIST) {
	Node * one = new Node(10);
	Node * two = new Node(20);
	one->sibling = two;
	two->sibling = NULL;

	one = reverseList(one);

	EXPECT_EQ(20, one->key);
	EXPECT_EQ(10, one->sibling->key);
	EXPECT_EQ(NULL, one->sibling->sibling);
}
TEST(REVERSE_LIST, REVERSE_THREE_ELEMENTS_LIST) {
	Node * one = new Node(10);
	Node * two = new Node(20);
	Node * three = new Node(30);

	one->sibling = two;
	one->sibling->sibling = three;

	one = reverseList(one);

	EXPECT_EQ(30, one->key);
	EXPECT_EQ(20, one->sibling->key);
	EXPECT_EQ(10, one->sibling->sibling->key);
	EXPECT_EQ(NULL, one->sibling->sibling->sibling);
}
TEST(REVERSE_LIST, REVERSE_MANY_ELEMENTS_LIST) {	
	Node * one = new Node(1);
	Node * two = new Node(2);
	Node * three = new Node(3);
	Node * four = new Node(4);
	one->sibling = two;
	two->sibling = three;
	three->sibling = four;

	one = reverseList(one);

	EXPECT_EQ(4, one->key);
	EXPECT_EQ(3, one->sibling->key);
	EXPECT_EQ(2, one->sibling->sibling->key);
	EXPECT_EQ(1, one->sibling->sibling->sibling->key);
	EXPECT_EQ(NULL, one->sibling->sibling->sibling->sibling);
}
TEST(BINOMINAL_HEAD_FINDING_MAX, JUST_TEST) {
	Node * head = makeBinominalHeap(0);
	for(int i = 0; i < 500; i++) {
		head = insertBinominalHeap(head, i+1000);
	}
	for(int i = 0; i < 500; i++) {
		head = insertBinominalHeap(head, i);
		EXPECT_EQ(1499, findBinominalHeapMaximumNode(head)->key);

	}
}
