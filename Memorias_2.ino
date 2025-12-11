#include <Keypad.h>

const int rows = 4;
const int columns = 4;

char keys[rows][columns] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte pin_rows[rows] = {37, 38, 39, 40};
byte pin_columns[columns] = {41, 42, 2, 1};

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_columns, rows, columns);

char TicTacToe[3][3] = {
  {' ', ' ', ' '},
  {' ', ' ', ' '},
  {' ', ' ', ' '}
};

int turn = 0;
int gameover = 0;

void Printing(){
  for(int row = 0; row < 3; row++){
    for(int column = 0; column < 3; column++){
      Serial.print(" ");
      Serial.print(TicTacToe[row][column]);
      Serial.print(" ");
      if(column < 2){
        Serial.print("|");
      }
    }
    Serial.println("");
    if(row < 2){
      for(int i = 0; i < 3; i++){
        if(i < 2){
          Serial.print("---+");
        } else {
          Serial.print("---");
        }
      }
    }
    Serial.println("");
  }
}

bool PlaceMark(char mark, int row, int column){
  if(TicTacToe[row][column] == ' '){
    TicTacToe[row][column] = mark;
    return true;
  } else {
    return false;
  }
}

void Check(){
  for(int i = 1; i <= 8; i++){
    switch(i){
      case 1:
        if(TicTacToe[0][0] == 'X' && TicTacToe[0][1] == 'X' && TicTacToe[0][2] == 'X'){
          gameover = 1;
        } else if(TicTacToe[0][0] == 'O' && TicTacToe[0][1] == 'O' && TicTacToe[0][2] == 'O'){
          gameover = 2;
        }
      break;

      case 2:
        if(TicTacToe[1][0] == 'X' && TicTacToe[1][1] == 'X' && TicTacToe[1][2] == 'X'){
          gameover = 1;
        } else if(TicTacToe[1][0] == 'O' && TicTacToe[1][1] == 'O' && TicTacToe[1][2] == 'O'){
          gameover = 2;
        }
      break;

      case 3:
        if(TicTacToe[2][0] == 'X' && TicTacToe[2][1] == 'X' && TicTacToe[2][2] == 'X'){
          gameover = 1;
        } else if(TicTacToe[2][0] == 'O' && TicTacToe[2][1] == 'O' && TicTacToe[2][2] == 'O'){
          gameover = 2;
        }
      break;

      case 4:
        if(TicTacToe[0][0] == 'X' && TicTacToe[1][0] == 'X' && TicTacToe[2][0] == 'X'){
          gameover = 1;
        } else if(TicTacToe[0][0] == 'O' && TicTacToe[1][0] == 'O' && TicTacToe[2][0] == 'O'){
          gameover = 2;
        }
      break;

      case 5:
        if(TicTacToe[0][1] == 'X' && TicTacToe[1][1] == 'X' && TicTacToe[2][1] == 'X'){
          gameover = 1;
        } else if(TicTacToe[0][1] == 'O' && TicTacToe[1][1] == 'O' && TicTacToe[2][1] == 'O'){
          gameover = 2;
        }
      break;

      case 6:
        if(TicTacToe[0][2] == 'X' && TicTacToe[1][2] == 'X' && TicTacToe[2][2] == 'X'){
          gameover = 1;
        } else if(TicTacToe[0][2] == 'O' && TicTacToe[1][2] == 'O' && TicTacToe[2][2] == 'O'){
          gameover = 2;
        }
      break;

      case 7:
        if(TicTacToe[0][0] == 'X' && TicTacToe[1][1] == 'X' && TicTacToe[2][2] == 'X'){
          gameover = 1;
        } else if(TicTacToe[0][0] == 'O' && TicTacToe[1][1] == 'O' && TicTacToe[2][2] == 'O'){
          gameover = 2;
        }
      break;

      case 8:
        if(TicTacToe[0][2] == 'X' && TicTacToe[1][1] == 'X' && TicTacToe[2][0] == 'X'){
          gameover = 1;
        } else if(TicTacToe[0][2] == 'O' && TicTacToe[1][1] == 'O' && TicTacToe[2][0] == 'O'){
          gameover = 2;
        }
      break;
    }
  }
}

void Finish(){
  Check();
  switch(gameover){
    case 1:
      Serial.println("Fin del juego - Jugador ha ganado");
      Reset();
    break;

    case 2:
      Serial.println("Fin del juego - CPU ha ganado");
      Reset();
    break;

    default:
      bool done = true;
      for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
          if(TicTacToe[i][j] == ' '){
            done = false;
            break;
          }
        }
      }
      if(done){
        Serial.println("Fin del juego - Ningun jugador ha ganado");
        Reset();
      }
    break;
  }
}

void Reset(){
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      TicTacToe[i][j] = ' ';
    }
  }
  turn = 0;
  gameover = 0;

  Serial.println("");
  Serial.println("  ### #### #####  ##  ");
  delay(250);
  Serial.println(" #    #  #   #   #  # ");
  delay(250);
  Serial.println(" # ## ####   #   #  # ");
  delay(250);
  Serial.println(" #  # #  #   #   #  # ");
  delay(250);
  Serial.println("  ##  #  #   #    ##  ");
  delay(250);
  Serial.println("");

  Printing();
}

void CPU_Turn(){
  bool done = false;
  int row;
  int column;

  while(!done){
    row = random(3);
    column = random(3);
    done = PlaceMark('O', row, column);
  }
}

void setup() {
  Serial.begin(9600);

  Reset();
}

void loop() {
  delay(100);
  Finish();
  
  bool marked = false;
  if(turn == 0){
    char key = keypad.getKey();

    switch(key){
      case 'D':
        Reset();
      break;

      case 'A':
        marked = PlaceMark('X', 0, 0);
        if(marked){
          Printing();
          turn = 1;
        }
      break;

      case 'B':
        marked = PlaceMark('X', 0, 1);
        if(marked){
          Printing();
          turn = 1;
        }
      break;

      case 'C':
        marked = PlaceMark('X', 0, 2);
        if(marked){
          Printing();
          turn = 1;
        }
      break;

      case '3':
        marked = PlaceMark('X', 1, 0);
        if(marked){
          Printing();
          turn = 1;
        }
      break;

      case '6':
        marked = PlaceMark('X', 1, 1);
        if(marked){
          Printing();
          turn = 1;
        }
      break;

      case '9':
        marked = PlaceMark('X', 1, 2);
        if(marked){
          Printing();
          turn = 1;
        }
      break;

      case '2':
        marked = PlaceMark('X', 2, 0);
        if(marked){
          Printing();
          turn = 1;
        }
      break;

      case '5':
        marked = PlaceMark('X', 2, 1);
        if(marked){
          Printing();
          turn = 1;
        }
      break;

      case '8':
        marked = PlaceMark('X', 2, 2);
        if(marked){
          Printing();
          turn = 1;
        }
      break;
    }
  } else {
    CPU_Turn();
    Printing();
    turn = 0;
  }
}
