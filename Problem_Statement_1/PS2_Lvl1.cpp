#include <iostream>
using namespace std;


 
int main() {
    int r;
    int c;
    cin >> r >> c;
    char arr[r][c];
    int G;
    cin >> G;

    for (int i = 0; i < r ; i++) {
        for (int j = 0; j < c ; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < r ; i++) {
        for (int j = 0; j< c; j++) {
                int h = 0;
                char arr1[8] = {arr[i-1][j-1] , arr[i][j-1] , arr[i+1][j-1] , arr[i-1][j] , arr[i+1][j] , arr[i-1][j+1] , arr[i][j+1] , arr[i+1][j+1]};
                    for (int k = 0; k < 8 ; i++) {
                        if (arr1[k] == '#') {
                            h++;
                        }
                        else {
                            continue;
                        }
                    }
                if (h < 2) {arr[i][j] = '.';} //underpopulation
                else if (h == 2 || h == 3) {arr[i][j] = '#';} //survival
                else if (h > 3) {arr[i][j] = '.';} //overpopulation
                else if (h == 3 && arr[i][j] == '.') {arr[i][j] = '#';} //reproduction
                else {return 0;}
        }
    }

    for (int i = 0; i < r ; i++) {
        for (int j = 0; j < c; j++) {
            cout << arr[i][j];
        }
        cout << "\n";
    }


    return 0;

}