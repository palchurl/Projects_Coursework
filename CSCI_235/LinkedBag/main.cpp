#include <iostream>
using namespace std;
#include "DoublyLinkedList.hpp"
//#include "LinkedBag.h"
//AKS ABT getHEADPTR
int main()
{
    DoublyLinkedList<int> ll;
    ll.insert(94,1);
    
    /*DoublyLinkedList<int> dll;
    dll.insert(66, 1);
    dll.insert(1, 2);
    dll.insert(69, 3);
    dll.insert(2, 4);
    dll.insert(85, 5);
    dll.insert(3, 6);
    dll.insert(14, 7);
    dll.insert(10000, 8);
    dll.insert(32, 9);
    dll.insert(100082390, 10);
    cout << "insert: ";
    dll.display();
    cout << endl; 

    DoublyLinkedList<char> s1;
    s1.insert('z', 1);
    s1.insert('y', 2);
    s1.insert('x', 3);
    s1.insert('w', 4);
    s1.insert('v', 5);
    s1.insert('u', 6);
    s1.insert('t', 7);
    cout << "insert: ";
    s1.display();
    cout << endl; 
    cout << "getAPos pos 1 : ";
    cout << s1.getAtPos(1)->getItem() << endl;
    cout << "getAPos pos 4 : ";
    cout << s1.getAtPos(4)->getItem() << endl;
    cout << "getAPos pos 7 : ";
    cout << s1.getAtPos(7)->getItem() << endl;

    DoublyLinkedList<int> ll;
    ll.insert(10, 1);
    ll.insert(20, 2);
    ll.insert(30, 3);
    ll.insert(40, 4);
    
    
    cout << "Testing Interleave L1          :  ";
    ll.display();
    cout << endl;

    DoublyLinkedList<int> dlll;
    dlll.insert(1, 1);
    dlll.insert(2, 2);
    dlll.insert(3, 3);
    dlll.insert(4, 4);
    dlll.insert(5, 5);
    dlll.insert(6, 6);
    dlll.insert(9, 7);

    cout << "Testing Interleave L2          :  ";
    dlll.display();
    cout << endl;

    DoublyLinkedList<int> result = ll.interleave(dlll);
    cout << "Testing Interleave result      :  ";
    result.display();
    cout << endl;*/

    /*//TESTS GRADESCOPE INSERT AND DISPLAY
    DoublyLinkedList<int> dll;
    dll.insert(66, 1);
    dll.insert(1, 2);
    dll.insert(69, 3);
    dll.insert(2, 4);
    dll.insert(85, 5);
    dll.insert(3, 6);
    dll.insert(14, 7);
    dll.insert(10000, 8);
    dll.insert(32, 9);
    dll.insert(100082390, 10);
    cout << "insert: ";
    dll.display();
    cout << endl; 
    
    
    //z, y, x, w, v, u, t
    DoublyLinkedList<char> s1;
    s1.insert('z', 1);
    s1.insert('y', 2);
    s1.insert('x', 3);
    s1.insert('w', 4);
    s1.insert('v', 5);
    s1.insert('u', 6);
    s1.insert('t', 7;

    cout << "getAPos pos 2 : ";
    cout << dll.getAtPos(4)->getItem() << endl;*/
    

    /*  //TESTS GRADESCOPE REVOVE AND DISPLAY BACKWARDS
    DoublyLinkedList<string> s;
    s.insert("uno", 1);
    s.insert("dos", 2);
    s.insert("tres", 3);
    s.insert("quatro", 4);
    cout << "insert: ";
    s.display();
    cout << endl;

    DoublyLinkedList<string> s2;
    s2.insert("a", 1);
    s2.insert("b", 2);
    s2.insert("c", 3);
    cout << "display backwards: ";
    s2.displayBackwards();

    cout  << endl;
    s.remove(4);
    s.display();
    cout  << endl;
    s.remove(1);
    s.display();
    cout  << endl;
    s.remove(2);
    s.display();
    cout  << endl;
    */


    /* TESTS INTERLEAVE 
    DoublyLinkedList<int> ll;
    ll.insert(10, 1);
    ll.insert(20, 2);
    ll.insert(30, 3);
    ll.insert(40, 4);
    cout << "Testing Interleave L1          :  ";
    ll.display();
    cout << endl;

    DoublyLinkedList<int> dll;
    dll.insert(1, 1);
    dll.insert(2, 2);
    dll.insert(3, 3);
    dll.insert(4, 4);
    cout << "Testing Interleave L2          :  ";
    dll.display();
    cout << endl;

    DoublyLinkedList<int> result = ll.interleave(dll);
    cout << "Testing Interleave result      :  ";
    result.display();
    cout << endl;*/
    

    /*cout << "Testing Insert head condition:  ";
    ll.insert(10, 1);
    ll.display();
    cout << endl << endl;

    cout << "Testing Insert tail condition:  ";
    ll.insert(30, 2);
    ll.display();
    cout << endl << endl;

    cout << "Testing Insert middle conditi:  ";
    ll.insert(20, 2);
    ll.display();
    cout << endl << endl;

    cout << "Testing Insert tail condition:  ";
    ll.insert(40, 4);
    ll.display();
    cout << endl << endl;

    cout << "Testing Insert tail condition:  ";
    ll.insert(50, 5);
    ll.display();
    cout << endl << endl;

    cout << "Testing Insert tail condition:  ";
    ll.insert(60, 6);
    ll.display();
    cout << endl << endl;

    cout << "Testing Insert tail condition:  ";
    ll.insert(70, 7);
    ll.display();
    cout << endl << endl;

    cout << "Testing Insert tail condition:  ";
    ll.insert(80, 8);
    ll.display();
    cout << endl << endl;

    cout << "Testing Insert tail condition:  ";
    ll.insert(90, 9);
    ll.display();
    cout << endl << endl;

    cout << "Testing Insert tail condition:  ";
    ll.insert(100, 10);
    ll.display();
    cout << endl << endl;

    cout << "Testing remove head condition:  ";
    ll.remove(1);
    ll.display();
    cout << endl << endl;

    cout << "Testing remove tail condition:  ";
    ll.remove(1);
    ll.display();
    cout << endl << endl;
    cout << "Testing Reverse Print        :  ";
    ll.displayBackwards();
    cout << endl;
    cout << "Testing Insert head condition:  ";
    ll.remove(1);
    ll.display();
    cout << endl << endl;
    cout << "Testing CLEAR                :  ";
    ll.insert(100, 4);
    ll.clear();
    ll.display();
    cout << endl << endl;
    cout << "Testing Insert2              :  ";
    ll.insert(90, 1);
    ll.display();
    cout << endl << endl;
    cout << "getAtPos                     :  ";
    cout << ll.getAtPos(2)->getItem() << endl << endl;
    

    cout << "Testing remove head          :  ";
    ll.remove(1);
    ll.display();
    cout << endl << endl;

    cout << "Testing remove tail          :  ";
    ll.remove(5);
    ll.display();
    cout << endl << endl;
    
    cout << "Testing remove middle        :  ";
    ll.remove(3);
    ll.display();
    cout << endl << endl;

    
    */


    return 0;
}

