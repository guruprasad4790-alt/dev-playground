// Linked List Core Interview Toolkit
// reverse, middle, cycle detection, deletion

struct Node
{
    int val;
    Node* next;
};

Node* reverse(Node* head)
{
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    while (curr!=nullptr)
    {
        //save next;
        next = curr->next;
        // make current next point to prev
        curr->next = prev;
        // keep moving prev with curr
        prev = curr;
        //move curr with saved next
        curr = next;
    }

    return prev;
}

Node* middle(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while ((fast!=nullptr) && (fast->next!=nullptr))
    {
        slow = slow->next;
        fast = (fast->next)->next;
    }
    return slow;
}

Node* firstMiddle(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while ((fast->next!=nullptr) && (fast->next)->next!=nullptr)
    {
        slow = slow->next;
        fast = (fast->next)->next;
    }
    return slow;
}

bool hasCycle(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while ( fast!=nullptr && (fast->next)!= nullptr )
    {
        slow = slow->next;
        fast = (fast->next)->next;
        if (slow == fast)
            return true;
    }
    return false;
}

Node* cycleStart(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while ( fast!=nullptr && (fast->next)!= nullptr )
    {
        slow = slow->next;
        fast = (fast->next)->next;
        if (slow == fast)
            break;
    }
    if(slow!=fast) // no loop
        return nullptr;
    
    //has loop
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

Node* deleteKey(Node* head, int key)
{
    //adding a dummy head to prevent head delete scenario
    
    Node* dummy = new Node();
    dummy->next = head;
    Node* curr = dummy;
    Node* temp = nullptr;

    while(curr->next!= nullptr)
    {
        if(curr->next->val == key)
        {
            temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            temp = nullptr;
        }
        else
        {
            curr = curr->next;
        }
    }
    temp = dummy;
    Node* newHead = dummy->next;
    delete dummy;
    dummy = nullptr;

    return newHead;

}
