#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>

using namespace std;

int count_word(string data){
    int count = 0;
    bool in_word = false;
    for(int i = 0; i < data.length(); i++){
        if(isalnum(data.at(i)) || data.at(i) == '\''){
            if(!in_word){
                in_word = true;
            }
        }
        else {
            if (in_word){
                count++;
            }
                in_word = false;
        }
    }
    if (isalnum(data.at(data.length() - 1))){
        count++;
    }
    return count;
}

int special_character(string data){
    int count = 0;
    for (int i = 0; i < data.length(); i++){
        if(!isalnum(data.at(i)) && data.at(i) != ' '){
            count++;
        }
    }
    return count;
}

int count_is(string data, int start, int end){
    if (start + 3 < end) {
        if(!isalnum(data.at(start))){
            if(data.at(start+1) == 'i'){
                if(data.at(start+2) == 's'){
                    if(!isalnum(data.at(start+3))){
                        return 1 + count_is(data, start+1, end);
                    }                    
                }
            }
        }
        return count_is(data, start+1, end);
    }
    else {
        return 0;
    }
}

int* encode_string(string data){
    int i = 0;
    int *encoded_data = new int[data.length()];
    for (int i = 0; data[i]; i++){
        encoded_data[i] = pow(data[i], 3) + 2 * pow(data[i], 2) + 5 * data[i] + 9;
    }
    return encoded_data;
}

int main(int argc, char const *argv[])
{
    // Part 1
    string College_history = "Indian Institute of Information Technology, Sri City, Chittoor known as IIIT, Sri City is an institute of national importance, setting best-in-class technology education standards in India. IIITS was established in 2013 under the Government of India\'s Initiative to set up 20 Institutes across India, focusing on Information Technology. The Institute was setup by the Government of India - MHRD, Government of Andhra Pradesh and Industry Partners represented by Sri City Foundation as a Not-for-Profit Public-Private-Partnership.";
    
    // Part 2
    cout << "Word Count: " << count_word(College_history) << " Words.\n";
    cout << "Special Characters: " << special_character(College_history) << ".\n";

    // Part 3
    cout << "\"is\" comes " << count_is(College_history, 0, College_history.length()-1) << " times." << endl;

    // Part 4
    cout << "Encoded String: \n";
    int *encoded = encode_string(College_history);
    for (int i = 0; i < College_history.length(); i++){
        cout << char(encoded[i]);
    }
    cout << "Encoded String(ASCII VALUES): \n";
    for (int i = 0; i < College_history.length(); i++){
        cout << int(char(encoded[i])) << ' ';
    }
    cout << endl;
    return 0;
}


