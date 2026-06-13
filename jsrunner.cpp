

#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

// Helper: check if a file exists
bool fileExists(const string& path) {
    struct stat buffer;
    return (stat(path.c_str(), &buffer) == 0);
}

// Helper: read entire file into a string
string readFile(const string& path) {
    ifstream t(path);
    if (!t.is_open()) {
        cerr << "Error: Cannot open file " << path << endl;
        exit(1);
    }
    string content((istreambuf_iterator<char>(t)),
                         istreambuf_iterator<char>());
    return content;
}

// Execute JavaScript code using Node.js
// Returns the captured stdout as a string.
// On error, prints stderr and exits.
string executeJS(const string& code) {
    // Create a temporary file name (POSIX-compliant)
    char tempName[] = "/tmp/jsrunnerXXXXXX";
    int fd = mkstemp(tempName);
    if (fd == -1) {
        cerr << "Error: Failed to create temporary file." << endl;
        exit(1);
    }
    // Write code to the temp file
    FILE* tempFile = fdopen(fd, "w");
    if (!tempFile) {
        cerr << "Error: fdopen failed." << endl;
        close(fd);
        exit(1);
    }
    fprintf(tempFile, "%s", code.c_str());
    fclose(tempFile);

    // Build command: node tempfile
    string command = "node " + string(tempName) + " 2>&1";

    // Execute and capture output
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        cerr << "Error: popen failed. Is Node.js installed?" << endl;
        unlink(tempName);
        exit(1);
    }

    string result;
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result += buffer;
    }

    int exitCode = pclose(pipe);
    // Clean up temp file
    unlink(tempName);

    if (exitCode != 0) {
        // If Node.js produced an error, result already contains stderr
        cerr << "Node.js execution failed (exit code " << exitCode << "):\n";
        cerr << result;
        exit(exitCode);
    }

    return result;
}

int main(int argc, char* argv[]) {
    string jsCode;

    // Determine source of JavaScript code
    if (argc == 1) {
        // No arguments – read from stdin
        string line;
        while (getline(cin, line)) {
            jsCode += line + "\n";
        }
    }
    else {
        string arg = argv[1];
        // If argument is an existing file, read it; otherwise treat as inline code
        if (fileExists(arg)) {
            jsCode = readFile(arg);
        } else {
            jsCode = arg;
        }
    }

    if (jsCode.empty()) {
        cerr << "No JavaScript code provided." << endl;
        return 1;
    }

    string output = executeJS(jsCode);
    cout << output;
    return 0;
}