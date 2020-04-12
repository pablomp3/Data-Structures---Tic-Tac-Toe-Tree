#include <iostream>

using namespace std;

#include <iostream>

using namespace std;
typedef int Dato;

class DoubleNode{
protected:

    //DoubleNode* backward;

public:
    Dato id;
    Dato parent_id;
    Dato pos_x;
    Dato pos_y;
    char dato;
    DoubleNode* first;
    DoubleNode* second;

    DoubleNode(Dato iden, Dato parent_iden, Dato posx, Dato posy, char t)
    {
        this->id = iden;
        this->parent_id = parent_iden;
        this->pos_x = posx;
        this->pos_y = posy;
        this->dato = t;
        this->first = this->second = NULL;//this->backward = NULL;
    }

    Dato Nodedato() const{return dato;}

    DoubleNode* firstchild() {
        return this->first;
    }
    DoubleNode* secondchild() {
        return this->second;
    }

    void putfirst(DoubleNode* a){
        this->first = a;
    }
    void putsecond(DoubleNode* a){
        this->second = a;
    }

friend class Tree;
};

// -------------------- Global variable --------------------
DoubleNode *root;
DoubleNode *aux;
int visited_id[100];
char arr_data[100];
char board[3][3] = {{'_','_','_'},
                    {'_','_','_'},
                    {'_','_','_'}};
int arr_posx[100];
int arr_posy[100];
int visit_index = 0;
int ind = 0;
int pos_i = 0;
bool path_found = 0;
// ---------------------------------------------------------
void print_board(char board[3][3]){
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cout << board[i][j];
            if (j!=2) cout << " ";
        }
        cout << endl;
    }
}

void reset_board(char board[3][3]){
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            board[i][j] = '_';
        }
    }
}

int check_board(char board[3][3]){
    if ((board[0][0]=='X' and board[1][0]=='X' and board[2][0]=='X') or
        (board[0][0]=='O' and board[1][0]=='O' and board[2][0]=='O') or
        (board[0][1]=='X' and board[1][1]=='X' and board[2][1]=='X') or
        (board[0][1]=='O' and board[1][1]=='O' and board[2][1]=='O') or
        (board[0][2]=='X' and board[1][2]=='X' and board[2][2]=='X') or
        (board[0][2]=='O' and board[1][2]=='O' and board[2][2]=='O') or
        (board[0][0]=='X' and board[0][1]=='X' and board[0][2]=='X') or
        (board[0][0]=='O' and board[0][1]=='O' and board[0][2]=='O') or
        (board[1][0]=='X' and board[1][1]=='X' and board[1][2]=='X') or
        (board[1][0]=='O' and board[1][1]=='O' and board[1][2]=='O') or
        (board[2][0]=='X' and board[2][1]=='X' and board[2][2]=='X') or
        (board[2][0]=='O' and board[2][1]=='O' and board[2][2]=='O') or
        (board[0][0]=='X' and board[1][1]=='X' and board[2][2]=='X') or
        (board[0][0]=='O' and board[1][1]=='O' and board[2][2]=='O') or
        (board[0][2]=='X' and board[1][1]=='X' and board[2][0]=='X') or
        (board[0][2]=='O' and board[1][1]=='O' and board[2][0]=='O')){
            path_found = 1;
            cout << "Win" << endl;
            print_board(board);
    }
}

