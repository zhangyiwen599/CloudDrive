#pragma once

#include <map>
#include "Package.h"

enum PackageType
{
    SIGNIN,         // 登陆
    SIGNIN_RES,     // 登陆返回结果

    SIGNUP,         // 注册
    SIGNUP_RES,     // 注册返回结果

    UPLOAD_REQ,     // 上传文件信号 第一次告知服务器文件路径、大小、名称
    UPLOAD_RESP,    // 上传文件的结果
    UPLOAD_FETCH,   // 服务器端要求上传某一特殊文件块
    UPLOAD_PUSH,    // 客户端传给服务器端需要的数据块
    UPLOAD_DONE,    // 服务端传给客户端的完成信号

    DOWNLOAD_REQ,   // 下载文件的信号 第一次告知服务器需要下载的文件的路径、名称
    DOWNLOAD_RESP,  // 下载文件的结果
    DOWNLOAD_PUSH,  // 服务器端给客户端某一个块
    DOWNLOAD_FETCH, // 客户端请求的某一块
    DOWNLOAD_DONE,  // 客户端通知服务端完成下载

    SYN_REQ,         // 同步信号 客户端请求同步某一路径的文件
    SYN_RESP,        // 同步信号 回应同步结果 包括文件下的文件个数
    SYN_PUSH,        // 同步信号 发送一个目录下的信息

    FILEINFO,        // 文件信息，包含hash，exist，completed，size(MB)

    COPY,            // 拷贝文件
    COPY_RES,

    MOVE,            // 复制文件
    MOVE_RES,
    
    DELETE,          // 删除文件
    DELETE_RES,
    
    MKDIR,          // 新建文件夹
    MKDIR_RES

};

// 对于不同指令交互的大小的映射表 const类型 不可以更改 只能初始化赋值
const static std::map<PackageType, uint16_t> PackageSizeMap{
    {PackageType::SIGNIN, sizeof (SigninBody)},
    {PackageType::SIGNIN_RES, sizeof (SigninresBody)},

    {PackageType::SIGNUP, sizeof (SignupBody)},
    {PackageType::SIGNUP_RES, sizeof (SignupresBody)},

    {PackageType::UPLOAD_REQ, sizeof (UploadReqBody)},
    {PackageType::UPLOAD_RESP, sizeof (UploadRespBody)},
    {PackageType::UPLOAD_FETCH, sizeof (UploadFetchBody)},
    {PackageType::UPLOAD_PUSH, sizeof (UploadPushBody)},
    {PackageType::UPLOAD_DONE, sizeof (UploadDoneBody)},
    {PackageType::DOWNLOAD_REQ, sizeof (DownloadReqBody)},
    {PackageType::DOWNLOAD_RESP, sizeof (DownloadRespBody)},
    {PackageType::DOWNLOAD_PUSH, sizeof (DownloadPushBody)},
    {PackageType::DOWNLOAD_FETCH, sizeof (DownloadFetchBody)},
    {PackageType::DOWNLOAD_DONE, sizeof (DownloadDoneBody)},
    {PackageType::SYN_REQ, sizeof (SYNReqBody)},
    {PackageType::SYN_RESP, sizeof (SYNRespBody)},
    {PackageType::SYN_PUSH, sizeof (SYNPushBody)},

    {PackageType::COPY, sizeof (CopyBody)},
    {PackageType::COPY_RES,sizeof (CopyRespBody)},
    {PackageType::MOVE, sizeof (MoveBody)},
    {PackageType::MOVE_RES,sizeof (MoveRespBody)},
    {PackageType::DELETE, sizeof (DeleteBody)},
    {PackageType::DELETE_RES, sizeof (DeleteRespBody)},

    {PackageType::MKDIR, sizeof(MkdirRespBody)},
    {PackageType::MKDIR_RES, sizeof(MkdirRespBody)},  

    {PackageType::FILEINFO, 0}                      //留个零，不定长包，按需要赋值sizeof(FileInfoBody+size)
};

// 统一的头包 每个指令发送前都要有的
struct UniformHeader
{
    PackageType p;
    uint16_t len;
    UniformHeader();
    UniformHeader(const PackageType &pIn);
};
