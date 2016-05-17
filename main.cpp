//
//  main.cpp
//  CardGame
//
//  Created by Артем Уваров on 16.05.16.
//  Copyright © 2016 Артем Уваров. All rights reserved.
//

#include <iostream>
#include <random>
#include <stdlib.h>
using namespace std;
int numberOfPlayers;
int iIndexCardNow;
struct Card{
    string Face;
    int point;
    int flag;
};
Card deck[8];



class player {
public: string nameOfPlayer;
public: int idOfPlayer,sum;
public: player(string name,int id) {
        nameOfPlayer = name;
        idOfPlayer = id;
        sum=0;
    }
    void GetCard (int card) {
        sum=sum+card;
    }
};
player *AllPlayer[5];
string nameBuff;

int main(int argc, const char * argv[]) {
    
    deck[0].Face = '6';
    deck[0].point = 6;
    deck[0].flag = 4;
    deck[1].Face = '7';
    deck[1].point = 7;
    deck[1].flag = 4;
    deck[2].Face = '8';
    deck[2].point = 8;
    deck[2].flag = 4;
    deck[3].Face = '9';
    deck[3].point = 9;
    deck[3].flag = 4;
    deck[4].Face =  "10";
    deck[4].point = 10;
    deck[4].flag = 4;
    deck[5].Face = "Валет";
    deck[5].point = 2;
    deck[5].flag = 4;
    deck[6].Face = "Дама";
    deck[6].point = 3;
    deck[6].flag = 4;
    deck[7].Face = "Король";
    deck[7].point = 4;
    deck[7].flag = 4;
    deck[8].Face = "Туз";
    deck[8].point = 11;
    deck[8].flag = 4;
   
    setlocale(LC_ALL, "Russian");
    
    cout << "Max 6 players.\n\n";
    cout << "Сколько игроков будет играть? ";
    cin >> numberOfPlayers;
    for (int i = 0; i < numberOfPlayers; i++){
        cout << "Введите имя игрока " << i+1 << " ";
        cin >> nameBuff;
        AllPlayer[i]=new player(nameBuff,i);
        
    }
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0,8);
    for (int i = 0; i < numberOfPlayers; i++){
        while (1){
        while (1) {
            iIndexCardNow = dist(gen);
            if (deck[iIndexCardNow].flag < 0)
                continue;
            else {
                deck[iIndexCardNow].flag = deck[iIndexCardNow].flag-1;
                break;
            }
        }
        AllPlayer[i]->GetCard(deck[iIndexCardNow].point);
        cout << "Играет " << i+1 << " игрок" << endl;
        cout << "Ваши очки: " << AllPlayer[i]->sum << endl;
        cout << "Еще?"<<endl;
            while (1) {
                //написать выбор н y/n
            }
    }
    }
    return 0;
}
