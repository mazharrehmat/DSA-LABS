#include <iostream>
using namespace std;

class node {
public:
    int playerid;
    int score;
    node* next;

    node(int id, int s) {
        playerid = id;
        score = s;
        next = NULL;
    }
};

class circulargame {
private:
    node* tail;
    node* current;

public:
    circulargame() {
        tail = NULL;
        current = NULL;
    }

    void addplayer(int id, int score) {
        node* newnode = new node(id, score);

        if (tail == NULL) {
            tail = newnode;
            tail->next = tail;
            current = tail;
        }
        else {
            newnode->next = tail->next;
            tail->next = newnode;
            tail = newnode;
        }

        cout << "player added -> id: " << id << " score: " << score << endl;
    }

    void displayplayers() {
        if (tail == NULL) {
            cout << "no players in the game." << endl;
            return;
        }

        node* temp = tail->next;

        cout << endl;
        cout << "players in the game:" << endl;

        do {
            cout << "player id: " << temp->playerid
                << "  score: " << temp->score << endl;

            temp = temp->next;

        } while (temp != tail->next);

        cout << endl;
    }

    void nextturn() {
        if (current == NULL) {
            cout << "no players available." << endl;
            return;
        }

        cout << "current turn -> player "
            << current->playerid << endl;

        current = current->next;
    }

    void skipplayer() {
        if (current == NULL) {
            cout << "no players available." << endl;
            return;
        }

        cout << "player " << current->playerid
            << " is skipped." << endl;

        current = current->next;

        cout << "next turn -> player "
            << current->playerid << endl;

        current = current->next;
    }

    void removeplayer(int id) {
        if (tail == NULL) {
            cout << "no players in the game." << endl;
            return;
        }

        node* curr = tail->next;
        node* prev = tail;

        do {
            if (curr->playerid == id) {

                if (curr == tail && curr->next == tail) {
                    cout << "player " << id
                        << " removed from the game." << endl;

                    delete curr;
                    tail = NULL;
                    current = NULL;
                    return;
                }

                prev->next = curr->next;

                if (curr == tail) {
                    tail = prev;
                }

                if (current == curr) {
                    current = curr->next;
                }

                cout << "player " << id
                    << " removed from the game." << endl;

                delete curr;
                return;
            }

            prev = curr;
            curr = curr->next;

        } while (curr != tail->next);

        cout << "player not found." << endl;
    }

    void checkwinner() {
        if (tail != NULL && tail->next == tail) {
            cout << endl;
            cout << "game over!" << endl;
            cout << "winner is player "
                << tail->playerid << endl;
        }
    }
};

int main() {
    circulargame g;

    g.addplayer(1, 100);
    g.addplayer(2, 150);
    g.addplayer(3, 200);
    g.addplayer(4, 120);

    g.displayplayers();

    cout << "moving turns:" << endl;

    g.nextturn();
    g.nextturn();

    cout << endl;
    cout << "skipping a player:" << endl;

    g.skipplayer();

    cout << endl;
    g.removeplayer(2);

    g.displayplayers();

    g.removeplayer(3);
    g.removeplayer(4);

    g.displayplayers();

    g.checkwinner();

    return 0;
}