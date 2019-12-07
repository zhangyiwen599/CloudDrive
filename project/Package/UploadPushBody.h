#pragma once

#include "Package.h"

struct UploadPushBody
{
    char fileName[fileNameLength];
    char path[pathLength];
    uint16_t id;
    char content[ChunkSize];
};
