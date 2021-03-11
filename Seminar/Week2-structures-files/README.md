### File Streams:

## Type of streams for files

    ofstream - This data type represents the output file stream and is used to create files and to write
               information to files.

    ifstream - This data type represents the input file stream and is used to read information from files.

    fstream  - This data type represents the file stream generally, and has the capabilities of both
               ofstream and ifstream which means it can create files, write information to files, and read
               information from files.

## Type of flags

    ios::app   - Append mode. All output to that file to be appended to the end.
    ios::ate   - Open a file for output and move the read/write control to the end of the file.
    ios::in    - Open a file for reading.
    ios::out   - Open a file for writing.
    ios::trunc - If the file already exists, its contents will be truncated before opening the file.

## read & write BINARY

    ofstream outFile("<directory>", std::ios::binary);

    outFile.write((char*)<address_of_object_to_write>, sizeof(object_type));

    outFile.seekp(<bytes>); //beg, end, cur
    outFile.tellp();

    ifstream inFile("<directory>", std::ios::binary);

    inFile.seekg(<bytes>); //beg, end, cur
    inFile.tellg();

    inFile.read((char*)<address_of_object_to_read>, sizeof(object_type));
