#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// Function to extract domains from a URL
vector<string> extractDomains(string url) {
    vector<string> domains;
    size_t start = url.find("//") + 2;
    size_t end = url.find("/", start);
    if (end != string::npos) {
        string domain = url.substr(start, end - start);
        domains.push_back(domain);
    } else {
        string domain = url.substr(start);
        domains.push_back(domain);
    }
    return domains;
}

int main() {
    // Ask user for start page URL
    string url;
    cout << "Enter the start page URL: ";
    cin >> url;

    // Ask user for desired download level
    int level = 2;
    cout << "Enter the desired download level (default 2): ";
    cin >> level;

    // Validate level input
    if (level < 1) {
        cerr << "Error: Level must be 1 or higher." << endl;
        return 1;
    }

    // Extract domains from URL
    vector<string> domains = extractDomains(url);

    // Build wget command string
    string command = "wget";
    command += " --recursive";
    command += " --level=" + to_string(level);
    command += " --page-requisites";
    command += " --convert-links";
    command += " --span-hosts";
    command += " --domains=";
    for (int i = 0; i < domains.size(); ++i) {
        command += domains[i];
        if (i < domains.size() - 1) {
            command += ",";
        }
    }
    command += " --no-parent";
    command += " " + url;

    // Print the constructed command for user reference
    cout << "wget command: " << command << endl;

    // Execute the wget command using system
    int result = system(command.c_str());

    // Check the result of the system call
    if (result != 0) {
        cerr << "Error: Failed to execute wget command." << endl;
        return 1;
    }

    return 0;
}

