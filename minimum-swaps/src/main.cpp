#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

vector<string> split_string(string);

int countNodes(unordered_map<int, int>& cycles, vector<bool>& seen, int index) {
	int count = 0;
	while (seen[index] == false) {
		seen[index] = true;
		index = cycles[index];
		count++;
	}

	return count;
}

// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
	unordered_map<int, int> cycles;
	vector<bool> seen;

	for (size_t index = 0; index < arr.size(); index++) {
		cycles[index] = arr[index] - 1;
		seen.push_back(false);
	}

	int count = 0;
	for (size_t index = 0; index < arr.size(); index++) {
		if (seen[index] == false) {
			count += countNodes(cycles, seen, index) - 1;
		}
	}

	return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);
        arr[i] = arr_item;
    }

    int res = minimumSwaps(arr);

    fout << res << "\n";
    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
