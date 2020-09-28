#include"List.h"

using namespace std;

int main()
{

    List <int> list;
    list.push_back(984);
    list.push_back(6);
    list.push_back(74);
    list.push_back(53);
    list.push_back(89);
    list.push_back(31);
    list.print_forward();
    list.print_backward();
    cout << endl;

    cout << "insert:" << endl;
    list.insert(100, 2);
    list.print_forward();
    list.print_backward();
    cout << endl;

    cout << "del:" << endl;
    list.del(5);
    list.print_forward();
    list.print_backward();
    cout << endl;

    cout << "push_front:" << endl;
    list.push_front(17);
    list.print_forward();
    list.print_backward();
    cout << endl;
    
    cout << "List(const List<T>& obj): " << endl;
    List<int>copy_list = list;
    copy_list.print_forward();
    list.print_forward();
    cout << endl;

    cout << "operator=(const List<T>& obj):" << endl;
    List<int>copy_list2;
    copy_list2.push_front(432);
    copy_list2.push_front(864);
    copy_list2.push_front(973);
    copy_list2.print_forward();
    copy_list2 = list;
    copy_list2.print_forward();
    list.print_forward();
    cout << endl;
        
    cout << "operator=(List<T>&& obj):" << endl;
    copy_list2 = move(list); 
    //copy_list2.sort_min_to_max();
    //copy_list2.sort_max_to_min();
    copy_list2.print_forward();
    copy_list2.print_backward();
    cout << endl;

    cout << "void List<T>::sort_min_to_max():" << endl;
    copy_list2.sort_min_to_max();
    copy_list2.print_forward();
    copy_list2.print_backward();
    cout << endl;

    cout << "void List<T>::sort_max_to_min():" << endl;
    copy_list2.sort_max_to_min();
    copy_list2.print_forward();
    copy_list2.print_backward();
    cout << endl;
}

