//Sample program to read and parse csv file in C++, file used is “ind_nifty50list.csv”
#include <bits/stdc++.h>
using namespace std;

class Nifty50 {
    string date;
    double open;
    double high;
    double low;
    double close;
    long sharesTraded;
    double turnover;

   public:
    double getturnover() {
        return this->turnover;
    }
    void setturnover(double turnover) {
        this->turnover = turnover;
    }
    long getsharesTraded() {
        return this->sharesTraded;
    }
    void setsharesTraded(long sharesTraded) {
        this->sharesTraded = sharesTraded;
    }
    double getclose() {
        return this->close;
    }
    void setclose(double close) {
        this->close = close;
    }
    double getlow() {
        return this->low;
    }
    void setlow(double low) {
        this->low = low;
    }
    double gethigh() {
        return this->high;
    }
    void sethigh(double high) {
        this->high = high;
    }
    double getopen() {
        return this->open;
    }
    void setopen(double open) {
        this->open = open;
    }
    string getdate() {
        return this->date;
    }
    void setdate(string date) {
        this->date = date;
    }
};

string clean(string s) {
    s = s.substr(1, s.length() - 2);
    string trimmed = regex_replace(s, regex("^\\s+"), string(""));
    trimmed = regex_replace(trimmed, regex("\\s+$"), string(""));
    return trimmed;
}

void printBrokenDays(vector<Nifty50> nifty50) {
    int count = 0;
    double last_low = 0;
    for (int i = 0; i < nifty50.size(); i++) {
        if (nifty50[i].getlow() < last_low) {
            count++;
            cout << "Nifty broke on: " << nifty50[i].getdate() << endl;
        }
        last_low = nifty50[i].getlow();
    }
    cout << "Total days nifty broke: " << count << endl;
}

void findMoreSharesTradedDays(vector<Nifty50> nifty50) {
    double meanSharesTraded = 0;
    int count = 0;
    for (int i = 0; i < nifty50.size(); i++) {
        meanSharesTraded += (nifty50[i].getsharesTraded() - meanSharesTraded)/(i+1);
    }
    for (int i = 0; i < nifty50.size(); i++) {
        if (nifty50[i].getsharesTraded() >= meanSharesTraded){
            cout << "More than avg. shares traded on: " << nifty50[i].getdate() << endl;
            count++;
        }
    }
    cout << "Total days shares Traded more than avg: " << count << endl;
}

int main() {
    ifstream fin("data.csv");
    if (!fin) {
        cout << "File not open\n";
        return 1;
    }

    vector<Nifty50> nifty50;

    string line;
    const char delim = ',';
    // Getting Headers
    getline(fin, line);
    // Reading Data
    while (getline(fin, line)) {
        // cout << line << endl;
        istringstream ss(line);
        Nifty50 nifty;
        string tmp;
        
        getline(ss, tmp, delim);
        nifty.setdate(clean(tmp));

        getline(ss, tmp, delim);
        nifty.setopen(stod(clean(tmp)));

        getline(ss, tmp, delim);
        nifty.sethigh(stod(clean(tmp)));

        getline(ss, tmp, delim);
        nifty.setlow(stod(clean(tmp)));

        getline(ss, tmp, delim);
        nifty.setclose(stod(clean(tmp)));

        getline(ss, tmp, delim);
        nifty.setsharesTraded(stol(clean(tmp)));

        getline(ss, tmp);
        nifty.setturnover(stod(clean(tmp)));

        nifty50.push_back(nifty);
    }
    cout << "no of entry: " << nifty50.size() << endl;

    // Print Nifty Crashes
    printBrokenDays(nifty50);
    
    // Print Nifty Trades
    findMoreSharesTradedDays(nifty50);
}