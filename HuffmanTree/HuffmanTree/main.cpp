#include <iostream>
#include "HuffmanTree.h"

int main(int argc, const char * argv[]) {
    HuffmanTree<int> huffman_tree;
    huffman_tree.init();
    cin.ignore(INT_MAX, '\n');
    while (getchar() != '\n') {
        continue;
    }
    huffman_tree.print_key_value();
    cout << "aaaaaaaaaaa" << endl;
    cin.ignore(INT_MAX, '\n');
    huffman_tree.encoding();
}
// ABCDEFGHIJKLMNOPQRSTUVWXYZ
//186 64 13 22 32 103 21 15 47 57 1 5 32 20 57 63 15 1 48 51 80 23 8 18 16 1
//THIS PROGRAM IS MY FAVORITE