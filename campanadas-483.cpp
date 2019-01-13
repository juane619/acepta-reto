#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;

const int INF = 0x3f3f3f3f;

void fastscan(int& number) {
    // variable to indicate sign of input number
    bool negative = false;
    register int c;

    number = 0;

    // extract current character from buffer
    c = getchar();
    if (c == '-') {
        // number is negative
        negative = true;

        // extract the next character from the buffer
        c = getchar();
    }

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c > 47 && c < 58); c = getchar()) number = number * 10 + c - 48;

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative) number *= -1;
}

class Time {
   private:
    int hour;    // 0 - 23 (24-hour clock format)
    int minute;  // 0 - 59
    int second;  // 0 - 59
   public:
    Time(int hour, int minute, int second) {
        setTime(hour, minute, second);  // validate and set time
    }                                   // end Time constructor

    Time(int seg) {
        hour = (int)(seg / 3600);
        minute = (int)((seg - hour * 3600) / 60);
        second = seg - (hour * 3600 + minute * 60);
    }

    bool operator<(const Time& other) {
        return toSeconds() < other.toSeconds();
    }

    long long toSeconds() const { return hour * 3600 + minute * 60 + second; }

    Time& resta(int hours, int minutes, int seconds) {
        Time other(hours, minutes, seconds);
        int dif = toSeconds() - other.toSeconds();
        Time other2(dif);

        setTime(other2.hour, other2.minute, other2.second);

        return *this;
    }

    Time& resta(const Time& other) {
        int dif = toSeconds() - other.toSeconds();
        Time other3(dif);

        setTime(other3.hour, other3.minute, other3.second);
        return *this;
    }

    Time& resta(int seg) {
        int dif = toSeconds() - seg;
        Time other3(dif);

        setTime(other3.hour, other3.minute, other3.second);

        return *this;
    }

    Time& suma(int hours, int minutes, int seconds) {
        Time other(hours, minutes, seconds);
        int dif = toSeconds() + other.toSeconds();
        Time other2(dif);

        hour = other2.hour;
        minute = other2.minute;
        second = other2.second;
    }

    Time& suma(const Time& other) {
        int dif = toSeconds() + other.toSeconds();
        Time other3(dif);

        hour = other3.hour;
        minute = other3.minute;
        second = other3.second;
    }

    Time& suma(int seg) {
        int dif = toSeconds() + seg;
        Time other3(dif);

        hour = other3.hour;
        minute = other3.minute;
        second = other3.second;
    }

    // set functions
    // set new Time value using universal time
    void setTime(int h, int m, int s) {
        setHour(h);    // set private field hour
        setMinute(m);  // set private field minute
        setSecond(s);  // set private field second
    }                  // end function setTime

    void setHour(int h) { hour = h; }  // end function setHour

    // set minute value
    void setMinute(int m) {
        if (m >= 0 && m < 60) {
            minute = m;
        }
    }  // end function setMinute

    // set second value
    void setSecond(int s) {
        if (s >= 0 && s < 60) {
            second = s;
        }
    }

    // return hour value
    int getHour() { return hour; }  // end function getHour

    // return minute value
    int getMinute() { return minute; }  // end function getMinute

    // return second value
    int getSecond() { return second; }  // end function getSecond

    // print Time in universal-time format (HH:MM:SS)
    void printUniversal() {
        cout << setfill('0') << setw(2)
             << ((getHour() >= 24) ? getHour() % 24 : getHour()) << ":"
             << setw(2) << getMinute() << ":" << setw(2) << getSecond();
    }  // end function printUniversal

    // print Time in standard-time format (HH:MM:SS AM or PM)
    void printStandard() {
        cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
             << ":" << setfill('0') << setw(2) << getMinute() << ":" << setw(2)
             << getSecond() << (hour < 12 ? " AM" : " PM");
    }  // end function printStandard

};  // end class Time

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int veces;
    int horas1, horas2, minutos1, minutos2, segundos1, segundos2;
    char aux;
    int ncamps, instante;
    int frec, difsegs, momseg;
    cin >> veces;

    for (; veces > 0; veces--) {
        cin >> horas1 >> aux >> minutos1 >> aux >> segundos1 >> horas2 >> aux >>
            minutos2 >> aux >> segundos2;
        cin >> ncamps >> instante;

        Time h1(horas1, minutos1, segundos1);
        Time h2(horas2, minutos2, segundos2);

        if (h2 < h1) {
            h2.setHour(horas2 + 24);
        }
        difsegs = h2.resta(h1.toSeconds()).toSeconds();

        momseg = difsegs / (ncamps - 1) * (instante - 1);

        h1.suma(momseg);
        h1.printUniversal();
        cout << '\n';
    }

    return 0;
}
