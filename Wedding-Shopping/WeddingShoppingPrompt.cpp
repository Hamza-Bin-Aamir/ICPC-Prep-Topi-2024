#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>

using namespace std;

struct ValueType{
    int Value;
    string NewString;
};

vector<int> parse_csv_string_to_int(const string& csv_string) {
    stringstream ss(csv_string);
    vector<int> tokens;
    string token;

    while (getline(ss, token, ',')) {
        // Trim leading/trailing whitespace
        token.erase(0, token.find_first_not_of(" "));
        token.erase(token.find_last_not_of(" ") + 1);

        // Convert to integer
        int value;
        stringstream token_stream(token);
        token_stream >> value;
        cout << value << endl;
        tokens.push_back(value);
    }

    return tokens;
}


int main()
{
    int NumTestCases; cin>>NumTestCases;
    int* Classes;
    int Budget; int NumClasses;
    string Buffer; vector<int> valBuffer;

    for (int i=0; i<NumTestCases; i++)
    {
        Buffer = "";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, Buffer);

        valBuffer = parse_csv_string_to_int(Buffer);
        Budget = valBuffer[0];

        valBuffer = parse_csv_string_to_int(Buffer);
        NumClasses = valBuffer[1];

        cout << Budget << ", " << NumClasses << endl;
        Classes = new int[NumClasses];

    }
}