#include <iostream>
#include <cstdio>
using namespace std;

struct intNode {
    int data;
    intNode* prev;
    intNode* next;
    intNode(int p_data) {
        data = p_data;
        prev = nullptr;
        next = nullptr;
    }
};

struct listNode {
    intNode* data;
    listNode* prev;
    listNode* next;
    listNode(intNode* p_data) {
        data = p_data;
        prev = nullptr;
        next = nullptr;
    }
    listNode(listNode* parent) {
        intNode* source = parent->data;
        intNode* head = new intNode(source->data);
        source = source->prev;
        intNode* temp = head;
        while (source != nullptr) {
            intNode* currNode = new intNode(source->data);
            currNode->next = temp;
            temp->prev = currNode;
            temp = currNode;

            source = source->prev;
        }
        data = head;
        prev = nullptr;
        next = nullptr;
    }
    listNode* push_back(listNode* newNode) {
        this->prev = newNode;
        newNode->next = this;
        return newNode;
    }
};




intNode* readList() {
    int items = 0;
    cin >> items;
    int content = 0;
    cin >> content;
    intNode* prevNode = new intNode(content);
    intNode* currNode = nullptr;
    for (int i = 1; i < items; i++) {
        cin >> content;
        currNode = new intNode(content);
        currNode->next = prevNode;
        prevNode->prev = currNode;
        prevNode = currNode;
    }
    return currNode;
}

bool compareLists(listNode* thisNode, listNode* otherNode) {
    intNode* first = thisNode->data;
    intNode* second = otherNode->data;

    if (first->data != second->data) {
        return false;
    }
    while (first->prev != nullptr) {
        if (second->prev == nullptr) {
            return false;
        }
        first = first->prev;
        second = second->prev;
        if (first->data != second->data) {
            return false;
        }
    }
    return true;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int listsNumber = 0;
    cin >> listsNumber;
    listNode* head = new listNode(readList());
    for (int i = 1; i < listsNumber; i++) {
        listNode* temp = new listNode(readList());
        temp->next = head;
        head->prev = temp;
        head = temp;
    }

    //turnaround
    listNode* back = head;
    listNode* iter;
    while (head->next != nullptr) {
        intNode* temp = head->data;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        head->data = temp;
        head = head->next;
    }
    intNode* temp = head->data;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    head->data = temp;


    bool ind = false;
    cout << endl;
    iter = head;
    while (iter != nullptr) {
        intNode* temp = iter->data;
        int level = 0;
        cout << "(";
        while (temp != nullptr) {
            
            if (temp->data == 1 || temp->data == -1) {
                if (temp->data == -1)
                {
                    cout << "¬";
                }
                cout << char(int('a') + level);
                ind = true;
            }
            
            level++;
            temp = temp->prev;
        }
        cout << ")";
        iter = iter->prev;

        if (ind == true && iter != nullptr)
        {
            cout << "+";
        }
        ind = false;
    }
    cout<< endl;


    iter = head;
   
        while (iter != nullptr) {
            intNode* temp = iter->data;
            while (temp != nullptr) {
                if (temp->data == 0) {
                    temp->data = 1;
                    listNode* node = new listNode(iter);
                    back = back->push_back(node);
                    temp->data = -1;
                }
                temp = temp->prev;
            }
            iter = iter->prev;
        }
    
        iter = head;
        while (iter->prev != nullptr) {
            listNode* iter2 = iter->prev;
            while (iter2 != nullptr) {
                if (compareLists(iter, iter2)) {
                    if (iter->next == nullptr) {
                        head = iter->prev;
                        iter->prev->next = nullptr;
                        iter = head;
                    }
                    else {
                        iter->prev->next = iter->next;
                        iter->next->prev = iter->prev;
                    }

                    /*if (iter2->prev == nullptr) {
                        back = iter2->next;
                        iter2->next->prev = nullptr;
                        iter2 = back;
                    }
                    else if (iter2->next == nullptr) {
                        head = iter2->prev;
                        head->next = nullptr;
                    }
                    else {
                        iter2->prev->next = iter2->next;
                        iter2->next->prev = iter2->prev;
                    }*/
                    intNode* temp = new intNode(0);
                    listNode* tmp = new listNode(temp);
                    tmp->prev = head;
                    iter = tmp;
                    break;
                }
                iter2 = iter2->prev;
            }
            iter = iter->prev;
        }



    ind = false;
    cout << endl;
    iter = head;
    while (iter != nullptr) {
        intNode* temp = iter->data;
        int level = 0;
        cout << "(";
        while (temp != nullptr) {

            if (temp->data == 1 || temp->data == -1) {
                if (temp->data == -1)
                {
                    cout << "¬";
                }
                cout << char(int('a') + level);
                ind = true;
            }

            level++;
            temp = temp->prev;
        }
        cout << ")";
        iter = iter->prev;

        if (ind == true && iter != nullptr)
        {
            cout << "+";
        }
        ind = false;
    }
    cout << endl;

   
    iter = head;
    while (iter != nullptr) {
            intNode* temp = iter->data;
            while (temp != nullptr) {
                if (temp->data == -1) {
                    temp->data = 0;
                    listNode* node = new listNode(iter);
                    back = back->push_back(node);
                    temp->data = 1;
                }
                temp = temp->prev;
            }
            iter = iter->prev;
        }

 
    

     iter = head;
    while (iter->prev != nullptr) {
        listNode* iter2 = iter->prev;
        while (iter2 != nullptr) {
            if (compareLists(iter, iter2)) {
                if (iter->next == nullptr) {
                    head = iter->prev;
                    iter->prev->next = nullptr;
                    iter = head;
                }
                else {
                    iter->prev->next = iter->next;
                    iter->next->prev = iter->prev;
                }

                if (iter2->prev == nullptr) {
                    back = iter2->next;
                    iter2->next->prev = nullptr;
                    iter2 = back;
                }
                else if (iter2->next == nullptr) {
                    head = iter2->prev;
                    head->next = nullptr;
                }
                else {
                    iter2->prev->next = iter2->next;
                    iter2->next->prev = iter2->prev;
                }
                intNode* temp = new intNode(0);
                listNode* tmp = new listNode(temp);
                tmp->prev = head;
                iter = tmp;
                break;
            }
            iter2 = iter2->prev;
        }
        iter = iter->prev;
    }



    bool ending = false;
    bool ind0 = false;
    cout << endl;
    iter = head;
    while (iter != nullptr) {
        intNode* temp = iter->data;
        int level = 0;
        while (temp != nullptr) {
            if (temp->data == 1) {
                cout << char(int('a') + level);
                ending = false;
                ind0 = true;
            }
            level++;
            temp = temp->prev;
        }

        iter = iter->prev;

        if (ind0 == true && iter != nullptr)
        {
            cout << "+";
            ending = true;
        }
        ind0 = false;
    }
    if (ending) {
        cout << 1;
    }
    cout << endl;

    ////debug
    //while (head != nullptr) {
    //    intNode* temp = head->data;
    //    while (temp != nullptr) {
    //        cout << temp->data << " ";
    //        temp = temp->prev;
    //    }
    //    cout << endl;
    //    head = head->prev;
    //}


}

//(a¬b¬c)+(¬ab¬c)+(¬a¬bc)+(ab¬c)+(a¬bc)+(¬abc)
//(¬ab)+(a¬b)