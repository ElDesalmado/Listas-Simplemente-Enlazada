
#include <iostream>
using namespace std;

struct Node {
    int dato;
    Node* next;
};

void addEnd(Node*& head, int dato) {

    Node* newnode = new Node;
    newnode->dato = dato;
    newnode->next = nullptr;

    if (head == nullptr) {
        head = newnode;
    }
    else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void addInicio(Node*& head, int dato) {
    Node* newnode = new Node;
    newnode->dato = dato;
    newnode->next = nullptr;

    Node* temp = head;

    head = newnode;
    head->next = temp;
}

void imprimirList(Node*& head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->dato << " ";
        temp = temp->next;
    }
}

void agregarAntDesp(Node* head, int valor1, int valor2, int valor3) {

    Node* newnode = new Node;
    newnode->dato = valor1;
    newnode->next = nullptr;

    if (valor3 == 0) { //agregar antes
        Node* temp1 = head;
        Node* temp2 = head;


        if (temp1->dato == valor2) {
            newnode->next = head;
            head = newnode;

        }else {
            int cont = 0;
            while (temp1->dato != valor2) {
                temp1 = temp1->next;
                cont++;
            }

            for (int i = 0; i < cont - 1; i++) {
                temp2 = temp2->next;
            }

            temp2->next = newnode;
            newnode->next = temp1;
        }
    }
    else {  //agregar depues
        Node* temp1 = head;
        Node* temp2 = head;


        if (temp1->dato == valor2) { //Si es el primer nodo
            temp2 = temp2->next;
            
            temp1->next = newnode;
            newnode->next = temp2;
        }
        else {
            int cont = 0;
            while (temp1->dato != valor2) {
                temp1 = temp1->next;
                cont++;
            }

            for (int i = 0; i < cont + 1; i++) {
                temp2 = temp2->next;
            }

            temp1->next = newnode;
            newnode->next = temp2;
        }
    }
}

int main()  {
    
    int n, m, o;
    Node* head = nullptr;

    cout << "Ingrese n de listas: "; cin >> n;
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << "Ingrese el " << i + 1 << " dato: ";
        cin >> m;
        addEnd(head, m);
    }

    system("cls");
    do {
        system("cls");
        cout << endl;
        cout << "            MENU             " << endl;
        cout << endl;
        cout << "1. Agregar al inicio" << endl;
        cout << "2. Agregar al final" << endl;
        cout << "3. Imprimir Lista" << endl;
        cout << "4. Agregar numero despues de" << endl;
        cout << "5. Agregar numero antes de" << endl;
        cout << endl << "\t\t";
        cin >> o;

        switch (o) {
        case 1:
            system("cls");
            int x;
            cout << "Ingrese el nuevo dato: "; cin >> x;
            addInicio(head, x);
            cout << endl;
            cout << "Numero correctamente registrado";
            break;

        case 2:
            system("cls");
            int z;
            cout << "Ingrese el nuevo dato: "; cin >> z;
            addEnd(head, z);
            cout << endl;
            cout << "Numero correctamente registrado";
            break;

        case 3:
            system("cls");
            cout << endl << "\t";

            imprimirList(head);
            cout << endl;

            system("pause");
            break;

        case 4:
            system("cls");
            int g,q;
            cout << "Numero a ingresar: "; cin >> g;
            cout << "Despues del numero: "; cin >> q;
            agregarAntDesp(head, g, q, 1);
            cout << endl;
            system("pause");
            break;

        case 5:
            system("cls");
            int a, b;
            cout << "Numero a ingresar: "; cin >> a;
            cout << "Antes del numero : "; cin >> b;
            agregarAntDesp(head, a, b, 0);
            cout << endl;
            system("pause");
            break;
        }
    } while (o != 6);

}
