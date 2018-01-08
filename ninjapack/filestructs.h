//
// Created by nbollom on 20/11/17.
//

#ifndef NINJAFRAMEWORK_PACK_FILE_STRUCTS_H
#define NINJAFRAMEWORK_PACK_FILE_STRUCTS_H

namespace NinjaFramework {
    namespace Pack {

#pragma pack(push, 1)

        struct PackHeader {
            char ident[6]; // should be NJPACK otherwise invalid pack file
            uint8_t version; // current and only version 1
            uint8_t compression; // CompressionType stored in uint8_t
            uint64_t ftable_offset; // Location to look for the FileHeader/FileEntry(s)
        };

        struct FileHeader {
            uint16_t file_count; // number of FileEntries to expect
        };

        struct FileEntry {
            uint16_t path_length; // the number of bytes to read for this file path
            uint64_t offset; // start of the file content
            uint64_t size; // size of the uncompressed file
            uint64_t compressed; // size of compressed file
            uint64_t modified; // last modified time
        };

#pragma pack(pop)

    }
}

#endif //NINJAFRAMEWORK_PACK_FILE_STRUCTS_H
