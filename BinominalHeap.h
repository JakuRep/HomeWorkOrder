#include <iostream>
#include <exception>
struct EmptyHeap : public std::exception {
	const char * what() const throw() {
		return "list is empty";
	}
};
struct DiffrentTreesHeight : public std::exception {
	const char * what() const throw() {
		return "you can't link trees with diffrent height";
	}
};
struct NoTreesToLink : public std::exception {
	const char * what() const throw() {
		return "you can't link empty trees" ;
	}

};


struct Node {
    Node * parent;
    Node * sibling;
    Node * child;
    int key;
    int depth;

    Node() : parent(NULL), sibling(NULL), child(NULL), key(0), depth(0) {}

    Node(int key) : parent(NULL), sibling(NULL), child(NULL), depth(0) {
	    this->key = key;
    }

};
Node * makeBinominalHeap() {
	return new Node();
}
Node * makeBinominalHeap(int key) {
    return new Node(key);
}
Node * findBinominalHeapMaximumNode(Node * head) {
	if(head == NULL) {
		throw EmptyHeap();
	}

	Node * maximumNode, * crawler;

	crawler = maximumNode = head;

	while(crawler != NULL) {
		if(crawler->key > maximumNode->key) {
			maximumNode = crawler;
		}
		crawler = crawler->sibling;
	}

	return maximumNode;
}
Node * linkTwoBinominalTrees(Node * xRoot, Node * yRoot) {
	//xRoot is new root of linkedTrees
    if(xRoot == NULL || yRoot == NULL) {
		throw NoTreesToLink();	
	}


	if(xRoot->depth != yRoot->depth) {
		throw DiffrentTreesHeight();
	}

	yRoot->parent = xRoot;
	yRoot->sibling = xRoot->child;
	xRoot->child = yRoot;
	xRoot->depth++;

	return xRoot;

}
Node * mergeBinominalHeaps(Node * xHead, Node * yHead) {
    Node * newHead, * newCrawler;
    Node *xCrawler = xHead;
    Node *yCrawler = yHead;


	if(xHead == NULL && yHead == NULL) {
		throw EmptyHeap();
	} else {

		if(xHead == NULL) {
			return yHead;
		} else if(yHead == NULL) {
			return xHead; 
		} else {
			//setting new head
			if(xHead->depth < yHead->depth) {
				newHead = xHead;
				xCrawler = xCrawler->sibling;
			} else {
				newHead = yHead;
				yCrawler = yCrawler->sibling;
			}	
			newCrawler = newHead;
			

			while(xCrawler != NULL && yCrawler != NULL) {
				if(xCrawler->depth  < yCrawler->depth) {
					newCrawler->sibling = xCrawler;
					newCrawler = newCrawler->sibling;
					xCrawler = xCrawler->sibling;
				} else {
					newCrawler->sibling = yCrawler;
					newCrawler = newCrawler->sibling;
					yCrawler = yCrawler->sibling;
				}
			}

			if(xCrawler != NULL && yCrawler == NULL) {
				newCrawler->sibling = xCrawler;
				return newHead;
			}


			if(yCrawler != NULL && xCrawler == NULL) {
				newCrawler->sibling = yCrawler;
				return newHead;
			}
			

			return newHead;
		}
	}
}
Node * unionBinominalHeaps(Node *xHead , Node * yHead) {
	Node * newHead = new Node();
	newHead = mergeBinominalHeaps(xHead,yHead);
	if(newHead == NULL) {
		return NULL;
	}
	Node * prevX = NULL;
	Node * x = newHead;
	Node * nextX = x->sibling;

	while(nextX != NULL) {
		if(x->depth != nextX->depth || (nextX->sibling != NULL && nextX->sibling->depth == x->depth)) {
			prevX = x;
			x = nextX;
		} else{
		       	if(x->key <= nextX->key) {
				x->sibling = nextX->sibling;
				linkTwoBinominalTrees(x, nextX);
			} else {
				if(prevX == NULL) {
					newHead = nextX; 
				} else {
					prevX->sibling = nextX;
				}
				linkTwoBinominalTrees(nextX, x);
				x = nextX;
			}
			
		} 
		nextX = x->sibling;
		
	}

	return newHead;
}
Node *  insertBinominalHeap(Node *  head, int key) {
	Node * n = makeBinominalHeap(key);
	return unionBinominalHeaps(n, head);
}
Node * reverseList(Node * head) {
	Node * prev, *x;
	prev = NULL;
	x = head;

	while(x != NULL) {

		Node * n = x->sibling;
		x->sibling = prev;
		x->parent = NULL;
		prev = x;
		x = n;
	}	

	return prev;

}
Node * extractMax(Node * &head) {
	Node * prev, * crawler, *prevMax, *max, *child, *tmp;
	prevMax = prev = NULL;
	max = crawler = head;

	while(crawler != NULL) {
	    if(crawler->key > max->key) {
	        max = crawler;
	        prevMax = prev;
	    }


	    prev = crawler;
	    crawler = crawler->sibling;
	}

	if(prevMax == NULL) {
	    if(max->sibling == NULL) {
	        if(max->child != NULL) {
	            head = reverseList(max->child);
	        } else {
	            head = NULL;
	        }
	    } else {
            if(max->child != NULL) {
                tmp = reverseList(max->child);
                head = max->sibling;
                head = unionBinominalHeaps(tmp, head);
            } else {
                head = max->sibling;
            }
	    }
	} else {

	    if(max->sibling == NULL) {
	        prevMax->sibling = NULL;
	    } else {
            prevMax->sibling = max->sibling;
	    };


        if(max->child != NULL) {
            tmp = reverseList(max->child);
            head = unionBinominalHeaps(tmp, head);
        }
	}
	max->sibling = NULL;
	max->parent = NULL;
	return max;
};
void swapKeys(Node *x, Node * y) {
	int key = x->key;
	x->key = y->key;
	y->key = key;
}
void increaseKey(Node * N, int key) {
	N->key = key;
	while(N->parent != NULL && N->key > N->parent->key) {
		swapKeys(N, N->parent);
		N = N->parent;
	}
}
Node * binominalHeapDelete(Node * head, Node * N) {
	N->key = WINT_MAX;
	while(N->parent != NULL) {
		swapKeys(N, N->parent);
		N = N->parent;
	}
	return extractMax(head);
}
Node * searchBinominalHeapNode(Node * head, int key) {
    Node * tmp = NULL;

    if(head->key == key) {
        return head;
    }
    
    if(head->child != NULL) {
        tmp = searchBinominalHeapNode(head->child, key);
    }

    if(tmp->key == key) {
        return tmp;
    }

    if(head->sibling != NULL) {
        tmp = searchBinominalHeapNode(head->child, key);
    }

    return tmp;

}



