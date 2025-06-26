#include<bits/stdc++.h>
using namespace std;

void initialize(char gameborad[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            gameborad[i][j] = ' ';
        }
    }
}

void print_board(char board[3][3]){
    cout << "| - | - | - |" << endl;
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            cout << "| " << board[i][j] << " " ;
        }
        cout << "|" << endl;
        if(i < 2)
        cout << "| + | + | + |" << endl;
    }
    cout << "| - | - | - | \n";
}

pair<int, int> input(char board[3][3]){
    bool valid_input = false;
    int row, col;
    while(!valid_input){
        cout << "Enter row and column no (1-3)\n";
        cin >> row >> col;
        if(row < 1 || row > 3 || col < 1 || col > 3){
            cout << "Enter correct row and column no. \n";
        }
        else{
            valid_input = true;
        }
    }
    return make_pair(row, col);
}

char switch_turn(char current_player){
    if(current_player == 'X'){
        current_player = 'O';
        return 'O';
    }
    else{
        current_player = 'X';
        return 'X';
    }
}

bool update_board(char gameboard[3][3], pair <int,int> input, char current_player){
    int row = input.first;
    int col = input.second;
    if(gameboard[row-1][col-1] == ' '){
        gameboard[row-1][col-1] = current_player;
        print_board(gameboard);
        return true;
    }   
    else{
    print_board(gameboard); 
    return false;
    }
}

char check_row_win(char gameboard[3][3]){
    for(int i = 0; i < 3; i++){
        if(gameboard[i][0] == gameboard[i][1] && gameboard[i][2] == gameboard[i][1]){
            if(gameboard[i][1] == 'X')
                return 'X'; 
            if(gameboard[i][1] == 'O')
            return 'O';
        }    
    }
    return ' ';
}

char check_col_win(char gameboard[3][3]){
    for(int i = 0; i < 3; i++){
        if(gameboard[0][i] == gameboard[1][i] && gameboard[1][i] == gameboard[2][i]){
            if(gameboard[1][i] == 'X')
                return 'X';
            if(gameboard[2][i] == 'O')    
                return 'O';
        }
    }
    return ' ';
}

char check_dgnl_win(char gameboard[3][3]){
    if((gameboard[0][0] == gameboard[1][1] && gameboard[1][1] == gameboard[2][2] )||
       (gameboard[2][0] == gameboard[1][1] && gameboard[1][1] == gameboard[0][2] )){
        if(gameboard[1][1] == 'X')
            return 'X';
        if(gameboard[1][1] == 'O')
            return 'O';    
    }   
    else return ' ';
}

char win_check(char gameboard[3][3]){
    //if(check_row_win(gameboard) == ' ') return ' ';
    if(check_row_win(gameboard) == 'X') return 'X';
    if(check_row_win(gameboard) == 'O') return 'O';
    
    //if(!check_col_win(gameboard) == ' ') return ' ';
    if(check_col_win(gameboard) == 'X') return 'X';
    if(check_col_win(gameboard) == 'O') return 'O';

    //if(!check_dgnl_win(gameboard) == ' ') return ' ';
    if(check_dgnl_win(gameboard) == 'X') return 'X';
    if(check_dgnl_win(gameboard) == 'O') return 'O';
    
    return ' ';
}

int main(){
    char gameboard[3][3];
    bool game = true; 
    pair<int, int> chaal;
    int turns = 0;
    while(game){
        initialize(gameboard);
        print_board(gameboard);
        char curr_player = 'X';
        
        while(win_check(gameboard) == ' ' || turns <= 8 ){
            if(turns > 8){
                cout << " ------------------its a tie!!-------------\n ";
                break;
            }
            cout << curr_player << "'s turn\n";
            chaal = input(gameboard);
            turns++;
            while(!update_board(gameboard,chaal,curr_player)){
                cout << "pehle se hai wahan \n";
                cout << curr_player << "'s turn\n";
                chaal = input(gameboard);
            };
            curr_player = switch_turn(curr_player);
            if(win_check(gameboard) != ' '){
                cout << win_check(gameboard) << " is winner\n";
                break;
            }    
        }
        
        cout << "another one???(1/0)\n";
        cin >> game;
    }
    return 0;
}