/*
 
    LinkedBag<int> ll;
    ll.add(10); 
    ll.add(20); 
    ll.add(30); 

    cout << "current size: " << ll.getCurrentSize() << endl;

    cout << ll.getCurrentSize();

    cout << endl << "After delete: ";
    ll.deleteSecondNode();
    cout << ll.getCurrentSize()<<endl;

    cout << endl << "Iterative get current size: ";
    cout << ll.getCurrentSize();

    
    cout << endl << "Recursive get current size: ";
    cout << ll.getCurrentSizeRecursive();

    ll.add(90); 
    cout << endl << "again Recursive get current size: ";
    cout << ll.getCurrentSizeRecursive() << endl;

    cout << endl<< "remove random : ";
    cout << ll.removeRandom() << endl;

    ll.add(100); 
    cout << endl << "Recursive get current size: ";
    cout << ll.getCurrentSizeRecursive();

    cout << endl<< "remove random : ";
    cout << ll.removeRandom() << endl;


    cout << "current size: " << ll.getCurrentSize() << endl;
_________________

Iterative
int getCount(Node* head)  
{  
    int count = 0; // Initialize count  
    Node* current = head; // Initialize current  
    while (current != NULL)  
    {  
        count++;  
        current = current->next;  
    }  
    return count;  
}  
  
Recursive
int getCount(struct Node* head) 
{ 
    // Base case 
    if (head == NULL) 
        return 0; 
  
    // count is 1 + count of remaining list 
    return 1 + getCount(head->next); 
} 

Random
public void removeRandomElement() {
        int index = new Random().nextInt(size);
        Node current = head;
        Node prev = head;
        for (int i = 0; i < index; i++) 
        {
            prev = current;
            current = current.next;
        }
        prev.next = current.next;
        current.next = null;
        size--;
    }
*/

