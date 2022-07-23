//
// Created by philippe on 23/07/2022.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <locale>

void CustomException(const char *string);

/// Writing to a file
void Test120() {
    std::ofstream os("foo.txt");
    if (os.is_open()) {
        os << "Hello World!";

        if (os.bad()) {
            // Failed to write
        }

        os.close();
    }

    std::ofstream os2("foo.txt");
    if (os2.is_open()) {
        char data[] = "Foo";
        // Writes 3 characters from data -> "Foo".
        os2.write(data, 3);
        os2.close();
    }
}
// std::ifstream ifs("foo.txt"); // ifstream: Opens file "foo.txt" for reading only.
// std::ofstream ofs("foo.txt"); // ofstream: Opens file "foo.txt" for writing only.
// std::fstream iofs("foo.txt"); // fstream: Opens file "foo.txt" for reading and writing.

//std::ifstream ifs;
//ifs.open("bar.txt"); // ifstream: Opens file "bar.txt" for reading only.
//std::ofstream ofs;
//ofs.open("bar.txt"); // ofstream: Opens file "bar.txt" for writing only.
//std::fstream iofs;
//iofs.open("bar.txt"); // fstream: Opens file "bar.txt" for reading and writing.

void Test121()
{
    // Try to read the file 'foo.txt'.
    std::ifstream ifs("fooo.txt"); // Note the typo; the file can't be opened.
    // Check if the file has been opened successfully.
    if (!ifs.is_open()) {
        // The file hasn't been opened; take appropriate actions here.
        //throw CustomException("File could not be opened");
    }
}

void CustomException(const char *string) {

}

void Test122()
{
    // Open the file 'c:\\folder\\foo.txt' on Windows.
    std::ifstream ifs1(R"(c:\\folder\\foo.txt)"); // using raw literal

    // Open the file 'c:\\folder\\foo.txt' on Windows.
    std::ifstream ifs2("c:/folder/foo.txt");

    // Open the file 'пример\\foo.txt' on Windows.
    std::ifstream ifs(LR"(пример\\foo.txt)"); // using wide characters with raw literal
}

/// Reading from a file

void Test123() {

    std::ofstream os("foo.txt");
    if (os.is_open()) {
        os << "John Doe 25 4 6 1987" << std::endl;
        os << "Jane Doe 15 5 24 1976" << std::endl;

        os.close();
    }

    // Define variables.
    std::ifstream is("foo.txt");
    std::string firstname, lastname;
    int age, bmonth, bday, byear;
// Extract firstname, lastname, age, bday month, bday day, and bday year in that order.
// Note: '>>' returns false if it reached EOF (end of file) or if the input data doesn't
// correspond to the type of the input variable (for example, the string "foo" can't be
// extracted into an 'int' variable).
    while (is >> firstname >> lastname >> age >> bmonth >> bday >> byear) {
        // Process the data that has been read.
        std::cout << firstname << lastname << age << bmonth << bday << byear << std::endl;
    }
}

/// If you wish to read an entire file as a string
void Test124()
{
// Opens 'foo.txt'.
    std::ifstream is("foo.txt");
    std::string whole_file;
// Sets position to the end of the file.
    is.seekg(0, std::ios::end);
// Reserves memory for the file.
    whole_file.reserve(is.tellg());
// Sets position to the start of the file.
    is.seekg(0, std::ios::beg);
    // Sets contents of 'whole_file' to all characters in the file.
    whole_file.assign(std::istreambuf_iterator<char>(is),
                      std::istreambuf_iterator<char>());
}

/// If you want to read a file line by line
void Test125()
{
    std::ifstream is("foo.txt");
// The function getline returns false if there are no more lines.
    for (std::string str; std::getline(is, str);) {
        // Process the line that has been read.
        std::cout << str << std::endl;
    }
}

/// If you want to read a fixed number of characters, you can use the stream's member function read():
void Test126()
{
    std::ifstream is("foo.txt");
    char str[4];
// Read 4 characters from the file.
    is.read(str, 4);

    if (is.fail())
        std::cout << "Failed to read!" << std::endl;
}

/// Opening modes

//std::ofstream os("foo.txt", std::ios::out | std::ios::trunc);
//std::ifstream is;
//is.open("foo.txt", std::ios::in | std::ios::binary);
//
//app append Output Appends data at the end of the file.
//binary binary Input/Output Input and output is done in binary.
//in input Input Opens the file for reading.
//out output Output Opens the file for writing.
//trunc truncate Input/Output Removes contents of the file when opening.
//ate at end Input Goes to the end of the file when opening.

//Note: Setting the binary mode lets the data be read/written exactly as-is; not setting it enables the translation of
//the newline '\n' character to/from a platform specific end of line sequence.
//For example on Windows the end of line sequence is CRLF ("\r\n").
//Write: "\n" => "\r\n"
//Read: "\r\n" => "\n"

/// Reading an ASCII file into a std::string
void Test127()
{
    std::ifstream f("file.txt");
    if (f)
    {
        std::stringstream buffer;
        buffer << f.rdbuf();
        f.close();
        // The content of "file.txt" is available in the string `buffer.str()`
    }

    std::ifstream f2("file.txt");
    if (f2)
    {
        std::string str((std::istreambuf_iterator<char>(f2)),
                        std::istreambuf_iterator<char>());
        f2.close();
        // Operations on `str`...

    }

    std::ifstream f3("file.txt");
    if (f3)
    {
        f3.seekg(0, std::ios::end);
        const auto size = f3.tellg();
        std::string str(size, ' ');
        f3.seekg(0);
        f3.read(&str[0], size);
        f3.close();
        // Operations on `str`...
    }
}


/// Writing files with non-standard locale settings
void Test128()
{
    std::cout << "User-preferred locale setting is "
              << std::locale("").name().c_str() << std::endl;
// Write a floating-point value using the user's preferred locale.
    std::ofstream ofs1;
    ofs1.imbue(std::locale(""));
    ofs1.open("file1.txt");
    ofs1 << 78123.456 << std::endl;
// Use a specific locale (names are system-dependent)
    std::ofstream ofs2;
    //ofs2.imbue(std::locale("en_US.UTF-8"));
    //ofs2.imbue(std::locale("en_US"));
    ofs2.open("file2.txt");
    ofs2 << 78123.456 << std::endl;
// Switch to the classic "C" locale
    std::ofstream ofs3;
    ofs3.imbue(std::locale::classic());
    ofs3.open("file3.txt");
    ofs3 << 78123.456 << std::endl;
}

void Test129()
{
    std::string buffer;
    std::ifstream f("file.txt");

    while (!f.eof())
    {
        // std::ws: discards leading whitespace from an input stream

        f >> buffer >> std::ws;
        if (f.fail())
            break;
        /* Use `buffer` */
    }

    std::ifstream f2("file.txt");
    while (f2 >> buffer)
    {
        /* Use `buffer` */
    }
}

/// Flushing a stream
void Test129_1()
{
    std::ofstream os("foo.txt");
    os << "Hello World!" << std::flush;

    char data[] = "Foo";
    os.write(data, 3);
    os.flush();

    // Both following lines do the same thing
    os << "Hello World!\n" << std::flush;
    os << "Hello world!" << std::endl;
}