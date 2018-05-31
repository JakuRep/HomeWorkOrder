
template <typename T>
class LinkedList {
private:
    struct Node {
        T * item;
        Node * next;
        int key;
        Node() {
            item = NULL;
            next = NULL;
            key = 0;
        }
        Node(T * item, int key) {
            this->item = item;
            this->key = key;
            this->next = NULL;
        }

    };
    Node * head;
    Node * tail;
public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insert(T * item, int key) {
        if(head == NULL) {
            head = new Node(item, key);
            tail = head;

        } else {
            tail->next = new Node(item, key);
            tail = tail->next;
        }
    }
    T * search(int key) {

        Node * crawler = head;
        bool isFound = false;

        while(crawler != NULL && isFound == false) {

            if(crawler->key == key) {
                isFound = true;
            } else {
                crawler = crawler->next;
            }

        }

        if(isFound) {
            return crawler->item;
        } else {
            return NULL;
        }


    }
    void remove(int key) {

        bool isDeleted = false;

        if(head != NULL) {
            if(head == tail) {
                if(head->key == key) {
                    delete head;
                    isDeleted = true;
                    head = tail = NULL;
                }
            }
            else {
                if(head->key == key) {
                    Node * tmp = head;
                    head = head->next;
                    delete tmp;
                    isDeleted = true;
                }
                else {
                    Node * crawler = head;

                    while(crawler->next != NULL) {
                        if(crawler->next->key == key) {
                            Node * tmp;

                            if(crawler->next == tail) {
                                tail = crawler;
                            }

                            tmp = crawler->next;
                            crawler->next = crawler->next->next;
                            delete tmp;
                            isDeleted = true;
                        }
                        else {
                            crawler = crawler->next;
                        }
                    }
                }
            }
        }
        if(isDeleted == false) {
            //error
        }

    }
    T* pop(int key) {
        bool isDeleted = false;

        if(head != NULL) {
            if(head == tail) {
                if(head->key == key) {
                    T * tmp = head->item;
                    head = tail = NULL;
                    return tmp;
                }
            }
            else {
                if(head->key == key) {
                    T * tmp = head->item;
                    head = head->next;
                    return tmp;

                }
                else {
                    Node * crawler = head;

                    while(crawler->next != NULL) {
                        if(crawler->next->key == key) {

                            if(crawler->next == tail) {
                                tail = crawler;
                            }

                            T * tmp = crawler->next->item;
                            crawler->next = crawler->next->next;
                            return tmp;

                        }
                        else {
                            crawler = crawler->next;
                        }
                    }
                }
            }
        }
        if(isDeleted == false) {
            //error
        }
    }
	T * popFront() {
        if(head != NULL) {
            Node * tmp = head;
            T * item = tmp->item;
            if(head == tail) {
                head = tail = NULL;
            } else {
                head = head->next;
            }
            delete tmp;
            return item;
        }
    };
    T * popTail() {
        if(tail != NULL) {
            Node * crawler = head;
            if(crawler != NULL) {
                if(crawler == tail) {
                    head = tail = NULL;
                    T * tmp = crawler->item;
                    delete crawler;
                    return tmp;
                } else {
                    while(crawler->next != tail) {
                        crawler = crawler->next;
                    }
                    tail = crawler;
                    crawler = crawler->next;
                    tail->next = NULL;
                    T * item = crawler->item;
                    delete crawler;
                    return item;
                }
            }
        }
    }
    void print() {
        Node * crawler = head;

        while(crawler != NULL) {
            std::cout << crawler->key << " ";
        }

        std::cout << std::endl;
    }
	Node * getHead() {
		return head;
		
	}
	Node * getTail() {
	return tail;
}
};
