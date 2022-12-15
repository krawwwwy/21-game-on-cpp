#include <iostream>
#include <cstdlib>
using namespace std;

struct Game{
    int result1 = 0;
    int result2 = 0;
    int* player = new int[18];
    int* bot = new int[18];
    int current1, current2;
    int rest = 35;
    int last1 = 2;
    int last2 = 2;
    char answer;
    int a[36] = {6, 6, 6, 6, 7, 7, 7, 7,    
                 8, 8, 8, 8, 9, 9, 9, 9,
                 10, 10, 10, 10, 11, 11,
                 2, 2, 2, 2, 3, 3, 3, 3,
                 4, 4, 4, 4, 11, 11};
    
    char convert(int obj)
    {
        if (obj == 2){return 'J';}
        if (obj == 3){return 'Q';}
        if (obj == 4){return 'K';}
    }
    
    void bot_check()
    {
        result2 = 0;
        for (int i = 0; i < 18; i++)
        {
            result2 = result2 + bot[i];
        }
        if (result2 > 21)
        {
            cout<<endl;
            cout<<"your sum: "<<result1<<'\t'<<"bot sum: "<<result2<<endl;
            cout<<"     ! ! ! YOU WIN ! ! !";
        }
        else if(result2 < result1 and result2 < 19)
        {
            extend('B');
        }
        else if(result1 < result2)
        {
            cout<<endl;
            cout<<"your sum: "<<result1<<'\t'<<"bot sum: "<<result2<<endl;
            cout<<"     . . . You lose . . .";}
        else if(result1 == result2){
            cout<<endl;
            cout<<"your sum: "<<result1<<'\t'<<"bot sum: "<<result2<<endl;
            cout<<"     . . . It is a Draw . . .";
        }else{
            cout<<endl;
            cout<<"your sum: "<<result1<<'\t'<<"bot sum: "<<result2<<endl;
            cout<<"     ! ! ! YOU WIN ! ! !";
        }
    }
    
    void player_check()
    {   
        result1 = 0;
        for(int j = 0; j < 18; j++)
        {
            result1 = result1 + player[j];
        }
        if (result1 > 21)
        {
            cout<<"     . . . Oh your sum is more than 21. You lose . . ."<<endl;
            exit(0);
        }
        cout<<"     Do you want to take an extra card?  (y / n)"<<endl;
        cin>>answer;
        if (answer == 'y'){extend('P');}
        else {
            cout<<"bot cards:"<<' ';
            for (int i = 0; i < 2; i++)
            {
                if (bot[i] == 2 or bot[i] == 3 or bot[i] == 4){cout<<convert(bot[i])<<' ';}
                else{cout<<bot[i]<<' ';}
            }
            bot_check();
            }
    }
    
    void start()
    {   
        cout<<"Начать игру? (y / n)"<<endl;
        cin>>answer;
        if (answer == 'n')
        {
            exit(0);
        } else {
            for (int i = 0; i < 2; i++)
            {
                srand(time(NULL));
                current1 = rand()%rest;
                player[i] = a[current1];
                a[current1] = a[rest];
                result1 = result1 + player[i];
                rest--;
                current1 = rand()%rest;
                bot[i] = a[current1];
                a[current1] = a[rest];
                result2 = result2 + bot[i];
                rest--;
            }
            for (int i = 0; i < 3; i++)
            {
                if (i == 0)
                {cout<<"your cards"<<'\t'<<"your oponnet cards"<<endl;}
                else if(i == 1)
                {
                    if (player[i - 1] == 2 or player[i - 1] == 3 or player[i - 1] == 4)
                    {
                        if (bot[i - 1] == 2 or bot[i-1] == 3 or bot[i-1] == 4){cout<<convert(player[i-1])<<'\t'<<'\t'<<convert(bot[i-1])<<endl;}
                        else{cout<<convert(player[i-1])<<'\t'<<'\t'<<bot[i-1]<<endl;}
                        
                    }
                    else if (bot[i-1] == 2 or bot[i-1] == 3 or bot[i-1] == 4){cout<<player[i-1]<<'\t'<<'\t'<<convert(bot[i-1])<<endl;}
                    else{cout<<player[i-1]<<'\t'<<'\t'<<bot[i-1]<<endl;}
                    
                }
                else
                {
                    if (player[i-1] == 2 or player[i-1] == 3 or player[i-1] == 4){cout<<convert(player[i-1])<<'\t'<<'\t'<<"hidden"<<endl;}
                    else{cout<<player[i-1]<<'\t'<<'\t'<<"hidden"<<endl;}
                    
                }
            }
            }
        player_check();
    }
    
    void extend(char flag)
    {   
        if (flag == 'P'){
            current1 = rand()%rest;
            player[last1] = a[current1];
            a[current1] = a[rest];
            rest--;
            last1++;
            for (int i = 0; i < last1; i++)
            {
                if(player[i] == 2 or player[i] == 3 or player[i] == 4){cout<<convert(player[i])<<' ';}
                else{cout<<player[i]<<' ';}
            }
            cout<<endl;
            player_check();
        }
        else{
            current1 = rand()%rest;
            bot[last2] = a[current1];
            a[current1] = a[rest];
            rest--;
            last2++;
            if (bot[last2 - 1] == 2 or bot[last2 - 1] == 3 or bot[last2] == 4){cout<<convert(bot[last2 - 1])<<' ';}
            else{cout<<bot[last2 - 1]<<' ';}
            bot_check();
        }
    }
    

};
int main()
{

    Game test;
    test.start();
    delete [] test.player;
    delete [] test.bot;
    return 0;
}
