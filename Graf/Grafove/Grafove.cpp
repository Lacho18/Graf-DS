#include <iostream>
#include<cmath>

const int Broi_Vurhove = 10;

struct Graf {
    char key;
    Graf* next;
} *Vurhove[Broi_Vurhove];

struct Opashka {
    char value;
    Opashka* next;
} *left, *right;

void Add_v_opashka(char key) {
    if (left == nullptr) {
        left = new Opashka;
        right = left;
        right->next = nullptr;
    }
    else {
        Opashka* p = left;
        while (p != right) {
            p = p->next;
        }
        Opashka* q = new Opashka;
        p->next = q;
        q->next = nullptr;
    }
}

void Delete_ot_opashka(int key) {
    if (left != nullptr) {
        if (left == right) {
            delete left;
            left = nullptr;
            right = nullptr;
        }
        else {
            Opashka* p = left;
            left = left->next;
            delete p;
        }
    }
}

void Inicializaciq(Graf* vrh[Broi_Vurhove]) {
    for (int i = 0; i < Broi_Vurhove; i++) {
        vrh[i] = nullptr;
    }
}

bool search_node(Graf* vrh[], char c) {
    bool flag = false;
    for (int i = 0; i < Broi_Vurhove; i++) {
        if (vrh[i]) {
            if (vrh[i]->key == c) {
                flag = true;
            }
        }
    }
    return flag;
}

bool search_duga(Graf* vrh[], char c1, char c2) {
    bool flag = false;
    if (search_node(vrh, c1) && search_node(vrh, c2)) {
        int i = 0;
        while (vrh[i]->key != c1) i++;
        Graf* p = vrh[i];
        while (p->key != c2 && p->next != nullptr) p = p->next;
        if (p->key == c2) flag = true;
    }
    return flag;
}

void Add_Vruh(Graf* vrh[], char c) {
    if (search_node(vrh, c)) {
        std::cout << "Vurhut veche sushtestvyva!" << std::endl;
    }
    else {
        int i = 0;
        while (vrh[i] && (i < Broi_Vurhove)) i++;
        if (vrh[i] == nullptr) {
            vrh[i] = new Graf;
            vrh[i]->key = c;
            vrh[i]->next = nullptr;
        }
        else {
            std::cout << "\nPrepulvane na structurata :(" << std::endl;
        }
    }
}

void Add_Duga(Graf* vrh[], char c1, char c2) {
    int i = 0;
    Graf* p = nullptr;
    if (search_duga(vrh, c1, c2)) {
        std::cout << "Dugata veche sushtestvyva!" << std::endl;
    }
    else {
        if (!search_node(vrh, c1)) Add_Vruh(vrh, c1);
        if (!search_node(vrh, c2)) Add_Vruh(vrh, c2);
        while (vrh[i]->key != c1) i++;
        p = new Graf;
        Graf* q = vrh[i];
        p->key = c2;
        while (q->next) {
            q = q->next;
        }
        q->next = p;
        p->next = nullptr;
        //p->next = vrh[i]->next;
        //vrh[i]->next = p;
    }
}

void Delete_Vruh(Graf* vrh[], char c) {
    if (search_node(vrh, c)) {
        int i = 0;
        while (vrh[i]->key != c) i++;
        Graf* p = nullptr, * q = nullptr;
        while (vrh[i] != nullptr) {
            p = vrh[i];
            vrh[i] = p->next;
            delete p;
        }
        for (i = 0; i < Broi_Vurhove; i++) {
            if (vrh[i]) {
                p = vrh[i];
                while ((p->key != c) && (p->next != nullptr)) {
                    q = p;
                    p = p->next;
                }
                if (p->key == c) {
                    q->next = p->next;
                    delete p;
                }
            }
        }
    }
}

void Delete_Duga(Graf* vrh[], char c1, char c2) {
    if (search_duga(vrh, c1, c2)) {
        int i = 0;
        while (vrh[i]->key != c1) i++;
        Graf* p = vrh[i], *q = nullptr;
        while (p->key != c2) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        delete p;
    }
    else {
        std::cout << "Nqma takava duga!" << std::endl;
    }
}

int convert(Graf* vrh[], char c1) {
    int i = 0;
    while (vrh[i]->key != c1) i++;
    return i;
}

void bfc(Graf* vrh[], char c1) {
    int m[10] = {};

    for (int i = 0; i < Broi_Vurhove; i++) {
        Add_v_opashka(c1);
    }
}

void dfs(Graf* vrh[], char c1, int m[]) {
    std::cout << c1 << " ";
    int j = convert(vrh, c1);
    m[j] = 1;
    for (Graf* t = vrh[j]->next; t != NULL; t = t->next) { 
        int h = convert(vrh, t->key); 
        if (m[h] == 0)
            dfs(vrh, t->key, m); 
    }
}


int main()
{
    Add_Vruh(Vurhove, 'A');
    Add_Vruh(Vurhove, 'B');
    Add_Vruh(Vurhove, 'C');
    Add_Vruh(Vurhove, 'D');
    
    Add_Duga(Vurhove, 'A', 'B');
    Add_Duga(Vurhove, 'A', 'C');
    Add_Duga(Vurhove, 'C', 'A');
    Add_Duga(Vurhove, 'B', 'C');
    Add_Duga(Vurhove, 'B', 'D');

    int masiv[10] = {};
    dfs(Vurhove, 'A', masiv);
}

