#include <iostream>

const int BroiVurhove = 4;

int matrica[5][5] = {};

struct Graf {
    int vruh;
    Graf* next;
} *masivOtvurhove[BroiVurhove], * start;

void Add_v_kraq(Graf* start, int value) {
    Graf* p = start;
    while (p->next) {
        p = p->next;
    }
    Graf* q = new Graf;
    q->vruh = value;
    p->next = q;
    q->next = nullptr;
}

void GrafIniticialisation(Graf* masiv[]) {
    for (int i = 0; i < BroiVurhove; i++) {
        masiv[i] = nullptr;
    }
}

bool searc_for_vruh(Graf* vurhove[], int vruh) {
    for (int i = 0; i < BroiVurhove; i++) {
        if (vurhove[i]) {
            if (vurhove[i]->vruh == vruh) {
                return true;
            }
        }
    }
    return false;
}

bool search_for_duga(Graf* vurhove[], int vruh1, int vruh2) {
    if (searc_for_vruh(vurhove, vruh1) && searc_for_vruh(vurhove, vruh2)) {
        int i = 0;
        while (vurhove[i]->vruh != vruh1)  i++;
        Graf* p = vurhove[i];
        while (p->vruh != vruh2 && p->next != nullptr) {
            p = p->next;
        }
        if (p->vruh == vruh2) {
            return true;
        }
        return false;
    }
}

void AddEdge(int i, int j) {
    matrica[i][j] = 1;
    matrica[j][i] = 1;
}

void RemoveEdge(int i, int j) {
    matrica[i][j] = 0;
    matrica[j][i] = 0;
}

bool HasEdge(int i, int j) {
    if (matrica[i][j] == 1) {
        return true;
    }
    return false;
}

void NameriSusedite(int i, int n) {
    for (i = 0; i < n; i++) {
        if (matrica[i][n] == 1) {
            Add_v_kraq(start, i);
        }
    }
}

 int main()
 {
        AddEdge(1, 2);
        AddEdge(1, 3);
        AddEdge(0, 1);
        AddEdge(2, 3);
        AddEdge(3, 4);

        int N = 0;
        std::cin >> N;

        return 0;
  }

