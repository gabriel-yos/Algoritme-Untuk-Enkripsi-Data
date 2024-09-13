#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

std::string decrypt(const std::string message) {
    srand(time(0));
    static int secret = rand() % 3200;
    std::string output;
    int i = 0, a = 0, b = 1, c = 0;
    
    for (int i = 0; i < message.size(); ++i) {
        output += ((int)message[i]) + (secret + c);

        c = a + b;
        a = b;
        b = c;
    }
    return output;
}

std::string encrypt(const std::string message) {
    srand(time(0));
    static int secret = rand() % 3200;
    std::string output;
    int i = 0, a = 0, b = 1, c = 0;

    for (int i = 0; i < message.size(); ++i) {
        output += ((int)message[i]) - (secret + c);

        c = a + b;
        a = b;
        b = c;
    }
    return output;
}

int main() {
    std::string message, output, result;
    cout << "Masukan pesan yang di Enkripsi: ";
    getline(cin, message);

    output = encrypt(message);
    result = decrypt(output);

    cout << "Pesan : " << message << endl << endl;
    cout << "Hasil Enkripsi : " << output << endl << endl;
    cout << "Hasil Dekripsi : " << result << endl << endl;

    system("PAUSE");
    return 0;
}
