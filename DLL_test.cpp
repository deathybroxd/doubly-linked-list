// this is the DLL test file

#include <iostream>
#include <string>
#include "dll.h"

// testing consts
const int A = 1;
const int B = 2;
const int C = 3;
const int D = 4;
const std::string line(50, '-');

// pass/fail amounts:
int pass = 0;
int fail = 0;

void check(const std::string& label, bool condition) {
    if(condition) {
        std::cout << label << ": PASS" << std::endl;
    } else {
        std::cout << label << ": FAIL" << std::endl;
    }
}
int main() {
    /////////////////////   test 1    ////////////////////////////////////
    std::cout << line << std::endl;
    std::cout << "test 1: default constructor and IsEmpty" << std::endl;
    DLL<int> list1;
    check("new DLL = IsEmpty() check: ", list1.IsEmpty());
    check("Size() should = 0: ", list1.Size() == 0);
    std::cout << "test 1 over " << std::endl;
    std::cout << line << std::endl;
    
    /////////////////////   test 2    ////////////////////////////////////
    std::cout << line << std::endl;
    std::cout << "test 2: PushBack() and Display()" << std::endl;
    list1.PushBack(A);
    list1.PushBack(B);
    list1.PushBack(C);
    list1.PushBack(D);
    std::cout << "should output 1->2->3->4: " << std::endl;
    list1.Display();
    check("Size() should be 4: ", list1.Size() == 4);
    std::cout << "test 2 over " << std::endl;
    std::cout << line << std::endl;

    /////////////////////   test 3    ////////////////////////////////////
    std::cout << line << std::endl;
    std::cout << "test 3: Pop()" << std::endl;
    int front = list1.Pop();
    check("Should have popped 1: ", front == A);
    check("Size() should be 3: ", list1.Size());
    std::cout << "display should now show 2->3->4: " << std::endl;
    list1.Display();
    std::cout << "end test 3" << std::endl;
    std::cout << line << std::endl;

    /////////////////////   test 4    ////////////////////////////////////
    std::cout << line << std::endl;
    std::cout << "test 4: PushFront()" << std::endl;
    list1.PushFront(A);
    list1.PushFront(D);
    std::cout << "List should now be 4->1->2->3->4" << std::endl;
    list1.Display();
    check("Size() should be 5", list1.Size() == 5);
    std::cout << "end test 4" << std::endl;
    std::cout << line << std::endl;

    /////////////////////   test 5    ////////////////////////////////////
    std::cout << line << std::endl;
    std::cout << "test 5: Peek()" << std::endl;
    int peek = list1.Peek();
    check("Peek() should be 4: ", peek == D);
    check("Size is still 5: ", list1.Size());
    std::cout << "end test 5" << std::endl;
    std::cout << line << std::endl;

    /////////////////////   test 6    ////////////////////////////////////
    std::cout << line << std::endl;
    std::cout << "test 5: GetAt()" << std::endl;
    check("GetAt(1) should be 4: ", list1.GetAt(1) == D);
    check("GetAt(2) should be 1: ", list1.GetAt(2) == A);
    check("GetAt(3) should be 2: ", list1.GetAt(3) == B);
    check("GetAt(4) should be 3: ", list1.GetAt(4) == C);
    check("GetAt(5) should be 4: ", list1.GetAt(5) == D);
    check("Size is still 5: ", list1.Size());
    std::cout << "end test 6" << std::endl;
    std::cout << line << std::endl;

    /////////////////////   test 7    ////////////////////////////////////
    std::cout << line << std::endl;
    std::cout << "test 7: RemoveAt()" << std::endl;
    check("RemoveAt(1) should return 4: ", list1.RemoveAt(1) == D);
    std::cout << "List should now be 1->2->3->4: " << std::endl;
    list1.Display();
    check("RemoveAt(4) should return 4", list1.RemoveAt(4) == D);
    std::cout << "List should now be 1->2->3: " << std::endl;
    list1.Display();
    std::cout << "RemoveAt(1) x 3: " << std::endl;
    for(int i = 0; i < 3; i++) {
        list1.RemoveAt(1);
    }
    std::cout << "List should now be empty and size 0: " << std::endl;
    list1.Display();
    check("Size() == 0: ", list1.Size() == 0);
    std::cout << "end test 7" << std::endl;
    std::cout << line << std::endl;

    /////////////////////   test 8    ////////////////////////////////////
    std::cout << line << std::endl;
    std::cout << "test 8: copy constructor" << std::endl;
    std::cout << "adding back 1, 2, 3, 4: " << std::endl;
    list1.PushBack(A);
    list1.PushBack(B);
    list1.PushBack(C);
    list1.PushBack(D);
    list1.Display();
    std::cout << "copying list1 into list2: DLL<int> list2(list1);" << std::endl;
    DLL<int> list2(list1);
    std::cout << "list2 should be the same as list1: " << std::endl;
    list2.Display();
    check("sizes should equal 4: ", list1.Size() == list2.Size());
    std::cout << "address of the lists should differ: " << std::endl;
    std::cout << "list1: " << &list1 << std::endl;
    std::cout << "list2: " << &list2 << std::endl;
    check("result: ", &list1 != &list2);
    std::cout << "end test 8" << std::endl;
    std::cout << line << std::endl;
    
    /////////////////////   test 9    ////////////////////////////////////
    std::cout << line << std::endl;
    std::cout << "test 9: assignment operator" << std::endl;
    DLL<int> list3;
    list3 = list1; // list1 = 1->2->3->4
    std::cout << "list3 should equal 1->2->3->4" << std::endl;
    list3.Display();
    check("size should be equal to list1: ", list1.Size() == list3.Size());
    std::cout << "list3.Pop(), should equal 2->3->4: " << std::endl;
    list3.Pop();
    list3.Display();
    check("After using Pop, size should equal 3: ", list3.Size() == 3);
    check("list3 should not equal the size of list1", list1.Size() != list3.Size());
    list3 = list3;
    check("self assignment check (list3 = list3), size should equal 3: ", list3.Size() == 3);
    std::cout << "end test 9 " << std::endl;

    /////////////////////   test 10    ////////////////////////////////////
    std::cout << line << std::endl;
    std::cout << "test 10: Clear() and other types" << std::endl;
    DLL<std::string> list4;
    list4.Pop();
    check("empty pop test, should have printed an error: ", list4.IsEmpty());
    list4.PushBack("tf2");
    list4.PushBack("portal 2");
    list4.PushBack("csgo");
    std::cout << "list4 should = tf2->portal 2->csgo" << std::endl;
    list4.Display();
    check("after pushing back 3 strings size should be 3: ", list4.Size() == 3);
    list4.Clear();
    check("list4 after clear() should be size 0: ", list4.Size() == 0);
    check("list4 after IsEmpty() should be true ", list4.IsEmpty());
    
    


    return 0;
}