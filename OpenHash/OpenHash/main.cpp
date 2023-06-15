//#include <iostream>
//#include "openHash.h"
//
//int main() {
//
//    int elem_num;
//    cout << "Please input the nums of the hash_table";
//    cin >> elem_num;
//    int key[elem_num];
//    cout << "Please input the data";
//    for(int i = 0; i < elem_num; i++)
//    {
//        int key_temp;
//        cin >> key_temp;
//        key[i] = key_temp;
//    }7
//    int divide;
//    cout << "please input the number you want divide";
//    cin >> divide;
//    OpenHash<int> hash_table(key,elem_num,divide);
//
//}


#include "openHash.h"
int main()
{
    int b[] = { 1,2,3 };
    OpenHash<int> hash(b, 3, 2);
    hash.show_hash();
    return 0;
}