void traverse(DoubleNode *current){

    visited_id[visit_index] = current->id;

    board[current->pos_y][current->pos_x] = current->dato;

    if (current->firstchild() == NULL){ // leaf found: evaluate path
        //cout << "id: " << current->id << ", leaf found and move back" << endl;
        //cout << "first child null: eval path" << endl;
        check_board(board);
        board[current->pos_y][current->pos_x] = '_';
        return;
    }
    else{
        if (current->firstchild()!=NULL){
            //cout << "id: " << current->id << ", move to next left child" << endl;
            if (current->dato=='X'){
                //cout << "X at " << current->pos_x << "," << current->pos_y << endl;
            }
            //else cout << "O at " << current->pos_x << "," << current->pos_y << endl;
            visit_index++;
            traverse(current->firstchild());

        }
        if (current->secondchild()!=NULL){
            //cout << "id: " << current->id << ", move to next right child" << endl;
            if (current->dato=='X'){
                //cout << "X at " << current->pos_x << "," << current->pos_y << endl;
            }
            //else cout << "O at " << current->pos_x << "," << current->pos_y << endl;
            visit_index++;
            traverse(current->secondchild());

        }
    }
    board[current->pos_y][current->pos_x] = '_';
}

void postorder(DoubleNode *current){
    if (current==NULL) return;
    postorder(current->firstchild());
    postorder(current->secondchild());
    //cout << current->id << " ";
    cout << current->pos_x << " " << current->pos_y << " " << current->dato << endl;
}

void preorder(DoubleNode *current){
    if (current==NULL) return;
    //cout << current->id << " ";
    cout << current->pos_x << " " << current->pos_y << " " << current->dato << endl;
    preorder(current->firstchild());
    preorder(current->secondchild());
}

void inorder(DoubleNode *current){
    if (current==NULL) return;
    inorder(current->firstchild());
    cout << current->pos_x << " " << current->pos_y << " " << current->dato << endl;
    inorder(current->secondchild());
}

int main()
{
    int num_nodes;
    cin >> num_nodes;

    DoubleNode *arr_ptr[num_nodes];
    int id_arr[num_nodes];
    int parent_id_arr[num_nodes];
    int posx_arr[num_nodes];
    int posy_arr[num_nodes];
    char t_arr[num_nodes];


    for (int i=0; i<num_nodes; i++){
        int id;
        int parent_id;
        int posx;
        int posy;
        char t;

        cin >> id >> parent_id >> posx >> posy >> t;

        id_arr[i] = id;
        parent_id_arr[i] = parent_id;
        posx_arr[i] = posx;
        posy_arr[i] = posy;
        t_arr[i] = t;

        // each cell of the array points to a new created node
        arr_ptr[i] = new DoubleNode(id_arr[i],parent_id_arr[i],posx_arr[i],posy_arr[i],t_arr[i]);
    }

    for (int i=0; i<num_nodes;i++){

        // find root node
        if (parent_id_arr[i] == -1){ // root
            root = arr_ptr[0];
            //cout << "found root, id: " << root->id << endl;
        }

        for(int j=0; j<num_nodes;j++){
            if (arr_ptr[i]->id == arr_ptr[j]->parent_id and arr_ptr[i]->firstchild()==NULL){ //point to child 1
                arr_ptr[i]->putfirst(arr_ptr[j]);
                //cout << arr_ptr[i]->id << " points to " << arr_ptr[j]->id << " (child 1)" << endl;
            }
            if (arr_ptr[i]->id == arr_ptr[j]->parent_id and arr_ptr[i]->secondchild()==NULL //point to child 2
                and arr_ptr[i]->firstchild()->id!=arr_ptr[j]->id){
                arr_ptr[i]->putsecond(arr_ptr[j]);
                //cout << arr_ptr[i]->id << " points to " << arr_ptr[j]->id << " (child 2)" << endl;
            }
            if (arr_ptr[i]->id == arr_ptr[j]->parent_id and arr_ptr[i]->firstchild()!=NULL //not point at all
                and arr_ptr[i]->secondchild()!=NULL){
                //cout << "dont point at all" << endl;
            }
        }
    }

    traverse(root);
    for (int i=0; i<num_nodes; i++){
        //cout << visited_id[i] << ", ";
    }
    if(path_found == 0){
        cout << "Tie" << endl;
        //postorder(root);
        //preorder(root);
        inorder(root);
    }

    return 0;
}
