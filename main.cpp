#include <iostream>
#include <fstream>

using namespace std;

int length = 500;


struct Node{
    int value;
    int amount;
};

Node *array = new Node[length];

void sum_up(Node *arr1, Node *arr2){
    int current_node1 = 0;
    int current_node2 = 0;
    int current_value_in_node1 = 1;
    int current_value_in_node2 = 1;
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            cout << arr1[current_node1].value + arr2[current_node2].value << ' ';
            if(current_value_in_node1 == arr1[current_node1].amount){
                current_node1++;
                current_value_in_node1 = 1;
            } else {
                current_value_in_node1++;
            }
            if(current_value_in_node2 == arr2[current_node2].amount){
                current_node2++;
                current_value_in_node2 = 1;
            } else {
                current_value_in_node2++;
            }
        }
        cout << endl;
    }
}
void print_matrix(){
    int current_node = 0;
    int current_value_in_node = 1;
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            cout << array[current_node].value << ' ';
            if(current_value_in_node == array[current_node].amount){
                current_node++;
                current_value_in_node = 1;
            } else {
                current_value_in_node++;
            }
        }
        cout << endl;
    }
};

int main() {
    ifstream fin ("matrix.txt");
    int current_index = 0;
    while(!fin.eof()){
        int a = 0;
        int b = 0;
        int counter = 0;
        if(fin.eof()) break;
        while(b == 0 && !fin.eof()) {
            fin >> b;
            counter++;
        } ;
        Node* n = new Node;
        n->value = 0;
        n->amount = counter-1;
        array[current_index] = *n;
        current_index++;
        if(fin.eof()) break;
        Node* m = new Node;
        m->value = b;
        m->amount = 1;
        array[current_index] = *m;
        current_index++;
    }

    for (int i = 0; i < current_index; i++){
        cout << array[i].value << ' ' << array[i].amount << " times\n";
    }

//    print_matrix();
    sum_up(array, array);
}
