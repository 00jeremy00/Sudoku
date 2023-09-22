#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#define T_SIZE 9
#define B_SIZE 81
#define G_LEN 3
class Game{
private:
    short tiles[B_SIZE];
    short notRow[T_SIZE][T_SIZE+1];
    short notCol[T_SIZE][T_SIZE+1];
    short notGroup[T_SIZE][T_SIZE+1];

public:
    Game(string tData){
        short temp;
        cout << tData << endl;
        for(int i = 0; i < B_SIZE; i++) {
            temp = tData[i] ;
            if(temp > 48 && temp < 58){
                tiles[i] = temp - 48;
            }
            else{
                tiles[i] = 0;
            }
            if(tiles[i] !=0){
                fillNot(i);
            }
        }
        for(int i =0;i<B_SIZE;i++){
            if(i% T_SIZE == 0){
                cout << endl;
            }
        cout <<tiles[i] <<"_";
        }
        cout<<endl;
        cout << tiles << endl;
    }

    void fillNot(int t) {
            int r = t / T_SIZE;
            int c = t % T_SIZE;
            int g = (c / G_LEN) + G_LEN * (t / (T_SIZE * G_LEN));
            cout << t << "/" << r << "/" << c << "/" << g << endl;
            notRow[r][t] = 1;
            notCol[c][t] = 1;
            notGroup[g][t] = 1;
            ++notRow[r][T_SIZE];
            ++notCol[c][T_SIZE];
            ++notGroup[g][T_SIZE];
    }

    void notDump(int r, int c, int g){
        if(r == -1){
            for(int i=0;i < T_SIZE; i++){
                cout << "R" << i << notRow[i] << endl;
            }
        }
        else if(r <T_SIZE){
            cout << "R" << r << notRow[r] << endl;
        }
        if(c == -1){
            for(int i=0;i < T_SIZE; i++){
                cout << "C" << i << notCol[i] << endl;
            }
        }
        else if(c <T_SIZE){
            cout << "C" << r << notCol[c] << endl;
        }
        if(g == -1){
            for(int i=0;i < T_SIZE; i++){
                cout << "G" << i << notGroup[i] << endl;
            }
        }
        else if(g <T_SIZE){
            cout << "G" << r << notGroup[g] << endl;
        }
    }
};
int main(){
    string s1 = ".....5.821.24.8..94...7......985..24..7.....1.....2.9..7......165....7........4.5.";
    char b1[T_SIZE * T_SIZE];
    for(int i; i < B_SIZE; i++){
        b1[i] = s[i]; 
    }
    //strcpy(b1, s1.c_str());
    cout << b1 << endl;
    cout << b1[0] << endl;
    Game g1(b1);
    //delete[] b1;
    //free(b1) ;
    
    
    return 0;
} 
	
