#include <iostream>
#include <string>

using namespace std;

int main() {
    string keyboard[] = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};

    char direction;
    cin >> direction;

    string typedText;
    cin >> typedText;

    string originalMessage = "";

    for (int i = 0; i < typedText.length(); i++) {
        char c = typedText[i];

        for (int row = 0; row < 3; row++) {
            for (int j = 0; j < keyboard[row].length(); j++) {
                if (c == keyboard[row][j]) {
                    if (direction == 'L') {
                        originalMessage += keyboard[row][j + 1];
                    } else {
                        originalMessage += keyboard[row][j - 1];
                    }
                    break;
                }
            }
        }
    }

    cout << originalMessage << endl;

    return 0;
}
