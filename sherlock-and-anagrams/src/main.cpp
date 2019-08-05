#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;


unordered_map<int, vector<string>> substrings(string input) {
	unordered_map<int, vector<string>> anamap;

	for (size_t len = 1; len < input.size(); len++) {
		anamap[len] = vector<string>();

		for (size_t index = 0; index + len <= input.size(); index++) {
			anamap[len].push_back(input.substr(index, len));
		}
	}

	return anamap;
}

bool isAnagram(string s1, string s2) {
	unordered_map<char, int> letters;

	if (s1.size() != s2.size()) {
		return false;
	}

	for (size_t index = 0; index < s1.size(); index++) {
		letters[s1[index]] += 1;
		letters[s2[index]] -= 1;
	}

	for (auto& kv : letters) {
		if (kv.second != 0) {
			return false;
		}
	}

	return true;
}

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
	int anagrams = 0;

	for (size_t len = 1; len < s.size(); len++) {
		for (size_t index = 0; index < s.size(); index++) {
			auto test = s.substr(index, len);

			for (size_t subdex = index + 1; subdex < s.size(); subdex++) {
				auto element = s.substr(subdex, len);

				if (isAnagram(test, element)) {
					anagrams++;
				}
			}
		}
	}

	return anagrams;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        //fout << result << "\n";
        cout << result << endl;
    }

    //fout.close();

    return 0;
}
