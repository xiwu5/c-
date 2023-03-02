class LinkedList {
private:
    struct Node {
        int data;
        Node *next;
    };
    
    Node *head;
    
public:
    LinkedList(int);   // constructor
    ~LinkedList();  // destructor
    bool swap(int, int);
    int count;
};

LinkedList::LinkedList(int count) {
    head = new Node; // head points to the sentinel node
    head->next = nullptr;
    this->count = count;
}


bool LinkedList::swap(int first, int second) {
    // make sure first is smaller than second
    if (second > first) {
        int tmp = first;
        first = second;
        second = tmp;
    }
    
    if ((count < second) || (first <= 0) || (second <= 0) || (first == second)) {
        return false;
    }
    
    // Search for first (keep track of prevX and CurrX
    int i = 1;
    Node *prevX = head, *currX = head->next;
    while (currX && i != first)
    {
        prevX = currX;
        currX = currX->next;
        i++;
    }
    
    // Search for second (keep track of prevY and CurrY
    i = 1;
    Node *prevY = head, *currY = head->next;
    while (currY && i != second)
    {
        prevY = currY;
        currY = currY->next;
        i++;
    }
    
    // change next of the previous nodes of the swapped nodes
    prevX->next = currY;
    prevY->next = currX;
    
    // change next of the nodes being swapped
    Node* tmp = currY->next;
    currY->next = currX->next;
    currX->next = tmp;
    
    return true;
}
