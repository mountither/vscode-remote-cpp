
#include <iostream>
#include <fstream>
#define BYTE_COUNT 256    

using namespace std;

class CharacterCounter
{
private:
    size_t fTotalNumberOfCharacters;
    size_t fCharacterCounts[256]; // all bytes will be considered. must filter further in method.
public:
    CharacterCounter()
    {
        for (int i = 0; i < BYTE_COUNT; i++) {
        fCharacterCounts[i] = 0;
        }
        fTotalNumberOfCharacters = 0;
    }
    void count(unsigned char aCharacter) {

        fCharacterCounts[aCharacter]++;
        fTotalNumberOfCharacters++;

    }

    friend ostream& operator<<(ostream& stream, const CharacterCounter& characterCount)
    {
        stream << "count: " << characterCount.fTotalNumberOfCharacters;

        for (int i = 0; i < BYTE_COUNT; i++) {
        // filtering the empty bytes (count is zero)
            if (characterCount.fCharacterCounts[i] != 0) {
            // casting to char.the filtered ^ 256 bytes are looped through.
            // every i represents a character in this file. specified in count method.
                stream << static_cast<char>(i) << ":    " << characterCount.fCharacterCounts[i] << endl;
            }

        }
        return stream;
    }
};

int main(int argc, char* argv[])
{
    // if (argc < 2) {

    //     cerr << "arguments are missing. " << endl;
    //     cerr << "usage: CharacterCounter <filename>" << endl;
    //     return 1;

    // }

    ifstream lInput("dsp-programs/t2-simple-io/main.cpp", fstream::binary);

    if (!lInput.good()) {
        // cerr << "cannot open input file: " << argv[1] << endl;
        cerr << "cannot open input file" << endl;

        return 2;
    }

    CharacterCounter lCounter;
    unsigned char lChar;
    lInput.unsetf(ios::skipws);

    while (lInput >> lChar) {
        lCounter.count(lChar);
    }

    cout << lCounter;

    lInput.close();

    return 0;
}
